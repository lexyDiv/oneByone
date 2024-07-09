#include "Game.flying.cpp"

Game::Game()
{
    for(int i = 0; i < 1000; i ++)
    {
        this->rollsOnDelete[i] = nullptr;
    }
}

Game::~Game()
{
    delete this->wayLine;
    this->wayLine = nullptr;

    if (this->flyingRoll != nullptr)
    {
        delete this->flyingRoll;
        this->flyingRoll = nullptr;
    }
    this->rollsToCollision.clear();
    //delete this->rollsToCollision;
    //this->rollsToCollision = nullptr;
};

void Game::draw()
{

    for(int i = 0; i < this->rolls2.size(); i++)
    {
        this->rolls2[i]->draw(i);
    }



    this->wayLine->drawPoints();
    this->station->draw();
    if (this->flyingRoll != nullptr)
    {
        this->flyingRoll->draw();
    }

    // for(int i = 0; i < 2; i++)
    // {
    //     PointF* p = this->LR[i];
    //     if(p != nullptr)
    //     {
    //         ctx.FillRect(p->x, p->y, 5, 5, "black");
    //     }
    // }
    // if(this->controllRoll != nullptr)
    // {
    //     Roll *roll = this->controllRoll;
    //    // ctx.StrokeRect(roll->x, roll->y, roll->kickDis, roll->kickDis, "red");
    //    //ctx.FillRect(roll->leftCont->wayPoint->x, roll->leftCont->wayPoint->y, 5, 5, "yellow");
    //   /// ctx.FillRect(roll->rightCont->wayPoint->x, roll->rightCont->wayPoint->y, 5, 5, "green");
    // }
}