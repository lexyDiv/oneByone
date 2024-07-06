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
        //console.log("this is sonRollRitation");
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
        //     this->sonRollCXCorrect();
        //     PointF a = {leftVirtualRoll->cX, leftVirtualRoll->cY};
        //     PointF b = {this->sonRoll->cX, this->sonRoll->cY};
        //     Delta deltas = getDeltas(a, b);
        //    // double dis = getDis(deltas);
        //     double conorToLeft = radToDeg(getConor(deltas));
        //     double conorToSonRollOnDeg = radToDeg(this->conorToSonRoll);
        //     // double oneConor = oneOnDeg < 0 ? oneOnDeg += 360 : oneOnDeg;
        //     // double tooConor =conorToLeft < 0 ? conorToLeft += 360 : conorToLeft;
        //     console.log("left dis = ");
    
        //     if(0)
        //     {
                
        //         this->game->pause = true;
        //     }
            delete leftVirtualRoll;
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
            // this->sonRollCXCorrect();
            // PointF a = {rightVirtualRoll->cX, rightVirtualRoll->cY};
            // PointF b = {this->sonRoll->cX, this->sonRoll->cY};
            // Delta deltas = getDeltas(a, b);
            // double dis = getDis(deltas);
            // console.log("right dis = " + to_string(dis));
            // if(dis <= this->sonRotationWay * 6)
            // {
            //     this->game->pause = true;
            // }
            delete rightVirtualRoll;
            rightVirtualRoll = nullptr;
        }
        this->sonRollOnPosition();
    }
}

void Roll::sonRollProg()
{
    if (this->sonRoll != nullptr)
    {
        // console.log("prog");
    }
}