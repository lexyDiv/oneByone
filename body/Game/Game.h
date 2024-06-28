#pragma once

#include "../Roll/Roll.cpp"

class Game
{
    public:
    int level = 1;
    string path = "levels/level" + to_string(this->level) + ".txt";
    WayLine* wayLine = new WayLine();

    void prog();
    void draw();

    Game();
    ~Game();
};