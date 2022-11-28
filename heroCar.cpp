#include "heroCar.hpp"
#include "Drawing.hpp"

//Draw the car on the screen 
void heroCar::Draw(){
    for(int i=0;i<b.size();i++)
    {
        b[i]->Draw();
        b[i]->ShootBullets();
    }
    life.Draw();
    score.displayScore();
    ++score;
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    

}

//initializes heroCar according to the sprite values of 
//sports car, bike or wagon.
heroCar::heroCar(int x, int y, int w, int h )
{
    // moverRect = {390,500, 100,120};
    setmoverRect(390,500, 100,120);
    setRect(x,y,w,h);
    // sprite.x = x;
    // sprite.y = y;
    // sprite.w = w;
    // sprite.h = h;
}

//Drive car using arrow keys
void heroCar::DriveHero(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key)
{
    
    // if (key == SDLK_UP)
    // {
    //     if(moverRect.y<0) 
    //         moverRect.y = 800;
    //         //not move out of screen in y axis
    //      moverRect.y-=30;
    // }
    // else if (key == SDLK_DOWN ) {
    //     if(moverRect.y<700) //not move out of screen in y axis
    //     moverRect.y+=30;
    // }

    if (key==SDLK_RIGHT) {
        if(moverRect.x<1200) //not move out of screen in x axis
        moverRect.x+=35;
    }
    else if (key == SDLK_LEFT) {
        if(moverRect.x>200) //not move out of screen in x axis
        moverRect.x-=35;
    }
    else if(key== SDLK_b){
        // if(fram%2==0)
        {
            Bullets *b1=new Bullets(moverRect.x,moverRect.y);
            b.push_back(b1);
            
        }
    }
    fram++;

    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}


// SDL_Rect heroCar::getRect()
// {
//     return moverRect;
// }


