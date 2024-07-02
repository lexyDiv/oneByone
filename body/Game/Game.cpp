#include "Game.prog.cpp"

#include "Game.Station/Station.cpp"

Game::Game()
{
    if(this->level == 2)
    {
        this->station->x = 100;
        this->station->y = 200;
    }
}

Game::~Game()
{
    delete this->wayLine;
    this->wayLine = nullptr;
    this->rolls->forEach([](Roll *rl)
                         {
        delete rl;
        rl = nullptr; });
};

void Game::draw()
{

    this->rolls->forEach([](Roll *roll, int i)
                         {
                             if(roll != nullptr)
                             {
                                roll->draw();
                             }
                         });

    this->wayLine->drawPoints();
    this->station->draw();
}