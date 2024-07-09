#include "../Roll/Roll.cpp"
#include "Group.h"

void Group::addRoll(Roll *roll)
{
    roll->group = this;
    this->arr.push_back(roll);
}

Group::Group(Game *game)
{
    this->game = game;
}

Group::~Group()
{
    for (int i = 0; i < this->arr.size(); i++)
    {
        Roll *roll = this->arr[i];
        roll->group = nullptr;
    }
};
