#include "Roll.sonRoll.prog.cpp"
#include "Roll.h"

void Roll::prog(int index)
{

    if (!this->father)
    {
        // this->speed = 0;
        this->impulse = false;

        this->prevCx = this->cX;
        this->prevCy = this->cY;

        PointF a = {this->cX, this->cY};
        PointF b = {this->leftRoll->cX, this->leftRoll->cY};
        Delta deltas = getDeltas(a, b);
        long double disToLeftRoll = getDis(deltas);

        this->speed += 3;

        this->sonRollRotation();

        this->forvardMove();

        this->move();
    }
};

void Roll::forvardMove()
{
    int iter = 0;
    while (true)
    {
        PointF a = {this->cX, this->cY};
        PointF b = {this->leftRoll->cX, this->leftRoll->cY};
        Delta deltas = getDeltas(a, b);
        long double disToLeftRoll = getDis(deltas);

        long double dis = 1000;

        if (this->sonRoll != nullptr)
        {
            this->sonRollCXCorrect();
            a = {this->sonRoll->cX, this->sonRoll->cY};
            deltas = getDeltas(a, b);
            dis = getDis(deltas);
        }

        if (this->leftRoll->sonRoll != nullptr)
        {
            b = {this->leftRoll->sonRoll->cX, this->leftRoll->sonRoll->cY};
            deltas = getDeltas(a, b);
            dis = getDis(deltas);
        }

        if (disToLeftRoll >= this->kickDis && dis >= this->kickDis)
        {
            break;
        }
        else
        {
            this->impulsForvard();
            // if(iter)
            // {
            this->speed = 0;
            //}
        }
    }
    this->reversMove();
}

void Roll::reversMove()
{
    for (int i = 0; i < this->speed; i++)
    {

        PointF a = {this->cX, this->cY};
        PointF b = {this->leftRoll->cX, this->leftRoll->cY};
        Delta deltas = getDeltas(a, b);
        long double dis = getDis(deltas);
        long double dis2 = 1000;

        if (this->sonRoll != nullptr)
        {
            this->sonRollCXCorrect();
            a = {this->sonRoll->cX, this->sonRoll->cY};
            deltas = getDeltas(a, b);
            dis2 = getDis(deltas);
        }

        if (this->leftRoll->sonRoll)
        {
            b = {this->leftRoll->sonRoll->cX, this->leftRoll->sonRoll->cY};
            deltas = getDeltas(a, b);
            dis2 = getDis(deltas);
        }

        if (dis <= this->kickDis || dis2 <= this->kickDis)
        {
            break;
        }
        else
        {
            this->impulseBack();
            // PointF a = {(long double)this->leftCont->wayPoint->x,
            // (long double)this->leftCont->wayPoint->y};
            // PointF b = {this->cX, this->cY};
            // Delta daltas = getDeltas(a, b);
            // long double conor = getConor(deltas);
            // this->cX = this->cX + cos(conor) * this->game->speedKoof;
            // this->cY = this->cY + sin(conor) * this->game->speedKoof;
        }
    }
}

void Roll::impulsForvard()
{

    if (this->rightCont != nullptr &&
        (int)this->cX == this->rightCont->wayPoint->x &&
        (int)this->rightCont->wayPoint->y == this->cY)
    {
        this->cX = this->rightCont->wayPoint->x;
        this->cY = this->rightCont->wayPoint->y;
        this->leftCont = this->rightCont;
        this->rightCont = this->leftCont->right;
    }

    long double conor = this->leftCont->getConorToRight();
    this->cX = this->cX - cos(conor) * this->game->speedKoof;
    this->cY = this->cY - sin(conor) * this->game->speedKoof;
    PointF a = {(long double)this->cX, (long double)this->cY};
    PointF b = {(long double)this->rightCont->wayPoint->x,
                (long double)this->rightCont->wayPoint->y};
    Delta nextContDeltas = getDeltas(a, b);
    long double nextContDis = getDis(nextContDeltas);
    if (nextContDis <= 1 * this->game->speedKoof)
    {
        if (this->rightCont->right != nullptr)
        {
            this->cX = this->rightCont->wayPoint->x;
            this->cY = this->rightCont->wayPoint->y;
            this->leftCont = this->rightCont;
            this->rightCont = this->leftCont->right;
        }
        else
        {
            this->del = true;
            if (this->sonRoll)
            {
                this->sonRoll->del = true;
            }
        }
    }
}

void Roll::impulseBack()
{

    if ((int)this->cX == this->leftCont->wayPoint->x &&
        (int)this->cY == this->leftCont->wayPoint->y)
    {
        this->cX = this->leftCont->wayPoint->x;
        this->cY = this->leftCont->wayPoint->y;
        this->rightCont = this->leftCont;
        this->leftCont = this->rightCont->left;
    }

    long double conor = this->rightCont->getConorToLeft();
    this->cX = this->cX - cos(conor) * this->game->speedKoof;
    this->cY = this->cY - sin(conor) * this->game->speedKoof;
    PointF a = {(long double)this->leftCont->wayPoint->x,
                (long double)this->leftCont->wayPoint->y};
    PointF b = {this->cX, this->cY};
    Delta deltas = getDeltas(a, b);
    long double dis = getDis(deltas);
    if (dis <= 1 * this->game->speedKoof)
    {
        this->cX = this->leftCont->wayPoint->x;
        this->cY = this->leftCont->wayPoint->y;
        this->rightCont = this->leftCont;
        this->leftCont = this->rightCont->left;
    }
}

void Roll::goToSecond()
{
    if (this->rightRoll != nullptr && !this->debut)
    {
        this->debut = true;
        while (true)
        {
            Roll *secondRoll = this->rightRoll;
            PointF a = {this->cX, this->cY};
            PointF b = {secondRoll->cX, secondRoll->cY};
            Delta deltas = getDeltas(a, b);
            long double disToSecondRoll = getDis(deltas);
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

    this->goToSecond();

    for (int i = 0; i < this->game->speed; i++)
    {
        this->impulsForvard();
    }
    // this->kick();
    this->move();
}

void Roll::kick()
{
    if (this->rightRoll != nullptr)
    {
        PointF a = {this->cX, this->cY};
        PointF b = {this->rightRoll->cX, this->rightRoll->cY};
        Delta deltas = getDeltas(a, b);
        long double dis = getDis(deltas);
        if (dis < this->kickDis)
        {
            this->rightRoll->impulse = true;
        }
    }
}
