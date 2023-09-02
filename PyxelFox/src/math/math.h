#pragma once

struct vec2 
{

};

struct vec3
{

};

struct vec4
{
	float x;
	float y;
	float z;
	float w;

	vec4(float xVal, float yVal, float zVal, float wVal) {
		x = xVal;
		y = yVal;
		z = zVal;
		w = wVal;
	}

};

struct ivec2
{
	int x = 0;
	int y = 0;

	ivec2(int xval = 0, int yval = 0)
	{
		x = xval;
		y = yval;
	}
};

struct ivec3
{

};
	
struct ivec4
{

};



struct mat2
{

};

struct mat3
{

};

struct mat4
{

};
