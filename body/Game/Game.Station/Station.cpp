#include "../../Groups/Group.cpp"

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
        this->y = 400;
        return;
    }
    case 2:
    {
       this->x = 250;
       this->y = 200;
        //  this->x = ctx.SCREEN_WIDTH - 200;
        //  this->y = 50;
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
    if (this->roll == nullptr &&
        this->game->flyingRoll == nullptr &&
        !this->game->unComplite)
    {
        this->roll = new Roll(1, (double)this->x + this->gabX / 2,
                              (double)this->y + this->gabY / 2);
        //this->game->rollsOnDelete.push_back(roll);
        this->game->pushOnRollsOnDelete(this->roll);
        this->roll->game = this->game;
        this->roll->conor = this->conor;
    }
    else if (this->roll != nullptr)
    {
        this->roll->conor = this->conor;
        if (mouse.leftKeyDown)
        {
            this->roll->conor += 90;
            this->game->flyingRoll = this->roll;
            this->roll = nullptr;
        }
    }
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

    if (this->roll != nullptr)
    {
        this->roll->draw();
    }
};