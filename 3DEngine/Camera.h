#pragma once

#include "Vector.h"

class Camera
{
private:
	Vector3D point;
	Vector3D lookdir;
public:
	Camera();
	Camera(float, float, float);
	Vector3D GetPoint();
	Vector3D GetLookDir();
};

