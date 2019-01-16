#include "Mesh.h"

Mesh::Mesh()
{
}

bool Mesh::LoadFromFile(std::string filename)
{
	std::ifstream f(filename);
	if (!f.is_open())
		return false;

	std::vector<Vector3D> vertices;

	while (!f.eof())
	{
		char line[256];
		f.getline(line, 256);
		std::strstream s;
		s << line;

		char junk;

		if (line[0] == 'v')
		{
			float x, y, z;
			s >> junk >> x >> y >> z;
			vertices.push_back(Vector3D(x, y, z));
		}

		if (line[0] == 'f')
		{
			int p[3];
			s >> junk >> p[0] >> p[1] >> p[2];
			this->polygons.push_back(Triangle3D(vertices[p[0] - 1], vertices[p[1] - 1], vertices[p[2] - 1]));
		}
	}

	return true;
}