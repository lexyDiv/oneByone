#pragma once

#include "../WayLine/WayLine.cpp"

class RollGroup;

class Roll
{
public:
    float x;
    float y;
    float cX;
    float cY;
    int gab = 40;
    Image *image;
    RollGroup* group = nullptr;
    Container* left = nullptr;
    Container* right = nullptr;
    Roll(int type, int cX, int cY);
    void prog();
    void draw();
};

