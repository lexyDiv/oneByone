#include "Roll.h"

void Roll::prog() {

};

void Roll::impulseProg()
{
    float speedKoof = 0.3;
    this->prevCx = this->cX;
    this->prevCy = this->cY;
    for (int i = 0; i < this->game->speed; i++)
    {
        double conor = this->leftCont->getConorToRight();
        this->cX = this->cX - cos(conor) * speedKoof;
        this->cY = this->cY - sin(conor) * speedKoof;
        PointF a = {(float)this->cX, (float)this->cY};
        PointF b = {(float)this->rightCont->wayPoint->x, (float)this->rightCont->wayPoint->y};
        Delta nextContDeltas = getDeltas(a, b);
        float nextContDis = getDis(nextContDeltas);
        if (nextContDis <= 1 * speedKoof)
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
    this->move();
}


