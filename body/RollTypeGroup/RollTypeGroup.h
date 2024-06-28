#pragma once

#include "../Roll/Roll.h"

class RollTypeGroup
{
    public:
    rapid<Roll*>* rolls = new rapid<Roll*>;
    RollTypeGroup();
};