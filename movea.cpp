#include "MOVEA.H"
#include "hello.h"
struct to
{
    int x,y,u,v;
};
vector<to> toadori,toadole,toadohi;
struct Character {
    int x, y, w, h;
    int frame = 0;
    vector<SDL_Texture*> framesri;
    vector<SDL_Texture*> framesle;
    vector<SDL_Texture*> frameshi;
};
Character player;
SDL_Event event;
SDL_Texture* spriteSheet;
void layanh(SDL_Renderer* renderer)
{
    spriteSheet=loadTexture("180Turn.png",renderer,0,0,0);
    SDL_Rect srcRect = { 851,190, 165, 153 };   // Cắt 1 frame 64x64 từ sprite sheet
    toadori.push_back({0,0,137,192});
    toadori.push_back({140,0,151,192});
    toadori.push_back({293,0,128,186});
    toadori.push_back({423,0,124,179});
    toadori.push_back({549,0,129,182});
    toadori.push_back({680,0,147,172});
    toadole.push_back({1,190,162,173});
    toadole.push_back({156,190,171,173});
    toadole.push_back({338,190,167,172});
    toadole.push_back({507,190, 169, 159 });
    toadole.push_back({678,190, 171, 155 });
    toadole.push_back({851,190, 165, 153 });

    SDL_Rect dstRect = { 100, 350, 64, 64 };  // Vị trí vẽ trên màn hình
    SDL_RenderCopy(renderer, spriteSheet, &srcRect, &dstRect);
    SDL_RenderPresent(renderer);
}

void moveright(SDL_Renderer* renderer,SDL_Texture * background,int x,int y ,int speed)
{
       /* int u=speed/8;
        for (int i=0;i<=7;i++)
        {
            x=x+u;
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, background, NULL, NULL);
            renderTexture(player.frames[i],x, y, NULL, NULL, renderer, 1);
            SDL_RenderPresent(renderer);
            SDL_Delay(16);
        }*/



}
void moveza (SDL_Texture * crta, int x, int y ,int speed,SDL_Renderer* renderer,SDL_Texture * background)
{
    layanh(renderer);
   /* renderTexture(crta,100,335,NULL,NULL,renderer,1);
    SDL_RenderPresent(renderer);
    player = {50, 350, 64, 64};
    for (int i = 1; i <= 8; i++) {
        string filename = "run-" + std::to_string(i) + ".png";
      //  player.frames.push_back(loadTexture(filename.c_str(), renderer,0,0,0));
    }
    bool running = true;
    // Vòng lặp game
        while (running) {
        while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    {
                    x -= speed;  // Di chuyển sang trái
                    break;
                    }
                case SDLK_RIGHT:
                    {
                        moveright(renderer,background,x,y,speed);
                        x += speed;  // Di chuyển sang phải
                        break;
                    }
                case SDLK_UP:
                    y -= speed;  // Di chuyển lên trên
                    break;
                case SDLK_DOWN:
                    y += speed;  // Di chuyển xuống dưới
                    break;
                case SDLK_ESCAPE:
                    running = false;  // Thoát game
                    break;
            }
        }
        }

        // Vẽ lại nền và nhân vật sau khi di chuyển
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
 //   renderTexture(player.frames[0], x, y, NULL, NULL, renderer, 1);
    SDL_RenderPresent(renderer);

    SDL_Delay(16); // Giới hạn tốc độ cập nhật (khoảng 60 FPS)
        }*/
}
