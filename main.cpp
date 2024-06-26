#include "vars_images.h"

int main()
{

    WayLine *wayLine = new WayLine();
    rapid<WayPoint> testArr = fs.read<WayPoint>("levels/level1.txt", sizeof(WayPoint));
    wayLine->update(testArr);
    
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
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN)
            {
                // console.log(to_string(e.key.keysym.scancode)); // int 40
                if (e.key.keysym.scancode == 40)
                {
                    console.log("eneter");
                }
            }
            if (e.type == SDL_MOUSEMOTION)
            {
                mouse.move(e.motion.x, e.motion.y);
                // console.log(to_string(e.motion.x));
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                // console.log(to_string(e.button.x)); // 1, 2, 3
                // WayPoint* pnt = new WayPoint(e.button.x, e.button.y);
                // fs.write("levels/level1.txt", pnt, sizeof(WayPoint));
                // wayLine->push(pnt);
                // pnt = nullptr;
                console.log("click");

                mouse.pressKey(e.button.button);
                // console.log("click point");
            }
            if (e.type == SDL_MOUSEBUTTONUP)
            {
                // console.log(to_string(e.button.button)); // 1, 2, 3
                mouse.upKey(e.button.button);
            }
            if (e.type == SDL_MOUSEWHEEL)
            {

                console.whellOrder(e.motion.yrel);
            }
        }
        console.proc(mouse.x, mouse.y, mouse.leftKey);

        // ctx.ClearRect(0, 0, 800, 600);

        // console.log("Is worcking !!!");

        ctx.CreateDrawZone(0, 0, 800, 600);
        ctx.FillRect(0, 0, 800, 600, "white");
        wayLine->drawPoints();

        console.draw();
        ctx.End();
    }

    ctx.Close();
    delete test;
    test = nullptr;
    delete wayLine;
    wayLine = nullptr;

    return 0;
}