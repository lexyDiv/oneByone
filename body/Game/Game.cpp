#include "Game.h"

Game::Game()
{
}

Game::~Game(){
    delete this->wayLine;
    this->wayLine = nullptr;
};