#include "vars_images.h"

// Image *test = new Image("union/src/zombi.png");

class WayPoint
{
public:
    WayPoint(){};
    WayPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int x;
    int y;
};

class WayPointContainer
{
public:
    int length = 0;
    WayPoint *arr[1000];
    void add(WayPoint *wPoint)
    {
        this->arr[this->length] = wPoint;
        this->length++;
    }
};

WayPointContainer wayPointContainer;

WayPoint *wPoint = new WayPoint(10, 10);
WayPoint *wPoint2 = new WayPoint(100, 100);

int main()
{
    ctx.getFont();
    bool quit = false;
    SDL_Event e;

    ///////////////////////////////////

    //  fs.write("levels/level1.txt", wPoint2);


    // rapid<WayPoint> arr = fs.read<WayPoint>("levels/level1.txt");
    // arr.forEach([](WayPoint el, int i)
    //             { console.log("i = " + to_string(i) + " x = " + to_string(el.x)); });



    while (!quit)
    {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN)
            {
                // console.log(to_string(e.type));
            }
            if (e.type == SDL_MOUSEMOTION)
            {
                mouse.move(e.motion.x, e.motion.y);
                // console.log(to_string(e.motion.x));
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                // console.log(to_string(e.button.button)); // 1, 2, 3
                mouse.pressKey(e.button.button);
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
        ctx.DrawImage(test, 0, 0, 256, 256, 0, 0, 100, 100);

        console.draw();
        ctx.End();
    }

    ctx.Close();
    delete test;
    test = nullptr;

    return 0;
}