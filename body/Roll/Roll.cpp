#include "Roll.prog.cpp"

Roll::Roll(int type, float cX, float cY)
{
    this->type = type;
    this->cX = cX;
    this->cY = cY;
    if (this->type == 1)
    {
        this->image = new Image("src/roll5");
    }
};

Image *Roll::getImage()
{
    return this->image;
};
