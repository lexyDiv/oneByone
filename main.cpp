#include "vars_images.h"

void goWork()
{
    SDL_Event e;
    while (!game->quit)
    {

         listenner(e, game);
         console.proc(mouse.x, mouse.y, mouse.leftKey);
         game->prog();
         this_thread::sleep_for(chrono::milliseconds(25));
    }
}

int main()
{

    // rapid<WayPoint> testArr = fs.read<WayPoint>("levels/level1.txt", sizeof(WayPoint));
    // wayLine->update(testArr);

    // for (int i = 0; i < 10; i++)
    // {
    //     WayPoint *wayPoint = new WayPoint(i * 10, 10);
    //     wayLine->push(wayPoint);
    //     wayPoint = nullptr;
    // }
    // Container* testCont = wayLine->getItem(2, wayLine->getHead());
    // console.log("index : 2 = " + to_string(testCont->wayPoint->x));

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