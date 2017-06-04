#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <time.h>
#include <math.h>
#include <string.h>

	
const char * GetText(int text_number)
{
	return	("");
}
	
	
const char * GetSTRING(int string_type, int array_number)
{
	return("");
}


int	GetSPRITEnumber(int sprite_type,int number,int LastSpriteNO)
{
	return(0);
}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�																 �
//�  SetToTEXTmode()														 �
//�                                                                                                                              �
//�  		Sets video mode to a test mode ready to return back to DOS.                                                      �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 

void	SetToTEXTmode()		
{
#ifdef IMPLEMENT_ME
		union REGS r;
		r.x.eax = 0x0003;
		int386(0x10, &r, &r);
#endif
}


