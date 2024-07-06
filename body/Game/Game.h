#pragma once

#include "../Roll/Roll.h"

class Game
{
public:
Roll *rollWithSon = nullptr;
PointF *LR[2]{nullptr, nullptr};
Roll* contactRoll = nullptr;
////////////////////

    bool pause = false;
    int level = 2;
    bool endLevel = false;
    int check = 0;
    bool needFilter = false;
    int speed =  25; // bug
    int speedVector = -1;
    bool quit = false;
    double speedKoof = 0.2; // !!!!
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