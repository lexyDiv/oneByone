#pragma once

#include "Game/Game.cpp"

WayLine *wayLine = new WayLine();

void listenner(SDL_Event e, Game* game)
{
    while (SDL_PollEvent(&e) != 0)
    {
        // User requests quit
        if (e.type == SDL_QUIT)
        {
            
            game->quit = true;
        }
        if (e.type == SDL_KEYDOWN)
        {
            // console.log(to_string(e.key.keysym.scancode)); // int 40
            if (e.key.keysym.scancode == 40)
            {
                console.log("eneter");
              //  game->speed++;
              game->endLevel = false;
              game->check = 0;
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
            // fs.write("levels/level2.txt", pnt, sizeof(WayPoint));
            // wayLine->push(pnt);
            // pnt = nullptr;
            // console.log("click");

            mouse.pressKey(e.button.button);
            mouse.keyDown(e.button.button);
            // console.log("click point");
        }
        if (e.type == SDL_MOUSEBUTTONUP)
        {
            // console.log(to_string(e.button.button)); // 1, 2, 3
            mouse.upKey(e.button.button);
            mouse.keyUp(e.button.button);
        }
        if (e.type == SDL_MOUSEWHEEL)
        {

            console.whellOrder(e.motion.yrel);
        }
    }
}