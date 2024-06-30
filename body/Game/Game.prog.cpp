#include "Game.h"

#include "../Roll/Roll.impulseProg.cpp"

int check = 0;

void Game::prog()
{
    if (!this->wayLine->getLength())
    {
        rapid<WayPoint> arr = fs.read<WayPoint>(this->path, sizeof(WayPoint));
        this->wayLine->update(arr, this->level);
    }

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

    this->impulseRoll->impulseProg();

    for (int i = 0; i < this->rolls->getLength(); i++)
    {
        Roll *roll = this->rolls->getItem(i);
        if (roll != nullptr)
        {
            roll->prog();
        }
        roll = nullptr;
    }

    if (this->speed == 100 || this->speed == 0)
    {
        this->speedVector = -this->speedVector;
    }
    this->speed += this->speedVector;
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
