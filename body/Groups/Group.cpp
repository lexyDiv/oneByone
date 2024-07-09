#include "../Roll/Roll.cpp"
#include "Group.h"

void Group::addRoll(Roll *roll)
{
    this->arr.push_back(roll);
}

Group::Group(Game *game){
    this->game = game;
};
