#pragma once
#include "Vectors.h"

//Defines a namespace for all entities
namespace Entities2D {
	class Wall {
		//------Variables/Constants------
		public:
			//Stores the position of the wall
			Vectors::Vec2 position;
			//Stores the scale of the wall as a 2-dimensional vector
			Vectors::Vec2 scale;
		//------Constructors------
		public:
			Wall() {}
			Wall(Vectors::Vec2 _position, Vectors::Vec2 _scale);
		//------Procedures/Functions------
		public:
			//Returns the shortest squared distance between a point and the wall
			float sdfSquared(Vectors::Vec2 &point);
	};
	//Defines a 2D camera
	class Camera {
		//------Variables/Constants------
		public:
			//Stores the position of the camera
			Vectors::Vec2 position;
			//Stores the angle of the camera
			float angle = 0;

		//------Constructors------
		public:
			Camera() {}
			Camera(Vectors::Vec2 _position, float _angle);
		//------Procedures/Functions------
		public:
			//Returns the direction vector
			Vectors::Vec2 getDirectionVec();
	};
}