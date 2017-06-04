#include "Frontend Vars.h"
#include "Wave.h"

#undef EXTERN
#define EXTERN extern
#include "Digi.h"
#include "Mallocx.h"

#include <AIFF.h>

short int ReadWAV(FILE *fp,long int freq,short int chan,short int bits,struct wavinfo *info)
{
wavhdr WAVHeader;
short int WAVError;
OSErr theErr;

	info->mem=0;
	info->size=0;
	if(fread(&WAVHeader,1,sizeof(struct wavhdr),fp))
		{
		if(WAVHeader.WAVEHeader=='WAVE')
			{
			InvertFloat( (BYTE *)&WAVHeader.WAVEFormatChunk.nSamplesPerSec, 1);
			if(WAVHeader.WAVEFormatChunk.nSamplesPerSec==freq)
				{
				InvertWord( (BYTE *)&WAVHeader.WAVEFormatChunk.nChannels, 1);
				if(WAVHeader.WAVEFormatChunk.nChannels==chan)
					{
					InvertWord( (BYTE *)&WAVHeader.WAVEFormatChunk.FormatSpecific, 1);
					if(WAVHeader.WAVEFormatChunk.FormatSpecific==bits)
						{
						InvertFloat( (BYTE *)&WAVHeader.WAVEDataChunk.dLen, 1);
						info->mem=(unsigned char *)MallocX(WAVHeader.WAVEDataChunk.dLen);
						if(info->mem)		// Allocate the memory
							{
							if(fread((info->mem),1,WAVHeader.WAVEDataChunk.dLen,fp))							// Read in the data
								{
								info->size=WAVHeader.WAVEDataChunk.dLen;
								WAVError=WAV_OKAY;
								}
							else
								{
								FreeX(info->mem);
								info->mem=0;
								WAVError=WAV_READ;
								}
							}
						else 
							WAVError=WAV_MEM;
						}
					else
						WAVError=WAV_BITS;
					}
				else
					WAVError=WAV_CHAN;
				}
			else
				WAVError=WAV_FREQ;
			}
		else
	    	WAVError=WAV_HEAD;
		}
	else
	  WAVError=WAV_READ;

	return(WAVError);
}
