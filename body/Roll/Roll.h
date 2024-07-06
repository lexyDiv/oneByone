#pragma once

#include "../WayLine/WayLine.h"

Image *roll5 = new Image("src/roll5.png");
Image *roll6 = new Image("src/roll6.png");
Image *roll7 = new Image("src/roll7.png");
Image *roll8 = new Image("src/roll8.png");
Image *roll9 = new Image("src/roll9.png");
Image *roll10 = new Image("src/roll10.png");

Image *ass = new Image("src/ass.png");


class Game;

class Roll
{
public:
    Game *game = nullptr;
    Roll *leftRoll = nullptr;
    Roll *rightRoll = nullptr;
    Container *leftCont = nullptr;
    Container *rightCont = nullptr;
 
    Image *image = nullptr;



    int flySpeed = 30;
    int type;
    double cX;
    double cY;
    int x;
    int y;
    double prevCx;
    double prevCy;
    double way;
    int diameter = 60;
    int mid = this->diameter / 2;
    double liner = 2 * M_PI * (mid - 3);
    int kickDis = this->diameter - 3;

        //////////////////////
    bool father = false;
    Roll* sonRoll = nullptr;
    double conorToSonRoll;
    int sonRollPosition;
    int sonRotation;
    PointF sonPoint;
    double sonRotationIndex = 0.1;
    double sonRotationWay = (liner * radToDeg(sonRotationIndex)) / 360;
    Roll *readyInLine = nullptr;
    double saveRotDis = 1000;
    /////////////////////

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
    bool del = false;
    Roll();
    Roll(int type, double cX, double cY);
    ~Roll();

    void prog(int index);
    ///////////
    void forvardMove(bool special);
    void reversMove();
    void impulsForvard();
    void impulseBack();
    void sonRollRotation();
    void sonRollProg();
    /////////////
    void goToSecond();
    void impulseProg();
    void kick();
    void getWayLength();
    void getRotation();
    void updateConor();
    void getDrawPosition();
    void move();
    void draw();
    //////////////
    void getConorToSonRoll();
    Roll* getRightSonPoint();
    Roll* getLeftSonPoint();
    void getSonPointAndRotation();
    void sonRollCXCorrect();
    void sonRollOnPosition();
    ///////////////
    Image *getImage(int type);

private:
};