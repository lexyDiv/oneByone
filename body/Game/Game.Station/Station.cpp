#include "Station.h"

Station::Station(Game *game)
{
    this->game = game;
    this->game->station = this;
}

Station::Station()
{
}

void Station::getPosition(int level)
{
    switch (level)
    {
    case 1:
    {
        this->x = 100;
        this->y = 200;
        return;
    }
    case 2:
    {
        this->x = 100;
        this->y = 200;
        return;
    }
    default:
    {
        this->x = 0;
        this->y = 0;
        return;
    }
    }
}

void Station::prog()
{
    PointF a = {(double)this->x, (double)this->y};
    PointF b = {(double)mouse.x, (double)mouse.y};
    Delta deltas = getDeltas(b, a);
    this->conor = getConor(deltas);
}

void Station::draw() 
{
   // ctx.FillRect(this->x, this->y, 5, 5, "blue");
};