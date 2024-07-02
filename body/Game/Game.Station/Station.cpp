#include "../../Listenner.h"

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
        this->x = 250;
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
    PointF a = {(double)this->x + 100, (double)this->y + 100};
    PointF b = {(double)mouse.x, (double)mouse.y};
    Delta deltas = getDeltas(b, a);
    this->conor = radToDeg(getConor(deltas)) + 90;
}

void Station::draw()
{
    ctx.DrawImage(ass,
                  0,
                  0,
                  1200,
                  1200,
                  this->x,
                  this->y,
                  this->gabX,
                  this->gabY,
                  SDL_FLIP_NONE,
                  this->conor,
                  255,
                  this->gabX / 2,
                  this->gabY / 2);
};