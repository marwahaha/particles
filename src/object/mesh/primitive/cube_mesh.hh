#pragma once

#include "src/object/mesh/indiced_mesh.hh"

const float cube_vert[] = {
	-1.000000,
	-1.000000,
	1.000000,
	-1.000000,
	1.000000,
	1.000000,
	-1.000000,
	-1.000000,
	-1.000000,
	-1.000000,
	1.000000,
	-1.000000,
	1.000000,
	-1.000000,
	1.000000,
	1.000000,
	1.000000,
	1.000000,
	1.000000,
	-1.000000,
	-1.000000,
	1.000000,
	1.000000,
	-1.000000,
};

const float cube_normals[] = {
	-1.0000,
	0.0000,
	0.0000,
	0.0000,
	0.0000,
	-1.0000,
	1.0000,
	0.0000,
	0.0000,
	0.0000,
	0.0000,
	1.0000,
	0.0000,
	-1.0000,
	0.0000,
	0.0000,
	1.0000,
	0.0000,
};

const GLuint cube_ind[] = {
	1, 2, 0, 3, 6, 2, 7, 4, 6, 5, 0, 4,
	6, 0, 2, 3, 5, 7, 1, 3, 2, 3, 7, 6,
	7, 5, 4, 5, 1, 0, 6, 4, 0, 3, 1, 5
};

const float cube_uv[] = {
	0.000200,
	0.666866,
	0.333134,
	0.999800,
	0.000200,
	0.999800,
	0.666866,
	0.000200,
	0.999800,
	0.333134,
	0.666866,
	0.333134,
	0.333134,
	0.666467,
	0.000200,
	0.333533,
	0.333134,
	0.333533,
	0.666467,
	0.666467,
	0.333533,
	0.333533,
	0.666467,
	0.333533,
	0.333533,
	0.333134,
	0.666467,
	0.000200,
	0.666467,
	0.333134,
	0.000200,
	0.333134,
	0.333134,
	0.000200,
	0.333134,
	0.333134,
	0.333134,
	0.666866,
	0.999800,
	0.000200,
	0.000200,
	0.666467,
	0.333533,
	0.666467,
	0.333533,
	0.000200,
	0.000200,
	0.000200,
};

class CubeMesh : public IndicedMesh {
public:
	CubeMesh()
		: IndicedMesh(
			  std::unique_ptr<std::vector<float>>(new std::vector<float>(cube_vert, cube_vert + sizeof(cube_vert) / sizeof(cube_vert[0]))),
			  std::unique_ptr<std::vector<GLuint>>(new std::vector<GLuint>(cube_ind, cube_ind + sizeof(cube_ind) / sizeof(cube_ind[0]))),
			  GL_TRIANGLES, 3)
	{
	}

	~CubeMesh() {}
};