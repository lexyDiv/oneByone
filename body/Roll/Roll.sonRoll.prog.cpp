#include "Roll.comlite.cpp"


void Roll::sonRollOnPosition()
{
    if(this->sonRoll != nullptr)
    {
        this->sonRoll->cX = this->cX + cos(this->conorToSonRoll) * this->kickDis;
        this->sonRoll->cY = this->cY + sin(this->conorToSonRoll) * this->kickDis;
    }
}



void Roll::sonRollRotation()
{
    if(this->sonRoll != nullptr)
    {
        // console.log("position = " + to_string(this->sonRollPosition));
        // console.log("rotation = " + to_string(this->sonRotation));
        console.log("deg = " + to_string(radToDeg(0.1)));
        if(!this->sonRollPosition)
        {
            Roll* leftVirtualRoll = this->getLeftSonPoint();
            if(!this->sonRotation)
            {
                this->conorToSonRoll += 0.1;
                console.log("here");
            }
            else
            {
                this->conorToSonRoll -= 0.1;
                //console.log("here 2");
            }
        }
        this->sonRollOnPosition();
    }
}


void Roll::sonRollProg()
{
   if(this->sonRoll != nullptr)
    {
       // console.log("prog");
    }
}