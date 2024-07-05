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