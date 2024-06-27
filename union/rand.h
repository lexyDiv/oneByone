#pragma once

#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <cstdlib>
#include <ctime>
#include <functional>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <string>
#include <cmath>
#include <cstring>
#include <fstream>
#include <list>

#include <SDL.h>
#include <SDL_image.h>

#include <SDL_mixer.h>

// #include <SDL/SDL.h>
// #include <SDL/SDL_image.h>


int intRand(int start, int finish)
{
    int random_number = (std::rand() % finish) + start; // rand() return a number between ​0​ and RAND_MAX
   // std::string ret = "random = " + std::to_string(random_number);
   // printf(ret.c_str());
    return random_number; // random_number;
};


struct PointF
{
    float x;
    float y;
    PointF(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};

float getDis(PointF a, PointF b)
{
    float dX = a.x - b.x;
    float dY = a.y - b.y;
    float c = sqrt(dX * dX + dY * dY);
    return c;
};

float getDis(PointF &a, PointF &b)
{
    float dX = a.x - b.x;
    float dY = a.y - b.y;
    float c = sqrt(dX * dX + dY * dY);
    return c;
};