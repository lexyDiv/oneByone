#include "Station.h"

Station::Station(Game *game)
{
    this->game = game;
    this->game->station = this;
}

Station::Station()
{
 
}


void Station::prog() 
{
   PointF a = {(double)this->x, (double)this->y};
   PointF b = {(double)mouse.x, (double)mouse.y};
   Delta deltas = getDeltas(b, a);
   double conor = getConor(deltas);

   

}


void Station::draw() 
{
};