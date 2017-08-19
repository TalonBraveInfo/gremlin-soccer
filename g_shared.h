/* Copyright (C) 1997 Gremlin Interactive Ltd.
 * With modifications by Mark E Sowden
 */

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_messagebox.h>

#define DisplayError(msg) \
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, GAME_TITLE " : Error", msg, NULL); \
    printf("%s\n", SDL_GetError())
#define DisplayWarning(msg) \
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, GAME_TITLE " : Warning", msg, NULL)

struct {
    SDL_Window      *window;
    SDL_Renderer    *renderer;
} g_state;
