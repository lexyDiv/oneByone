#pragma once


class Game;

class Station
{
    public:
    int x;
    int y;
    double conor = 0;
    Station(Game* game);
    Game* game = nullptr;
    Station();
    void getPosition(int level);
    void prog();
    void draw();
};