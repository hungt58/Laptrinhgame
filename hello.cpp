#include "hello.h"

void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}
 SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
      logErrorAndExit("SDL_Init", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //full screen
    //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

     if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    logErrorAndExit( "SDL_image error:", IMG_GetError());

    return window;
}
void renderTexture(SDL_Texture *texture, int x, int y, int u,int v,SDL_Renderer* renderer,int to)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
    dest.w = u;
    dest.h = v;

 	if (to==1) SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h); // lấy kích thước thật của ảnh

	SDL_RenderCopy(renderer, texture, NULL, &dest);// hiển thị hình ảnh vào gpu
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

SDL_Texture* loadTexture(const char* filename,SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b) {

    /*
    Uint32 redKey   = SDL_MapRGB(loadedSurface->format, 255, 0, 0);   // Xóa màu đỏ
    Uint32 greenKey = SDL_MapRGB(loadedSurface->format, 0, 255, 0);   // Xóa màu xanh lá
    Uint32 blueKey  = SDL_MapRGB(loadedSurface->format, 0, 255, 255);   // Xóa màu xanh dương
    */
    // Load ảnh vào SDL_Surface trước
    SDL_Surface* surface = IMG_Load(filename);
    if (!surface) {
        SDL_Log("Failed to load image %s! SDL_image Error: %s", filename, IMG_GetError());
        return NULL;
    }
    // Thiết lập Color Key (Xóa màu nền)
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b));
    // Chuyển Surface thành Texture
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); // Giải phóng surface sau khi tạo texture
    if (!texture) {
        SDL_Log("Failed to create texture from %s! SDL Error: %s", filename, SDL_GetError());
    }

    return texture;
}
 SDL_Renderer* createRenderer(SDL_Window* window,int SCREEN_WIDTH, int SCREEN_HEIGHT )
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    return renderer;
}
queue<SDL_Texture*> q;
SDL_Texture* creatTexture()
{
        SDL_Texture* u=NULL;


        return u;
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    IMG_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

