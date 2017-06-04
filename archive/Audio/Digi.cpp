#include "Frontend Vars.h"
#include "Digi.h"

#undef EXTERN
#define EXTERN extern
#include "Audio.h"
#include "Digi.h"
#include "Front Variables.h"
#include "Mallocx.h"
#include "Not Written Yet.h"
#include "Play.h"
#include "Sos.h"
#include "Wave.h"

//WORD DIGIDriverHandle;					// Handle of driver for playing samples
//WORD DIGITimerHandle;					// Handle of timer

//void(* FinishedCallback)(void);
//short int HardActive;
//short int HardPending;
//short int HardPaused;
//short int HardFinished;
//int HardDiskSampleRemaining;	// Length of Current Hard Disk Sample left to play
//FILE *HardFilePointer;					// File pointer of Current Hard Disk Sample

//int HardDiskHandle;				// Store for Hard Disk Sample handle

//unsigned char *HardDiskSampleBuffer[2];

static long startVolume;

_SOS_START_SAMPLE MemSampleData;

//************************************************************************************************
//
// Sets up the Digital Sound hardware.
//	Reads the setup from the config file 
//
//	Returns 0 if okay, otherwise failed.
//
//************************************************************************************************
int InitialiseDIGI(int freq,int flags)
{
NumVersion theVersion;
void *trap1;
void *trap2;

	trap1 = (void *)GetToolTrapAddress( _SoundDispatch);
	trap2 = (void *)GetToolTrapAddress( _Unimplemented);
	if( trap1 != trap2)
		{
		theVersion = SndSoundManagerVersion();
		if( theVersion.majorRev >= 3)
			{
			if( !flags)
				{
				GetDefaultOutputVolume( & startVolume);
				PLAYER_InitSound();
				SoundCard = true;
				}
			return EXIT_SUCCESS;
			}
		}
	SoundCard = false;
	return EXIT_FAILURE;
}

//************************************************************************************************
//
// Uninitialise Digital Sound Hardware
//
//************************************************************************************************
int UnInitialiseDIGI(void)
{
	if(SoundCard)
		{
		PLAYER_KillSound();
		SetDefaultOutputVolume( startVolume);
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
int StartSample(void *mem, int length, short amp, short pan, int freq)
{
	if(SoundCard && mem)
		{
		MemSampleData.lpSamplePtr=(unsigned char *)mem;		//set pointer to start of sample
		MemSampleData.wSampleID=1;									//set sample I.D.
		MemSampleData.dwSampleSize=length-1; 					//set sample length (-1 to stop click)
		MemSampleData.dwSamplePitchAdd=freq;					//set sample pitch shift
		MemSampleData.wVolume=amp;									//set volume
		MemSampleData.wSamplePanLocation=pan;					//set pan location
		MemSampleData.bLoop = false;
//		MemSampleData.wLoopCount=-1;								//set loop count
		return(sosDIGIStartSample(DIGIDriverHandle,&MemSampleData));	//start sample
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
void StopSample(int handle)
{
	if(SoundCard&&(handle!=-1))
	  {
	  sosDIGIStopSample( DIGIDriverHandle, handle);
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
short CheckSample(int handle)
{
	return sosDIGISampleDone( DIGIDriverHandle, handle);
}

//************************************************************************************************
//
// Check if a the hard disk sample has finished playing
//
//	slot		The Sample Slot
//
// returns	0 if finished, otherwise still going.
//
//************************************************************************************************
short CheckHardDiskSample(void)
{
		return(0);
}


//************************************************************************************************
//
// Returns the current amount of sample processed since the start
//
//************************************************************************************************
unsigned int GetSamplePosition(int handle)
{
	if(SoundCard&&(handle!=-1))
		{
		}

	return(0);
}

#if 0
//************************************************************************************************
//
// Start a hard disk sample playing, Reads the first
// part of the sample in and starts it playing
//
//	*fp		File Pointer of file with sample in.
// offset	Offset into file of start of sample.
//	length	Length of the sample to be played.
//
//	Only one hard disk sample can be played at once.
//
//************************************************************************************************
void InitHardDiskSample(FILE *fp,int offset,int length,int rate,int volume,int flags,void (callback)(void))
{
	int toread;

	if(SoundCard)
		{
/*
		HardFilePointer=fp;
		HardDiskSampleRemaining=length;
		HardActive=0;
		HardPaused=0;
		HardPending=1;
		HardFinished=0;

		FinishedCallback=callback;
		HardDiskSampleData.wSampleFlags|=flags;				// Set appropriate flags

		if(flags&HSF_STEREO)
			HardDiskSampleData.wChannel|=_INTERLEAVED;
		else
			HardDiskSampleData.wChannel|=_CENTER_CHANNEL;

		if(rate!=0x10000)
			{
			HardDiskSampleData.wSampleFlags|=_PITCH_SHIFT;
			HardDiskSampleData.dwSamplePitchAdd=rate;
			}

		HardDiskSampleData.wVolume=volume;

		if(HardDiskSampleRemaining<SoundHardDiskBuffer)
			toread=HardDiskSampleRemaining;
		else
			toread=SoundHardDiskBuffer;

		fseek(fp,offset,SEEK_SET);									// Find start of sample
		HardDiskSampleData.dwSampleSize=fread(HardDiskSampleBuffer[HardActive],1,toread,fp);					// Get first part of sample
		HardDiskSampleRemaining-=HardDiskSampleData.dwSampleSize;
//		printf("Read %d Remain %ld Active %d\n",HardDiskSampleData.dwSampleSize,HardDiskSampleRemaining,HardActive);
		HardDiskSampleData.lpSamplePtr=(LPSTR)HardDiskSampleBuffer[HardActive];
//		HardDiskHandle=sosDIGIStartSample(DIGIDriverHandle,&HardDiskSampleData);			// Start the sample playing
*/
		}
}

//************************************************************************************************
//
// Called now and again by the SOS to keep Hard Disk Sample playing
//
//************************************************************************************************
int ContinueHardDiskSample()
{
	int toread;

	if(!SoundCard)
		return(0);
/*
	if(HardPending)									// Only read data if needed
		{
		HardPending=0;
		HardActive^=1;									// Swap the sample buffer

		if(HardDiskSampleRemaining<SoundHardDiskBuffer)
			toread=HardDiskSampleRemaining;
		else
			toread=SoundHardDiskBuffer;

		HardDiskSampleData.dwSampleSize=fread(HardDiskSampleBuffer[HardActive],1,toread,HardFilePointer);
		HardDiskSampleRemaining-=HardDiskSampleData.dwSampleSize;
		if(HardDiskSampleData.dwSampleSize<SoundHardDiskBuffer)
			HardDiskSampleRemaining=0;

		if(HardPaused)
			{
			sosDIGIContinueSample(DIGIDriverHandle,HardDiskHandle,&HardDiskSampleData);
			HardPaused=0;
			}
		}

	return(HardDiskSampleRemaining);
*/
	return 0;
}


//************************************************************************************************
//
// Called now and again by the SOS to keep Hard Disk Sample playing
//
//************************************************************************************************
void HardDiskSampleCallBack(WORD wDriverHandle,WORD wAction,WORD wSampleHandle)
{
/*
	switch(wAction)
		{
		case _SAMPLE_PROCESSED:		// Sample is loaded into DMA Buffer, so fetch some more
			if(!HardPending)
				{
				HardDiskSampleData.lpSamplePtr=(LPSTR)HardDiskSampleBuffer[HardActive];
				sosDIGIContinueSample(DIGIDriverHandle,HardDiskHandle,&HardDiskSampleData);
//				sosDIGIContinueSample(wDriverHandle,wSampleHandle,&HardDiskSampleData);
				HardPending=1;
				}
			break;

		case _SAMPLE_DONE:
			if(HardDiskSampleRemaining)
				{
				HardPaused=1;
//				HardPending^1;
				}
			else
				{
//				sosDIGIStopSample(wDriverHandle,wSampleHandle);
				HardFinished=1;
				if(FinishedCallback)
					FinishedCallback();
				}
			break;

		default:
			break;
		}
*/
}

//************************************************************************************************
// Default Finished callback
//************************************************************************************************
static void DefaultCallback()
{
}
#endif

//************************************************************************************************
//
// Set up the digital volume levels
//
//************************************************************************************************
void SetDIGIVolume(short int Master,short int HardDisk)
{
	if(SoundCard)
		{
//		sosDIGISetSampleVolume(DIGIDriverHandle,HardDiskHandle,HardDisk);
		sosDIGISetMasterVolume(DIGIDriverHandle,Master);
	 	}
}
