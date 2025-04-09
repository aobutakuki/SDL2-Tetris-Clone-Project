#pragma once
#include <SDL.h>
#include <iostream>

class gameObject
{
private:
	SDL_Texture* objTexture;
	SDL_Rect objRect;
	float velocity;
public:
	gameObject(int x, int y, int w, int h, float velocity = 0) :objRect{ x,y,w,h }, velocity(velocity), objTexture(nullptr) {};

	virtual ~gameObject() { if (objTexture)SDL_DestroyTexture(objTexture); }

	virtual void update();

	virtual void render(SDL_Renderer* renderer);


	void getObjInfo() {
		std::cout << " " << objRect.x << " , " << objRect.y << " , " << objRect.w << " , " << objRect.h << " , " << velocity << " , " << "OBJECTINFO!" << std::endl;
	}

};

