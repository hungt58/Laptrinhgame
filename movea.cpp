#include "MOVEA.H"
#include "hello.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
struct to
{
    double x,y,u,v;
};
int Rand(int L,int R) {
    assert(L <= R);
    return L + rd() % (R - L + 1);
}
vector<double> timming;
int timee=0,o=16,speedmonster=6,diffi,currentMap=0,battu=0,so=1;

vector<to> toadori,toadole,toadohi,toadoidle;
struct Character {
    int x, y, w, h,speedx,speedy,health;
    int frame = 0;
    vector<SDL_Texture*> frames;
    vector<SDL_Texture*> framesri;
    vector<SDL_Texture*> framesle;
    vector<SDL_Texture*> frameshi;
    vector<SDL_Texture*> hurt;
    vector<SDL_Texture*> dead;
};
typedef vector<Character> ii;
ii monsters;
vector<Character> monstersii ;
Character player,monster,monster1,monster2,monster3,boss,partz,hehe;
SDL_Event event;
SDL_Texture* spriteSheet;
SDL_Texture* spriteSheetup;
SDL_Texture* spriteSheetidle;
SDL_Texture* background;
SDL_Renderer* renderer;
SDL_Texture*  win;
SDL_Texture*  lose;
int oa=0;
SDL_Texture* princessTexture ;
Mix_Music* bgMusic = NULL;
TTF_Font* font = nullptr;
SDL_Texture* helpText = nullptr;
SDL_Rect helpTextRect;
void initAudio() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }

    bgMusic = Mix_LoadMUS("freefire.mp3");
    if (bgMusic == NULL) {
        printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
    } else {
        printf("Nhac da duoc load thanh cong!\n");
    }
}

void playMusic() {
    if (Mix_PlayingMusic() == 0) {
        Mix_VolumeMusic(MIX_MAX_VOLUME);
        if (Mix_PlayMusic(bgMusic, -1) == -1) {
            printf("Loi khi phat nhac: %s\n", Mix_GetError());
        } else {
            printf("Nhac nen dang phat...\n");
        }
    }
}

void cleanAudio() {
    Mix_FreeMusic(bgMusic);
    Mix_CloseAudio();
}
void layanh(SDL_Renderer* renderer,int difficulty)
{
    spriteSheet=loadTexture("run.png",renderer,1,1,1);
    for (int i = 0; i < 8; i++)
    {
             toadori.push_back({ i * 73, 0, 73, 86 });

    }
    for (int i = 7; i>=0;  i--)
    {
            toadole.push_back({ i * 73, 0, 73, 86 });

    }
    toadole.push_back(toadori[7]);
    spriteSheet=loadTexture("walk.png",renderer,0,0,0);
    spriteSheetup=loadTexture("jump1.png",renderer,0,0,0);
    spriteSheetidle=loadTexture("idle.png",renderer,0,0,0);
    win=loadTexture("win.jpg",renderer,0,0,0);
    lose=loadTexture("lose.jpg",renderer,0,0,0);
    for (int i = 0; i < 6; i++)
    {
            toadohi.push_back({ i * 80, 0, 72, 86 });
    }
    for (int i = 0; i < 4; i++)
    {
            toadoidle.push_back({ i * 72.5, 0, 72, 86 });
    }

    for (int i = 0; i <= 9; i++) {
        std::string path = "0_Skeleton_Crusader_Running_00" + std::to_string(i) + ".png";
        SDL_Texture* tex = loadTexture(path.c_str(),renderer,0,0,0);
        if (tex) monster.frames.push_back(tex);
    }
    for (int i = 0; i <= 9; i++) {
        std::string path = "0_Skeleton_Crusader_Run Slashing_00" + std::to_string(i) + ".png";
        SDL_Texture* tex = loadTexture(path.c_str(),renderer,0,0,0);
        if (tex) monster1.frames.push_back(tex);
    }
    for (int i = 0; i <= 9; i++) {
        std::string path = "Attack_00" + std::to_string(i) + ".png";
        SDL_Texture* tex = loadTexture(path.c_str(),renderer,255,255,255);
        if (tex) boss.frames.push_back(tex);
    }
    for (int i = 0; i <= 9; i++) {
        std::string path = "Hurt_00" + std::to_string(i) + ".png";
        SDL_Texture* tex = loadTexture(path.c_str(),renderer,255,255,255);
        if (tex) boss.hurt.push_back(tex);
    }
     for (int i = 1; i <= 9; i++) {
        std::string path = "Dead_00" + std::to_string(i) + ".png";
        SDL_Texture* tex = loadTexture(path.c_str(),renderer,255,255,255);
        if (tex) boss.dead.push_back(tex);
    }
    for (int i = 1; i <= 5; i++) {
        std::string path = "part" + std::to_string(i) + ".png";
        SDL_Texture* tex = loadTexture(path.c_str(),renderer,255,255,255);
        if (tex) partz.frames.push_back(tex);
    }
    player.x=100;player.y=350;player.w=64,player.h=64;
    monster.x=Rand(0,1000);monster.y=Rand(0,500);monster.w=64,monster.h=64,monster.speedx=speedmonster;
    monster1.x=Rand(0,1000);monster1.y=Rand(0,500);monster1.w=64;monster1.h=64,monster1.speedx=speedmonster;
    monster2=monster1;
    monster3=monster1;
    monster2.x=Rand(0,1000);monster2.y=Rand(0,500);monster2.w=64;monster2.h=64,monster2.speedy=Rand(1,10);monster2.speedx=Rand(1,10);
    monster3.x=Rand(0,1000);monster3.y=Rand(0,500);monster3.w=64;monster3.h=64,monster3.speedy=Rand(1 ,10);monster3.speedx=Rand(1,10);
    monsters.push_back(monster);
    monsters.push_back(monster1);
    monsters.push_back(monster2);
    monsters.push_back(monster3);
    hehe=monster1;
    for (int i=1;i<=so;i++)
    {
    hehe.x=Rand(0,100);hehe.y=Rand(0,500);hehe.w=64;hehe.h=64,hehe.speedy=Rand(currentMap,10+diffi*2);hehe.speedx=Rand(currentMap,10+diffi*2);
    monsters.push_back(hehe);
    }
    boss.health=100;boss.x=500;boss.y=0,boss.w=600,boss.h=500;
    so+=diffi;

  /*  font = TTF_OpenFont("GEO_AI__.ttf", 25);
    SDL_Color textColor = {255, 255, 255}; // Trắng
    SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, "Cách chơi: A/D để di chuyển, J để đánh", textColor);
    helpText = SDL_CreateTextureFromSurface(renderer, textSurface);

    helpTextRect.x = 10;
    helpTextRect.y = 900;
    helpTextRect.w = textSurface->w;
    helpTextRect.h = textSurface->h;

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(helpText);
    TTF_CloseFont(font);
    TTF_Quit();*/
}


void nextMap() {
    battu=0;
    currentMap++;  // Chuyển sang map tiếp theo
    if (currentMap > 3) currentMap = 1;  // Vòng lại map 1 nếu hết map
    // Tải ảnh nền mới dựa trên map hiện tại
    std::string mapPath = "map" + std::to_string(currentMap) + ".png";
    background = loadTexture(mapPath.c_str(), renderer, 0, 0, 0);

    // Thiết lập lại vị trí nhân vật
    player.x = 0;
    player.y = 355;

    // Thiết lập lại quái vật
    monsters.clear();
    layanh(renderer,diffi);  // Gọi lại hàm để tạo quái vật mới
    printf("Đã chuyển sang map %d\n", currentMap);
}

bool moveLeft=false,moveRight=false,moveUp=false,moveDown=false;
int wo=0;
bool checkCollision(SDL_Rect a, SDL_Rect b) {
    if (a.x + a.w <= b.x){ wo=1;return false;} // a nằm hoàn toàn bên trái b
    if (b.x + b.w <= a.x){ wo=2;return false;} // b nằm hoàn toàn bên trái a
    if (a.y + a.h <= b.y){ wo=3;return false;} // a nằm hoàn toàn bên trên b
    if (b.y + b.h <= a.y){ wo=4;return false;}// b nằm hoàn toàn bên trên a
    return true; // Nếu không rơi vào các trường hợp trên thì có giao nhau
}
int chet=0,danh=8,danhdau=0,timerespon=20;
SDL_Rect   partect;  int quit2=0;
void lastmap()
{

    if (quit2==0)
    {
          SDL_RenderClear(renderer);
      SDL_Texture* huongdachoi=loadTexture("hi2.jpg",renderer,0,0,0);
      SDL_RenderCopy(renderer,huongdachoi,NULL,NULL);
      SDL_RenderPresent(renderer);
        SDL_Event ea;

    while (quit2==0)
        {
        while (SDL_PollEvent(&ea) != 0) {
            if ( ea.type == SDL_KEYDOWN&& ea.key.keysym.sym == SDLK_RIGHT) {quit2=1;break;}
            }
        }

    }
    SDL_Rect bossRect = {boss.x, boss.y, boss.w, boss.h};
    SDL_Rect spriterect = {player.x, player.y, player.w, player.h};
    if (danh==8&&chet==0)
    {
        SDL_RenderCopy(renderer, boss.frames[boss.frame], NULL, &bossRect);
        boss.frame = (boss.frame + 1) % boss.frames.size();
    }else if (chet==0)
    {
        danh=danh+1;
        SDL_RenderCopy(renderer, boss.hurt[boss.frame], NULL, &bossRect);
        boss.frame = (boss.frame + 1) % boss.hurt.size();
    }
    else if (chet==1&&danh<=8)
    {
        danh++;
        SDL_RenderCopy(renderer, boss.dead[boss.frame], NULL, &bossRect);
        boss.frame = (boss.frame + 1) % boss.dead.size();
    }
    else
    {
        SDL_RenderCopy(renderer, boss.dead[8], NULL, &bossRect);
    }
    if (chet==0)
    {
        if (checkCollision(spriterect,bossRect)==1&&spriterect.x-bossRect.x>=20)
        {
             SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, lose, NULL, NULL);
                    SDL_RenderPresent(renderer);
            SDL_Delay(2000); // Đợi 2 giây trước khi thoát
            exit(0); // Kết thúc game
        }
        if (checkCollision(partect,spriterect)==1 &&timerespon==0)
        {
            boss.health-=20;
            if (boss.health==0) chet=1;
            partz.frame = (partz.frame + 1) % partz.frames.size();
            danhdau=0;
            danh=0;
            timerespon=20;
        }
        if (danhdau==0) {partect ={Rand(0,500),Rand(100,300),30,30};danhdau=1;}
        if (timerespon==0) SDL_RenderCopy(renderer, partz.frames[partz.frame], NULL, &partect); else timerespon--;
    }

    // Vẽ thanh máu phía trên đầu boss
    int healthBarWidth = boss.health * 3;  // Độ dài thanh máu tỷ lệ với máu
    SDL_Rect healthBar = {650, 150, healthBarWidth, 20};  // Vị trí trên đầu boss
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Màu đỏ
    SDL_RenderFillRect(renderer, &healthBar);

    // Vẽ công chúa
    SDL_Rect princessRect = {1000 - 64, 500 - 64, 64, 64};
    SDL_RenderCopy(renderer, princessTexture, NULL, &princessRect);

// Kiểm tra va chạm với công chúa
    if (player.x + 50 > princessRect.x && player.x < princessRect.x + 50 &&
        player.y + 50 > princessRect.y && player.y < princessRect.y + 50)
        {
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, win, NULL, NULL);

                    SDL_RenderPresent(renderer);
            SDL_Delay(2000); // Đợi 2 giây trước khi thoát
            exit(0); // Kết thúc game
        }
}
int ob=0;

void updateGame(int speed) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);

    // Di chuyển nhân vật
    if (moveLeft)  player.x -= speed;
    if (moveRight) player.x += speed;
    if (moveUp)    player.y -= speed;
    if (moveDown)  player.y += speed;

    // Giữ nhân vật trong giới hạn màn hình
    if (player.x < 0) player.x = 0;
    if (player.x > 995) {player.x=0;nextMap();}
    if (player.y < 0) player.y = 0;
    if (player.y > 500) player.y = 355;
    if (moveRight)
    {
        oa++;
        if (oa>=6) oa=1;
        SDL_Rect srcRect = {toadori[oa].x, toadori[oa].y, toadori[oa].u, toadori[oa].v};  // Frame đầu tiên
        SDL_Rect dstRect = {player.x, player.y, 64, 64};
        SDL_RenderCopy(renderer, spriteSheet, &srcRect, &dstRect);
    }else
    if (moveLeft)
    {
        oa++;
        if (oa>=6) oa=1;
        SDL_Rect srcRect = {toadole[oa].x, toadole[oa].y, toadole[oa].u, toadole[oa].v};  // Frame đầu tiên
        SDL_Rect dstRect = {player.x, player.y, 64, 64};
        SDL_RenderCopy(renderer, spriteSheet, &srcRect, &dstRect);
    }else
    if (moveUp)
    {
        oa++;
        if (oa>=6) oa=1;
        SDL_Rect srcRect = {toadohi[oa].x, toadohi[oa].y, toadohi[oa].u, toadohi[oa].v};  // Frame đầu tiên
        SDL_Rect dstRect = {player.x, player.y, 64, 64};
        SDL_RenderCopy(renderer, spriteSheetup, &srcRect, &dstRect);
    }
    else
    {
        oa++;
        if (oa>=2) oa=1;


        SDL_Rect srcRect = {toadoidle[oa].x, toadoidle[oa].y, toadoidle[oa].u, toadoidle[oa].v};  // Frame đầu tiên
        SDL_Rect dstRect = {player.x, player.y, 64, 64};
        SDL_RenderCopy(renderer, spriteSheetidle, &srcRect, &dstRect);
    }

    // Cập nhật & di chuyển quái vật
    for (auto& monster : monsters) {
        monster.x += monster.speedx;  // Quái vật di chuyển về phía trước
        monster.y += monster.speedy;  // Quái vật di chuyển về phía trước
        if (monster.x > 995) monster.x = 0;
        if (monster.y > 500) monster.y = 0;
        monster.frame = (monster.frame + 1) % monster.frames.size();
        SDL_Rect monsterRect = {monster.x, monster.y, monster.w, monster.h};
        SDL_RenderCopy(renderer, monster.frames[monster.frame], NULL, &monsterRect);
    }
    if (currentMap==3)
    {
        lastmap();
    }
    SDL_RenderPresent(renderer);
}


void moveza (SDL_Texture * crta, int x, int y ,int speed,SDL_Renderer* renderer1,SDL_Texture * background1,int difficult)
{
     renderer=renderer1;
      SDL_RenderClear(renderer);
      SDL_Texture* huongdachoi=loadTexture("hi.jpg",renderer,0,0,0);
      SDL_RenderCopy(renderer,huongdachoi,NULL,NULL);
      SDL_RenderPresent(renderer);
      SDL_Event e;
      int quit=0;
    while (quit==0)
        {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_MOUSEBUTTONDOWN||e.type == SDL_KEYDOWN) quit=1;
            }
        }


    diffi=difficult;
    moveLeft=false,moveRight=false,moveUp=false,moveDown=false;


//    spriteSheetup=loadTexture("Jump1.png",renderer,0,0,0);
    layanh(renderer,diffi);
    renderTexture(crta,100,335,NULL,NULL,renderer,1);
    player.w=64;
    player.h=64;
     princessTexture = loadTexture("princess.png",renderer,0,0,0);
     initAudio();
   playMusic();
    bool running = true;
    background = loadTexture("map1.png",renderer,0,0,0);
      while (running) {

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:  moveLeft = true; break;
                case SDLK_RIGHT: moveRight = true; break;
                case SDLK_UP:    moveUp = true; break;
                case SDLK_DOWN:  moveDown = true; break;
                case SDLK_ESCAPE: running = false; break;
            }
        }
        else if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:  moveLeft = false; break;
                case SDLK_RIGHT: moveRight = false; break;
                case SDLK_UP:    moveUp = false; break;
                case SDLK_DOWN:  moveDown = false; break;
            }
        }
    }
    speed=4;
    // Gọi hàm update để di chuyển nhân vật & quái vật đồng thời*/
     updateGame(10);
     battu++;
    for (auto &monster : monsters) {
    SDL_Rect monsterRect = { monster.x, monster.y, monster.w, monster.h };
    SDL_Rect playerRect = { player.x, player.y, player.w, player.h };
    wo=0;int check=0;
    if (checkCollision(playerRect, monsterRect)&&battu>20)
    {
        check=1;

        if (wo==0)
        {
        if (monsterRect.x-playerRect.x>30) check=0;
        if (playerRect.x-monsterRect.x>15) check=0;
        if (playerRect.y-monsterRect.y>30) check=0;
        if (monsterRect.y-playerRect.y>30) check=0;

        }
    else
    if (monsterRect.y - playerRect.y <64)//|| abs(playerRect.y - monsterRect.y) > 4)
    {
        if (playerRect.x-monsterRect.x>5) continue;
    }
    if (check==1)
        {
        printf("Player: x=%d, y=%d, w=%d, h=%d\n", playerRect.x, playerRect.y, playerRect.w, playerRect.h);
         printf("Monster: x=%d, y=%d, w=%d, h=%d\n", monsterRect.x, monsterRect.y, monsterRect.w, monsterRect.h);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, lose, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
        cleanAudio();
        running = false;
        }
    }
      }

        SDL_Delay(60);

}
}
