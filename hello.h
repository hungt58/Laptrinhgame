#ifndef HELLO_H
#define HELLO_H
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;
    void logErrorAndExit(const char* msg, const char* error);
    SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);
    SDL_Renderer* createRenderer(SDL_Window* window,int SCREEN_WIDTH, int SCREEN_HEIGHT);
    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
    void waitUntilKeyPressed();
    void renderTexture(SDL_Texture *texture, int x, int y,int u, int v, SDL_Renderer* renderer,int to);
    SDL_Texture* loadTexture(const char* filename,SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b);
    SDL_Rect creatRect(int x,int y,int u,int v);
    void prepareSence();
    void presentSence();

#endif
