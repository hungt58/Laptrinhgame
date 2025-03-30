#include "menu.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "hello.h"
#include "movea.h"

// Hàm tải texture

int showOptions(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = {255, 255, 255, 255};
    const char* options[] = {"Easy", "Medium", "Hard"};
    SDL_Rect optionRects[3];

    // Thiết lập vị trí cho các tùy chọn
    for (int i = 0; i < 3; ++i) {
        optionRects[i] = {300, 150 + i * 100, 200, 50};
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) return -1;

            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);

                // Kiểm tra xem người chơi đã chọn mức độ nào
                for (int i = 0; i < 3; ++i) {
                    if (x >= optionRects[i].x && x <= optionRects[i].x + optionRects[i].w &&
                        y >= optionRects[i].y && y <= optionRects[i].y + optionRects[i].h) {
                        return i + 1; // Trả về 1, 2 hoặc 3 tùy theo mức độ
                    }
                }
            }
        }

        // Vẽ các tùy chọn lên màn hình
        SDL_RenderClear(renderer);
        for (int i = 0; i < 3; ++i) {
            SDL_Surface* surface = TTF_RenderText_Solid(font, options[i], textColor);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(renderer, texture, NULL, &optionRects[i]);
            SDL_DestroyTexture(texture);
        }
        SDL_RenderPresent(renderer);
    }
    return 0;
}
// Hàm hiển thị menu
int difficulty=1;
int showMenu(SDL_Renderer* renderer, TTF_Font* font) {
    // Tạo màu cho text
    SDL_Color textColor = {255, 255, 255, 255};

    // Tạo bề mặt background1
    SDL_Texture* background1 = loadTexture("66e2c9b675572 .png", renderer,0,0,0);
    if (!background1) {
        return -1;
    }
     SDL_Texture* de = loadTexture("cuoi.png", renderer,0,0,0);
     SDL_Texture* thuong = loadTexture("medium.png", renderer,0,0,0);
     SDL_Texture* kho = loadTexture("hard.png", renderer,0,0,0);


    // Tạo bề mặt các nút
    SDL_Surface* playSurface = TTF_RenderText_Solid(font, "Play", textColor);
    SDL_Surface* optionsSurface = TTF_RenderText_Solid(font, "Option", textColor);
    SDL_Surface* exitSurface = TTF_RenderText_Solid(font, "Exit", textColor);

    SDL_Texture* playTexture = SDL_CreateTextureFromSurface(renderer, playSurface);
    SDL_Texture* optionsTexture = SDL_CreateTextureFromSurface(renderer, optionsSurface);
    SDL_Texture* exitTexture = SDL_CreateTextureFromSurface(renderer, exitSurface);

    // Giải phóng bề mặt
    SDL_FreeSurface(playSurface);
    SDL_FreeSurface(optionsSurface);
    SDL_FreeSurface(exitSurface);

    // Vị trí của các nút
    SDL_Rect playRect = {300, 200, 100, 50};
    SDL_Rect optionsRect = {300, 300, 100, 50};
    SDL_Rect exitRect = {300, 400, 100, 50};

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Xử lý sự kiện
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                return -1;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);

                // Kiểm tra vị trí click
                if (x >= playRect.x && x <= playRect.x + playRect.w &&
                    y >= playRect.y && y <= playRect.y + playRect.h) {
                    return 1;  // Bắt đầu game
                }

                if (x >= optionsRect.x && x <= optionsRect.x + optionsRect.w &&
                    y >= optionsRect.y && y <= optionsRect.y + optionsRect.h) {
                    int difficultyChoice = showOptions(renderer, font);
                    if (difficultyChoice == 1) difficulty = 1;
                    else if (difficultyChoice == 2) difficulty = 2;
                    else if (difficultyChoice == 3) difficulty = 3;
                    SDL_RenderClear(renderer);
                    if (difficulty==1) SDL_RenderCopy(renderer,de,NULL,NULL);
                    if (difficulty==2) SDL_RenderCopy(renderer,thuong,NULL,NULL);
                    if (difficulty==3) SDL_RenderCopy(renderer,kho,NULL,NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(1000);
                    std::cout << "Options selected" << std::endl;
                }

                if (x >= exitRect.x && x <= exitRect.x + exitRect.w &&
                    y >= exitRect.y && y <= exitRect.y + exitRect.h) {
                    return 0;  // Thoát game
                }
            }
        }

        // Vẽ background1
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background1, NULL, NULL);

        // Vẽ các nút
        SDL_RenderCopy(renderer, playTexture, NULL, &playRect);
        SDL_RenderCopy(renderer, optionsTexture, NULL, &optionsRect);
        SDL_RenderCopy(renderer, exitTexture, NULL, &exitRect);

        SDL_RenderPresent(renderer);
    }

    // Giải phóng texture
    SDL_DestroyTexture(background1);
    SDL_DestroyTexture(playTexture);
    SDL_DestroyTexture(optionsTexture);
    SDL_DestroyTexture(exitTexture);

    return 0;
}
int chaymenu(SDL_Texture* crta,SDL_Renderer* renderer , SDL_Texture* background)
{
     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    if (TTF_Init() == -1) {
        std::cerr << "TTF could not initialize! TTF Error: " << TTF_GetError() << std::endl;
        return -1;
    }




       TTF_Font* font = TTF_OpenFont("GEO_AI__.ttf", 25);
    if (!font) {
        std::cerr << "Failed to load font! TTF Error: " << TTF_GetError() << std::endl;
        return -1;
    }

    int menuChoice = showMenu(renderer, font);
    if (menuChoice == 1) {
        std::cout << "Game Started!" << std::endl;
        cout<<difficulty<<'\n';

        moveza(crta,100,350,16,renderer,background,difficulty);
    }

    // Dọn dẹp
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);


}
