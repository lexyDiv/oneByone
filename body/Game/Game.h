#pragma once

 #include "../WayLine/WayLine.cpp"

class Game
{
    public:
    int level = 1;
    string path = "level" + this->level;
    WayLine* wayLine = new WayLine();
    
    Game();
};