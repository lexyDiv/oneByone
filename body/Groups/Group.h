#pragma once

#include "../../union/FS/FS.cpp"

class Game;
class Roll;

class Group
{
public:
    Game *game = nullptr;
    vector<Roll *> arr;
    void addRoll(Roll *roll);
    int length();
    Group(Game *game);
    ~Group();
};