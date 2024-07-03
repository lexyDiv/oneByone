#include "Game.flying.cpp"

Game::Game()
{
}

Game::~Game()
{
    delete this->wayLine;
    this->wayLine = nullptr;
    this->rolls->forEach([](Roll *rl)
                         {
        delete rl;
        rl = nullptr; });
    if (this->flyingRoll != nullptr)
    {
        delete this->flyingRoll;
        this->flyingRoll = nullptr;
    }
    this->rollsToCollision->clear();
    delete this->rollsToCollision;
    this->rollsToCollision = nullptr;
};

void Game::draw()
{

    this->rolls->forEach([](Roll *roll, int i)
                         {
                             if(roll != nullptr)
                             {
                                roll->draw();
                             } });

    this->wayLine->drawPoints();
    this->station->draw();
    if (this->flyingRoll != nullptr)
    {
        this->flyingRoll->draw();
    }

    // this->rollsToCollision->forEach([](Roll* roll){
    //     ctx.StrokeRect(roll->x, roll->y, roll->diameter, roll->diameter, "red");
    // });
    // if(this->contactRoll != nullptr)
    // {
    //     ctx.StrokeRect(this->contactRoll->x, this->contactRoll->y, this->contactRoll->diameter, this->contactRoll->diameter, "violet");
    // }
}