#include "Game.flying.cpp"
#include "Game.h"

int Game::getTypeNewRoll()
{
    vector<int> types{1, 2, 3, 4, 5, 6};
    if (this->rolls2.size() >= 2)
    {
        Roll *firstRoll = this->rolls2[0];
        Roll *secondRoll = this->rolls2[1];
        if (firstRoll->type == secondRoll->type)
        {
            types.erase(types.cbegin() + this->rolls2[0]->type - 1);
        }
    }
    return types[intRand(0, types.size())];
};

void Game::getGroups()
{
    for (int i = 0; i < this->groups.size(); i++)
    {
        Group *group = this->groups[i];
        delete group;
        group = nullptr;
        this->groups[i] = nullptr;
    }

    this->groups.clear();

    for (int i = 0; i < this->rolls2.size(); i++)
    {
        Group *group = new Group(this);
        Roll *roll = this->rolls2[i];
        group->addRoll(roll);
        for (int k = i + 1; k < this->rolls2.size(); k++)
        {
            Roll *rollN = this->rolls2[k];
            if (rollN->type == roll->type)
            {
                group->addRoll(rollN);
            }
            else
            {
                break;
            }
        }
        if (group->length() >= 3)
        {
            this->groups.push_back(group);
        }
        else
        {
            delete group;
        }
        group = nullptr;
    }
}