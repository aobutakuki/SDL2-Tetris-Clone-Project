#include "gameObject.h"

gameObject::gameObject(int x, int y, int w, int h, float velocity, std::string objectType)
{
	objRect.x = x;
	objRect.y = y;
	objRect.w = w;
	objRect.h = h;

	this->velocity = velocity;

	if (objectType == "Rectangle")
	{
		
		shapeParts[0] = { x - 10, y, 10, 10 };
		shapeParts[1] = {x, y, 10, 10 };
		shapeParts[2] = { x + 10, y, 10, 10 };
		shapeParts[3] = { x + 20, y, 10, 10 };
	}
}


void gameObject::update() {
	objRect.y += velocity;

	for (int i = 0; i < 4; i++) {
		shapeParts[i].y = objRect.y;
	}
}

void gameObject::render(SDL_Renderer* renderer) {
	if (objTexture)
	{
		SDL_RenderCopy(renderer, objTexture, NULL, &objRect);
	}
	else
	{
		for (int i = 0; i < 4; i++) {
			objRect = shapeParts[i];
			
			
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderFillRect(renderer, &objRect);
		}
		
		
	}
}
