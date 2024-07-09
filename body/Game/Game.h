#pragma once

#include "../Roll/Roll.h"

class Game
{
public:

bool tryDel = false;
void tryDelProg();
//Roll *controllRoll = nullptr;
Roll *rollWithSon = nullptr;

void deleter();
Roll* rollsOnDelete[1000];
void pushOnRollsOnDelete(Roll *roll);
void rollsOnDeleteProg();

    bool pause = false;
    int level = 1;
    bool endLevel = false;
    int check = 0;
    bool needFilter = false;
    int speed =  75; // bug
    int speedVector = -1;
    bool quit = false;
    double speedKoof = 0.1; // !!!!
    Station *station = new Station(this);
    string path = "levels/level" + to_string(this->level) + ".txt";
    WayLine *wayLine = new WayLine();

    rapid<Roll *> *rolls = new rapid<Roll *>;
    vector<Roll *> rolls2;
    Roll *impulseRoll = nullptr;
    Roll *flyingRoll = nullptr;
    bool unComplite = false;
    //rapid<Roll *> *rollsToCollision = new rapid<Roll *>;
    vector<Roll *> rollsToCollision;

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