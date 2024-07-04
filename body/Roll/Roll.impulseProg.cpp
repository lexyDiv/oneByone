#include "../Game/Game.prog.cpp"

void Roll::prog(int index)
{

    if (!this->father)
    {
        this->speed = 0;
        this->impulse = false;

        this->prevCx = this->cX;
        this->prevCy = this->cY;

        PointF a = {this->cX, this->cY};
        PointF b = {this->leftRoll->cX, this->leftRoll->cY};
        Delta deltas = getDeltas(a, b);
        double disToLeftRoll = getDis(deltas);

        this->speed++;

        while (true)
        {
            PointF a = {this->cX, this->cY};
            PointF b = {this->leftRoll->cX, this->leftRoll->cY};
            Delta deltas = getDeltas(a, b);
            double disToLeftRoll = getDis(deltas);

            if (disToLeftRoll >= this->kickDis)
            {
                break;
            }
            else
            {
                this->impulsForvard();
                this->speed = 0;
            }
        }
        this->move();
        if(this->sonRoll)
        {
           
        }
    }
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
            if(this->sonRoll)
            {
                this->sonRoll->del = true;
            }
        }
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
        double dis = getDis(deltas);
        if (dis < this->kickDis)
        {
            this->rightRoll->impulse = true;
        }
    }
}
