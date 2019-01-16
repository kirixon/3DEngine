#pragma once
#include <GL/glut.h>
#include "Triangle.h"
#include "Mesh.h"
#include "Matrix.h"
#include "Camera.h"
#include <algorithm>

//Screen specs
#define WIDTH 1920
#define HEIGHT 1080
#define FOV 90.0f 
#define ZNEAR 0.1f
#define ZFAR 1000.0f

//Basic colors
#define C_BLACK {0.0f, 0.0f, 0.0f} 
#define C_WHITE {1.0f, 1.0f, 1.0f} 
#define C_GRAY  {0.5f, 0.5f, 0.5f} 

class Drawer
{
private:
	int frame = 0, time, timebase = 0;
	float fps;
	float aratio = (float)HEIGHT / (float)WIDTH;
	float fovrad = 1.0f / tanf(FOV * 0.5f / 180.0f * 3.14159f);
	Matrix4x4 ProjectionMat;
	Matrix4x4 RotMatZ, RotMatX;
	Camera cam;
public:
	Drawer();
	void DrawAll();
	Mesh cube;
};

typedef struct
{
	float r, g, b;
} Color;
