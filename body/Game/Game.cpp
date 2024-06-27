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
    this->rollGroups->forEach([](RollGroup *gr)
                              { gr->arr->forEach([](Roll *rl)
                                                 { rl->draw(); }); });
    this->wayLine->drawPoints();
}