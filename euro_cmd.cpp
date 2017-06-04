/* Copyright (C) 1997 Gremlin Interactive Ltd.
 * With modifications by Mark E Sowden
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <locale>

#include "3deng.h"
#include "defines.h"
#include "gamedata.h"

#include "eurodefs.h"
#include "euro_def.h"
#include "euro_fxd.h"
#include "euro_var.h"

//**********************************************************************************************************************

void ProcessCommandLine(int argc, char **argv) {
    signed char CommandLineTEAM = -1;
    EUROverbose = 0;
    EUROconsole = 0;
    EUROcommOVERIDE = (char) 128;

    // Inputs...
    for (int i = 1; i < argc; i++) {
        std::locale p;
        std::string command = argv[i];
        for(std::string::size_type j = 0; j < command.length(); ++j) {
            command[j] = std::tolower(command[j], p);
        }

        if (i < (argc - 1)) {
            std::string setting = argv[i + 1];
            for(std::string::size_type j = 0; j < setting.length(); ++j) {
                setting[j] = std::tolower(setting[j], p);
            }

            if (setting == "bul")
                CommandLineTEAM = Bulgaria;
            if (setting == "cro")
                CommandLineTEAM = Croatia;
            if (setting == "cze")
                CommandLineTEAM = Czech;
            if (setting == "den")
                CommandLineTEAM = Denmark;
            if (setting == "eng")
                CommandLineTEAM = England;
            if (setting == "fra")
                CommandLineTEAM = France;
            if (setting == "ger")
                CommandLineTEAM = Germany;
            if (setting == "hol")
                CommandLineTEAM = Holland;
            if (setting == "ita")
                CommandLineTEAM = Italy;
            if (setting == "por")
                CommandLineTEAM = Portugal;
            if (setting == "rom")
                CommandLineTEAM = Romania;
            if (setting == "rus")
                CommandLineTEAM = Russia;
            if (setting == "sco")
                CommandLineTEAM = Scotland;
            if (setting == "spa")
                CommandLineTEAM = Spain;
            if (setting == "swi")
                CommandLineTEAM = Switzerland;
            if (setting == "tur")
                CommandLineTEAM = Turkey;
        }

        //*****************************
        //*                           *
        //*     WIREPLAY COMMANDS     *
        //*                           *
        //*****************************

        if (command == "-wireplay") {
            printf("Attempting WIREPLAY game.\n");
            EUROgameType = EURO_wireplay;
        }

        if (command == "-network") {
            printf("Attempting NETWORK game.\n");
            EUROgameType = EURO_network_game;
        }

        if (command == "-friendly") {
            printf("Attempting FRIENDLY game.\n");
            EUROgameType = EURO_friendly;
        }

        if (EUROgameType == EURO_wireplay) {
            if (command == "-home") {
                if (CommandLineTEAM != -1)
                    EUROteamA = CommandLineTEAM;
            }

            if (command == "-away") {
                if (CommandLineTEAM != -1)
                    EUROteamB = CommandLineTEAM;
            }
        }

        //*****************************
        //*                           *
        //*      GENERAL COMMANDS     *
        //*                           *
        //*****************************

        if (command == "-1player")
            EUROnoOfMatchPlyrs = 1;
        if (command == "-2players")
            EUROnoOfMatchPlyrs = 2;
        if (command == "-3players")
            EUROnoOfMatchPlyrs = 3;
        if (command == "-4players")
            EUROnoOfMatchPlyrs = 4;

        if (EUROgameType == EURO_championship) {
            if (command == "-5players")
                EUROnoOfMatchPlyrs = 5;
            if (command == "-6players")
                EUROnoOfMatchPlyrs = 6;
            if (command == "-7players")
                EUROnoOfMatchPlyrs = 7;
            if (command == "-8players")
                EUROnoOfMatchPlyrs = 8;
            if (command == "-9players")
                EUROnoOfMatchPlyrs = 9;
            if (command == "-10players")
                EUROnoOfMatchPlyrs = 10;
            if (command == "-11players")
                EUROnoOfMatchPlyrs = 11;
            if (command == "-12players")
                EUROnoOfMatchPlyrs = 12;
            if (command == "-13players")
                EUROnoOfMatchPlyrs = 13;
            if (command == "-14players")
                EUROnoOfMatchPlyrs = 14;
            if (command == "-15players")
                EUROnoOfMatchPlyrs = 15;
            if (command == "-16players")
                EUROnoOfMatchPlyrs = 16;
        }

        if (command == "-groups")
            Menu = GROUP_FIXTURES;
        if (command == "-wembley")
            Menu = VENUE_FLYTHRU;
        if (command == "-modem")
            Menu = MODEM_SETUP;
        if (command == "-symbols")
            EUROsymbol = 1;
        if (command == "-v1")
            EUROverbose = 1;
        if (command == "-console")
            EUROconsole = 1;

        if (command == "-commtype0")
            EUROcommOVERIDE = 0;
        if (command == "-commtype1")
            EUROcommOVERIDE = 1;
        if (command == "-commtype2")
            EUROcommOVERIDE = 2;
        if (command == "-commtype3")
            EUROcommOVERIDE = 3;

        if (command == "?") {
            printf("\n\n");
            printf("  -friendly			Defaults to friendly game on execution.\n");
            printf("  -network			Defaults to network game on execution.\n");
            printf("  -wireplay			Defaults to wireplay game on execution.\n");
        }
    }

    setup.verbose = EUROverbose;

    if (EUROverbose != 0) {
        printf("Outputting VERBOSE information.\n");
    }
}
