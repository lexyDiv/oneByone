#include "Mouse.h"

void Mouse::move(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Mouse::pressKey(int keyCode)
{
    switch (keyCode)
    {
    case 1:
    {
        this->leftKey = true;
        break;
    }
    case 2:
    {
        this->midKey = true;
        break;
    }
    case 3:
    {
        this->rightKey = true;
        break;
    }
    }
}

void Mouse::upKey(int keyCode)
{
    switch (keyCode)
    {
    case 1:
    {
        this->leftKey = false;
        break;
    }
    case 2:
    {
        this->midKey = false;
        break;
    }
    case 3:
    {
        this->rightKey = false;
        break;
    }
    }
}

////

void Mouse::keyDown(int keyCode)
{
    switch (keyCode)
    {
    case 1:
    {
        this->leftKeyDown = true;
        break;
    }
    case 2:
    {
        this->midKeyDown = true;
        break;
    }
    case 3:
    {
        this->rightKeyDown = true;
        break;
    }
    }
}

void Mouse::keyUp(int keyCode)
{
    switch (keyCode)
    {
    case 1:
    {
        this->leftKeyUp = true;
        break;
    }
    case 2:
    {
        this->midKeyUp = true;
        break;
    }
    case 3:
    {
        this->rightKeyUp = true;
        break;
    }
    }
}

void Mouse::defaultKeys()
{
    this->leftKeyDown = false;
    this->leftKeyUp = false;
    this->midKeyDown = false;
    this->midKeyUp = false;
    this->rightKeyDown = false;
    this->rightKeyUp = false;
}

Mouse mouse;
