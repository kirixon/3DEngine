#include "Triangle.h"

/* Triangle2D Class */

Triangle2D::Triangle2D(Vector2D p1, Vector2D p2, Vector2D p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}


Vector2D Triangle2D::GetP1()
{
	return this->p1;
}

Vector2D Triangle2D::GetP2()
{
	return this->p2;
}

Vector2D Triangle2D::GetP3()
{
	return this->p3;
}

Triangle2D Triangle2D::ScaleToScreen()
{
	Vector2D shift(1.0f, 1.0f);

	this->p1 = this->p1 + shift;
	this->p2 = this->p2 + shift;
	this->p3 = this->p3 + shift;

	Vector2D p1(this->p1.GetX() * 0.5f * 1920.0f, this->p1.GetY() * 0.5f * 1080.0f);
	Vector2D p2(this->p2.GetX() * 0.5f * 1920.0f, this->p2.GetY() * 0.5f * 1080.0f);
	Vector2D p3(this->p3.GetX() * 0.5f * 1920.0f, this->p3.GetY() * 0.5f * 1080.0f);

	return Triangle2D(p1, p2, p3);
}

/* Triangle3D Class */

Triangle3D::Triangle3D(Vector3D p1, Vector3D p2, Vector3D p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

Triangle3D::Triangle3D(Vector3D p1, Vector3D p2, Vector3D p3, float illumination)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->illumination = illumination;
}

Triangle2D Triangle3D::ToTriangle2D()
{
	return Triangle2D(this->p1.ToVector2D(), this->p2.ToVector2D(), this->p3.ToVector2D());
}

Vector3D Triangle3D::GetP1()
{
	return this->p1;
}

Vector3D Triangle3D::GetP2()
{
	return this->p2;
}

Vector3D Triangle3D::GetP3()
{
	return this->p3;
}

Vector3D Triangle3D::GetNormal()
{
	Vector3D l1 = this->p2 - this->p1;
	Vector3D l2 = this->p3 - this->p1;
	Vector3D normal(l1.GetY() * l2.GetZ() - l1.GetZ() * l2.GetY(), l1.GetZ() * l2.GetX() - l1.GetX() * l2.GetZ(), l1.GetX() * l2.GetY() - l1.GetY() * l2.GetX());
	normal.Normalize();

	return normal;
}

float Triangle3D::GetAverageZ()
{
	return ((this->p1.GetZ() + this->p2.GetZ() + this->p3.GetZ()) / 3.0f);
}

float Triangle3D::GetIllumination()
{
	return this->illumination;
}

void Triangle3D::Print()
{
	std::cout << "Triangle [ ( " << this->GetP1().GetX() << ", " << this->GetP1().GetY() << ", " << this->GetP1().GetZ() << " ), ( " << this->GetP2().GetX() << ", " << this->GetP2().GetY() << ", " << this->GetP2().GetZ() << " ), ( " << this->GetP3().GetX() << ", " << this->GetP3().GetY() << ", " << this->GetP3().GetZ() << " ) ]" << std::endl;
}
