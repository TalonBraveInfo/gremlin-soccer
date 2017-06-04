/* DIGI.H */

EXTERN int UnInitialiseDIGI();
EXTERN int  InitialiseDIGI(int SampleRate, int Verbose);
EXTERN int StartSample(void *mem, int length, short amp, short pan, int freq);
EXTERN void StopSample(int handle);
EXTERN short CheckSample(int handle);
EXTERN short CheckHardDiskSample(void);
EXTERN unsigned int GetSamplePosition(int handle);
#if 0
EXTERN void InitHardDiskSample(FILE *fp,int offset,int length,int rate,int volume,int flags,void (callback)(void));
EXTERN int ContinueHardDiskSample();
EXTERN void HardDiskSampleCallBack(WORD wDriverHandle,WORD wAction,WORD wSampleHandle);
EXTERN void SetDIGIVolume(short int Master,short int HardDisk);
#endif
EXTERN void SetDIGIVolume(short int Master,short int HardDisk);

//#define IDF_VERBOSE	0x0001

