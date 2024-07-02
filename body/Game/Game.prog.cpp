#include "Game.h"

#include "../Roll/Roll.impulseProg.cpp"

int check = 0;

void Game::getWayLine()
{
    if (!this->wayLine->getLength())
    {
        rapid<WayPoint> arr = fs.read<WayPoint>(this->path, sizeof(WayPoint));
        this->wayLine->update(arr, this->level);
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

    if (!this->rolls->getLength() ||
        (disToImpulseRoll && disToImpulseRoll >= this->rolls->getItem(0)->kickDis))
    {
        this->impulseRollCreate();
    }
}

void Game::rollsToProg()
{
    this->rolls = this->rolls->filter([](Roll* roll, int i){
       return roll != nullptr;
    });
    for (int i = 0; i < this->rolls->getLength(); i++)
    {
        Roll *roll = this->rolls->getItem(i);
        if (roll != nullptr)
        {
            if(!roll->del)
            {
                roll->prog(i);
            }
            else
            {
                this->deleteProg(roll);
                this->rolls->reDate(i, nullptr);
            }
        }
        roll = nullptr;
    }
}

void Game::deleteProg(Roll *roll)
{
   delete roll;
   roll = nullptr;
}


void Game::prog()
{
    this->getWayLine();

    this->newRollCreating();

    this->impulseRoll->impulseProg();

    this->rollsToProg();

    // if (this->speed == 100 || this->speed == 0)
    // {
    //     this->speedVector = -this->speedVector;
    // }
    // this->speed += this->speedVector;
    this->station->prog();
}

void Game::impulseRollCreate()
{
    Container *head = this->wayLine->getHead();
    Roll *newRoll = new Roll(intRand(1, 6),
                             head->wayPoint->x,
                             head->wayPoint->y);
    this->impulseRoll = newRoll;
    this->rolls->frontForce(1);
    this->rolls->unshift(newRoll);
    this->rolls->norm();
    newRoll->leftCont = head;
    newRoll->rightCont = head->right;
    newRoll->game = this;
    if (this->rolls->getLength() > 1)
    {
        Roll *secondRoll = this->rolls->getItem(1);
        newRoll->rightRoll = secondRoll;
        secondRoll->leftRoll = newRoll;
    }
    newRoll = nullptr;
    head = nullptr;
}
