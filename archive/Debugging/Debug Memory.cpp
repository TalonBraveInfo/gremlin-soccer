#include "Vars.h"

#undef EXTERN
#define EXTERN extern
#include "Failure.h"

#if DEBUGGING==YES
static Handle Handles[1024];

void DEBUG_CheckMemory(void)
{
}

Handle DEBUG_NewHandle(long Size, char *filename, long line)
{
Handle h = NewHandle(Size);
	
	for(int i=0; i< 1024;i++)
	  if(!Handles[i])
	    return (Handles[i] = h);
	return h;
}

Handle DEBUG_NewHandleClear(long Size, char *filename, long line)
{
Handle h = NewHandleClear(Size);
	
	for(int i=0; i< 1024;i++)
	  if(!Handles[i])
	    return (Handles[i] = h);
	return h;
}

void DEBUG_DisposeHandle(Handle Hand, char *filename, long line)
{
int i=0;

	if(Hand == NULL)
	  Fail(-1, filename, line, false, "\pDisposing of NULL Handle");
	else
	  {
	  while(i<1024)
	    {
	    if(Handles[i]==Hand)
	      {
	      DisposeHandle(Hand);
	      Handles[i]=NULL;
	      return;
	      }
	    i++;
	    }
	  Fail(-1, filename, line, false, "\pCould Not Find Handle");
  	  DisposeHandle( Hand);
	  }
}


#endif
