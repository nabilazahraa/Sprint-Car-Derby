#include "NormalCar.hpp"
#include<iostream>
#include<SDL.h>
#pragma once
void NormalCar::Draw()
{
    //choose sprite from 3 sprites randomly
    if(random==0)
    {
        setRect(sprite1.x, sprite1.y, sprite1.w, sprite1.h);  

    }
    if(random==1)
    {
        setRect(sprite2.x, sprite2.y, sprite2.w, sprite2.h);    
    }
    if(random==2)
    {
        setRect(sprite3.x, sprite3.y, sprite3.w, sprite3.h); 
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

NormalCar::NormalCar(int x)
{  
    // int r=300+(rand()%900);
    // int r = rand()%3;
    if(x ==1)
    {
        moverRect={390,800, 100, 120};
    }
    else{
        moverRect={780,800, 100, 120};
    }
    
}

void NormalCar::DriveNormalCar(car *h, SDL_Rect car,int dir)
{
    if(moverRect.y<0)
    {
        //if normal car goes out of screen
        //normal car comes back on the screen
        moverRect.y= 800; 
        moverRect.x+= 100;
        if(moverRect.x>900)
        {
            moverRect.x = 390;
        }
        
        random=rand()%3; 
    }
    if(Mask(h) == false)
    {
        //prevent normal car from crashing into police car
        if(moverRect.x+10 == car.x ||moverRect.x-10 ==car.x || moverRect.x ==car.x)
        {
            if(dir == -1)
            {   //move car to right
                moverRect.x+=50;
            }
            else
            {   //move car to left
                moverRect.x -=50;
            }
        }
    
        moverRect.y -= 10;
    }
}

//collision of normal car with hero car
bool NormalCar::Mask(car* h)
{
    bool collision = SDL_HasIntersection(getMoverRect(), h->getMoverRect());
    if(collision == true)
    { 
        h->DecreaseScore();
    }
    return collision;
}

