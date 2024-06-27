#include "Game.h"

void Game::prog()
{
    if (!this->wayLine->getLength())
    {
        rapid<WayPoint> arr = fs.read<WayPoint>(this->path, sizeof(WayPoint));
        this->wayLine->update(arr);
    }
}

void Game::draw()
{
    this->wayLine->drawPoints();
}
