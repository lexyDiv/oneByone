#pragma once

#include "../WayLine/WayLine.cpp"


Image* roll5 = new Image("src/roll5.png");


class RollTypeGroup;
class Game;

class Roll
{
public:
    Game* game = nullptr;
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
    float way;
    int diameter = 50;
    float liner = 2 * M_PI * ((this->diameter / 2) - 1);
    int mid = this->diameter / 2;
    double conor = 0;
    int rotation = 1;
    int vector = 1;
    int speed;
    bool impulse = false;
    int animX = 0;
    int animY = 0;
    int animW = 213;
    int animH = 213;
    Roll();
    Roll(int type, float cX, float cY);

    void prog();
    void impulsForvard();
    void goToSecond();
    void impulseProg();
    void getWayLength();
    void getRotation();
    void updateConor();
    void move();
    void draw();

private:
};