#include "Game.groups.cpp"

Game::Game()
{
    for(int i = 0; i < 1000; i ++)
    {
        this->rollsOnDelete[i] = nullptr;
    }

    for(int i = 0; i < this->rollsOnBooMaxSize; i ++)
    {
        this->rollsOnBoo[i] = nullptr;
    }
}

Game::~Game()
{
    this->deleteGroups();
    delete this->wayLine;
    this->wayLine = nullptr;

    if (this->flyingRoll != nullptr)
    {
        delete this->flyingRoll;
        this->flyingRoll = nullptr;
    }
    for(int i = 0; i < 1000; i ++)
    {
        Roll *roll = this->rollsOnDelete[i];
        if(roll != nullptr)
        {
            delete roll;
            roll = nullptr;
        }
    };
    this->rollsToCollision.clear();
    //delete this->rollsToCollision;
    //this->rollsToCollision = nullptr;
};

void Game::draw()
{

    for(int i = 0; i < this->rolls2.size(); i++)
    {
        Roll *roll = this->rolls2[i];
        roll->draw(i);
        if(roll->sonRoll != nullptr)
        {
            roll->sonRoll->draw();
        }
    }



    this->wayLine->drawPoints();
    this->station->draw();
    if (this->flyingRoll != nullptr)
    {
        this->flyingRoll->draw();
    }

    this->rollsOnBooDraw();
    //////////////////// groups

    // for(int i = 0; i < this->groups.size(); i++)
    // {
    //     this->pause = true;
    //     Group *group = this->groups[i];
    //     for(int k = 0; k < group->arr.size(); k++)
    //     {
    //         Roll *roll = group->arr[k];
    //         ctx.StrokeRect(roll->x, roll->y, roll->diameter, roll->diameter, "red");
    //     }
    //     ctx.DrawText(group->arr[0]->x, group->arr[0]->y, 50, to_string(i));
    //     ctx.DrawText(group->arr[0]->x, group->arr[0]->y + 50, 50, 
    //    "localDel = " + to_string(group->arr[0]->localDel));

    // }
}