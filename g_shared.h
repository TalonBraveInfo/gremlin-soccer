/* Copyright (C) 1997 Gremlin Interactive Ltd.
 * With modifications by Mark E Sowden
 */

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_messagebox.h>

#define MAX_FRAMERATE   60  // Maximum framerate for game-logic

#define DisplayError(...) \
    { \
    char strn_err[512] = { 0 }; \
    snprintf(strn_err, 512, __VA_ARGS__); \
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, GAME_TITLE " : Error", strn_err, NULL); \
    printf("%s\n", strn_err); \
    }
#define DisplayWarning(...) \
    { \
    char strn_err[512] = { 0 }; \
    snprintf(strn_err, 512, __VA_ARGS__); \
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, GAME_TITLE " : Warning", strn_err, NULL) \
    }


struct {
    SDL_Window      *window;
    SDL_Surface     *surface;
} g_state;
