#pragma once
#include "bitmap_image.hpp"
#include "vector.h"


class draw
{
public:
	bitmap_image img;
	bitmap_image zbuffer_img;
	std::vector<double> zbuffer;
	int w, h;

	draw(int nw, int nh);

	void point(vec2 p, vec3 color);
	void line(int x0, int y0, int x1, int y1, vec3 color);
	void triangle(vec2 t0, vec2 t1, vec2 t2, vec3 color);

	void save(std::string file);
};

