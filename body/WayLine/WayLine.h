#pragma once

#include "../../union/FS/FS.cpp"

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

private:
    double conorToRight;
    double conorToLeft;
};

class WayLine
{
public:
    WayLine();
    int getLength();

    Container *getHead();
    Container *getNext(Container *container);
    Container *getItem(int index, Container *cont);

    void update(rapid<WayPoint> &arr);
    void getAllConors();
    void push(WayPoint *wayPoint);
    void unshift(WayPoint *wayPoint);
    void drawPoints();
    ~WayLine();

private:
    Container *head = nullptr;
    Container *tale = nullptr;
    int length = 0;
};