#include "Roll.comlite.cpp"

void Roll::sonRollCXCorrect()
{
    this->sonRoll->cX = this->cX + cos(this->conorToSonRoll) * this->kickDis;
    this->sonRoll->cY = this->cY + sin(this->conorToSonRoll) * this->kickDis;
}

void Roll::sonRollOnPosition()
{
    if (this->sonRoll != nullptr)
    {
        this->sonRollCXCorrect();
        if (!this->sonRotation)
        {
            this->sonRoll->conor += radToDeg(this->sonRotationIndex) * 2;
        }
        else
        {
            this->sonRoll->conor -= radToDeg(this->sonRotationIndex) * 2;
        }
    }
}

void Roll::sonRollRotation()
{
    if (this->sonRoll != nullptr)
    {
        // console.log("rot way = " + to_string(this->sonRotationWay));
        // console.log("liner = " + to_string(this->liner));
        // console.log("this is sonRollRitation");
        // console.log("position = " + to_string(this->sonRollPosition));
        // console.log("rotation = " + to_string(this->sonRotation));
        // console.log("deg = " + to_string(radToDeg(0.1)));
        if (!this->sonRollPosition)
        {
            Roll *leftVirtualRoll = this->getLeftSonPoint();
            if (!this->sonRotation)
            {
                this->conorToSonRoll += this->sonRotationIndex;
                //  console.log("here");
            }
            else
            {
                this->conorToSonRoll -= this->sonRotationIndex;
                // console.log("here 2");
            }
            this->sonRollCXCorrect();
            PointF a = {leftVirtualRoll->cX, leftVirtualRoll->cY};
            PointF b = {this->sonRoll->cX, this->sonRoll->cY};
            Delta deltas = getDeltas(a, b);
            double dis = getDis(deltas);

            if (dis <= this->sonRotationWay)
            {
                console.log("left");
                this->game->pause = true;
                this->sonRoll->readyInLine = leftVirtualRoll;
                b = {this->cX, this->cY};
                deltas = getDeltas(b, a);
                this->conorToSonRoll = getConor(deltas);
                // this->sonRoll->leftRoll = this->leftRoll;
                // this->sonRoll->rightRoll = this;
                // this->sonRoll->leftRoll->rightRoll = this->sonRoll;
                // this->leftRoll = this->sonRoll;
                // this->sonRoll->game = this->game;
                // this->sonRoll = nullptr;
            }
            // delete leftVirtualRoll;
            leftVirtualRoll = nullptr;
        }
        else
        {
            Roll *rightVirtualRoll = this->getRightSonPoint();
            if (!this->sonRotation)
            {
                this->conorToSonRoll += this->sonRotationIndex;
                //  console.log("here");
            }
            else
            {
                this->conorToSonRoll -= this->sonRotationIndex;
                //  console.log("here 2");
            }
            this->sonRollCXCorrect();
            PointF a = {rightVirtualRoll->cX, rightVirtualRoll->cY};
            PointF b = {this->sonRoll->cX, this->sonRoll->cY};
            Delta deltas = getDeltas(a, b);
            double dis = getDis(deltas);

            if (dis <= this->sonRotationWay)
            {
                console.log("right");
                this->game->pause = true;
                this->sonRoll->readyInLine = rightVirtualRoll;
                b = {this->cX, this->cY};
                deltas = getDeltas(b, a);
                this->conorToSonRoll = getConor(deltas);
                // this->sonRoll->leftRoll = this;
                // this->sonRoll->rightRoll = this->rightRoll;
                // this->sonRoll->rightRoll->leftRoll = this->sonRoll;
                // this->rightRoll = this->sonRoll;
                // this->sonRoll->game = this->game;
                // this->sonRoll = nullptr;
            }
            // delete rightVirtualRoll;
            rightVirtualRoll = nullptr;
        }
        this->sonRollOnPosition();
    }
}

void Roll::sonRollProg()
{
    if (this->sonRoll != nullptr && this->sonRoll->readyInLine != nullptr)
    {
        Roll *virtualRoll = this->sonRoll->readyInLine;

        this->sonRoll->leftCont = virtualRoll->leftCont;
        this->sonRoll->rightCont = virtualRoll->rightCont;
        this->sonRoll->father = false;
       // this->game->unComplite = false;

        if (!this->sonRollPosition)
        {
            this->sonRoll->leftRoll = this->leftRoll;
            this->sonRoll->rightRoll = this;
            this->sonRoll->leftRoll->rightRoll = this->sonRoll;
            this->leftRoll = this->sonRoll;
            this->sonRoll->game = this->game;
        }
        else
        {
            this->sonRoll->leftRoll = this;
            this->sonRoll->rightRoll = this->rightRoll;
            this->sonRoll->rightRoll->leftRoll = this->sonRoll;
            this->rightRoll = this->sonRoll;
            this->sonRoll->game = this->game;
        }


        delete this->sonRoll->readyInLine;
        this->sonRoll->readyInLine = nullptr;
        virtualRoll = nullptr;
        this->sonRoll = nullptr;
    }
}