#pragma once

#include "Game/Game.cpp"

WayLine *wayLine = new WayLine();

void listenner(SDL_Event e, bool &quit)
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
            WayPoint* pnt = new WayPoint(e.button.x, e.button.y);
            fs.write("levels/level1.txt", pnt, sizeof(WayPoint));
            wayLine->push(pnt);
            pnt = nullptr;
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
}