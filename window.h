#ifndef SNAKE_WINDOW_H_
#define SNAKE_WINDOW_H_

#include <SDL2/SDL.h>

class Window
{
private:
    // The window we'll be rendering to
    SDL_Window *window_ = NULL;

    // The surface contained by the window
    SDL_Surface *screen_ = NULL;

    // The image we will load and show on the screen
    SDL_Surface *image_ = NULL;

    // Starts up SDL and creates window
    bool Init();

    // Loads media
    bool LoadMedia();

public:
    Window();
    ~Window();
};

#endif // SNAKE_WINDOW_H_
