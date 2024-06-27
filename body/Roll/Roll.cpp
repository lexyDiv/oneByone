#include "Roll.prog.cpp"

Roll::Roll(int type, int cX, int cY)
{
    if (type == 1)
    {
        this->image = new Image("src/roll.png");
    }
    int mid = this->gab / 2;
    this->cX = cX;
    this->cY = cY;
    this->x = cX - mid;
    this->y = cY - mid;
}

void Roll::draw()
{
    ctx.DrawImage(this->image, 0, 0, 900, 900, this->x, this->y, this->gab, this->gab);
    ctx.FillRect(this->cX, this->cY, 3, 3, "yellow");
};

