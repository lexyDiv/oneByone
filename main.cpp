#include "vars_images.h"

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
    SDL_Event e;

    while (!quit)
    {
        listenner(e, quit);
        console.proc(mouse.x, mouse.y, mouse.leftKey);
        //game.prog();
     

        ctx.CreateDrawZone(0, 0, 800, 600);
        ctx.FillRect(0, 0, 800, 600, "white");
       // game.draw();
        wayLine->drawPoints();

        console.draw();
        ctx.End();
    }

    ctx.Close();
    delete test;
    test = nullptr;
    // delete wayLine;
    // wayLine = nullptr;

    return 0;
}