#pragma once

#include "../Console/Console.cpp"

class Mouse
{
   public:
   int x;
   int y;
   bool leftKey = false;
   bool rightKey = false;
   bool midKey = false;
   void move(int x, int y);
   void pressKey(int keyCode);
   void upKey(int keyCode);

   /////

   bool leftKeyDown = false;
   bool leftKeyUp = false;
   bool midKeyDown = false;
   bool midKeyUp = false;
   bool rightKeyDown = false;
   bool rightKeyUp = false;

   void keyDown(int keyCode);
   void keyUp(int keyCode);

   void defaultKeys();


};