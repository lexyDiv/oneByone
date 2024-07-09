#pragma once

#include "../Game/Game.Station/Station.h"

class WayPoint
{
public:
    int x;
    int y;
    WayPoint(){};
    WayPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    };
};

class Container
{
public:
    WayPoint *wayPoint;
    Container *left = nullptr;
    Container *right = nullptr;
    double getConorToRight();
    void setConorToRight(double conor);
    double getConorToLeft();
    void setConorToLeft(double conor);


    Container(WayPoint *wayPoint)
    {
        this->wayPoint = wayPoint;
    }
    ~Container()
    {
        delete this->wayPoint;
        this->wayPoint = nullptr;
    }

private:
    double conorToRight;
    double conorToLeft;
};

class WayLine
{
public:
Container *tale = nullptr;
    WayLine();
    int getLength();

    Container *getHead();
    Container *getNext(Container *container);
    Container *getItem(int index, Container *cont);

    void update(rapid<WayPoint> &arr, int level);
    void getAllConors();
    void push(WayPoint *wayPoint);
    void unshift(WayPoint *wayPoint);
    void drawPoints();
    void clear();
    ~WayLine();

private:
    Container *head = nullptr;
    int length = 0;
};