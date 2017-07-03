/* Copyright (C) 1997 Gremlin Interactive Ltd.
 * With modifications by Mark E Sowden
 */

#include <SDL2/SDL.h>

#include "mallocx.h"

#include "eurodefs.h"
#include "euro_def.h"
#include "euro_fxd.h"
#include "euro_var.h"
#include "euro_cnt.h"
#include "euro_usr.h"
#include "euro_net.h"
#include "euro_cmd.h"
#include "euro_dsk.h"
#include "euro_mem.h"
#include "euro_spt.h"
#include "euro_int.h"
#include "euro_grf.h"
#include "euro_gen.h"

#include "euro.equ"

#include "defines.h"
#include "config.h"
#include "3deng.h"
#include "gamedata.h"
#include "results.h"
#include "intronet.h"
#include "timer.h"
#include "menu.h"

//**********************************************************************************************************************

/* todo, seperate both game-logic and engine-logic so that we can easily support different versions of ActuaSoccer?
 * todo, cut down on the number of globals and tidy them up as much as possible!!
 * todo, modernise the codebase, start moving code over to organised classes etc.
 * todo, move over to SDL2 and OpenGL
 * todo, remove the 'euro' prefix, make code more generic where applicable
 */

#define VERSION_MAJOR   0
#define VERSION_MINOR   1

#define GAME_TITLE  "VR Soccer"

void InitializeGameVariables() { // todo, move these into their own class handler / whatever
    LogicState      = BLANK_SCREEN;
    Team            = England;
    Menu            = MAIN;
    NoOfSubs        = 4;
    UsableSubs      = 4;
    WinPts          = 3;
    DrawPts         = 1;
    MatchNumber     = 0;
    ChangeMenu      = -2;
    RunMatch        = No;

    EUROday             = 2;
    EUROmonth           = 2;
    EUROyear            = 96;
    EUROgameType        = EURO_championship;    //friendly;
    EUROteamA           = England;
    EUROteamB           = Scotland;
    EUROteamView        = 0;
    EUROnoOfMatchPlyrs  = 1;
    EUROplyrSetup       = 0;
}

void InitialiseAudio() {
    InitialiseTimer();



#ifdef IMPLEMENT_ME
    if(InitialiseDIGI(22050, 0)) { // Initialise Digital Sound Drivers
        return (EXIT_FAILURE);
    }
#endif
}

void InitialiseVideo() {
    SDL_Window *window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if(!window) {
        printf("Failed to create window!\n%s", SDL_GetError());
        exit(-1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
    if(!renderer) {
        printf("Failed to create renderer!\n%s", SDL_GetError());
        exit(-1);
    }


}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("\nACTUA SOCCER '96\n");
    printf("(C) 1997 Gremlin Interactive Ltd.\n");
    printf("With modifications by Mark E Sowden\n\n");
    printf("Version: %d.%d      " __DATE__ "\n\n", VERSION_MAJOR, VERSION_MINOR);

    printf("-------------------------------------------\n\n");

    InitializeGameVariables();

    ProcessCommandLine(argc, argv);

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        printf("Failed to initialize SDL!\n%s", SDL_GetError());
        return -1;
    }

    if (EUROverbose != 0) {
        printf("Memory check: %d\n", get_mem_info());
    }

    ResetUsers();

    EUROmaxPlayers = SetupControlMethods();

    InitEUROnet();
    if (!EUROnetInitialise && EUROgameType == EURO_network_game) {
        EUROgameType = EURO_friendly;
    }

    ReadDataOffsetFile(EuroOFFSETfile);

    Euro96_MemoryInitialise();

    TextStringMemHandle = AllocateTextStringMemory();
    printf("%d Bytes allocated for script file text.\n", TEXT_STRING_BUFFER_LEN);

    if (EUROsymbol) {
        fp2 = fopen("euro_sym.h", "wb");
        if (fp2 == NULL) {
            EUROsymbol = false;
            printf("Error trying to create symbol table.\n");
        }
    }

    process_script_file(EuroSCRIPTfile);

    if (EUROsymbol) {
        fclose(fp2);
        printf("Symbol table created.\n");
        DeAllocateMemory(TextStringMemHandle);
        exit(-1);
    }

    if (EUROgameType == EURO_wireplay) {
        printf("Wireplay Teams:    %s  V", GetTEAMname(EUROteamA, 11));
        printf("  %s\n", GetTEAMname(EUROteamB, 11));
    }

    AllocateDisplayBuffers();

    TexturePageMemHandle = AllocateTexturePageMemory(8, &FrontendTextureDEFN);
    FrontendTextureDEFN.page_start = TexturePages;
    LoadTexturePage(BIN_PAGE1, EuroDATfile, 0, &FrontendTextureDEFN);

    LoadPalette(BIN_TSELPAL, EuroDATfile, 0);        // creates special filters for team select section.
    CreateFilter(&FilterBuffer[256], 40, 54, 60, .7, .7, .7);
    CreateFilter(&FilterBuffer[512], 40, 54, 60, .6, .6, .6);
    CreateFilter(&FilterBuffer[768], 40, 54, 60, .5, .5, .5);
    CreateFilter(&FilterBuffer[1024], 40, 54, 60, .4, .4, .4);
    CreateFilter(&FilterBuffer[1280], 40, 54, 60, .3, .3, .3);
    CreateFilter(&FilterBuffer[1536], 40, 54, 60, .2, .2, .2);
    CreateFilter(&FilterBuffer[1792], 40, 54, 60, .1, .1, .1);

    // todo, implementation for this is missing
    //ReadConfigFile();

    memset(&match_info, 0, sizeof(match_data));
    match_info.menu_res                 = HI;
    match_info.tga_enable               = OFF;
    match_info.language                 = (char) English;
    match_info.referee                  = 16 + 16;
    match_info.CompetitionType          = FRIENDLY;
    match_info.CompetitionType_toggle   = FRIENDLY;

    match_info.control_methods[0]   = EuroKeyboard1;
    match_info.control_methods[1]   = EuroKeyboard2;
    match_info.control_methods[2]   = EuroJoystick1;
    match_info.control_methods[3]   = EuroJoystick2;
    match_info.control_methods[4]   = EuroMouse;
    match_info.control_methods[5]   = EuroLogictechPad;

    //net_half = (volatile char) match_info.time;
    match_info.substitutes              = TRUE;
    match_info.substitutes_toggle       = TRUE;
    match_info.bookings                 = TRUE;
    match_info.bookings_toggle          = TRUE;
    match_info.freekicks                = TRUE;
    match_info.freekicks_toggle         = TRUE;

    memset(&batch_info, 0, sizeof(batch_data));
    batch_info.rolling_demo             = ROLLING_DEMO;
    batch_info.GDVres                   = HI;
    batch_info.match_number             = -1;
    batch_info.cup_match_number         = -1;
    batch_info.number_of_cup_teams      = 32;

    batch_info.keys_used[UP_RED]        = 0x1e; // A
    batch_info.keys_used[DN_RED]        = 0x2c; // Z
    batch_info.keys_used[LF_RED]        = 0x33; // <
    batch_info.keys_used[RT_RED]        = 0x34; // >
    batch_info.keys_used[F1_RED]        = 0x10; // Q
    batch_info.keys_used[F2_RED]        = 0x35; // /
    batch_info.keys_used[UP_RED + 6]    = -0x48;    // Arrow Up
    batch_info.keys_used[DN_RED + 6]    = -0x50;    // Arrow Dn
    batch_info.keys_used[LF_RED + 6]    = -0x4b;    // Arrow Lf
    batch_info.keys_used[RT_RED + 6]    = -0x4d;    // Arrow Rt
    batch_info.keys_used[F1_RED + 6]    = 0x52;     // 0(num)
    batch_info.keys_used[F2_RED + 6]    = 0x53;     // .(num)

    if (batch_info.rolling_demo == Off) {
        match_info.GameType = SIMULATION;
        match_info.GameType_toggle = SIMULATION;
    } else {
        match_info.GameType = ARCADE;
        match_info.GameType_toggle = ARCADE;
    }

    extern unsigned int timing(); // see 3deng.cpp
    unsigned int sys_speed = timing();
    if (sys_speed > 31)
        sys_speed = 31;

    memset(&setup, 0, sizeof(setup_info));
    setup.M8                = 1;    //DisplayFree();
    setup.detail.sky        = ON;
    setup.detail.stadia     = HI;
    setup.detail.lines      = ON;
    setup.vidi_type         = HI;
    setup.detail.players    = HI;
    setup.detail.pitch      = MED;
    setup.start_res         = LO;
    setup.screen_size       = 0;
    setup.stadium           = TRUE;
    setup.detail.sky        = detail_defaults[sys_speed].sky;
    setup.detail.stadia     = detail_defaults[sys_speed].stadia;
    setup.detail.pitch      = detail_defaults[sys_speed].pitch;
    setup.detail.players    = detail_defaults[sys_speed].players;
    setup.detail.lines      = detail_defaults[sys_speed].lines;
    setup.detail.shadows    = detail_defaults[sys_speed].shadows;
    setup.screen_size       = screen_defaults[sys_speed];
    setup.vidi_type         = NULL;
    setup.start_res         = NULL;

    reset_league_teams();

    InitialiseAudio();
    InitialiseVideo();

    ftick = 0;
    tick = 0;
    count = 0;
    game_speed = REAL_SPEED;
    readptr = writeptr = 0;

    AddTimer(TIMER_SPEED, nethandler, NetworkHandle);
    AddTimer(63, EUROinterupt, EuroHandle);

    FrontendBackgroundDEFN.pseudo_start = EuroBackgroundBuffer;
    FrontendPseudoDEFN.pseudo_start = EuroPseudoBuffer;
    Set_640x480_VideoMode();

    SetPaletteToBlack();

    return 0;
}