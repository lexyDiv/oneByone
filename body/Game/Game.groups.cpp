#include "Game.flying.cpp"

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