/* Copyright (C) 1997 Gremlin Interactive Ltd.
 * With modifications by Mark E Sowden
 */

#include "g_shared.h"

#include <SDL2/SDL_mixer.h>

#include "config.h"
#include "defines.h"

bool SoundCard = false; // SOS ID of Sound Card

//************************************************************************************************
//
// Sets up the Digital Sound hardware.
//	Reads the setup from the config file
//
//	Returns 0 if okay, otherwise failed.
//
//************************************************************************************************
int InitialiseDIGI(int freq,int flags) {
    if(Mix_OpenAudio(freq, AUDIO_S16, 2, 1024) == 0) {
        Mix_AllocateChannels(32);

        SoundCard = true;
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

//************************************************************************************************
//
// Uninitialise Digital Sound Hardware
//
//************************************************************************************************
int UnInitialiseDIGI(void) {
    if(SoundCard) {
        Mix_HaltChannel(-1);
        Mix_CloseAudio();

        SoundCard = false;
    }
    return(EXIT_SUCCESS);
}

//************************************************************************************************
//
// Play a sample from memory
//
//	*sample	Pointer to the sample.
//
//	Returns 	Channel Number or -1 for an error (0 is a valid handle)
//
//************************************************************************************************
int StartSample(void *mem, int length, short amp, short pan, int freq) {
    if(SoundCard && mem) {
        Mix_Chunk chunk = {
                FALSE,
                static_cast<Uint8 *>(mem),          //set pointer to start of sample
                static_cast<Uint32>(length - 1),    //set sample length (-1 to stop click)
                static_cast<Uint8>(amp)             //set volume
        };
        // todo, set sample pitch shift
        return Mix_PlayChannel(-1, &chunk, 0); //start sample
        //Mix_SetPanning(channel, 255, 255); //todo, set pan location
    }
    return(-1);
}

//************************************************************************************************
//
// Stop a sample playing from memory
//
//	slot	The Sample Slot
//
//************************************************************************************************
void StopSample(int handle) {
    if(SoundCard && (handle!=-1)) {
        Mix_HaltChannel(handle);
    }
}

//************************************************************************************************
//
// Check if a sample has finished playing
//
//	slot		The Sample Slot
//
// returns	0 if finished, otherwise still going.
//
//************************************************************************************************
short CheckSample(int handle) {
    return static_cast<short>(Mix_Playing(handle));
}

//************************************************************************************************
//
// Set up the digital volume levels
//
//************************************************************************************************
void SetDIGIVolume(int Master, int HardDisk) {
    if(SoundCard) {
        // todo, tweak so this is calculated correctly!
        Mix_Volume(-1, Master / MIX_MAX_VOLUME);
    }
}