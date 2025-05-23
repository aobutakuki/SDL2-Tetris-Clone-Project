#pragma once
#include <SDL.h>
#include <iostream>
#include <string>

class gameObject
{
private:
	SDL_Texture* objTexture;
	SDL_Rect objRect;
	SDL_Rect shapeParts[4];
	int j;
	float velocity = 1;

public:
	//Store game objects inside an array rect for different shapes

	gameObject(int x, int y, int w, int h, float velocity,std::string objectType);

	virtual ~gameObject() { if (objTexture)SDL_DestroyTexture(objTexture); }

	virtual void update();

	virtual void render(SDL_Renderer* renderer);


	void getObjInfo() {
		std::cout << " " << objRect.x << " , " << objRect.y << " , " << objRect.w << " , " << objRect.h << " , " << velocity << " , " << "OBJECTINFO!" << std::endl;
	}

};

