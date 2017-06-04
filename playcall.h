#ifndef _PLAYCALL_H_INCLUDED
/*
 ������������ͻ
 � AUTOHEADER �
 �������������������������������ͻ
 � Filename     PLAYCALL.H       �
 �������������������������������Ķ
 � Creation     11/5/1995        �
 �������������������������������͹
 �                               �
 � Updated: Fri 12/5/1995 13:50  �
 �                               �
 � Version: 1.016                �
 �                               �
 �������������������������������ͼ
*/

#include "playdam.h"

#ifdef __cplusplus
extern "C" {
#endif

// calls
long int InitAnim	( _PlayAnimBlock * ); 
long int StartAnim( _PlayAnimBlock * ); // should not be called if InitAnim failed
void 		CloseAnim( _PlayAnimBlock * ); // should always be called even if it fails

#define _PLAYCALL_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif