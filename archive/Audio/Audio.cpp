#include "Frontend Vars.h"
#include "Audio.h"

#undef EXTERN
#define EXTERN extern
#include "Digi.h"
#include "FileUtils.h"
#include "Front Variables.h"
#include "Mallocx.h"
#include "Not Written Yet.h"
#include "Play.h"
#include "Sos.h"
#include "The Frontend.h"
#include "Wave.h"

int CrowdVolume;
int PitchVolume;
int CommentaryVolume;
int MusicVolume;
int MasterVolume;

//struct memstatus TotalMemStatus={0};	// Accumulation of all memory allocations
char SampleLanguage[][2]= { 
						  "E", 			// English
						  "F",			// Francais
						  "G",			// Deutsch
						  "A",			// American
						  "C",			// Canadian
						  "N",			// Norwegian
						  "J",			// Japanese
						  "S",			// Spanish
						  "P"			// Portuguese
						  };

memsam SampleBank[]=							// Pitch and Crowd Samples
	{
	"AMBI2",NULL,NULL,0,						// Levels of Crowd Ambience
	"AMBI4",NULL,NULL,0,
	"AMBI6",NULL,NULL,0,
	"AMBI8",NULL,NULL,0,
	"GOAL",NULL,NULL,0,						// Crowd Cheers for a goal
	"C_MISS",NULL,NULL,0,					// Crowd Just Missed (Ooooh)
	"SAVE",NULL,NULL,0,						// Great Save (Claps)
	"LAUGH",NULL,NULL,0,						// Fluff (Laughs)
	"C_FOWL",NULL,NULL,0,					// Nasty Fowl
	"RESTLESS",NULL,NULL,0,					// Crowd Cheers for a goal
	"LNGREF",NULL,NULL,0,					// Long referee whistle
	"SHRTREF",NULL,NULL,0,					// Short referee whistle
	"HRDKICK",NULL,NULL,0,					// Hard Kick
	"KICK1",NULL,NULL,0,						// Kick
	"PASS1",NULL,NULL,0,						// Kick
	"BOOT",NULL,NULL,0,						// Kick
	"BOUNCE",NULL,NULL,0,					// Bounce
	"FALL",NULL,NULL,0,						// Sliding Tackle
	"FULL",NULL,NULL,MSF_DONTKEEP,		// Full time whistle
	"HALF",NULL,NULL,MSF_DONTKEEP,		// Half time whistle
//	"CHANT0",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//	"CHANT1",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//	"CHANT2",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//	"CHANT3",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//	"CHANT4",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
//	"CHANT5",NULL,NULL,0,MSF_DONTKEEP,	// Random Chant for Variety
	NULL,NULL,NULL,0
	};

pitchsam PitchBank[]=				// Pitch Samples
	{
	&SampleBank[MS_LNGREF],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		// PS_LONGWHISTLE			Whistles
	&SampleBank[MS_SHRTREF],0x7fff,0x8000,PSF_APPROX|PSF_THREED,	//	PS_SHORTWHISTLE
	&SampleBank[MS_HALF],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_HALFTIMEWHISTLE
	&SampleBank[MS_FULL],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_FULLTIMEWHISTLE

	&SampleBank[MS_BOOT],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		// PS_SOFTKICK				Ball Kicks
	&SampleBank[MS_KICK1],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_MEDKICK
	&SampleBank[MS_HRDKICK],0x7fff,0x8000,PSF_APPROX|PSF_THREED,	//	PS_HARDKICK

	&SampleBank[MS_BOUNCE],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		// PS_SOFTHEAD				Headers
	&SampleBank[MS_BOUNCE],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_HARDHEAD

	&SampleBank[MS_BOOT],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		// PS_SOFTCATCH			Handling of the Ball
	&SampleBank[MS_KICK1],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_HARDCATCH
	&SampleBank[MS_HRDKICK],0x7fff,0x8000,PSF_APPROX|PSF_THREED,	//	PS_PUNCH

	&SampleBank[MS_BOUNCE],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_SOFTBOUNCE			Ball Bounces
	&SampleBank[MS_PASS1],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_HARDBOUNCE

	&SampleBank[MS_BOUNCE],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_SOFTWOOD				Ball Rebounds off the Woodwork
	&SampleBank[MS_BOOT],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_HARDWOOD

	&SampleBank[MS_FALL],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_SLIDING				Sliding Tackle

	&SampleBank[MS_BOUNCE],0x7fff,0x8000,PSF_APPROX|PSF_THREED,		//	PS_SOFTGOAL				Balls Hitting the back of the net
	&SampleBank[MS_BOUNCE],0x7fff,0x8000,PSF_APPROX|PSF_THREED		//	PS_HARDGOAL
	};

pitchsam CrowdBank[]=									// Crowd Samples
	{
	&SampleBank[MS_AMBI2],0x3fff,0x8000,0,			// CS_AMBIENCE1		Crowd levels
	&SampleBank[MS_AMBI4],0x3fff,0x8000,0,			// CS_AMBIENCE2
	&SampleBank[MS_AMBI6],0x3fff,0x8000,0,			// CS_AMBIENCE3
	&SampleBank[MS_AMBI8],0x4fff,0x8000,0,			// CS_AMBIENCE4
	&SampleBank[MS_GOAL],0x6fff,0x8000,0,			//	CS_GOAL				Goals
	&SampleBank[MS_RESTLESS],0x6fff,0x8000,0,		//	CS_RESTLESS
	&SampleBank[MS_MISS],0x4fff,0x8000,0,			//	CS_MISS				Just Missed
	&SampleBank[MS_SAVE],0x4fff,0x8000,0,			//	CS_SAVE				Great Save
	&SampleBank[MS_LAUGH],0x6800,0x8000,0,			//	CS_LAUGH				Missed by miles
	&SampleBank[MS_FOWL],0x6800,0x8000,0			//	CS_FOWL				Nasty fowl
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

struct commcat CommentaryCategories[]=
	{
	"SPA",MAX_SP_CORNER,					// Set piece
	"SPB",MAX_SP_GOALKICK,
	"SPC",MAX_SP_THROWIN,
	"SPF",MAX_SP_LONGTHROWIN,
	"SPD",MAX_SP_PENALTY,

	"FUA",MAX_FU_FREEKICK,				// Foul
	"FUB",MAX_FU_WALL,
	"FUC",MAX_FU_BADFOUL,
	"FUE",MAX_FU_YELLOWCARD,
	"FUF",MAX_FU_REDCARD,
	"FUG",MAX_FU_INJURY,
	"DIV",MAX_FU_DIVE,

	"CPA",MAX_CP_LONG,					// Completed pass
	"CPB",MAX_CP_SHORT,
	"CPC",MAX_CP_TARGET,
	"CPD",MAX_CP_HEAD,
	"CPE",MAX_CP_NICEMOVE,
	"CPI",MAX_CP_SETPIECE,

	"FPA",MAX_FP_LONG,					// Failed Pass
	"FPB",MAX_FP_SHORT,
	"FPC",MAX_FP_LOOSE,

	"GLA",MAX_GL_GENERIC,				// Goal
	"GLB",MAX_GL_DEFLECT,
	"GLC",MAX_GL_HARDKICK,
	"GLD",MAX_GL_HEADER,
	"GLE",MAX_GL_KEEPER,
	"GLF",MAX_GL_POST,
	"GLG",MAX_GL_CURVE,
	"GLH",MAX_GL_CURVEWALL,

	"PMA",MAX_PM_CATCH,					// Player missed goal attempt
	"PMB",MAX_PM_BLOCK,
	"PMC",MAX_PM_WIDE,
	"PMD",MAX_PM_CLOSE,
	"PME",MAX_PM_POST,
	"PMF",MAX_PM_CROSSBAR
	};

struct commcat RepeatBuffer[MAX_REPEAT_BUFFER];		// Store of the last x samples to avoid repeats
struct commcat *RepeatCurrent,*RepeatHigh;

int CommentaryHandle=-1;
int CommentaryMode=0;
int CommentaryPaused=0;
int LinkIndex=-1;							// Number of Samples in this link and index into Link Buffer
memsam *LinkStack[4];					// Pointers to samples that get linked
memsam LinkBank[MAX_LINKS];			// Temporary store for samples that get linked
intonsam Substitute;						// Temporary buffer used in substitutions

_SOS_START_SAMPLE CrowdSampleData;

/*
_SOS_START_SAMPLE CrowdSampleData=
	{
	_NULL, 0L, -1, _CENTER_CHANNEL, 0,
	0xC1, 0L, 0,_TRANSLATE8TO16|_PITCH_SHIFT|_VOLUME|_PANNING|_LOOPING,
	0L, 0L, 0L, 0L, 0, 0, 0, 0, 0, 0, 0,
	0, 0L, 0, 0, 0L, 0L, 0L
	};
*/

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

static int InitRandom(int eax)
{
	if(!eax)
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
static void BuildSampleDisk( char *where, char *main)
{
	if( bUseHardDiskForSamples)
		strcpy( where,main);
	else
		{
		if( Language == American || Language == Canadian)
			strcpy( where, "VR Soccer:VR Soccer");
		else
			strcpy( where, "Actua Soccer:Actua Soccer");
		strcat( where, main);
		}
}

//************************************************************************************************
//
// Initialise the volume levels and random number seed
//
//************************************************************************************************
unsigned int InitMatchAudio(unsigned int seed)
{
	RepeatCurrent=RepeatHigh=&RepeatBuffer[0];
	UpdateVolumeLevels();
	return(InitRandom(seed));
}

//************************************************************************************************
//
// Updates all the volume levels for the various sources
//
//************************************************************************************************
void UpdateVolumeLevels(void)
{
	CrowdVolume=match_info.crowd;
	PitchVolume=match_info.pitch;
	CommentaryVolume=match_info.commentary;
	MusicVolume=match_info.music;
	MasterVolume=match_info.master;

	SetDIGIVolume(MasterVolume,MusicVolume);
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

//************************************************************************************************
//
// Start a tune call "Football Music"
//
// Returns the Sample handle or -1 if not started
//
//************************************************************************************************
int StartMusic( char *name, int volume)
{
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
}

//************************************************************************************************
//
// Stop the Music previously Started with StartMusic
//
//************************************************************************************************
void StopMusic(void)
{
OSErr	err;

	if(SoundCard)
		{
		err = SndStopFilePlay( externalChannel[MUSICCHANNEL], true);
		err = FSClose( fMusicRefNum);
		}
	MusicState = false;
}

//************************************************************************************************
//
// Check to see if the Music is still Playing
//
// Returns 0 if Finished otherwise still playing
//
//************************************************************************************************
int CheckMusic(void)
{
	return bMusicPlaying;
}

//************************************************************************************************
//
// Called periodically to keep the music playing
//
// Returns the amount of Sample left to play or -1
//
//************************************************************************************************
int UpdateMusic(void)
{
	if (MusicState==false && match_info.audio && SuspendAudio==false)
		{
		StopMusic();
		StartMusic("FINAL",0);
		}
	else if ((MusicState!=NULL && !match_info.audio) || SuspendAudio)
		StopMusic();

	return false;
}

static unsigned int Random(unsigned int Range)
{
unsigned int ebx = (Seed + Seed);

		if(!(Seed&0x7fffffff))
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
unsigned int LoadPitchSamples(void)
{
memsam *bank;
char madname[64];
char filename[16];
	struct memstatus PitchMemory={0};

	if(SoundCard&&(PitchVolume||CrowdVolume))
		{
		bank=&SampleBank[0];
		while(bank->name)
			{
			CreatePitchFileName(bank->name,&madname[0],&filename[0]);
			LoadSample(madname,filename,bank,&PitchMemory);
			bank++;
			}
		}
	return(PitchMemory.fail);
}

//************************************************************************************************
//
// Load int all the samples for the front end
//
//************************************************************************************************
unsigned int LoadFrontEndSamples(void)
{
	memsam *bank;
	char madname[64];
	char filename[16];
	struct memstatus FrontEndMemory={0};

	if(SoundCard)
		{
		bank=&FrontEndBank[0];
		CreatePitchFileName("GOAL",&madname[0],&filename[0]);
		LoadSample(madname,filename,bank,&FrontEndMemory);
		bank++;
		CreatePitchFileName("LNGREF",&madname[0],&filename[0]);
		LoadSample(madname,filename,bank,&FrontEndMemory);
		bank++;
		CreateFrontEndFileName("TIM","TIM05",&madname[0],&filename[0]);
		LoadSample(madname,filename,bank,&FrontEndMemory);
		bank++;
		CreateFrontEndFileName("SPE","CHEAT2",&madname[0],&filename[0]);
		LoadSample(madname,filename,bank,&FrontEndMemory);
		}

	return(FrontEndMemory.fail);
}

//************************************************************************************************
//
// Free memory previously allocated with LoadFrontEndSamples
//
//************************************************************************************************
void FreeFrontEndSamples(void)
{
	memsam *bank;
	int i;

	if(SoundCard)
		{
		bank=&FrontEndBank[0];

		for(i=MAX_FRONTEND_SAMPLES-1;i>=0;i--)
			FreeSample(&bank[i]);
		}
}

//************************************************************************************************
//
// Free memory previously allocated with LoadPitchSamples
//
//************************************************************************************************
void FreePitchSamples(void)
{
	memsam *bank;
	int i;

	if(SoundCard)
		{
		bank=&SampleBank[0];

		for(i=MAX_PITCH_SAMPLES-1;i>=0;i--)
			FreeSample(&bank[i]);
		}
}

//************************************************************************************************
//
//	Plays a sample from the SampleBank
//
// Returns the sample handle of -1
//
//************************************************************************************************
int PlayPitchSample(int sam,short int amp,short int pan)
{
	pitchsam *bank;
	int freq;

	bank=&PitchBank[sam-1];												// Ignore the NULL sample

	if(bank->info->mem==NULL)
		{
		return(-1);				// Might want to load it here
		}

	if(bank->flags&PSF_APPROX)
		freq=bank->freq+((Random(0x400))-0x200);
	else
		freq=bank->freq;

	if(bank->flags&PSF_THREED)
		amp=(amp*bank->amp)/0x7fff;										// Scale volume appropriately
	else
		{
		amp=bank->amp;			// Full Volume
		pan=0x8000;				// Centre Channel
		}

	amp=(amp*PitchVolume)/0x7fff;

	return(StartSample(bank->info->mem,bank->info->size,amp,pan,freq));		// Start the sample
}

//************************************************************************************************
//
//	Plays a sample from the SampleBank
//
// Returns the sample handle of -1
//
//************************************************************************************************
int PlayFrontEndSample(int sam,int amp)
{
	memsam *bank;

	bank=&FrontEndBank[sam];												// Ignore the NULL sample

	if(bank->mem==NULL)
		{
		return(-1);				// Might want to load it here
		}

	amp=(amp*MasterVolume)/0x7fff;

	return(StartSample(bank->mem,bank->size,amp,0x8000,0x8000));		// Start the sample
}

//################################################################################################
//################################################################################################
//
// Crowd
//
//################################################################################################
//################################################################################################

//************************************************************************************************
//
// Starts the Crowd Ambience, given the size of the home and away crowds in people
//
//************************************************************************************************
void StartCrowd(int team)
{
	struct crowdsam *Crowd;
	pitchsam *bank;

	if(SoundCard)
		{
		bank=&CrowdBank[CS_AMBIENCE1-1];													// Ignore the NULL sample

		if(bank->info->mem==NULL)
			{
			return;				// Might want to load it here
			}

		CrowdSampleData.lpSamplePtr=bank->info->mem;				// Set pointer to start of sample
		CrowdSampleData.dwSampleSize=bank->info->size-1; 			// Set sample length
		CrowdSampleData.dwSamplePitchAdd=bank->freq;				// Set sample pitch shift
		CrowdSampleData.wSamplePanLocation=0x8000;					// Set pan location
		CrowdSampleData.wVolume=(bank->amp*CrowdVolume)/0x7fff;		// Set volume
		CrowdSampleData.bLoop = true;
//		CrowdSampleData.dwSampleLoopPoint=0;						// Set loop start
//		CrowdSampleData.dwSampleLoopLength=bank->info->size-1;		// Set loop length

		Crowd=&CrowdControl[team];

		Crowd->mainhandle = sosDIGIStartSample(DIGIDriverHandle,&CrowdSampleData);	// Start sample
		Crowd->mood=CS_AMBIENCE1;
		Crowd->tranmood=CS_AMBIENCE1;
		Crowd->mainvol=(bank->amp*CrowdVolume)/0x7fff;
		Crowd->volmax=(bank->amp*CrowdVolume)/0x7fff;
		Crowd->pan=0x8000;
		Crowd->flags=0;
		}
}

//************************************************************************************************
//
// Starts the Crowd Ambience, given the size of the home and away crowds in people
//
//************************************************************************************************
static void StartCrowdMerge(struct crowdsam *Crowd,int sam)
{
	pitchsam *bank;
	int time;

	if(SoundCard && !(Crowd->flags&CF_TRAN))
		{
		bank=&CrowdBank[sam-1];											// Ignore the NULL sample

		if(bank->info->mem==NULL)
			{
			return;				// Might want to load it here
			}

		CrowdSampleData.lpSamplePtr=bank->info->mem;						// Set pointer to start of sample
		CrowdSampleData.dwSampleSize=bank->info->size-1; 				// Set sample length
		CrowdSampleData.dwSamplePitchAdd=bank->freq;						// Set sample pitch shift
		CrowdSampleData.wSamplePanLocation=Crowd->pan;					// Set pan location
		CrowdSampleData.bLoop = true;
//		CrowdSampleData.dwSampleLoopPoint=0;								// Set loop start
//		CrowdSampleData.dwSampleLoopLength=bank->info->size-1;		// Set loop length
//		CrowdSampleData.wVolume=0;												// Set volume

		Crowd->mergehandle = sosDIGIStartSample(DIGIDriverHandle,&CrowdSampleData);	// Start sample
//		Crowd->mergehandle = PLAYER_PlayExternalSound ( MallocGetHandle( bank->info->mem), bank->freq);

		if(Crowd->tranmood>Crowd->mood)
			time=0x40;
		else
			time=0x20;

		Crowd->maindelta=Crowd->volmax/time;
		Crowd->volmax=(bank->amp*CrowdVolume)/0x7fff;
		Crowd->mergevol=0x0;
		Crowd->mergedelta=Crowd->volmax/time;
		Crowd->flags|=CF_TRAN;
		}
}

//************************************************************************************************
//
// Stops calls to play any commentary samples doing anything
//
//************************************************************************************************
void PauseCommentary(void)
{
	CommentaryPaused=1;
}

//************************************************************************************************
//
// Stops calls to play any commentary samples doing anything
//
//************************************************************************************************
void ResumeCommentary(void)
{
	CommentaryPaused=0;
}

//************************************************************************************************
//
// Stops all the audio currently playing
//
//************************************************************************************************
void StopAudio(void)
{
	int i;

	if(SoundCard)
		{
		sosDIGISetMasterVolume(DIGIDriverHandle,0);					// Turn down volume first
		for(i=0;i<MAXIMUM_CHANNELS;i++)
			sosDIGIStopSample(DIGIDriverHandle,i);
		sosDIGISetMasterVolume(DIGIDriverHandle,MasterVolume);	// Restore Volume
		CommentaryHandle=-1;
		CommentaryMode=0;
		LinkIndex=-1;
		CommentaryPaused=0;
		}

}

//************************************************************************************************
//
//	Plays an event keyed or random keyed crowd sample from the SampleBank
//
// Returns the sample handle of -1
//
//************************************************************************************************
static int PlayCrowdSample(struct crowdsam *Crowd,int sam)
{
	pitchsam *bank;

	bank=&CrowdBank[sam-1];												// Ignore the NULL sample

	if(bank->info->mem==NULL)
		{
		return(-1);				// Might want to load it here
		}

	return(StartSample(bank->info->mem,bank->info->size,(bank->amp*CrowdVolume)/0x7fff,Crowd->pan,bank->freq));		// Start the sample
}

//************************************************************************************************
//
// Updates the crowd periodically.
//
//************************************************************************************************
void UpdateCrowd(int mood,int team)
{
	struct crowdsam *Crowd;
//	unsigned int r;

	Crowd=&CrowdControl[team];
	Crowd->mood=mood;

	if(Crowd->ticks++==Crowd->nextevent)
		{
		Crowd->nextevent=0x0;
		Crowd->ticks=0;

//		printf("Home %d Away %d ",Crowd->nextevent,home,away);
//		printf("ReqMood %d CurMood %d TranMood %d ",mood,Crowd->mood,Crowd->tranmood);
//		printf("Pan %4x Delta %4x ",Crowd->pan,Crowd->pandelta);
//		printf("Vol %4x Merge %4x ",Crowd->mainvol,Crowd->mergevol);
//		printf("Flags %d\n",Crowd->flags);

// Random Triggers

//		if((r=Random())==0xf)						// Handle Triggers Here
//			{
//			if(r>0xc)
//				PlayCrowdSample(Crowd,CS_CHANT1);
//			if(r>0xa)
//				PlayCrowdSample(Crowd,CS_RESTLESS);
//			}
//		}

// Mood Triggers
	if(Crowd->mood!=Crowd->tranmood)
		{
		switch(mood)
			{
			case CN_OFF:							// Start Transition to Crowd Off
//				StopCrowd(team);
				break;

			case CN_NORMAL:						// Start Transition to Crowd Normal
				StartCrowdMerge(Crowd,CS_AMBIENCE1);
				break;

			case CN_PENSIVE:						// Start Transition to Crowd Pensive
				StartCrowdMerge(Crowd,CS_AMBIENCE2);
				break;

			case CN_ENCOURAGING:					// Start Transition to Crowd Encouraging
				StartCrowdMerge(Crowd,CS_AMBIENCE3);
				break;

			case CN_EXCITED:						// Start Transition to Crowd Exited
				StartCrowdMerge(Crowd,CS_AMBIENCE4);
				break;

			case CN_CELEBRATE:					// Celebration Event
				StartCrowdMerge(Crowd,CS_AMBIENCE4);
				PlayCrowdSample(Crowd,CS_GOAL);
				break;

			case CN_BOO:							// Booing
				StartCrowdMerge(Crowd,CS_RESTLESS);
//				if(!(Crowd->flags&CF_PAN))
//					{
//					Crowd->pan=0x8000;
//					Crowd->pandelta=0x400;		// Variable Pan Rate
//					Crowd->flags|=CF_PAN;
//					}
				break;

			case CN_SAVE:							// Good Save
				StartCrowdMerge(Crowd,CS_AMBIENCE4);
				PlayCrowdSample(Crowd,CS_SAVE);
				break;

			case CN_MISS:							// Good strike but missed
				StartCrowdMerge(Crowd,CS_AMBIENCE4);
				PlayCrowdSample(Crowd,CS_MISS);
				break;

			case CN_LAUGH:							// Good strike but missed
				StartCrowdMerge(Crowd,CS_AMBIENCE4);
				PlayCrowdSample(Crowd,CS_LAUGH);
				break;

			case CN_FOWL:							// Good strike but missed
				StartCrowdMerge(Crowd,CS_AMBIENCE4);
				PlayCrowdSample(Crowd,CS_FOWL);
				break;

			default:
				break;
			}
		Crowd->tranmood=mood;
		}
	}

// Updates, this ensures smooth transition of the samples

	if(Crowd->flags&CF_PAN)			// Continue Pan Around
		{
		Crowd->pan+=Crowd->pandelta;
		if(Crowd->pan>0xffff)		// Change Direction if at maximum
			{
			Crowd->pan=0xffff;
			Crowd->pandelta=-Crowd->pandelta;
			}
		if(Crowd->pan<0)				// Change Direction if at minimum
			{
			Crowd->pan=0x0;
			Crowd->pandelta=-Crowd->pandelta;
			}
//		sosDIGISetPanLocation(DIGIDriverHandle,Crowd->mainhandle,Crowd->pan);
		}

	if(Crowd->flags&CF_TRAN)		// Ambience Transition
		{
		Crowd->mainvol-=Crowd->maindelta;
		Crowd->mergevol+=Crowd->mergedelta;
		if((Crowd->mergevol>Crowd->volmax)||(Crowd->mainvol<0))
			{
			Crowd->mergevol=Crowd->volmax;
			Crowd->mergedelta=0;
			Crowd->mainvol=0;
			}
//		sosDIGISetSampleVolume(DIGIDriverHandle,Crowd->mainhandle,Crowd->mainvol);
//		sosDIGISetSampleVolume(DIGIDriverHandle,Crowd->mergehandle,Crowd->mergevol);
		if(!Crowd->mainvol)
			{
			sosDIGIStopSample(DIGIDriverHandle,Crowd->mainhandle);
			Crowd->mainhandle=Crowd->mergehandle;
			Crowd->mainvol=Crowd->mergevol;
			Crowd->mergevol=0;
			Crowd->mood=Crowd->tranmood;
			Crowd->flags&=~CF_TRAN;
			}
		}
}

//************************************************************************************************
//
// Create a pitch or crowd effects fullname and place it in dest
//
//************************************************************************************************
void CreatePitchFileName(char *name,char *mad,char *dest)
{
	BuildSampleDisk( mad, ":DIGI:PITCH:PITCH.MAD");
	strcpy(dest,name); strcat(dest,".WAV");
}

//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################
//
// Commentary
//
//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################


//************************************************************************************************
//
// Loads in the samples for Country name, Manager name and Player names given a 
// the team number and the sample bank to load in to.
//
//************************************************************************************************
unsigned int LoadTeamSamples(int team_num,int team)
{
	struct team_info *teamdata;
	player_info *player;
	struct memstatus TeamMemory={0};
	teamsam *bank;
	char madname[64];
	char filename[16];
	char playernum[3];
	int i;

	if( ChecksumTeam( team_num) != TeamChecksums[ team_num] )
		return false;

	if(SoundCard&&CommentaryVolume)
		{
		teamdata=&game_data[team_num];				// Get Address of Team Data Structure
		bank=&PlayerBank[team];
		bank->team=team_num;

// Load Country Name

		CreatePlayerFileName(teamdata->country_code,"TT","Z",&madname[0],&filename[0]);
		LoadSample(madname,filename,&bank->country.z,&TeamMemory);

// Load Manager Name

//		CreatePlayerFileName(teamdata->country_code,"00","X",&madname[0],&filename[0]);
//		LoadSample(madname,filename,&bank->manager.x,&TeamMemory);

// Load Players Names

		player=&teamdata->players[0];						// Address of First Player (Keeper)

		for(i=0;i<11;i++)
			{
			sprintf(&playernum[0],"%.2d",player[i].squad_number+1);			// Convert squadnumber to a string

			CreatePlayerFileName(teamdata->country_code,playernum,"X",&madname[0],&filename[0]);
			LoadSample(madname,filename,&bank->players[i].x,&TeamMemory);

			CreatePlayerFileName(teamdata->country_code,playernum,"Y",&madname[0],&filename[0]);
			LoadSample(madname,filename,&bank->players[i].y,&TeamMemory);

			CreatePlayerFileName(teamdata->country_code,playernum,"Z",&madname[0],&filename[0]);
			LoadSample(madname,filename,&bank->players[i].z,&TeamMemory);
			}
		}

		return(TeamMemory.fail);
}

//************************************************************************************************
//
// Free the samples for Country name, Manager name and Player names from memory
//
//************************************************************************************************
void FreeTeamSamples(int team)
{
	teamsam *bank;						// Pointer to team data
	int i;

	if(SoundCard)
		{
		bank=&PlayerBank[team];

		for(i=11-1;i>=0;i--)
			{
			FreeSample(&bank->players[i].z);	// Player samples
			FreeSample(&bank->players[i].y);	// Player samples
			FreeSample(&bank->players[i].x);	// Player samples
			}

//		FreeSample(&bank->manager.x);			// Manager sample
		FreeSample(&bank->country.z);			// Country sample
		}
}

//************************************************************************************************
//
//	Play a team sample (player name) from the SampleBank
//
//************************************************************************************************
int PlayTeamSample(int player,int intonation)
{
	teamsam *bank;						// Pointer to team data
	unsigned char *mem;				// Pointer to the sample
	unsigned int size;			// Size of the sample
	int playerindex;					// Index in to team data

	if(CommentaryHandle==-1&&!CommentaryPaused)
		{
		playerindex=player;

		if(player<12)
			bank=&PlayerBank[HOME_TEAM];
		else
			{
			bank=&PlayerBank[AWAY_TEAM];
			playerindex-=11;				// Compatability with game code
			}

		playerindex--;						// All players start from zero

		switch(intonation)
			{
			case PI_OWN_HALF:
				mem=bank->players[playerindex].x.mem;			// In own half
				size=bank->players[playerindex].x.size;
				break;

			case PI_OPPONENTS_HALF:
				mem=bank->players[playerindex].y.mem;			// In opponents half
				size=bank->players[playerindex].y.size;
				break;

			case PI_SHOOTING:
				mem=bank->players[playerindex].z.mem;			// Shooting
				size=bank->players[playerindex].z.size;
				if(playerindex==0)
					return(-1);
				break;

			default:
				return(-1);
			}

		CommentaryHandle=StartSample(mem,size,CommentaryVolume,0x8000,0x8000);

		return(CommentaryHandle);		// Start the sample
		}
	else
		return(-1);
}

//************************************************************************************************
//
//	Loads in the two samples for the welcome message and starts them playing
//
//************************************************************************************************
void PlayWelcomeMessage(void)
{
	struct team_info *teamdata;
	struct memstatus Memory={0};
	char madname[64];
	char filename[16];
	char filenum[3];
	int r;
	int error=0;

	if((CommentaryHandle==-1)&&SoundCard&&!CommentaryPaused)
		{
// Pre-match comment

		r=Random(MAX_MC_PREMATCH)+1;
		sprintf(&filenum[0],"%.2d",r);					// Convert sample number to a string
		CreateCommentaryFileName("MCA",filenum,&madname[0],&filename[0]);
		if(!LoadSample(madname,filename,&LinkBank[0],&Memory))
			{
			LinkStack[++LinkIndex]=&LinkBank[0];						// Add to the sample Stack
			CommentaryMode=CM_LINKBANK;
			}

// Away Team
		teamdata=&game_data[PlayerBank[AWAY_TEAM].team];					// Get Address of away Team Data Structure
		CreatePlayerFileName(teamdata->country_code,"TT","Y",&madname[0],&filename[0]);
		if(!LoadSample(madname,filename,&LinkBank[1],&Memory))
			{
// Home Team
			teamdata=&game_data[PlayerBank[HOME_TEAM].team];					// Get Address of home Team Data Stucture
			CreatePlayerFileName(teamdata->country_code,"TT","X",&madname[0],&filename[0]);
			if(!LoadSample(madname,filename,&LinkBank[2],&Memory))
				{	
				LinkStack[++LinkIndex]=&LinkBank[1];						// Add to the sample Stack
				LinkStack[++LinkIndex]=&LinkBank[2];						// Add to the sample Stack
				}
			else
				FreeSample(&LinkBank[1]);
			}
		}
}

//************************************************************************************************
//
//	Loads in the two samples for the welcome message and starts them playing
//
//************************************************************************************************
void PlaySubstitutionMessage(int team,int player_off,int player_on,int injured)
{
	struct team_info *teamdata;
	teamsam *teambank;
	memsam *linkbank;
	struct memstatus Memory={0};
	char madname[64];
	char filename[16];
	char filenum[3];
	int r;

	if((CommentaryHandle==-1)&&SoundCard&&!CommentaryPaused)
		{
		teambank=&PlayerBank[team];
		teamdata=&game_data[teambank->team];			// Get Address of Team Data Structure
		linkbank=&LinkBank[0];

		memcpy(&Substitute,&teambank->players[player_off],sizeof(intonsam));			// Copy player off to sub buffer
		memset(&teambank->players[player_off],0,sizeof(intonsam));

		sprintf(&filenum[0],"%.2d",teamdata->players[player_on].squad_number+1);			// Load in new player
		CreatePlayerFileName(teamdata->country_code,filenum,"X",&madname[0],&filename[0]);
		LoadSample(madname,filename,&teambank->players[player_off].x,&Memory);
		CreatePlayerFileName(teamdata->country_code,filenum,"Y",&madname[0],&filename[0]);
		LoadSample(madname,filename,&teambank->players[player_off].y,&Memory);
		CreatePlayerFileName(teamdata->country_code,filenum,"Z",&madname[0],&filename[0]);
		LoadSample(madname,filename,&teambank->players[player_off].z,&Memory);

		if(injured)
			{
			r=Random(MAX_SU_INJURED)+1;
			sprintf(&filenum[0],"%.2d",r);									// Convert sample number to a string
 			CreateCommentaryFileName("SUC",filenum,&madname[0],&filename[0]);		// Intermediate sample
			if(!LoadSample(madname,filename,linkbank,&Memory))
				{
				LinkStack[++LinkIndex]=&Substitute.x;							// Add player going off to sample stack
				LinkStack[++LinkIndex]=linkbank;									// Add to the sample Stack
				LinkStack[++LinkIndex]=&teambank->players[player_off].x;			// Player going off
				}	
	  		CommentaryMode=SU_INJURED;
			}
		else
			if(Random(8)>2)
				{
				r=Random(MAX_SU_TEAM)+1;
				sprintf(&filenum[0],"%.2d",r);									// Convert sample number to a string
				switch(r)
					{
					case 1:
 						CreateCommentaryFileName("SUB",filenum,&madname[0],&filename[0]);		// Play the team then the sample
						if(!LoadSample(madname,filename,linkbank,&Memory))
							{
							LinkStack[++LinkIndex]=linkbank;									// Add to the sample Stack
							LinkStack[++LinkIndex]=&PlayerBank[team].country.z;
							}
						CommentaryMode=SU_TEAM;
						break;

					case 5:
						LinkStack[++LinkIndex]=&PlayerBank[team].country.z;
 						CreateCommentaryFileName("SUB",filenum,&madname[0],&filename[0]);		// Play the sample then the team
						if(!LoadSample(madname,filename,linkbank,&Memory))
							LinkStack[++LinkIndex]=linkbank;									// Add to the sample Stack
						CommentaryMode=SU_TEAM;
						break;

					default:
 						CreateCommentaryFileName("SUB",filenum,&madname[0],&filename[0]);		// Just play the sample on its own
						if(!LoadSample(madname,filename,linkbank,&Memory))
							LinkStack[++LinkIndex]=linkbank;									// Add to the sample Stack
						CommentaryMode=SU_TEAM;
						break;
					}
				}
			else
				{
				r=Random(MAX_SU_ONFOR)+1;
				sprintf(&filenum[0],"%.2d",r);									// Convert sample number to a string
 				CreateCommentaryFileName("SUA",filenum,&madname[0],&filename[0]);		// Intermediate sample
				if(!LoadSample(madname,filename,linkbank,&Memory))
					{
					LinkStack[++LinkIndex]=&Substitute.x;							// Add player going off to sample stack
					LinkStack[++LinkIndex]=linkbank;									// Add to the sample Stack
					LinkStack[++LinkIndex]=&teambank->players[player_off].x;			// Player going off
					}
	  			CommentaryMode=SU_ONFOR;
				}
		}
}

//************************************************************************************************
//
// Plays a commentary message
//
//************************************************************************************************
void PlayCommentaryMessage(int type)
{
	if(!CommentaryMode&&SoundCard&&!CommentaryPaused)
		{
		switch(type)
			{
			case CP_LONG:
			case CP_SHORT:									  
			case FP_LONG:
			case FP_SHORT:
			case FP_LOOSE:
				if(CommentaryBank[type-1].mem)
					if(CommentaryHandle==-1&&(Random(8)<4))
						{
						LinkStack[++LinkIndex]=&CommentaryBank[type-1];		// Add to the sample Stack
						CommentaryMode=type;
						}
				break;

			case FU_FREEKICK:			// Foul
			case FU_WALL:
			case FU_BADFOUL:
			case FU_YELLOWCARD:
			case FU_REDCARD:
			case FU_INJURY:
			case FU_DIVE:
			case GL_GENERIC:			// Goal
			case GL_DEFLECT:
			case GL_HARDKICK:
			case GL_HEADER:
			case GL_KEEPER:
			case GL_POST:
			case GL_CURVE:
			case GL_CURVEWALL:
			case PM_CATCH:				// Player missed goal attempt
			case PM_BLOCK:
			case PM_WIDE:
			case PM_CLOSE:
			case PM_POST:
			case PM_CROSSBAR:
				if(CommentaryBank[type-1].mem)
					if(!(CommentaryBank[type-1].flags&MSF_PLAYED))
						{
						LinkStack[++LinkIndex]=&CommentaryBank[type-1];		// Add to the sample Stack
						CommentaryMode=type;
						}
				break;

			case TI_FULLTIME:
				if(CommentaryHandle==-1)
					{
					LoadCommentarySample("TIM",-3,&LinkBank[0]);			// 'and thats the final score'
					LinkStack[++LinkIndex]=&LinkBank[0];					// Add to the sample Stack
					CommentaryMode=CM_LINKBANK;
					}	
				break;
			case TI_HALFTIME:
				if(CommentaryHandle==-1)
					{
					LoadCommentarySample("TIM",-10,&LinkBank[0]);		// 'thats the score at half time'
					LinkStack[++LinkIndex]=&LinkBank[0];					// Add to the sample Stack
					CommentaryMode=CM_LINKBANK;
					}	
				break;

			default:
				if(CommentaryBank[type-1].mem)
					if(CommentaryHandle==-1)
						{
						LinkStack[++LinkIndex]=&CommentaryBank[type-1];		// Add to the sample Stack
						CommentaryMode=type;
						}
				break;
			}
		}
	else if(type<MAX_COMMENTARY_CATEGORIES)
		LoadCommentarySample(CommentaryCategories[type].name,CommentaryCategories[type].count,&CommentaryBank[type]);
}

//************************************************************************************************
//
// Plays a possession sample
//
// team 		is the team with the most possession
//
//************************************************************************************************
void PlayPossessionSample(int team)
{
	memsam *linkbank;
	struct memstatus Memory={0};
	char madname[64];
	char filename[16];
	char filenum[3];
	int r;

	if((CommentaryHandle==-1)&&SoundCard&&!CommentaryPaused)
		{
		linkbank=&LinkBank[0];
		if(Random(8)>3)
			{					// Play a Good Play Sample
			r=Random(MAX_OT_GOODPLAY)+1;
//			r=1;
			sprintf(&filenum[0],"%.2d",r);					// Convert sample number to a string
			switch(r)
				{
				case 17:		// Play managers name and then the sample
// 				CreateCommentaryFileName("OTB",filenum,&madname[0],&filename[0]);
//					if!(LoadSample(madname,filename,linkbank,&Memory))
//						{
//						LinkStack[++LinkIndex]=linkbank;				// Add to the sample Stack
//						LinkStack[++LinkIndex]=&PlayerBank[team].country.z;
//						CommentaryMode=CM_LINKBANK;
//						}
					break;

				case 1:		// Play teams sample and then the sample
				case 18:
				case 19:
				case 20:
				case 25:
				case 27:
					CreateCommentaryFileName("OTB",filenum,&madname[0],&filename[0]);
					if(!LoadSample(madname,filename,linkbank,&Memory))
						{
						LinkStack[++LinkIndex]=linkbank;				// Add to the sample Stack
						LinkStack[++LinkIndex]=&PlayerBank[team].country.z;
						CommentaryMode=CM_LINKBANK;
						}
					break;

				default:		// Just play the sample
					CreateCommentaryFileName("OTB",filenum,&madname[0],&filename[0]);
					if(!LoadSample(madname,filename,linkbank,&Memory))
						{
						LinkStack[++LinkIndex]=linkbank;				// Add to the sample Stack
						CommentaryMode=CM_LINKBANK;
						}
					break;
				}
			}
		else
			{					// Play a Poor Play Sample
			r=Random(MAX_OT_POORPLAY)+1;
//			r=2;
			sprintf(&filenum[0],"%.2d",r);					// Convert sample number to a string
			switch(r)
				{
				case 2:		// Play teams sample and then the sample
					CreateCommentaryFileName("OTD",filenum,&madname[0],&filename[0]);
					if(!LoadSample(madname,filename,linkbank,&Memory))
						{	
						LinkStack[++LinkIndex]=linkbank;				// Add to the sample Stack
						LinkStack[++LinkIndex]=&PlayerBank[team^1].country.z;
						CommentaryMode=CM_LINKBANK;
						}	
					break;

				case 4:		// Play the sample and then the teams sample
					CreateCommentaryFileName("OTD",filenum,&madname[0],&filename[0]);
					if(!LoadSample(madname,filename,linkbank,&Memory))
						{
						LinkStack[++LinkIndex]=&PlayerBank[team^1].country.z;
						LinkStack[++LinkIndex]=linkbank;				// Add to the sample Stack
						CommentaryMode=CM_LINKBANK;
						}
					break;

				default:		// Just play the sample
					CreateCommentaryFileName("OTD",filenum,&madname[0],&filename[0]);
					if(!LoadSample(madname,filename,linkbank,&Memory))
						{
						LinkStack[++LinkIndex]=linkbank;				// Add to the sample Stack
						CommentaryMode=CM_LINKBANK;
						}	
					break;
				}
			}
		}
}

//************************************************************************************************
//
// Loads a commentary sample
//
//************************************************************************************************
void LoadCommentarySample(char *category,int samples,memsam *bank)
{
	struct memstatus Memory={0};
	char madname[64];
	char filename[16];
	char filenum[3];
	int i,r;

	if((CommentaryHandle==-1)&&SoundCard&&CommentaryVolume)
		{
		if(samples>0)
			{
			for(i=0;i<samples;i++) 								// MAX_REPEAT_ATTEMPTS
				{
				r=Random(samples)+1;
				if(!CheckRepeatBuffer(category,r))
					break;
				}
			}
		else
			r=-samples;
		sprintf(&filenum[0],"%.2d",r);					// Convert sample number to a string
		CreateCommentaryFileName(category,filenum,&madname[0],&filename[0]);
		LoadSample(madname,filename,bank,&Memory);
//		LinkStack[++LinkIndex]=bank;						// Add to the sample Stack
		return;
		}
}

//************************************************************************************************
//
// Loads and plays a score sample
//
//************************************************************************************************
void PlayScoreSample(int home,int away)
{
	char homescore[2];
	char awayscore[2];
	char madname[64];
	char filename[16];
	memsam *bank;
	int i;
	struct memstatus Memory={0};

	if(CommentaryHandle==-1&&SoundCard&&!CommentaryPaused)
		{
		if(home<away)			// The home score has to be the highest score
			{
			i=home;
			home=away;
			away=i;
			}

		if((home<=7)&&(away<=5))					// Range check the score
			{
			itoa(home,homescore,10);
			itoa(away,awayscore,10);

			if(away>home)
				CreateScoreFileName(&awayscore[0],&homescore[0],&madname[0],&filename[0]);
			else
				CreateScoreFileName(&homescore[0],&awayscore[0],&madname[0],&filename[0]);

			bank=&LinkBank[0];
			LoadSample(madname,filename,bank,&Memory);
			LinkStack[++LinkIndex]=bank;						// Add to the sample Stack
			CommentaryMode=CM_LINKBANK;
			}
		}
}

//************************************************************************************************
//
// Create score filename and place it in dest
//
//************************************************************************************************
void CreateScoreFileName(char *home,char *away,char *mad,char *dest)
{
	BuildSampleDisk(mad, ":DIGI:PHRASES:");
	strcat(mad,SampleLanguage[Language]);		// Language of Samples
	strcat(mad,":");
	strcat(mad,SampleLanguage[Language]);		// Language of Samples
	strcat(mad,"_");
	strcat(mad,"SCO");
	strcat(mad,".MAD");

	strcpy(dest,SampleLanguage[Language]);		// Language of Samples
	strcat(dest,"_");
	strcat(dest,"SCO");
	strcat(dest,home);
	strcat(dest,away);
	strcat(dest,".WAV");
}

//************************************************************************************************
//
// Free all the samples in the Link Bank
//
//************************************************************************************************
void FreeLinkBank(void)
{
	int i;

	for(i=MAX_LINKS-1;i>=0;i--)
		if(LinkBank[i].mem)
			FreeSample(&LinkBank[i]);
}

//************************************************************************************************
//
// Create a full music filename and place it in dest
//
//************************************************************************************************
void CreateMusicFileName(char *name,char *dest)
{
	BuildSampleDisk( dest, ":DIGI:MUSIC:");
	strcat(dest,name); strcat(dest,".WAV");
}

//************************************************************************************************
//
// Create a players filename given country,squad number,intonation and place it in dest
//
//************************************************************************************************
void CreatePlayerFileName(char *country,char *number,char *intonation,char *mad,char *dest)
{
	BuildSampleDisk( mad, ":DIGI:TEAMS:");				// Create path
	strcat(mad,SampleLanguage[Language]);		// Language of Samples
	strcat(mad,":");
	strcat(mad,SampleLanguage[Language]);		// Language of Samples
	strcat(mad,"_");
	strcat(mad,country);								// Append country code
	strcat(mad,".MAD");								// Add the MAD Extension

	strcpy(dest,SampleLanguage[Language]);		// Language of Samples
	strcat(dest,"_");
	strcat(dest,country);							// Append country code
	strcat(dest,intonation);						// Level of Inotonation
	strcat(dest,number);								// 
	strcat(dest,".WAV");								// Add the WAV Extension
}

//************************************************************************************************
//
// Load as many commentary samples that will fit in memory
//
//************************************************************************************************
unsigned int LoadCommentarySamples(void)
{
	memsam *bank;
	struct memstatus CommentaryMemory={0};
	char madname[64];
	char filename[16];
	char filenum[3];
	int i,r;

	bank=&CommentaryBank[0];

	if(SoundCard&&CommentaryVolume)
		{
		for(i=0;i<MAX_COMMENTARY_CATEGORIES;i++)
			{
			r=Random(CommentaryCategories[i].count)+1;
			CheckRepeatBuffer(CommentaryCategories[i].name,r);		// Add to the repeat buffer
			sprintf(&filenum[0],"%.2d",r);					// Convert sample number to a string
			CreateCommentaryFileName(CommentaryCategories[i].name,filenum,&madname[0],&filename[0]);
			LoadSample(madname,filename,bank,&CommentaryMemory);
			bank++;
			}
		}
	return(CommentaryMemory.fail);
}

//************************************************************************************************
//
// Free memory previously allocated with LoadCommentarySamples
//
//************************************************************************************************
void FreeCommentarySamples(void)
{
	memsam *bank;
	int i;

	if(SoundCard)
		{
		FreeLinkBank();					// This may not be freed by UpdateCommentary

		bank=&CommentaryBank[0];

		for(i=MAX_COMMENTARY_CATEGORIES-1;i>=0;i--)
			FreeSample(&bank[i]);
		}
}

//************************************************************************************************
//
// Create a commentary phrases full filename and place it in dest
//
//************************************************************************************************
void CreateCommentaryFileName(char *category,char *number,char *mad,char *dest)
{
	BuildSampleDisk( mad, ":DIGI:PHRASES:");
	strcat(mad,SampleLanguage[Language]);		// Language of Samples
	strcat(mad,":");
	strcat(mad,SampleLanguage[Language]);		// Language of Samples
	strcat(mad,"_");
	strcat(mad,category);							// Main Category Code
	strcat(mad,".MAD");

	strcpy(dest,SampleLanguage[Language]);		// Language of Samples
	strcat(dest,"_");
	strcat(dest,category);							// Main Category Code
	strcat(dest,number);
	strcat(dest,".WAV");
}

//************************************************************************************************
//
// Create a full filename for the front end
//
//************************************************************************************************
void CreateFrontEndFileName(char *category,char *name,char *mad,char *dest)
{
	BuildSampleDisk( mad, ":DIGI:PHRASES:");
	strcat(mad,SampleLanguage[Language]);		// Language of Samples
	strcat(mad,":");
	strcat(mad,SampleLanguage[Language]);		// Language of Samples
	strcat(mad,"_");
	strcat(mad,category);							// Main Category Code
	strcat(mad,".MAD");

	strcpy(dest,SampleLanguage[Language]);		// Language of Samples
	strcat(dest,"_");
	strcat(dest,name);							// Main Category Code
	strcat(dest,".WAV");
}

//************************************************************************************************
//
// Updates the Commentary Periodically
//
//************************************************************************************************
void UpdateCommentary(void)
{
	unsigned char *mem;				// Pointer to the sample
	unsigned int size;			// Size of the sample

	if(!CheckCommentary())
		{
		if(LinkIndex>=0)								// Check for linked phrases
			{												// Playing a linked phrase
			mem=LinkStack[LinkIndex]->mem;
			size=LinkStack[LinkIndex]->size;
			LinkStack[LinkIndex]->flags|=MSF_PLAYED;		// Flag the sample as played
			CommentaryHandle=StartSample(mem,size,CommentaryVolume,0x8000,0x8000);
			LinkIndex--;
			}
		else
			switch(CommentaryMode)
				{
				case CM_NULL:
					break;

				case SU_ONFOR:							// Players exchanged for substitutions
				case SU_TEAM:
				case SU_INJURED:
					FreeSample(&Substitute.z);
					FreeSample(&Substitute.y);
					FreeSample(&Substitute.x);
					FreeLinkBank();
					CommentaryMode=CM_NULL;
					break;

				case CM_LINKBANK:
					FreeLinkBank();
					CommentaryMode=CM_NULL;
					break;

				default:									// Replace sample in commentary bank
					CommentaryMode-=1;
					FreeSample(&CommentaryBank[CommentaryMode]);
					LoadCommentarySample(CommentaryCategories[CommentaryMode].name,CommentaryCategories[CommentaryMode].count,&CommentaryBank[CommentaryMode]);
					CommentaryMode=CM_NULL;
					break;
				}
		}
}

//************************************************************************************************
//
// Check if the commentator is still talking
//
//************************************************************************************************
short int CheckCommentary(void)
{
	if((CommentaryHandle!=-1)&&SoundCard)
		{
		if(CheckSample(CommentaryHandle))			// Sample still playing?
			return(1);
		else
			CommentaryHandle=-1;							// Flag sample has Finished
		}
	return(0);												// Not Talking
}





//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################
//
// General Internal Functions for above
//
//################################################################################################
//################################################################################################
//################################################################################################
//################################################################################################





//************************************************************************************************
//
// Load in a Sample given the filename, fills in the memsam structure and modifies
// module structure MemStatus
//
//************************************************************************************************
int LoadSample(char *mad,char *name,memsam *bank,struct memstatus *MemStatus)
{
	FILE *fp;
	wavinfo WAVInfo;
	short int WAVError;

	fp=fopen(mad,"rb");
	if(fp)
		{
		if(!MADFindFile(fp,name))
			WAVError=ReadWAV(fp,11025,WAV_MONO,WAV_8_BIT,&WAVInfo);
		else
			{
			WAVError=WAV_FILE;
			WAVInfo.size=0;
			}
		fclose(fp);
		}
	else
		{
		WAVError=WAV_FILE;
		WAVInfo.size=0;
		}

	if(WAVError)
		{
		bank->mem=0;
		bank->size=0;
		bank->flags&=~MSF_PLAYED;
		MemStatus->fail+=WAVInfo.size;			// Add to the failed list (This value is only true if the header of the wav header got loaded)
//		TotalMemStatus.fail+=WAVInfo.size;
		return(1);										// Failed
		}
	else
		{
		bank->mem=(unsigned char *)WAVInfo.mem;
		bank->size=WAVInfo.size;
		bank->flags&=~MSF_PLAYED;
//		MemStatus->ext+=WAVInfo.size;		// Add to the base list
//		TotalMemStatus.ext+=WAVInfo.size;
		return(0);									// Success
		}
}

//************************************************************************************************
//
// Frees a sample from memory given its bank
//
//************************************************************************************************
void FreeSample(memsam *bank)
{
	FreeX(bank->mem);
//	TotalMemStatus.ext-=bank->size;
	bank->mem=0;
}

//************************************************************************************************
//
// Compares Two String (no case)
//
//************************************************************************************************
static int stricmp( char *one, char *two)
{
char c,d;

	while(*one)
	  {
	  if(!*two)
		return -1;
	  c=*one++; d=*two++;
	  if(c>='a' && c<='z') c-= 32;
	  if(d>='a' && d<='z') d-= 32;
	  c-=d;
	  if(c)
	    return -1;
	  }
		  
	return *one-*two;
}

//************************************************************************************************
//
// Find a file in a MAD file
//
//************************************************************************************************
int MADFindFile(FILE *fp,char *name)
{
madfile *mem;
madfile *dir;
madfile first;
madfile MADFileHeader[128];
int i;

	if(fread(&first,1,sizeof(madfile),fp))
		{
		InvertFloat( (BYTE *)&first.offset, 2);
		if(!fseek(fp,0,SEEK_SET))											// Load in the mad directory
			{
//			mem=dir=(madfile *)MallocX(MADFileHeader.offset);
			mem = dir = (madfile *)&MADFileHeader[0];
			if(mem)
				{
				if(fread(mem,first.offset,1,fp))
					{
					for(i=0;i<(first.offset/sizeof(madfile));i++)
						InvertFloat( (BYTE *)&MADFileHeader[i].offset, 2);
					dir = mem;
					for(i=0;i<(first.offset/sizeof(madfile));i++,dir++)
						{
						if(!stricmp(name,dir->name))
							{
							if(!fseek(fp,dir->offset,SEEK_SET))						// Seek to the file location
								{
//								FreeX((void *)mem);
								return(0);
								}		
							}
						}
					}
//				FreeX((void *)mem);
				}
			}
		}
	return(1);				// Some kind of error
}

//************************************************************************************************
//
// Checks and maintains the repeat buffer
//
// returns NULL if not found
//
//************************************************************************************************
int CheckRepeatBuffer(char *category,int num)
{
	commcat *ptr;
	
	if(RepeatHigh!=&RepeatBuffer[0])				// Check for first entry
		{
		ptr=&RepeatBuffer[0];

		while(ptr<RepeatHigh)
			{
			if(!stricmp(category,ptr->name))
				if(num==ptr->count)
					return(1);							// Found in the repeat buffer
			ptr++;
			}
		}

	strcpy(RepeatCurrent->name,category);
	RepeatCurrent->count=num;
	if(RepeatHigh<&RepeatBuffer[MAX_REPEAT_BUFFER])
		RepeatHigh++;
	RepeatCurrent++;
	if(RepeatCurrent>&RepeatBuffer[MAX_REPEAT_BUFFER-1])
		RepeatCurrent=&RepeatBuffer[0];

	return(0);
}

#if DEBUGGING==ON
void DumpAudioStuff(void)
{
	DumpLong( 340, CommentaryHandle);
	
	DumpLong( 360, CrowdControl[0].mainhandle);
	DumpLong( 370, CrowdControl[0].mood);
	DumpLong( 380, CrowdControl[0].tranmood);
	DumpLong( 390, CrowdControl[0].mainvol);
	DumpLong( 400, CrowdControl[0].volmax);
	DumpLong( 410, CrowdControl[0].pan);
	DumpLong( 420, CrowdControl[0].flags);
	
	DumpLong( 440, CrowdControl[1].mainhandle);
	DumpLong( 450, CrowdControl[1].mood);
	DumpLong( 460, CrowdControl[1].tranmood);
	DumpLong( 470, CrowdControl[1].mainvol);
	DumpLong( 480, CrowdControl[1].volmax);
	DumpLong( 490, CrowdControl[1].pan);
	DumpLong( 500, CrowdControl[1].flags);

}
#endif
