#include "Roll.h"

void Roll::prog()
{
    if (this->impulse)
    {
        this->impulse = false;

        this->prevCx = this->cX;
        this->prevCy = this->cY;

        PointF a = {this->cX, this->cY};
        PointF b = {this->leftRoll->cX, this->leftRoll->cY};
        Delta deltas = getDeltas(a, b);
        double disToLeftRoll = getDis(deltas);

        while (true)
        {
            PointF a = {this->cX, this->cY};
            PointF b = {this->leftRoll->cX, this->leftRoll->cY};
            Delta deltas = getDeltas(a, b);
            double disToLeftRoll = getDis(deltas);

            if (disToLeftRoll >= this->diameter - 3)
            {
                break;
            }
            else
            {
                this->impulsForvard();
            }
        }

        this->kick();
    }
    this->move();
};

void Roll::impulsForvard()
{

    double conor = this->leftCont->getConorToRight();
    this->cX = this->cX - cos(conor) * this->game->speedKoof;
    this->cY = this->cY - sin(conor) * this->game->speedKoof;
    PointF a = {(double)this->cX, (double)this->cY};
    PointF b = {(double)this->rightCont->wayPoint->x, (double)this->rightCont->wayPoint->y};
    Delta nextContDeltas = getDeltas(a, b);
    double nextContDis = getDis(nextContDeltas);
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
    if (this->rightRoll && !this->debut)
    {
        this->debut = true;
        while (true)
        {
            Roll *secondRoll = this->rightRoll;
            PointF a = {this->cX, this->cY};
            PointF b = {secondRoll->cX, secondRoll->cY};
            Delta deltas = getDeltas(a, b);
            double disToSecondRoll = getDis(deltas);
            if (disToSecondRoll <= this->diameter)
            {
                break;
            }
            else
            {
                this->impulsForvard();
            }
        }
    }
};

void Roll::impulseProg()
{

    this->prevCx = this->cX;
    this->prevCy = this->cY;
    if (this->rightRoll != nullptr)
    {
        this->goToSecond();
    }

    for (int i = 0; i < this->game->speed; i++)
    {
        this->impulsForvard();
    }
    this->kick();
    this->move();
}



void Roll::kick()
{
    if (this->rightRoll != nullptr)
    {
        PointF a = {this->cX, this->cY};
        PointF b = {this->rightRoll->cX, this->rightRoll->cY};
        Delta deltas = getDeltas(a, b);
        double dis = getDis(deltas);
        if (dis < this->kickDis)
        {
            this->rightRoll->impulse = true;
        }
    }
}
