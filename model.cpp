#include "model.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


model::model(std::vector<vec3> v, std::vector<int> f)
{
	this->vertex = v;
	this->faces = f;
}


model::model(std::string file)
{
	std::ifstream in;
	in.open(file, std::ifstream::in);
	if (in.fail()) return;

	std::string line;

	while (!in.eof())
	{
		std::getline(in, line);
		std::istringstream iss(line.c_str());

		char trash;

		if (!line.compare(0, 2, "v ")) {
			iss >> trash;
			vec3 v;
			iss >> v.x;
			iss >> v.y;
			iss >> v.z;
			this->vertex.push_back(v);
		}
		else if (!line.compare(0, 2, "f ")) {
			int f, t, n;
			iss >> trash;
			int cnt = 0;
			while (iss >> f >> trash >> t >> trash >> n) {
				this->faces.push_back(--f);
				cnt++;
			}
			if (3 != cnt) {
				std::cerr << "Error: the obj file is supposed to be triangulated" << std::endl;
				in.close();
				return;
			}
		}
	}

	in.close();
}


float dot(vec3 a, vec3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}


vec3 get_norm(vec3 a, vec3 b, vec3 c)
{
	vec3 ab = b - a;
	vec3 bc = b - c;
	return ab * bc;
}


float get_light(vec3 a, vec3 b, vec3 c, vec3 ld)
{
	vec3 n = get_norm(a, b, c);
	return dot(n, ld) * 0.9 + 0.6;
}


void model::show(draw &image, int width, int height)
{
	image_drawer zdraw(image.zbuffer_img);

	for (int f = 0; f < this->faces.size(); f += 3)
	{
		float l = get_light(this->vertex[this->faces[f]], this->vertex[this->faces[f+1]], this->vertex[this->faces[f+2]], vec3(1, 1, 0));

		if (l > 0)
		{
			vec2 points[3];

			for (int v = 0; v < 3; v++)
			{
				int vert = this->faces[f + v];
				vec3 vertex = this->vertex[vert];

				points[v] = vec2((vertex.x + 1) * width / 2, (vertex.y + 1) * height / 2);
				//points[v] = vec2(vertex.x / vertex.z, vertex.y / vertex.z);

				points[v].y = height - points[v].y;
			}

			image.triangle(points[0], points[1], points[2], vec3(255 * l, 255 * l, 255 * l));
		}
	}

	for (int i = 0; i < width * height; i++)
	{
		int x = i % width;
		int y = i / width;
		zdraw.pen_width(1);
		zdraw.pen_color((image.zbuffer[i]+0.5)*255, (image.zbuffer[i]+0.5)*255, (image.zbuffer[i]+0.5)*255);
		zdraw.plot_pixel(x, y);
	}

	image.save("obj_output.bmp");
	image.save("zbuffer.bmp");
}
