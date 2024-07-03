#include "../Roll/Roll.impulseProg.cpp"
#include "Game.h"

void Roll::getConorToSonRoll()
{
    if (this->sonRoll != nullptr)
    {
    }
}

void Game::getRollsToCheckCollision()
{
    if (this->flyingRoll != nullptr)
    {
        for (int i = 1; i < this->rolls->getLength(); i++)
        {
        }
    }
}



Roll *Game::checkCollision()
{
    if (this->flyingRoll != nullptr)
    {
    }
    return nullptr;
}

void Game::flyingMove()
{
    if (this->flyingRoll != nullptr)
    {
        double moveConor = degToRad(this->flyingRoll->conor);
        for (int i = 0; i < this->flyingRoll->flySpeed; i++)
        {
            this->flyingRoll->cX += cos(moveConor);
            this->flyingRoll->cY += sin(moveConor);
        }
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