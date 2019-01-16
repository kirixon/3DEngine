#pragma once
#include "Triangle.h"
#include <vector>
#include <fstream>
#include <strstream>

class Mesh
{
public:
	std::vector<Triangle3D> polygons;
	Mesh();
	bool LoadFromFile(std::string);
};

