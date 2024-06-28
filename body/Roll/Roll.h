#pragma once

#include "../WayLine/WayLine.cpp"

class RollTypeGroup;

class Roll
{
public:
    Image *getImage();
    Roll *leftRoll = nullptr;
    Roll *rightRoll = nullptr;
    Container *leftCont = nullptr;
    Container *rightCont = nullptr;
    RollTypeGroup *typeGroup = nullptr;
    Roll();
    Roll(int type, float cX, float cY);

    void prog();

private:
    Image *image = nullptr;
    int type;
    float cX;
    float cY;
    int x;
    int y;
};