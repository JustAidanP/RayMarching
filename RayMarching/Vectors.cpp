#include "Vectors.h"

//------------Declarations------------
//------Constructors------
Vectors::Vec2::Vec2() { x = 0; y = 0; }
Vectors::Vec2::Vec2(float _x, float _y) { this->x = _x; this->y = _y; }
Vectors::Vec2::Vec2(float theta) { this->x = sin(theta); this->y = cos(theta); }
//------Procedures/Functions------
void Vectors::Vec2::rotate(float theta) {
	float X = this->x * cos(-theta) - this->y * sin(-theta);
	float Y = this->x * sin(-theta) + this->y * cos(-theta);
	this->x = X; this->y = Y;
}
float Vectors::Vec2::mag() { return sqrt(this->x * this->x + this->y * this->y); }
float Vectors::Vec2::squaredMag() { return this->x * this->x + this->y * this->y; }
float Vectors::Vec2::dotProduct(Vectors::Vec2& _r) { return this->x * _r.x + this->y * _r.y; }
//------Operators------
Vectors::Vec2 Vectors::Vec2::operator+(const Vectors::Vec2& _r) { Vectors::Vec2 vec; vec.x = this->x + _r.x; vec.y = this->y + _r.y; return vec; }
Vectors::Vec2& Vectors::Vec2::operator+=(const Vectors::Vec2& _r) { this->x += _r.x; this->y += _r.y; return *this; }
Vectors::Vec2 Vectors::Vec2::operator-(const Vectors::Vec2& _r) { Vectors::Vec2 vec; vec.x = this->x - _r.x; vec.y = this->y - _r.y; return vec; }
Vectors::Vec2& Vectors::Vec2::operator-=(const Vectors::Vec2& _r) { this->x -= _r.x; this->y -= _r.y; return *this; }
Vectors::Vec2 Vectors::Vec2::operator==(const Vectors::Vec2& _r) { return this->x == _r.x && this->y == _r.y; }
Vectors::Vec2 Vectors::Vec2::operator!=(const Vectors::Vec2& _r) { return this->x != _r.x || this->y != _r.y; }