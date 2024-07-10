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

vector<Roll*> arr;

int main()
{
    srand(time(0));


    /////////////


//////////////////

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