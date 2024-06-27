#include "Game.h"

void Game::getWayLine()
{
    if (!this->wayLine->getLength())
    {
        rapid<WayPoint> arr = fs.read<WayPoint>(this->path, sizeof(WayPoint));
        this->wayLine->update(arr);
    }
}

void Game::firstGroupCreate()
{
    if (!this->rollGroups->getLength())
    {
        RollGroup *group = new RollGroup;
        Container *head = this->wayLine->getHead();
        this->rollGroups->frontForce(1);
        this->rollGroups->unshift(group);
        group->arr->frontForce(1);
        Roll *newRoll = new Roll(1,
                                 head->wayPoint->x,
                                 head->wayPoint->y);
        group->arr->unshift(newRoll);
        group->head = newRoll;
        group->tale = newRoll;
        newRoll->group = group;
        newRoll->left = head;
        newRoll->right = head->right;
        group->speed = 1;
        head = nullptr;
        group = nullptr;
        newRoll = nullptr;
    }
}

void Game::prog()
{
    this->getWayLine();
    this->firstGroupCreate();
}
