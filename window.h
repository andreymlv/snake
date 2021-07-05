// Copyright(c) 2021 Andrey Malov

#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>

class Window {
 public:
  Window();
  ~Window();

 private:
  // The window we'll be rendering to
  SDL_Window *window_ = NULL;

  // The surface contained by the window
  SDL_Surface *screen_ = NULL;

  // The image we will load and show on the screen
  SDL_Surface *image_ = NULL;

  // Event handler
  SDL_Event event_handler_;

  // Main loop flag
  bool quit = false;

  // Starts up SDL and creates window
  bool Init();

  // Loads media
  bool LoadMedia();
};

#endif  // WINDOW_H_
