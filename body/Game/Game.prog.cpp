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

    if (!this->rolls->getLength() ||
        (disToImpulseRoll && disToImpulseRoll >= this->rolls->getItem(0)->kickDis))
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

    if (this->needFilter)
    {
        this->rolls->filter([](Roll *roll, int i)
                            { return roll != nullptr; });
        this->needFilter = false;
    }

    for (int i = 1; i < this->rolls->getLength(); i++)
    {
        Roll *roll = this->rolls->getItem(i);
      //  if (roll != nullptr)
      //  {
            if (!roll->del)
            {
                roll->prog(i);
            }
            else
            {
                this->deleteProg(roll);
                this->rolls->reDate(i, nullptr);
                this->needFilter = true;
            }
       // }
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

    if (this->impulseRoll != nullptr && !this->impulseRoll->del)
    {
        this->impulseRoll->impulseProg();
    }
    else
    {
        if (this->impulseRoll != nullptr)
        {
            this->deleteProg(impulseRoll);
            this->rolls->reDate(0, nullptr);
            this->impulseRoll = nullptr;
            this->endLevel = true;
            this->needFilter = true;
        }
    }

    this->rollsToProg();

    // if (this->speed == 150 || this->speed == 0)
    // {
    //     this->speedVector = -this->speedVector;
    // }
    // this->speed += this->speedVector;

    this->station->prog();
    this->getRollsToCheckCollision();
    this->flyingMove();
    this->flyingOutDel();
  //  this->rollsToCollisionClear();  // !!
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
