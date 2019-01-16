#include "Drawer.h"

void DrawLine(Vector2D p1, Vector2D p2, Color c) // Just Bresenham's line algorithm
{
	float dx = (p2.GetX() - p1.GetX() >= 0.0f ? 1.0f : -1.0f);
	float dy = (p2.GetY() - p1.GetY() >= 0.0f ? 1.0f : -1.0f);

	float lx = abs(p2.GetX() - p1.GetX());
	float ly = abs(p2.GetY() - p1.GetY());

	int l = (ly < lx) ? lx : ly;

	glColor3f(c.r, c.g, c.b);

	if (l == 0)
	{
		glBegin(GL_POINTS);
		glVertex2f(p1.GetX(), p1.GetY());
		glEnd();
	}

	if (ly <= lx)
	{
		float x = p1.GetX();
		float y = p1.GetY();
		float d = -lx;

		l++;
		while (l--)
		{
			glBegin(GL_POINTS);
			glVertex2f(x, y);
			glEnd();

			x += dx;
			d += 2 * ly;

			if (d > 0)
			{
				d -= 2 * lx;
				y += dy;
			}
		}
	}
	else
	{
		float x = p1.GetX();
		float y = p1.GetY();
		float d = -ly;

		l++;
		while (l--)
		{
			glBegin(GL_POINTS);
			glVertex2f(x, y);
			glEnd();

			y += dy;
			d += 2 * lx;

			if (d > 0)
			{
				d -= 2 * ly;
				x += dx;
			}
		}
	}
}

void DrawTriangle2D(Triangle2D t, Color c)
{
	DrawLine(t.GetP1(), t.GetP2(), c);
	DrawLine(t.GetP2(), t.GetP3(), c);
	DrawLine(t.GetP3(), t.GetP1(), c);
}

void FillTriangle2D(Triangle2D t, Color c)
{
	Vector2D p1, p2, p3;
	p1 = t.GetP1();
	p2 = t.GetP2();
	p3 = t.GetP3();

	if (p1.GetY() == p2.GetY() && p1.GetY() == p3.GetY()) return;

	if (p2.GetY() < p1.GetY())
		std::swap(p1, p2);
	if (p3.GetY() < p1.GetY())
		std::swap(p1, p3);
	if (p2.GetY() > p3.GetY())
		std::swap(p2, p3);

	int totalh = p3.GetY() - p1.GetY();

	for (int i = 0; i < totalh; i++)
	{
		bool second_half = i > (p2.GetY() - p1.GetY()) || p2.GetY() == p1.GetY();
		int seg_height = second_half ? p3.GetY() - p2.GetY() : p2.GetY() - p1.GetY();
		float alpha = (float)i / totalh;
		float beta = (float)(i - (second_half ? p2.GetY() - p1.GetY() : 0)) / seg_height;
		Vector2D A = p1 + (p3-p1)*alpha;
		Vector2D B = second_half ? p2 + (p3 - p2)*beta : p1 + (p2 - p1)*beta;

		if (A.GetX() > B.GetX())
			std::swap(A, B);

		glColor3f(c.r, c.g, c.b);

		for (int j = A.GetX(); j <= B.GetX(); j++)
		{
			glBegin(GL_POINTS);
			glVertex2f(j, p1.GetY() + i);
			glEnd();
		}
	}
}

Drawer::Drawer()
{
	ProjectionMat.GenProjectionMat(aratio, fovrad, (float)ZFAR, (float)ZNEAR);

	cam = Camera(0.0f, 0.0f, 0.0f);

	if (!cube.LoadFromFile("test.obj")) {
		std::cerr << "Error loading from file!" << std::endl;
		exit(1);
	}
}

void Drawer::DrawAll()
{
	std::vector<Triangle3D> queue;

	Matrix4x4 shiftmat;
	shiftmat.GenShiftMat(Vector3D(0.0f, 0.0f, 6.0f));
	RotMatZ.GenRotationMatZ(0.001f * time);
	RotMatX.GenRotationMatX(0.001f * time);
	Matrix4x4 world = RotMatZ * RotMatX;
	world = world * shiftmat;

	Vector3D up(0.0f, -1.0f, 0.0f);
	Vector3D target = cam.GetPoint() + cam.GetLookDir();

	Matrix4x4 cameramat;
	cameramat.GenPointAtMat(cam.GetPoint(), target, up);
	cameramat.DumbInverse();

	//world = cameramat * world;

	for (auto tri : cube.polygons)
	{
		Triangle3D shifted(world * tri.GetP1(), world * tri.GetP2(), world * tri.GetP3());

		Vector3D normal = shifted.GetNormal();
		Vector3D camray = shifted.GetP1() - cam.GetPoint();

		if (normal.DotProduct(camray) < 0.0f)
		{
			Vector3D dir_light(0.0f, 0.0f, -1.0f);
			dir_light.Normalize();

			float dp = normal.DotProduct(dir_light);

			Triangle3D triProjected(ProjectionMat * shifted.GetP1(), ProjectionMat * shifted.GetP2(), ProjectionMat * shifted.GetP3(), dp);

			queue.push_back(triProjected);
		}
	}

	sort(queue.begin(), queue.end(), [](Triangle3D &t1, Triangle3D &t2)
	{
		float z1 = t1.GetAverageZ();
		float z2 = t2.GetAverageZ();
		return z1 > z2;
	});

	for (auto tri : queue)
	{
		DrawTriangle2D(tri.ToTriangle2D().ScaleToScreen(), C_BLACK);
		FillTriangle2D(tri.ToTriangle2D().ScaleToScreen(), {tri.GetIllumination(), tri.GetIllumination(), tri.GetIllumination() });
	}

	glutPostRedisplay();

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		fps = frame * 1000.0 / (time - timebase);
		timebase = time;
		frame = 0;
	}

	std::cout << "FPS: " << fps << std::endl;
}
