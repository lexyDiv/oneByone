#pragma once

#include "../Roll/Roll.cpp"

class Game
{
    public:
    int level = 1;
    string path = "levels/level" + to_string(this->level) + ".txt";
    WayLine* wayLine = new WayLine();

    rapid<Roll*>* rolls = new rapid<Roll*>;
    Roll* impulseRoll = nullptr;

    void prog();
    void draw();

    Game();
    ~Game();
};