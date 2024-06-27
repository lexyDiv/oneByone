#include "Game.prog.cpp"



Game::Game()
{
}

Game::~Game(){
    delete this->wayLine;
    this->wayLine = nullptr;
};