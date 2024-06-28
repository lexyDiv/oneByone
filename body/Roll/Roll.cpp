#include "Roll.prog.cpp"
#include "Roll.h"

Roll::Roll()
{
};

Roll::Roll(int type, float cX, float cY)
{
    this->type = type;
    this->cX = cX;
    this->cY = cY;
    this->x = this->cX - this->mid;
    this->y = this->cY - this->mid;
    if (this->type == 1)
    {
        this->image = new Image("src/roll5.png");
    }
}


void Roll::draw()
{
    ctx.DrawImage(this->image, 
    this->animX, 
    this->animY, 
    this->animW, 
    this->animH, 
    this->x, 
    this->y, 
    this->radius, 
    this->radius, SDL_FLIP_NONE, 
    this->conor, 
    255, 
    this->mid, 
    this->mid);

    ctx.FillRect(this->cX, this->cY, 3, 3, "green");
}
