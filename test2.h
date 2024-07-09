#pragma once

// cell.h
class unit;

class cell2
{
    public:
    unit* u = nullptr;
    int hz();
    
    cell2(){};
};
//

// unit.h
class unit
{
    public:
    cell2* c = nullptr;
    int hz();
   
    unit(){};
};
//

// unit.cpp
int unit::hz()
    {
        this->c->hz();
        return 1;
    };
//

// cell.cpp
int cell2::hz()
    {
        this->u->hz();
        return 25;
    };
//