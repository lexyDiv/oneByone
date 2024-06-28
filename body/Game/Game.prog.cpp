#include "Game.h"

void Game::prog()
{
    if (!this->wayLine->getLength())
    {
        rapid<WayPoint> arr = fs.read<WayPoint>(this->path, sizeof(WayPoint));
        this->wayLine->update(arr);
    }
    this->impulseRollCreate();
    this->impulseRoll->impulseProg(this->speed);
}

void Game::impulseRollCreate()
{
    if (!this->rolls->getLength())
    {
        Container *head = this->wayLine->getHead();
        Roll *newRoll = new Roll(1,
                                 head->wayPoint->x,
                                 head->wayPoint->y);
        this->impulseRoll = newRoll;
        this->rolls->frontForce(1);
        this->rolls->unshift(newRoll);
        this->rolls->norm();
        newRoll->leftCont = head;
        newRoll->rightCont = head->right;
        newRoll = nullptr;
        head = nullptr;
    }
}
