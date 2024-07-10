#include "../Game/Game.cpp"
#include "Roll.h"

void Roll::localDelProg()
{
    if(this->localDel > 1)
    {
        this->localDel--;
    }
    else if(this->localDel == 1)
    {
        this->show = false;
    }
}

Roll::Roll(){};

Roll::Roll(int type, double cX, double cY)
{
    this->type = type;
    this->cX = cX;
    this->cY = cY;
    this->x = this->cX - this->mid;
    this->y = this->cY - this->mid;
    this->image = this->getImage(this->type);
}

Roll::~Roll()
{
    // if(this->isLast)
    // {
    //     if(this->leftRoll != nullptr)
    //     {
    //         this->leftRoll->rightRoll = nullptr;
    //     }
    // }
    this->image = nullptr;
    this->leftCont = nullptr;
    this->rightCont = nullptr;
    this->leftRoll = nullptr;
    this->rightRoll = nullptr;
    this->image = nullptr;
     // console.log("Roll * deleted !!!");
}

void Roll::draw(int i)
{
    if (this->show)
    {
        this->getDrawPosition();
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
//ctx.DrawText(this->cX - 25, this->cY - 25, 50, to_string(i));
    }
    // ctx.FillRect(this->cX, this->cY, 3, 3, "yellow");
}

Image *Roll::getImage(int type)
{
    switch (type)
    {
    case 1:
        return roll5;
    case 2:
        return roll6;
    case 3:
        return roll7;
    case 4:
        return roll8;
    case 5:
        return roll9;
    case 6:
        return roll10;
    default:
        return roll5;
    }
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
            !this->speed ? this->rotation = 1 : this->rotation = -1;
        }
        else
        {
            !this->speed ? this->rotation = -1 : this->rotation = 1;
        }
    }
}

void Roll::updateConor()
{
    this->getRotation();

    double deltaConor = (this->way * 360) / this->liner;
    this->conor += deltaConor * this->rotation;

    if (this->conor > 360)
    {
        this->conor = this->conor - 360;
    }
    if (this->conor <= -360)
    {
        this->conor = this->conor + 360;
    }
};

void Roll::getDrawPosition()
{
    this->x = this->cX - this->mid;
    this->y = this->cY - this->mid;
}

void Roll::move()
{
    this->getWayLength();
    this->updateConor();
}
