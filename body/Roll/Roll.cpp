#include "Roll.prog.cpp"
#include "Roll.h"

Roll::Roll(){};

Roll::Roll(int type, float cX, float cY)
{
    this->type = type;
    this->cX = cX;
    this->cY = cY;
    this->x = this->cX - this->mid;
    this->y = this->cY - this->mid;
    if (this->type == 1)
    {
        this->image = roll5;
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
                  this->diameter,
                  this->diameter, SDL_FLIP_NONE,
                  this->conor,
                  255,
                  this->mid,
                  this->mid);

    //  ctx.FillRect(this->cX, this->cY, 3, 3, "violet");
}

void Roll::getWayLength()
{
    PointF a = {this->prevCx, this->prevCy};
    PointF b = {this->cX, this->cY};
    Delta delta = getDeltas(a, b);
    this->way = getDis(delta);
}

void Roll::updateConor()
{
    double deltaConor = (this->way * 360) / this->liner;
    this->conor += deltaConor;

    double moveConorRad = this->rightCont->getConorToRight();
    float toDeg = moveConorRad * 180 / M_PI;
   // console.log("deg = " + to_string(toDeg));
   
    if (this->conor >= 360)
    {
        this->conor = this->conor - 360;
    }
    else if(this->conor <=0)
    {
        this->conor = 360 - this->conor;
    }


};

void Roll::move()
{
    this->getWayLength();
    this->updateConor();

    this->x = this->cX - this->mid;
    this->y = this->cY - this->mid;
}
