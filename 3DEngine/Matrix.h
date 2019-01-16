#pragma once

#include "Vector.h"

class Matrix4x4
{
private:
	float matrix[4][4] = { 0 };
public:
	Matrix4x4();
	Matrix4x4(float init[4][4]);
	void GenProjectionMat(float, float, float, float);
	void GenRotationMatZ(float);
	void GenRotationMatX(float);
	void GenShiftMat(Vector3D);
	void GenPointAtMat(Vector3D, Vector3D, Vector3D);
	void GenIdentity();
	Matrix4x4 DumbInverse();
	Vector3D operator*(Vector3D);
	Matrix4x4 operator*(Matrix4x4);
};

