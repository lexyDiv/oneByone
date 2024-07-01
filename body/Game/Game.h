#pragma once

#include "../Roll/Roll.cpp"

#include "Game.Station/Station.h"

class Game
{
    public:
    int level = 1;
    int speed = 10;
    int speedVector = -1;
    bool quit = false;
    double speedKoof = 0.1;
    Station* station = nullptr;
    string path = "levels/level" + to_string(this->level) + ".txt";
    WayLine* wayLine = new WayLine();

    rapid<Roll*>* rolls = new rapid<Roll*>;
    Roll* impulseRoll = nullptr;

    void getWayLine();
    void newRollCreating();
    void rollsToProg();
    void prog();
    
    void impulseRollCreate();
    void draw();

    Game();
    ~Game();
};