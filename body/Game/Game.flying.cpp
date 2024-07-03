#include "../Roll/Roll.impulseProg.cpp"
#include "Game.h"

void Game::flyingMove()
{
    if (this->flyingRoll != nullptr)
    {
        this->flyingRoll->cX += cos(degToRad(this->flyingRoll->conor)) * this->flyingRoll->flySpeed;
        this->flyingRoll->cY += sin(degToRad(this->flyingRoll->conor)) * this->flyingRoll->flySpeed;
        this->flyingRoll->x = this->flyingRoll->cX - this->flyingRoll->mid;
        this->flyingRoll->y = this->flyingRoll->cY - this->flyingRoll->mid;
    }
}

void Game::flyingOutDel()
{
    if (this->flyingRoll != nullptr)
    {
        double x = this->flyingRoll->x;
        double y = this->flyingRoll->y;
        int gab = this->flyingRoll->diameter;
        if (x > ctx.SCREEN_WIDTH || x + gab < 0 || y > ctx.SCREEN_HEIGHT || y + gab < 0)
        {
            delete this->flyingRoll;
            this->flyingRoll = nullptr;
        }
    }
}