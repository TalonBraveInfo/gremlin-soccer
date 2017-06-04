#ifndef _ANIMLINK_H_INCLUDED
/*
 ������������ͻ
 � AUTOHEADER �
 �������������������������������ͻ
 � Filename     ANIMLINK.H       �
 �������������������������������Ķ
 � Creation     7/8/1995         �
 �������������������������������͹
 �                               �
 � Updated: Mon 7/8/1995 16:27   �
 �                               �
 � Version: 1.009                �
 �                               �
 �������������������������������ͼ
*/
#include "playdam.h"
#include "playcall.h"

/* link function for playdam...
****************************************
playanim {
		 	_PlayAnimBlock pab;

		 	if (! InitAnim	( InitAnimPlay( pab ) ))
				{
				StartAnim( pab );
	 			CloseAnim( pab );
				RestoreAnimPlay( pab )
          	}
****************************************
*/

_PlayAnimBlock * InitAnimPlay (_PlayAnimBlock *);
void RestoreAnimPlay (_PlayAnimBlock *);

#define _ANIMLINK_H_INCLUDED
#endif