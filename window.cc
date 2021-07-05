#include "window.h"

Window::Window()
{
    if (Init() == false)
    {
        printf("Error! SDL_Error: %s\n", SDL_GetError());
    }

    if (LoadMedia() == false)
    {
        printf("Error! SDL_Error: %s\n", SDL_GetError());
    }
}

Window::~Window()
{
    SDL_FreeSurface(image_);
    image_ = NULL;

    SDL_DestroyWindow(window_);
    window_ = NULL;

    SDL_Quit();
}

bool Window::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    else
    {
        window_ = SDL_CreateWindow(
            "The Snake Game",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_OPENGL);

        if (window_ == NULL)
        {
            printf("Could not create window: %s\n", SDL_GetError());
            return false;
        }
        else
        {
            screen_ = SDL_GetWindowSurface(window_);
        }
    }

    return true;
}

bool Window::LoadMedia()
{
    image_ = SDL_LoadBMP("hello.bmp");
    SDL_BlitSurface(image_, NULL, screen_, NULL); // blit it to the screen

    SDL_UpdateWindowSurface(window_);
    if (image_ == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "hello.bmp", SDL_GetError());
        return false;
    }

    SDL_Delay(3000);

    return true;
}
