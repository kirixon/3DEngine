#pragma once

#include "Vector.h"

class Triangle2D
{
private:
	Vector2D p1, p2, p3;
public:
	Triangle2D(Vector2D, Vector2D, Vector2D);
	Vector2D GetP1();
	Vector2D GetP2();
	Vector2D GetP3();
	Triangle2D ScaleToScreen();
};

class Triangle3D
{
private:
	Vector3D p1, p2, p3;
	float illumination;
public:
	Triangle3D(Vector3D, Vector3D, Vector3D);
	Triangle3D(Vector3D, Vector3D, Vector3D, float);
	Triangle2D ToTriangle2D();
	Vector3D GetP1();
	Vector3D GetP2();
	Vector3D GetP3();
	Vector3D GetNormal();
	float GetAverageZ();
	float GetIllumination();
	void Print();
};

