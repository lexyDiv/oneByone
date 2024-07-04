#include "../Game/Game.prog.cpp"
#include "Roll.h"

void Roll::getConorToSonRoll()
{
    if (this->sonRoll != nullptr)
    {
        PointF a = {this->cX, this->cY};
        PointF b = {this->sonRoll->cX, this->sonRoll->cY};
        Delta deltas = getDeltas(a, b);
        this->conorToSonRoll = getConor(deltas);
    }
}

PointF *Roll::getRightSonPoint()
{
    Roll *rightRoll = new Roll(1, this->cX, this->cY);
    rightRoll->leftRoll = this;
    rightRoll->leftCont = this->leftCont;
    rightRoll->rightCont = this->rightCont;
    rightRoll->game = this->game;
    rightRoll->forvardMove();
    PointF *rightSonPoint = new PointF{rightRoll->cX, rightRoll->cY};
    this->game->LR[1] = rightSonPoint;
    delete rightRoll;
    rightRoll = nullptr;
    return rightSonPoint;
}

PointF *Roll::getLeftSonPoint()
{
    Roll *leftRoll = new Roll(1, this->cX, this->cY);
    // leftRoll->rightRoll = this;
    leftRoll->rightCont = this->rightCont;
    leftRoll->leftCont = this->leftCont;
    leftRoll->game = this->game;
    /////
    while (true)
    {
        PointF a = {this->cX, this->cY};
        PointF b{leftRoll->cX, leftRoll->cY};
        Delta deltas = getDeltas(a, b);
        double dis = getDis(deltas);
        if (dis >= this->kickDis)
        {
            PointF *point = new PointF{leftRoll->cX, leftRoll->cY};
            this->game->LR[0] = point;
            return point;
        }
        else
        {
            leftRoll->impulseBack();
          
        }
    }
    /////

    return nullptr;
}

void Roll::getSonPointAndRotation()
{
    if (this->sonRoll && this->leftCont != nullptr && this->rightCont != nullptr)
    {
        PointF *rightSonPoint = this->getRightSonPoint();
        PointF *leftSonPoint = this->getLeftSonPoint();
    }
}