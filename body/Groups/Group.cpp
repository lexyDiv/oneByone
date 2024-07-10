#include "../Roll/Roll.cpp"


void Group::addRoll(Roll *roll)
{
    roll->group = this;
    this->arr.push_back(roll);
}

int Group::length()
{
    return this->arr.size();
}

Group::Group(Game *game)
{
    this->game = game;
}

Group::~Group()
{
    // for (int i = 0; i < this->arr.size(); i++)
    // {
    //     Roll *roll = this->arr[i];
    //     roll->group = nullptr;
    //     roll = nullptr;
    // }
    this->game = nullptr;
};
