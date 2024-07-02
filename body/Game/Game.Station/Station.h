#pragma once

//#include "../../union/FS/FS.cpp"
#include "../../../union/FS/FS.cpp"

class Game;

class Station
{
    public:
    int x;
    int y;
    int gabX = 200;
    int gabY = 200;
    double conor = 0;
    Station(Game* game);
    Game* game = nullptr;
    Station();
    void getPosition(int level);
    void prog();
    void draw();
};