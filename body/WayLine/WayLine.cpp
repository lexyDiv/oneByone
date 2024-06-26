#include "WayLine.h"

WayLine::WayLine(){};

int WayLine::getLength()
{
    return this->length;
};

Container *WayLine::getHead()
{
    return this->head;
}

Container *WayLine::getNext(Container *container)
{
    return container->right;
}

Container *WayLine::getItem(int index, Container *cont)
{
    if (index)
    {
        index--;
        return this->getItem(index, this->getNext(cont));
    }
    return cont;
}

void WayLine::update(rapid<WayPoint> &arr)
{
    for (int i = 0; i < arr.getLength(); i++)
    {
        WayPoint &pnt = arr.getItem(i);
        WayPoint *nPnt = new WayPoint(pnt.x, pnt.y);
        this->push(nPnt);
        nPnt = nullptr;
    }
}

void WayLine::push(WayPoint *wayPoint)
{
    Container *container = new Container(wayPoint);
    if (!this->length)
    {
        this->head = container;
        this->tale = container;
        this->head->right = this->tale;
        this->tale->left = this->head;
    }
    else
    {
        this->tale->right = container;
        container->left = this->tale;
        this->tale = container;
    }
    this->length++;
}

void WayLine::drawPoints()
{
    for (int i = 0; i < this->length; i++)
    {
        Container *cont = this->getItem(i, this->getHead());
        int x = cont->wayPoint->x;
        int y = cont->wayPoint->y;
        ctx.FillRect(x, y, 3, 3, "red");
    }
}

WayLine::~WayLine()
{
    for (int i = 0; i < this->length; i++)
    {
        Container *cont = this->getItem(i, this->getHead());
        delete cont;
        cont = nullptr;
    }
};
