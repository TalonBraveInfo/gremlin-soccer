#include <stdio.h>

#include "euro_def.h"

#include "cgdv.h"
#include "defines.h"

#define    MAX_USERS    20

extern int network_on;
extern volatile int NetTeams[MAX_USERS], Players[MAX_USERS];

char EUROnetInitialise = FALSE;

//********************************************************************************************************************************

void InitEUROnet() {
#ifdef IMPLEMENT_ME
    if ( ( hmiNETNOWInitSystem(20)!=_NETNOW_NO_ERROR) )
    {
        EUROnetInitialise	= FALSE;
        printf	("Network cannot be initialised.\n");
        fflush(stdout);
    }
    else
    {
        EUROnetInitialise	= TRUE;
        printf	("Network initialised okay.\n");
        fflush(stdout);
    }
#else
    EUROnetInitialise = FALSE;
    printf("Network cannot be initialised.\n");
#endif
}

//********************************************************************************************************************************

void UnInitEUROnet() {
#ifdef IMPLEMENT_ME
    if (EUROnetInitialise == Yes)
        hmiNETNOWUnInitSystem();
#endif
    EUROnetInitialise = FALSE;
}

//********************************************************************************************************************************

char CountNumberOfNETstarts() {
#ifdef IMPLEMENT_ME
    char Starts = 0;
    char i;

    for (i = 0; i < network_on; i++) {
        if (NetTeams[i] >= 2)
            Starts++;
    }
    return (char) (network_on - Starts);
#else
    return 0;
#endif
}

//********************************************************************************************************************************

