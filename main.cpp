#include "hello.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

int main(int argc, char *argv[])
{
     SDL_Window* window = nullptr;
     SDL_Renderer* renderer = nullptr;

     int SCREEN_WIDTH=1000, SCREEN_HEIGHT=500;
     const char* WINDOW_TITLE = "Hello World!";
     window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
     renderer = createRenderer(window,SCREEN_WIDTH,SCREEN_HEIGHT  );

    SDL_Texture* background = loadTexture("bikiniBottom.jpg", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    SDL_RenderPresent( renderer );
    waitUntilKeyPressed();

    SDL_Texture* spongeBob = loadTexture("Spongebob.png", renderer);
    renderTexture(spongeBob, 1, 1,1000,1000, renderer);

    SDL_RenderPresent( renderer );
    waitUntilKeyPressed();

    SDL_DestroyTexture( spongeBob );
    spongeBob = NULL;
    SDL_DestroyTexture( background );
    background = NULL;

    quitSDL(window, renderer);
    return 0;
}
