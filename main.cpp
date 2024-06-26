#include "vars_images.h"







int main()
{
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
        

        console.draw();
        ctx.End();
    }

    ctx.Close();
    delete test;
    test = nullptr;
    
    return 0;
}