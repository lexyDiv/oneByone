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

    }
}

void Game::rollsToCollisionClear()
{

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