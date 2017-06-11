// Substitute malloc functions...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct meminfo {
	unsigned LargestBlockAvail;
	unsigned MaxUnlockedPage;
	unsigned LargestLockablePage;
	unsigned LinAddrSpace;
	unsigned NumFreePagesAvail;
	unsigned NumPhysicalPagesFree;
	unsigned TotalPhysicalPages;
	unsigned FreeLinAddrSpace;
	unsigned SizeOfPageFile;
	unsigned Reserved[3];
	} MemInfo;
		 
unsigned int get_mem_info()
{
#ifdef IMPLEMENT_ME
	union REGS regs;
	struct SREGS sregs;

	regs.x.eax=0x500;
	memset(&sregs,0,sizeof(sregs));
	sregs.es=FP_SEG(&MemInfo);
	regs.x.edi=FP_OFF(&MemInfo);
	int386x(0x31,&regs,&regs,&sregs);

	return (MemInfo.LargestBlockAvail);
#else
    return 0;
#endif
}
