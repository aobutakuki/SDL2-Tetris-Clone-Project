#include "gameObject.h"

gameObject::gameObject(int x, int y, int w, int h, float velocity, std::string objectType)
{
	stop = false;
	objRect.x = x;
	objRect.y = y;
	objRect.w = w;
	objRect.h = h;

	this->velocity = velocity;

	int size = 20;
	if (objectType == "Rectangle")
	{
	
		shapeParts[0] = { x - size, y, size, size };
		shapeParts[1] = {x, y, size, size };
		shapeParts[2] = { x + size, y, size, size };
		shapeParts[3] = { x + (size * 2), y, size, size };
	}
}


void gameObject::update() {
	if (!stop) {
		objRect.y += velocity;
		std::cout << "gameObj y = " << objRect.y << "\n";
		for (int i = 0; i < 4; i++) {
			shapeParts[i].y = objRect.y;
		}
	}
}

void gameObject::checkPos() {

	if (firstObject)
	{
		if (objRect.y >= 420)
		{
			objRect.y = 420;
			stop = true;
			firstObject = false;
			for (int i = 0; i < 4; i++)
			{
				SDL_Point point = ScreenToGrid(shapeParts[i].x, shapeParts[i].y);
				grid[point.y][point.x] = true;
				std::cout << "Grid point taken || Y: " << point.y << " / X: " << point.x << "\n";
			}
		}
	}

}


void gameObject::render(SDL_Renderer* renderer) {
for (int i = 0; i < 4; i++) {
			objRect = shapeParts[i];
			
			
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderFillRect(renderer, &objRect);

	
}
