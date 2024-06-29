#include "Game.h"

#include "../Roll/Roll.impulseProg.cpp"


bool cc = false;

void Game::prog()
{
    if (!this->wayLine->getLength())
    {
        rapid<WayPoint> arr = fs.read<WayPoint>(this->path, sizeof(WayPoint));
        this->wayLine->update(arr);
    }

    float disToImpulseRoll = 0.0f;
    if (this->impulseRoll != nullptr)
    {
        WayPoint *head = this->wayLine->getHead()->wayPoint;
        PointF a = {(float)head->x, (float)head->y};
        PointF b = {(float)this->impulseRoll->cX, (float)this->impulseRoll->cY};
        Delta deltas = getDeltas(a, b);
        disToImpulseRoll = getDis(deltas);
    }



    if (!this->rolls->getLength()
    ||
    (disToImpulseRoll && disToImpulseRoll >= this->impulseRoll->diameter))
    {
        this->impulseRollCreate();
    }

    this->impulseRoll->impulseProg();
}

void Game::impulseRollCreate()
{
    Container *head = this->wayLine->getHead();
    Roll *newRoll = new Roll(1,
                             head->wayPoint->x,
                             head->wayPoint->y);
    this->impulseRoll = newRoll;
     this->rolls->frontForce(1);
     this->rolls->unshift(newRoll);
     this->rolls->norm();
    //this->rollsV.insert(this->rollsV.begin(), newRoll);
    newRoll->leftCont = head;
    newRoll->rightCont = head->right;
    newRoll->game = this;
    if (this->rolls->getLength() > 1)
    {
        newRoll->rightRoll = this->rolls->getItem(1);
    }
    newRoll = nullptr;
    head = nullptr;
    console.log("create");
}
