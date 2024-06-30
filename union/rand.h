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
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include <SDL_mixer.h>

// #include <SDL/SDL.h>
// #include <SDL/SDL_image.h>

// #include "../test/cell.cpp"

int intRand(int start, int finish)
{
    int random_number = (std::rand() % finish) + start; // rand() return a number between ​0​ and RAND_MAX
                                                        // std::string ret = "random = " + std::to_string(random_number);
                                                        // printf(ret.c_str());
    return random_number;                               // random_number;
};

struct PointF
{
    double x;
    double y;
};

struct Delta
{
    double deltaX;
    double deltaY;
};



// Delta getDeltas(PointF a, PointF b)
// {
//     double deltaX = b.x - a.x;
//     double deltaY = b.y - a.y;
//     return {deltaX, deltaY};;
// }

Delta getDeltas(PointF &a, PointF &b)
{
    double deltaX = b.x - a.x;
    double deltaY = b.y - a.y;
    return {deltaX, deltaY};
}

Delta getDeltas(PointF *a, PointF *b)
{
    double deltaX = b->x - a->x;
    double deltaY = b->y - a->y;
    return {deltaX, deltaY};
}




double getDis(Delta &del)
{
    double c = sqrt(del.deltaX * del.deltaX + del.deltaY * del.deltaY);
    return c;
};

// double getDis(Delta del)
// {
//     double c = sqrt(del.deltaX * del.deltaX + del.deltaY * del.deltaY);
//     return c;
// };

double getDis(Delta *del)
{
    double c = sqrt(del->deltaX * del->deltaX + del->deltaY * del->deltaY);
    return c;
};




// double getConor(Delta del)
// {
//     double conorData = atan2(del.deltaY, del.deltaX);
//     return conorData;
// };

double getConor(Delta &del)
{
    double conorData = atan2(del.deltaY, del.deltaX);
    return conorData;
};

double getConor(Delta *del)
{
    double conorData = atan2(del->deltaY, del->deltaX);
    return conorData;
};
