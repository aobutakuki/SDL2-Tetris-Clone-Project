#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>

class gameObject
{
private:
	const int TILESIZE = 20;
	const int OFFSET_Y = 40;
	const int OFFSET_X = 230;
	std::array<std::array<bool, 10>, 20> grid = {};
	

	// Convert grid coordinates to screen pixels
	SDL_Point GridToScreen(int gridX, int gridY) {
		return { gridX * TILESIZE + OFFSET_X,
				gridY * TILESIZE + OFFSET_Y };
	}

	// Convert screen pixels to grid coordinates
	SDL_Point ScreenToGrid(int pixelX, int pixelY) {
		return { (pixelX - OFFSET_X) / TILESIZE,
				(pixelY - OFFSET_Y) / TILESIZE };
	}



	SDL_Rect objRect;
	SDL_Rect shapeParts[4];
	int j;
	float velocity = 1;
	bool stop = false;
	bool firstObject = true;

public:
	//Store game objects inside an array rect for different shapes

	gameObject(int x, int y, int w, int h, float velocity,std::string objectType);

	virtual void update();

	virtual void checkPos();

	virtual bool checkStop()  const { return stop; };

	virtual void render(SDL_Renderer* renderer);


	void getObjInfo() {
		std::cout << " " << objRect.x << " , " << objRect.y << " , " << objRect.w << " , " << objRect.h << " , " << velocity << " , " << "OBJECTINFO!" << std::endl;
	}

};

