#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL_net.h>

#include "euro_def.h"

#include "cgdv.h"
#include "defines.h"

extern int network_on;
extern volatile int NetTeams[MAX_USERS], Players[MAX_USERS];

char EUROnetInitialise = FALSE;

//********************************************************************************************************************************

void InitEUROnet() {
    if(SDLNet_Init() == -1) {
        EUROnetInitialise = false;
        printf("Network cannot be initialised.\n%s\n", SDLNet_GetError());
        return;
    }

    EUROnetInitialise = true;
    printf("Network initialised okay.\n");
}

//********************************************************************************************************************************

void UnInitEUROnet() {
    if(EUROnetInitialise == true) {
        SDLNet_Quit();
    }
    EUROnetInitialise = false;
}

//********************************************************************************************************************************

char CountNumberOfNETstarts() {
    char Starts = 0;
    for(char i = 0; i < network_on; i++) {
#ifdef IMPLEMENT_ME
        if(NetTeams[i] >= 2) {
            Starts++;
        }
#endif
    }
    return (char)(network_on - Starts);
}

//********************************************************************************************************************************

