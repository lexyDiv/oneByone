#pragma once

#include "../Roll/Roll.cpp"

class Game
{
    public:
    int level = 1;
    int speed = 0;
    int speedVector = -1;
    bool quit = false;
    double speedKoof = 0.1;
    string path = "levels/level" + to_string(this->level) + ".txt";
    WayLine* wayLine = new WayLine();

    rapid<Roll*>* rolls = new rapid<Roll*>;
    //vector<Roll*> rollsV;
    Roll* impulseRoll = nullptr;

    void prog();
    
    void impulseRollCreate();
    void draw();

    Game();
    ~Game();
};