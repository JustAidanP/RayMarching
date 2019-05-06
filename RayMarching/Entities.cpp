#include "Entities.h"
#include "Vectors.h"

//------Entities::Wall------
Entities2D::Wall::Wall() {}

//------Entities::Camera------a
Entities2D::Camera::Camera(Vectors::Vec2 _position, float _angle) {
	this->position = _position;
	this->angle = _angle;
}