#include "Roll.h"

void Roll::prog() {

};

void Roll::impulsForvard()
{

    double conor = this->leftCont->getConorToRight();
    this->cX = this->cX - cos(conor) * this->game->speedKoof;
    this->cY = this->cY - sin(conor) * this->game->speedKoof;
    PointF a = {(float)this->cX, (float)this->cY};
    PointF b = {(float)this->rightCont->wayPoint->x, (float)this->rightCont->wayPoint->y};
    Delta nextContDeltas = getDeltas(a, b);
    float nextContDis = getDis(nextContDeltas);
    if (nextContDis <= 1 * this->game->speedKoof)
    {
        this->cX = this->rightCont->wayPoint->x;
        this->cY = this->rightCont->wayPoint->y;
        if (this->rightCont->right != nullptr)
        {
            this->leftCont = this->rightCont;
            this->rightCont = this->leftCont->right;
        }
    }
}

void Roll::goToSecond()
{
    if (this->rightRoll)
    {
        while (true)
        {
            Roll *secondRoll = this->rightRoll;
            PointF a = {this->cX, this->cY};
            PointF b = {secondRoll->cX, secondRoll->cY};
            Delta deltas = getDeltas(a, b);
            float disToSecondRoll = getDis(deltas);
            if (disToSecondRoll <= 1 * this->game->speedKoof)
            {
                break;
            }
            else
            {
                this->impulsForvard();
            }
        }
        this->rightRoll->impulse = true;
    }
};

void Roll::impulseProg()
{
    this->prevCx = this->cX;
    this->prevCy = this->cY;
    this->goToSecond();

    for (int i = 0; i < this->game->speed; i++)
    {
        this->impulsForvard();
    }
    this->move();
}
