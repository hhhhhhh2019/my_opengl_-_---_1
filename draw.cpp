#include "draw.h"
#include <math.h>
#include <iostream>
#include <cmath>


draw::draw(int nw, int nh)
{
	this->w = nw;
	this->h = nh;
	this->img = bitmap_image(nw, nh);
	this->zbuffer_img = bitmap_image(nw, nh);
    
    for (int i = 0; i < w * h; i++)
    {
        zbuffer.push_back(std::numeric_limits<int>::min());
    }
}


void draw::point(vec2 p, vec3 color)
{
    image_drawer drawer(img);
	drawer.pen_width(1);
	drawer.pen_color(color.x, color.y, color.z);
	drawer.plot_pixel(p.x, p.y);
}





void draw::line(int x0, int y0, int x1, int y1, vec3 color) {
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1 - x0;
    int dy = y1 - y0;
    int derror2 = std::abs(dy) * 2;
    int error2 = 0;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        if (steep) {
            point(vec2(y, x), color);
        }
        else {
            point(vec2(x, y), color);
        }
        error2 += derror2;

        if (error2 > dx) {
            y += (y1 > y0 ? 1 : -1);
            error2 -= dx * 2;
        }
    }
}



void draw::triangle(vec2 t0, vec2 t1, vec2 t2, vec3 color)
{
    if (t0.y == t1.y && t0.y == t2.y) return; // i dont care about degenerate triangles
    // sort the vertices, t0, t1, t2 lower-to-upper (bubblesort yay!)
    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);
    int total_height = t2.y - t0.y;
    for (int i = 0; i < total_height; i++) {
        bool second_half = i > t1.y - t0.y || t1.y == t0.y;
        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y;
        float alpha = (float)i / total_height;
        float beta = (float)(i - (second_half ? t1.y - t0.y : 0)) / segment_height; // be careful: with above conditions no division by zero here
        vec2 A = t0 + (t2 - t0) * alpha;
        vec2 B = second_half ? t1 + (t2 - t1) * beta : t0 + (t1 - t0) * beta;
        if (A.x > B.x) std::swap(A, B);
        for (int j = A.x; j <= B.x; j++) {
            double phi = B.x == A.x ? 1. : (float)(j - A.x) / (float)(B.x - A.x);
            vec3 P = A + (B - A) * phi;
            P.x = int(P.x);P.y = int(P.y);P.z = int(P.z);
            int idx = std::min(std::max(0, int(P.x + P.y * w)), w*h-1);
            if (zbuffer[idx] < P.z) {
                zbuffer[idx] = P.z;
                P.x = j; P.y = t0.y + i;
                point(vec2(P.x, P.y), color); // attention, due to int casts t0.y+i != A.y
            }
        }
    }
}


void draw::save(std::string file)
{
    img.save_image(file);
}
