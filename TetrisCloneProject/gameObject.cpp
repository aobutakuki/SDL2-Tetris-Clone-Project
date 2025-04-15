#include "gameObject.h"

gameObject::gameObject(int x, int y, int w, int h, float velocity, std::string objectType)
{
	stop = false;
	objRect.x = x;
	objRect.y = y;
	objRect.w = w;
	objRect.h = h;

	this->velocity = velocity;

	if (objectType == "Rectangle")
	{
		for (int i = 0; i < 4; i++) {
			mainObj_y.push_back(y);
		}
		
		shapeParts[0] = { x - 10, y, 10, 10 };
		shapeParts[1] = {x, y, 10, 10 };
		shapeParts[2] = { x + 10, y, 10, 10 };
		shapeParts[3] = { x + 20, y, 10, 10 };
	}
}


void gameObject::update() {
	if (!stop) {
		objRect.y += velocity;
		std::cout << "gameObj y = " << objRect.y << "\n";
		for (int i = 0; i < 4; i++) {
			shapeParts[i].y = objRect.y;
			mainObj_y[i] = shapeParts[i].y;
		}
	}
}

void gameObject::checkPos() {

	if (firstObject)
	{
		if (objRect.y >= 460)
		{
			objRect.y = 460;
			stop = true;
			firstObject = false;
		}
	}
	else {
		for (int i = 0; i < mainObj_y.size(); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (shapeParts[j].y == mainObj_y[i] - 10)
				{
					stop = true;
					std::cout << "Obj has been stopped" << "\n";
				}
			}
		}
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
