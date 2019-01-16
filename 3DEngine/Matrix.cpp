#include "Matrix.h"

Matrix4x4::Matrix4x4()
{
}

Matrix4x4::Matrix4x4(float init[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->matrix[i][j] = init[i][j];
		}
	}
}

Matrix4x4 Matrix4x4::operator*(Matrix4x4 mat)
{
	Matrix4x4 newmat;

	newmat.matrix[0][0] = this->matrix[0][0] * mat.matrix[0][0] + this->matrix[0][1] * mat.matrix[1][0] + this->matrix[0][2] * mat.matrix[2][0] + this->matrix[0][3] * mat.matrix[3][0];
	newmat.matrix[0][1] = this->matrix[0][0] * mat.matrix[0][1] + this->matrix[0][1] * mat.matrix[1][1] + this->matrix[0][2] * mat.matrix[2][1] + this->matrix[0][3] * mat.matrix[3][1];
	newmat.matrix[0][2] = this->matrix[0][0] * mat.matrix[0][2] + this->matrix[0][1] * mat.matrix[1][2] + this->matrix[0][2] * mat.matrix[2][2] + this->matrix[0][3] * mat.matrix[3][2];
	newmat.matrix[0][3] = this->matrix[0][0] * mat.matrix[0][3] + this->matrix[0][1] * mat.matrix[1][3] + this->matrix[0][2] * mat.matrix[2][3] + this->matrix[0][3] * mat.matrix[3][3];
	
	newmat.matrix[1][0] = this->matrix[1][0] * mat.matrix[0][0] + this->matrix[1][1] * mat.matrix[1][0] + this->matrix[1][2] * mat.matrix[2][0] + this->matrix[1][3] * mat.matrix[3][0];
	newmat.matrix[1][1] = this->matrix[1][0] * mat.matrix[0][1] + this->matrix[1][1] * mat.matrix[1][1] + this->matrix[1][2] * mat.matrix[2][1] + this->matrix[1][3] * mat.matrix[3][1];
	newmat.matrix[1][2] = this->matrix[1][0] * mat.matrix[0][2] + this->matrix[1][1] * mat.matrix[1][2] + this->matrix[1][2] * mat.matrix[2][2] + this->matrix[1][3] * mat.matrix[3][2];
	newmat.matrix[1][3] = this->matrix[1][0] * mat.matrix[0][3] + this->matrix[1][1] * mat.matrix[1][3] + this->matrix[1][2] * mat.matrix[2][3] + this->matrix[1][3] * mat.matrix[3][3];

	newmat.matrix[2][0] = this->matrix[2][0] * mat.matrix[0][0] + this->matrix[2][1] * mat.matrix[1][0] + this->matrix[2][2] * mat.matrix[2][0] + this->matrix[2][3] * mat.matrix[3][0];
	newmat.matrix[2][1] = this->matrix[2][0] * mat.matrix[0][1] + this->matrix[2][1] * mat.matrix[1][1] + this->matrix[2][2] * mat.matrix[2][1] + this->matrix[2][3] * mat.matrix[3][1];
	newmat.matrix[2][2] = this->matrix[2][0] * mat.matrix[0][2] + this->matrix[2][1] * mat.matrix[1][2] + this->matrix[2][2] * mat.matrix[2][2] + this->matrix[2][3] * mat.matrix[3][2];
	newmat.matrix[2][3] = this->matrix[2][0] * mat.matrix[0][3] + this->matrix[2][1] * mat.matrix[1][3] + this->matrix[2][2] * mat.matrix[2][3] + this->matrix[2][3] * mat.matrix[3][3];

	newmat.matrix[3][0] = this->matrix[3][0] * mat.matrix[0][0] + this->matrix[3][1] * mat.matrix[1][0] + this->matrix[3][2] * mat.matrix[2][0] + this->matrix[3][3] * mat.matrix[3][0];
	newmat.matrix[3][1] = this->matrix[3][0] * mat.matrix[0][1] + this->matrix[3][1] * mat.matrix[1][1] + this->matrix[3][2] * mat.matrix[2][1] + this->matrix[3][3] * mat.matrix[3][1];
	newmat.matrix[3][2] = this->matrix[3][0] * mat.matrix[0][2] + this->matrix[3][1] * mat.matrix[1][2] + this->matrix[3][2] * mat.matrix[2][2] + this->matrix[3][3] * mat.matrix[3][2];
	newmat.matrix[3][3] = this->matrix[3][0] * mat.matrix[0][3] + this->matrix[3][1] * mat.matrix[1][3] + this->matrix[3][2] * mat.matrix[2][3] + this->matrix[3][3] * mat.matrix[3][3];

	return newmat;
}

Vector3D Matrix4x4::operator*(Vector3D vec)
{
	float x = vec.GetX() * this->matrix[0][0] + vec.GetY() * this->matrix[1][0] + vec.GetZ() * this->matrix[2][0] + this->matrix[3][0];
	float y = vec.GetX() * this->matrix[0][1] + vec.GetY() * this->matrix[1][1] + vec.GetZ() * this->matrix[2][1] + this->matrix[3][1];
	float z = vec.GetX() * this->matrix[0][2] + vec.GetY() * this->matrix[1][2] + vec.GetZ() * this->matrix[2][2] + this->matrix[3][2];
	float w = vec.GetX() * this->matrix[0][3] + vec.GetY() * this->matrix[1][3] + vec.GetZ() * this->matrix[2][3] + this->matrix[3][3];

	if (w != 0.0f)
	{
		x /= w;
		y /= w;
		z /= w;
	}

	return Vector3D(x, y, z);
}

void Matrix4x4::GenProjectionMat(float aspectratio, float fovrad, float zfar, float znear)
{
	this->matrix[0][0] = aspectratio * fovrad;
	this->matrix[1][1] = fovrad;
	this->matrix[2][2] = zfar / (zfar - znear);
	this->matrix[3][2] = (-zfar * znear) / (zfar - znear);
	this->matrix[2][3] = 1.0f;
}

void Matrix4x4::GenRotationMatZ(float angle)
{
	this->matrix[0][0] = cosf(angle);
	this->matrix[0][1] = sinf(angle);
	this->matrix[1][0] = -sinf(angle);
	this->matrix[1][1] = cosf(angle);
	this->matrix[2][2] = 1.0f;
	this->matrix[3][3] = 1.0f;
}

void Matrix4x4::GenRotationMatX(float angle)
{
	this->matrix[0][0] = 1.0f;
	this->matrix[1][1] = cosf(angle);
	this->matrix[1][2] = sinf(angle);
	this->matrix[2][1] = -sinf(angle);
	this->matrix[2][2] = cosf(angle);
	this->matrix[3][3] = 1.0f;
}

void Matrix4x4::GenPointAtMat(Vector3D pos, Vector3D target, Vector3D up)
{
	Vector3D newForward = target - pos;
	newForward.Normalize();

	Vector3D a = newForward * up.DotProduct(newForward);
	Vector3D newup = up - a;
	newup.Normalize();

	Vector3D newright = newup.CrossProduct(newForward);

	this->matrix[0][0] = newright.GetX();
	this->matrix[0][1] = newright.GetY();
	this->matrix[0][2] = newright.GetZ();
	this->matrix[0][3] = 0.0f;
	this->matrix[1][0] = newup.GetX();
	this->matrix[1][1] = newup.GetY();
	this->matrix[1][2] = newup.GetZ();
	this->matrix[1][3] = 0.0f;
	this->matrix[2][0] = newForward.GetX();
	this->matrix[2][1] = newForward.GetY();
	this->matrix[2][2] = newForward.GetZ();
	this->matrix[2][3] = 0.0f;
	this->matrix[3][0] = pos.GetX();
	this->matrix[3][1] = pos.GetY();
	this->matrix[3][2] = pos.GetZ();
	this->matrix[3][3] = 1.0f;
}

void Matrix4x4::GenShiftMat(Vector3D vec)
{
	this->matrix[0][0] = 1.0f;
	this->matrix[1][1] = 1.0f;
	this->matrix[2][2] = 1.0f;
	this->matrix[3][3] = 1.0f;
	this->matrix[3][0] = vec.GetX();
	this->matrix[3][1] = vec.GetY();
	this->matrix[3][2] = vec.GetZ();
}

void Matrix4x4::GenIdentity()
{
	this->matrix[0][0] = 1.0f;
	this->matrix[1][1] = 1.0f;
	this->matrix[2][2] = 1.0f;
	this->matrix[3][3] = 1.0f;
}

Matrix4x4 Matrix4x4::DumbInverse()
{
	Matrix4x4 inverted;

	inverted.matrix[0][0] = this->matrix[0][0];
	inverted.matrix[1][1] = this->matrix[1][1];
	inverted.matrix[2][2] = this->matrix[2][2];
	inverted.matrix[3][3] = 1.0f;

	inverted.matrix[0][1] = this->matrix[1][0];
	inverted.matrix[0][2] = this->matrix[2][0];
	inverted.matrix[1][0] = this->matrix[0][1];
	inverted.matrix[1][2] = this->matrix[2][1];
	inverted.matrix[2][0] = this->matrix[0][2];
	inverted.matrix[2][1] = this->matrix[1][2];

	inverted.matrix[3][0] = -(this->matrix[3][0] * inverted.matrix[0][0] + this->matrix[3][1] * inverted.matrix[1][0] + this->matrix[3][2] * inverted.matrix[2][0]);
	inverted.matrix[3][1] = -(this->matrix[3][0] * inverted.matrix[0][1] + this->matrix[3][1] * inverted.matrix[1][1] + this->matrix[3][2] * inverted.matrix[2][1]);
	inverted.matrix[3][2] = -(this->matrix[3][0] * inverted.matrix[0][2] + this->matrix[3][1] * inverted.matrix[1][2] + this->matrix[3][2] * inverted.matrix[2][2]);

	return inverted;
}

