#include "../Roll/Roll.impulseProg.cpp"
#include "Game.h"

void Game::getRollsToCheckCollision()
{
    this->rollsToCollisionClear();
    if (this->flyingRoll != nullptr)
    {
        this->rollsToCollision->backForce(20);
        for (int i = 1; i < this->rolls->getLength(); i++)
        {
            Roll *roll = this->rolls->getItem(i);
            PointF a = {this->flyingRoll->cX, this->flyingRoll->cY};
            PointF b = {roll->cX, roll->cY};
            Delta deltas = getDeltas(a, b);
            double dis = getDis(deltas);
            if (dis <= this->flyingRoll->flySpeed + this->flyingRoll->diameter)
            {
                this->rollsToCollision->push(roll);
            }
            roll = nullptr;
        }
        this->rollsToCollision->norm();
         console.log("length = " + to_string(this->rollsToCollision->getLength()));
    }
}

void Game::rollsToCollisionClear()
{
    for (int i = 0; i < this->rollsToCollision->getLength(); i++)
    {
        Roll *rl = this->rollsToCollision->getItem(i);
        if (rl != nullptr)
        {
            this->rollsToCollision->reDate(i, nullptr);
            rl = nullptr;
        }
    }
    this->rollsToCollision->clear();
}

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