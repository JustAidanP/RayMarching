#pragma once
#include <cmath>

//Defines a vectors namespace
namespace Vectors {
	//Stores a constant PI
	const float PI = 3.14159;
	//Defines a 2 dimensional vector
	struct Vec2 {
		//------Variables/Constants------
		float x = 0; float y = 0;
		
		//------Constructors------
		//Creates a vector with default 0 values
		Vec2();
		//Creates a vector with a given x and y
		Vec2(float _x, float _y);
		//Creates a vector from an angle clockwise from the positive y-axis
		Vec2(float theta);
		
		//------Procedures/Functions------
		//Rotates the vector
		void rotate(float theta);
		//Gets the angle between this vector and another
		float getAngle(Vec2 &_r);
		//Finds the magnitude of the vector
		float mag();
		//Finds the squared magnitude of the vector
		float squaredMag();
		//Finds the dot product of two vectors
		float dotProduct(Vec2& _r);

		//------Operators------
		Vec2 operator+(const Vec2& _r);
		Vec2& operator+=(const Vec2& _r);
		Vec2 operator-(const Vec2& _r);
		Vec2& operator-=(const Vec2& _r);
		Vec2 operator*(const float&f);
		Vec2 operator==(const Vec2& _r);
		Vec2 operator!=(const Vec2& _r);
	};
}






