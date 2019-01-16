#include "Camera.h"

Camera::Camera()
{
	lookdir = Vector3D(0.0f, 0.0f, 1.0f);
}

Camera::Camera(float x, float y, float z)
{
	this->point = Vector3D(x, y, z);
}

Vector3D Camera::GetPoint()
{
	return this->point;
}

Vector3D Camera::GetLookDir()
{
	return this->lookdir;
}