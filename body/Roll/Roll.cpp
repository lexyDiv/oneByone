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

void Roll::getRotation()
{
    if (this->vector)
    {
        WayPoint *next = this->rightCont->wayPoint;
        WayPoint *prev = this->leftCont->wayPoint;
        if (next->x > prev->x)
        {
            this->rotation = 1;
        }
        else
        {
            this->rotation = -1;
        }
    }
}

void Roll::updateConor()
{
    this->getRotation();

    double deltaConor = (this->way * 360) / this->liner;
    this->conor += deltaConor * this->rotation;

    double moveConorRad = this->rightCont->getConorToRight();
    float toDeg = moveConorRad * 180 / M_PI;
    // console.log("deg = " + to_string(toDeg));

    // if (this->conor > 0)
    // {
    //     if (this->conor > 360)
    //     {
    //         this->conor = this->conor - 360;
    //     }
    // }
    // else if (this->conor < 0)
    // {
    // }

    if (this->conor > 360)
    {
        this->conor = this->conor - 360;
    }
     if (this->conor <= -360)
    {
       // console.log("conor before = " + to_string(this->conor));
        this->conor = this->conor + 360;
       // console.log("conor past = " + to_string(this->conor));
    }

    // if ((int)this->conor % 360 == 0)
    // {
    //     double full = this->conor / 360;
    //     double deltaTail = full - (int)full;
    //     console.log("deltaTale = " + to_string(deltaTail));
    //    if(this->conor > 0)
    //    {
    //     this->conor =  deltaTail;
    //    }
    //     console.log("format");
    // }
   // console.log("conor = " + to_string(this->conor));
};

void Roll::move()
{
    this->getWayLength();
    this->updateConor();

    this->x = this->cX - this->mid;
    this->y = this->cY - this->mid;
}
