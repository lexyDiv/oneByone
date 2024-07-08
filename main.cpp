#include "vars_images.h"

void goWork()
{
    SDL_Event e;
    while (!game->quit)
    {

        listenner(e, game);
        console.proc(mouse.x, mouse.y, mouse.leftKey);
        if (!game->pause)
        {
            game->prog();
        }
        mouse.defaultKeys();
        this_thread::sleep_for(chrono::milliseconds(25));
    }
}

//////////////////

class Unit;

class Cell
{
public:
    int x;
     Unit *unit;
    Cell(int x)
    {
        this->x = x;
    };
    Cell(){};
};

class Unit
{
public:
    int type;
    Cell *cell;
    Cell cells[1000];
    Unit(int type)
    {
        this->type = type;
    };
    Unit(){};
};

int main()
{
   // Cell cell(10);
    Unit unit(0);
    // unit.cell = &cell;
    // unit.cells[0] = &cell;
  
   for(int i = 0; i < 100; i++)
   {
    Cell cell(i);
    cell.unit = &unit;
    unit.cells[i] = cell;
   }
   console.log("unit.cells[2] = " + to_string(unit.cells[0].unit->cells[999].x));
    // rapid<Roll> arr;

    ///////////////

    ctx.getFont();
    bool quit = false;
    // SDL_Event e;

    thread th(goWork);

    while (!game->quit)
    {
        // listenner(e, game);
        // console.proc(mouse.x, mouse.y, mouse.leftKey);
        // game->prog();
        // th.;
        ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
        ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");
        // ctx.DrawImage(spiral, 0, 0, 512, 512, 0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
        game->draw();
        // wayLine->drawPoints();

        console.draw();
        ctx.End();

        // this_thread::sleep_for(chrono::milliseconds(30));
    }

    ctx.Close();
    delete test;
    test = nullptr;
    delete game;
    game = nullptr;
    delete wayLine;
    wayLine = nullptr;

    th.join();

    return 0;
}