// Copyright(c) 2021 Andrey Malov

//
// Created by andreymlv on 10.07.2021.
//

#ifndef MODERN_SNAKE_WINDOW_H
#define MODERN_SNAKE_WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
    Window();

    ~Window();

private:
    // The window we'll be rendering to
    SDL_Window *window_ = nullptr;

    // The surface contained by the window
    SDL_Surface *screen_ = nullptr;

    // The image we will load and show on the screen
    SDL_Surface *image_ = nullptr;

    // Event handler
    SDL_Event event_handler_{};

    // Main loop flag
    bool quit = false;

    // Starts up SDL and creates window
    bool Init();

    // Loads media
    bool LoadMedia();
};

#endif //MODERN_SNAKE_WINDOW_H
