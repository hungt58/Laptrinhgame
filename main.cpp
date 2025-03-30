#include <bits/stdc++.h>
#include "hello.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "movea.h"
#include "menu.h"

using namespace std;
//Mix_Music* bgMusic = NULL;

int main(int argc, char *argv[])
{

    SDL_Window* window = nullptr;
     SDL_Renderer* renderer = nullptr;

     int SCREEN_WIDTH=1000, SCREEN_HEIGHT=500;
     const char* WINDOW_TITLE = "Hello World!";
     window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
     renderer = createRenderer(window,SCREEN_WIDTH,SCREEN_HEIGHT  );
     SDL_Texture* background = loadTexture("bgbannhau.jpg", renderer,0,0,0);
     SDL_RenderCopy (renderer,background,NULL,NULL);
     SDL_Texture* crta;//= loadTexture("human64x91.png",renderer,0,255,255);
    chaymenu(crta,renderer,background);

     waitUntilKeyPressed();
     SDL_DestroyTexture(background);
     background=NULL;

     quitSDL(window, renderer);
     return 1;
}
