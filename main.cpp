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
    bool needDel = false;
};

class WayPointContainer
{
public:
    int length = 0;
    WayPointContainer(){};
    rapid<WayPoint *> *arr = new rapid<WayPoint *>;

    void add(WayPoint* pnt)
    {
        this->arr->backForce(1);
        this->arr->push(pnt);
        this->arr->norm();
    }

    void add(WayPoint &pnt)
    {
        WayPoint* newPnt = new WayPoint(pnt.x, pnt.y);
        this->arr->backForce(1);
        this->arr->push(newPnt);
        this->arr->norm();
        newPnt = nullptr;
    }

    void update(rapid<WayPoint> &arr)
    {
        this->arr->backForce(arr.getLength());
        for (int i = 0; i < arr.getLength(); i++)
        {
            this->add(arr.getItem(i));
        }
        this->arr->norm();
    }

    void draw()
    {
        this->arr->forEach([](WayPoint *el)
                           { ctx.FillRect(el->x, el->y, 5, 5); });
    };

    ~WayPointContainer()
    {
        this->arr->forEach([](WayPoint *el)
                           {
        delete el;
        el = nullptr; });
        delete this->arr;
        this->arr = nullptr;
        printf(" delete arr !!!");
    }
};

WayPointContainer *wpc = new WayPointContainer();

// WayPoint *wPoint = new WayPoint(10, 10);
// WayPoint *wPoint2 = new WayPoint(100, 100);

WayPoint wPoint(10, 10);
WayPoint wPoint2(100, 100);

int main()
{
    ctx.getFont();
    bool quit = false;
    SDL_Event e;

    ///////////////////////////////////
    //   fs.write("levels/level1.txt", wPoint);
    //   fs.write("levels/level1.txt", wPoint2);

    rapid<WayPoint> arr = fs.read<WayPoint>("levels/level1.txt", sizeof(WayPoint));

    arr.forEach([](WayPoint el, int i)
                {
                     console.log(" x = " + to_string(el.x));
                    // wpc->add(el);
                      });
     // wpc->add(wPoint);
     // wpc->add(wPoint2);
    wpc->update(arr);


    rapid<WayPoint *> *saveArr = new rapid<WayPoint *>;
    saveArr->backForce(30);

    while (!quit)
    {
        // for (int i = 0; i < 1000000; i++)
        // {
        //     testArr->backForce(200);
        //     testArr2->backForce(200);
        //     for (int i = 0; i < 1; i++)
        //     {
        //         WayPoint *pnt = new WayPoint(i, 1);
        //         testArr->push(pnt);
        //         testArr2->push(pnt);
        //         pnt = nullptr;
        //     }
        //     testArr->norm();
        //     testArr2->norm();

        //     testArr->forEach([](WayPoint *el)
        //                      {
        //           el->needDel = true;
        //           el = nullptr;
        //     });
        //     testArr->clear();
        //     testArr2->forEach([](WayPoint *el)
        //                       {
        //     if(el->needDel)
        //     {
        //         delete el;
        //         el = nullptr;
        //        //console.log("el.x = " + to_string(el->x));
        //        if(el == nullptr)
        //        {
        //         console.log("el = nullptr");
        //        }
        //     el = nullptr;
        //     } });
        //     testArr2->clear();
        // } // ok !!!
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
                // console.log(to_string(e.key.keysym.scancode)); // int 40
                if (e.key.keysym.scancode == 40)
                {
                    console.log("eneter");
                    saveArr->norm();
                    saveArr->forEach([](WayPoint *pnt)
                                     {
                                         //  write("levels/level1.txt", pnt, sizeof(WayPoint));
                                         fs.write("levels/level1.txt", pnt, sizeof(WayPoint));
                                         //                     ofstream fout;
                                         // fout.open("levels/level1.txt", ofstream::app);
                                         // if (fout.is_open())
                                         // {
                                         //     fout.write((char *)pnt, sizeof(WayPoint));
                                         //     console.log("write");
                                         // }
                                         // else
                                         // {
                                         //     console.log("fuck u");
                                         // }
                                         // fout.close();
                                     });
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
                WayPoint *pnt = new WayPoint(e.button.x, e.button.y);
                saveArr->push(pnt);
                pnt = nullptr;
                console.log("click");
                // fs.write("levels/level1.txt", &pnt);

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
        wpc->draw();

        console.draw();
        ctx.End();
    }

    ctx.Close();
    delete test;
    test = nullptr;
    saveArr->forEach([](WayPoint *el)
                     {
        delete el;
        el = nullptr; });
    delete saveArr;
    saveArr = nullptr;
    delete wpc;
    wpc = nullptr;

    return 0;
}