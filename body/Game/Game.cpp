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
    this->rolls->forEach([](Roll *roll)
                         { roll->draw(); });
    this->wayLine->drawPoints();
}