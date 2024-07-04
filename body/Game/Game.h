#pragma once

#include "../Roll/Roll.h"

class Game
{
public:

PointF *LR[2]{nullptr, nullptr};
Roll* contactRoll = nullptr;
////////////////////

    bool pause = false;
    int level = 2;
    bool endLevel = false;
    int check = 0;
    bool needFilter = false;
    int speed = 150;
    int speedVector = -1;
    bool quit = false;
    double speedKoof = 0.1; // !!!!
    Station *station = new Station(this);
    string path = "levels/level" + to_string(this->level) + ".txt";
    WayLine *wayLine = new WayLine();

    rapid<Roll *> *rolls = new rapid<Roll *>;
    Roll *impulseRoll = nullptr;
    Roll *flyingRoll = nullptr;
    bool unComplite = false;
    rapid<Roll *> *rollsToCollision = new rapid<Roll *>;

    void getWayLine();
    void newRollCreating();
    void rollsToProg();
    void deleteProg(Roll *roll);
    void prog();

    void getRollsToCheckCollision();
    Roll* checkCollision();
    void flyingMove();
    void flyingOutDel();

    void impulseRollCreate();
    void draw();

    Game();
    ~Game();
};