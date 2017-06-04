#include "Frontend Vars.h"

#undef EXTERN
#define EXTERN extern
#include "3deng.h"
#include "Front Variables.h"

#define		DBL	4

team_formation	formation_data[MAX_FORMATIONS]={
// 4-3-3
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"3",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"4",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-106),SHADOWtextOFF|SFONT,MD,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"7",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/8),FORM_PITCH_yOFF+(PITCH_HI-114),SHADOWtextOFF|SFONT,MD,
		"8",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-(PITCH_WID/8),FORM_PITCH_yOFF+(PITCH_HI-114),SHADOWtextOFF|SFONT,MD,
		"9",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-130),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/4)+8-DBL,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		"11",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-8-DBL,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		},	
// 5-3-2
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"3",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"4",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-64),SHADOWtextOFF|SFONT,DF,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"7",FORM_PITCH_xOFF+(PITCH_WID/4)+8,FORM_PITCH_yOFF+(PITCH_HI-116),SHADOWtextOFF|SFONT,MD,
		"8",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-116),SHADOWtextOFF|SFONT,FD,
		"9",FORM_PITCH_xOFF+(PITCH_WID/4)+16,FORM_PITCH_yOFF+(PITCH_HI-154),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-16-DBL,FORM_PITCH_yOFF+(PITCH_HI-154),SHADOWtextOFF|SFONT,MD,
		"11",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-8-DBL,FORM_PITCH_yOFF+(PITCH_HI-116),SHADOWtextOFF|SFONT,MD,
		},	
// 6-3-1
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(15*(PITCH_WID/16)),FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,MD,
		"3",FORM_PITCH_xOFF+(PITCH_WID/16),FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"4",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"7",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-109),SHADOWtextOFF|SFONT,MD,
		"8",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"9",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-128),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/2)-DBL,FORM_PITCH_yOFF+(PITCH_HI-100),SHADOWtextOFF|SFONT,DF,
		"11",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-DBL,FORM_PITCH_yOFF+(PITCH_HI-109),SHADOWtextOFF|SFONT,MD,
		},	
// 4-2-4    		CHECKED OKAY
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF, 
		"3",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"4",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-106),SHADOWtextOFF|SFONT,MD,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"7",FORM_PITCH_xOFF+(PITCH_WID/8)+8,FORM_PITCH_yOFF+(PITCH_HI-154),SHADOWtextOFF|SFONT,FD,
		"8",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-106),SHADOWtextOFF|SFONT,MD,
		"9",FORM_PITCH_xOFF+(PITCH_WID/4)+32,FORM_PITCH_yOFF+(PITCH_HI-134),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-32-DBL,FORM_PITCH_yOFF+(PITCH_HI-134),SHADOWtextOFF|SFONT,FD,
		"11",FORM_PITCH_xOFF+(7*(PITCH_WID/8))-(2*DBL),FORM_PITCH_yOFF+(PITCH_HI-154),SHADOWtextOFF|SFONT,FD,
		},	
// 5-1-4
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-88),SHADOWtextOFF|SFONT,DF,
		"3",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-88),SHADOWtextOFF|SFONT,DF,
		"4",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-64),SHADOWtextOFF|SFONT,DF,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"7",FORM_PITCH_xOFF+(PITCH_WID/16)+8,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,MD,
		"8",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-108),SHADOWtextOFF|SFONT,FD,
		"9",FORM_PITCH_xOFF+(PITCH_WID/4)+32,FORM_PITCH_yOFF+(PITCH_HI-134),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-32-DBL,FORM_PITCH_yOFF+(PITCH_HI-134),SHADOWtextOFF|SFONT,FD,
		"11",FORM_PITCH_xOFF+(15*(PITCH_WID/16))-(2*DBL),FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		},	
// 4-0-6
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"3",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,FD,
		"4",FORM_PITCH_xOFF+(PITCH_WID/4)+8,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"7",FORM_PITCH_xOFF+(PITCH_WID/16)+8,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,DF,
		"8",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-8,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		"9",FORM_PITCH_xOFF+(PITCH_WID/4)+32,FORM_PITCH_yOFF+(PITCH_HI-134),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-32-DBL,FORM_PITCH_yOFF+(PITCH_HI-134),SHADOWtextOFF|SFONT,FD,
		"11",FORM_PITCH_xOFF+(15*(PITCH_WID/16))-(2*DBL),FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		},	
// 3-1-6
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,MD,
		"3",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"4",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-108),SHADOWtextOFF|SFONT,DF,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-8,FORM_PITCH_yOFF+(PITCH_HI-152),SHADOWtextOFF|SFONT,FD,
		"7",FORM_PITCH_xOFF+(PITCH_WID/16)+8,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		"8",FORM_PITCH_xOFF+(PITCH_WID/4)+8,FORM_PITCH_yOFF+(PITCH_HI-152),SHADOWtextOFF|SFONT,FD,
		"9",FORM_PITCH_xOFF+(PITCH_WID/4)+32,FORM_PITCH_yOFF+(PITCH_HI-134),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-32-DBL,FORM_PITCH_yOFF+(PITCH_HI-134),SHADOWtextOFF|SFONT,FD,
		"11",FORM_PITCH_xOFF+(15*(PITCH_WID/16))-(2*DBL),FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		},	
// 4-1-5
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"3",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,MD,
		"4",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-100),SHADOWtextOFF|SFONT,DF,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"7",FORM_PITCH_xOFF+(PITCH_WID/16)+8,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		"8",FORM_PITCH_xOFF+(PITCH_WID/4)+8,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		"9",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-126),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-8-DBL,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		"11",FORM_PITCH_xOFF+(15*(PITCH_WID/16))-(2*DBL),FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		},	
// 5-2-3
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-80+10),SHADOWtextOFF|SFONT,DF,
		"3",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-80+10),SHADOWtextOFF|SFONT,	DF,
		"4",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-64),SHADOWtextOFF|SFONT,DF,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-88+10),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-88+10),SHADOWtextOFF|SFONT,DF,
		"7",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-8,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,MD,
		"8",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-108),SHADOWtextOFF|SFONT,FD,
		"9",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-128),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/4)+8-DBL,FORM_PITCH_yOFF+(PITCH_HI-158),SHADOWtextOFF|SFONT,FD,
		"11",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-108),SHADOWtextOFF|SFONT,MD,
		},	
// 4-4-2    		CHECKED OKAY
		{
		"1",FORM_PITCH_xOFF+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-24),SHADOWtextOFF|SFONT,GK,
		"2",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"3",FORM_PITCH_xOFF+(PITCH_WID/4),FORM_PITCH_yOFF+(PITCH_HI-78),SHADOWtextOFF|SFONT,DF,
		"4",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-106),SHADOWtextOFF|SFONT,MD,
		"5",FORM_PITCH_xOFF+(PITCH_WID/2)-24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"6",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-80),SHADOWtextOFF|SFONT,DF,
		"7",FORM_PITCH_xOFF+(PITCH_WID/4)-16,FORM_PITCH_yOFF+(PITCH_HI-118),SHADOWtextOFF|SFONT,MD,
		"8",FORM_PITCH_xOFF+(PITCH_WID/2)+24,FORM_PITCH_yOFF+(PITCH_HI-106),SHADOWtextOFF|SFONT,MD,
		"9",FORM_PITCH_xOFF+(PITCH_WID/4)+16,FORM_PITCH_yOFF+(PITCH_HI-154),SHADOWtextOFF|SFONT,FD,
		"10",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-16-DBL,FORM_PITCH_yOFF+(PITCH_HI-154),SHADOWtextOFF|SFONT,FD,
		"11",FORM_PITCH_xOFF+(PITCH_WID/4)+(PITCH_WID/2)-DBL+16,FORM_PITCH_yOFF+(PITCH_HI-118),SHADOWtextOFF|SFONT,MD,
		},	
	   };



swap_player_buffer	swap_buffer[1]={
		{
		"",			NULL,					// player name, position ?.
 		NULL,	NULL,	NULL,	NULL,					// player info: rate, power, control, flair.
		NULL,	NULL,	NULL,	NULL,					// player info: vision, accuracy, stamina, discipline.
		NULL,	NULL,	NULL,						// player info:	disc_points, goals_season, injury_duration.
		},
				       };



referee_info		referee_data[33]={

		"Angeles",		86,	55,	USA, 
		"Spirin",		50,	35,	RUS, 
		"Vega Diaz",		68,	90,	SPN, 
		"Van Langenhove",	78,	66,	BEL, 
		"Mikkelsen",		92,	44,	DEN, 
		"Snoddy",		75,	49,	NIR, 
		"Jouini",		32,	70,	TUN, 
		"Rothlisberger",    	50,	32,	SWZ, 
		"Duk-hwan",   	 	67,	23,	SKR, 
		"Baldas",    		88,	94,	ITA, 
		"Don",    		79,	56,	ENG, 
		"Mottram",    		25,	77,	SCO, 
		"Burge",    		48,	64,	WAL, 
		"Torres Cadena",   	88,	76,	COL, 
		"Karlsson", 	  	66,	28,	SWE, 
		"Lamolina", 	  	96,	88,	ARG, 

		"Van der Ende",		34,	23,	HOL,
		"Kruger", 		88,	98,	GER,
		"Quiniou",		50,	44,	FRA,
		"Filippi Cavani",	22,	75,	URU,
		"Marsiglia",		78,	89,	BRA,
		"Brizio Carter",	66,	13,	MEX,
		"Krondl",		34,	49,	CZE,
		"Koho",			23,	44,	FIN,
		"Okada",		88,	96,	JAP,
		"Bakas",		78,	45,	GRE,
		"Orumbouio",		56,	89,	ROM,
		"Hrinak",		34,	23,	SLV,
		"Pena",			45,	77,	BOL,
		"Pairetto",    		78,	64,	ITA, 
		"Araujo",		98,	80,	BRA,
		"Matto",		52,	85,	URU,

		"Random", 	  	60,	40,	NULL, 
		};

team_info	game_data[MAX_TEAMS];

sprite		sprite_table[]={				       	 
								 
		{
		sprite1width,sprite1height,sprite1Bitmap,
		},

		{
		sprite1awidth,sprite1aheight,sprite1aBitmap,
		},

		{
		sprite1bwidth,sprite1bheight,sprite1bBitmap,
		},

		{
		sprite2width,sprite2height,sprite2Bitmap,
		},

		{
		sprite3width,sprite3height,sprite3Bitmap,
		},

		{
		sprite4width,sprite4height,sprite4Bitmap,
		},

		{
		sprite5width,sprite5height,sprite5Bitmap,
		},

		{
		sprite6width,sprite6height,sprite6Bitmap,
		},

		{
		sprite7width,sprite7height,sprite7Bitmap,
		},

		{
		sprite8width,sprite8height,sprite8Bitmap,
		},

		{
		sprite9width,sprite9height,sprite9Bitmap,
		},

		{
		sprite10width,sprite10height,sprite10Bitmap,
		},

		{
		sprite11width,sprite11height,sprite11Bitmap,
		},

		{
		sprite12width,sprite12height,sprite12Bitmap,
		},

		{
		sprite13width,sprite13height,sprite13Bitmap,
		},

		{
		sprite14width,sprite14height,sprite14Bitmap,
		},

		{
		sprite15width,sprite15height,sprite15Bitmap,
		},

		{
		sprite16width,sprite16height,sprite16Bitmap,
		},

		{
		sprite17width,sprite17height,sprite17Bitmap,
		},

		{
		sprite18width,sprite18height,sprite18Bitmap,
		},

		{
		sprite19width,sprite19height,sprite19Bitmap,
		},

		{
		sprite20width,sprite20height,sprite20Bitmap,
		},

		{
		sprite21width,sprite21height,sprite21Bitmap,
		},

		{
		sprite22width,sprite22height,sprite22Bitmap,
		},

		{
		sprite23width,sprite23height,sprite23Bitmap,
		},

		{
		sprite24width,sprite24height,sprite24Bitmap,
		},
	
		{
		sprite25width,sprite25height,sprite25Bitmap,
		},

		{
		sprite26width,sprite26height,sprite26Bitmap,
		},

		{
		sprite27width,sprite27height,sprite27Bitmap,
		},

		{
		sprite28width,sprite28height,sprite28Bitmap,
		},

		{
		sprite29width,sprite29height,sprite29Bitmap,
		},

		{
		sprite30width,sprite30height,sprite30Bitmap,
		},

		{
		sprite31width,sprite31height,sprite31Bitmap,
		},

		{
		sprite32width,sprite32height,sprite32Bitmap,
		},

		{
		sprite33width,sprite33height,sprite33Bitmap,
		},

		{
		sprite34width,sprite34height,sprite34Bitmap,
		},

		{
		sprite35width,sprite35height,sprite35Bitmap,
		},

		{
		sprite36width,sprite36height,sprite36Bitmap,
		},

		{
		sprite37width,sprite37height,sprite37Bitmap,
		},

		{
		sprite38width,sprite38height,sprite38Bitmap,
		},

		{
		sprite39width,sprite39height,sprite39Bitmap,
		},

		{
		sprite40width,sprite40height,sprite40Bitmap,
		},

		{
		sprite41width,sprite41height,sprite41Bitmap,
		},

		{
		sprite42width,sprite42height,sprite42Bitmap,
		},

		{
		sprite43width,sprite43height,sprite43Bitmap,
		},

		{
		sprite44width,sprite44height,sprite44Bitmap,
		},

		{
		sprite45width,sprite45height,sprite45Bitmap,
		},

		{
		sprite46width,sprite46height,sprite46Bitmap,
		},

		{
		sprite47width,sprite47height,sprite47Bitmap,
		},

		{
		sprite48width,sprite48height,sprite48Bitmap,
		},

		{
		sprite49width,sprite49height,sprite49Bitmap,
		},

		{
		sprite50width,sprite50height,sprite50Bitmap,
		},

		{
		sprite51width,sprite51height,sprite51Bitmap,
		},

		{
		sprite52width,sprite52height,sprite52Bitmap,
		},

		{
		sprite53width,sprite53height,sprite53Bitmap,
		},

		{
		sprite54width,sprite54height,sprite54Bitmap,
		},

		{
		sprite55width,sprite55height,sprite55Bitmap,
		},

		{
		sprite55Bwidth,sprite55Bheight,sprite55BBitmap,
		},

		{
		sprite55Cwidth,sprite55Cheight,sprite55CBitmap,
		},

		{
		sprite56width,sprite56height,sprite56Bitmap,
		},

		{
		sprite57width,sprite57height,sprite57Bitmap,
		},

		{
		sprite58width,sprite58height,sprite58Bitmap,
		},

		{
		sprite59width,sprite59height,sprite59Bitmap,
		},

		{
		sprite60width,sprite60height,sprite60Bitmap,
		},

		{
		sprite61width,sprite61height,sprite61Bitmap,
		},

		{
		sprite62width,sprite62height,sprite62Bitmap,
		},

		{
		sprite63width,sprite63height,sprite63Bitmap,
		},

		{
		sprite64width,sprite64height,sprite64Bitmap,
		},

		{
		sprite65width,sprite65height,sprite65Bitmap,
		},

		{
		sprite66width,sprite66height,sprite66Bitmap,
		},

		{
		sprite67width,sprite67height,sprite67Bitmap,
		},

		{
		sprite68width,sprite68height,sprite68Bitmap,
		},

		{
		sprite69width,sprite69height,sprite69Bitmap,
		},

		{
		sprite70width,sprite70height,sprite70Bitmap,
		},

		{
		sprite71width,sprite71height,sprite71Bitmap,
		},

		{
		sprite72width,sprite72height,sprite72Bitmap,
		},

		{
		sprite73width,sprite73height,sprite73Bitmap,
		},

		{
		sprite74width,sprite74height,sprite74Bitmap,
		},

		{
		sprite75width,sprite75height,sprite75Bitmap,
		},

		{
		sprite76width,sprite76height,sprite76Bitmap,
		},

		{
		sprite77width,sprite77height,sprite77Bitmap,
		},

		{
		sprite78width,sprite78height,sprite78Bitmap,
		},

		{
		sprite79width,sprite79height,sprite79Bitmap,
		},

		{
		sprite80width,sprite80height,sprite80Bitmap,
		},

		{
		sprite81width,sprite81height,sprite81Bitmap,
		},

		{
		sprite82width,sprite82height,sprite82Bitmap,
		},

		{
		sprite83width,sprite83height,sprite83Bitmap,
		},

		{
		sprite84width,sprite84height,sprite84Bitmap,
		},

		{
		sprite85width,sprite85height,sprite85Bitmap,
		},

		{
		sprite86width,sprite86height,sprite86Bitmap,
		},

		{
		sprite87width,sprite87height,sprite87Bitmap,
		},

		{
		sprite88width,sprite88height,sprite88Bitmap,
		},

		{
		sprite89width,sprite89height,sprite89Bitmap,
		},

		{
		sprite90width,sprite90height,sprite90Bitmap,
		},

		{
		sprite91width,sprite91height,sprite91Bitmap,
		},

		{
		sprite92width,sprite92height,sprite92Bitmap,
		},

		{
		sprite93width,sprite93height,sprite93Bitmap,
		},

		{
		sprite94width,sprite94height,sprite94Bitmap,
		},

		{
		sprite95width,sprite95height,sprite95Bitmap,
		},

		{
		sprite96width,sprite96height,sprite96Bitmap,
		},

		{
		sprite97width,sprite97height,sprite97Bitmap,
		},

		{
		sprite98width,sprite98height,sprite98Bitmap,
		},

		{
		sprite99width,sprite99height,sprite99Bitmap,
		},

		{
		sprite100width,sprite100height,sprite100Bitmap,
		},

		{
		sprite101width,sprite101height,sprite101Bitmap,
		},

		{
		sprite102width,sprite102height,sprite102Bitmap,
		},

		{
		sprite103width,sprite103height,sprite103Bitmap,
		},

		{
		sprite104width,sprite104height,sprite104Bitmap,
		},

		{
		sprite105width,sprite105height,sprite105Bitmap,
		},

		{
		sprite106width,sprite106height,sprite106Bitmap,
		},

		{
		sprite107width,sprite107height,sprite107Bitmap,
		},

		{
		sprite108width,sprite108height,sprite108Bitmap,
		},

		{
		sprite109width,sprite109height,sprite109Bitmap,
		},

		{
		sprite110width,sprite110height,sprite110Bitmap,
		},

		{
		sprite111width,sprite111height,sprite111Bitmap,
		},

		{
		sprite112width,sprite112height,sprite112Bitmap,
		},

		{
		sprite113width,sprite113height,sprite113Bitmap,
		},

		{
		sprite114width,sprite114height,sprite114Bitmap,
		},

		{
		sprite115width,sprite115height,sprite115Bitmap,
		},

		{
		sprite116width,sprite116height,sprite116Bitmap,
		},

		{
		sprite117width,sprite117height,sprite117Bitmap,
		},

		{
		sprite118width,sprite118height,sprite118Bitmap,
		},

		{
		sprite119width,sprite119height,sprite119Bitmap,
		},

		{
		sprite120width,sprite120height,sprite120Bitmap,
		},

		{
		sprite121width,sprite121height,sprite121Bitmap,
		},

		{
		sprite122width,sprite122height,sprite122Bitmap,
		},

		{
		sprite123width,sprite123height,sprite123Bitmap,
		},

		{
		sprite124width,sprite124height,sprite124Bitmap,
		},

		{
		sprite125width,sprite125height,sprite125Bitmap,
		},

		{
		sprite126width,sprite126height,sprite126Bitmap,
		},

		{
		sprite127width,sprite127height,sprite127Bitmap,
		},

		{
		sprite128width,sprite128height,sprite128Bitmap,
		},

		{
		sprite129width,sprite129height,sprite129Bitmap,
		},

		{
		sprite130width,sprite130height,sprite130Bitmap,
		},

		{
		sprite131width,sprite131height,sprite131Bitmap,
		},

		{
		sprite132width,sprite132height,sprite132Bitmap,
		},

		{
		sprite133width,sprite133height,sprite133Bitmap,
		},

		{
		sprite134width,sprite134height,sprite134Bitmap,
		},

		{
		sprite135width,sprite135height,sprite135Bitmap,
		},

		{
		sprite136width,sprite136height,sprite136Bitmap,
		},

		{
		sprite137width,sprite137height,sprite137Bitmap,
		},

		{
		sprite138width,sprite138height,sprite138Bitmap,
		},

		{
		sprite139width,sprite139height,sprite139Bitmap,
		},

		{
		sprite140width,sprite140height,sprite140Bitmap,
		},

		{
		sprite141width,sprite141height,sprite141Bitmap,
		},

		{
		sprite142width,sprite142height,sprite142Bitmap,
		},

		{
		sprite143width,sprite143height,sprite143Bitmap,
		},

		{
		sprite144width,sprite144height,sprite144Bitmap,
		},

		{
		sprite145width,sprite145height,sprite145Bitmap,
		},

		{
		sprite146width,sprite146height,sprite146Bitmap,
		},

		{
		sprite147width,sprite147height,sprite147Bitmap,
		},

		{
		sprite148width,sprite148height,sprite148Bitmap,
		},

		{
		sprite149width,sprite149height,sprite149Bitmap,
		},

		{
		sprite150width,sprite150height,sprite150Bitmap,
		},

//		{
//		sprite151width,sprite151height,sprite151Bitmap,
//		},
//
//		{
//		sprite152width,sprite152height,sprite152Bitmap,
//		},






		
		{
		sprite_S62width,sprite_S62height,sprite_S62Bitmap,
		},

		{
		sprite_S63width,sprite_S63height,sprite_S63Bitmap,
		},

		{
		sprite_S64width,sprite_S64height,sprite_S64Bitmap,
		},

		{
		sprite_S65width,sprite_S65height,sprite_S65Bitmap,
		},

		{
		sprite_S66width,sprite_S66height,sprite_S66Bitmap,
		},

		{
		sprite_S67width,sprite_S67height,sprite_S67Bitmap,
		},

		{
		sprite_S68width,sprite_S68height,sprite_S68Bitmap,
		},

		{
		sprite_S69width,sprite_S69height,sprite_S69Bitmap,
		},

		{
		sprite_S70width,sprite_S70height,sprite_S70Bitmap,
		},

		{
		sprite_S71width,sprite_S71height,sprite_S71Bitmap,
		},

		{
		sprite_S72width,sprite_S72height,sprite_S72Bitmap,
		},

		{
		sprite_S73width,sprite_S73height,sprite_S73Bitmap,
		},

		{
		sprite_S74width,sprite_S74height,sprite_S74Bitmap,
		},

		{
		sprite_S75width,sprite_S75height,sprite_S75Bitmap,
		},

		{
		sprite_S76width,sprite_S76height,sprite_S76Bitmap,
		},

		{
		sprite_S77width,sprite_S77height,sprite_S77Bitmap,
		},

		{
		sprite_S78width,sprite_S78height,sprite_S78Bitmap,
		},

		{
		sprite_S79width,sprite_S79height,sprite_S79Bitmap,
		},

		{
		sprite_S80width,sprite_S80height,sprite_S80Bitmap,
		},

		{
		sprite_S81width,sprite_S81height,sprite_S81Bitmap,
		},

		{
		sprite_S82width,sprite_S82height,sprite_S82Bitmap,
		},

		{
		sprite_S83width,sprite_S83height,sprite_S83Bitmap,
		},

		{
		sprite_S84width,sprite_S84height,sprite_S84Bitmap,
		},

		{
		sprite_S85width,sprite_S85height,sprite_S85Bitmap,
		},

		{
		sprite_S86width,sprite_S86height,sprite_S86Bitmap,
		},

		{
		sprite_S87width,sprite_S87height,sprite_S87Bitmap,
		},

		{
		sprite_S88width,sprite_S88height,sprite_S88Bitmap,
		},

		{
		sprite_S89width,sprite_S89height,sprite_S89Bitmap,
		},

		{
		sprite_S90width,sprite_S90height,sprite_S90Bitmap,
		},

		{
		sprite_S91width,sprite_S91height,sprite_S91Bitmap,
		},

		{
		sprite_S92width,sprite_S92height,sprite_S92Bitmap,
		},

		{
		sprite_S93width,sprite_S93height,sprite_S93Bitmap,
		},

		{
		sprite_S94width,sprite_S94height,sprite_S94Bitmap,
		},

		{
		sprite_S95width,sprite_S95height,sprite_S95Bitmap,
		},

		{
		sprite_S96width,sprite_S96height,sprite_S96Bitmap,
		},

		{
		sprite_S97width,sprite_S97height,sprite_S97Bitmap,
		},

		{
		sprite_S98width,sprite_S98height,sprite_S98Bitmap,
		},

		{
		sprite_S99width,sprite_S99height,sprite_S99Bitmap,
		},

		{
		sprite_S100width,sprite_S100height,sprite_S100Bitmap,
		},

		{
		sprite_S101width,sprite_S101height,sprite_S101Bitmap,
		},

		{
		sprite_S102width,sprite_S102height,sprite_S102Bitmap,
		},

		{
		sprite_S103width,sprite_S103height,sprite_S103Bitmap,
		},

		{
		sprite_S104width,sprite_S104height,sprite_S104Bitmap,
		},

		{
		sprite_S105width,sprite_S105height,sprite_S105Bitmap,
		},

		{
		sprite_S106width,sprite_S106height,sprite_S106Bitmap,
		},

		{
		sprite_S107width,sprite_S107height,sprite_S107Bitmap,
		},

		{
		sprite_S108width,sprite_S108height,sprite_S108Bitmap,
		},

		{
		sprite_S109width,sprite_S109height,sprite_S109Bitmap,
		},

		{
		sprite_S110width,sprite_S110height,sprite_S110Bitmap,
		},

		{
		sprite_S111width,sprite_S111height,sprite_S111Bitmap,
		},

		{
		sprite_S112width,sprite_S112height,sprite_S112Bitmap,
		},

		{
		sprite_S113width,sprite_S113height,sprite_S113Bitmap,
		},

		{
		sprite_S114width,sprite_S114height,sprite_S114Bitmap,
		},
 
		{
		sprite_S115width,sprite_S115height,sprite_S115Bitmap,
		},

		{
		sprite_S116width,sprite_S116height,sprite_S116Bitmap,
		},

		{
		sprite_S117width,sprite_S117height,sprite_S117Bitmap,
		},

		{
		sprite_S118width,sprite_S118height,sprite_S118Bitmap,
		},

		{
		sprite_S119width,sprite_S119height,sprite_S119Bitmap,
		},

		{
		sprite_S120width,sprite_S120height,sprite_S120Bitmap,
		},

		{
		sprite_S121width,sprite_S121height,sprite_S121Bitmap,
		},

		{
		sprite_S122width,sprite_S122height,sprite_S122Bitmap,
		},

		{
		sprite_S123width,sprite_S123height,sprite_S123Bitmap,
		},

		{
		sprite_S124width,sprite_S124height,sprite_S124Bitmap,
		},

		{
		sprite_S125width,sprite_S125height,sprite_S125Bitmap,
		},

		{
		sprite_S126width,sprite_S126height,sprite_S126Bitmap,
		},

		{
		sprite_S127width,sprite_S127height,sprite_S127Bitmap,
		},

		{
		sprite_S128width,sprite_S128height,sprite_S128Bitmap,
		},

		{
		sprite_S129width,sprite_S129height,sprite_S129Bitmap,
		},

		{
		sprite_S130width,sprite_S130height,sprite_S130Bitmap,
		},

		{
		sprite_S131width,sprite_S131height,sprite_S131Bitmap,
		},

		{
		sprite_S132width,sprite_S132height,sprite_S132Bitmap,
		},

		{
		sprite_S133width,sprite_S133height,sprite_S133Bitmap,
		},

		{
		sprite_S134width,sprite_S134height,sprite_S134Bitmap,
		},

		{
		sprite_S135width,sprite_S135height,sprite_S135Bitmap,
		},
		  
		{
		sprite_S136width,sprite_S136height,sprite_S136Bitmap,
		},

		{
		sprite_S137width,sprite_S137height,sprite_S137Bitmap,
		},

		{
		sprite_S138width,sprite_S138height,sprite_S138Bitmap,
		},

		{
		sprite_S139width,sprite_S139height,sprite_S139Bitmap,
		},

		{
		sprite_S140width,sprite_S140height,sprite_S140Bitmap,
		},

		{
		sprite_S141width,sprite_S141height,sprite_S141Bitmap,
		},

		{
		sprite_S142width,sprite_S142height,sprite_S142Bitmap,
		},

		{
		sprite_S143width,sprite_S143height,sprite_S143Bitmap,
		},

		{
		sprite_S144width,sprite_S144height,sprite_S144Bitmap,
		},

		{
		sprite_S145width,sprite_S145height,sprite_S145Bitmap,
		},

		{
		sprite_S146width,sprite_S146height,sprite_S146Bitmap,
		},

		{
		sprite_S147width,sprite_S147height,sprite_S147Bitmap,
		},

		{
		sprite_S148width,sprite_S148height,sprite_S148Bitmap,
		},

		{
		sprite_S149width,sprite_S149height,sprite_S149Bitmap,
		},

		{
		sprite_S150width,sprite_S150height,sprite_S150Bitmap,
		},

		{
		sprite_S151width,sprite_S151height,sprite_S151Bitmap,
		},

		{
		sprite_S152width,sprite_S152height,sprite_S152Bitmap,
		},

		{
		sprite_S153width,sprite_S153height,sprite_S153Bitmap,
		},

		{
		sprite_S154width,sprite_S154height,sprite_S154Bitmap,
		},

		{
		sprite_S155width,sprite_S155height,sprite_S155Bitmap,
		},

		{
		sprite_S156width,sprite_S156height,sprite_S156Bitmap,
		},

		{
		sprite_S157width,sprite_S157height,sprite_S157Bitmap,
		},

		{
		sprite_S158width,sprite_S158height,sprite_S158Bitmap,
		},

		{
		sprite_S159width,sprite_S159height,sprite_S159Bitmap,
		},

		{
		sprite_S160width,sprite_S160height,sprite_S160Bitmap,
		},

		{
		sprite_S161width,sprite_S161height,sprite_S161Bitmap,
		},

		{
		sprite_S162width,sprite_S162height,sprite_S162Bitmap,
		},

		{
		sprite_S163width,sprite_S163height,sprite_S163Bitmap,
		},

		{
		sprite_S164width,sprite_S164height,sprite_S164Bitmap,
		},

		{
		sprite_S165width,sprite_S165height,sprite_S165Bitmap,
		},

		{
		sprite_S166width,sprite_S166height,sprite_S166Bitmap,
		},

		{
		sprite_S167width,sprite_S167height,sprite_S167Bitmap,
		},

		{
		sprite_S168width,sprite_S168height,sprite_S168Bitmap,
		},

		{
		sprite_S169width,sprite_S169height,sprite_S169Bitmap,
		},

		{
		sprite_S170width,sprite_S170height,sprite_S170Bitmap,
		},

		{
		sprite_S171width,sprite_S171height,sprite_S171Bitmap,
		},

		{
		sprite_S172width,sprite_S172height,sprite_S172Bitmap,
		},

		{
		sprite_S173width,sprite_S173height,sprite_S173Bitmap,
		},

		{
		sprite_S174width,sprite_S174height,sprite_S174Bitmap,
		},

		{
		sprite_S175width,sprite_S175height,sprite_S175Bitmap,
		},

		{
		sprite_S176width,sprite_S176height,sprite_S176Bitmap,
		},

		{
		sprite_S177width,sprite_S177height,sprite_S177Bitmap,
		},

		{
		sprite_S178width,sprite_S178height,sprite_S178Bitmap,
		},

		{
		sprite_S179width,sprite_S179height,sprite_S179Bitmap,
		},

		{
		sprite_S180width,sprite_S180height,sprite_S180Bitmap,
		},

		{
		sprite_S181width,sprite_S181height,sprite_S181Bitmap,
		},

		{
		sprite_S182width,sprite_S182height,sprite_S182Bitmap,
		},

		{
		sprite_S183width,sprite_S183height,sprite_S183Bitmap,
		},

		{
		sprite_S184width,sprite_S184height,sprite_S184Bitmap,
		},

		{
		sprite_S185width,sprite_S185height,sprite_S185Bitmap,
		},

		{
		sprite_S186width,sprite_S186height,sprite_S186Bitmap,
		},

		{
		sprite_S187width,sprite_S187height,sprite_S187Bitmap,
		},

		{
		sprite_S188width,sprite_S188height,sprite_S188Bitmap,
		},

		{
		sprite_S189width,sprite_S189height,sprite_S189Bitmap,
		},

		{
		sprite_S190width,sprite_S190height,sprite_S190Bitmap,
		},

		{
		sprite_S191width,sprite_S191height,sprite_S191Bitmap,
		},

		{
		sprite_S192width,sprite_S192height,sprite_S192Bitmap,
		},

		{
		sprite_S193width,sprite_S193height,sprite_S193Bitmap,
		},

		{
		sprite_S194width,sprite_S194height,sprite_S194Bitmap,
		},

		{
		sprite_S195width,sprite_S195height,sprite_S195Bitmap,
		},

		{
		sprite_S196width,sprite_S196height,sprite_S196Bitmap,
		},

		{
		sprite_S197width,sprite_S197height,sprite_S197Bitmap,
		},

		{
		sprite_S198width,sprite_S198height,sprite_S198Bitmap,
		},

		{
		sprite_S199width,sprite_S199height,sprite_S199Bitmap,
		},

		{
		sprite_S200width,sprite_S200height,sprite_S200Bitmap,
		},

		{
		sprite_S201width,sprite_S201height,sprite_S201Bitmap,
		},

		{
		sprite_S202width,sprite_S202height,sprite_S202Bitmap,
		},

		{
		sprite_S203width,sprite_S203height,sprite_S203Bitmap,
		},

		{
		sprite_S204width,sprite_S204height,sprite_S204Bitmap,
		},

		{
		sprite_S205width,sprite_S205height,sprite_S205Bitmap,
		},

		{
		sprite_S206width,sprite_S206height,sprite_S206Bitmap,
		},

		{
		sprite_S207width,sprite_S207height,sprite_S207Bitmap,
		},

		{
		sprite_S208width,sprite_S208height,sprite_S208Bitmap,
		},

		{
		sprite_S209width,sprite_S209height,sprite_S209Bitmap,
		},

		{
		sprite_S210width,sprite_S210height,sprite_S210Bitmap,
		},

		{
		sprite_S211width,sprite_S211height,sprite_S211Bitmap,
		},

		{
		sprite_S212width,sprite_S212height,sprite_S212Bitmap,
		},

		{
		sprite_S213width,sprite_S213height,sprite_S213Bitmap,
		},

		{
		sprite_S214width,sprite_S214height,sprite_S214Bitmap,
		},
 
		{
		sprite_S215width,sprite_S215height,sprite_S215Bitmap,
		},

		{
		sprite_S216width,sprite_S216height,sprite_S216Bitmap,
		},

		{
		sprite_S217width,sprite_S217height,sprite_S217Bitmap,
		},

		{
		sprite_S218width,sprite_S218height,sprite_S218Bitmap,
		},

		{
		sprite_S219width,sprite_S219height,sprite_S219Bitmap,
		},

		{
		sprite_S220width,sprite_S220height,sprite_S220Bitmap,
		},

		{
		sprite_S221width,sprite_S221height,sprite_S221Bitmap,
		},

		{
		sprite_S222width,sprite_S222height,sprite_S222Bitmap,
		},

		{
		sprite_S223width,sprite_S223height,sprite_S223Bitmap,
		},

		{
		sprite_S224width,sprite_S224height,sprite_S224Bitmap,
		},

		{
		sprite_S225width,sprite_S225height,sprite_S225Bitmap,
		},

		{
		sprite_S226width,sprite_S226height,sprite_S226Bitmap,
		},

		{
		sprite_S227width,sprite_S227height,sprite_S227Bitmap,
		},

		{
		sprite_S228width,sprite_S228height,sprite_S228Bitmap,
		},

		{
		sprite_S229width,sprite_S229height,sprite_S229Bitmap,
		},

		{
		sprite_S230width,sprite_S230height,sprite_S230Bitmap,
		},

		{
		sprite_S231width,sprite_S231height,sprite_S231Bitmap,
		},

		{
		sprite_S232width,sprite_S232height,sprite_S232Bitmap,
		},

		{
		sprite_S233width,sprite_S233height,sprite_S233Bitmap,
		},

		{
		sprite_S234width,sprite_S234height,sprite_S234Bitmap,
		},

		{
		sprite_S235width,sprite_S235height,sprite_S235Bitmap,
		},

		{
		sprite_S236width,sprite_S236height,sprite_S236Bitmap,
		},

		{
		sprite_S237width,sprite_S237height,sprite_S237Bitmap,
		},

		{
		sprite_S238width,sprite_S238height,sprite_S238Bitmap,
		},

		{
		sprite_S239width,sprite_S239height,sprite_S239Bitmap,
		},

		{
		sprite_S240width,sprite_S240height,sprite_S240Bitmap,
		},

		{
		sprite_S241width,sprite_S241height,sprite_S241Bitmap,
		},

		{
		sprite_S242width,sprite_S242height,sprite_S242Bitmap,
		},

		{
		sprite_S243width,sprite_S243height,sprite_S243Bitmap,
		},

		{
		sprite_S244width,sprite_S244height,sprite_S244Bitmap,
		},

		{
		sprite_S245width,sprite_S245height,sprite_S245Bitmap,
		},

		{
		sprite_S246width,sprite_S246height,sprite_S246Bitmap,
		},

		{
		sprite_S247width,sprite_S247height,sprite_S247Bitmap,
		},

		{
		sprite_S248width,sprite_S248height,sprite_S248Bitmap,
		},

		{
		sprite_S249width,sprite_S249height,sprite_S249Bitmap,
		},

		{
		sprite_S250width,sprite_S250height,sprite_S250Bitmap,
		},

		{
		sprite_S251width,sprite_S251height,sprite_S251Bitmap,
		},

		{
		sprite_S252width,sprite_S252height,sprite_S252Bitmap,
		},

		{
		sprite_S253width,sprite_S253height,sprite_S253Bitmap,
		},

		{
		sprite_S254width,sprite_S254height,sprite_S254Bitmap,
		},

		{
		sprite_S255width,sprite_S255height,sprite_S255Bitmap,
		},

		{
		sprite_S256width,sprite_S256height,sprite_S256Bitmap,
		},

		{
		sprite_S257width,sprite_S257height,sprite_S257Bitmap,
		},

		{
		sprite_S258width,sprite_S258height,sprite_S258Bitmap,
		},

		{
		sprite_S259width,sprite_S259height,sprite_S259Bitmap,
		},

		{
		sprite_S260width,sprite_S260height,sprite_S260Bitmap,
		},

		{
		sprite_S261width,sprite_S261height,sprite_S261Bitmap,
		},

		{
		sprite_S262width,sprite_S262height,sprite_S262Bitmap,
		},

		{
		sprite_S263width,sprite_S263height,sprite_S263Bitmap,
		},

		{
		sprite_S264width,sprite_S264height,sprite_S264Bitmap,
		},

		{
		sprite_S265width,sprite_S265height,sprite_S265Bitmap,
		},

		{
		sprite_S266width,sprite_S266height,sprite_S266Bitmap,
		},

		{
		sprite_S267width,sprite_S267height,sprite_S267Bitmap,
		},

		{
		sprite_S268width,sprite_S268height,sprite_S268Bitmap,
		},

		{
		sprite_S269width,sprite_S269height,sprite_S269Bitmap,
		},

		{
		sprite_S270width,sprite_S270height,sprite_S270Bitmap,
		},

		{
		sprite_S271width,sprite_S271height,sprite_S271Bitmap,
		},

		{
		sprite_S272width,sprite_S272height,sprite_S272Bitmap,
		},

		{
		sprite_S273width,sprite_S273height,sprite_S273Bitmap,
		},

		{
		sprite_S274width,sprite_S274height,sprite_S274Bitmap,
		},

		{
		sprite_S275width,sprite_S275height,sprite_S275Bitmap,
		},

		{
		sprite_S276width,sprite_S276height,sprite_S276Bitmap,
		},

		{
		sprite_S277width,sprite_S277height,sprite_S277Bitmap,
		},

		{
		sprite_S278width,sprite_S278height,sprite_S278Bitmap,
		},

		{
		sprite_S279width,sprite_S279height,sprite_S279Bitmap,
		},

		{
		sprite_S280width,sprite_S280height,sprite_S280Bitmap,
		},

		{
		sprite_S281width,sprite_S281height,sprite_S281Bitmap,
		},

		{
		sprite_S282width,sprite_S282height,sprite_S282Bitmap,
		},

		{
		sprite_S283width,sprite_S283height,sprite_S283Bitmap,
		},

		{
		sprite_S284width,sprite_S284height,sprite_S284Bitmap,
		},

		{
		sprite_S285width,sprite_S285height,sprite_S285Bitmap,
		},

		{
		sprite_S286width,sprite_S286height,sprite_S286Bitmap,
		},

		{
		sprite_S287width,sprite_S287height,sprite_S287Bitmap,
		},

		{
		sprite_S288width,sprite_S288height,sprite_S288Bitmap,
		},

		{
		sprite_S289width,sprite_S289height,sprite_S289Bitmap,
		},

		{
		sprite_S290width,sprite_S290height,sprite_S290Bitmap,
		},

		{
		sprite_S291width,sprite_S291height,sprite_S291Bitmap,
		},

		{
		sprite_S292width,sprite_S292height,sprite_S292Bitmap,
		},

		{
		sprite_S293width,sprite_S293height,sprite_S293Bitmap,
		},

		{
		sprite_S294width,sprite_S294height,sprite_S294Bitmap,
		},

		{
		sprite_S295width,sprite_S295height,sprite_S295Bitmap,
		},

		{
		sprite_S296width,sprite_S296height,sprite_S296Bitmap,
		},

		{
		sprite_S297width,sprite_S297height,sprite_S297Bitmap,
		},

		{
		sprite_S298width,sprite_S298height,sprite_S298Bitmap,
		},

		{
		sprite_S299width,sprite_S299height,sprite_S299Bitmap,
		},

		{
		sprite_S300width,sprite_S300height,sprite_S300Bitmap,
		},

		{
		sprite_S301width,sprite_S301height,sprite_S301Bitmap,
		},

		{
		sprite_S302width,sprite_S302height,sprite_S302Bitmap,
		},

		{
		sprite_S303width,sprite_S303height,sprite_S303Bitmap,
		},

		{
		sprite_S304width,sprite_S304height,sprite_S304Bitmap,
		},

		{
		sprite_S305width,sprite_S305height,sprite_S305Bitmap,
		},

		{
		sprite_S306width,sprite_S306height,sprite_S306Bitmap,
		},

		{
		sprite_S307width,sprite_S307height,sprite_S307Bitmap,
		},

		{
		sprite_S308width,sprite_S308height,sprite_S308Bitmap,
		},

		{
		sprite_S309width,sprite_S309height,sprite_S309Bitmap,
		},

		{
		sprite_S310width,sprite_S310height,sprite_S310Bitmap,
		},

		{
		sprite_S311width,sprite_S311height,sprite_S311Bitmap,
		},

		{
		sprite_S312width,sprite_S312height,sprite_S312Bitmap,
		},

		{
		sprite_S313width,sprite_S313height,sprite_S313Bitmap,
		},

		{
		sprite_S314width,sprite_S314height,sprite_S314Bitmap,
		},
 
		{
		sprite_S315width,sprite_S315height,sprite_S315Bitmap,
		},

		{
		sprite_S316width,sprite_S316height,sprite_S316Bitmap,
		},

		{
		sprite_S317width,sprite_S317height,sprite_S317Bitmap,
		},

		{
		sprite_S318width,sprite_S318height,sprite_S318Bitmap,
		},

		{
		sprite_S319width,sprite_S319height,sprite_S319Bitmap,
		},

		{
		sprite_S320width,sprite_S320height,sprite_S320Bitmap,
		},

		{
		sprite_S321width,sprite_S321height,sprite_S321Bitmap,
		},

		{
		sprite_S322width,sprite_S322height,sprite_S322Bitmap,
		},

		{
		sprite_S323width,sprite_S323height,sprite_S323Bitmap,
		},

		{
		sprite_S324width,sprite_S324height,sprite_S324Bitmap,
		},

		{
		sprite_S325width,sprite_S325height,sprite_S325Bitmap,
		},

		{
		sprite_S326width,sprite_S326height,sprite_S326Bitmap,
		},

		{
		sprite_S327width,sprite_S327height,sprite_S327Bitmap,
		},

		{
		sprite_S328width,sprite_S328height,sprite_S328Bitmap,
		},

		{
		sprite_S329width,sprite_S329height,sprite_S329Bitmap,
		},

		{
		sprite_S330width,sprite_S330height,sprite_S330Bitmap,
		},

		{
		sprite_S331width,sprite_S331height,sprite_S331Bitmap,
		},

		{
		sprite_S332width,sprite_S332height,sprite_S332Bitmap,
		},

		{
		sprite_S333width,sprite_S333height,sprite_S333Bitmap,
		},

		{
		sprite_S333width,sprite_S333height,sprite_S333Bitmap,
		},

		{
		sprite_S334width,sprite_S334height,sprite_S334Bitmap,
		},

		{
		sprite_S335width,sprite_S335height,sprite_S335Bitmap,
		},

		{
		sprite_S336width,sprite_S336height,sprite_S336Bitmap,
		},

		{
		sprite_S337width,sprite_S337height,sprite_S337Bitmap,
		},

		{
		sprite_S338width,sprite_S338height,sprite_S338Bitmap,
		},

		{
		sprite_S339width,sprite_S339height,sprite_S339Bitmap,
		},

		{
		sprite_S340width,sprite_S340height,sprite_S340Bitmap,
		},

		{
		sprite_S341width,sprite_S341height,sprite_S341Bitmap,
		},

		{
		sprite_S342width,sprite_S342height,sprite_S342Bitmap,
		},

		{
		sprite_S343width,sprite_S343height,sprite_S343Bitmap,
		},

		{
		sprite_S344width,sprite_S344height,sprite_S344Bitmap,
		},

		{
		sprite_S345width,sprite_S345height,sprite_S345Bitmap,
		},

		{
		sprite_S346width,sprite_S346height,sprite_S346Bitmap,
		},

		{
		sprite_S347width,sprite_S347height,sprite_S347Bitmap,
		},

		{
		sprite_S348width,sprite_S348height,sprite_S348Bitmap,
		},

		{
		sprite_S349width,sprite_S349height,sprite_S349Bitmap,
		},

		{
		sprite_S350width,sprite_S350height,sprite_S350Bitmap,
		},

		{
		sprite_S351width,sprite_S351height,sprite_S351Bitmap,
		},

		{
		sprite_S352width,sprite_S352height,sprite_S352Bitmap,
		},

		{
		sprite_S353width,sprite_S353height,sprite_S353Bitmap,
		},

		{
		sprite_S354width,sprite_S354height,sprite_S354Bitmap,
		},

		{
		sprite_S355width,sprite_S355height,sprite_S355Bitmap,
		},

		{
		sprite_S356width,sprite_S356height,sprite_S356Bitmap,
		},

		{
		sprite_S357width,sprite_S357height,sprite_S357Bitmap,
		},

		{
		sprite_S358width,sprite_S358height,sprite_S358Bitmap,
		},

		{
		sprite_S359width,sprite_S359height,sprite_S359Bitmap,
		},

		{
		sprite_S360width,sprite_S360height,sprite_S360Bitmap,
		},

		{
		sprite_S361width,sprite_S361height,sprite_S361Bitmap,
		},

		{
		sprite_S362width,sprite_S362height,sprite_S362Bitmap,
		},

		{
		sprite_S363width,sprite_S363height,sprite_S363Bitmap,
		},

		{
		sprite_S364width,sprite_S364height,sprite_S364Bitmap,
		},

		{
		sprite_S365width,sprite_S365height,sprite_S365Bitmap,
		},

		{
		sprite_S366width,sprite_S366height,sprite_S366Bitmap,
		},

		{
		sprite_S367width,sprite_S367height,sprite_S367Bitmap,
		},

		{
		sprite_S368width,sprite_S368height,sprite_S368Bitmap,
		},

		{
		sprite_S369width,sprite_S369height,sprite_S369Bitmap,
		},

		{
		sprite_S370width,sprite_S370height,sprite_S370Bitmap,
		},

		{
		sprite_S371width,sprite_S371height,sprite_S371Bitmap,
		},

		{
		sprite_S372width,sprite_S372height,sprite_S372Bitmap,
		},

		{
		sprite_S373width,sprite_S373height,sprite_S373Bitmap,
		},

		{
		sprite_S374width,sprite_S374height,sprite_S374Bitmap,
		},

		{
		sprite_S375width,sprite_S375height,sprite_S375Bitmap,
		},

		{
		sprite_S376width,sprite_S376height,sprite_S376Bitmap,
		},

		{
		sprite_S377width,sprite_S377height,sprite_S377Bitmap,
		},

		{
		sprite_S378width,sprite_S378height,sprite_S378Bitmap,
		},

		{
		sprite_S379width,sprite_S379height,sprite_S379Bitmap,
		},

		{
		sprite_S380width,sprite_S380height,sprite_S380Bitmap,
		},

		{
		sprite_S381width,sprite_S381height,sprite_S381Bitmap,
		},

		{
		sprite_S382width,sprite_S382height,sprite_S382Bitmap,
		},

		{
		sprite_S383width,sprite_S383height,sprite_S383Bitmap,
		},

		{
		sprite_S384width,sprite_S384height,sprite_S384Bitmap,
		},

		{
		sprite_S385width,sprite_S385height,sprite_S385Bitmap,
		},

		{
		sprite_S386width,sprite_S386height,sprite_S386Bitmap,
		},

		{
		sprite_S387width,sprite_S387height,sprite_S387Bitmap,
		},

		{
		sprite_S388width,sprite_S388height,sprite_S388Bitmap,
		},

		{
		sprite_S389width,sprite_S389height,sprite_S389Bitmap,
		},

		{
		sprite_S390width,sprite_S390height,sprite_S390Bitmap,
		},

		{
		sprite_S391width,sprite_S391height,sprite_S391Bitmap,
		},

		{
		sprite_S392width,sprite_S392height,sprite_S392Bitmap,
		},

		{
		sprite_S393width,sprite_S393height,sprite_S393Bitmap,
		},

		{
		sprite_S394width,sprite_S394height,sprite_S394Bitmap,
		},

		{
		sprite_S395width,sprite_S395height,sprite_S395Bitmap,
		},

		{
		sprite_S396width,sprite_S396height,sprite_S396Bitmap,
		},

		{
		sprite_S397width,sprite_S397height,sprite_S397Bitmap,
		},

		{
		sprite_S398width,sprite_S398height,sprite_S398Bitmap,
		},

		{
		sprite_S399width,sprite_S399height,sprite_S399Bitmap,
		},

		{
		sprite_S400width,sprite_S400height,sprite_S400Bitmap,
		},

		{
		sprite_S401width,sprite_S401height,sprite_S401Bitmap,
		},

		{
		sprite_S402width,sprite_S402height,sprite_S402Bitmap,
		},

		{
		sprite_S403width,sprite_S403height,sprite_S403Bitmap,
		},

		{
		sprite_S404width,sprite_S404height,sprite_S404Bitmap,
		},

		{
		sprite_S405width,sprite_S405height,sprite_S405Bitmap,
		},

		{
		sprite_S406width,sprite_S406height,sprite_S406Bitmap,
		},

		{
		sprite_S407width,sprite_S407height,sprite_S407Bitmap,
		},

		{
		sprite_S408width,sprite_S408height,sprite_S408Bitmap,
		},

		{
		sprite_S409width,sprite_S409height,sprite_S409Bitmap,
		},

		{
		sprite_S410width,sprite_S410height,sprite_S410Bitmap,
		},

		{
		sprite_S411width,sprite_S411height,sprite_S411Bitmap,
		},

		{
		sprite_S412width,sprite_S412height,sprite_S412Bitmap,
		},

		{
		sprite_S413width,sprite_S413height,sprite_S413Bitmap,
		},

		{
		sprite_S414width,sprite_S414height,sprite_S414Bitmap,
		},
 
		{
		sprite_S415width,sprite_S415height,sprite_S415Bitmap,
		},

		{
		sprite_S416width,sprite_S416height,sprite_S416Bitmap,
		},

		{
		sprite_S417width,sprite_S417height,sprite_S417Bitmap,
		},

		{
		sprite_S418width,sprite_S418height,sprite_S418Bitmap,
		},

		{
		sprite_S419width,sprite_S419height,sprite_S419Bitmap,
		},

		{
		sprite_S420width,sprite_S420height,sprite_S420Bitmap,
		},

		{
		sprite_999width,sprite_999height,sprite_999Bitmap,
		}

				};



	long	spool_index[]={

	spool_index1,spool_index1,spool_index1,spool_index1,spool_index1,spool_index1,spool_index1,spool_index1,
	spool_index2,spool_index2,spool_index2,spool_index2,spool_index2,spool_index2,spool_index2,spool_index2,
	spool_index3,spool_index3,spool_index3,spool_index3,spool_index3,spool_index3,spool_index3,spool_index3,
	spool_index4,spool_index4,spool_index4,spool_index4,spool_index4,spool_index4,spool_index4,spool_index4,
	spool_index5,spool_index5,spool_index5,spool_index5,spool_index5,spool_index5,spool_index5,spool_index5,
	spool_index6,spool_index6,spool_index6,spool_index6,spool_index6,spool_index6,spool_index6,spool_index6,
	spool_index7,spool_index7,spool_index7,spool_index7,spool_index7,spool_index7,spool_index7,spool_index7,
	spool_index8,spool_index8,spool_index8,spool_index8,spool_index8,spool_index8,spool_index8,spool_index8,
	spool_index9,spool_index9,spool_index9,spool_index9,spool_index9,spool_index9,spool_index9,spool_index9,
	spool_index10,spool_index10,spool_index10,spool_index10,spool_index10,spool_index10,spool_index10,spool_index10,
	spool_index11,spool_index11,spool_index11,spool_index11,spool_index11,spool_index11,spool_index11,spool_index11,
	spool_index12,spool_index12,spool_index12,spool_index12,spool_index12,spool_index12,spool_index12,spool_index12,
	spool_index13,spool_index13,spool_index13,spool_index13,spool_index13,spool_index13,spool_index13,spool_index13,
	spool_index14,spool_index14,spool_index14,spool_index14,spool_index14,spool_index14,spool_index14,spool_index14,
	spool_index15,spool_index15,spool_index15,spool_index15,spool_index15,spool_index15,spool_index15,spool_index15,
	spool_index16,spool_index16,spool_index16,spool_index16,spool_index16,spool_index16,spool_index16,spool_index16,
	spool_index17,spool_index17,spool_index17,spool_index17,spool_index17,spool_index17,spool_index17,spool_index17,
	spool_index18,spool_index18,spool_index18,spool_index18,spool_index18,spool_index18,spool_index18,spool_index18,
	spool_index19,spool_index19,spool_index19,spool_index19,spool_index19,spool_index19,spool_index19,spool_index19,
	spool_index20,spool_index20,spool_index20,spool_index20,spool_index20,spool_index20,spool_index20,spool_index20,
	spool_index21,spool_index21,spool_index21,spool_index21,spool_index21,spool_index21,spool_index21,spool_index21,
	spool_index22,spool_index22,spool_index22,spool_index22,spool_index22,spool_index22,spool_index22,spool_index22,
	spool_index23,spool_index23,spool_index23,spool_index23,spool_index23,spool_index23,spool_index23,spool_index23,
	spool_index24,spool_index24,spool_index24,spool_index24,spool_index24,spool_index24,spool_index24,spool_index24,
	spool_index25,spool_index25,spool_index25,spool_index25,spool_index25,spool_index25,spool_index25,spool_index25,
	spool_index26,spool_index26,spool_index26,spool_index26,spool_index26,spool_index26,spool_index26,spool_index26,
	spool_index27,spool_index27,spool_index27,spool_index27,spool_index27,spool_index27,spool_index27,spool_index27,
	spool_index28,spool_index28,spool_index28,spool_index28,spool_index28,spool_index28,spool_index28,spool_index28,
	spool_index29,spool_index29,spool_index29,spool_index29,spool_index29,spool_index29,spool_index29,spool_index29,
	spool_index30,spool_index30,spool_index30,spool_index30,spool_index30,spool_index30,spool_index30,spool_index30,
	spool_index31,spool_index31,spool_index31,spool_index31,spool_index31,spool_index31,spool_index31,spool_index31,
	spool_index32,spool_index32,spool_index32,spool_index32,spool_index32,spool_index32,spool_index32,spool_index32,
	spool_index33,spool_index33,spool_index33,spool_index33,spool_index33,spool_index33,spool_index33,spool_index33,
	spool_index34,spool_index34,spool_index34,spool_index34,spool_index34,spool_index34,spool_index34,spool_index34,
	spool_index35,spool_index35,spool_index35,spool_index35,spool_index35,spool_index35,spool_index35,spool_index35,
	spool_index36,spool_index36,spool_index36,spool_index36,spool_index36,spool_index36,spool_index36,spool_index36,
	spool_index37,spool_index37,spool_index37,spool_index37,spool_index37,spool_index37,spool_index37,spool_index37,
	spool_index38,spool_index38,spool_index38,spool_index38,spool_index38,spool_index38,spool_index38,spool_index38,
	spool_index39,spool_index39,spool_index39,spool_index39,spool_index39,spool_index39,spool_index39,spool_index39,
	spool_index40,spool_index40,spool_index40,spool_index40,spool_index40,spool_index40,spool_index40,spool_index40,
	spool_index41,spool_index41,spool_index41,spool_index41,spool_index41,spool_index41,spool_index41,spool_index41,
	spool_index42,spool_index42,spool_index42,spool_index42,spool_index42,spool_index42,spool_index42,spool_index42,
	spool_index43,spool_index43,spool_index43,spool_index43,spool_index43,spool_index43,spool_index43,spool_index43,
	spool_index44,spool_index44,spool_index44,spool_index44,spool_index44,spool_index44,spool_index44,spool_index44,
	spool_index45,spool_index45,spool_index45,spool_index45,spool_index45,spool_index45,spool_index45,spool_index45,
	
			      };


	long	spool_index_small[]={

	spool_index1s,spool_index1s,spool_index1s,spool_index1s,spool_index1s,spool_index1s,spool_index1s,spool_index1s,
	spool_index2s,spool_index2s,spool_index2s,spool_index2s,spool_index2s,spool_index2s,spool_index2s,spool_index2s,
	spool_index3s,spool_index3s,spool_index3s,spool_index3s,spool_index3s,spool_index3s,spool_index3s,spool_index3s,
	spool_index4s,spool_index4s,spool_index4s,spool_index4s,spool_index4s,spool_index4s,spool_index4s,spool_index4s,
	spool_index5s,spool_index5s,spool_index5s,spool_index5s,spool_index5s,spool_index5s,spool_index5s,spool_index5s,
	spool_index6s,spool_index6s,spool_index6s,spool_index6s,spool_index6s,spool_index6s,spool_index6s,spool_index6s,
	spool_index7s,spool_index7s,spool_index7s,spool_index7s,spool_index7s,spool_index7s,spool_index7s,spool_index7s,
	spool_index8s,spool_index8s,spool_index8s,spool_index8s,spool_index8s,spool_index8s,spool_index8s,spool_index8s,
	spool_index9s,spool_index9s,spool_index9s,spool_index9s,spool_index9s,spool_index9s,spool_index9s,spool_index9s,
	spool_index10s,spool_index10s,spool_index10s,spool_index10s,spool_index10s,spool_index10s,spool_index10s,spool_index10s,
	spool_index11s,spool_index11s,spool_index11s,spool_index11s,spool_index11s,spool_index11s,spool_index11s,spool_index11s,
	spool_index12s,spool_index12s,spool_index12s,spool_index12s,spool_index12s,spool_index12s,spool_index12s,spool_index12s,
	spool_index13s,spool_index13s,spool_index13s,spool_index13s,spool_index13s,spool_index13s,spool_index13s,spool_index13s,
	spool_index14s,spool_index14s,spool_index14s,spool_index14s,spool_index14s,spool_index14s,spool_index14s,spool_index14s,
	spool_index15s,spool_index15s,spool_index15s,spool_index15s,spool_index15s,spool_index15s,spool_index15s,spool_index15s,
	spool_index16s,spool_index16s,spool_index16s,spool_index16s,spool_index16s,spool_index16s,spool_index16s,spool_index16s,
	spool_index17s,spool_index17s,spool_index17s,spool_index17s,spool_index17s,spool_index17s,spool_index17s,spool_index17s,
	spool_index18s,spool_index18s,spool_index18s,spool_index18s,spool_index18s,spool_index18s,spool_index18s,spool_index18s,
	spool_index19s,spool_index19s,spool_index19s,spool_index19s,spool_index19s,spool_index19s,spool_index19s,spool_index19s,
	spool_index20s,spool_index20s,spool_index20s,spool_index20s,spool_index20s,spool_index20s,spool_index20s,spool_index20s,
	spool_index21s,spool_index21s,spool_index21s,spool_index21s,spool_index21s,spool_index21s,spool_index21s,spool_index21s,
	spool_index22s,spool_index22s,spool_index22s,spool_index22s,spool_index22s,spool_index22s,spool_index22s,spool_index22s,
	spool_index23s,spool_index23s,spool_index23s,spool_index23s,spool_index23s,spool_index23s,spool_index23s,spool_index23s,
	spool_index24s,spool_index24s,spool_index24s,spool_index24s,spool_index24s,spool_index24s,spool_index24s,spool_index24s,
	spool_index25s,spool_index25s,spool_index25s,spool_index25s,spool_index25s,spool_index25s,spool_index25s,spool_index25s,
	spool_index26s,spool_index26s,spool_index26s,spool_index26s,spool_index26s,spool_index26s,spool_index26s,spool_index26s,
	spool_index27s,spool_index27s,spool_index27s,spool_index27s,spool_index27s,spool_index27s,spool_index27s,spool_index27s,
	spool_index28s,spool_index28s,spool_index28s,spool_index28s,spool_index28s,spool_index28s,spool_index28s,spool_index28s,
	spool_index29s,spool_index29s,spool_index29s,spool_index29s,spool_index29s,spool_index29s,spool_index29s,spool_index29s,
	spool_index30s,spool_index30s,spool_index30s,spool_index30s,spool_index30s,spool_index30s,spool_index30s,spool_index30s,
	spool_index31s,spool_index31s,spool_index31s,spool_index31s,spool_index31s,spool_index31s,spool_index31s,spool_index31s,
	spool_index32s,spool_index32s,spool_index32s,spool_index32s,spool_index32s,spool_index32s,spool_index32s,spool_index32s,
	spool_index33s,spool_index33s,spool_index33s,spool_index33s,spool_index33s,spool_index33s,spool_index33s,spool_index33s,
	spool_index34s,spool_index34s,spool_index34s,spool_index34s,spool_index34s,spool_index34s,spool_index34s,spool_index34s,
	spool_index35s,spool_index35s,spool_index35s,spool_index35s,spool_index35s,spool_index35s,spool_index35s,spool_index35s,
	spool_index36s,spool_index36s,spool_index36s,spool_index36s,spool_index36s,spool_index36s,spool_index36s,spool_index36s,
	spool_index37s,spool_index37s,spool_index37s,spool_index37s,spool_index37s,spool_index37s,spool_index37s,spool_index37s,
	spool_index38s,spool_index38s,spool_index38s,spool_index38s,spool_index38s,spool_index38s,spool_index38s,spool_index38s,
	spool_index39s,spool_index39s,spool_index39s,spool_index39s,spool_index39s,spool_index39s,spool_index39s,spool_index39s,
	spool_index40s,spool_index40s,spool_index40s,spool_index40s,spool_index40s,spool_index40s,spool_index40s,spool_index40s,
	spool_index41s,spool_index41s,spool_index41s,spool_index41s,spool_index41s,spool_index41s,spool_index41s,spool_index41s,
	spool_index42s,spool_index42s,spool_index42s,spool_index42s,spool_index42s,spool_index42s,spool_index42s,spool_index42s,
	spool_index43s,spool_index43s,spool_index43s,spool_index43s,spool_index43s,spool_index43s,spool_index43s,spool_index43s,
	spool_index44s,spool_index44s,spool_index44s,spool_index44s,spool_index44s,spool_index44s,spool_index44s,spool_index44s,
	spool_index45s,spool_index45s,spool_index45s,spool_index45s,spool_index45s,spool_index45s,spool_index45s,spool_index45s,
	
			      };














sprite		sprite_table_small[]={				       	 
								 
		{
		sprite1width_s,sprite1height_s,sprite1Bitmap_s,
		},

		{
		sprite1awidth_s,sprite1aheight_s,sprite1aBitmap_s,
		},

		{
		sprite1bwidth_s,sprite1bheight_s,sprite1bBitmap_s,
		},

		{
		sprite2width_s,sprite2height_s,sprite2Bitmap_s,
		},

		{
		sprite3width_s,sprite3height_s,sprite3Bitmap_s,
		},

		{
		sprite4width_s,sprite4height_s,sprite4Bitmap_s,
		},

		{
		sprite5width_s,sprite5height_s,sprite5Bitmap_s,
		},

		{
		sprite6width_s,sprite6height_s,sprite6Bitmap_s,
		},

		{
		sprite7width_s,sprite7height_s,sprite7Bitmap_s,
		},

		{
		sprite8width_s,sprite8height_s,sprite8Bitmap_s,
		},

		{
		sprite9width_s,sprite9height_s,sprite9Bitmap_s,
		},

		{
		sprite10width_s,sprite10height_s,sprite10Bitmap_s,
		},

		{
		sprite11width_s,sprite11height_s,sprite11Bitmap_s,
		},

		{
		sprite12width_s,sprite12height_s,sprite12Bitmap_s,
		},

		{
		sprite13width_s,sprite13height_s,sprite13Bitmap_s,
		},

		{
		sprite14width_s,sprite14height_s,sprite14Bitmap_s,
		},

		{
		sprite15width_s,sprite15height_s,sprite15Bitmap_s,
		},

		{
		sprite16width_s,sprite16height_s,sprite16Bitmap_s,
		},

		{
		sprite17width_s,sprite17height_s,sprite17Bitmap_s,
		},

		{
		sprite18width_s,sprite18height_s,sprite18Bitmap_s,
		},

		{
		sprite19width_s,sprite19height_s,sprite19Bitmap_s,
		},

		{
		sprite20width_s,sprite20height_s,sprite20Bitmap_s,
		},

		{
		sprite21width_s,sprite21height_s,sprite21Bitmap_s,
		},

		{
		sprite22width_s,sprite22height_s,sprite22Bitmap_s,
		},

		{
		sprite23width_s,sprite23height_s,sprite23Bitmap_s,
		},

		{
		sprite24width_s,sprite24height_s,sprite24Bitmap_s,
		},
	
		{
		sprite25width_s,sprite25height_s,sprite25Bitmap_s,
		},

		{
		sprite26width_s,sprite26height_s,sprite26Bitmap_s,
		},

		{
		sprite27width_s,sprite27height_s,sprite27Bitmap_s,
		},

		{
		sprite28width_s,sprite28height_s,sprite28Bitmap_s,
		},

		{
		sprite29width_s,sprite29height_s,sprite29Bitmap_s,
		},

		{
		sprite30width_s,sprite30height_s,sprite30Bitmap_s,
		},

		{
		sprite31width_s,sprite31height_s,sprite31Bitmap_s,
		},

		{
		sprite32width_s,sprite32height_s,sprite32Bitmap_s,
		},

		{
		sprite33width_s,sprite33height_s,sprite33Bitmap_s,
		},

		{
		sprite34width_s,sprite34height_s,sprite34Bitmap_s,
		},

		{
		sprite35width_s,sprite35height_s,sprite35Bitmap_s,
		},

		{
		sprite36width_s,sprite36height_s,sprite36Bitmap_s,
		},

		{
		sprite37width_s,sprite37height_s,sprite37Bitmap_s,
		},

		{
		sprite38width_s,sprite38height_s,sprite38Bitmap_s,
		},

		{
		sprite39width_s,sprite39height_s,sprite39Bitmap_s,
		},

		{
		sprite40width_s,sprite40height_s,sprite40Bitmap_s,
		},

		{
		sprite41width_s,sprite41height_s,sprite41Bitmap_s,
		},

		{
		sprite42width_s,sprite42height_s,sprite42Bitmap_s,
		},

		{
		sprite43width_s,sprite43height_s,sprite43Bitmap_s,
		},

		{
		sprite44width_s,sprite44height_s,sprite44Bitmap_s,
		},

		{
		sprite45width_s,sprite45height_s,sprite45Bitmap_s,
		},

		{
		sprite46width_s,sprite46height_s,sprite46Bitmap_s,
		},

		{
		sprite47width_s,sprite47height_s,sprite47Bitmap_s,
		},

		{
		sprite48width_s,sprite48height_s,sprite48Bitmap_s,
		},

		{
		sprite49width_s,sprite49height_s,sprite49Bitmap_s,
		},

		{
		sprite50width_s,sprite50height_s,sprite50Bitmap_s,
		},

		{
		sprite51width_s,sprite51height_s,sprite51Bitmap_s,
		},

		{
		sprite52width_s,sprite52height_s,sprite52Bitmap_s,
		},

		{
		sprite53width_s,sprite53height_s,sprite53Bitmap_s,
		},

		{
		sprite54width_s,sprite54height_s,sprite54Bitmap_s,
		},

		{
		sprite55width_s,sprite55height_s,sprite55Bitmap_s,
		},

		{
		sprite55Bwidth_s,sprite55Bheight_s,sprite55BBitmap_s,
		},

		{
		sprite55Cwidth_s,sprite55Cheight_s,sprite55CBitmap_s,
		},

		{
		sprite56width_s,sprite56height_s,sprite56Bitmap_s,
		},

		{
		sprite57width_s,sprite57height_s,sprite57Bitmap_s,
		},

		{
		sprite58width_s,sprite58height_s,sprite58Bitmap_s,
		},

		{
		sprite59width_s,sprite59height_s,sprite59Bitmap_s,
		},

		{
		sprite60width_s,sprite60height_s,sprite60Bitmap_s,
		},

		{
		sprite61width_s,sprite61height_s,sprite61Bitmap_s,
		},

		{
		sprite62width_s,sprite62height_s,sprite62Bitmap_s,
		},

		{
		sprite63width_s,sprite63height_s,sprite63Bitmap_s,
		},

		{
		sprite64width_s,sprite64height_s,sprite64Bitmap_s,
		},

		{
		sprite65width_s,sprite65height_s,sprite65Bitmap_s,
		},

		{
		sprite66width_s,sprite66height_s,sprite66Bitmap_s,
		},

		{
		sprite67width_s,sprite67height_s,sprite67Bitmap_s,
		},

		{
		sprite68width_s,sprite68height_s,sprite68Bitmap_s,
		},

		{
		sprite69width_s,sprite69height_s,sprite69Bitmap_s,
		},

		{
		sprite70width_s,sprite70height_s,sprite70Bitmap_s,
		},

		{
		sprite71width_s,sprite71height_s,sprite71Bitmap_s,
		},

		{
		sprite72width_s,sprite72height_s,sprite72Bitmap_s,
		},

		{
		sprite73width_s,sprite73height_s,sprite73Bitmap_s,
		},

		{
		sprite74width_s,sprite74height_s,sprite74Bitmap_s,
		},

		{
		sprite75width_s,sprite75height_s,sprite75Bitmap_s,
		},

		{
		sprite76width_s,sprite76height_s,sprite76Bitmap_s,
		},

		{
		sprite77width_s,sprite77height_s,sprite77Bitmap_s,
		},

		{
		sprite78width_s,sprite78height_s,sprite78Bitmap_s,
		},

		{
		sprite79width_s,sprite79height_s,sprite79Bitmap_s,
		},

		{
		sprite80width_s,sprite80height_s,sprite80Bitmap_s,
		},

		{
		sprite81width_s,sprite81height_s,sprite81Bitmap_s,
		},

		{
		sprite82width_s,sprite82height_s,sprite82Bitmap_s,
		},

		{
		sprite83width_s,sprite83height_s,sprite83Bitmap_s,
		},

		{
		sprite84width_s,sprite84height_s,sprite84Bitmap_s,
		},

		{
		sprite85width_s,sprite85height_s,sprite85Bitmap_s,
		},

		{
		sprite86width_s,sprite86height_s,sprite86Bitmap_s,
		},

		{
		sprite87width_s,sprite87height_s,sprite87Bitmap_s,
		},

		{
		sprite88width_s,sprite88height_s,sprite88Bitmap_s,
		},

		{
		sprite89width_s,sprite89height_s,sprite89Bitmap_s,
		},

		{
		sprite90width_s,sprite90height_s,sprite90Bitmap_s,
		},

		{
		sprite91width_s,sprite91height_s,sprite91Bitmap_s,
		},

		{
		sprite92width_s,sprite92height_s,sprite92Bitmap_s,
		},

		{
		sprite93width_s,sprite93height_s,sprite93Bitmap_s,
		},

		{
		sprite94width_s,sprite94height_s,sprite94Bitmap_s,
		},

		{
		sprite95width_s,sprite95height_s,sprite95Bitmap_s,
		},

		{
		sprite96width_s,sprite96height_s,sprite96Bitmap_s,
		},

		{
		sprite97width_s,sprite97height_s,sprite97Bitmap_s,
		},

		{
		sprite98width_s,sprite98height_s,sprite98Bitmap_s,
		},

		{
		sprite99width_s,sprite99height_s,sprite99Bitmap_s,
		},

		{
		sprite100width_s,sprite100height_s,sprite100Bitmap_s,
		},

		{
		sprite101width_s,sprite101height_s,sprite101Bitmap_s,
		},

		{
		sprite102width_s,sprite102height_s,sprite102Bitmap_s,
		},

		{
		sprite103width_s,sprite103height_s,sprite103Bitmap_s,
		},

		{
		sprite104width_s,sprite104height_s,sprite104Bitmap_s,
		},

		{
		sprite105width_s,sprite105height_s,sprite105Bitmap_s,
		},

		{
		sprite106width_s,sprite106height_s,sprite106Bitmap_s,
		},

		{
		sprite107width_s,sprite107height_s,sprite107Bitmap_s,
		},

		{
		sprite108width_s,sprite108height_s,sprite108Bitmap_s,
		},

		{
		sprite109width_s,sprite109height_s,sprite109Bitmap_s,
		},

		{
		sprite110width_s,sprite110height_s,sprite110Bitmap_s,
		},

		{
		sprite111width_s,sprite111height_s,sprite111Bitmap_s,
		},

		{
		sprite112width_s,sprite112height_s,sprite112Bitmap_s,
		},

		{
		sprite113width_s,sprite113height_s,sprite113Bitmap_s,
		},

		{
		sprite114width_s,sprite114height_s,sprite114Bitmap_s,
		},

		{
		sprite115width_s,sprite115height_s,sprite115Bitmap_s,
		},

		{
		sprite116width_s,sprite116height_s,sprite116Bitmap_s,
		},

		{
		sprite117width_s,sprite117height_s,sprite117Bitmap_s,
		},

		{
		sprite118width_s,sprite118height_s,sprite118Bitmap_s,
		},

		{
		sprite119width_s,sprite119height_s,sprite119Bitmap_s,
		},

		{
		sprite120width_s,sprite120height_s,sprite120Bitmap_s,
		},

		{
		sprite121width_s,sprite121height_s,sprite121Bitmap_s,
		},

		{
		sprite122width_s,sprite122height_s,sprite122Bitmap_s,
		},

		{
		sprite123width_s,sprite123height_s,sprite123Bitmap_s,
		},

		{
		sprite124width_s,sprite124height_s,sprite124Bitmap_s,
		},

		{
		sprite125width_s,sprite125height_s,sprite125Bitmap_s,
		},

		{
		sprite126width_s,sprite126height_s,sprite126Bitmap_s,
		},

		{
		sprite127width_s,sprite127height_s,sprite127Bitmap_s,
		},

		{
		sprite128width_s,sprite128height_s,sprite128Bitmap_s,
		},

		{
		sprite129width_s,sprite129height_s,sprite129Bitmap_s,
		},

		{
		sprite130width_s,sprite130height_s,sprite130Bitmap_s,
		},

		{
		sprite131width_s,sprite131height_s,sprite131Bitmap_s,
		},

		{
		sprite132width_s,sprite132height_s,sprite132Bitmap_s,
		},

		{
		sprite133width_s,sprite133height_s,sprite133Bitmap_s,
		},

		{
		sprite134width_s,sprite134height_s,sprite134Bitmap_s,
		},

		{
		sprite135width_s,sprite135height_s,sprite135Bitmap_s,
		},

		{
		sprite136width_s,sprite136height_s,sprite136Bitmap_s,
		},

		{
		sprite137width_s,sprite137height_s,sprite137Bitmap_s,
		},

		{
		sprite138width_s,sprite138height_s,sprite138Bitmap_s,
		},

		{
		sprite139width_s,sprite139height_s,sprite139Bitmap_s,
		},

		{
		sprite140width_s,sprite140height_s,sprite140Bitmap_s,
		},

		{
		sprite141width_s,sprite141height_s,sprite141Bitmap_s,
		},

		{
		sprite142width_s,sprite142height_s,sprite142Bitmap_s,
		},

		{
		sprite143width_s,sprite143height_s,sprite143Bitmap_s,
		},

		{
		sprite144width_s,sprite144height_s,sprite144Bitmap_s,
		},

		{
		sprite145width_s,sprite145height_s,sprite145Bitmap_s,
		},

		{
		sprite146width_s,sprite146height_s,sprite146Bitmap_s,
		},

		{
		sprite147width_s,sprite147height_s,sprite147Bitmap_s,
		},

		{
		sprite148width_s,sprite148height_s,sprite148Bitmap_s,
		},

		{
		sprite149width_s,sprite149height_s,sprite149Bitmap_s,
		},

		{
		sprite150width_s,sprite150height_s,sprite150Bitmap_s,
		},

//		{
//		sprite151width_s,sprite151height_s,sprite151Bitmap_s,
//		},
//
//		{
//		sprite152width_s,sprite152height_s,sprite152Bitmap_s,
//		},

		{
		sprite_S62width_s,sprite_S62height_s,sprite_S62Bitmap_s,
		},

		{
		sprite_S63width_s,sprite_S63height_s,sprite_S63Bitmap_s,
		},

		{
		sprite_S64width_s,sprite_S64height_s,sprite_S64Bitmap_s,
		},

		{
		sprite_S65width_s,sprite_S65height_s,sprite_S65Bitmap_s,
		},

		{
		sprite_S66width_s,sprite_S66height_s,sprite_S66Bitmap_s,
		},

		{
		sprite_S67width_s,sprite_S67height_s,sprite_S67Bitmap_s,
		},

		{
		sprite_S68width_s,sprite_S68height_s,sprite_S68Bitmap_s,
		},

		{
		sprite_S69width_s,sprite_S69height_s,sprite_S69Bitmap_s,
		},

		{
		sprite_S70width_s,sprite_S70height_s,sprite_S70Bitmap_s,
		},

		{
		sprite_S71width_s,sprite_S71height_s,sprite_S71Bitmap_s,
		},

		{
		sprite_S72width_s,sprite_S72height_s,sprite_S72Bitmap_s,
		},

		{
		sprite_S73width_s,sprite_S73height_s,sprite_S73Bitmap_s,
		},

		{
		sprite_S74width_s,sprite_S74height_s,sprite_S74Bitmap_s,
		},

		{
		sprite_S75width_s,sprite_S75height_s,sprite_S75Bitmap_s,
		},

		{
		sprite_S76width_s,sprite_S76height_s,sprite_S76Bitmap_s,
		},

		{
		sprite_S77width_s,sprite_S77height_s,sprite_S77Bitmap_s,
		},

		{
		sprite_S78width_s,sprite_S78height_s,sprite_S78Bitmap_s,
		},

		{
		sprite_S79width_s,sprite_S79height_s,sprite_S79Bitmap_s,
		},

		{
		sprite_S80width_s,sprite_S80height_s,sprite_S80Bitmap_s,
		},

		{
		sprite_S81width_s,sprite_S81height_s,sprite_S81Bitmap_s,
		},

		{
		sprite_S82width_s,sprite_S82height_s,sprite_S82Bitmap_s,
		},

		{
		sprite_S83width_s,sprite_S83height_s,sprite_S83Bitmap_s,
		},

		{
		sprite_S84width_s,sprite_S84height_s,sprite_S84Bitmap_s,
		},

		{
		sprite_S85width_s,sprite_S85height_s,sprite_S85Bitmap_s,
		},

		{
		sprite_S86width_s,sprite_S86height_s,sprite_S86Bitmap_s,
		},

		{
		sprite_S87width_s,sprite_S87height_s,sprite_S87Bitmap_s,
		},

		{
		sprite_S88width_s,sprite_S88height_s,sprite_S88Bitmap_s,
		},

		{
		sprite_S89width_s,sprite_S89height_s,sprite_S89Bitmap_s,
		},

		{
		sprite_S90width_s,sprite_S90height_s,sprite_S90Bitmap_s,
		},

		{
		sprite_S91width_s,sprite_S91height_s,sprite_S91Bitmap_s,
		},

		{
		sprite_S92width_s,sprite_S92height_s,sprite_S92Bitmap_s,
		},

		{
		sprite_S93width_s,sprite_S93height_s,sprite_S93Bitmap_s,
		},

		{
		sprite_S94width_s,sprite_S94height_s,sprite_S94Bitmap_s,
		},

		{
		sprite_S95width_s,sprite_S95height_s,sprite_S95Bitmap_s,
		},

		{
		sprite_S96width_s,sprite_S96height_s,sprite_S96Bitmap_s,
		},

		{
		sprite_S97width_s,sprite_S97height_s,sprite_S97Bitmap_s,
		},

		{
		sprite_S98width_s,sprite_S98height_s,sprite_S98Bitmap_s,
		},

		{
		sprite_S99width_s,sprite_S99height_s,sprite_S99Bitmap_s,
		},

		{
		sprite_S100width_s,sprite_S100height_s,sprite_S100Bitmap_s,
		},

		{
		sprite_S101width_s,sprite_S101height_s,sprite_S101Bitmap_s,
		},

		{
		sprite_S102width_s,sprite_S102height_s,sprite_S102Bitmap_s,
		},

		{
		sprite_S103width_s,sprite_S103height_s,sprite_S103Bitmap_s,
		},

		{
		sprite_S104width_s,sprite_S104height_s,sprite_S104Bitmap_s,
		},

		{
		sprite_S105width_s,sprite_S105height_s,sprite_S105Bitmap_s,
		},

		{
		sprite_S106width_s,sprite_S106height_s,sprite_S106Bitmap_s,
		},

		{
		sprite_S107width_s,sprite_S107height_s,sprite_S107Bitmap_s,
		},

		{
		sprite_S108width_s,sprite_S108height_s,sprite_S108Bitmap_s,
		},

		{
		sprite_S109width_s,sprite_S109height_s,sprite_S109Bitmap_s,
		},

		{
		sprite_S110width_s,sprite_S110height_s,sprite_S110Bitmap_s,
		},

		{
		sprite_S111width_s,sprite_S111height_s,sprite_S111Bitmap_s,
		},

		{
		sprite_S112width_s,sprite_S112height_s,sprite_S112Bitmap_s,
		},

		{
		sprite_S113width_s,sprite_S113height_s,sprite_S113Bitmap_s,
		},

		{
		sprite_S114width_s,sprite_S114height_s,sprite_S114Bitmap_s,
		},
 
		{
		sprite_S115width_s,sprite_S115height_s,sprite_S115Bitmap_s,
		},

		{
		sprite_S116width_s,sprite_S116height_s,sprite_S116Bitmap_s,
		},

		{
		sprite_S117width_s,sprite_S117height_s,sprite_S117Bitmap_s,
		},

		{
		sprite_S118width_s,sprite_S118height_s,sprite_S118Bitmap_s,
		},

		{
		sprite_S119width_s,sprite_S119height_s,sprite_S119Bitmap_s,
		},

		{
		sprite_S120width_s,sprite_S120height_s,sprite_S120Bitmap_s,
		},

		{
		sprite_S121width_s,sprite_S121height_s,sprite_S121Bitmap_s,
		},

		{
		sprite_S122width_s,sprite_S122height_s,sprite_S122Bitmap_s,
		},

		{
		sprite_S123width_s,sprite_S123height_s,sprite_S123Bitmap_s,
		},

		{
		sprite_S124width_s,sprite_S124height_s,sprite_S124Bitmap_s,
		},

		{
		sprite_S125width_s,sprite_S125height_s,sprite_S125Bitmap_s,
		},

		{
		sprite_S126width_s,sprite_S126height_s,sprite_S126Bitmap_s,
		},

		{
		sprite_S127width_s,sprite_S127height_s,sprite_S127Bitmap_s,
		},

		{
		sprite_S128width_s,sprite_S128height_s,sprite_S128Bitmap_s,
		},

		{
		sprite_S129width_s,sprite_S129height_s,sprite_S129Bitmap_s,
		},

		{
		sprite_S130width_s,sprite_S130height_s,sprite_S130Bitmap_s,
		},

		{
		sprite_S131width_s,sprite_S131height_s,sprite_S131Bitmap_s,
		},

		{
		sprite_S132width_s,sprite_S132height_s,sprite_S132Bitmap_s,
		},

		{
		sprite_S133width_s,sprite_S133height_s,sprite_S133Bitmap_s,
		},

		{
		sprite_S134width_s,sprite_S134height_s,sprite_S134Bitmap_s,
		},

		{
		sprite_S135width_s,sprite_S135height_s,sprite_S135Bitmap_s,
		},

		{
		sprite_S136width_s,sprite_S136height_s,sprite_S136Bitmap_s,
		},

		{
		sprite_S137width_s,sprite_S137height_s,sprite_S137Bitmap_s,
		},

		{
		sprite_S138width_s,sprite_S138height_s,sprite_S138Bitmap_s,
		},

		{
		sprite_S139width_s,sprite_S139height_s,sprite_S139Bitmap_s,
		},

		{
		sprite_S140width_s,sprite_S140height_s,sprite_S140Bitmap_s,
		},

		{
		sprite_S141width_s,sprite_S141height_s,sprite_S141Bitmap_s,
		},

		{
		sprite_S142width_s,sprite_S142height_s,sprite_S142Bitmap_s,
		},

		{
		sprite_S143width_s,sprite_S143height_s,sprite_S143Bitmap_s,
		},

		{
		sprite_S144width_s,sprite_S144height_s,sprite_S144Bitmap_s,
		},

		{
		sprite_S145width_s,sprite_S145height_s,sprite_S145Bitmap_s,
		},

		{
		sprite_S146width_s,sprite_S146height_s,sprite_S146Bitmap_s,
		},

		{
		sprite_S147width_s,sprite_S147height_s,sprite_S147Bitmap_s,
		},

		{
		sprite_S148width_s,sprite_S148height_s,sprite_S148Bitmap_s,
		},

		{
		sprite_S149width_s,sprite_S149height_s,sprite_S149Bitmap_s,
		},

		{
		sprite_S150width_s,sprite_S150height_s,sprite_S150Bitmap_s,
		},

		{
		sprite_S151width_s,sprite_S151height_s,sprite_S151Bitmap_s,
		},

		{
		sprite_S152width_s,sprite_S152height_s,sprite_S152Bitmap_s,
		},

		{
		sprite_S153width_s,sprite_S153height_s,sprite_S153Bitmap_s,
		},

		{
		sprite_S154width_s,sprite_S154height_s,sprite_S154Bitmap_s,
		},

		{
		sprite_S155width_s,sprite_S155height_s,sprite_S155Bitmap_s,
		},

		{
		sprite_S156width_s,sprite_S156height_s,sprite_S156Bitmap_s,
		},

		{
		sprite_S157width_s,sprite_S157height_s,sprite_S157Bitmap_s,
		},

		{
		sprite_S158width_s,sprite_S158height_s,sprite_S158Bitmap_s,
		},

		{
		sprite_S159width_s,sprite_S159height_s,sprite_S159Bitmap_s,
		},

		{
		sprite_S160width_s,sprite_S160height_s,sprite_S160Bitmap_s,
		},

		{
		sprite_S161width_s,sprite_S161height_s,sprite_S161Bitmap_s,
		},

		{
		sprite_S162width_s,sprite_S162height_s,sprite_S162Bitmap_s,
		},

		{
		sprite_S163width_s,sprite_S163height_s,sprite_S163Bitmap_s,
		},

		{
		sprite_S164width_s,sprite_S164height_s,sprite_S164Bitmap_s,
		},

		{
		sprite_S165width_s,sprite_S165height_s,sprite_S165Bitmap_s,
		},

		{
		sprite_S166width_s,sprite_S166height_s,sprite_S166Bitmap_s,
		},

		{
		sprite_S167width_s,sprite_S167height_s,sprite_S167Bitmap_s,
		},

		{
		sprite_S168width_s,sprite_S168height_s,sprite_S168Bitmap_s,
		},

		{
		sprite_S169width_s,sprite_S169height_s,sprite_S169Bitmap_s,
		},

		{
		sprite_S170width_s,sprite_S170height_s,sprite_S170Bitmap_s,
		},

		{
		sprite_S171width_s,sprite_S171height_s,sprite_S171Bitmap_s,
		},

		{
		sprite_S172width_s,sprite_S172height_s,sprite_S172Bitmap_s,
		},

		{
		sprite_S173width_s,sprite_S173height_s,sprite_S173Bitmap_s,
		},

		{
		sprite_S174width_s,sprite_S174height_s,sprite_S174Bitmap_s,
		},

		{
		sprite_S175width_s,sprite_S175height_s,sprite_S175Bitmap_s,
		},

		{
		sprite_S176width_s,sprite_S176height_s,sprite_S176Bitmap_s,
		},

		{
		sprite_S177width_s,sprite_S177height_s,sprite_S177Bitmap_s,
		},

		{
		sprite_S178width_s,sprite_S178height_s,sprite_S178Bitmap_s,
		},

		{
		sprite_S179width_s,sprite_S179height_s,sprite_S179Bitmap_s,
		},

		{
		sprite_S180width_s,sprite_S180height_s,sprite_S180Bitmap_s,
		},

		{
		sprite_S181width_s,sprite_S181height_s,sprite_S181Bitmap_s,
		},

		{
		sprite_S182width_s,sprite_S182height_s,sprite_S182Bitmap_s,
		},

		{
		sprite_S183width_s,sprite_S183height_s,sprite_S183Bitmap_s,
		},

		{
		sprite_S184width_s,sprite_S184height_s,sprite_S184Bitmap_s,
		},

		{
		sprite_S185width_s,sprite_S185height_s,sprite_S185Bitmap_s,
		},

		{
		sprite_S186width_s,sprite_S186height_s,sprite_S186Bitmap_s,
		},

		{
		sprite_S187width_s,sprite_S187height_s,sprite_S187Bitmap_s,
		},

		{
		sprite_S188width_s,sprite_S188height_s,sprite_S188Bitmap_s,
		},

		{
		sprite_S189width_s,sprite_S189height_s,sprite_S189Bitmap_s,
		},

		{
		sprite_S190width_s,sprite_S190height_s,sprite_S190Bitmap_s,
		},

		{
		sprite_S191width_s,sprite_S191height_s,sprite_S191Bitmap_s,
		},

		{
		sprite_S192width_s,sprite_S192height_s,sprite_S192Bitmap_s,
		},

		{
		sprite_S193width_s,sprite_S193height_s,sprite_S193Bitmap_s,
		},

		{
		sprite_S194width_s,sprite_S194height_s,sprite_S194Bitmap_s,
		},

		{
		sprite_S195width_s,sprite_S195height_s,sprite_S195Bitmap_s,
		},

		{
		sprite_S196width_s,sprite_S196height_s,sprite_S196Bitmap_s,
		},

		{
		sprite_S197width_s,sprite_S197height_s,sprite_S197Bitmap_s,
		},

		{
		sprite_S198width_s,sprite_S198height_s,sprite_S198Bitmap_s,
		},

		{
		sprite_S199width_s,sprite_S199height_s,sprite_S199Bitmap_s,
		},

		{
		sprite_S200width_s,sprite_S200height_s,sprite_S200Bitmap_s,
		},

		{
		sprite_S201width_s,sprite_S201height_s,sprite_S201Bitmap_s,
		},

		{
		sprite_S202width_s,sprite_S202height_s,sprite_S202Bitmap_s,
		},

		{
		sprite_S203width_s,sprite_S203height_s,sprite_S203Bitmap_s,
		},

		{
		sprite_S204width_s,sprite_S204height_s,sprite_S204Bitmap_s,
		},

		{
		sprite_S205width_s,sprite_S205height_s,sprite_S205Bitmap_s,
		},

		{
		sprite_S206width_s,sprite_S206height_s,sprite_S206Bitmap_s,
		},

		{
		sprite_S207width_s,sprite_S207height_s,sprite_S207Bitmap_s,
		},

		{
		sprite_S208width_s,sprite_S208height_s,sprite_S208Bitmap_s,
		},

		{
		sprite_S209width_s,sprite_S209height_s,sprite_S209Bitmap_s,
		},

		{
		sprite_S210width_s,sprite_S210height_s,sprite_S210Bitmap_s,
		},

		{
		sprite_S211width_s,sprite_S211height_s,sprite_S211Bitmap_s,
		},

		{
		sprite_S212width_s,sprite_S212height_s,sprite_S212Bitmap_s,
		},

		{
		sprite_S213width_s,sprite_S213height_s,sprite_S213Bitmap_s,
		},

		{
		sprite_S214width_s,sprite_S214height_s,sprite_S214Bitmap_s,
		},
 
		{
		sprite_S215width_s,sprite_S215height_s,sprite_S215Bitmap_s,
		},

		{
		sprite_S216width_s,sprite_S216height_s,sprite_S216Bitmap_s,
		},

		{
		sprite_S217width_s,sprite_S217height_s,sprite_S217Bitmap_s,
		},

		{
		sprite_S218width_s,sprite_S218height_s,sprite_S218Bitmap_s,
		},

		{
		sprite_S219width_s,sprite_S219height_s,sprite_S219Bitmap_s,
		},

		{
		sprite_S220width_s,sprite_S220height_s,sprite_S220Bitmap_s,
		},

		{
		sprite_S221width_s,sprite_S221height_s,sprite_S221Bitmap_s,
		},

		{
		sprite_S222width_s,sprite_S222height_s,sprite_S222Bitmap_s,
		},

		{
		sprite_S223width_s,sprite_S223height_s,sprite_S223Bitmap_s,
		},

		{
		sprite_S224width_s,sprite_S224height_s,sprite_S224Bitmap_s,
		},

		{
		sprite_S225width_s,sprite_S225height_s,sprite_S225Bitmap_s,
		},

		{
		sprite_S226width_s,sprite_S226height_s,sprite_S226Bitmap_s,
		},

		{
		sprite_S227width_s,sprite_S227height_s,sprite_S227Bitmap_s,
		},

		{
		sprite_S228width_s,sprite_S228height_s,sprite_S228Bitmap_s,
		},

		{
		sprite_S229width_s,sprite_S229height_s,sprite_S229Bitmap_s,
		},

		{
		sprite_S230width_s,sprite_S230height_s,sprite_S230Bitmap_s,
		},

		{
		sprite_S231width_s,sprite_S231height_s,sprite_S231Bitmap_s,
		},

		{
		sprite_S232width_s,sprite_S232height_s,sprite_S232Bitmap_s,
		},

		{
		sprite_S233width_s,sprite_S233height_s,sprite_S233Bitmap_s,
		},

		{
		sprite_S234width_s,sprite_S234height_s,sprite_S234Bitmap_s,
		},

		{
		sprite_S235width_s,sprite_S235height_s,sprite_S235Bitmap_s,
		},

		{
		sprite_S236width_s,sprite_S236height_s,sprite_S236Bitmap_s,
		},

		{
		sprite_S237width_s,sprite_S237height_s,sprite_S237Bitmap_s,
		},

		{
		sprite_S238width_s,sprite_S238height_s,sprite_S238Bitmap_s,
		},

		{
		sprite_S239width_s,sprite_S239height_s,sprite_S239Bitmap_s,
		},

		{
		sprite_S240width_s,sprite_S240height_s,sprite_S240Bitmap_s,
		},

		{
		sprite_S241width_s,sprite_S241height_s,sprite_S241Bitmap_s,
		},

		{
		sprite_S242width_s,sprite_S242height_s,sprite_S242Bitmap_s,
		},

		{
		sprite_S243width_s,sprite_S243height_s,sprite_S243Bitmap_s,
		},

		{
		sprite_S244width_s,sprite_S244height_s,sprite_S244Bitmap_s,
		},

		{
		sprite_S245width_s,sprite_S245height_s,sprite_S245Bitmap_s,
		},

		{
		sprite_S246width_s,sprite_S246height_s,sprite_S246Bitmap_s,
		},

		{
		sprite_S247width_s,sprite_S247height_s,sprite_S247Bitmap_s,
		},

		{
		sprite_S248width_s,sprite_S248height_s,sprite_S248Bitmap_s,
		},

		{
		sprite_S249width_s,sprite_S249height_s,sprite_S249Bitmap_s,
		},

		{
		sprite_S250width_s,sprite_S250height_s,sprite_S250Bitmap_s,
		},

		{
		sprite_S251width_s,sprite_S251height_s,sprite_S251Bitmap_s,
		},

		{
		sprite_S252width_s,sprite_S252height_s,sprite_S252Bitmap_s,
		},

		{
		sprite_S253width_s,sprite_S253height_s,sprite_S253Bitmap_s,
		},

		{
		sprite_S254width_s,sprite_S254height_s,sprite_S254Bitmap_s,
		},

		{
		sprite_S255width_s,sprite_S255height_s,sprite_S255Bitmap_s,
		},

		{
		sprite_S256width_s,sprite_S256height_s,sprite_S256Bitmap_s,
		},

		{
		sprite_S257width_s,sprite_S257height_s,sprite_S257Bitmap_s,
		},

		{
		sprite_S258width_s,sprite_S258height_s,sprite_S258Bitmap_s,
		},

		{
		sprite_S259width_s,sprite_S259height_s,sprite_S259Bitmap_s,
		},

		{
		sprite_S260width_s,sprite_S260height_s,sprite_S260Bitmap_s,
		},

		{
		sprite_S261width_s,sprite_S261height_s,sprite_S261Bitmap_s,
		},

		{
		sprite_S262width_s,sprite_S262height_s,sprite_S262Bitmap_s,
		},

		{
		sprite_S263width_s,sprite_S263height_s,sprite_S263Bitmap_s,
		},

		{
		sprite_S264width_s,sprite_S264height_s,sprite_S264Bitmap_s,
		},

		{
		sprite_S265width_s,sprite_S265height_s,sprite_S265Bitmap_s,
		},

		{
		sprite_S266width_s,sprite_S266height_s,sprite_S266Bitmap_s,
		},

		{
		sprite_S267width_s,sprite_S267height_s,sprite_S267Bitmap_s,
		},

		{
		sprite_S268width_s,sprite_S268height_s,sprite_S268Bitmap_s,
		},

		{
		sprite_S269width_s,sprite_S269height_s,sprite_S269Bitmap_s,
		},

		{
		sprite_S270width_s,sprite_S270height_s,sprite_S270Bitmap_s,
		},

		{
		sprite_S271width_s,sprite_S271height_s,sprite_S271Bitmap_s,
		},

		{
		sprite_S272width_s,sprite_S272height_s,sprite_S272Bitmap_s,
		},

		{
		sprite_S273width_s,sprite_S273height_s,sprite_S273Bitmap_s,
		},

		{
		sprite_S274width_s,sprite_S274height_s,sprite_S274Bitmap_s,
		},

		{
		sprite_S275width_s,sprite_S275height_s,sprite_S275Bitmap_s,
		},

		{
		sprite_S276width_s,sprite_S276height_s,sprite_S276Bitmap_s,
		},

		{
		sprite_S277width_s,sprite_S277height_s,sprite_S277Bitmap_s,
		},

		{
		sprite_S278width_s,sprite_S278height_s,sprite_S278Bitmap_s,
		},

		{
		sprite_S279width_s,sprite_S279height_s,sprite_S279Bitmap_s,
		},

		{
		sprite_S280width_s,sprite_S280height_s,sprite_S280Bitmap_s,
		},

		{
		sprite_S281width_s,sprite_S281height_s,sprite_S281Bitmap_s,
		},

		{
		sprite_S282width_s,sprite_S282height_s,sprite_S282Bitmap_s,
		},

		{
		sprite_S283width_s,sprite_S283height_s,sprite_S283Bitmap_s,
		},

		{
		sprite_S284width_s,sprite_S284height_s,sprite_S284Bitmap_s,
		},

		{
		sprite_S285width_s,sprite_S285height_s,sprite_S285Bitmap_s,
		},

		{
		sprite_S286width_s,sprite_S286height_s,sprite_S286Bitmap_s,
		},

		{
		sprite_S287width_s,sprite_S287height_s,sprite_S287Bitmap_s,
		},

		{
		sprite_S288width_s,sprite_S288height_s,sprite_S288Bitmap_s,
		},

		{
		sprite_S289width_s,sprite_S289height_s,sprite_S289Bitmap_s,
		},

		{
		sprite_S290width_s,sprite_S290height_s,sprite_S290Bitmap_s,
		},

		{
		sprite_S291width_s,sprite_S291height_s,sprite_S291Bitmap_s,
		},

		{
		sprite_S292width_s,sprite_S292height_s,sprite_S292Bitmap_s,
		},

		{
		sprite_S293width_s,sprite_S293height_s,sprite_S293Bitmap_s,
		},

		{
		sprite_S294width_s,sprite_S294height_s,sprite_S294Bitmap_s,
		},

		{
		sprite_S295width_s,sprite_S295height_s,sprite_S295Bitmap_s,
		},

		{
		sprite_S296width_s,sprite_S296height_s,sprite_S296Bitmap_s,
		},

		{
		sprite_S297width_s,sprite_S297height_s,sprite_S297Bitmap_s,
		},

		{
		sprite_S298width_s,sprite_S298height_s,sprite_S298Bitmap_s,
		},

		{
		sprite_S299width_s,sprite_S299height_s,sprite_S299Bitmap_s,
		},

		{
		sprite_S300width_s,sprite_S300height_s,sprite_S300Bitmap_s,
		},

		{
		sprite_S301width_s,sprite_S301height_s,sprite_S301Bitmap_s,
		},

		{
		sprite_S302width_s,sprite_S302height_s,sprite_S302Bitmap_s,
		},

		{
		sprite_S303width_s,sprite_S303height_s,sprite_S303Bitmap_s,
		},

		{
		sprite_S304width_s,sprite_S304height_s,sprite_S304Bitmap_s,
		},

		{
		sprite_S305width_s,sprite_S305height_s,sprite_S305Bitmap_s,
		},

		{
		sprite_S306width_s,sprite_S306height_s,sprite_S306Bitmap_s,
		},

		{
		sprite_S307width_s,sprite_S307height_s,sprite_S307Bitmap_s,
		},

		{
		sprite_S308width_s,sprite_S308height_s,sprite_S308Bitmap_s,
		},

		{
		sprite_S309width_s,sprite_S309height_s,sprite_S309Bitmap_s,
		},

		{
		sprite_S310width_s,sprite_S310height_s,sprite_S310Bitmap_s,
		},

		{
		sprite_S311width_s,sprite_S311height_s,sprite_S311Bitmap_s,
		},

		{
		sprite_S312width_s,sprite_S312height_s,sprite_S312Bitmap_s,
		},

		{
		sprite_S313width_s,sprite_S313height_s,sprite_S313Bitmap_s,
		},

		{
		sprite_S314width_s,sprite_S314height_s,sprite_S314Bitmap_s,
		},
 
		{
		sprite_S315width_s,sprite_S315height_s,sprite_S315Bitmap_s,
		},

		{
		sprite_S316width_s,sprite_S316height_s,sprite_S316Bitmap_s,
		},

		{
		sprite_S317width_s,sprite_S317height_s,sprite_S317Bitmap_s,
		},

		{
		sprite_S318width_s,sprite_S318height_s,sprite_S318Bitmap_s,
		},

		{
		sprite_S319width_s,sprite_S319height_s,sprite_S319Bitmap_s,
		},

		{
		sprite_S320width_s,sprite_S320height_s,sprite_S320Bitmap_s,
		},

		{
		sprite_S321width_s,sprite_S321height_s,sprite_S321Bitmap_s,
		},

		{
		sprite_S322width_s,sprite_S322height_s,sprite_S322Bitmap_s,
		},

		{
		sprite_S323width_s,sprite_S323height_s,sprite_S323Bitmap_s,
		},

		{
		sprite_S324width_s,sprite_S324height_s,sprite_S324Bitmap_s,
		},

		{
		sprite_S325width_s,sprite_S325height_s,sprite_S325Bitmap_s,
		},

		{
		sprite_S326width_s,sprite_S326height_s,sprite_S326Bitmap_s,
		},

		{
		sprite_S327width_s,sprite_S327height_s,sprite_S327Bitmap_s,
		},

		{
		sprite_S328width_s,sprite_S328height_s,sprite_S328Bitmap_s,
		},

		{
		sprite_S329width_s,sprite_S329height_s,sprite_S329Bitmap_s,
		},

		{
		sprite_S330width_s,sprite_S330height_s,sprite_S330Bitmap_s,
		},

		{
		sprite_S331width_s,sprite_S331height_s,sprite_S331Bitmap_s,
		},

		{
		sprite_S332width_s,sprite_S332height_s,sprite_S332Bitmap_s,
		},

		{
		sprite_S333width_s,sprite_S333height_s,sprite_S333Bitmap_s,
		},

		{
		sprite_S333width_s,sprite_S333height_s,sprite_S333Bitmap_s,
		},

		{
		sprite_S334width_s,sprite_S334height_s,sprite_S334Bitmap_s,
		},

		{
		sprite_S335width_s,sprite_S335height_s,sprite_S335Bitmap_s,
		},

		{
		sprite_S336width_s,sprite_S336height_s,sprite_S336Bitmap_s,
		},

		{
		sprite_S337width_s,sprite_S337height_s,sprite_S337Bitmap_s,
		},

		{
		sprite_S338width_s,sprite_S338height_s,sprite_S338Bitmap_s,
		},

		{
		sprite_S339width_s,sprite_S339height_s,sprite_S339Bitmap_s,
		},

		{
		sprite_S340width_s,sprite_S340height_s,sprite_S340Bitmap_s,
		},

		{
		sprite_S341width_s,sprite_S341height_s,sprite_S341Bitmap_s,
		},

		{
		sprite_S342width_s,sprite_S342height_s,sprite_S342Bitmap_s,
		},

		{
		sprite_S343width_s,sprite_S343height_s,sprite_S343Bitmap_s,
		},

		{
		sprite_S344width_s,sprite_S344height_s,sprite_S344Bitmap_s,
		},

		{
		sprite_S345width_s,sprite_S345height_s,sprite_S345Bitmap_s,
		},

		{
		sprite_S346width_s,sprite_S346height_s,sprite_S346Bitmap_s,
		},

		{
		sprite_S347width_s,sprite_S347height_s,sprite_S347Bitmap_s,
		},

		{
		sprite_S348width_s,sprite_S348height_s,sprite_S348Bitmap_s,
		},

		{
		sprite_S349width_s,sprite_S349height_s,sprite_S349Bitmap_s,
		},

		{
		sprite_S350width_s,sprite_S350height_s,sprite_S350Bitmap_s,
		},

		{
		sprite_S351width_s,sprite_S351height_s,sprite_S351Bitmap_s,
		},

		{
		sprite_S352width_s,sprite_S352height_s,sprite_S352Bitmap_s,
		},

		{
		sprite_S353width_s,sprite_S353height_s,sprite_S353Bitmap_s,
		},

		{
		sprite_S354width_s,sprite_S354height_s,sprite_S354Bitmap_s,
		},

		{
		sprite_S355width_s,sprite_S355height_s,sprite_S355Bitmap_s,
		},

		{
		sprite_S356width_s,sprite_S356height_s,sprite_S356Bitmap_s,
		},

		{
		sprite_S357width_s,sprite_S357height_s,sprite_S357Bitmap_s,
		},

		{
		sprite_S358width_s,sprite_S358height_s,sprite_S358Bitmap_s,
		},

		{
		sprite_S359width_s,sprite_S359height_s,sprite_S359Bitmap_s,
		},

		{
		sprite_S360width_s,sprite_S360height_s,sprite_S360Bitmap_s,
		},

		{
		sprite_S361width_s,sprite_S361height_s,sprite_S361Bitmap_s,
		},

		{
		sprite_S362width_s,sprite_S362height_s,sprite_S362Bitmap_s,
		},

		{
		sprite_S363width_s,sprite_S363height_s,sprite_S363Bitmap_s,
		},

		{
		sprite_S364width_s,sprite_S364height_s,sprite_S364Bitmap_s,
		},

		{
		sprite_S365width_s,sprite_S365height_s,sprite_S365Bitmap_s,
		},

		{
		sprite_S366width_s,sprite_S366height_s,sprite_S366Bitmap_s,
		},

		{
		sprite_S367width_s,sprite_S367height_s,sprite_S367Bitmap_s,
		},

		{
		sprite_S368width_s,sprite_S368height_s,sprite_S368Bitmap_s,
		},

		{
		sprite_S369width_s,sprite_S369height_s,sprite_S369Bitmap_s,
		},

		{
		sprite_S370width_s,sprite_S370height_s,sprite_S370Bitmap_s,
		},

		{
		sprite_S371width_s,sprite_S371height_s,sprite_S371Bitmap_s,
		},

		{
		sprite_S372width_s,sprite_S372height_s,sprite_S372Bitmap_s,
		},

		{
		sprite_S373width_s,sprite_S373height_s,sprite_S373Bitmap_s,
		},

		{
		sprite_S374width_s,sprite_S374height_s,sprite_S374Bitmap_s,
		},

		{
		sprite_S375width_s,sprite_S375height_s,sprite_S375Bitmap_s,
		},

		{
		sprite_S376width_s,sprite_S376height_s,sprite_S376Bitmap_s,
		},

		{
		sprite_S377width_s,sprite_S377height_s,sprite_S377Bitmap_s,
		},

		{
		sprite_S378width_s,sprite_S378height_s,sprite_S378Bitmap_s,
		},

		{
		sprite_S379width_s,sprite_S379height_s,sprite_S379Bitmap_s,
		},

		{
		sprite_S380width_s,sprite_S380height_s,sprite_S380Bitmap_s,
		},

		{
		sprite_S381width_s,sprite_S381height_s,sprite_S381Bitmap_s,
		},

		{
		sprite_S382width_s,sprite_S382height_s,sprite_S382Bitmap_s,
		},

		{
		sprite_S383width_s,sprite_S383height_s,sprite_S383Bitmap_s,
		},

		{
		sprite_S384width_s,sprite_S384height_s,sprite_S384Bitmap_s,
		},

		{
		sprite_S385width_s,sprite_S385height_s,sprite_S385Bitmap_s,
		},

		{
		sprite_S386width_s,sprite_S386height_s,sprite_S386Bitmap_s,
		},

		{
		sprite_S387width_s,sprite_S387height_s,sprite_S387Bitmap_s,
		},

		{
		sprite_S388width_s,sprite_S388height_s,sprite_S388Bitmap_s,
		},

		{
		sprite_S389width_s,sprite_S389height_s,sprite_S389Bitmap_s,
		},

		{
		sprite_S390width_s,sprite_S390height_s,sprite_S390Bitmap_s,
		},

		{
		sprite_S391width_s,sprite_S391height_s,sprite_S391Bitmap_s,
		},

		{
		sprite_S392width_s,sprite_S392height_s,sprite_S392Bitmap_s,
		},

		{
		sprite_S393width_s,sprite_S393height_s,sprite_S393Bitmap_s,
		},

		{
		sprite_S394width_s,sprite_S394height_s,sprite_S394Bitmap_s,
		},

		{
		sprite_S395width_s,sprite_S395height_s,sprite_S395Bitmap_s,
		},

		{
		sprite_S396width_s,sprite_S396height_s,sprite_S396Bitmap_s,
		},

		{
		sprite_S397width_s,sprite_S397height_s,sprite_S397Bitmap_s,
		},

		{
		sprite_S398width_s,sprite_S398height_s,sprite_S398Bitmap_s,
		},

		{
		sprite_S399width_s,sprite_S399height_s,sprite_S399Bitmap_s,
		},

		{
		sprite_S400width_s,sprite_S400height_s,sprite_S400Bitmap_s,
		},

		{
		sprite_S401width_s,sprite_S401height_s,sprite_S401Bitmap_s,
		},

		{
		sprite_S402width_s,sprite_S402height_s,sprite_S402Bitmap_s,
		},

		{
		sprite_S403width_s,sprite_S403height_s,sprite_S403Bitmap_s,
		},

		{
		sprite_S404width_s,sprite_S404height_s,sprite_S404Bitmap_s,
		},

		{
		sprite_S405width_s,sprite_S405height_s,sprite_S405Bitmap_s,
		},

		{
		sprite_S406width_s,sprite_S406height_s,sprite_S406Bitmap_s,
		},

		{
		sprite_S407width_s,sprite_S407height_s,sprite_S407Bitmap_s,
		},

		{
		sprite_S408width_s,sprite_S408height_s,sprite_S408Bitmap_s,
		},

		{
		sprite_S409width_s,sprite_S409height_s,sprite_S409Bitmap_s,
		},

		{
		sprite_S410width_s,sprite_S410height_s,sprite_S410Bitmap_s,
		},

		{
		sprite_S411width_s,sprite_S411height_s,sprite_S411Bitmap_s,
		},

		{
		sprite_S412width_s,sprite_S412height_s,sprite_S412Bitmap_s,
		},

		{
		sprite_S413width_s,sprite_S413height_s,sprite_S413Bitmap_s,
		},

		{
		sprite_S414width_s,sprite_S414height_s,sprite_S414Bitmap_s,
		},
 
		{
		sprite_S415width_s,sprite_S415height_s,sprite_S415Bitmap_s,
		},

		{
		sprite_S416width_s,sprite_S416height_s,sprite_S416Bitmap_s,
		},

		{
		sprite_S417width_s,sprite_S417height_s,sprite_S417Bitmap_s,
		},

		{
		sprite_S418width_s,sprite_S418height_s,sprite_S418Bitmap_s,
		},

		{
		sprite_S419width_s,sprite_S419height_s,sprite_S419Bitmap_s,
		},

		{
		sprite_S420width_s,sprite_S420height_s,sprite_S420Bitmap_s,
		},

		{
		sprite_999width_s,sprite_999height_s,sprite_999Bitmap_s,
		},

		};
		




#define		Scr100		0
#define		Scr85		1
#define		Scr85w		2
#define		Scr75		3
#define		Scr75w		4
#define		Scr65		5
#define		Scr65w		6
#define		Scr50		7
#define		Scr50w		8
#define		Scr40w		9

#define		SKY_OFF		0
#define		SKY_ON		1
#define		STADIA_OFF	0
#define		STADIA_ON	1
#define		PITCH_OFF	0
#define		PITCH_MED	1
#define		PITCH_ON	2
#define		PLAYERS_OFF	0
#define		PLAYERS_ON	1
#define		LINES_OFF	0
#define		LINES_ON	1
#define		SHADOWS_OFF	0
#define		SHADOWS_ON	1

detail_info detail_defaults[]=								// PC_speed
		{
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 0
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 1
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 2
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 3
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 4
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 5
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 6
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 7
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 8
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 9
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 10
		{SKY_ON , STADIA_OFF, PITCH_MED, PLAYERS_ON , LINES_OFF, SHADOWS_ON },		// 11
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_OFF, LINES_OFF, SHADOWS_ON },		// 12
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_OFF, LINES_OFF, SHADOWS_ON },		// 13
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_OFF, LINES_OFF, SHADOWS_ON },		// 14
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_OFF, LINES_OFF, SHADOWS_ON },		// 15
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_OFF, LINES_OFF, SHADOWS_ON },		// 16
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_OFF, LINES_OFF, SHADOWS_ON },		// 17
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 18
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 19
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 20
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 21
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 22
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 23
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 24
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 25
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 26
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 27
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 28
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 29
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 30
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 31
		{SKY_ON , STADIA_ON , PITCH_MED, PLAYERS_ON , LINES_ON , SHADOWS_ON },		// 32
		};												  

short screen_defaults[]=
		{	

		{ Scr65w },									// 0
		{ Scr65w },									// 1
		{ Scr65w },									// 2
		{ Scr65w },									// 3
		{ Scr65w },									// 4
		{ Scr65w },									// 5
		{ Scr65w },									// 6
		{ Scr65w },									// 7
		{ Scr65w },									// 8
		{ Scr65w },									// 9
		{ Scr65w },									// 10
		{ Scr65w },									// 11
		{ Scr75	 },									// 12
		{ Scr75	 },									// 13
		{ Scr75	 },									// 14
		{ Scr75	 },									// 15
		{ Scr75	 },									// 16
		{ Scr75	 },									// 17
		{ Scr100 },									// 18
		{ Scr100 },									// 19
		{ Scr100 },									// 20
		{ Scr100 },									// 21
		{ Scr100 },									// 22
		{ Scr100 },									// 23
		{ Scr100 },									// 24
		{ Scr100 },									// 25
		{ Scr100 },									// 26
		{ Scr100 },									// 27
		{ Scr100 },									// 28
		{ Scr100 },									// 29
		{ Scr100 },									// 30
		{ Scr100 },									// 31
		{ Scr100 },									// 32
		};


	int	spin_y_offsets[]={
		15,17,20,23,25,28,30,33,10,10,9,9,10,11,12,
		};

#if 0
	char	*formation_types[]={
		"4-3-3",
		"5-3-2",
		"6-3-1",
		"4-2-4",
		"5-1-4",
		"4-0-6",
		"3-1-6",
		"4-1-5",
		"5-2-3",
		"4-4-2",     };
				
	char	*sky_types[]={
		"OFF",
		"ON",	     

		  "OFF",
		  "ON",	     
		
		    "AUS",
		    "AN",

		      "OFF",
        	      "ON",	     

		        "OFF",
		        "ON",	     

			  "AV",
			  "P|",	     
				};
				
	char	*sub_types[]={
		"OFF",
		"ON",	     

		  "OFF",
		  "ON",	     
		
		    "AUS",
		    "AN",

		      "OFF",
		      "ON",	     

		        "OFF",
		        "ON",	     

			  "AV",
			  "P|",	     
				};
				
	char	*stadium_types[]={
		"LOW",
		"HIGH",	     

		  "FAIBLE",
		  "ELEVE",
		    
		    "MIN",
		    "MAX",

		      "LOW",
		      "HIGH",	     

		        "FAIBLE",
		        "ELEVE",

			  "FIN",
			  "GROV",

				};
	
	char	*pitch_types[]={
		"LOW",
		"MED",
		"HIGH",	     

		  "FAIBLE",
		  "MOYEN",
		  "ELEVE",

		    "MIN",
		    "MED",
		    "MAX",

		      "LOW",
		      "MED",
		      "HIGH",	     

		        "FAIBLE",
		        "MOYEN",
		        "ELEVE",

			  "LAV",
			  "MED",
			  "H{Y",	     
				};

				
	char	*wind_types[]={
		"OFF",
		"LOW",
		"MED",
		"HIGH",	     

	 	  "OFF",
		  "FAIBLE",
		  "MOYEN",
		  "ELEVE",

		    "AUS",
		    "MIN",
		    "MED",
		    "MAX",

		      "OFF",
		      "LOW",
		      "MED",
		      "HIGH",	     

	 	        "OFF",
		        "FAIBLE",
		        "MOYEN",
		        "ELEVE",

			  "AV",
			  "SVAK",
			  "MED",
			  "STERK",	     

				};
				
	char	*camera_types[]={

		"WIRE",
		"FAR",
		"PLAN",
		"G.LINE",
		"ISO.",
		"PLYR",
		"REF",

	 	  "MAN.",  
		  "ELO.",  
		  "AERIEN",
		  "LIGNE", 
		  "ISO.",
		  "JOU.",
		  "ARB",
		
		    "FREI",
		    "WEIT",
		    "PLAN",
		    "TOR L.",
		    "ISO.",
		    "PLYR",
		    "SCHI.",

		      "WIRE",
		      "FAR",
		      "PLAN",
		      "G.LINE",
		      "ISO.",
		      "PLYR",
		      "REF",

	 	        "MAN.",  
		        "ELO.",  
		        "AERIEN",
		        "LIGNE", 
		        "ISO.",
		        "JOU.",
		        "ARB",

			  "WIRE",
			  "VIDV.",
			  "PLAN",
			  "M|L-L",
			  "ISO.",
			  "SPLR",
			  "DOMR",
				};
	
	char	*player_labels[]={

		"PLAYER 1",
		"PLAYER 2",
		"PLAYER 3",
		"PLAYER 4",

		  "JOUEUR 1",
		  "JOUEUR 2",
		  "JOUEUR 3",
		  "JOUEUR 4",

		    "SPIELER 1",
		    "SPIELER 2",
		    "SPIELER 3",
		    "SPIELER 4",

		      "PLAYER 1",
		      "PLAYER 2",
		      "PLAYER 3",
		      "PLAYER 4",

		        "JOUEUR 1",
		        "JOUEUR 2",
		        "JOUEUR 3",
		        "JOUEUR 4",

			  "SPILLER 1",
			  "SPILLER 2",
			  "SPILLER 3",
			  "SPILLER 4",

				};
			
#if 0
#if TWOKEY==YES
char	*control_labels[]={	"KEYBOARD 1", "KEYBOARD 2", "JOYSTICK 1", "JOYSTICK 2",
							"CLAVIER 1",  "CLAVIER 2",  "JOYSTICK 1", "JOYSTICK 2",
							"TASTATUR 1", "TASTATUR 2", "JOYSTICK 1", "JOYSTICK 2",
							"KEYBOARD 1", "KEYBOARD 2", "JOYSTICK 1", "JOYSTICK 2",
							"CLAVIER 1",  "CLAVIER 2",  "JOYSTICK 1", "JOYSTICK 2",
							"TASTATUR 1", "TASTATUR 2", "JOYSTICK 1", "JOYSTICK 2"
						   };
#else
char	*control_labels[]={	"KEYBOARD 1", "JOYSTICK 1", "JOYSTICK 2", "JOYSTICK 3",
							"CLAVIER 1",  "JOYSTICK 1", "JOYSTICK 2", "JOYSTICK 3",
							"TASTATUR 1", "JOYSTICK 1", "JOYSTICK 2", "JOYSTICK 3",
							"KEYBOARD 1", "JOYSTICK 1", "JOYSTICK 2", "JOYSTICK 3",
							"CLAVIER 1",  "JOYSTICK 1", "JOYSTICK 2", "JOYSTICK 3",
							"TASTATUR 1", "JOYSTICK 1", "JOYSTICK 2", "JOYSTICK 3"
						   };
#endif

#if TWOKEY==YES
char *calibrate_message[]={ "PLAYER 1, Circle joystick 1 then press fire...",
							"PLAYER 2, Circle joystick 1 then press fire...",
							"PLAYER 3, Circle joystick 1 then press fire...",
							"PLAYER 4, Circle joystick 1 then press fire...",
							"PLAYER 1, Circle joystick 2 then press fire...",
							"PLAYER 2, Circle joystick 2 then press fire...",
							"PLAYER 3, Circle joystick 2 then press fire...",
							"PLAYER 4, Circle joystick 2 then press fire...",
							
							"J1, Cercle avec joystick 1, puis Feu...",
							"J2, Cercle avec joystick 1, puis Feu...",
							"J3, Cercle avec joystick 1, puis Feu...",
							"J4, Cercle avec joystick 1, puis Feu...",
							"J1, Cercle avec joystick 2, puis Feu...",
							"J2, Cercle avec joystick 2, puis Feu...",
							"J3, Cercle avec joystick 2, puis Feu...",
							"J4, Cercle avec joystick 2, puis Feu...",
							
							"SPIELER 1, bitte Joystick 1 drehen, dann Feuer",
							"SPIELER 2, bitte Joystick 1 drehen, dann Feuer",
		    				"SPIELER 3, bitte Joystick 1 drehen, dann Feuer",
		    				"SPIELER 4, bitte Joystick 1 drehen, dann Feuer",
		    				"SPIELER 1, bitte Joystick 2 drehen, dann Feuer",
		    				"SPIELER 2, bitte Joystick 2 drehen, dann Feuer",
		    				"SPIELER 3, bitte Joystick 2 drehen, dann Feuer",
		    				"SPIELER 4, bitte Joystick 2 drehen, dann Feuer",
		
		      				"PLAYER 1, Circle joystick 1 then press fire...",
		     				"PLAYER 2, Circle joystick 1 then press fire...",
		      				"PLAYER 3, Circle joystick 1 then press fire...",
		     			 	"PLAYER 4, Circle joystick 1 then press fire...",
		      				"PLAYER 1, Circle joystick 2 then press fire...",
		      				"PLAYER 2, Circle joystick 2 then press fire...",
		      				"PLAYER 3, Circle joystick 2 then press fire...",
		      				"PLAYER 4, Circle joystick 2 then press fire...",

		        			"J1, Cercle avec joystick 1, puis Feu...",
		        			"J2, Cercle avec joystick 1, puis Feu...",
		        			"J3, Cercle avec joystick 1, puis Feu...",
		        			"J4, Cercle avec joystick 1, puis Feu...",
		        			"J1, Cercle avec joystick 2, puis Feu...",
		        			"J2, Cercle avec joystick 2, puis Feu...",
		        			"J3, Cercle avec joystick 2, puis Feu...",
		        			"J4, Cercle avec joystick 2, puis Feu...",
		    
			  				"SPILLER 1, Vri joystick 1, deretter fyr...",
			  				"SPILLER 2, Vri joystick 1, deretter fyr...",
			  				"SPILLER 3, Vri joystick 1, deretter fyr...",
			  				"SPILLER 4, Vri joystick 1, deretter fyr...",
			  				"SPILLER 1, Vri joystick 2, deretter fyr...",
			  				"SPILLER 2, Vri joystick 2, deretter fyr...",
			  				"SPILLER 3, Vri joystick 2, deretter fyr...",
			  				"SPILLER 4, Vri joystick 2, deretter fyr...",
							};
#else
char *calibrate_message[]={ "PLAYER X, Circle joystick Y then press fire...",
							"JX, Cercle avec joystick Y, puis Feu...",
							"SPIELER X, bitte Joystick Y drehen, dann Feuer",
		      				"PLAYER X, Circle joystick Y then press fire...",
		        			"JX, Cercle avec joystick Y, puis Feu...",
		        			"SPILLER X, Vri joystick Y, deretter fyr...",
							};
#endif

			 	
#if TWOKEY == YES
char *redefine_message[]={
		
		"PLAYER 1, Redefine Keyboard 1...",
		"PLAYER 2, Redefine Keyboard 1...",
		"PLAYER 3, Redefine Keyboard 1...",
		"PLAYER 4, Redefine Keyboard 1...",
		"PLAYER 1, Redefine Keyboard 2...",
		"PLAYER 2, Redefine Keyboard 2...",
		"PLAYER 3, Redefine Keyboard 2...",
		"PLAYER 4, Redefine Keyboard 2...",
		
		  "JOUEUR NUMERO 1, Redefinissez le clavier 1...",
		  "JOUEUR NUMERO 2, Redefinissez le clavier 1...",
		  "JOUEUR NUMERO 3, Redefinissez le clavier 1...",
		  "JOUEUR NUMERO 4, Redefinissez le clavier 1...",
		  "JOUEUR NUMERO 1, Redefinissez le clavier 2...",
		  "JOUEUR NUMERO 2, Redefinissez le clavier 2...",
		  "JOUEUR NUMERO 3, Redefinissez le clavier 2...",
		  "JOUEUR NUMERO 4, Redefinissez le clavier 2...",

		    "SPIELER 1, Testatur umdefinieren 1...",
		    "SPIELER 2, Testatur umdefinieren 1...",
		    "SPIELER 3, Testatur umdefinieren 1...",
		    "SPIELER 4, Testatur umdefinieren 1...",
		    "SPIELER 1, Testatur umdefinieren 2...",
		    "SPIELER 2, Testatur umdefinieren 2...",
		    "SPIELER 3, Testatur umdefinieren 2...",
		    "SPIELER 4, Testatur umdefinieren 2...",
		
		      "PLAYER 1, Redefine Keyboard 1...",
		      "PLAYER 2, Redefine Keyboard 1...",
		      "PLAYER 3, Redefine Keyboard 1...",
		      "PLAYER 4, Redefine Keyboard 1...",
		      "PLAYER 1, Redefine Keyboard 2...",
		      "PLAYER 2, Redefine Keyboard 2...",
		      "PLAYER 3, Redefine Keyboard 2...",
		      "PLAYER 4, Redefine Keyboard 2...",
		
		        "JOUEUR NUMERO 1, Redefinissez le clavier 1...",
		        "JOUEUR NUMERO 2, Redefinissez le clavier 1...",
		        "JOUEUR NUMERO 3, Redefinissez le clavier 1...",
		        "JOUEUR NUMERO 4, Redefinissez le clavier 1...",
		        "JOUEUR NUMERO 1, Redefinissez le clavier 2...",
		        "JOUEUR NUMERO 2, Redefinissez le clavier 2...",
		        "JOUEUR NUMERO 3, Redefinissez le clavier 2...",
		        "JOUEUR NUMERO 4, Redefinissez le clavier 2...",

			  "SPILLER 1, definer tastatur 1...",
			  "SPILLER 2, definer tastatur 1...",
			  "SPILLER 3, definer tastatur 1...",
			  "SPILLER 4, definer tastatur 1...",
			  "SPILLER 1, definer tastatur 2...",
			  "SPILLER 2, definer tastatur 2...",
			  "SPILLER 3, definer tastatur 2...",
		 	  "SPILLER 4, definer tastatur 2...",

				};
#else
char *redefine_message[]={ "Player X, Redefine Keyboard Y...",
						   "JOUEUR NUMERO X, Redefinissez le clavier Y...",
						   "SPIELER X, Testatur umdefinieren Y...",
						   "Player X, Redefine Keyboard Y...",
						   "JOUEUR NUMERO X, Redefinissez le clavier Y...",
						   "SPILLER X, definer tastatur Y...",
						 };
#endif
#endif

	char	*size_types[]={
		"100%",
		"85%",
		"85%W",
		"75%",
		"75%W",
		"65%",
		"65%W",
		"50%",
		"50%W",
		"40%W",

	// SAME IN FRENCH
				};
				
	char	*time_types[]={
		"5",
		"10",
		"20",
		"40",
		"90",

	// SAME IN FRENCH
				};
				
				
	char	*audio_types[]={
		"OFF",
		"MONO",
		"3D",	 	

		  "OFF",
		  "MONO",
		  "3D",

		    "AUS",
		    "MONO",
		    "3D",

		      "OFF",
		      "MONO",
		      "3D",	 	

		        "OFF",
		        "MONO",
		        "3D",

			  "AV",
			  "MONO",
	 		  "3D",
				};

	char	*NoOfPLAYERS_types[]={

		"PLAYERS: 1",
		"PLAYERS: 2",
		"PLAYERS: 3",
		"PLAYERS: 4",
		"HOST GAME",	// "GAME: 0"
		"JOIN GAME",	// "GAME: 1",
		"GAME: 2",
		"GAME: 3",
		"GAME: 4",
		"GAME: 5",
		"GAME: 6",
		"GAME: 7",

		  "JOUEURS: 1",
		  "JOUEURS: 2",
		  "JOUEURS: 3",
		  "JOUEURS: 4",
		"HOST GAME",	// "JEU: 0"
		"JOIN GAME",	// "JEU: 1",
		  "JEU: 2",
		  "JEU: 3",
		  "JEU: 4",
		  "JEU: 5",
		  "JEU: 6",
		  "JEU: 7",

		    "SPIELER: 1",
		    "SPIELER: 2",
		    "SPIELER: 3",
		    "SPIELER: 4",	
		"HOST GAME",	// "SPIEL: 0"
		"JOIN GAME",	// "SPIEL: 1",
		    "SPIEL: 2",
		    "SPIEL: 3",
		    "SPIEL: 4",
		    "SPIEL: 5",
		    "SPIEL: 6",
		    "SPIEL: 7",

		      "PLAYERS: 1",
		      "PLAYERS: 2",
		      "PLAYERS: 3",
		      "PLAYERS: 4",	
		"HOST GAME",	// "GAME: 0"
		"JOIN GAME",	// "GAME: 1",
		      "GAME: 2",
		      "GAME: 3",
		      "GAME: 4",
		      "GAME: 5",
		      "GAME: 6",
		      "GAME: 7",
		      
		        "JOUEURS: 1",
		        "JOUEURS: 2",
		        "JOUEURS: 3",
		        "JOUEURS: 4",
		"HOST GAME",	// "JEU: 0"
		"JOIN GAME",	// "JEU: 1",
		        "JEU: 2",
		        "JEU: 3",
		        "JEU: 4",
		        "JEU: 5",
		        "JEU: 6",
		        "JEU: 7",

			  "SPILLERE: 1",
			  "SPILLERE: 2",
			  "SPILLERE: 3",
			  "SPILLERE: 4",
		"HOST GAME",	// "KAMP: 0"
		"JOIN GAME",	// "KAMP: 1",
			  "KAMP: 2",
			  "KAMP: 3",
			  "KAMP: 4",
			  "KAMP: 5",
			  "KAMP: 6",
			  "KAMP: 7",

				};
				
	char	*Game_types[]={
		"ARCADE",
		"SIMULATION",

		  "ARCADE",
		  "SIMULATION",

		    "ARCADE",
		    "SIMULATION",

		      "ARCADE",
		      "SIMULATION",

		        "ARCADE",
		        "SIMULATION",

			  "ARKADE",
	 		  "SIMULERING",

				};

	char	*COMPETITION_types[]={

		"FRIENDLY",
		"LEAGUE",
		"CUP",
		"PRACTICE",
		"NETWORK",
		
		  "AMICAL",
		  "LIGUE",
		  "COUPE",
		  "PRACTIQUE",
		  "RESEAU",

		    "FREUNDSCHA.",
		    "LIGA",
		    "POKAL",
		    "TRAINING",
		    "NETZWERK",

		      "FRIENDLY",
		      "LEAGUE",
		      "CUP",
		      "PRACTICE",
		      "NETWORK",
		      
		        "AMICAL",
		        "LIGUE",
		        "COUPE",
		        "PRACTIQUE",
		        "RESEAU",

			  "VENNSKAP",
			  "LIGA",
			  "CUP",
			  "TRENING",
			  "NETTVERK",

				};

	char	*NETWORK_types[]={
		"DONE",
		"WAITING",

		  "FAIT",
		  "EN ATTENTE",

		    "FERTIG",
		    "BITTE WARTEN",

		      "DONE",
		      "WAITING",
		      
		        "FAIT",
		        "EN ATTENTE",

			  "FERDIG",
	  		  "VENTER",

		 		};

	char	*slot_names[]={
		"SLOT 1",
		"SLOT 2",
		"SLOT 3",	     
		"SLOT 4",	     
		"SLOT 5",	     
		"SLOT 6",	     
		"SLOT 7",	     
		"SLOT 8",	     

		  "EMPL. 1",
		  "EMPL. 2",
		  "EMPL. 3",	     
		  "EMPL. 4",	     
		  "EMPL. 5",	     
		  "EMPL. 6",	     
		  "EMPL. 7",	     
		  "EMPL. 8",	     

		    "SPIEL 1",
		    "SPIEL 2",
		    "SPIEL 3",	     
		    "SPIEL 4",	     
		    "SPIEL 5",	     
		    "SPIEL 6",	     
		    "SPIEL 7",	     
		    "SPIEL 8",	     

		      "SLOT 1",
		      "SLOT 2",
		      "SLOT 3",	     
		      "SLOT 4",	     
		      "SLOT 5",	     
		      "SLOT 6",	     
		      "SLOT 7",	     
		      "SLOT 8",	     
		      
		        "EMPL. 1",
		        "EMPL. 2",
		        "EMPL. 3",	     
		        "EMPL. 4",	     
		        "EMPL. 5",	     
		        "EMPL. 6",	     
		        "EMPL. 7",	     
		        "EMPL. 8",	     

			  "SPILL 1",
			  "SPILL 2",
			  "SPILL 3",
			  "SPILL 4",
			  "SPILL 5",
			  "SPILL 6",
			  "SPILL 7",
			  "SPILL 8",

				};
				
#endif

match_data	match_info;

batch_data	batch_info;


#if 0
	char	*ROUNDS[]={

		"1st Round",   			// 32
		"2nd Round",			// 16 
		"Quarter Final", 		// 8
		"Semi-Final",			// 4
		"Final",			// 2
		
		"1st Round",   			// 16
		"Quarter Final",		// 8
		"Semi-Final",			// 4
		"Final",			// 2

		  "1are manche",   
		  "2ame manche",   
		  "Quart de finale",
		  "Demi-finale",
		  "Finale",

		  "1are manche",   
		  "Quart de finale",
		  "Demi-finale",
		  "Finale",

		    "1. Runde",
		    "2. Runde",
		    "Viertelfinale",
		    "Halbfinale",
		    "Finale",

		    "1. Runde",
		    "Viertelfinale",
		    "Halbfinale",
		    "Finale",

		      "1st Round",   			// 32
		      "2nd Round",			// 16 
		      "Quarter Final", 		// 8
		      "Semi-Final",			// 4
		      "Final",			// 2
		
		      "1st Round",   			// 16
		      "Quarter Final",		// 8
		      "Semi-Final",			// 4
		      "Final",			// 2

		        "1are manche", 
		        "2ame manche", 
		        "Quart de finale",
		        "Demi-finale",
		        "Finale",
		      
		        "1are manche", 
		        "Quart de finale",
		        "Demi-finale",
		        "Finale",

			   "1. runde",
			   "2. runde",
			   "Kvartfinale",
			   "Semifinale",
			   "Finale",

			   "1. runde",
			   "Kvartfinale",
			   "Semifinale",
			   "Finale",


		      
			};


			
	char	*VENUES[]={

		"New York",
		"Moscow",
		"Madrid",
		"Sofia",
		"Brussels",
		"Copenhagen",
		"Belfast",
		"Tunis",
		"Lusaka",
		"Zurich",
		"Yaoynde",
		"Seoul",
		"Rome",
		"Rabat",
		"London",
		"Glasgow",
		"Cardiff",
		"Cairo",
		"Bogota",
		"Stockholm",
		"Buenos Aires",
		"Dublin",
		"Amsterdam",
		"Helsinki",
		"Bratislava",
		"Abidjan",
		"Accra",
		"Bucharest",
		"Berlin",
		"Athens",
		"Oslo",
		"Riyadh",
		"Paris",
		"Warsaw",
		"Tokyo",
		"Montevideo",
		"Rio De Janeiro",
		"Lagos",
		"Guadalajara",	
		"Prague",
		"Reykjavik",
		"Lisbon",
		"Peking",
		"La Paz",
		"Sheffield",

			"New York",
			"Moscou",	// ok
			"Madrid",	// ok
			"Sofia",
			"Bruxelles",
			"Copenhagen",	// ok
			"Belfast",
			"Tunis",	// ok
			"Lusaka",
			"Zurich",
			"Yaoynde",
			"Seoul",
			"Rome",
			"Rabat",
			"Londres",	// ok
			"Glasgow",
			"Cardiff",
			"Caire",	// ok
			"Bogota",
			"Stockholm",
			"Buenos Aires",
			"Dublin",
			"Amsterdam",
			"Helsinki",
			"Bratislava",
			"Abidjan",
			"Accra",
			"Bucharest",
			"Berlin",
			"Athenes",	// ok
			"Oslo",
			"Riyadh",
			"Paris",        // ok
			"Varsovie",	// ok
			"Tokyo",
			"Montevideo",
			"Rio De Janeiro",
			"Lagos",
			"Guadalajara",	
			"Prague",
			"Reykjavik",
			"Lisbon",
			"Pekin",
			"La Paz",
			"Sheffield",

				"New York", 	
				"Moskau",	//ok 1
				"Madrid",
				"Sofia",
				"Bruessel",	//ok 2
				"Kopenhagen",	//ok 3
				"Belfast",
				"Tunis",
				"Lusaka",
				"Zuerich",	//ok 4
				"Jaunde",	//ok 5
				"Seoul",
				"Rom",		//ok 6
				"Rabat",
				"London",
				"Glasgow",
				"Cardiff",
				"Kairo",	//ok 7
				"Bogota",
				"Stockholm",
				"Buenos Aires",
				"Dublin",
				"Amsterdam",
				"Helsinki",
				"Bratyslawa",	//ok 8
				"Abidzan",	//ok 9
				"Akra",		//ok 10
				"Bukarest",	//ok 11
				"Berlin",
				"Athen",	//ok 12
				"Oslo",
				"Riad",		//ok 13
				"Paris",
				"Warschau",	//ok 14
				"Tokio", 	//ok 15
				"Montevideo",
				"Rio De Janeiro",
				"Lagos",
				"Guadalajara",	
				"Prag",		//ok 16
				"Reykjavik",
				"Lissabon",	//ok 17
				"Peking",
				"La Paz",
				"Sheffield",

					"New York",
					"Moscow",
					"Madrid",
					"Sofia",
					"Brussels",
					"Copenhagen",
					"Belfast",
					"Tunis",
					"Lusaka",
					"Zurich",
					"Yaoynde",
					"Seoul",
					"Rome",
					"Rabat",
					"London",
					"Glasgow",
					"Cardiff",
					"Cairo",
					"Bogota",
					"Stockholm",
					"Buenos Aires",
					"Dublin",
					"Amsterdam",
					"Helsinki",
					"Bratislava",
					"Abidjan",
					"Accra",
					"Bucharest",
					"Berlin",
					"Athens",
					"Oslo",
					"Riyadh",
					"Paris",
					"Warsaw",
					"Tokyo",
					"Montevideo",
					"Rio De Janeiro",
					"Lagos",
					"Guadalajara",	
					"Prague",
					"Reykjavik",
					"Lisbon",
					"Peking",
					"La Paz",
					"Sheffield",
			
						"New York",
						"Moscou",	// ok
						"Madrid",	// ok
						"Sofia",
						"Bruxelles",
						"Copenhagen",	// ok
						"Belfast",
						"Tunis",	// ok
						"Lusaka",
						"Zurich",
						"Yaoynde",
						"Seoul",
						"Rome",
						"Rabat",
						"Londres",	// ok
						"Glasgow",
						"Cardiff",
						"Caire",	// ok
						"Bogota",
						"Stockholm",
						"Buenos Aires",
						"Dublin",
						"Amsterdam",
						"Helsinki",
						"Bratislava",
						"Abidjan",
						"Accra",
						"Bucharest",
						"Berlin",
						"Athenes",	// ok
						"Oslo",
						"Riyadh",
						"Paris",        // ok
						"Varsovie",	// ok
						"Tokyo",
						"Montevideo",
						"Rio De Janeiro",
						"Lagos",
						"Guadalajara",	
						"Prague",
						"Reykjavik",
						"Lisbon",
						"Pekin",
						"La Paz",
						"Sheffield",

							"New York",
							"Moskva",
							"Madrid",
							"Sofia",
							"Brussel",
							"K�benhavn",
							"Belfast",
							"Tunis",
							"Lusaka",
							"Zurich",
							"Yaoynde",
							"Seoul",
							"Roma",
							"Rabat",
							"London",
							"Glasgow",
							"Cardiff",
							"Kairo",
							"Bogota",
							"Stockholm",
							"Buenos Aires",
							"Dublin",
							"Amsterdam",
							"Helsinki",
							"Bratislava",
							"Abidjan",
							"Accra",
							"Bucharest",
							"Berlin",
							"Athen",
							"Oslo",
							"Riyadh",
							"Paris",
							"Warsawa",
							"Tokyo",
							"Montevideo",
							"Rio de Janeiro",
							"Lagos",
							"Guadalajara",
							"Praha",
							"Reykjavik",
							"Lisboa",
							"Peking",
							"La Paz",
							"Sheffield",	
				};
						
#endif


	
//int allocation_flags[]={ NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

copydata	copy_list[MAX_COPIES]; /* ={
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
		{NULL,NULL,NULL,NULL,NULL,},
			      };
*/

choose_info	choose_data[5]={

		{
		-14,6,
		-14,22,		
		-14,38,
// 4 TEAMS
		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME, 
		TABx16TEAMS+(sprite_S62width/2),                             A03yPOS-2+(3*A03yOFFSET)+76, 
                TABx16TEAMS,                                                 A03yPOS-2+(3*A03yOFFSET)+16,
                TABx16TEAMS,                                                 A03yPOS-2+(3*A03yOFFSET)+16,
		TABx16TEAMS+sprite_S62width,				     A03yPOS-2+(3*A03yOFFSET)+16+sprite_S62height+24,
                TABx16TEAMS-16,                                              A03yPOS-2+(3*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(2*TABx16TEAMS)+(sprite_S62width)+(sprite_S62width/2),       A03yPOS-2+(3*A03yOFFSET)+76, 
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(3*A03yOFFSET)+16,
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(3*A03yOFFSET)+16,
		(2*TABx16TEAMS)+(sprite_S62width)+sprite_S62width,	     A03yPOS-2+(3*A03yOFFSET)+16+sprite_S62height+24,
                (2*TABx16TEAMS)+(sprite_S62width)-16,                        A03yPOS-2+(3*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(3*TABx16TEAMS)+(2*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(3*A03yOFFSET)+76, 
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(3*A03yOFFSET)+16,
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(3*A03yOFFSET)+16,
		(3*TABx16TEAMS)+(2*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(3*A03yOFFSET)+16+sprite_S62height+24,
                (3*TABx16TEAMS)+(2*sprite_S62width)-16,                      A03yPOS-2+(3*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(4*TABx16TEAMS)+(3*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(3*A03yOFFSET)+76, 
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(3*A03yOFFSET)+16,
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(3*A03yOFFSET)+16,
		(4*TABx16TEAMS)+(3*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(3*A03yOFFSET)+16+sprite_S62height+24,
                (4*TABx16TEAMS)+(3*sprite_S62width)-16,                      A03yPOS-2+(3*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		},

		{
		-14,6,
		-14,22,		
		-14,38,
// 8 TEAMS
		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME, 
		TABx16TEAMS+(sprite_S62width/2),                             A03yPOS-2+(1*A03yOFFSET)+76, 
                TABx16TEAMS,                                                 A03yPOS-2+(1*A03yOFFSET)+16,
                TABx16TEAMS,                                                 A03yPOS-2+(1*A03yOFFSET)+16,
		TABx16TEAMS+sprite_S62width,				     A03yPOS-2+(1*A03yOFFSET)+16+sprite_S62height+24,
                TABx16TEAMS-16,                                              A03yPOS-2+(1*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(2*TABx16TEAMS)+(sprite_S62width)+(sprite_S62width/2),       A03yPOS-2+(1*A03yOFFSET)+76, 
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(1*A03yOFFSET)+16,
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(1*A03yOFFSET)+16,
		(2*TABx16TEAMS)+(sprite_S62width)+sprite_S62width,	     A03yPOS-2+(1*A03yOFFSET)+16+sprite_S62height+24,
                (2*TABx16TEAMS)+(sprite_S62width)-16,                        A03yPOS-2+(1*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(3*TABx16TEAMS)+(2*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(1*A03yOFFSET)+76, 
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(1*A03yOFFSET)+16,
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(1*A03yOFFSET)+16,
		(3*TABx16TEAMS)+(2*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(1*A03yOFFSET)+16+sprite_S62height+24,
                (3*TABx16TEAMS)+(2*sprite_S62width)-16,                      A03yPOS-2+(1*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(4*TABx16TEAMS)+(3*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(1*A03yOFFSET)+76, 
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(1*A03yOFFSET)+16,
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(1*A03yOFFSET)+16,
		(4*TABx16TEAMS)+(3*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(1*A03yOFFSET)+16+sprite_S62height+24,
                (4*TABx16TEAMS)+(3*sprite_S62width)-16,                      A03yPOS-2+(1*A03yOFFSET)+76,
		sprite_S62width+28,				             24,


		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		TABx16TEAMS+(sprite_S62width/2),                             A03yPOS-2+(6*A03yOFFSET)+76-8, 
                TABx16TEAMS,                                                 A03yPOS-2+(6*A03yOFFSET)+16-8,
                TABx16TEAMS,                                                 A03yPOS-2+(6*A03yOFFSET)+16-8,
		TABx16TEAMS+sprite_S62width,				     A03yPOS-2+(6*A03yOFFSET)+16-8+sprite_S62height+24,
                TABx16TEAMS-16,                                              A03yPOS-2+(6*A03yOFFSET)+76-8,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(2*TABx16TEAMS)+(sprite_S62width)+(sprite_S62width/2),       A03yPOS-2+(6*A03yOFFSET)+76-8, 
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(6*A03yOFFSET)+16-8,
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(6*A03yOFFSET)+16-8,
		(2*TABx16TEAMS)+(sprite_S62width)+sprite_S62width,	     A03yPOS-2+(6*A03yOFFSET)+16-8+sprite_S62height+24,
                (2*TABx16TEAMS)+(sprite_S62width)-16,                        A03yPOS-2+(6*A03yOFFSET)+76-8,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(3*TABx16TEAMS)+(2*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(6*A03yOFFSET)+76-8, 
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(6*A03yOFFSET)+16-8,
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(6*A03yOFFSET)+16-8,
		(3*TABx16TEAMS)+(2*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(6*A03yOFFSET)+16-8+sprite_S62height+24,
                (3*TABx16TEAMS)+(2*sprite_S62width)-16,                      A03yPOS-2+(6*A03yOFFSET)+76-8,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(4*TABx16TEAMS)+(3*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(6*A03yOFFSET)+76-8, 
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(6*A03yOFFSET)+16-8,
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(6*A03yOFFSET)+16-8,
		(4*TABx16TEAMS)+(3*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(6*A03yOFFSET)+16-8+sprite_S62height+24,
                (4*TABx16TEAMS)+(3*sprite_S62width)-16,                      A03yPOS-2+(6*A03yOFFSET)+76-8,
		sprite_S62width+28,				             24,


		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		},

		{
		-14,6,
		-14,22,		
		-14,38,
// 16 TEAMS
		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME, 
		TABx16TEAMS+(sprite_S62width/2),                             A03yPOS-2+(0*A03yOFFSET)+76, 
                TABx16TEAMS,                                                 A03yPOS-2+(0*A03yOFFSET)+16,
                TABx16TEAMS,                                                 A03yPOS-2+(0*A03yOFFSET)+16,
		TABx16TEAMS+sprite_S62width,				     A03yPOS-2+(0*A03yOFFSET)+16+sprite_S62height+24,
                TABx16TEAMS-16,                                              A03yPOS-2+(0*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(2*TABx16TEAMS)+(sprite_S62width)+(sprite_S62width/2),       A03yPOS-2+(0*A03yOFFSET)+76, 
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(0*A03yOFFSET)+16,
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(0*A03yOFFSET)+16,
		(2*TABx16TEAMS)+(sprite_S62width)+sprite_S62width,	     A03yPOS-2+(0*A03yOFFSET)+16+sprite_S62height+24,
                (2*TABx16TEAMS)+(sprite_S62width)-16,                        A03yPOS-2+(0*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(3*TABx16TEAMS)+(2*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(0*A03yOFFSET)+76, 
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(0*A03yOFFSET)+16,
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(0*A03yOFFSET)+16,
		(3*TABx16TEAMS)+(2*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(0*A03yOFFSET)+16+sprite_S62height+24,
                (3*TABx16TEAMS)+(2*sprite_S62width)-16,                      A03yPOS-2+(0*A03yOFFSET)+76,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(4*TABx16TEAMS)+(3*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(0*A03yOFFSET)+76, 
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(0*A03yOFFSET)+16,
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(0*A03yOFFSET)+16,
		(4*TABx16TEAMS)+(3*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(0*A03yOFFSET)+16+sprite_S62height+24,
                (4*TABx16TEAMS)+(3*sprite_S62width)-16,                      A03yPOS-2+(0*A03yOFFSET)+76,
		sprite_S62width+28,				             24,


		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		TABx16TEAMS+(sprite_S62width/2),                             A03yPOS-2+(3*A03yOFFSET)+76-8, 
                TABx16TEAMS,                                                 A03yPOS-2+(3*A03yOFFSET)+16-8,
                TABx16TEAMS,                                                 A03yPOS-2+(3*A03yOFFSET)+16-8,
		TABx16TEAMS+sprite_S62width,				     A03yPOS-2+(3*A03yOFFSET)+16-8+sprite_S62height+24,
                TABx16TEAMS-16,                                              A03yPOS-2+(3*A03yOFFSET)+76-8,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(2*TABx16TEAMS)+(sprite_S62width)+(sprite_S62width/2),       A03yPOS-2+(3*A03yOFFSET)+76-8, 
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(3*A03yOFFSET)+16-8,
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(3*A03yOFFSET)+16-8,
		(2*TABx16TEAMS)+(sprite_S62width)+sprite_S62width,	     A03yPOS-2+(3*A03yOFFSET)+16-8+sprite_S62height+24,
                (2*TABx16TEAMS)+(sprite_S62width)-16,                        A03yPOS-2+(3*A03yOFFSET)+76-8,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(3*TABx16TEAMS)+(2*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(3*A03yOFFSET)+76-8, 
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(3*A03yOFFSET)+16-8,
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(3*A03yOFFSET)+16-8,
		(3*TABx16TEAMS)+(2*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(3*A03yOFFSET)+16-8+sprite_S62height+24,
                (3*TABx16TEAMS)+(2*sprite_S62width)-16,                      A03yPOS-2+(3*A03yOFFSET)+76-8,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(4*TABx16TEAMS)+(3*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(3*A03yOFFSET)+76-8, 
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(3*A03yOFFSET)+16-8,
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(3*A03yOFFSET)+16-8,
		(4*TABx16TEAMS)+(3*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(3*A03yOFFSET)+16-8+sprite_S62height+24,
                (4*TABx16TEAMS)+(3*sprite_S62width)-16,                      A03yPOS-2+(3*A03yOFFSET)+76-8,
		sprite_S62width+28,				             24,


		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		TABx16TEAMS+(sprite_S62width/2),                             A03yPOS-2+(6*A03yOFFSET)+76-16, 
                TABx16TEAMS,                                                 A03yPOS-2+(6*A03yOFFSET)+16-16,
                TABx16TEAMS,                                                 A03yPOS-2+(6*A03yOFFSET)+16-16,
		TABx16TEAMS+sprite_S62width,				     A03yPOS-2+(6*A03yOFFSET)+16-16+sprite_S62height+24,
                TABx16TEAMS-16,                                              A03yPOS-2+(6*A03yOFFSET)+76-16,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(2*TABx16TEAMS)+(sprite_S62width)+(sprite_S62width/2),       A03yPOS-2+(6*A03yOFFSET)+76-16, 
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(6*A03yOFFSET)+16-16,
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(6*A03yOFFSET)+16-16,
		(2*TABx16TEAMS)+(sprite_S62width)+sprite_S62width,	     A03yPOS-2+(6*A03yOFFSET)+16-16+sprite_S62height+24,
                (2*TABx16TEAMS)+(sprite_S62width)-16,                        A03yPOS-2+(6*A03yOFFSET)+76-16,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(3*TABx16TEAMS)+(2*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(6*A03yOFFSET)+76-16, 
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(6*A03yOFFSET)+16-16,
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(6*A03yOFFSET)+16-16,
		(3*TABx16TEAMS)+(2*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(6*A03yOFFSET)+16-16+sprite_S62height+24,
                (3*TABx16TEAMS)+(2*sprite_S62width)-16,                      A03yPOS-2+(6*A03yOFFSET)+76-16,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(4*TABx16TEAMS)+(3*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(6*A03yOFFSET)+76-16, 
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(6*A03yOFFSET)+16-16,
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(6*A03yOFFSET)+16-16,
		(4*TABx16TEAMS)+(3*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(6*A03yOFFSET)+16-16+sprite_S62height+24,
                (4*TABx16TEAMS)+(3*sprite_S62width)-16,                      A03yPOS-2+(6*A03yOFFSET)+76-16,
		sprite_S62width+28,				             24,


		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		TABx16TEAMS+(sprite_S62width/2),                             A03yPOS-2+(9*A03yOFFSET)+76-24, 
                TABx16TEAMS,                                                 A03yPOS-2+(9*A03yOFFSET)+16-24,
                TABx16TEAMS,                                                 A03yPOS-2+(9*A03yOFFSET)+16-24,
		TABx16TEAMS+sprite_S62width,				     A03yPOS-2+(9*A03yOFFSET)+16-24+sprite_S62height+24,
                TABx16TEAMS-16,                                              A03yPOS-2+(9*A03yOFFSET)+76-24,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(2*TABx16TEAMS)+(sprite_S62width)+(sprite_S62width/2),       A03yPOS-2+(9*A03yOFFSET)+76-24, 
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(9*A03yOFFSET)+16-24,
                (2*TABx16TEAMS)+(sprite_S62width),                           A03yPOS-2+(9*A03yOFFSET)+16-24,
		(2*TABx16TEAMS)+(sprite_S62width)+sprite_S62width,	     A03yPOS-2+(9*A03yOFFSET)+16-24+sprite_S62height+24,
                (2*TABx16TEAMS)+(sprite_S62width)-16,                        A03yPOS-2+(9*A03yOFFSET)+76-24,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(3*TABx16TEAMS)+(2*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(9*A03yOFFSET)+76-24, 
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(9*A03yOFFSET)+16-24,
                (3*TABx16TEAMS)+(2*sprite_S62width),                         A03yPOS-2+(9*A03yOFFSET)+16-24,
		(3*TABx16TEAMS)+(2*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(9*A03yOFFSET)+16-24+sprite_S62height+24,
                (3*TABx16TEAMS)+(2*sprite_S62width)-16,                      A03yPOS-2+(9*A03yOFFSET)+76-24,
		sprite_S62width+28,				             24,

		SHADOWtextON|SFONT|CENTREjustifyTEXT, LARGE|SHADOW, CHOOSE_TEAM_NAME,
		(4*TABx16TEAMS)+(3*sprite_S62width)+(sprite_S62width/2),     A03yPOS-2+(9*A03yOFFSET)+76-24, 
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(9*A03yOFFSET)+16-24,
                (4*TABx16TEAMS)+(3*sprite_S62width),                         A03yPOS-2+(9*A03yOFFSET)+16-24,
		(4*TABx16TEAMS)+(3*sprite_S62width)+sprite_S62width,	     A03yPOS-2+(9*A03yOFFSET)+16-24+sprite_S62height+24,
                (4*TABx16TEAMS)+(3*sprite_S62width)-16,                      A03yPOS-2+(9*A03yOFFSET)+76-24,
		sprite_S62width+28,				             24,


		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		},




		{
		50,4,
		66,4,		
		82,4,
// 32 TEAMS
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(1*TABx32TEAMS)+(sprite_S62width/4),                          A03yPOS-14+(0*A03yOFFSET)+54, 
		(1*TABx32TEAMS),                          	              A03yPOS-14+(0*A03yOFFSET)+24,
		(1*TABx32TEAMS),                          	              A03yPOS-14+(0*A03yOFFSET)+24,
		(1*TABx32TEAMS)+(sprite_S62width/2),                          A03yPOS-14+(0*A03yOFFSET)+24+(sprite_S62height/2)+20, 
		(1*TABx32TEAMS)-36,                          		      A03yPOS-14+(0*A03yOFFSET)+54, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(0*A03yOFFSET)+54, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2)), 		      A03yPOS-14+(0*A03yOFFSET)+24,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(0*A03yOFFSET)+24,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(0*A03yOFFSET)+24+(sprite_S62height/2)+20, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))-36,                   A03yPOS-14+(0*A03yOFFSET)+54, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(0*A03yOFFSET)+54, 
                (5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(0*A03yOFFSET)+24,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(0*A03yOFFSET)+24,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(0*A03yOFFSET)+24+(sprite_S62height/2)+20, 
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))-36,                   A03yPOS-14+(0*A03yOFFSET)+54, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(0*A03yOFFSET)+54, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(0*A03yOFFSET)+24,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(0*A03yOFFSET)+24,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(0*A03yOFFSET)+24+(sprite_S62height/2)+20, 
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))-36,                   A03yPOS-14+(0*A03yOFFSET)+54, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(0*A03yOFFSET)+54, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(0*A03yOFFSET)+24,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(0*A03yOFFSET)+24,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(0*A03yOFFSET)+24+(sprite_S62height/2)+20, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))-36,                   A03yPOS-14+(0*A03yOFFSET)+54, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (1*TABx32TEAMS)+(sprite_S62width/4),                          A03yPOS-14+(2*A03yOFFSET)+54-8, 
		(1*TABx32TEAMS),                                              A03yPOS-14+(2*A03yOFFSET)+24-8,
		(1*TABx32TEAMS),                          	              A03yPOS-14+(2*A03yOFFSET)+24-8,
		(1*TABx32TEAMS)+(sprite_S62width/2),                          A03yPOS-14+(2*A03yOFFSET)+24-8+(sprite_S62height/2)+20, 
		(1*TABx32TEAMS)-36,                          		      A03yPOS-14+(2*A03yOFFSET)+54-8, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(2*A03yOFFSET)+54-8, 
                (3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(2*A03yOFFSET)+24-8,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(2*A03yOFFSET)+24-8,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(2*A03yOFFSET)+24-8+(sprite_S62height/2)+20, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))-36,                   A03yPOS-14+(2*A03yOFFSET)+54-8, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(2*A03yOFFSET)+54-8, 
                (5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(2*A03yOFFSET)+24-8,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(2*A03yOFFSET)+24-8,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(2*A03yOFFSET)+24-8+(sprite_S62height/2)+20, 
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))-36,                   A03yPOS-14+(2*A03yOFFSET)+54-8, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(2*A03yOFFSET)+54-8, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(2*A03yOFFSET)+24-8,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(2*A03yOFFSET)+24-8,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(2*A03yOFFSET)+24-8+(sprite_S62height/2)+20, 
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))-36,                   A03yPOS-14+(2*A03yOFFSET)+54-8, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(2*A03yOFFSET)+54-8, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(2*A03yOFFSET)+24-8,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(2*A03yOFFSET)+24-8,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(2*A03yOFFSET)+24-8+(sprite_S62height/2)+20, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))-36,                   A03yPOS-14+(2*A03yOFFSET)+54-8, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (1*TABx32TEAMS)+(sprite_S62width/4),                          A03yPOS-14+(4*A03yOFFSET)+54-16, 
                (1*TABx32TEAMS),                                              A03yPOS-14+(4*A03yOFFSET)+24-16,
		(1*TABx32TEAMS),                          	              A03yPOS-14+(4*A03yOFFSET)+24-16,
		(1*TABx32TEAMS)+(sprite_S62width/2),                          A03yPOS-14+(4*A03yOFFSET)+24-16+(sprite_S62height/2)+20, 
		(1*TABx32TEAMS)-36,                          		      A03yPOS-14+(4*A03yOFFSET)+54-16, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(4*A03yOFFSET)+54-16, 
                (3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(4*A03yOFFSET)+24-16,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(4*A03yOFFSET)+24-16,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(4*A03yOFFSET)+24-16+(sprite_S62height/2)+20, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))-36,                   A03yPOS-14+(4*A03yOFFSET)+54-16, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(4*A03yOFFSET)+54-16, 
                (5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(4*A03yOFFSET)+24-16,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(4*A03yOFFSET)+24-16,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(4*A03yOFFSET)+24-16+(sprite_S62height/2)+20, 
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))-36,                   A03yPOS-14+(4*A03yOFFSET)+54-16, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(4*A03yOFFSET)+54-16, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(4*A03yOFFSET)+24-16,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(4*A03yOFFSET)+24-16,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(4*A03yOFFSET)+24-16+(sprite_S62height/2)+20, 
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))-36,                   A03yPOS-14+(4*A03yOFFSET)+54-16, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(4*A03yOFFSET)+54-16, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(4*A03yOFFSET)+24-16,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(4*A03yOFFSET)+24-16,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(4*A03yOFFSET)+24-16+(sprite_S62height/2)+20, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))-36,                   A03yPOS-14+(4*A03yOFFSET)+54-16, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (1*TABx32TEAMS)+(sprite_S62width/4),                          A03yPOS-14+(6*A03yOFFSET)+54-24, 
                (1*TABx32TEAMS),                                              A03yPOS-14+(6*A03yOFFSET)+24-24,
		(1*TABx32TEAMS),                          	              A03yPOS-14+(6*A03yOFFSET)+24-24,
		(1*TABx32TEAMS)+(sprite_S62width/2),                          A03yPOS-14+(6*A03yOFFSET)+24-24+(sprite_S62height/2)+20, 
		(1*TABx32TEAMS)-36,                          		      A03yPOS-14+(6*A03yOFFSET)+54-24, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(6*A03yOFFSET)+54-24, 
                (3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(6*A03yOFFSET)+24-24,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(6*A03yOFFSET)+24-24,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(6*A03yOFFSET)+24-24+(sprite_S62height/2)+20, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))-36,                   A03yPOS-14+(6*A03yOFFSET)+54-24, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(6*A03yOFFSET)+54-24, 
	        (5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(6*A03yOFFSET)+24-24,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(6*A03yOFFSET)+24-24,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(6*A03yOFFSET)+24-24+(sprite_S62height/2)+20, 
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))-36,                   A03yPOS-14+(6*A03yOFFSET)+54-24, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(6*A03yOFFSET)+54-24, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(6*A03yOFFSET)+24-24,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(6*A03yOFFSET)+24-24,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(6*A03yOFFSET)+24-24+(sprite_S62height/2)+20, 
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))-36,                   A03yPOS-14+(6*A03yOFFSET)+54-24, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(6*A03yOFFSET)+54-24, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(6*A03yOFFSET)+24-24,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(6*A03yOFFSET)+24-24,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(6*A03yOFFSET)+24-24+(sprite_S62height/2)+20, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))-36,                   A03yPOS-14+(6*A03yOFFSET)+54-24, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(1*TABx32TEAMS)+(sprite_S62width/4),                          A03yPOS-14+(8*A03yOFFSET)+54-32, 
                (1*TABx32TEAMS),                                              A03yPOS-14+(8*A03yOFFSET)+24-32,
		(1*TABx32TEAMS),                          	              A03yPOS-14+(8*A03yOFFSET)+24-32,
		(1*TABx32TEAMS)+(sprite_S62width/2),                          A03yPOS-14+(8*A03yOFFSET)+24-32+(sprite_S62height/2)+20, 
		(1*TABx32TEAMS)-36,                          		      A03yPOS-14+(8*A03yOFFSET)+54-32, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(8*A03yOFFSET)+54-32, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2)), 		      A03yPOS-14+(8*A03yOFFSET)+24-32,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(8*A03yOFFSET)+24-32,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(8*A03yOFFSET)+24-32+(sprite_S62height/2)+20, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))-36,                   A03yPOS-14+(8*A03yOFFSET)+54-32, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(8*A03yOFFSET)+54-32, 
		(5*TABx32TEAMS)+(2*(sprite_S62width/2)), 		      A03yPOS-14+(8*A03yOFFSET)+24-32,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(8*A03yOFFSET)+24-32,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(8*A03yOFFSET)+24-32+(sprite_S62height/2)+20, 
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))-36,                   A03yPOS-14+(8*A03yOFFSET)+54-32, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(8*A03yOFFSET)+54-32, 
		(7*TABx32TEAMS)+(3*(sprite_S62width/2)), 		      A03yPOS-14+(8*A03yOFFSET)+24-32,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(8*A03yOFFSET)+24-32,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(8*A03yOFFSET)+24-32+(sprite_S62height/2)+20, 
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))-36,                   A03yPOS-14+(8*A03yOFFSET)+54-32, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(8*A03yOFFSET)+54-32, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)), 		      A03yPOS-14+(8*A03yOFFSET)+24-32,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(8*A03yOFFSET)+24-32,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(8*A03yOFFSET)+24-32+(sprite_S62height/2)+20, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))-36,                   A03yPOS-14+(8*A03yOFFSET)+54-32, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(1*TABx32TEAMS)+(sprite_S62width/4),                          A03yPOS-14+(10*A03yOFFSET)+54-40, 
		(1*TABx32TEAMS),                             		      A03yPOS-14+(10*A03yOFFSET)+24-40,
		(1*TABx32TEAMS),                          	              A03yPOS-14+(10*A03yOFFSET)+24-40,
		(1*TABx32TEAMS)+(sprite_S62width/2),                          A03yPOS-14+(10*A03yOFFSET)+24-40+(sprite_S62height/2)+20, 
		(1*TABx32TEAMS)-36,                          		      A03yPOS-14+(10*A03yOFFSET)+54-40, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(10*A03yOFFSET)+54-40, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(10*A03yOFFSET)+24-40,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2)),                      A03yPOS-14+(10*A03yOFFSET)+24-40,
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(10*A03yOFFSET)+24-40+(sprite_S62height/2)+20, 
		(3*TABx32TEAMS)+(1*(sprite_S62width/2))-36,                   A03yPOS-14+(10*A03yOFFSET)+54-40, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(10*A03yOFFSET)+54-40, 
                (5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(10*A03yOFFSET)+24-40,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2)),                      A03yPOS-14+(10*A03yOFFSET)+24-40,
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(10*A03yOFFSET)+24-40+(sprite_S62height/2)+20, 
		(5*TABx32TEAMS)+(2*(sprite_S62width/2))-36,                   A03yPOS-14+(10*A03yOFFSET)+54-40, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(10*A03yOFFSET)+54-40, 
                (7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(10*A03yOFFSET)+24-40,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2)),                      A03yPOS-14+(10*A03yOFFSET)+24-40,
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(10*A03yOFFSET)+24-40+(sprite_S62height/2)+20, 
		(7*TABx32TEAMS)+(3*(sprite_S62width/2))-36,                   A03yPOS-14+(10*A03yOFFSET)+54-40, 
		(sprite_S62width/2)+74,                                       24, 
				
		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(10*A03yOFFSET)+54-40, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)), 		      A03yPOS-14+(10*A03yOFFSET)+24-40,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(10*A03yOFFSET)+24-40,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(10*A03yOFFSET)+24-40+(sprite_S62height/2)+20, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))-36,                   A03yPOS-14+(10*A03yOFFSET)+54-40, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		(1*TABx32TEAMS)+(sprite_S62width/4),                          A03yPOS-14+(12*A03yOFFSET)+54-48, 
		(1*TABx32TEAMS),                             		      A03yPOS-14+(12*A03yOFFSET)+24-48,
		(1*TABx32TEAMS),                          	              A03yPOS-14+(12*A03yOFFSET)+24-48,
		(1*TABx32TEAMS)+(sprite_S62width/2),                          A03yPOS-14+(12*A03yOFFSET)+24-48+(sprite_S62height/2)+20, 
		(1*TABx32TEAMS)-36,                          		      A03yPOS-14+(12*A03yOFFSET)+54-48, 
		(sprite_S62width/2)+74,                                       24, 

		SHADOWtextON|SFONT|CENTREjustifyTEXT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/4),  A03yPOS-14+(12*A03yOFFSET)+54-48, 
                (9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(12*A03yOFFSET)+24-48,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2)),                      A03yPOS-14+(12*A03yOFFSET)+24-48,
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))+(sprite_S62width/2),  A03yPOS-14+(12*A03yOFFSET)+24-48+(sprite_S62height/2)+20, 
		(9*TABx32TEAMS)+(4*(sprite_S62width/2))-36,                   A03yPOS-14+(12*A03yOFFSET)+54-48, 
		(sprite_S62width/2)+74,                                       24, 

		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		},

		{
		50, 15,
		66, 15,		
		82, 15,
// 44 TEAMS
		SHADOWtextON|TIGHTEN|SFONT, SMALL|SHADOW, CHOOSE_TEAM_NAME, 
		A03xTAB+A03xINDENT, 		A15yPOS+A15yINDENT, 
		A03xTAB, 			A15yPOS,

		A03xTAB, A15yPOS,
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS,
		A03xTAB+A03xINDENT,A15yPOS+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(1*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(1*A03yOFFSET),
		A03xTAB, A15yPOS+(1*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(1*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(1*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(2*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(2*A03yOFFSET),
		A03xTAB, A15yPOS+(2*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(2*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(2*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(3*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(3*A03yOFFSET),
		A03xTAB, A15yPOS+(3*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(3*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(3*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(4*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(4*A03yOFFSET),
		A03xTAB, A15yPOS+(4*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(4*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(4*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(5*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(5*A03yOFFSET),
		A03xTAB, A15yPOS+(5*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(5*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(5*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(6*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(6*A03yOFFSET),
		A03xTAB, A15yPOS+(6*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(6*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(6*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(7*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(7*A03yOFFSET),
		A03xTAB, A15yPOS+(7*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(7*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(7*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(8*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(8*A03yOFFSET),
		A03xTAB, A15yPOS+(8*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(8*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(8*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(9*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(9*A03yOFFSET),
		A03xTAB, A15yPOS+(9*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(9*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(9*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+A03xINDENT,A15yPOS+(10*A03yOFFSET)+A15yINDENT,A03xTAB, A15yPOS+(10*A03yOFFSET),
		A03xTAB, A15yPOS+(10*A03yOFFSET),
		A03xTAB+A03xOFFSET,A03yOFFSET+A15yPOS+(10*A03yOFFSET),
		A03xTAB+A03xINDENT,A15yPOS+(10*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS,
		A03xTAB+(1*A03xOFFSET), A15yPOS,
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS,
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(1*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(1*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(1*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(1*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(1*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(2*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(2*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(2*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(2*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(2*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(3*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(3*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(3*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(3*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(3*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(4*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(4*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(4*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(4*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(4*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(5*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(5*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(5*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(5*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(5*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(6*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(6*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(6*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(6*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(6*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(7*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(7*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(7*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(7*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(7*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(8*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(8*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(8*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(8*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(8*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(9*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(9*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(9*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(9*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(9*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(10*A03yOFFSET)+A15yINDENT,A03xTAB+(1*A03xOFFSET), A15yPOS+(10*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET), A15yPOS+(10*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET) ,A03yOFFSET+A15yPOS+(10*A03yOFFSET),
		A03xTAB+(1*A03xOFFSET)+A03xINDENT,A15yPOS+(10*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT)+3,32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS,
		A03xTAB+(2*A03xOFFSET), A15yPOS,
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS,
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(1*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(1*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(1*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(1*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(1*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(2*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(2*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(2*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(2*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(2*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(3*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(3*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(3*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(3*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(3*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(4*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(4*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(4*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(4*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(4*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(5*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(5*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(5*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(5*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(5*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(6*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(6*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(6*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(6*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(6*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(7*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(7*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(7*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(7*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(7*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(8*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(8*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(8*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(8*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(8*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(9*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(9*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(9*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(9*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(9*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(10*A03yOFFSET)+A15yINDENT,A03xTAB+(2*A03xOFFSET), A15yPOS+(10*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET), A15yPOS+(10*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET) ,A03yOFFSET+A15yPOS+(10*A03yOFFSET),
		A03xTAB+(2*A03xOFFSET)+A03xINDENT,A15yPOS+(10*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS,
		A03xTAB+(3*A03xOFFSET), A15yPOS,
		A03xTAB+(4*A03xOFFSET) ,A03yOFFSET+A15yPOS,
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(1*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(1*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET), A15yPOS+(1*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET) ,A03yOFFSET+A15yPOS+(1*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(1*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(2*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(2*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET), A15yPOS+(2*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET) ,A03yOFFSET+A15yPOS+(2*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(2*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(3*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(3*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET), A15yPOS+(3*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET) ,A03yOFFSET+A15yPOS+(3*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(3*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(4*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(4*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET), A15yPOS+(4*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET) ,A03yOFFSET+A15yPOS+(4*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(4*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(5*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(5*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET), A15yPOS+(5*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET) ,A03yOFFSET+A15yPOS+(5*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(5*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(6*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(6*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET), A15yPOS+(6*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET) ,A03yOFFSET+A15yPOS+(6*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(6*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT),32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(7*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(7*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET),                        A15yPOS+(7*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET),                        A03yOFFSET+A15yPOS+(7*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,             A15yPOS+(7*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT), 32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(8*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(8*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET),                        A15yPOS+(8*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET),                        A03yOFFSET+A15yPOS+(8*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,             A15yPOS+(8*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT), 32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(9*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(9*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET),                        A15yPOS+(9*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET),                        A03yOFFSET+A15yPOS+(9*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,             A15yPOS+(9*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT), 32,

		SHADOWtextON|TIGHTEN|SFONT,SMALL|SHADOW,CHOOSE_TEAM_NAME,A03xTAB+(3*A03xOFFSET)+A03xINDENT,A15yPOS+(10*A03yOFFSET)+A15yINDENT,A03xTAB+(3*A03xOFFSET), A15yPOS+(10*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET),                        A15yPOS+(10*A03yOFFSET),
		A03xTAB+(4*A03xOFFSET),                        A03yOFFSET+A15yPOS+(10*A03yOFFSET),
		A03xTAB+(3*A03xOFFSET)+A03xINDENT,             A15yPOS+(10*A03yOFFSET)+A15yINDENT,
		(A03xTAB+(1*A03xOFFSET))-(A03xTAB+A03xINDENT), 32,

		},

					};

controls   	control_table[16]={


	       	COMPUTER_TEXT, 0, NULL,
		NULL, NULL, NULL, 
		NULL, NULL, NULL, 
		NULL, NULL, NULL, 

		PLAYER_ONE_TEXT, 0, PLAYER1,
		NULL, NULL, NULL,
		NULL, NULL, NULL,
		NULL, NULL, NULL,

		PLAYER_TWO_TEXT, 0, PLAYER2,
		NULL, NULL, NULL,
		NULL, NULL, NULL,
		NULL, NULL, NULL,

		PLAYER_ONE_TEXT, 0,  PLAYER1,
		PLAYER_TWO_TEXT, 22, PLAYER2,
		NULL, NULL, NULL,
		NULL, NULL, NULL,

		PLAYER_THREE_TEXT, 0, PLAYER3,
		NULL, NULL, NULL,
		NULL, NULL, NULL,
		NULL, NULL, NULL,

		PLAYER_ONE_TEXT, 0,    PLAYER1,
		PLAYER_THREE_TEXT, 22, PLAYER3,
		NULL, NULL, NULL, 
		NULL, NULL, NULL, 

		PLAYER_TWO_TEXT, 0,    PLAYER2,
		PLAYER_THREE_TEXT, 22, PLAYER3,
		NULL, NULL, NULL, 
		NULL, NULL, NULL, 

		PLAYER_ONE_TEXT, 0,    PLAYER1,
		PLAYER_TWO_TEXT, 22,   PLAYER2,
		PLAYER_THREE_TEXT, 44, PLAYER3,
		NULL, NULL, NULL, 

		PLAYER_FOUR_TEXT, 0,   PLAYER4,
		NULL, NULL, NULL, 
		NULL, NULL, NULL, 
		NULL, NULL, NULL, 

		PLAYER_ONE_TEXT, 0,    PLAYER1,
		PLAYER_FOUR_TEXT, 22,  PLAYER4,
		NULL, NULL, NULL, 
		NULL, NULL, NULL, 

		PLAYER_TWO_TEXT, 0,   PLAYER2,
		PLAYER_FOUR_TEXT, 22, PLAYER4,
		NULL, NULL, NULL,
		NULL, NULL, NULL,
				
		PLAYER_ONE_TEXT, 0,   PLAYER1,
		PLAYER_TWO_TEXT, 22,  PLAYER2,
		PLAYER_FOUR_TEXT, 44, PLAYER4,
		NULL, NULL, NULL,

		PLAYER_THREE_TEXT, 0, PLAYER3,
		PLAYER_FOUR_TEXT, 22, PLAYER4,
		NULL, NULL, NULL,
		NULL, NULL, NULL,

		PLAYER_ONE_TEXT, 0,     PLAYER1,
		PLAYER_THREE_TEXT,  22, PLAYER3,
		PLAYER_FOUR_TEXT, 44,   PLAYER4,
		NULL, NULL, NULL,

		PLAYER_TWO_TEXT, 0,    PLAYER2,
		PLAYER_THREE_TEXT, 22, PLAYER3,
		PLAYER_FOUR_TEXT, 44,  PLAYER4,
		NULL, NULL, NULL,

		PLAYER_ONE_TEXT, 0,    PLAYER1,
		PLAYER_TWO_TEXT, 22,   PLAYER2,
		PLAYER_THREE_TEXT, 44, PLAYER3,
		PLAYER_FOUR_TEXT, 66,  PLAYER4,

				};








	char	friendly_controls[]={
		PLAYER1,PLAYER1,PLAYER1+PLAYER2,PLAYER1+PLAYER2,
		NULL,PLAYER2,PLAYER3,PLAYER3+PLAYER4,
				};

	int	cup_games[]={
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL,
		NULL,	NULL
				};

result_table	results[650]={
		0,0,0,0,
			     };


fixture_table	fixtures[]={
									       	// 600 matches
		(DIV1*16)+POS11,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS13,	DIV3,		

		(DIV2*16)+POS11,	(DIV2*16)+POS14,	DIV2,		
		(DIV1*16)+POS01,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS02,	DIV2,		

		(DIV1*16)+POS03,	(DIV1*16)+POS04,	DIV1,		//1
		(DIV3*16)+POS03,	(DIV3*16)+POS04,	DIV3,		//1
		(DIV2*16)+POS03,	(DIV2*16)+POS04,	DIV2,		
		(DIV1*16)+POS05,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS06,	DIV3,		

		(DIV2*16)+POS05,	(DIV2*16)+POS06,	DIV2,		

		(DIV2*16)+POS09,	(DIV2*16)+POS12,	DIV2,		
		(DIV1*16)+POS07,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS07,	(DIV2*16)+POS08,	DIV2,		

		(DIV1*16)+POS09,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS10,	DIV2,		

		(DIV1*16)+POS11,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS12,	DIV2,		

		(DIV2*16)+POS02,	(DIV2*16)+POS16,	DIV2,		
		(DIV1*16)+POS13,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS14,	DIV2,		

		(DIV1*16)+POS02,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS16,	DIV2,		

		(DIV1*16)+POS06,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS02,	(DIV2*16)+POS03,	DIV2,		

		(DIV2*16)+POS13,	(DIV2*16)+POS15,	DIV2,		
		(DIV1*16)+POS04,	(DIV1*16)+POS05,	DIV1,		//2
		(DIV3*16)+POS04,	(DIV3*16)+POS05,	DIV3,		//2
		(DIV2*16)+POS06,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS08,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS09,	DIV2,		

		(DIV2*16)+POS07,	(DIV2*16)+POS10,	DIV2,		
		(DIV1*16)+POS12,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS10,	(DIV2*16)+POS11,	DIV2,		

		(DIV1*16)+POS14,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS05,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS14,	(DIV2*16)+POS15,	DIV2,		

		(DIV2*16)+POS05,	(DIV2*16)+POS08,	DIV2,		
		(DIV1*16)+POS03,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS16,	(DIV2*16)+POS01,	DIV2,		

		(DIV1*16)+POS07,	(DIV1*16)+POS04,	DIV1,		//3
		(DIV3*16)+POS07,	(DIV3*16)+POS04,	DIV3,		//3
		(DIV2*16)+POS05,	(DIV2*16)+POS02,	DIV2,		

		(DIV1*16)+POS09,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS03,	(DIV2*16)+POS01,	DIV2,		

		(DIV2*16)+POS03,	(DIV2*16)+POS06,	DIV2,		
		(DIV1*16)+POS11,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS07,	(DIV2*16)+POS04,	DIV2,		

		(DIV1*16)+POS13,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS06,	DIV2,		

		(DIV1*16)+POS12,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS08,	DIV2,		

		(DIV2*16)+POS01,	(DIV2*16)+POS04,	DIV2,		
		(DIV1*16)+POS02,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS10,	DIV2,		

		(DIV1*16)+POS01,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS12,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS09,	DIV1,		//4
		(DIV3*16)+POS04,	(DIV3*16)+POS09,	DIV3,		//4
		(DIV2*16)+POS14,	(DIV2*16)+POS16,	DIV2,		

		(DIV2*16)+POS13,	(DIV2*16)+POS16,	DIV2,		
		(DIV1*16)+POS06,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS02,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS08,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS09,	DIV2,		

		(DIV2*16)+POS14,	(DIV2*16)+POS09,	DIV2,		
		(DIV1*16)+POS14,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS06,	(DIV2*16)+POS11,	DIV2,		

		(DIV1*16)+POS09,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS07,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS10,	(DIV2*16)+POS15,	DIV2,		

		(DIV2*16)+POS12,	(DIV2*16)+POS07,	DIV2,		
		(DIV1*16)+POS05,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS14,	DIV2,		

		(DIV1*16)+POS11,	(DIV1*16)+POS04,	DIV1,		//5
		(DIV3*16)+POS11,	(DIV3*16)+POS04,	DIV3,		//5
		(DIV2*16)+POS16,	(DIV2*16)+POS03,	DIV2,		

		(DIV1*16)+POS13,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS02,	DIV2,		

		(DIV2*16)+POS15,	(DIV2*16)+POS11,	DIV2,		
		(DIV1*16)+POS12,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS07,	(DIV2*16)+POS01,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS05,	(DIV2*16)+POS03,	DIV2,		

		(DIV1*16)+POS02,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS04,	DIV2,		

		(DIV2*16)+POS10,	(DIV2*16)+POS05,	DIV2,		
		(DIV1*16)+POS01,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS06,	DIV2,		

		(DIV1*16)+POS03,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS16,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS13,	DIV1,		//6
		(DIV3*16)+POS04,	(DIV3*16)+POS13,	DIV3,		//6
		(DIV2*16)+POS14,	(DIV2*16)+POS10,	DIV2,		

		(DIV2*16)+POS08,	(DIV2*16)+POS03,	DIV2,		
		(DIV1*16)+POS06,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS08,	DIV2,		

		(DIV1*16)+POS08,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS02,	(DIV2*16)+POS11,	DIV2,		

		(DIV1*16)+POS14,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS09,	DIV2,		

		(DIV2*16)+POS06,	(DIV2*16)+POS01,	DIV2,		
		(DIV1*16)+POS13,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS03,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS11,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS09,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS06,	(DIV2*16)+POS15,	DIV2,		

		(DIV2*16)+POS04,	(DIV2*16)+POS02,	DIV2,		
		(DIV1*16)+POS07,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS14,	DIV2,		

		(DIV1*16)+POS12,	(DIV1*16)+POS04,	DIV1,		//7
		(DIV3*16)+POS12,	(DIV3*16)+POS04,	DIV3,		//7
		(DIV2*16)+POS16,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS10,	(DIV2*16)+POS12,	DIV2,		

		(DIV2*16)+POS09,	(DIV2*16)+POS15,	DIV2,		
		(DIV1*16)+POS08,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS02,	DIV2,		

		(DIV1*16)+POS02,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS01,	DIV2,		

		(DIV1*16)+POS01,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS03,	DIV2,		

		(DIV2*16)+POS07,	(DIV2*16)+POS14,	DIV2,		
		(DIV1*16)+POS03,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS07,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS05,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS08,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS10,	DIV1,		//8
		(DIV3*16)+POS04,	(DIV3*16)+POS10,	DIV3,		//8
		(DIV2*16)+POS10,	(DIV2*16)+POS16,	DIV2,		

		(DIV2*16)+POS11,	(DIV2*16)+POS13,	DIV2,		
		(DIV1*16)+POS06,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS14,	(DIV2*16)+POS06,	DIV2,		

		(DIV1*16)+POS14,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS04,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS02,	(DIV2*16)+POS15,	DIV2,		

		(DIV2*16)+POS05,	(DIV2*16)+POS12,	DIV2,		
		(DIV1*16)+POS12,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS13,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS03,	(DIV2*16)+POS11,	DIV2,		

		(DIV1*16)+POS11,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS05,	(DIV2*16)+POS09,	DIV2,		

								      
		(DIV2*16)+POS03,	(DIV2*16)+POS10,	DIV2,		
		(DIV1*16)+POS09,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS14,	DIV2,		

		(DIV1*16)+POS08,	(DIV1*16)+POS04,	DIV1,		//9
		(DIV3*16)+POS08,	(DIV3*16)+POS04,	DIV3,		//9
		(DIV2*16)+POS06,	(DIV2*16)+POS12,	DIV2,		

		(DIV1*16)+POS06,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS10,	DIV2,		

		(DIV2*16)+POS01,	(DIV2*16)+POS08,	DIV2,		
		(DIV1*16)+POS02,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS16,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS01,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS10,	(DIV2*16)+POS06,	DIV2,		

		(DIV1*16)+POS03,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS04,	DIV2,		

		(DIV2*16)+POS02,	(DIV2*16)+POS06,	DIV2,		
		(DIV1*16)+POS05,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS03,	DIV2,		

		(DIV1*16)+POS07,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS06,	DIV1,		//10
		(DIV3*16)+POS04,	(DIV3*16)+POS06,	DIV3,		//10
		(DIV2*16)+POS09,	(DIV2*16)+POS07,	DIV2,		

		(DIV2*16)+POS16,	(DIV2*16)+POS04,	DIV2,		
		(DIV1*16)+POS14,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS16,	DIV2,		

		(DIV1*16)+POS06,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS01,	DIV2,		

		(DIV1*16)+POS08,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS14,	(DIV2*16)+POS02,	DIV2,		

		(DIV2*16)+POS11,	(DIV2*16)+POS16,	DIV2,		
		(DIV1*16)+POS10,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS02,	(DIV2*16)+POS12,	DIV2,		

		(DIV1*16)+POS12,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS14,	DIV2,		

		(DIV1*16)+POS13,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS03,	(DIV2*16)+POS15,	DIV2,		

		(DIV2*16)+POS06,	(DIV2*16)+POS04,	DIV2,		
		(DIV1*16)+POS11,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS05,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS14,	DIV1,		//11
		(DIV3*16)+POS04,	(DIV3*16)+POS14,	DIV3,		//11
		(DIV2*16)+POS07,	(DIV2*16)+POS11,	DIV2,		

		(DIV1*16)+POS02,	(DIV1*16)+POS04,	DIV1,		//12
		(DIV3*16)+POS02,	(DIV3*16)+POS04,	DIV3,		//12
		(DIV2*16)+POS04,	(DIV2*16)+POS10,	DIV2,		

		(DIV2*16)+POS13,	(DIV2*16)+POS09,	DIV2,		
		(DIV1*16)+POS01,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS06,	(DIV2*16)+POS08,	DIV2,		

		(DIV1*16)+POS03,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS16,	(DIV2*16)+POS09,	DIV2,		

		(DIV1*16)+POS05,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS06,	(DIV2*16)+POS16,	DIV2,		

		(DIV2*16)+POS15,	(DIV2*16)+POS07,	DIV2,		
		(DIV1*16)+POS07,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS04,	DIV2,		

		(DIV1*16)+POS09,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS10,	(DIV2*16)+POS02,	DIV2,		

		(DIV1*16)+POS14,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS01,	DIV2,		

		(DIV2*16)+POS14,	(DIV2*16)+POS05,	DIV2,		
		(DIV1*16)+POS04,	(DIV1*16)+POS01,	DIV1,		//13
		(DIV3*16)+POS04,	(DIV3*16)+POS01,	DIV3,		//13
		(DIV2*16)+POS13,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS06,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS09,	DIV2,		

		(DIV1*16)+POS08,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS14,	(DIV2*16)+POS03,	DIV2,		

		(DIV2*16)+POS12,	(DIV2*16)+POS03,	DIV2,		
		(DIV1*16)+POS10,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS09,	(DIV1*16)+POS12,	DIV1,		//14
		(DIV3*16)+POS09,	(DIV3*16)+POS12,	DIV3,		//14
		(DIV2*16)+POS02,	(DIV2*16)+POS08,	DIV2,		

		(DIV1*16)+POS02,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS10,	DIV2,		

		(DIV2*16)+POS10,	(DIV2*16)+POS01,	DIV2,		
		(DIV1*16)+POS02,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS03,	(DIV2*16)+POS12,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS03,	DIV1,		//15
		(DIV3*16)+POS04,	(DIV3*16)+POS03,	DIV3,		//15
		(DIV2*16)+POS05,	(DIV2*16)+POS14,	DIV2,		

		(DIV1*16)+POS06,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS07,	(DIV2*16)+POS15,	DIV2,		

		(DIV2*16)+POS08,	(DIV2*16)+POS02,	DIV2,		
		(DIV1*16)+POS08,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS06,	DIV2,		

		(DIV1*16)+POS12,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS16,	(DIV2*16)+POS11,	DIV2,		

		(DIV2*16)+POS05,	(DIV2*16)+POS15,	DIV2,		
		(DIV1*16)+POS14,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS16,	DIV2,		

		(DIV1*16)+POS03,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS06,	(DIV2*16)+POS02,	DIV2,		

		(DIV1*16)+POS07,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS01,	DIV2,		

		(DIV2*16)+POS03,	(DIV2*16)+POS14,	DIV2,		
		(DIV1*16)+POS05,	(DIV1*16)+POS04,	DIV1,		//16
		(DIV3*16)+POS05,	(DIV3*16)+POS04,	DIV3,		//16
		(DIV2*16)+POS10,	(DIV2*16)+POS03,	DIV2,		

		(DIV1*16)+POS09,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS11,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS11,	DIV2,		

		(DIV2*16)+POS09,	(DIV2*16)+POS11,	DIV2,		
		(DIV1*16)+POS13,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS14,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS01,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS09,	DIV2,		

		(DIV1*16)+POS02,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS02,	(DIV2*16)+POS04,	DIV2,		

		(DIV2*16)+POS07,	(DIV2*16)+POS13,	DIV2,		
		(DIV1*16)+POS01,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS06,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS07,	DIV1,		//17
		(DIV3*16)+POS04,	(DIV3*16)+POS07,	DIV3,		//17
		(DIV2*16)+POS03,	(DIV2*16)+POS08,	DIV2,		

		(DIV1*16)+POS06,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS05,	(DIV2*16)+POS10,	DIV2,		

		(DIV2*16)+POS01,	(DIV2*16)+POS12,	DIV2,		
		(DIV1*16)+POS08,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS15,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS07,	(DIV2*16)+POS12,	DIV2,		

		(DIV1*16)+POS14,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS14,	DIV2,		

		(DIV2*16)+POS02,	(DIV2*16)+POS10,	DIV2,		
		(DIV1*16)+POS07,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS16,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS05,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS01,	DIV2,		

		(DIV1*16)+POS09,	(DIV1*16)+POS04,	DIV1,		//18
		(DIV3*16)+POS09,	(DIV3*16)+POS04,	DIV3,		//18
		(DIV2*16)+POS06,	(DIV2*16)+POS03,	DIV2,		

		(DIV2*16)+POS04,	(DIV2*16)+POS08,	DIV2,		
		(DIV1*16)+POS11,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS13,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS10,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS12,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS13,	DIV2,		

		(DIV2*16)+POS16,	(DIV2*16)+POS06,	DIV2,		
		(DIV1*16)+POS03,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS16,	(DIV2*16)+POS02,	DIV2,		

		(DIV1*16)+POS02,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS09,	DIV2,		

		(DIV1*16)+POS13,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS11,	DIV3,		

		(DIV1*16)+POS01,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS14,	(DIV2*16)+POS11,	DIV2,		

		(DIV2*16)+POS09,	(DIV2*16)+POS16,	DIV2,		
		(DIV1*16)+POS03,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS02,	(DIV2*16)+POS01,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS11,	DIV1,		//19
		(DIV3*16)+POS04,	(DIV3*16)+POS11,	DIV3,		//19
		(DIV2*16)+POS04,	(DIV2*16)+POS03,	DIV2,		

		(DIV1*16)+POS06,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS06,	(DIV2*16)+POS05,	DIV2,		

		(DIV2*16)+POS08,	(DIV2*16)+POS06,	DIV2,		
		(DIV1*16)+POS08,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS14,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS10,	(DIV2*16)+POS09,	DIV2,		

		(DIV1*16)+POS11,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS11,	DIV2,		

		(DIV2*16)+POS10,	(DIV2*16)+POS04,	DIV2,		
		(DIV1*16)+POS09,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS14,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS07,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS16,	(DIV2*16)+POS15,	DIV2,		

		(DIV1*16)+POS13,	(DIV1*16)+POS04,	DIV1,		//20
		(DIV3*16)+POS13,	(DIV3*16)+POS04,	DIV3,		//20
		(DIV2*16)+POS03,	(DIV2*16)+POS02,	DIV2,		

		(DIV2*16)+POS11,	(DIV2*16)+POS07,	DIV2,		
		(DIV1*16)+POS12,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS07,	(DIV2*16)+POS06,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS05,	(DIV2*16)+POS04,	DIV2,		

		(DIV1*16)+POS05,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS08,	DIV2,		

		(DIV2*16)+POS13,	(DIV2*16)+POS05,	DIV2,		
		(DIV1*16)+POS02,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS10,	DIV2,		

		(DIV1*16)+POS01,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS12,	DIV2,		

		(DIV1*16)+POS03,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS14,	DIV2,		

		(DIV2*16)+POS15,	(DIV2*16)+POS03,	DIV2,		
		(DIV1*16)+POS05,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS16,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS12,	DIV1,		//21
		(DIV3*16)+POS04,	(DIV3*16)+POS12,	DIV3,		//21
		(DIV2*16)+POS02,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS06,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS03,	DIV2,		

		(DIV2*16)+POS14,	(DIV2*16)+POS01,	DIV2,		
		(DIV1*16)+POS14,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS12,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS06,	(DIV2*16)+POS09,	DIV2,		

		(DIV1*16)+POS13,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS11,	DIV2,		

		(DIV2*16)+POS12,	(DIV2*16)+POS02,	DIV2,		
		(DIV1*16)+POS11,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS10,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS09,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS12,	(DIV2*16)+POS15,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS04,	DIV1,		//22
		(DIV3*16)+POS10,	(DIV3*16)+POS04,	DIV3,		//22
		(DIV2*16)+POS16,	(DIV2*16)+POS14,	DIV2,		

		(DIV2*16)+POS02,	(DIV2*16)+POS14,	DIV2,		
		(DIV1*16)+POS08,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS07,	(DIV2*16)+POS02,	DIV2,		

		(DIV1*16)+POS07,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS05,	(DIV2*16)+POS01,	DIV2,		

		(DIV1*16)+POS02,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS04,	DIV2,		

		(DIV2*16)+POS01,	(DIV2*16)+POS15,	DIV2,		
		(DIV1*16)+POS01,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS06,	DIV2,		

		(DIV1*16)+POS03,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS08,	DIV2,		

		(DIV1*16)+POS05,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS10,	DIV2,		

		(DIV2*16)+POS16,	(DIV2*16)+POS08,	DIV2,		
		(DIV1*16)+POS07,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS14,	(DIV2*16)+POS12,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS08,	DIV1,		//23
		(DIV3*16)+POS04,	(DIV3*16)+POS08,	DIV3,		//23
		(DIV2*16)+POS03,	(DIV2*16)+POS16,	DIV2,		

		(DIV1*16)+POS14,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS02,	(DIV2*16)+POS09,	DIV2,		

		(DIV2*16)+POS07,	(DIV2*16)+POS09,	DIV2,		
		(DIV1*16)+POS08,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS03,	(DIV2*16)+POS05,	DIV2,		

		(DIV1*16)+POS12,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS11,	DIV2,		

		(DIV2*16)+POS05,	(DIV2*16)+POS11,	DIV2,		
		(DIV1*16)+POS13,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS06,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS11,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS16,	(DIV2*16)+POS12,	DIV2,		

		(DIV1*16)+POS06,	(DIV1*16)+POS04,	DIV1,		//24
		(DIV3*16)+POS06,	(DIV3*16)+POS04,	DIV3,		//24
		(DIV2*16)+POS10,	(DIV2*16)+POS14,	DIV2,		

		(DIV2*16)+POS03,	(DIV2*16)+POS13,	DIV2,		
		(DIV1*16)+POS09,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS15,	DIV2,		

		(DIV1*16)+POS02,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS02,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS11,	(DIV2*16)+POS02,	DIV2,		

		(DIV1*16)+POS01,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS01,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS01,	DIV2,		

		(DIV2*16)+POS04,	(DIV2*16)+POS12,	DIV2,		
		(DIV1*16)+POS03,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS07,	(DIV2*16)+POS03,	DIV2,		

		(DIV1*16)+POS05,	(DIV1*16)+POS12,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS12,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS04,	DIV2,		

		(DIV1*16)+POS07,	(DIV1*16)+POS13,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS13,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS06,	DIV2,		

		(DIV2*16)+POS06,	(DIV2*16)+POS10,	DIV2,		
		(DIV1*16)+POS09,	(DIV1*16)+POS11,	DIV1,		
		(DIV3*16)+POS09,	(DIV3*16)+POS11,	DIV3,		
		(DIV2*16)+POS14,	(DIV2*16)+POS08,	DIV2,		

		(DIV1*16)+POS14,	(DIV1*16)+POS04,	DIV1,		//25
		(DIV3*16)+POS14,	(DIV3*16)+POS04,	DIV3,		//25
		(DIV2*16)+POS05,	(DIV2*16)+POS16,	DIV2,		

		(DIV1*16)+POS04,	(DIV1*16)+POS02,	DIV1,		//26
		(DIV3*16)+POS04,	(DIV3*16)+POS02,	DIV3,		//26
		(DIV2*16)+POS12,	(DIV2*16)+POS10,	DIV2,		

		(DIV2*16)+POS07,	(DIV2*16)+POS16,	DIV2,		
		(DIV1*16)+POS06,	(DIV1*16)+POS01,	DIV1,		
		(DIV3*16)+POS06,	(DIV3*16)+POS01,	DIV3,		
		(DIV2*16)+POS02,	(DIV2*16)+POS13,	DIV2,		

		(DIV1*16)+POS08,	(DIV1*16)+POS03,	DIV1,		
		(DIV3*16)+POS08,	(DIV3*16)+POS03,	DIV3,		
		(DIV2*16)+POS01,	(DIV2*16)+POS11,	DIV2,		

		(DIV1*16)+POS10,	(DIV1*16)+POS05,	DIV1,		
		(DIV3*16)+POS10,	(DIV3*16)+POS05,	DIV3,		
		(DIV2*16)+POS03,	(DIV2*16)+POS09,	DIV2,		

		(DIV2*16)+POS10,	(DIV2*16)+POS08,	DIV2,		
	 	(DIV1*16)+POS12,	(DIV1*16)+POS07,	DIV1,		
		(DIV3*16)+POS12,	(DIV3*16)+POS07,	DIV3,		
		(DIV2*16)+POS05,	(DIV2*16)+POS07,	DIV2,		

		(DIV1*16)+POS13,	(DIV1*16)+POS09,	DIV1,		
		(DIV3*16)+POS13,	(DIV3*16)+POS09,	DIV3,		
		(DIV2*16)+POS08,	(DIV2*16)+POS12,	DIV2,		

		(DIV1*16)+POS11,	(DIV1*16)+POS14,	DIV1,		
		(DIV3*16)+POS11,	(DIV3*16)+POS14,	DIV3,		
		(DIV2*16)+POS16,	(DIV2*16)+POS10,	DIV2,		

		(DIV2*16)+POS12,	(DIV2*16)+POS06,	DIV2,		
		(DIV1*16)+POS01,	(DIV1*16)+POS04,	DIV1,		//27
		(DIV3*16)+POS01,	(DIV3*16)+POS04,	DIV3,		//27
		(DIV2*16)+POS06,	(DIV2*16)+POS14,	DIV2,		

		(DIV1*16)+POS03,	(DIV1*16)+POS06,	DIV1,		
		(DIV3*16)+POS03,	(DIV3*16)+POS06,	DIV3,		
		(DIV2*16)+POS04,	(DIV2*16)+POS15,	DIV2,		

		(DIV1*16)+POS05,	(DIV1*16)+POS08,	DIV1,		
		(DIV3*16)+POS05,	(DIV3*16)+POS08,	DIV3,		
		(DIV2*16)+POS15,	(DIV2*16)+POS02,	DIV2,		

		(DIV2*16)+POS14,	(DIV2*16)+POS04,	DIV2,		
		(DIV1*16)+POS07,	(DIV1*16)+POS10,	DIV1,		
		(DIV3*16)+POS07,	(DIV3*16)+POS10,	DIV3,		
		(DIV2*16)+POS13,	(DIV2*16)+POS01,	DIV2,		

		(DIV1*16)+POS12,	(DIV1*16)+POS09,	DIV1,		//28
		(DIV3*16)+POS12,	(DIV3*16)+POS09,	DIV3,		//28
		(DIV2*16)+POS11,	(DIV2*16)+POS03,	DIV2,		

		(DIV1*16)+POS14,	(DIV1*16)+POS02,	DIV1,		
		(DIV3*16)+POS14,	(DIV3*16)+POS02,	DIV3,		
		(DIV2*16)+POS09,	(DIV2*16)+POS05,	DIV2,		

		-1,			-1,			-1,		// END OF SEASON

			}; 

signed int 	restore_cup_data[MAX_TEAMS-1]={
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
		{-1,},
			};


demo_struct	demo_data[]={

		{ENG,BRA,55745,ENG,4},		// english demo
//		{ENG,BRA,55745,ENG,4},		
//		{SPN,ITA,2778,CAM,9},
//		{SPN,ITA,2778,CAM,9},
//		{GER,FRA,9808,BEL,2},
//		{GER,FRA,9808,BEL,2},
//		{DEN,SCO,9808,NOR,14},
//		{DEN,SCO,9808,NOR,14},

//		{ENG,BRA,55745,ENG,4},		// french demo
//		{ENG,BRA,55745,ENG,4},		
//		{SPN,ITA,2778,CAM,9},
//		{SPN,ITA,2778,CAM,9},
//		{GER,FRA,9808,BEL,2},
//		{GER,FRA,9808,BEL,2},
//		{DEN,SCO,9808,NOR,14},
//		{DEN,SCO,9808,NOR,14},

//		{GER,FRA,9808,BEL,2},	     	// german demo
//		{GER,FRA,9808,BEL,2},	     	
//		{ENG,BRA,55745,ENG,4},
//		{ENG,BRA,55745,ENG,4},
//		{SPN,ITA,2778,CAM,9},
//		{SPN,ITA,2778,CAM,9},
//		{DEN,SCO,9808,NOR,14},
//		{DEN,SCO,9808,NOR,14},

//		{USA,BRA,55745,ENG,4},		// american demo
//		{USA,BRA,55745,ENG,4},		
//		{SPN,ENG,2778,CAM,9},
//		{SPN,ENG,2778,CAM,9},
//		{GER,FRA,9808,BEL,2},
//		{GER,FRA,9808,BEL,2},
//		{DEN,SCO,9808,NOR,14},
//		{DEN,SCO,9808,NOR,14},

//		{USA,BRA,55745,ENG,4},		// canadian demo
//		{USA,BRA,55745,ENG,4},		
//		{SPN,ENG,2778,CAM,9},
//		{SPN,ENG,2778,CAM,9},
//		{GER,FRA,9808,BEL,2},
//		{GER,FRA,9808,BEL,2},
//		{DEN,SCO,9808,NOR,14},
//		{DEN,SCO,9808,NOR,14},

//		{NOR,BRA,55745,ENG,4},		// norwegian demo
//		{NOR,BRA,55745,ENG,4},		
//		{SPN,ENG,2778,CAM,9},
//		{SPN,ENG,2778,CAM,9},
//		{GER,FRA,9808,BEL,2},
//		{GER,FRA,9808,BEL,2},
//		{DEN,SCO,9808,NOR,14},
//		{DEN,SCO,9808,NOR,14},

				};


restore_data	restore_league_data[MAX_TEAMS-1]={
		
		{DIV2,POS09,},
		{DIV1,POS13,},
		{DIV1,POS02,},
		{DIV2,POS02,},
		{DIV2,POS10,},
		{DIV1,POS14,},
		{DIV3,POS12,},
		{DIV3,POS13,},
		{DIV2,POS07,},
		{DIV1,POS07,},
		{DIV3,POS01,},
		{DIV3,POS05,},
		{DIV1,POS04,},
		{DIV3,POS03,},
		{DIV2,POS04,},
		{DIV3,POS02,},
		{DIV3,POS11,},
		{DIV2,POS08,},
		{DIV2,POS03,},
		{DIV1,POS03,},
		{DIV1,POS10,},
		{DIV1,POS09,},
		{DIV1,POS06,},
		{DIV3,POS08,},
		{DIV3,POS14,},
		{DIV2,POS11,},
		{DIV2,POS12,},
		{DIV1,POS11,},
		{DIV1,POS05,},
		{DIV2,POS14,},
		{DIV1,POS08,},
		{DIV2,POS13,},
		{DIV2,POS05,},
		{DIV2,POS15,},
		{DIV2,POS16,},
		{DIV3,POS06,},
		{DIV1,POS01,},
		{DIV1,POS12,},
		{DIV2,POS01,},
		{DIV3,POS04,},
		{DIV3,POS09,},
		{DIV2,POS06,},
		{DIV3,POS07,},
		{DIV3,POS10,},
		};




goal_table	goals[MAX_GOALS+1]={
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
					};


int	team_b_kit[]={
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, WHT, WHT, MOR, ENG, WHT,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	WHT, IVR, GHA, ROM, GER, WHT, NOR, SAU,	WHT, POL, WHT, URU, BRA, NIG, MEX, CZE,	WHT, POR, CHI, BOL, GRM,
	USA, RUS, SPN, BLU, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, BLU, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, BLU,	SLV, IVR, BLU, ROM, BLU, GRE, NOR, BLU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	USA, RUS, SPN, BUL, WHT, WHT, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, WHT, WHT, BOL, GRM,
	USA, BLU, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, BLU, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, BLU,	SLV, IVR, BLU, ROM, BLU, GRE, NOR, BLU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	USA, RUS, WHT, BUL, BEL, WHT, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, WHT, WHT, BOL, GRM,
	USA, RUS, WHT, BUL, WHT, DEN, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, WHT, WHT, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, WHT, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	USA, RUS, WHT, BUL, WHT, WHT, NIR, TUN,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, WHT, WHT, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, WHT, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, WHT, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, WHT, WHT, CZE,	ICE, POR, CHI, WHT, GRM,
	USA, RUS, WHT, BUL, WHT, WHT, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, WHT, WHT, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	WHT, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, WHT, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, WHT, WHT, CZE,	ICE, POR, CHI, WHT, GRM,
	WHT, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, WHT, MOR, ENG, WHT,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	WHT, IVR, GHA, ROM, GER, WHT, NOR, SAU,	WHT, POL, WHT, WHT, BRA, NIG, MEX, CZE,	WHT, POR, CHI, BOL, GRM,
	WHT, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, WHT, ITA, MOR, ENG, WHT,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	WHT, IVR, GHA, ROM, GER, WHT, NOR, SAU,	WHT, POL, WHT, WHT, BRA, NIG, MEX, CZE,	WHT, POR, CHI, BOL, GRM,
	USA, RUS, WHT, BUL, WHT, WHT, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, WHT, WHT, BOL, GRM,
	USA, BLU, SPN, BLU, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, BLU,	SLV, IVR, BLU, ROM, BLU, GRE, NOR, BLU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	WHT, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, WHT, WHT, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	WHT, IVR, GHA, ROM, GER, WHT, NOR, SAU,	WHT, POL, WHT, URU, BRA, NIG, MEX, CZE,	WHT, POR, CHI, BOL, GRM,
	USA, RUS, WHT, BUL, WHT, WHT, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WAL, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, WHT, WHT, BOL, GRM,
	USA, RUS, WHT, BUL, WHT, WHT, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, EGY, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, WHT, WHT, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, BLU, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, BLU, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BLU, NIG, MEX, CZE,	ICE, POR, CHI, BOL, BLU,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, BLU, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, BLU, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BLU, NIG, MEX, CZE,	ICE, POR, CHI, BOL, BLU,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, BLU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, WHT, TUN,	WHT, SWZ, WHT, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, WHT, WHT, CZE,	ICE, POR, CHI, WHT, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	SLV, WHT, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	USA, BLU, SPN, BLU, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, BLU, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, BLU, ROM, BLU, GRE, NOR, BLU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	WHT, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, WHT, WHT, MOR, ENG, WHT,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, WHT, NOR, SAU,	WHT, POL, WHT, URU, BRA, NIG, MEX, CZE,	WHT, POR, CHI, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, EIR, WHT, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	USA, BLU, SPN, BLU, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, BLU, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, BLU,	SLV, IVR, GHA, ROM, BLU, GRE, NOR, BLU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, BLU, BLU, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BLU, NIG, MEX, CZE,	ICE, POR, CHI, BOL, BLU,
	USA, BLU, SPN, BLU, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, BLU, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, BLU,	SLV, IVR, BLU, ROM, GER, GRE, NOR, BLU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	WHT, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, WHT, WHT, MOR, ENG, WHT,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	WHT, IVR, GHA, ROM, GER, GRE, NOR, SAU,	WHT, POL, WHT, URU, BRA, NIG, MEX, CZE,	WHT, POR, CHI, BOL, GRM,
	USA, RUS, WHT, BUL, BLU, BLU, NIR, BLU,	ZAM, BLU, CAM, SKR, ITA, BLU, ENG, SCO,	BLU, BLU, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, BLU, JAP, URU, BRA, NIG, MEX, BLU,	ICE, BLU, BLU, BOL, GRM,
	USA, BLU, SPN, BLU, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, BLU, SCO,	WAL, EGY, COL, SWE, ARG, EIR, HOL, BLU,	SLV, IVR, BLU, ROM, BLU, BLU, NOR, SAU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	WHT, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, WHT, WHT, MOR, ENG, WHT,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	WHT, IVR, GHA, ROM, GER, WHT, NOR, SAU,	WHT, POL, WHT, WHT, BRA, NIG, MEX, CZE,	WHT, POR, CHI, BOL, GRM,
	USA, RUS, WHT, BUL, BLU, BLU, NIR, BLU,	ZAM, BLU, CAM, SKR, ITA, BLU, ENG, SCO,	BLU, BLU, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, POL, JAP, URU, BRA, NIG, MEX, BLU,	ICE, BLU, BLU, BOL, GRM,
	WHT, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, WHT, WHT, MOR, ENG, WHT,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	WHT, IVR, GHA, ROM, GER, WHT, NOR, SAU,	WHT, POL, JAP, WHT, BRA, NIG, MEX, CZE,	WHT, POR, CHI, BOL, GRM,
	WHT, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, WHT, WHT, MOR, ENG, WHT,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	WHT, IVR, GHA, ROM, GER, WHT, NOR, SAU,	WHT, POL, WHT, URU, BRA, NIG, MEX, CZE,	WHT, POR, CHI, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, BLU, BLU, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, BLU, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, BLU,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	WHT, SWZ, WHT, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, WHT, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, NIG, WHT, CZE,	ICE, POR, CHI, WHT, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	WHT, SWZ, WHT, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, WHT, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, WHT, MEX, CZE,	ICE, POR, CHI, WHT, GRM,
	USA, RUS, WHT, BUL, WHT, WHT, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, CZE,	ICE, WHT, WHT, BOL, GRM,
	WHT, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, WHT, WHT, MOR, ENG, WHT,	WAL, EGY, COL, SWE, ARG, EIR, HOL, FIN,	WHT, IVR, GHA, ROM, GER, WHT, NOR, SAU,	WHT, POL, WHT, WHT, BRA, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
	USA, RUS, WHT, BUL, WHT, WHT, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, POR, WHT, BOL, GRM,
	USA, RUS, WHT, BUL, WHT, WHT, NIR, WHT,	ZAM, WHT, CAM, SKR, ITA, WHT, ENG, SCO,	WHT, WHT, COL, SWE, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, WHT, SAU,	FRA, WHT, JAP, URU, BRA, NIG, MEX, WHT,	ICE, WHT, WHT, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	WHT, SWZ, WHT, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, COL, SWE, ARG, WHT, HOL, FIN,	SLV, IVR, GHA, ROM, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BRA, WHT, WHT, CZE,	ICE, POR, CHI, BOL, GRM,
	USA, RUS, SPN, BUL, BEL, DEN, NIR, TUN,	ZAM, SWZ, CAM, SKR, ITA, MOR, ENG, SCO,	WAL, EGY, BLU, BLU, ARG, EIR, HOL, FIN,	SLV, IVR, GHA, BLU, GER, GRE, NOR, SAU,	FRA, POL, JAP, URU, BLU, NIG, MEX, CZE,	ICE, POR, CHI, BOL, GRM,
			};


#if 0
redefine_info	redefine_data[]={
		{
	150, 350,
		},
		{
	470, 350,
		},
		{
	150, 370,
		},
		{
	470, 370,
		},
		{
	150, 390,
		},
		{
	470, 390,
		},
				};

#endif

char LegalKEY[]={//	 0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
		/*  0 */	 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		/* 16 */	 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		/* 32 */	 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	 	/* 48 */	 1,  0,  0,  0,  1,  0,  1,  1,  0,  0,  0,  0,  1,  1,  1,  1,
	 	/* 64 */	 1,  0,  1,  0,  1,  0,  1,  0,  0,  1,  0,  1,  1,  0,  0,  0,
	 				 1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  1,  1,  0,  1,  1,
	 				 1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0,
	 				 1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,
		};

char KEYtext[]={
		/*  0 */ 'X','Z','G','H','F','D','S','A','R','E','W','Q','B','�','V','C'
		/* 16 */ ,'5','6','4','3','2','1','T','Y','O',']','0','8','-','7','9','='
		/* 32 */ , 39,'J','L', 13,'P','I','[','U','.','M','N','/',',','\\',';','K'
		/* 48 */ ,141,' ',' ',' ',  8,' ',' ',  9,' ',' ',' ',' ',128,129,130,130
		/* 64 */ ,131,' ','+',' ','*',' ','.',' ',' ','-',' ', 13,'/',' ',' ',' '
				 ,'5','4','3','2','1','0','=',' ',' ',' ',' ','9','8',' ','7','6'
				 ,170,' ',168,167,162,166,165,164,171,' ',169,' ',173,' ',172,' '
				 ,134,163,  8,133,135,136,174,' ',' ',137,138,139,140,160,132,161
				};

#if 0

BYTE copykeys[12]={ 0,0,0,0,0,0,0,0,0,0,0,0 };

#endif


#ifdef WHEEL
char	CodeWheelNumbers[]={
	37,  5, 54, 45, 15,		// a
	49,  8, 40, 59, 21,		// p
	20, 78, 74,  9, 58,		// o
	57, 48, 30, 75, 39,		// n
	73,  7, 65, 19, 76,		// m
	 2, 77, 56, 29, 10,		// l
	67, 18, 47, 55, 38,		// k
	79, 60, 28, 50, 31,		// j
	17, 68, 46, 11, 22,		// i
	33, 13, 61, 41, 66,		// h
	80, 23, 69,  1, 32,		// g
	34, 45, 62, 42, 51,		// f
	 4, 63, 16, 12, 70,		// e
	52, 25, 35, 72, 24,		// d
	64, 36, 44,  6,  3,		// c
	14, 71, 26, 53, 27,		// b

	37,  5, 54, 45, 15,		// a
	49,  8, 40, 59, 21,		// p
	20, 78, 74,  9, 58,		// o
	57, 48, 30, 75, 39,		// n
	73,  7, 65, 19, 76,		// m
	 2, 77, 56, 29, 10,		// l
	67, 18, 47, 55, 38,		// k
	79, 60, 28, 50, 31,		// j
	17, 68, 46, 11, 22,		// i
	33, 13, 61, 41, 66,		// h
	80, 23, 69,  1, 32,		// g
	34, 45, 62, 42, 51,		// f
	 4, 63, 16, 12, 70,		// e
	52, 25, 35, 72, 24,		// d
	64, 36, 44,  6,  3,		// c
	14, 71, 26, 53, 27,		// b

	37,  5, 54, 45, 15,		// a
	49,  8, 40, 59, 21,		// p
	20, 78, 74,  9, 58,		// o
	57, 48, 30, 75, 39,		// n
	73,  7, 65, 19, 76,		// m
	 2, 77, 56, 29, 10,		// l
	67, 18, 47, 55, 38,		// k
	79, 60, 28, 50, 31,		// j
	17, 68, 46, 11, 22,		// i
	33, 13, 61, 41, 66,		// h
	80, 23, 69,  1, 32,		// g
	34, 45, 62, 42, 51,		// f
	 4, 63, 16, 12, 70,		// e
	52, 25, 35, 72, 24,		// d
	64, 36, 44,  6,  3,		// c
	14, 71, 26, 53, 27,		// b

	37,  5, 54, 45, 15,		// a
	49,  8, 40, 59, 21,		// p
	20, 78, 74,  9, 58,		// o
	57, 48, 30, 75, 39,		// n
	73,  7, 65, 19, 76,		// m
	 2, 77, 56, 29, 10,		// l
	67, 18, 47, 55, 38,		// k
	79, 60, 28, 50, 31,		// j
	17, 68, 46, 11, 22,		// i
	33, 13, 61, 41, 66,		// h
	80, 23, 69,  1, 32,		// g
	34, 45, 62, 42, 51,		// f
	 4, 63, 16, 12, 70,		// e
	52, 25, 35, 72, 24,		// d
	64, 36, 44,  6,  3,		// c
	14, 71, 26, 53, 27,		// b

	37,  5, 54, 45, 15,		// a
	49,  8, 40, 59, 21,		// p
	20, 78, 74,  9, 58,		// o
	57, 48, 30, 75, 39,		// n
	73,  7, 65, 19, 76,		// m
	 2, 77, 56, 29, 10,		// l
	67, 18, 47, 55, 38,		// k
	79, 60, 28, 50, 31,		// j
	17, 68, 46, 11, 22,		// i
	33, 13, 61, 41, 66,		// h
	80, 23, 69,  1, 32,		// g
	34, 45, 62, 42, 51,		// f
	 4, 63, 16, 12, 70,		// e
	52, 25, 35, 72, 24,		// d
	64, 36, 44,  6,  3,		// c
	14, 71, 26, 53, 27,		// b

	37,  5, 54, 45, 15,		// a
	49,  8, 40, 59, 21,		// p
	20, 78, 74,  9, 58,		// o
	57, 48, 30, 75, 39,		// n
	73,  7, 65, 19, 76,		// m
	 2, 77, 56, 29, 10,		// l
	67, 18, 47, 55, 38,		// k
	79, 60, 28, 50, 31,		// j
	17, 68, 46, 11, 22,		// i
	33, 13, 61, 41, 66,		// h
	80, 23, 69,  1, 32,		// g
	34, 45, 62, 42, 51,		// f
	 4, 63, 16, 12, 70,		// e
	52, 25, 35, 72, 24,		// d
	64, 36, 44,  6,  3,		// c
	14, 71, 26, 53, 27,		// b

	37,  5, 54, 45, 15,		// a
	49,  8, 40, 59, 21,		// p
	20, 78, 74,  9, 58,		// o
	57, 48, 30, 75, 39,		// n
	73,  7, 65, 19, 76,		// m
	 2, 77, 56, 29, 10,		// l
	67, 18, 47, 55, 38,		// k
	79, 60, 28, 50, 31,		// j
	17, 68, 46, 11, 22,		// i
	33, 13, 61, 41, 66,		// h
	80, 23, 69,  1, 32,		// g
	34, 45, 62, 42, 51,		// f
	 4, 63, 16, 12, 70,		// e
	52, 25, 35, 72, 24,		// d
	64, 36, 44,  6,  3,		// c
	14, 71, 26, 53, 27,		// b

	37,  5, 54, 45, 15,		// a
	49,  8, 40, 59, 21,		// p
	20, 78, 74,  9, 58,		// o
	57, 48, 30, 75, 39,		// n
	73,  7, 65, 19, 76,		// m
	 2, 77, 56, 29, 10,		// l
	67, 18, 47, 55, 38,		// k
	79, 60, 28, 50, 31,		// j
	17, 68, 46, 11, 22,		// i
	33, 13, 61, 41, 66,		// h
	80, 23, 69,  1, 32,		// g
	34, 45, 62, 42, 51,		// f
	 4, 63, 16, 12, 70,		// e
	52, 25, 35, 72, 24,		// d
	64, 36, 44,  6,  3,		// c
	14, 71, 26, 53, 27,		// b
		     };

#define		A	0
#define		B	1
#define		C	2
#define		D	3
#define		E	4
#define		F	5
#define		G	6
#define		H	7
#define		I	8
#define		J	9
#define		K	10
#define		L	11
#define		M	12
#define		N	13
#define		O	14
#define		P	15

char	CodeWheelWindows[]={
	A, A, B, B, C, C, D, E,
	E, F, F, F, G, H, H, H,
	I, I, J, J, J, K, K, K, 
	L, M, M, M, N, N, O, O,
	P, P, 
	A, A, B, B, C, C, D, E,
	E, F, F, F, G, H, H, H,
	I, I, J, J, J, K, K, K, 
	L, M, M, M, N, N, O, O,
	P, P, 
	A, A, B, B, C, C, D, E,
	E, F, F, F, G, H, H, H,
	I, I, J, J, J, K, K, K, 
	L, M, M, M, N, N, O, O,
	P, P, 
	A, A, B, B, C, C, D, E,
	E, F, F, F, G, H, H, H,
	I, I, J, J, J, K, K, K, 
	L, M, M, M, N, N, O, O,
	P, P, 
	A, A, B, B, C, C, D, E,
	E, F, F, F, G, H, H, H,
	I, I, J, J, J, K, K, K, 
	L, M, M, M, N, N, O, O,
	P, P, 
	A, A, B, B, C, C, D, E,
	E, F, F, F, G, H, H, H,
	I, I, J, J, J, K, K, K, 
	L, M, M, M, N, N, O, O,
	P, P, 
	A, A, B, B, C, C, D, E,
	E, F, F, F, G, H, H, H,
	I, I, J, J, J, K, K, K, 
	L, M, M, M, N, N, O, O,
	P, P, 
	A, A, B, B, C, C, D, E,
	E, F, F, F, G, H, H, H,
	I, I, J, J, J, K, K, K, 
	L, M, M, M, N, N, O, O,
	P, P, 
		     };



char	CodeWheelWindowsOffs[]={
	1, 4, 0, 2, 1, 3, 2, 0,
	4, 0, 2, 3, 1, 0, 3, 4,
	0, 2, 1, 2, 4, 0, 1, 3,
	0, 1, 2, 4, 0, 2, 1, 3, 
	0, 2, 
	1, 4, 0, 2, 1, 3, 2, 0,
	4, 0, 2, 3, 1, 0, 3, 4,
	0, 2, 1, 2, 4, 0, 1, 3,
	0, 1, 2, 4, 0, 2, 1, 3, 
	0, 2, 
	1, 4, 0, 2, 1, 3, 2, 0,
	4, 0, 2, 3, 1, 0, 3, 4,
	0, 2, 1, 2, 4, 0, 1, 3,
	0, 1, 2, 4, 0, 2, 1, 3, 
	0, 2, 
	1, 4, 0, 2, 1, 3, 2, 0,
	4, 0, 2, 3, 1, 0, 3, 4,
	0, 2, 1, 2, 4, 0, 1, 3,
	0, 1, 2, 4, 0, 2, 1, 3, 
	0, 2, 
	1, 4, 0, 2, 1, 3, 2, 0,
	4, 0, 2, 3, 1, 0, 3, 4,
	0, 2, 1, 2, 4, 0, 1, 3,
	0, 1, 2, 4, 0, 2, 1, 3, 
	0, 2, 
	1, 4, 0, 2, 1, 3, 2, 0,
	4, 0, 2, 3, 1, 0, 3, 4,
	0, 2, 1, 2, 4, 0, 1, 3,
	0, 1, 2, 4, 0, 2, 1, 3, 
	0, 2, 
	1, 4, 0, 2, 1, 3, 2, 0,
	4, 0, 2, 3, 1, 0, 3, 4,
	0, 2, 1, 2, 4, 0, 1, 3,
	0, 1, 2, 4, 0, 2, 1, 3, 
	0, 2, 
	1, 4, 0, 2, 1, 3, 2, 0,
	4, 0, 2, 3, 1, 0, 3, 4,
	0, 2, 1, 2, 4, 0, 1, 3,
	0, 1, 2, 4, 0, 2, 1, 3, 
	0, 2, 
		     };
#endif

/*
char	*FrenchCountryNames[]={

	"Etats Unis",
	"Russie",
	"Espagne",
	"Bulgarie",
	"Belgique",
	"Danemark",
	"Irlande du Nord",
	"Tunisie",
	"Zambie",
	"Suisse",
	"Cameroun",
	"Sud Coree",
	"Italie",
	"Maroc",
	"Angleterre",
	"Ecosse",
	"Pays de Galles",
	"Egypte",
	"Colombie",
	"Suede",
	"Argentine",
	"Irlande",
	"Hollande",
	"Finlande",
	"Slovaquie",
	"Cote d'Ivoire",
	"Ghana",
	"Ghana",
	"Allemagne",
	"Grece",
	"Norvege",
	"Arabie Saoudite",
	"France",
	"Pologne",
	"Japon",
	"Uruguay",
	"Bresil",
	"Nigeria",
	"Mexique",
	"Tchecoslovaquie",
	"Islande",
	"Portugal",
	"Chine",
	"Bolivie",
	"Gremlin Showbiz XI",
	};

char	*FrenchNickNames[]={

	"Etats Unis",
	"Russie",
	"Espagne",
	"Bulgarie",
	"Belgique",
	"Danemark",
	"Irlande du Nord",
	"Tunisie",
	"Zambie",
	"Suisse",
	"Cameroun",
	"Sud Coree",
	"Italie",
	"Maroc",
	"Angleterre",
	"Ecosse",
	"Pays de Galles",
	"Egypte",
	"Colombia",
	"Suede",
	"Argentine",
	"Irlande",
	"Hollande",
	"Finlande",
	"Slovaque",
	"Cote d'Ivoire",
	"Ghana",
	"Roumanie",
	"Allemagne",
	"Grece",
	"Norvege",
	"Arabie Saoudite",
	"France",
	"Pologne",
	"Japon",
	"Uruguay",
	"Bresil",
	"Nigeria",
	"Mexique",
	"Tchecoslov.",
	"Islande",
	"Portugal",
	"Chine",
	"Bolivie",
	"Gremlin Showbiz XI",
	};
*/

/*
char	*GermanTeamNames[]={

	"Berti Logts",
	"A. Koppke",	
	"M. Bubbel",	
	"C. Neringer",	
	"T. Hellner",	
	"L. Matthaeuser",	
	"H. Herluch",
	"T. Heffler",	
	"A. Mueller",	
	"K-H. Reudle",	
	"J. Klinkmanns",
	"M. Sommer",	
	"O. Kuhn",	
	"T. Heinrichs",	
	"M. Freunths",	
	"U. Karsten",	
	"D. Eiling",	
	"C. Ziega",	
	"M. Schull",	
	"T. Stranz",	
	"M. Baller",	
	"S. Kantz",	
	"U. Habsch",	
	};
		
char	*GermanCountryNames[]={
	"U.S.A.",		 
	"Russland", 		
	"Spanien",		
	"Bulgarien",		
	"Belgien",	 	
	"Daenemark",		  
	"Nord-Irland", 		
	"Tunesien",	 	
	"Sambia",  		
	"Schweiz",		
	"Kamerun",   		
	"Korea",		
	"Italien",	 	
	"Marokko",		
	"England",  	    	
	"Schottland",  		
	"Wales",     	      	
	"Aegypten",		     
	"Kolumbien",		   
	"Schweden", 		
	"Argentinien",		
	"Irland",		
	"Holland",	   	
	"Finnland", 		
	"Slowakei",  		
	"Elfenbeinkueste",	 
	"Ghana", 		
	"Rumaenien", 		
	"Deutschland",  	
	"Griechenland",    	
	"Norwegen",    		
	"Saudi Arabien",	
	"Frankreich",      	
	"Polen",		
	"Japan",		   
	"Uruguay", 		
	"Brasilien",   		
	"Nigera", 		
	"Mexiko",		 
	"Tschechien",		
	"Island", 		
	"Portugal",  		
	"China",		   
	"Bolivien",		 
	"SAT.1 Dream Team", 							
	};

char	*GermanNickNames[]={
	"U.S.A.",		 
	"Russland", 		
	"Spanien",		
	"Bulgarien",		
	"Belgien",	 	
	"Daenemark",		  
	"Nord-Irland", 		
	"Tunesien",	 	
	"Sambia",  		
	"Schweiz",		
	"Kamerun",   		
	"Korea",		
	"Italien",	 	
	"Marokko",		
	"England",  	    	
	"Schottland",  		
	"Wales",     	      	
	"Aegypten",		     
	"Kolumbien",		   
	"Schweden", 		
	"Argentinien",		
	"Irland",		
	"Holland",	   	
	"Finnland", 		
	"Slowakei",  		
	"Elfenbeink.",	 
	"Ghana", 		
	"Rumaenien", 		
	"Deutschland",  	
	"Griechen.",    	
	"Norwegen",    		
	"S. Arabien",	
	"Frankreich",      	
	"Polen",		
	"Japan",		   
	"Uruguay", 		
	"Brasilien",   		
	"Nigera", 		
	"Mexiko",		 
	"Tschechien",		
	"Island", 		
	"Portugal",  		
	"China",		   
	"Bolivien",		 
	"SAT.1", 							
	};

char	*NorwegianCountryNames[]={

	"U.S.A.",
	"Russland",
	"Spanian",
	"Bulgaria",
	"Belgia",
	"Danmark",
	"Nord-Irland",
	"Tunis",
	"Zambia",
	"Sveits",
	"Kamerun",
	"Syd-Korea",
	"Italia",
	"Marokko",
	"England",
	"Skotland",
	"Wales",
	"Egypt",
	"Columbia",	
	"Sverige",
	"Argentina",
	"Irland",
	"Nederland",
	"Finland",
	"Slovakia",
	"Elfenbenkysten",
	"Ghana",
	"Romania",
	"Tyskland",
	"Hallas",
	"Norge",
	"Saudi Arabia",
	"Frankrike",
	"Polen",
	"Japan",
	"Uruguay",
	"Brasil",
	"Nigeria",
	"Mexico",
	"Tsjekkia",
	"Island",
	"Portugal",
	"Kina",
	"Bolivia",
	"Gremlin Showbiz XI",
	};

char	*NorwegianNickNames[]={

	"U.S.A.",
	"Russland",
	"Spanian",
	"Bulgaria",
	"Belgia",
	"Danmark",
	"N. Irland",
	"Tunis",
	"Zambia",
	"Sveits",
	"Kamerun",
	"S. Korea",
	"Italia",
	"Marokko",
	"England",
	"Skotland",
	"Wales",
	"Egypt",
	"Columbia",	
	"Sverige",
	"Argentina",
	"Irland",
	"Nederland",
	"Finland",
	"Slovakia",
	"Elfenbenk.",
	"Ghana",
	"Romania",
	"Tyskland",
	"Hallas",
	"Norge",
	"S. Arabia",
	"Frankrike",
	"Polen",
	"Japan",
	"Uruguay",
	"Brasil",
	"Nigeria",
	"Mexico",
	"Tsjekkia",
	"Island",
	"Portugal",
	"Kina",
	"Bolivia",
	"Gremlin XI",
	};
*/

#ifdef WHEEL
german_manual	manual[50]={
	{"6",       "3",       "1",       "SOUND",},
	{"6",       "7",       "2",       "PUNKT",},
	{"6",       "9",       "5",       "BILDSCHIRM",},
	{"7",       "2",       "7",       "ZEIT",},
	{"7",       "9",       "1",       "TEAMAUSWAHL",},
	{"7",       "11",      "3",       "TEAM",},
	{"8",       "2",       "5",       "COMPUTER",},
	{"8",       "5",       "1",       "MAUSTASTE",},
	{"8",       "12",      "4",       "SPIELER",},
	{"9",       "1",       "3",       "FORMATION",},
	{"9",       "6",       "2",       "EINSTELLUNGEN",},
	{"9",       "9",       "3",       "SPIELES",},
	{"10",      "1",       "13",      "BUTTON",},
	{"10",      "4",       "1",       "MANNSCHAFTEN",},
	{"10",      "7",       "3",       "LIGA",},
	{"11",      "2",       "5",       "SAISON",},
	{"11",      "4",       "2",       "SIMULATIONSMODUS",},
	{"11",      "8",       "1",       "POKAL",},
	{"12",      "3",       "3",       "NAMEN",},
	{"12",      "5",       "5",       "TEAMAUSWAHL",},
	{"12",      "10",      "4",       "SIEGER",},
	{"13",      "1",       "1",       "NETZWERKSPIEL",},
	{"13",      "2",       "3",       "FUNKTION",},
	{"13",      "7",       "3",       "NETZ",},
	{"14",      "1",       "4",       "FALLE",},
	{"14",      "4",       "7",       "AUFSTELLUNG",},
	{"14",      "5",       "7",       "SEITE",},
	{"15",      "4",       "5",       "STEUERUNG",},
	{"15",      "6",       "1",       "SPIELART",},
	{"15",      "7",       "1",       "ARCADE",},
	{"16",      "1",       "1",       "UMGEBUNG",},
	{"16",      "7",       "4",       "STATUS",},
	{"17",      "1",       "2",       "KAMERAWINKEL",},
	{"17",      "1",       "5",       "RANSOCCER",},
	{"17",      "2",       "3",       "REGISSEUR",},
	{"19",      "7",       "1",       "FLUGWEITE",},
	{"19",      "7",       "3",       "BALLES",},
	{"19",      "12",      "1",       "CHANCEN",},
	{"23",      "2",       "6",       "ABWEHR",},
	{"23",      "4",       "1",       "ANGREIFERS",},
	{"23",      "7",       "3",       "HILFE",},
	{"26",      "1",       "1",       "ELFMETER",},
	{"26",      "3",       "1",       "RICHTUNG",},
	{"26",      "6",       "3",       "SCHIEDSRICHTER",},
	{"28",      "1",       "1",       "AUFSTELLUNG",},
	{"28",      "1",       "9",       "FORMATION",},
	{"28",      "4",       "4",       "SPIELERNUMMER",},
	{"30",      "1",       "3",       "TASTE",},
	{"30",      "1",       "11",      "AUGEN",},
	{"30",      "2",       "6",       "ZAHLENFELD",},
			    	 
	};
#endif

