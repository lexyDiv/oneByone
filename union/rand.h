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
    long double x;
    long double y;
};

struct Delta
{
    long double deltaX;
    long double deltaY;
};


Delta getDeltas(PointF &a, PointF &b)
{
    long double deltaX = b.x - a.x;
    long double deltaY = b.y - a.y;
    return {deltaX, deltaY};
}

Delta getDeltas(PointF *a, PointF *b)
{
    long double deltaX = b->x - a->x;
    long double deltaY = b->y - a->y;
    return {deltaX, deltaY};
}




long double getDis(Delta &del)
{
    long double c = sqrt(del.deltaX * del.deltaX + del.deltaY * del.deltaY);
    return c;
};


long double getDis(Delta *del)
{
    long double c = sqrt(del->deltaX * del->deltaX + del->deltaY * del->deltaY);
    return c;
};



long double getConor(Delta &del)
{
    long double conorData = atan2(del.deltaY, del.deltaX);
    return conorData;
};



long double getConor(Delta *del)
{
    long double conorData = atan2(del->deltaY, del->deltaX);
    return conorData;
};


long double radToDeg(long double rad)
{
    return rad * 180 / M_PI;
}

long double degToRad(long double deg)
{
    return deg * (M_PI / 180);
}
