#pragma once
#include "Vectors.h"

//Defines a namespace for all entities
namespace Entities2D {
	class Wall {
		//------Variables/Constants------
		//------Constructors------
		public:
			Wall();
		//------Procedures/Functions------
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
	};
}