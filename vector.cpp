#include "vector.h"


vec2::vec2()
{
	this->x = 0;
	this->y = 0;
}


vec2::vec2(double x)
{
	this->x = x;
	this->y = x;
}


vec2::vec2(double x, double y)
{
	this->x = x;
	this->y = y;
}


vec2 vec2::operator+(vec2 other)
{
	return vec2(this->x + other.x, this->y + other.y);
}


/*vec3 vec2::operator+(vec3 other)
{
	return vec3(this->x + other.x, this->y + other.y, other.z);
}*/


vec2 vec2::operator-(vec2 other)
{
	return vec2(this->x - other.x, this->y - other.y);
}


/*vec3 vec2::operator-(vec3 other)
{
	return vec3(this->x - other.x, this->y - other.y, other.z);
}*/


vec2 vec2::operator*(vec2 other)
{
	return vec2(this->x * other.x, this->y * other.y);
}


vec2 vec2::operator*(double other)
{
	return vec2(this->x * other, this->y * other);
}


vec2 vec2::operator/(vec2 other)
{
	return vec2(this->x / other.x, this->y / other.y);
}


vec2 vec2::operator/(double other)
{
	return vec2(this->x / other, this->y / other);
}



vec3::vec3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}


vec3::vec3(double x)
{
	this->x = x;
	this->y = x;
	this->z = x;
}


vec3::vec3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


vec3::vec3(vec2 xy)
{
	this->x = xy.x;
	this->y = xy.y;
	this->z = 0;
}


vec3::vec3(vec2 xy, double z)
{
	this->x = xy.x;
	this->y = xy.y;
	this->z = z;
}


vec3 vec3::operator+(vec3 other)
{
	return vec3(this->x + other.x, this->y + other.y, this->z + other.z);
}


vec3 vec3::operator+(vec2 other)
{
	return vec3(this->x + other.x, this->y + other.y, this->z);
}


vec3 vec3::operator-(vec3 other)
{
	return vec3(this->x - other.x, this->y - other.y, this->z - other.z);
}


vec3 vec3::operator-(vec2 other)
{
	return vec3(this->x - other.x, this->y - other.y, this->z);
}


vec3 vec3::operator*(vec3 other)
{
	return vec3(this->x * other.x, this->y * other.y, this->z * other.z);
}


vec3 vec3::operator*(double other)
{
	return vec3(this->x * other, this->y * other, this->z * other);
}


vec3 vec3::operator/(vec3 other)
{
	return vec3(this->x / other.x, this->y / other.y, this->z / other.z);
}


vec3 vec3::operator/(double other)
{
	return vec3(this->x / other, this->y / other, this->z / other);
}
