#pragma once

#include "../WayLine/WayLine.cpp"


Image* roll5 = new Image("src/roll5.png");
Image* roll6 = new Image("src/roll6.png");
Image* roll7 = new Image("src/roll7.png");
Image* roll8 = new Image("src/roll8.png");
Image* roll9 = new Image("src/roll9.png");
Image* roll10 = new Image("src/roll10.png");


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
    double cX;
    double cY;
    int x;
    int y;
    double prevCx;
    double prevCy;
    double way;
    int diameter = 50;
    double liner = 2 * M_PI * ((this->diameter / 2) - 3);
    int kickDis = this->diameter - 3;
    int mid = this->diameter / 2;
    double conor = 0;
    int rotation = 1;
    int vector = 1;
    int speed;
    bool impulse = false;
    bool debut = false;
    int animX = 0;
    int animY = 0;
    int animW = 213;
    int animH = 213;
    Roll();
    Roll(int type, double cX, double cY);

    void prog();
    void impulsForvard();
    void goToSecond();
    void impulseProg();
    void kick();
    void getWayLength();
    void getRotation();
    void updateConor();
    void move();
    void draw();
    Image* getImage(int type);

private:
};