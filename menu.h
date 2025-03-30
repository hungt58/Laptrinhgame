#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>


int showMenu(SDL_Renderer* renderer, TTF_Font* font);
int chaymenu(SDL_Texture* crta, SDL_Renderer * renderer, SDL_Texture* background);
#endif
