#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Entities.h"
#include "Vectors.h"

class Example : public olc::PixelGameEngine {
//------Variables/Constants------
public:
	Entities2D::Camera camera;

//------Decorators------
public:
	Example() {sAppName = "Example";}

//------Procedures/Functions------
public:
	//Called once at the start, so create things here
	bool OnUserCreate() override {
		camera = Entities2D::Camera::Camera(Vectors::Vec2(100, 100), 0.5 * Vectors::PI);
		return true;
	}
	//Called every frame, passing a deltatime
	bool OnUserUpdate(float _deltaTime) override {
		Clear(olc::BLACK);
		//Draws the camera position
		FillCircle(this->camera.position.x, this->camera.position.y, 50, olc::WHITE);
		DrawLine(this->camera.position.x, this->camera.position.y, this->camera.position.x + sin(this->camera.angle) * 50, this->camera.position.y + cos(this->camera.angle) * 50, olc::GREEN);
		return true;
	}

};





int main() {
	Example demo;
	if (demo.Construct(1280, 720, 1, 1)) {
		demo.Start();
	}

	return 0;
}