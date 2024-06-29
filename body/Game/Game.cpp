#include "Game.prog.cpp"

Game::Game()
{
}

Game::~Game()
{
    delete this->wayLine;
    this->wayLine = nullptr;
    for(int i = 0; i < this->rollsV.size(); i++)
    {
        
         delete this->rollsV[i];
         this->rollsV[i] = nullptr;
    }
};

void Game::draw()
{

    // for(int i = 0; i < this->rollsV.size(); i++)
    // {
    //     this->rollsV[i]->draw();
    // }


    this->rolls->forEach([](Roll *roll, int i)
                         { 
                            if(roll != nullptr)
                            {
                                roll->draw();
                            }
                            else 
                            {
                               // console.log("i = " + to_string);
                            } });

    this->wayLine->drawPoints();
}