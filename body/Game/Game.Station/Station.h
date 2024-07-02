#pragma once


class Game;

class Station
{
    public:
    int x;
    int y;
    Station(Game* game);
    Game* game = nullptr;
    Station();
    void prog();
    void draw();
};