EXTERN long int UnMangleMemToMem(unsigned char *source, unsigned char *dest);
EXTERN long int UnMangleFileToMem(char *srcfile,unsigned char *dest);
EXTERN long int UnMangleFileToFile(char *srcfile,char *destfile);
/* Header File for unmangle decompression */

#if     !defined(__UNMANGLE_H)
#define __UNMANGLE_H

#define LOOKBACK 8196		// biggest lookback
#define BLOCKSIZE 10240		// output block size (keep > LOOKBACK to avoid overlap copies)
#define INPUTBLOCK 1024		// Size of the mangled data block to load


unsigned char *unmangleGet(unsigned long offset,unsigned long size);

#endif  /* __UNMANGLE_H */

