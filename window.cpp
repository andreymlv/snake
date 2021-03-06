// Copyright(c) 2021 Andrey Malov

//
// Created by andreymlv on 10.07.2021.
//

#include "window.h"

Window::Window() {
    if (Init() && !LoadMedia()) {
        printf("Error! SDL_Error: %s\n", SDL_GetError());
    }

    while (!quit) {
        while (SDL_PollEvent(&event_handler_) != 0) {
            if (event_handler_.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_BlitSurface(image_, nullptr, screen_, nullptr);  // blit it to the screen
        SDL_UpdateWindowSurface(window_);
    }
}

Window::~Window() {
    SDL_FreeSurface(image_);
    image_ = nullptr;

    SDL_DestroyWindow(window_);
    window_ = nullptr;

    SDL_Quit();
}

bool Window::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    } else {
        window_ =
                SDL_CreateWindow("The Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                 SDL_WINDOW_OPENGL);

        if (window_ == nullptr) {
            printf("Could not create window: %s\n", SDL_GetError());
            return false;
        } else {
            screen_ = SDL_GetWindowSurface(window_);
        }
    }

    return true;
}

bool Window::LoadMedia() {
    image_ = SDL_LoadBMP("hello.bmp");
    SDL_BlitSurface(image_, nullptr, screen_, nullptr);  // blit it to the screen

    SDL_UpdateWindowSurface(window_);
    if (image_ == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "hello.bmp", SDL_GetError());
        return false;
    }

    return true;
}
