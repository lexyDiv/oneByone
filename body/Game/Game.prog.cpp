#include "Game.h"

void Game::prog()
{
    if (!this->wayLine->getLength())
    {
        rapid<WayPoint> arr = fs.read<WayPoint>(this->path, sizeof(WayPoint));
        this->wayLine->update(arr);
    }
    if(!this->rolls->getLength())
    {
        Roll* newRoll = new Roll(1, 
        this->wayLine->getHead()->wayPoint->x, 
        this->wayLine->getHead()->wayPoint->y);
        this->impulseRoll = newRoll;
        this->rolls->frontForce(1);
        this->rolls->unshift(newRoll);
        this->rolls->norm();
        newRoll = nullptr;
    }
}


