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
    this->rollsToCollisionClear();
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
    // if(this->colisionRoll != nullptr)
    // {
    //     ctx.StrokeRect(this->colisionRoll->x, this->colisionRoll->y, this->colisionRoll->diameter, this->colisionRoll->diameter, "violet");
    // }
}