#pragma once



class RollTypeGroup;

class Roll
{
public:
    Roll(int type, float cX, float cY);
    Image *getImage();
    Roll *leftRoll = nullptr;
    Roll *rightRoll = nullptr;

private:
    Image *image = nullptr;
    int type;
    float cX;
    float cY;
    int x;
    int y;
};