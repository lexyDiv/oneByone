#include "../WayLine/WayLine.cpp"
#include "Game.h"

void Game::getWayLine()
{
    if (!this->wayLine->getLength())
    {
        rapid<WayPoint> arr = fs.read<WayPoint>(this->path, sizeof(WayPoint));
        this->wayLine->update(arr, this->level);
        this->station->getPosition(this->level);
    }
}

void Game::newRollCreating()
{
    double disToImpulseRoll = 0.0f;
    if (this->impulseRoll != nullptr)
    {
        WayPoint *head = this->wayLine->getHead()->wayPoint;
        PointF a = {(double)head->x, (double)head->y};
        PointF b = {(double)this->impulseRoll->cX, (double)this->impulseRoll->cY};
        Delta deltas = getDeltas(a, b);
        disToImpulseRoll = getDis(deltas);
    }

    if (!this->rolls2.size() ||
        (disToImpulseRoll && disToImpulseRoll >= this->rolls2[0]->kickDis)
        //this->rolls->getItem(0)->kickDis)
        )
    {
        if (this->check < 3)
        {
            this->impulseRollCreate();
            // this->check++;
        }
    }
}

void Game::rollsToProg()
{
    for (int i = 1; i < this->rolls2.size(); i++)
    {
        Roll *roll = this->rolls2[i];
        //  if (roll != nullptr)
        //  {
        // if (!roll->del)
        // {
            roll->prog(i);
        // }
        // else
        // {
        //     if(roll == this->rollWithSon)
        //     {
        //         this->unComplite = false;
        //     }
        //     this->deleteProg(roll);
        //     this->rolls->reDate(i, nullptr);
        //     this->needFilter = true;
        // }
        // }
        roll = nullptr;
    }

    if (this->needFilter)
    {
        this->rolls->filter([](Roll *roll, int i)
                            { return roll != nullptr; });
        this->needFilter = false;
    }
}

void Game::deleteProg(Roll *roll)
{
    delete roll;
    roll = nullptr;
}

void Game::prog()
{
    // if(this->unComplite)
    // {
    //     this->pause = true;
    // }
    this->getWayLine();

    this->newRollCreating();

    if (this->impulseRoll != nullptr)
    {
        this->impulseRoll->impulseProg();
    }


     this->rollsToProg();


     this->station->prog();
     this->getRollsToCheckCollision();
     this->flyingMove();
     this->flyingOutDel();
    if (this->rollWithSon != nullptr)
    {
        this->rollWithSon->sonRollProg();
    }
     this->rollsToCollision.clear();
}



void Game::impulseRollCreate()
{
    Container *head = this->wayLine->getHead();
    Roll *newRoll = new Roll(intRand(1, 6),
                             head->wayPoint->x,
                             head->wayPoint->y);
    this->impulseRoll = newRoll;
    this->rolls2.emplace(this->rolls2.begin(), newRoll);
    newRoll->leftCont = head;
    newRoll->rightCont = head->right;
    newRoll->game = this;
    if (this->rolls2.size() > 1)
    {
        Roll *secondRoll = this->rolls2[1];
        newRoll->rightRoll = secondRoll;
        secondRoll->leftRoll = newRoll;
    }
    newRoll = nullptr;
    head = nullptr;
}
