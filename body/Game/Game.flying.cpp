#include "../Roll/Roll.impulseProg.cpp"
#include "Game.h"

void Game::getRollsToCheckCollision()
{
    if (this->flyingRoll != nullptr)
    {
       // this->rollsToCollision->backForce(this->rolls->getLength());
        for (int i = 1; i < this->rolls2.size(); i++)
        {
            Roll *roll = this->rolls2[i];
            PointF a = {roll->cX, roll->cY};
            PointF b = {this->flyingRoll->cX, this->flyingRoll->cY};
            Delta deltas = getDeltas(a, b);
            double dis = getDis(deltas);
            if (dis <= roll->diameter + this->flyingRoll->flySpeed * 2
            && roll->show)
            {
                this->rollsToCollision.push_back(roll);
            }
        }
        
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
        for (int i = 0; i < this->rollsToCollision.size(); i++)
        {
            Roll *roll = this->rollsToCollision[i];
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
                //this->pause = true;
                this->unComplite = true;
                this->flyingRoll->father = true;
                roll->sonRoll = this->flyingRoll;
                roll->getConorToSonRoll();
                this->flyingRoll->cX = roll->cX + cos(roll->conorToSonRoll) * roll->kickDis;
                this->flyingRoll->cY = roll->cY + sin(roll->conorToSonRoll) * roll->kickDis;
                roll->getSonPointAndRotation();

                //////////////
                // this->rolls->splice(this->rolls->indexOf(roll) + roll->sonRollPosition,
                //                     this->flyingRoll);
                int index;
                for(int i = 0; i < this->rolls2.size(); i++)
                {
                    if(this->rolls2[i] == roll)
                    {
                        index = i;
                        break;
                    }
                }
                this->rolls2.emplace(this->rolls2.begin()+(index + roll->sonRollPosition),
                this->flyingRoll);
                 this->rollWithSon = roll;
                // if(!roll->sonRollPosition)
                // {
                //     this->flyingRoll->leftRoll = roll->leftRoll;
                //     this->flyingRoll->rightRoll = roll;
                //     this->flyingRoll->leftRoll->rightRoll = this->flyingRoll;
                //     roll->leftRoll = this->flyingRoll;
                // }
                // else
                // {
                //     this->flyingRoll->leftRoll = roll;
                //     this->flyingRoll->rightRoll = roll->rightRoll;
                //     this->flyingRoll->rightRoll->leftRoll = this->flyingRoll;
                //     roll->rightRoll = this->flyingRoll;
                // }
                this->flyingRoll = nullptr;
                roll = nullptr;
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
          //  delete this->flyingRoll;
            this->flyingRoll->del = true;
            this->flyingRoll = nullptr;
        }
    }
}