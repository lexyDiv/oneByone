#pragma once

#include "../WayLine/WayLine.cpp"


Image* roll5 = new Image("src/roll5.png");


class RollTypeGroup;

class Roll
{
public:
    Roll *leftRoll = nullptr;
    Roll *rightRoll = nullptr;
    Container *leftCont = nullptr;
    Container *rightCont = nullptr;
    RollTypeGroup *typeGroup = nullptr;
    Image *image = nullptr;
    int type;
    float cX;
    float cY;
    int x;
    int y;
    float prevCx;
    float prevCy;
    int radius = 50;
    int mid = this->radius / 2;
    double conor = 0;
    int speed;
    bool impulse = false;
    int animX = 0;
    int animY = 0;
    int animW = 213;
    int animH = 213;
    Roll();
    Roll(int type, float cX, float cY);

    void prog();
    void draw();

private:
};