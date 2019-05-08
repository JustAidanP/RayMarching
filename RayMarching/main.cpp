#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Entities.h"
#include "Vectors.h"

class Example : public olc::PixelGameEngine {
//------Variables/Constants------
public:
	Entities2D::Camera camera;
	Entities2D::Wall walls[9];

//------Decorators------
public:
	Example() {sAppName = "Example";}

//------Procedures/Functions------
public:
	//Called once at the start, so create things here
	bool OnUserCreate() override {
		camera = Entities2D::Camera::Camera(Vectors::Vec2(100, 100), 0.5 * Vectors::PI);
		//walls[4] = Entities2D::Wall(Vectors::Vec2(100, 100), Vectors::Vec2(20, 100));
		//walls[5] = Entities2D::Wall(Vectors::Vec2(350, 350), Vectors::Vec2(100, 20));
		//walls[6] = Entities2D::Wall(Vectors::Vec2(400, 250), Vectors::Vec2(50, 50));
		//walls[7] = Entities2D::Wall(Vectors::Vec2(450, 420), Vectors::Vec2(100, 20));
		//walls[8] = Entities2D::Wall(Vectors::Vec2(600, 300), Vectors::Vec2(20, 100));
		walls[4] = Entities2D::Wall(Vectors::Vec2(100, 100), Vectors::Vec2(500, 20));
		walls[5] = Entities2D::Wall(Vectors::Vec2(100, 100), Vectors::Vec2(20, 400));
		walls[6] = Entities2D::Wall(Vectors::Vec2(100, 450), Vectors::Vec2(600, 20));
		walls[7] = Entities2D::Wall(Vectors::Vec2(600, 200), Vectors::Vec2(20, 350));
		walls[8] = Entities2D::Wall(Vectors::Vec2(300, 300), Vectors::Vec2(100, 100));
		//Creates border walls
		walls[0] = Entities2D::Wall(Vectors::Vec2(0, 0), Vectors::Vec2(ScreenWidth(), 1));
		walls[1] = Entities2D::Wall(Vectors::Vec2(0, 0), Vectors::Vec2(1, ScreenHeight()));
		walls[2] = Entities2D::Wall(Vectors::Vec2(ScreenWidth(), 0), Vectors::Vec2(1, ScreenHeight()));
		walls[3] = Entities2D::Wall(Vectors::Vec2(0, ScreenHeight()), Vectors::Vec2(ScreenWidth(), 1));
		return true;
	}
	//Called every frame, passing a deltatime
	bool OnUserUpdate(float _deltaTime) override {
		//Sets the camera's position to that of the mouse
		this->camera.position.x = GetMouseX();
		this->camera.position.y = GetMouseY();
		this->camera.angle += (float)GetMouseWheel() / 1200;
		//this->camera.angle += _deltaTime * 0.5;
		//Clears the screen
		Clear(olc::BLACK);
		
		//Draws the camera position
		FillCircle(this->camera.position.x, this->camera.position.y, 10, olc::WHITE);
		Vectors::Vec2 camDir = camera.getDirectionVec();
		DrawLine(this->camera.position.x, this->camera.position.y, this->camera.position.x + camDir.x * 50, this->camera.position.y + camDir.y * 50, olc::GREEN);
		
		//Draws the walls
		for (int i = 0; i < 9; i++) {
			//FillRect(this->walls[i].position.x, this->walls[i].position.y, this->walls[i].scale.x, this->walls[i].scale.y, olc::BLUE);
		}
		for (int degree = 0; degree < 1440; degree++) {
			//Calculates the degree in radians
			const float rad = (degree - 720) / 4 * Vectors::PI / 180;
			//Performs ray marching
			const int maxIter = 20;
			//Defines the current ray march iteration
			int counter = 0;
			//Defines the starting point
			Vectors::Vec2 startingP = this->camera.position;
			while (counter < maxIter) {
				//Calculates the shortest distance to the nearest wall
				float sd = NULL;
				for (int i = 0; i < 9; i++) {
					const float dist = sqrt(this->walls[i].sdfSquared(startingP));
					if (sd == NULL || sd > dist) {
						sd = dist;
					}
				}
				//Draws a circle at the starting point with a radius of the shortest distance
				DrawCircle(startingP.x, startingP.y, sd, olc::MAGENTA);
				//Adds to the starting point to place it at the edge of the circle
				startingP += Vectors::Vec2(this->camera.angle + rad) * sd;
				//Breaks if the sd if less that 1
				if (sd <= 4 && sd > 3) {
					Draw(startingP.x, startingP.y, olc::VERY_DARK_GREY);
				}
				if (sd <= 3 && sd > 2) {
					Draw(startingP.x, startingP.y, olc::DARK_GREY);
				}
				if (sd <= 2 && sd > 1) {
					Draw(startingP.x, startingP.y, olc::GREY);
				}
				if (sd <= 1 || sd > ScreenWidth()) {
					//FillCircle(startingP.x, startingP.y, 3, olc::WHITE);
					Draw(startingP.x, startingP.y, olc::WHITE);
					break;
				}
				counter++;
			}
		}
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