#include "gameObject.h"

void gameObject::update() {
	objRect.y += velocity;
}

void gameObject::render(SDL_Renderer* renderer) {
	if (objTexture)
	{
		SDL_RenderCopy(renderer, objTexture, NULL, &objRect);
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &objRect);
		
	}
}
