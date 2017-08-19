#include <cstring>
#include <cstdlib>
#include <cstdio>

#include <euro_def.h>
#include <defines.h>
#include <config.h>
#include <3deng.h>
#include <gamedata.h>
#include <digi.h>

#include "audio.h"

struct {
    int CrowdVolume;
    int PitchVolume;
    int CommentaryVolume;
    int MusicVolume;
    int MasterVolume;
} audio_state;

char SampleLanguage[][2] = {
        "E",    // English
        "F",    // Francais
        "G",    // Deutsch
        "A",    // American
        "C",    // Canadian
        "N",    // Norwegian
        "J",    // Japanese
        "S",    // Spanish
        "P"     // Portuguese
};

// Pitch and Crowd Samples
memsam SampleBank[] = {
        "AMBI2", NULL, NULL, 0,                 // Levels of Crowd Ambience
        "AMBI4", NULL, NULL, 0,
        "AMBI6", NULL, NULL, 0,
        "AMBI8", NULL, NULL, 0,
        "GOAL", NULL, NULL, 0,                  // Crowd Cheers for a goal
        "C_MISS", NULL, NULL, 0,                // Crowd Just Missed (Ooooh)
        "SAVE", NULL, NULL, 0,                  // Great Save (Claps)
        "LAUGH", NULL, NULL, 0,                 // Fluff (Laughs)
        "C_FOWL", NULL, NULL, 0,                // Nasty Fowl
        "RESTLESS", NULL, NULL, 0,              // Crowd Cheers for a goal
        "LNGREF", NULL, NULL, 0,                // Long referee whistle
        "SHRTREF", NULL, NULL, 0,               // Short referee whistle
        "HRDKICK", NULL, NULL, 0,               // Hard Kick
        "KICK1", NULL, NULL, 0,                 // Kick
        "PASS1", NULL, NULL, 0,                 // Kick
        "BOOT", NULL, NULL, 0,                  // Kick
        "BOUNCE", NULL, NULL, 0,                // Bounce
        "FALL", NULL, NULL, 0,                  // Sliding Tackle
        "FULL", NULL, NULL, MSF_DONTKEEP,       // Full time whistle
        "HALF", NULL, NULL, MSF_DONTKEEP,       // Half time whistle
//  "CHANT0",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//  "CHANT1",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//  "CHANT2",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//  "CHANT3",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//  "CHANT4",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//  "CHANT5",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
        NULL, NULL, NULL, 0
};

// Pitch Samples
pitchsam PitchBank[] = {
        &SampleBank[MS_LNGREF], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,    // PS_LONGWHISTLE           Whistles
        &SampleBank[MS_SHRTREF], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,   // PS_SHORTWHISTLE
        &SampleBank[MS_HALF], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,      // PS_HALFTIMEWHISTLE
        &SampleBank[MS_FULL], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,      // PS_FULLTIMEWHISTLE

        &SampleBank[MS_BOOT], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,      // PS_SOFTKICK              Ball Kicks
        &SampleBank[MS_KICK1], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,     // PS_MEDKICK
        &SampleBank[MS_HRDKICK], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,   // PS_HARDKICK

        &SampleBank[MS_BOUNCE], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,    // PS_SOFTHEAD              Headers
        &SampleBank[MS_BOUNCE], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,    // PS_HARDHEAD

        &SampleBank[MS_BOOT], 0x7fff, 0x8000,
        PSF_APPROX | PSF_THREED,      // PS_SOFTCATCH             Handling of the Ball
        &SampleBank[MS_KICK1], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,     // PS_HARDCATCH
        &SampleBank[MS_HRDKICK], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,   // PS_PUNCH

        &SampleBank[MS_BOUNCE], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,    // PS_SOFTBOUNCE            Ball Bounces
        &SampleBank[MS_PASS1], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,     // PS_HARDBOUNCE

        &SampleBank[MS_BOUNCE], 0x7fff, 0x8000,
        PSF_APPROX | PSF_THREED,    // PS_SOFTWOOD              Ball Rebounds off the Woodwork
        &SampleBank[MS_BOOT], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,      // PS_HARDWOOD

        &SampleBank[MS_FALL], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED,      // PS_SLIDING               Sliding Tackle

        &SampleBank[MS_BOUNCE], 0x7fff, 0x8000,
        PSF_APPROX | PSF_THREED,    // PS_SOFTGOAL              Balls Hitting the back of the net
        &SampleBank[MS_BOUNCE], 0x7fff, 0x8000, PSF_APPROX | PSF_THREED     // PS_HARDGOAL
};

// Crowd Samples
pitchsam CrowdBank[] = {
        &SampleBank[MS_AMBI2], 0x3fff, 0x8000, 0,       // CS_AMBIENCE1     Crowd levels
        &SampleBank[MS_AMBI4], 0x3fff, 0x8000, 0,       // CS_AMBIENCE2
        &SampleBank[MS_AMBI6], 0x3fff, 0x8000, 0,       // CS_AMBIENCE3
        &SampleBank[MS_AMBI8], 0x4fff, 0x8000, 0,       // CS_AMBIENCE4
        &SampleBank[MS_GOAL], 0x6fff, 0x8000, 0,        // CS_GOAL          Goals
        &SampleBank[MS_RESTLESS], 0x6fff, 0x8000, 0,    // CS_RESTLESS
        &SampleBank[MS_MISS], 0x4fff, 0x8000, 0,        // CS_MISS          Just Missed
        &SampleBank[MS_SAVE], 0x4fff, 0x8000, 0,        // CS_SAVE          Great Save
        &SampleBank[MS_LAUGH], 0x6800, 0x8000, 0,       // CS_LAUGH         Missed by miles
        &SampleBank[MS_FOWL], 0x6800, 0x8000, 0         // CS_FOWL          Nasty fowl
//	&SampleBank[MS_CHANT0],0x4fff,0x8000,0,		//	CS_CHANT0			Crowd Chants
//	&SampleBank[MS_CHANT1],0x4fff,0x8000,0,		//	CS_CHANT1			Crowd Chants
//	&SampleBank[MS_CHANT2],0x4fff,0x8000,0,		//	CS_CHANT2			Crowd Chants
//	&SampleBank[MS_CHANT3],0x4fff,0x8000,0,		//	CS_CHANT3			Crowd Chants
//	&SampleBank[MS_CHANT4],0x4fff,0x8000,0,		//	CS_CHANT4			Crowd Chants
//	&SampleBank[MS_CHANT5],0x4fff,0x8000,0			//	CS_CHANT5			Crowd Chants
};

teamsam PlayerBank[2];
struct crowdsam CrowdControl[2];
memsam CommentaryBank[MAX_COMMENTARY_CATEGORIES];
memsam FrontEndBank[MAX_FRONTEND_SAMPLES];

struct commcat CommentaryCategories[] = {
        "SPA", MAX_SP_CORNER,           // Set piece
        "SPB", MAX_SP_GOALKICK,
        "SPC", MAX_SP_THROWIN,
        "SPF", MAX_SP_LONGTHROWIN,
        "SPD", MAX_SP_PENALTY,

        "FUA", MAX_FU_FREEKICK,         // Foul
        "FUB", MAX_FU_WALL,
        "FUC", MAX_FU_BADFOUL,
        "FUE", MAX_FU_YELLOWCARD,
        "FUF", MAX_FU_REDCARD,
        "FUG", MAX_FU_INJURY,
        "DIV", MAX_FU_DIVE,

        "CPA", MAX_CP_LONG,             // Completed pass
        "CPB", MAX_CP_SHORT,
        "CPC", MAX_CP_TARGET,
        "CPD", MAX_CP_HEAD,
        "CPE", MAX_CP_NICEMOVE,
        "CPI", MAX_CP_SETPIECE,

        "FPA", MAX_FP_LONG,             // Failed Pass
        "FPB", MAX_FP_SHORT,
        "FPC", MAX_FP_LOOSE,

        "GLA", MAX_GL_GENERIC,          // Goal
        "GLB", MAX_GL_DEFLECT,
        "GLC", MAX_GL_HARDKICK,
        "GLD", MAX_GL_HEADER,
        "GLE", MAX_GL_KEEPER,
        "GLF", MAX_GL_POST,
        "GLG", MAX_GL_CURVE,
        "GLH", MAX_GL_CURVEWALL,

        "PMA", MAX_PM_CATCH,            // Player missed goal attempt
        "PMB", MAX_PM_BLOCK,
        "PMC", MAX_PM_WIDE,
        "PMD", MAX_PM_CLOSE,
        "PME", MAX_PM_POST,
        "PMF", MAX_PM_CROSSBAR
};

struct commcat RepeatBuffer[MAX_REPEAT_BUFFER];        // Store of the last x samples to avoid repeats
struct commcat *RepeatCurrent, *RepeatHigh;

int CommentaryHandle = -1;
int CommentaryMode = 0;
int CommentaryPaused = 0;
int LinkIndex = -1;                            // Number of Samples in this link and index into Link Buffer
memsam *LinkStack[4];                    // Pointers to samples that get linked
memsam LinkBank[MAX_LINKS];            // Temporary store for samples that get linked
intonsam Substitute;                        // Temporary buffer used in substitutions

#ifdef IMPLEMENT_ME
_SOS_START_SAMPLE CrowdSampleData;
#endif

//************************************************************************************************
//
// Checks and maintains the repeat buffer
//
// returns NULL if not found
//
//************************************************************************************************
int CheckRepeatBuffer(char *category, int num) {
    commcat *ptr;

    if (RepeatHigh != &RepeatBuffer[0]) // Check for first entry
    {
        ptr = &RepeatBuffer[0];

        while (ptr < RepeatHigh) {
            if (!strcasecmp(category, ptr->name))
                if (num == ptr->count)
                    return (1); // Found in the repeat buffer
            ptr++;
        }
    }

    strcpy(RepeatCurrent->name, category);
    RepeatCurrent->count = (short) num;
    if (RepeatHigh < &RepeatBuffer[MAX_REPEAT_BUFFER])
        RepeatHigh++;
    RepeatCurrent++;
    if (RepeatCurrent > &RepeatBuffer[MAX_REPEAT_BUFFER - 1])
        RepeatCurrent = &RepeatBuffer[0];

    return (0);
}

//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################
//
// General
//
//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################

static int Seed;

static int InitRandom(int eax) {
    if (!eax)
        Seed = rand();
    else
        Seed = eax;

    return Seed;
}

//************************************************************************************************
//
// Depending On Where It Can Find The InGame Music This Sets Where To Get The Digi
//
//************************************************************************************************
static void BuildSampleDisk(char *where, char *main) {
#ifndef IMPLEMENT_ME
    strcpy(where, main);
#else
    if (bUseHardDiskForSamples)
        strcpy(where, main);
    else {
        if (Language == American || Language == Canadian)
            strcpy(where, "VR Soccer:VR Soccer");
        else
            strcpy(where, "Actua Soccer:Actua Soccer");
        strcat(where, main);
    }
#endif
}

//************************************************************************************************
//
// Initialise the volume levels and random number seed
//
//************************************************************************************************
unsigned int InitMatchAudio(unsigned int seed) {
    RepeatCurrent = RepeatHigh = &RepeatBuffer[0];
    UpdateVolumeLevels();
    return (unsigned int) (InitRandom(seed));
}

//************************************************************************************************
//
// Updates all the volume levels for the various sources
//
//************************************************************************************************
void UpdateVolumeLevels(void) {
    audio_state.CrowdVolume         = match_info.crowd;
    audio_state.PitchVolume         = match_info.pitch;
    audio_state.CommentaryVolume    = match_info.commentary;
    audio_state.MusicVolume         = match_info.music;
    audio_state.MasterVolume        = match_info.master;

    SetDIGIVolume(audio_state.MasterVolume, audio_state.MusicVolume);
}

//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################
//
// Music for Front End
//
//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################

#ifdef IMPLEMENT_ME // ???? Mac specific crap???
//************************************************************************************************
//
// Completion For Musci Routine
//
//************************************************************************************************
RoutineDescriptor ExternalSndFilePlayRD = BUILD_ROUTINE_DESCRIPTOR(uppFilePlayCompletionProcInfo, MusicCompletion);

pascal void MusicCompletion( SndChannelPtr sndChannel)
{
    bMusicPlaying = false;
    MusicState = false;
}
#endif

//************************************************************************************************
//
// Start a tune call "Football Music"
//
// Returns the Sample handle or -1 if not started
//
//************************************************************************************************
int StartMusic(const char *name, int volume) {
#ifdef IMPLEMENT_ME
    FSSpec	spec;
    OSErr	err;

        if(SoundCard)
            {
            err = BuildFSSpec( "\p:DIGI:Football Music", &spec);
            if( err ==noErr)
                {
                err = FSpOpenDF( &spec, fsRdPerm, &fMusicRefNum);
                if( err == noErr)
                    {
                    err = SndStartFilePlay( externalChannel[MUSICCHANNEL], fMusicRefNum, 0, 2*40960, nil, nil, &ExternalSndFilePlayRD, true);
                    if( err == noErr)
                        {
                        bMusicPlaying = true;
                        MusicState = true;
                        }
                    }
                }
            }

        return( err);
#else
    return -1;
#endif
}

//************************************************************************************************
//
// Stop the Music previously Started with StartMusic
//
//************************************************************************************************
void StopMusic(void) {
#ifdef IMPLEMENT_ME
    OSErr	err;

        if(SoundCard)
            {
            err = SndStopFilePlay( externalChannel[MUSICCHANNEL], true);
            err = FSClose( fMusicRefNum);
            }
        MusicState = false;
#endif
}

//************************************************************************************************
//
// Called periodically to keep the music playing
//
// Returns the amount of Sample left to play or -1
//
//************************************************************************************************
void UpdateMusic(void) {
#ifdef IMPLEMENT_ME
    if (MusicState == false && match_info.audio && SuspendAudio == false) {
        StopMusic();
        StartMusic("FINAL", 0);
    } else if ((MusicState != NULL && !match_info.audio) || SuspendAudio)
        StopMusic();
#endif
}

static unsigned int Random(unsigned int Range) {
    unsigned int ebx = (unsigned int) (Seed + Seed);
    if (!(Seed & 0x7fffffff))
        ebx += 0x01d872b45;

    Seed = ebx;
    return Seed % Range;
}

//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################
//
// Pitch
//
//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################

//************************************************************************************************
//
// Load as many samples pitch samples that will fit in memory
//
//************************************************************************************************
unsigned int LoadPitchSamples(void) {
    struct memstatus PitchMemory = {0};
#ifdef IMPLEMENT_ME
    if (SoundCard && (PitchVolume || CrowdVolume)) {
        memsam *bank = &SampleBank[0];
        while (bank->name) {
            char filename[16], madname[64];
            CreatePitchFileName(bank->name, &madname[0], &filename[0]);
            LoadSample(madname, filename, bank, &PitchMemory);
            bank++;
        }
    }
#endif
    return (unsigned int) (PitchMemory.fail);
}

