#pragma once
class vec2
{
public:
	double x, y;

	vec2();
	vec2(double x);
	vec2(double x, double y);

	vec2 operator+(vec2 other);
	//vec3 operator+(vec3 other);

	vec2 operator-(vec2 other);
	//vec3 operator-(vec3 other);

	vec2 operator*(vec2 other);
	vec2 operator*(double other);

	vec2 operator/(vec2 other);
	vec2 operator/(double other);
};


class vec3
{
public:
	double x, y, z;

	vec3();
	vec3(double x);
	vec3(double x, double y, double z);
	vec3(vec2 xy);
	vec3(vec2 xy, double z);

	vec3 operator+(vec3 other);
	vec3 operator+(vec2 other);

	vec3 operator-(vec3 other);
	vec3 operator-(vec2 other);

	vec3 operator*(vec3 other);
	vec3 operator*(double other);

	vec3 operator/(vec3 other);
	vec3 operator/(double other);
};
