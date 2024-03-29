#include "mouse.hpp"

//Initializes mouse values 
Mouse::Mouse()
{
    rect.w = 25;
    rect.h = 25;
    point.w = 1;
    point.h = 1;
    SDL_ShowCursor(false);
}

//Update mouse position
void Mouse:: update()
{
    SDL_GetMouseState(&rect.x, &rect.y);
    point.x = rect.x;
    point.y = point.y;
}

//draw mouse
void Mouse:: draw(){

        SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &sprite, &rect);
    }
