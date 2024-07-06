
#include "../Game/Game.h"


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

void WayLine::update(rapid<WayPoint> &arr, int level)
{
    for (int i = 0; i < arr.getLength(); i++)
    {
        WayPoint &pnt = arr.getItem(i);
        WayPoint *nPnt = new WayPoint(pnt.x, pnt.y);
        this->push(nPnt);
        nPnt = nullptr;
    }
    if(level == 1)
    {
        WayPoint *startPoint = new WayPoint(-150, 600);
        this->unshift(startPoint);
    }
    else if(level == 2)
    {
        WayPoint *startPoint = new WayPoint(1500, -600);
        this->unshift(startPoint);
    }
    this->getAllConors();
}

void WayLine::getAllConors()
{
    for (int i = 0; i < this->length; i++)
    {
        Container *cont = this->getItem(i, this->getHead());
        if (i < this->length - 1)
        {
            Container *nextCont = cont->right;
            PointF a = {(float)nextCont->wayPoint->x, (float)nextCont->wayPoint->y};
            PointF b = {(float)cont->wayPoint->x, (float)cont->wayPoint->y};
            Delta deltas = getDeltas(a, b);
            double conor = getConor(deltas);
            cont->setConorToRight(conor);
            nextCont = nullptr;
        }
        if (i)
        {
             Container *prevCont = cont->left;
             PointF a = {(float)prevCont->wayPoint->x, (float)prevCont->wayPoint->y};
             PointF b = {(float)cont->wayPoint->x, (float)cont->wayPoint->y};
             Delta deltas = getDeltas(a, b);
             double conor = getConor(deltas);
             cont->setConorToLeft(conor);
             prevCont = nullptr;
        }
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

void WayLine::unshift(WayPoint *wayPoint)
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
      container->right = this->head;
      this->head = container;
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

void WayLine::clear()
{
        for (int i = 0; i < this->length; i++)
    {
        Container *cont = this->getItem(i, this->getHead());
        delete cont;
        cont = nullptr;
    }
    this->length = 0;
}

WayLine::~WayLine()
{
   this->clear();
};

double Container::getConorToRight()
{
    return this->conorToRight;
}

void Container::setConorToRight(double conor)
{
    this->conorToRight = conor;
}

double Container::getConorToLeft()
{
    return this->conorToLeft;
}

void Container::setConorToLeft(double conor)
{
    this->conorToLeft = conor;
}
