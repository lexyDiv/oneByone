#include "Game.prog.cpp"

Game::Game()
{
}

Game::~Game()
{
    delete this->wayLine;
    this->wayLine = nullptr;
};

void Game::draw()
{
    this->rolls->forEach([](Roll *roll, int i)
                         { 
                            if(roll != nullptr)
                            {
                                roll->draw();
                            }
                            else 
                            {
                                console.log("i = " + to_string(i));
                            } });

    this->wayLine->drawPoints();
}