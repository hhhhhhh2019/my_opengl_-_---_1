#pragma once
#include "vector.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "draw.h"


class model
{
public:
	std::vector<vec3> vertex;
	std::vector<int> faces;

	model(std::vector<vec3> v, std::vector<int> f);
	model(std::string file);

	void show(draw &draw, int w, int h);
};

