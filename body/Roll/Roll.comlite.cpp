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

PointF* Roll::getRightSonPoint()
{
    Roll *rightRoll = new Roll(1, this->cX, this->cY);
    rightRoll->leftRoll = this;
    rightRoll->leftCont = this->leftCont;
    rightRoll->rightCont = this->rightCont;
    rightRoll->game = this->game;
    rightRoll->impulsForvard();
    PointF* rightSonPoint = new PointF{rightRoll->cX, rightRoll->cY};
    this->game->LR[1] = rightSonPoint;
    delete rightRoll;
    rightRoll = nullptr;
    return rightSonPoint;
}

void Roll::getSonPointAndRotation()
{
    if (this->sonRoll && this->leftCont != nullptr && this->rightCont != nullptr)
    {
       PointF *rightSonPoint = this->getRightSonPoint();
    }
}