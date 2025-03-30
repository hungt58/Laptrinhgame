#ifndef MOVEA_H
#define MOVEA_H
#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
using namespace std ;

void moveza ( SDL_Texture* crta, int x, int y ,int speed,SDL_Renderer* renderer,SDL_Texture* background,int difficulty);
void moveanimation(SDL_Renderer* renderer,SDL_Texture * background);
void layanh(SDL_Renderer* renderer);
#endif
