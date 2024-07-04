#include "../Roll/Roll.impulseProg.cpp"
#include "Game.h"



void Game::getRollsToCheckCollision()
{
    if (this->flyingRoll != nullptr)
    {
        this->rollsToCollision->backForce(this->rolls->getLength());
        for (int i = 1; i < this->rolls->getLength(); i++)
        {
            Roll *roll = this->rolls->getItem(i);
            PointF a = {roll->cX, roll->cY};
            PointF b = {this->flyingRoll->cX, this->flyingRoll->cY};
            Delta deltas = getDeltas(a, b);
            double dis = getDis(deltas);
            if (dis <= roll->diameter + this->flyingRoll->flySpeed * 2)
            {
                this->rollsToCollision->push(roll);
            }
        }
        this->rollsToCollision->norm();
        // if(this->rollsToCollision->getLength())
        // {
        //     console.log("length = " + to_string(this->rollsToCollision->getLength()));
        // }
    }
}

Roll *Game::checkCollision()
{
    if (this->flyingRoll != nullptr)
    {
        for (int i = 0; i < this->rollsToCollision->getLength(); i++)
        {
            Roll *roll = this->rollsToCollision->getItem(i);
            PointF a = {this->flyingRoll->cX, this->flyingRoll->cY};
            PointF b = {roll->cX, roll->cY};
            Delta deltas = getDeltas(a, b);
            double dis = getDis(deltas);
            if (dis <= roll->kickDis)
            {
                return roll;
            }
            roll = nullptr;
        }
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
            Roll *roll = this->checkCollision();
            if (roll != nullptr)
            {
                this->pause = true;
                this->unComplite = true;
                this->flyingRoll->father = true;
                roll->sonRoll = this->flyingRoll;
                roll->getConorToSonRoll();
                this->flyingRoll->cX = roll->cX + cos(roll->conorToSonRoll) * roll->kickDis;
                this->flyingRoll->cY = roll->cY + sin(roll->conorToSonRoll) * roll->kickDis;
                this->rolls->splice(this->rolls->indexOf(roll) + 1, this->flyingRoll);
                this->flyingRoll = nullptr;
                roll->getSonPointAndRotation();
                return;
            }
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