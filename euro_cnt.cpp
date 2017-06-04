/* Copyright (C) 1997 Gremlin Interactive Ltd.
 * With modifications by Mark E Sowden
 */

#include <stdio.h>
#include <SDL/SDL.h>

#include "eurodefs.h"
#include "euro_fxd.h"
#include "euro_def.h"
#include "euro_var.h"

#include "defines.h"

//**********************************************************************************************************************

uint8_t InitialiseUser(uint8_t user, uint8_t cntrl) {
    if (EUROgameType == EURO_friendly) {
        UserList[user].control = cntrl;
        user++;
    }

    if (EUROgameType == EURO_championship) {
        UserList[user].control = cntrl;
        user++;
    }

    if ((EUROgameType == EURO_network_game || EUROgameType == EURO_wireplay)
        && user == 0) {
        UserList[user].control = cntrl;
        user = 1;
    }

    return user;
}

//**********************************************************************************************************************

uint8_t CalculateMaxPlayers() {
    uint8_t players = 0;
    for (uint8_t p = 0; p < 16; p++) {
        if (CtrlFlags[p] == Usable)
            players++;
    }

    return players;
}

//**********************************************************************************************************************

void SetupMouseLimits(int Xmin, int Xmax, int Ymin, int Ymax) {
#ifdef IMPLEMENT_ME
        union REGS rg;
        rg.x.ecx = Xmin;
        rg.x.edx = Xmax;
        rg.x.eax = 7;
        int386(0x33,&rg,&rg);
        rg.x.ecx = Ymin;
        rg.x.edx = Ymax;
        rg.x.eax = 8;
        int386(0x33,&rg,&rg);
#endif
}

//**********************************************************************************************************************

uint8_t SetupControlMethods() {
    for (char m = 0; m < 16; m++) { CtrlFlags[m] = Unusable; }

// ***> Configure KEYBOARD 1

    CtrlFlags[EuroKeyboard1] = (char) Usable;
    uint8_t user = InitialiseUser(0, EuroKeyboard1);

    if (EUROverbose)
        printf("Keyboard 1 initialised.\n");

// ***> Configure KEYBOARD 2

    CtrlFlags[EuroKeyboard2] = (char) Usable;
    user = InitialiseUser(user, EuroKeyboard2);

    if (EUROverbose)
        printf("Keyboard 2 initialised.\n");

    if(SDL_InitSubSystem(SDL_INIT_JOYSTICK) == 0) {

// ***> Configure JOYSTICK 1

        CtrlFlags[EuroJoystick1] = (char) Usable;
        user = InitialiseUser( user, EuroJoystick1 );

        if(EUROverbose)
            printf("Joystick 1 initialised.\n");

// ***> Configure JOYSTICK 2

        CtrlFlags[EuroJoystick2] = (char) Usable;
        user = InitialiseUser( user, EuroJoystick2 );

        if(EUROverbose)
            printf("Joystick 2 initialised.\n");
    } else {
        printf("Failed to initialise SDL joystick subsystem!\n%s\n", SDL_GetError());
    }

// ***> Configure MOUSE

    CtrlFlags[EuroMouse] = (char) Usable;
    SetupMouseLimits( 0, 626, 1, 452 );
    user = InitialiseUser( user, EuroMouse);

    if (EUROverbose)
        printf("Mouse Driver found and initialised.\n");

    return CalculateMaxPlayers();
}

//**********************************************************************************************************************

float WhichButton(float var) {
    if (ButtonState == LEFT_BUTTON)
        return -var;

    return var;
}

//**********************************************************************************************************************

void GetConsoleInput() {
    SDL_PumpEvents();

    SDL_GetMouseState(&SelectorXcoord, &SelectorYcoord);
    if(SDL_BUTTON(SDL_BUTTON_LEFT)) {
        ButtonState = LEFT_BUTTON;
    } else if(SDL_BUTTON(SDL_BUTTON_RIGHT)) {
        ButtonState = RIGHT_BUTTON;
    }
}

//**********************************************************************************************************************
