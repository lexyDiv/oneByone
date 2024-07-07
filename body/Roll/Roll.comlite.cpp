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

Roll *Roll::getRightSonPoint()
{
    Roll *rightRoll = new Roll(1, this->cX, this->cY);
    rightRoll->leftRoll = this;
    rightRoll->leftCont = this->leftCont;
    rightRoll->rightCont = this->rightCont;
    rightRoll->game = this->game;
    rightRoll->forvardMove(true);
    // PointF *rightSonPoint = new PointF{rightRoll->cX, rightRoll->cY};
    // this->game->LR[1] = rightSonPoint;
    // delete rightRoll;
    // rightRoll = nullptr;
    return rightRoll;
}

Roll *Roll::getLeftSonPoint()
{
    Roll *leftRoll = new Roll(1, this->cX, this->cY);
    // leftRoll->rightRoll = this;
    leftRoll->rightCont = this->rightCont;
    leftRoll->leftCont = this->leftCont;
    leftRoll->game = this->game;
    /////
    // int iter = 0;
    while (true)
    {
        PointF a = {this->cX, this->cY};
        PointF b{leftRoll->cX, leftRoll->cY};
        Delta deltas = getDeltas(a, b);
        double dis = getDis(deltas);
        // console.log("dis = " + to_string(dis));
        if (dis >= this->kickDis
            // || iter == 10000
        )
        {
            // PointF *point = new PointF{leftRoll->cX, leftRoll->cY};
            // this->game->LR[0] = point;
            return leftRoll;
        }
        else
        {
            leftRoll->impulseBack();
        }
        // iter ++;
    }
    /////

    return nullptr;
}

void Roll::getSonPointAndRotation()
{
    if (this->sonRoll && this->leftCont != nullptr && this->rightCont != nullptr)
    {

        Roll *rightVirtualRoll = this->getRightSonPoint();
        Roll *leftVirtualRoll = this->getLeftSonPoint();

        ///////////////////////////////
        //  this->game->LR[0] = new PointF{leftVirtualRoll->cX, leftVirtualRoll->cY};
        //  this->game->LR[1] = new PointF{rightVirtualRoll->cX, rightVirtualRoll->cY};
        //  this->game->pause = true;
        //////////////////////

        PointF rightSonPoint = {rightVirtualRoll->cX, rightVirtualRoll->cY};
        PointF leftSonPoint = {leftVirtualRoll->cX, leftVirtualRoll->cY};

        PointF a = {rightSonPoint.x, rightSonPoint.y};
        PointF b = {this->sonRoll->cX, this->sonRoll->cY};
        Delta deltas = getDeltas(a, b);
        double disToRight = getDis(deltas);
        a = {leftSonPoint.x, leftSonPoint.y};
        deltas = getDeltas(a, b);
        double disToLeft = getDis(deltas);
        this->sonRollPosition = disToLeft < disToRight ? 0 : 1;

        double virtualConor = this->conorToSonRoll;

        if (!this->sonRollPosition)
        {
            virtualConor += 0.1;
            PointF virtualPoint = {this->cX + cos(virtualConor) * this->kickDis,
                                   this->cY + sin(virtualConor) * this->kickDis};
            deltas = getDeltas(leftSonPoint, virtualPoint);
            double disToLeftSonPoint = getDis(deltas);
            this->sonRotation = disToLeftSonPoint < disToLeft ? 0 : 1;
        }
        else
        {
            virtualConor += 0.1;
            PointF virtualPoint = {this->cX + cos(virtualConor) * this->kickDis,
                                   this->cY + sin(virtualConor) * this->kickDis};
            deltas = getDeltas(rightSonPoint, virtualPoint);
            double disToRightSonPoint = getDis(deltas);
            this->sonRotation = disToRightSonPoint < disToRight ? 0 : 1;
        }

        // b = {rightSonPoint.x, rightSonPoint.y};
        // deltas = getDeltas(a, b);
        // double leftToRightConor = radToDeg(getConor(deltas));
        // b = {this->sonRoll->cX, this->sonRoll->cY};
        // deltas = getDeltas(a, b);
        // double leftToSunRollConor = radToDeg(getConor(deltas));

        // if (leftToRightConor < 0)
        // {
        //     leftToRightConor += 360;
        // }
        // if (leftToSunRollConor < 0)
        // {
        //     leftToSunRollConor += 360;
        // }

        // if (leftToRightConor > leftToSunRollConor)
        // {
        //      console.log("LEFT");
        //     this->sonRotation = !this->sonRollPosition ? 1 : 0;
        // }
        // else
        // {
        //      console.log("RIGHT");
        //     this->sonRotation = !this->sonRollPosition ? 0 : 1;
        // }
        delete leftVirtualRoll;
        delete rightVirtualRoll;
        leftVirtualRoll = nullptr;
        rightVirtualRoll = nullptr;
    }
}
