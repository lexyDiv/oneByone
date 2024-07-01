#pragma once


class Game;

class Station
{
    public:
    int x;
    int y;
    Game* game = nullptr;
    Station(int x, int y);
};