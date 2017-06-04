/* Header File for WAV File format */

#if     !defined(__WAVE_H)
#define __WAVE_H

enum
{
	WAV_OKAY,			// Everything Okay
	WAV_FILE,			// Cannot find file
	WAV_HEAD,			// Bad Header (Not a WAV file)
	WAV_FREQ,			// Incorrect Frequency
	WAV_CHAN,			// Wrong number of channels
	WAV_BITS,			// Wrong number of bits
	WAV_READ,			// File Read Error
	WAV_MEM				// Cannot allocate memory
};

struct wavinfo
{
	unsigned char *mem;
	long	size;
};

struct riffhdr
{
	long 	rID;
	long	rLen;
};

struct wavfmtchnk
{
	long 	fID;
	long 	fLen;
	short 	wFormatTag;
	short 	nChannels;
	long 	nSamplesPerSec;
	long 	nAvgBytesPerSec;
	short 	nBlockAlign;
	short 	FormatSpecific;
};

struct wavdatachnk
{
	long	dID;
	long	dLen;
};

struct wavhdr
{
	riffhdr			RIFFHeader;
	long			WAVEHeader;
	wavfmtchnk		WAVEFormatChunk;
	wavdatachnk		WAVEDataChunk;
};

#define WAV_8_BIT 8
#define WAV_16_BIT 16

#define WAV_MONO 1
#define WAV_STEREO 2

extern short int ReadWAV(FILE *fp,long int freq,short int chan,short int bits,struct wavinfo *info);

#define FreeWAV(m) FreeX(m)

#endif  /* __WAVE_H */
