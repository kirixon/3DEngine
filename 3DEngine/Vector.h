#pragma once

#include <iostream>
#include <math.h>

class Vector2D
{
private:
	float x, y;
public:
	Vector2D();
	Vector2D(float, float);
	Vector2D operator+(Vector2D);
	Vector2D operator-(Vector2D);
	Vector2D operator*(float);
	float GetX();
	float GetY();
	float Length();
};

class Vector3D
{
private:
	float x, y, z;
public:
	Vector3D();
	Vector3D(float, float, float);
	Vector3D operator+(Vector3D);
	Vector3D operator-(Vector3D);
	Vector3D operator*(float);
	float GetX();
	float GetY();
	float GetZ();
	float Length();
	void Normalize();
	float DotProduct(Vector3D);
	Vector3D CrossProduct(Vector3D);
	Vector2D ToVector2D();
};

