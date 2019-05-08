#include "Entities.h"
#include "Vectors.h"

//------Entities::Wall------
Entities2D::Wall::Wall(Vectors::Vec2 _position, Vectors::Vec2 _scale) { this->position = _position; this->scale = _scale; }
float Entities2D::Wall::sdfSquared(Vectors::Vec2 &point) {
	float dx = fmin(fmax(point.x, this->position.x), this->position.x + this->scale.x);
	float dy = fmin(fmax(point.y, this->position.y), this->position.y + this->scale.y);
	return powf(dx - point.x, 2) + powf(dy - point.y, 2);
}

//------Entities::Camera------
Entities2D::Camera::Camera(Vectors::Vec2 _position, float _angle) { this->position = _position; this->angle = _angle; }
Vectors::Vec2 Entities2D::Camera::getDirectionVec() { return Vectors::Vec2(this->angle); }