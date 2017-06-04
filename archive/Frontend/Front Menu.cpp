#include "Frontend Vars.h"
#include "Front Menu.h"

#undef EXTERN
#define EXTERN extern
#include "Blitter.h"
#include "Flc Player.h"
#include "Memory.h"
#include "Menudisp.h"
#include "Mouse.h"
#include "Not Written Yet.h"
#include "Palette.h"
#include "Resource.h"
#include "Results.h"
#include "Slot.h"
#include "Sprite.h"
#include "Front Variables.h"

#if USERAVEENGINE==YES
#include "RAGE Starter Code.h"
#endif

// STATIC DATA
static char			pen1[5];
static char			pen2[5];
static char			penalty_text[80];
static int			messge;
static int			pen_index;
static int			state;
static int			TextFLAGS;

char *GetText(int text_number, int base )
{
#if 1
Str255 theString;
static char newString[192];
int a;

	if(base != textMain) 
		text_number++;
	base += (Language*50);

	GetIndString( theString, base, text_number);
	memcpy( newString, theString+1, (int)*theString);
	newString[*theString]=0;	

	return &newString[0];
#else
//	if (match_info.language==English || match_info.language==American)
		return(EnglishText[text_number-1]);
	if (match_info.language==French || match_info.language==Canadian)
		return(FrenchText[text_number-1]);
	if (match_info.language==German)
		return(GermanText[text_number-1]);
	if (match_info.language==Norwegian)
		return(NorwegianText[text_number-1]);

	return	("");
#endif
}

char *GetSTRING(int string_type,int array_number)
{
//char	*player;
char	*nostring	=	"";
char 	NumberBUFFER[3];
int	name_array;
int 	nametm;

	if (string_type<240 && string_type!=NULL)
		return(GetText(string_type));

	switch (string_type)
		{

		case(NULL):
				return("");

#ifdef WHEEL
		case(WHEEL_NUMBER):
			if (match_info.language==English)
				return(wheel);
			return("");

		case(MANUAL_WORD):
			if (match_info.language==German)
				return(wheel);
			return("");
		
		case(MANUAL1_TEXT):
			if (match_info.language==German)
				return	(GetSTRING(WHEEL1_TEXT, NULL));
			return	("");			       	

		case(MANUAL2_TEXT):
			if (match_info.language==German)
				return	(GetSTRING(WHEEL2_TEXT, NULL));
			return	("");			       	

		case(MANUAL3_TEXT):
			if (match_info.language==German)
				return	(GetSTRING(WHEEL3_TEXT, NULL));
			return	("");			       	

		case(MANUAL4_TEXT):
			if (match_info.language==German)
				return	(GetSTRING(MANUAL_PAGE_TEXT, NULL));
			return	("");			       	

		case(MANUAL_NO1):
			if (match_info.language==German)
				return	(manual[german_man].page);
			return	("");			       	

		case(MANUAL_NO2):
			if (match_info.language==German)
				return	(manual[german_man].line);
			return	("");			       	

		case(MANUAL_NO3):
			if (match_info.language==German)
				return	(manual[german_man].word);
			return	("");			       	

		case(WINDOW1_TEXT):
			if (match_info.language==English)
				{
				penalty_text[0]			=	NULL;
			       	strcpy(penalty_text, GetSTRING(WHEEL1_TEXT,NULL));
				pen_index			=	strlen	( penalty_text );
				penalty_text[pen_index-1]	=	WheelOuter+65;
				return	(penalty_text);			       	
				}
			return	("");			       	

		case(WINDOW2_TEXT):
			if (match_info.language==English)
				{
				penalty_text[0]			=	NULL;
				itoa(match_info.team_a_penalties,pen1,10);
			       	strcpy(penalty_text, GetSTRING(WHEEL2_TEXT,NULL));
				pen_index			=	strlen	( penalty_text );
				penalty_text[pen_index-1]	=	WheelInner+65;
				return	(penalty_text);			       	
				}
			return	("");			       	

		case(WINDOW3_TEXT):
			if (match_info.language==English)
				{
				penalty_text[0]			=	NULL;
		       	strcpy(penalty_text, GetSTRING(WHEEL3_TEXT,NULL));
				itoa(WindowNumber+1, pen1, 10);
				pen_index			=	strlen	( penalty_text );
				penalty_text[pen_index-2]	=	pen1[0];
				penalty_text[pen_index-1]	=	pen1[1];
				return	(penalty_text);			       	
				}
			return	("");			       	
#endif

		case(SLOT_NAME):
//			return(slot_names[array_number+(8*match_info.language)]);
			return GetText( array_number, textSlot);
			
		case(SLOT_STATE):
			SlotNumber	=	array_number;
			GetSLOTinfo();
			if ( SlotExists==0)
				return(GetText(NOT_USED_TEXT) );
			TextCOLOUR	=	BRIGHT_GREEN;
			return	(&SlotSTRING[0]);

#if 0
		case(CALIBRATE_TEXT):
			if ( calibrate_flag==255)
				return("");
			if ( calibrate_flag==1)
				{
#if TWOKEY==YES
				messge	= (MarkControlType-1+( 4* ((match_info.control_methods[MarkControlType-1])-JOYSTICK1) ));
				return( calibrate_message[messge+(8*match_info.language)] );
#else
{
char *p = calibrate_message[match_info.language];

				while(*p)
				  {
				  if(*p=='X') *p = MarkControlType+49;
				  if(*p=='Y') *p = match_info.control_methods[MarkControlType]+49;
				  p++;
				  }
				return calibrate_message[match_info.language];
}
#endif
				}
			if ( calibrate_flag==2)
				return(GetText(CENTRE_TEXT) );
			break;
				
		case(REDEFINE_TEXT):
			if ( redefine_flag==255)
				return("");
#if TWOKEY==YES
			else
				messge	= ( (MarkControlType-1)+( 4* ((match_info.control_methods[MarkControlType-1])) ));
			return( redefine_message[messge+(8*match_info.language)] );
#else
{
char *p = redefine_message[match_info.language];

				while(*p)
				  {
				  if(*p=='X') *p = MarkControlType+49;
				  if(*p=='Y') *p = match_info.control_methods[MarkControlType]+49;
				  p++;
				  }
				return redefine_message[match_info.language];
}
#endif				
				break;

		case(REQUEST_TEXT):
			if ( redefine_flag==255)
				return("");
			return(GetText(REQUEST_DIR_TEXT+array_number) );
#endif
				
		case(SKY_TEXT):
//			return(sky_types[setup.detail.sky+(2*match_info.language) ]);
			return GetText( setup.detail.sky, textSky );

		case(CHOSEN_KEY):
//			return(KEYtext[array_number]);
			return ("");

		case(PLAYER_LABEL):
			if ( array_number>match_info.NoOfPlayers || (match_info.CompetitionType==NETWORK && array_number!=0) )
				{
				TextCOLOUR	=	DULL_WHITE;
				return(GetText(NOT_USED_TEXT) );
				}  		
//			return(player_labels[array_number+(4*match_info.language)]);
			return GetText( array_number, textPlayers);

//		case(CONTROL_STATE):
//			return(control_labels[match_info.control_methods[array_number]+(4*match_info.language)]);

		case(OFFSIDE_TEXT):
//			return(sky_types[match_info.offside+(2*match_info.language)]);
			return GetText( match_info.offside, textSky);

		case(SUBS_TEXT):
//			return(sub_types[match_info.substitutes+(2*match_info.language)]);
			return GetText( match_info.substitutes, textSubs);

		case(FREEKICKS_TEXT):
//			return(sky_types[match_info.freekicks+(2*match_info.language)]);
			return GetText( match_info.freekicks, textSky);

		case(TIME_TEXT):
//			return(time_types[match_info.time]);
			return GetText( match_info.time, textTime);

		case(BOOKING_TEXT):
//			return(sky_types[match_info.bookings+(2*match_info.language)]);
			return GetText( match_info.bookings, textSky);

		case(WIND_TEXT):
//			return(wind_types[match_info.wind+(4*match_info.language)]);
			return GetText( match_info.wind, textWind);

		case(STADIUM_TEXT):
//			return(stadium_types[setup.detail.stadia+(2*match_info.language)]);
			return GetText( setup.detail.stadia, textStad);

		case(LINE_TEXT):
//			return(stadium_types[setup.detail.lines+(2*match_info.language)]);  	       	// same as stadium  HIGH/LOW
			return GetText( setup.detail.lines, textStad);

		case(VIDI_TEXT):
//			return(sky_types[match_info.vidi+(2*match_info.language)]);       		// same as sky ON/OFF
			return GetText( match_info.vidi, textSky);

		case(PLAYER_TEXT):
//			return(stadium_types[setup.detail.players+(2*match_info.language)]);         	// same as stadium  HIGH/LOW
			return GetText( setup.detail.players, textStad);

		case(PITCH_TEXT):
//			return(pitch_types[setup.detail.pitch+(3*match_info.language)]);  	       	// same as stadium  HIGH/LOW
			return GetText( setup.detail.pitch, textPitch);

		case(RES_TEXT):
//			return(stadium_types[setup.start_res+(2*match_info.language)]);	  	       	// same as stadium  HIGH/LOW
			return GetText( setup.start_res, textStad);

		case(CAMERA_TEXT):
//			return(camera_types[match_info.camera+(7*match_info.language)]);
			return GetText( match_info.camera, textCamera);
			
		case(SIZE_TEXT):
//			return(size_types[setup.screen_size]);
			return GetText( setup.screen_size, textSize);

		case(AUDIO_TEXT): 
//			return(audio_types[match_info.audio+(3*match_info.language)]);
			return GetText( match_info.audio, textAudio);

		case(FORMATION_TEXT):
//			return(formation_types[game_data[selected_team].formation]);
			return GetText( game_data[selected_team].formation, textForm);
			
		case(PLAYER_NAME):
			return(game_data[selected_team].players[array_number].name);
		
		case(SLOT_TITLE):
			if (slot_TITLE==NULL)
				{
				strcpy(slot_TITLETEXT,GetText(UNTITLED_TEXT));
				slot_TITLE = &slot_TITLETEXT[0];
				}
			return(slot_TITLE);

		case(REFEREE_NAME):
			if	( match_info.referee>15+16 )
				{
				TextCOLOUR	=	175;
				return(GetText(RANDOM_TEXT));
				}
			return( referee_data[match_info.referee].name );

		case(REFEREE_COUNTRY):
			if	( match_info.referee>15+16 )
				return("");
			return( game_data[ referee_data[match_info.referee].country ].Nickname );

		case(PLAYER_NAME_TEAMa):
			return(game_data[setup.team_a].players[array_number].name);

		case(PLAYER_NAME_TEAMb):
			return(game_data[setup.team_b].players[array_number].name);

		case(COACH_NAME):
			return(game_data[selected_team].coachname);

		case(NoOfPLAYERS_TEXT):
//			return( NoOfPLAYERS_types[match_info.NoOfPlayers+(12*match_info.language)]);
			return GetText( match_info.NoOfPlayers, textNoOfPlay );
			
		case(GAMEtype_TEXT):
//			return(Game_types[match_info.GameType+(2*match_info.language) ]);
			return GetText( match_info.GameType, textGameType);
			
		case(COMPETITION_TEXT):
//			return(COMPETITION_types[match_info.CompetitionType+(5*match_info.language) ]);
			return GetText( match_info.CompetitionType, textCompType);
			
		case(NETWORK_TEXT):
//			return(NETWORK_types[NetworkType+(2*match_info.language)]);
			return GetText( NetworkType, textNetwType);
			
		case(SELECTED_PLAYER_NAME):
//			if 	(match_info.menu_res==LO)
//				TextYposn+=	2;
			return(game_data[selected_team].players[selected_player].name);

		case(RANK_HEADING):
//			if 	(match_info.menu_res==LO)
//				TextYposn+=	2;
			return(GetText(RANK_A_TEXT+array_number));

		case(SELECTED_TEAM_NAME):
//			if 	(match_info.menu_res==LO)
//				TextYposn+=	2;
			return(game_data[selected_team].name);

		case(TEAM_NAMEa):
			return(game_data[setup.team_a].Nickname);

		case(TEAM_NAMEb):
			return(game_data[setup.team_b].Nickname);

		case(WINNERS_NAME):
			return(game_data[batch_info.winners].Nickname);

		case(RUNNERS_UP_NAME):
			return(game_data[batch_info.runners_up].Nickname);

		case(TEAM_NAMEa_SCORE):
			itoa	( match_info.team_a_score, NumberBUFFER,10);			
			DisplaySTRING( NumberBUFFER, SHADOWtextON|MFONT|CENTREjustifyTEXT);
			return(nostring);

		case(TEAM_NAMEb_SCORE):
			itoa	( match_info.team_b_score, NumberBUFFER,10);			
			DisplaySTRING( NumberBUFFER, SHADOWtextON|MFONT|CENTREjustifyTEXT);
			return(nostring);

		case(VENUE_TEXT):
//			return(VENUES[match_info.venue+(45*match_info.language)]);
			return GetText( match_info.venue, textVenues);
		case(PARTICIPATING_TEAM_NAME):
			return(game_data[array_number].Nickname);

		case(RESULT_TEAM_NAMEa):
			if ( results[ (batch_info.round_up_page+array_number) ].result_data.team_a_score>MAX_TEAMS+1 )
				{
      			TextCOLOUR	=	DULL_WHITE;
				return (" ");
				}
			return(game_data[ results[ (batch_info.round_up_page+array_number) ].result_data.team_a].Nickname);

		case(RESULT_TEAM_NAMEb):
			if ( results[ (batch_info.round_up_page+array_number) ].result_data.team_b_score>MAX_TEAMS+1 )
				{
      			TextCOLOUR	=	DULL_WHITE;
				return (" ");
				}
			return(game_data[ results[ (batch_info.round_up_page+array_number) ].result_data.team_b].Nickname);

		case(RESULT_TEAMa):
			if ( results[ (batch_info.round_up_page+array_number) ].result_data.team_a_score!=255 )
				{
				itoa	( results[ (batch_info.round_up_page+array_number) ].result_data.team_a_score , NumberBUFFER,10);			
				DisplaySTRING( NumberBUFFER, SHADOWtextON|SFONT|CENTREjustifyTEXT);
				}
			return(nostring);

		case(RESULT_TEAMb):
			if ( results[ (batch_info.round_up_page+array_number) ].result_data.team_b_score!=255 )
				{
				itoa	( results[ (batch_info.round_up_page+array_number) ].result_data.team_b_score , NumberBUFFER,10);			
				DisplaySTRING( NumberBUFFER, SHADOWtextON|SFONT|CENTREjustifyTEXT);
				}
			return(nostring);
	
		case(CHOOSE_TEAM_NAME):
			return(game_data[array_number].Nickname);
	
		case(DOS_TEXT):
			return("QUIT");
	
		case(PLAYER_FORMATION):
			TextXposn	=	formation_data[formation_toggle].formations[array_number].formation_xposn;
			TextYposn	=	formation_data[formation_toggle].formations[array_number].formation_yposn;
			TextFLAGS	=	formation_data[formation_toggle].formations[array_number].formation_flags;
			return(formation_data[formation_toggle].formations[array_number].formation_no);

		case(TEAM_SEASON_END):
			for (nametm = 0; nametm < MAX_TEAMS-1; nametm++)
				{
				if ( array_number == ( (game_data[nametm].division*16)+game_data[nametm].position) )
					name_array	=	nametm;
				}
			return( game_data[name_array].Nickname );

		case(GAMETYPE_TEXT):
			if	(match_info.CompetitionType==FRIENDLY)
				return(GetText(FRIENDLY_TEXT));
			else if	(match_info.CompetitionType==PRACTICE)
				return(GetText(PRACTICE_TEXT));
			else if	(match_info.CompetitionType==LEAGUE)
				{
				if(game_data[setup.team_a].division==0)
					return(GetText(DIVISION1_TEXT));
				else if	(game_data[setup.team_a].division==1)
					return(GetText(DIVISION2_TEXT));
				else if	(game_data[setup.team_a].division==2)
					return(GetText(DIVISION3_TEXT));
				}
			else if	(match_info.CompetitionType==CUP && match_info.extra==NULL && match_info.penalties==NULL)
//				return( ROUNDS[batch_info.Round_index+(9*match_info.language)] );
				return GetText( batch_info.Round_index, textRounds);
			else if	(match_info.CompetitionType==CUP && match_info.extra!=NULL && match_info.penalties==NULL)
				return(GetText(EXTRA_TIME_TEXT));
			else if	(match_info.CompetitionType==CUP && match_info.penalties!=NULL)
				{
				penalty_text[0]		=	NULL;
				if (match_info.team_a_penalties > match_info.team_b_penalties)
			       	strcpy(penalty_text, GetSTRING(TEAM_NAMEa,NULL));
				else
			       	strcpy(penalty_text, GetSTRING(TEAM_NAMEb,NULL));
				pen_index = 0;
				if (match_info.team_a_penalties<10 && match_info.team_b_penalties<10)
					{
					strcat(penalty_text,(GetText(ON_PENALTIES_TEXT)));
					while( penalty_text[pen_index]!='0' || penalty_text[pen_index+2]!='0')
						pen_index++;
					if (match_info.team_a_penalties > match_info.team_b_penalties)
						{
						penalty_text[pen_index] = match_info.team_a_penalties+48;
						penalty_text[pen_index+2] = match_info.team_b_penalties+48;
						}
					else
						{
						penalty_text[pen_index] = match_info.team_b_penalties+48;
						penalty_text[pen_index+2] = match_info.team_a_penalties+48;
						}
					}
				else
					strcat(penalty_text,(GetText(OVER10PEN_TEXT)));
				return	(penalty_text);			       	
				}
			else if	(match_info.CompetitionType==NETWORK && net_error==0)
				return(GetText(NETWORK_GAME_TEXT));
			else if	(match_info.CompetitionType==NETWORK && net_error==-1)
				return(GetText(NETWORK_ABORT_TEXT));
			else if	(match_info.CompetitionType==NETWORK && net_error==-2)
				return(GetText(NETWORK_SYNC_TEXT));
			break;

		case(CUSTOMISE_TEXT):
			return(GetText(CUSTOM_TEXT));
//			if (match_info.language!=American)
//				return(GetText(CUSTOM_TEXT));
//			return	("CUSTOMIZE");			       	

		case(ROUNDUP_CONCLUSION):
			if	(match_info.CompetitionType==CUP && 
				results[ (batch_info.round_up_page+array_number) ].result_data.extra!=NULL && 
				results[ (batch_info.round_up_page+array_number) ].result_data.penalties==NULL)
	     		return(GetText(After_Extra_TEXT));
			if	(match_info.CompetitionType==CUP && results[ (batch_info.round_up_page+array_number) ].result_data.penalties!=NULL)
				{
				for (int clrFlag = 0; clrFlag < 80; clrFlag++)
					{penalty_text[clrFlag] 	= NULL;}

				if (results[ (batch_info.round_up_page+array_number) ].result_data.team_a_penalties > results[ (batch_info.round_up_page+array_number) ].result_data.team_b_penalties)
					{
			       	strcpy(penalty_text, GetSTRING(RESULT_TEAM_NAMEa, array_number));
					pen_index	=	strlen	( GetSTRING(RESULT_TEAM_NAMEa, array_number) );
					}
				else
					{
				    strcpy(penalty_text, GetSTRING(RESULT_TEAM_NAMEb, array_number));
					pen_index	=	strlen	( GetSTRING(RESULT_TEAM_NAMEb, array_number) );
					}
				
				if ( results[ (batch_info.round_up_page+array_number) ].result_data.team_a_penalties < 10 &&
			     results[ (batch_info.round_up_page+array_number) ].result_data.team_b_penalties < 10 )
					{				
					strcat(penalty_text,(GetText(ON_PENALTIES_TEXT2)) );

					if (results[ (batch_info.round_up_page+array_number) ].result_data.team_a_penalties > results[ (batch_info.round_up_page+array_number) ].result_data.team_b_penalties)
						{
						itoa(results[ (batch_info.round_up_page+array_number) ].result_data.team_a_penalties,pen1,10);
						itoa(results[ (batch_info.round_up_page+array_number) ].result_data.team_b_penalties,pen2,10);
						}
					else
						{
						itoa(results[ (batch_info.round_up_page+array_number) ].result_data.team_a_penalties,pen2,10);
						itoa(results[ (batch_info.round_up_page+array_number) ].result_data.team_b_penalties,pen1,10);
						}

					{
int a;
					for( a=0; a< strlen( penalty_text); a++)
						if( penalty_text[a] == '0' && penalty_text[a+2] == '0')
							break;
					
					penalty_text[a] = pen1[0];
					penalty_text[a+2] = pen2[0];
					}
//					if (match_info.language==English || match_info.language==American)
//						{
//						penalty_text[pen_index+5]	=	pen1[0];
//						penalty_text[pen_index+7]	=	pen2[0];
//						}				
//					if (match_info.language==French || match_info.language==Canadian)
//						{
//						penalty_text[pen_index+9]	=	pen1[0];
//						penalty_text[pen_index+11]	=	pen2[0];
//						}
//					if (match_info.language==German)
//						{
//						penalty_text[pen_index+8]	=	pen1[0];
//						penalty_text[pen_index+10]	=	pen2[0];
//						}
//					if (match_info.language==Norwegian)
//						{
//						penalty_text[pen_index+6]	=	pen1[0];
//						penalty_text[pen_index+8]	=	pen2[0];
//						}
					}
				else
					{
					strcat(penalty_text,(GetText(OVER10PEN_TEXT2)));
					}
				return	(penalty_text);			       	
				}
			if	( (match_info.CompetitionType!=CUP) || (match_info.CompetitionType==CUP && 
				results[ (batch_info.round_up_page+array_number) ].result_data.extra==NULL && 
				results[ (batch_info.round_up_page+array_number) ].result_data.penalties==NULL) )
					return("");
			break;

		case(LEAGUE_TEAM):
 			state	=	FALSE;
			for (int PosnFlag = 0; PosnFlag < MAX_TEAMS-1; PosnFlag++)
				{
				if ( game_data[PosnFlag].division == batch_info.Ranking_Division && game_data[PosnFlag].position == array_number )
					{
					SelectedLEAGUEteam = PosnFlag;	
					state	=	TRUE;
					}
				}

			if (state == TRUE)
				return(game_data[SelectedLEAGUEteam].name);
			return(NULL);
/*
#if USERAVEENGINE==YES
		case RAVE_TEXT:
			return "RAVE";
		case RAVE_TEXT+1:
			return "ENGINE NAME";
		case RAVE_TEXT+2:
			return EngineName[ ThisEngineNumber];
		case RAVE_TEXT+3:
			return "FILTERING";
		case RAVE_TEXT+4:
			if( !TextureQuality)
				return "LOW QUALITY";
			else if( TextureQuality==1)
				return "MEDIUM QUALITY";
			else
				return "HIGH QUALITY";
		case RAVE_TEXT+5:
			return "NEXT";
#endif
*/
		}
	
	return(nostring);
}

int	GetSPRITEnumber(int sprite_type,int number,int LastSpriteNO)
{
int	SpriteIMAGEno	=	NULL;
int	TemporyFlag	=	0;
Sprite			=	OFF;		
int	IndexFlag;

	switch(sprite_type)
		{
	  	case(PLAYER_STAT_ICON):
			if (game_data[selected_team].players[number].pace >= 80)
				{
				SpriteIMAGEno	=	PACE_IMAGE;
				TemporyFlag	=	game_data[selected_team].players[number].pace;
				}

			if (game_data[selected_team].players[number].power >= 80 && game_data[selected_team].players[number].power > TemporyFlag)
				{
				SpriteIMAGEno	=	POWER_IMAGE;
				TemporyFlag	=	game_data[selected_team].players[number].power;
				}

			if (game_data[selected_team].players[number].control >= 80 && game_data[selected_team].players[number].control > TemporyFlag)
				{
				SpriteIMAGEno	=	CONTROL_IMAGE;
				TemporyFlag	=	game_data[selected_team].players[number].control;
				}
									
			if (game_data[selected_team].players[number].flair >= 80 && game_data[selected_team].players[number].flair > TemporyFlag)
				{
				SpriteIMAGEno	=	FLAIR_IMAGE;
				TemporyFlag	=	game_data[selected_team].players[number].flair;
				}
									
			if (game_data[selected_team].players[number].accuracy >= 80 && game_data[selected_team].players[number].accuracy > TemporyFlag)
				{
				SpriteIMAGEno	=	ACCURACY_IMAGE;
				TemporyFlag	=	game_data[selected_team].players[number].accuracy;
				}

			if (game_data[selected_team].players[number].vision >= 80 && game_data[selected_team].players[number].vision > TemporyFlag)
				{
				SpriteIMAGEno	=	VISION_IMAGE;
				TemporyFlag	=	game_data[selected_team].players[number].vision;
				}
									
			if (game_data[selected_team].players[number].stamina >= 80 && game_data[selected_team].players[number].stamina > TemporyFlag)
				{
				SpriteIMAGEno	=	STAMINA_IMAGE;
				TemporyFlag	=	game_data[selected_team].players[number].stamina;
				}
									
			if (game_data[selected_team].players[number].discipline >= 80 && game_data[selected_team].players[number].discipline > TemporyFlag)
				SpriteIMAGEno	=	DISCIPLINE_IMAGE;

			break;
		case(GREMLIN_INTERACTIVE):			
			SpriteIMAGEno	= 	SMALL_GREM_LOGO;
	  		break;
		case(TEAM_FLAG_ICON):
			SpriteIMAGEno	=	USA_FLAG+(tempFrame >>8)+(number*8);
			break;
		case(RESULT_FLAG_ICON):
			if ( number<8 )
		  		IndexFlag	=	results[ (batch_info.round_up_page+number) ].result_data.team_a;
			else
		  		IndexFlag	=	results[ (batch_info.round_up_page+(number-8) ) ].result_data.team_b;
			SpriteIMAGEno	=	USA_FLAG+(IndexFlag*8);
			
			if ( (number<8 && results[ (batch_info.round_up_page+number) ].result_data.team_a_score==255 ) || (number>=8 && results[ (batch_info.round_up_page+number-8) ].result_data.team_b_score==255 ) )
				SpriteIMAGEno	=	NULL;
			break;
		case(CHOICE_FLAG_ICON):
			SpriteIMAGEno = USA_FLAG+(tempFrame >>8)+(menu_data[MENU_A15].StringLIST[number].string_array*8);
			break;
		case(REF_FLAG_ICON):
			if ( match_info.referee>(15+16) )
				SpriteIMAGEno	=	ACTUA_FLAG+ (tempFrame>>8);
			else			
				SpriteIMAGEno	=	USA_FLAG+(tempFrame >>8)+( referee_data[match_info.referee].country*8);
			break;
		case(TEAM_BIG_FLAGa):
			SpriteIMAGEno	=	(BIG_FLAG+setup.team_a);
			break;
		case(TEAM_KITa):
			SpriteIMAGEno	=	(USA_KIT_IMAGE+setup.team_a);
			break;
		case(TEAM_KITb):
			setup.team_b_kit	=	team_b_kit[ ((setup.team_a*MAX_TEAMS)+setup.team_b) ];
			SpriteIMAGEno		=	USA_KIT_IMAGE+setup.team_b_kit;
			break;
		case(TEAM_BIG_FLAGb):
			SpriteIMAGEno	=	(BIG_FLAG+setup.team_b);
			break;
		case(VERSUS_TEAM_IMAGE):
			SpriteIMAGEno	=	VERSUS_IMAGE;
			break;
		case(COMPETITION_IMAGE):
			if ( match_info.CompetitionType==FRIENDLY || match_info.CompetitionType==NETWORK || match_info.CompetitionType==PRACTICE )
				SpriteIMAGEno 	=	BIG_BALL_IMAGE;
			if ( match_info.CompetitionType==LEAGUE )
				SpriteIMAGEno 	=	GOLD_CUP_BIG;
			if ( match_info.CompetitionType==CUP )
				SpriteIMAGEno 	=	SILVER_CUP_BIG;
			break;
		case(SILVER_CUP):
			SpriteIMAGEno	=	SILVER_CUP_IMAGE+(tempFrame >>8);
			break;
		case(SERIES_IMAGE):
			SpriteIMAGEno	=	SERIES_LOGO;
			break;
		case(GOLD_CUP):
			SpriteIMAGEno	=	GOLD_CUP_IMAGE+(tempFrame >>8);
			break;
		case(TEAMS_4_LIGHT):
			SpriteIMAGEno	=	TEAMS_4_HIGHLGT;
			break;
		case(TEAMS_8_LIGHT):
			SpriteIMAGEno	=	TEAMS_8_HIGHLGT;
			break;
		case(TEAMS_16_LIGHT):
			SpriteIMAGEno	=	TEAMS_16_HIGHLGT;
			break;
		case(TEAMS_32_LIGHT):
			SpriteIMAGEno	=	TEAMS_32_HIGHLGT;
			break;
		case(SLIDER):
			SpriteIMAGEno	=	SLIDE_IMAGE;
			break;
		case(ACTUA_LOGO):
			SpriteIMAGEno	=	ACTUA_FLAG+(tempFrame >>8);	//+(number*8);
			break;
		case(JOYSTICK_ICON):
			SpriteIMAGEno	=	JOYSTICK_IMAGE;
			break;
		}
	if(SpriteIMAGEno==LastSpriteNO)
	  Sprite	=	OFF;
	else
	  Sprite	=	ON;

	return	(SpriteIMAGEno);
}

int GetSTATvalue(int string_type,int array_number,int stat_type)
{		

	if (string_type==PLAYER_STAT)
		{
		switch (stat_type)
			{
			case(PACE):
				return(game_data[selected_team].players[selected_player].pace);

			case(POWER):
				return(game_data[selected_team].players[selected_player].power);

			case(CONTROL):
				return(game_data[selected_team].players[selected_player].control);

			case(FLAIR):
				return(game_data[selected_team].players[selected_player].flair);

			case(VISION):
				return(game_data[selected_team].players[selected_player].vision);

			case(ACCURACY):
				return(game_data[selected_team].players[selected_player].accuracy);

			case(STAMINA):
				return(game_data[selected_team].players[selected_player].stamina);

			case(DISCIPLINE):
				return(game_data[selected_team].players[selected_player].discipline);

			case(REFS_VISION):
				if (match_info.referee>15+16)
					return(ref_vision);
				return(referee_data[match_info.referee].vision);
				
			case(REFS_DISCIPLINE):
				if (match_info.referee>15+16)
					return(ref_disc);
				return(referee_data[match_info.referee].discipline);
			 }
		}
	return(0);
}


int GetBUTTONnumber(int button_type, int button_index, int button_flags)
{
int	SPIN_BUTTON_TYPE =	button_index;

	switch (button_type)
		{
    	case(KIT_BUTTON):
			return(USA_KIT_IMAGE+selected_team);

		case(ACTUA_BUTTON):
			return(ACTUA_FLAG);
	
		case(WAVE_BUTTON):
			return(STADIUM_IMAGE);
	
		case(FLAG_BUTTON):
			return( USA_FLAG+(selected_team*8) );
	
		case(CLICK_BUTTON):
			return( CLICK_IMAGE );
	
		case(TEAMS_BUTTON):
			return( TEAMS_4+button_index );
		
		case(TEST_BUTTON):
			return( GREMLIN_FLAG+6 );	//button_index );
		
		case(SLIDE_BAR):
			return(STATS_HEAD_IMAGE);
		
       	case(UP_ARROW_BUTTON):
			return( UP_ARROW_IMAGE );
		
		case(DOWN_ARROW_BUTTON):
			return( DOWN_ARROW_IMAGE );
		
       	case(SELECTION_BUTTON):
			return( SELECTION_IMAGE );
		
       	case(REF_BUTTON):
			return(REFS_KIT_IMAGE);
		
       	case(SPIN_BUTTON):
			if ( (button_flags & MINI_BUTTON)!=0)
				SPIN_BUTTON_TYPE += MINI_SPIN_IMAGE;							
			if ( (button_flags & STANDARD_BUTTON)!=0)
				SPIN_BUTTON_TYPE += SPIN_BUTTON_IMAGE;							
			return( SPIN_BUTTON_TYPE );

		}
	return(0);
}

long CheckSums_hi[] = { 62465571, 62465571, 60412275, 60529223, 60529223};

void	Initialise_menu(int menu_number)
{
int chksum = 1;

	MouseDeBOUNCE = TRUE;

	if( menu_number == MENU_A23)
		FlcPlaying = true;
	else
		FlcPlaying = false;
		
//	if(match_info.menu_res == HI)
	  BlitterMode = REAL_640480;
//	else
//	  BlitterMode = DOUBLE_320240;
	
	if (menu_number==MENU_A22 && match_info.CompetitionType==LEAGUE)
		{
		if (batch_info.match_number!=-1)
			batch_info.round_up_page	=	(batch_info.match_number-8);
		}
	if (menu_number==MENU_A22 && match_info.CompetitionType==CUP)
		batch_info.round_up_page	=	batch_info.cup_match_number-(batch_info.RoundPrint+1);	//8;

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Unmangle a 640x480 background bitmap file to background buffer. If a NULL filename is passed then the background buffer	 บ
//บ  is cleared. Then background buffer is then copied to the psudo buffer (working buffer).                                     บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

	if	(menu_data[menu_number].BkgBITMAPfile==-1)
		memset(  background_buffer, 0, background_buffer_LEN );
	else
		{
		if(LoadBinaryDirect( background_buffer, RESTYPE_DATA, NORMRES(menu_data[menu_number].BkgBITMAPfile)))
			{
			  // Load_data
			  // English, French		menu_data[menu_number].BkgBITMAPfile+resolution,	"DATA.DAT",		background_buffer
			  // Norwegian			menu_data[menu_number].BkgBITMAPfile+resolution,	"NORWAY.DAT",	background_buffer
			  // American, Canadian	menu_data[menu_number].BkgBITMAPfile+resolution,	"VRDATA.DAT",	background_buffer
			  // German				menu_data[menu_number].BkgBITMAPfile+resolution,	"RANDATA.DAT",	background_buffer

			if (menu_number==MENU_A0)
				{
				chksum = 0;
				for (int c=0; c<background_buffer_LEN-1; c++)
					chksum += background_buffer[c];
				if( chksum != CheckSums_hi[match_info.language])
					bomb_message |= 0x80;
			 	}
			}
		else
			bomb_message |= 0x80;
		}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Unmangle header at top of psudo buffer.											 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

	if	(menu_data[menu_number].HeaderBITMAPfile!=-1)
		{
		LoadBinaryDirect( background_buffer+header_y, RESTYPE_DATA, NORMRES(menu_data[menu_number].HeaderBITMAPfile) );
// Load_data
// English, French		menu_data[menu_number].HeaderBITMAPfile+resolution,		"DATA.DAT",		background_buffer+header_y
// Norwegian			menu_data[menu_number].HeaderBITMAPfile+resolution,		"NORWAY.DAT",	background_buffer+header_y
// German				menu_data[menu_number].HeaderBITMAPfile+resolution,"	"RANDATA.DAT",	background_buffer+header_y
// American, Canadian	menu_data[menu_number].HeaderBITMAPfile+resolution,		"VRDATA.DAT",	background_buffer+header_y
		}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Unmangle 768 bytes of palette data into palette buffer. If a NULL filename is passed then the palette buffer is cleared.	 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

{
BYTE pal1[(55-31)*3];
BYTE pal2[(87-79)*3];

   	if	(menu_number==MENU_A17 || menu_number==MENU_A19)
		{
		memcpy(  pal1, palette_buffer+(32*3), ((55-31)*3) );
		memcpy(  pal2, palette_buffer+(80*3), ((87-79)*3) );
		}		

	if	(menu_data[menu_number].PaletteDATAfile==-1)
		ClearPalette();			// memset( palette_buffer, 0, 768 );
	else
		LoadBinaryDirect( palette_buffer, RESTYPE_DATA, NORMRES(menu_data[menu_number].PaletteDATAfile) );

	if	(menu_number==MENU_A17 || menu_number==MENU_A19)
		{
		memcpy(  palette_buffer+(32*3), pal1, ((55-31)*3) );
		memcpy(  palette_buffer+(80*3), pal2, ((87-79)*3) );
		}		
}
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Sets up mouse movement range. The user will not be able to move the cursor outside this bounding area.                      บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
	
	MouseFlags&=	65535-REPL_BKG;
	ShirtFlags&=	65535-REPL_BKG;

		if (keyboard==0)
			InitialiseMOUSE();

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Display static images to be displayed on menu.                                                                              บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

	int 	ImageNumber;
	
	for (int imagenum = 0; imagenum < MAX_IMAGES; imagenum++)
	{

		if ( menu_data[menu_number].ImageLIST[imagenum]!=NULL )
		{
		       		ImageNumber		=	menu_data[menu_number].ImageLIST[imagenum]-1;	
				SpriteXposn		=	menu_images[ImageNumber].ImageXposn;		
				SpriteYposn		=	menu_images[ImageNumber].ImageYposn;		
				ShadowXoffset		=	menu_images[ImageNumber].ImageShadowXposn;		
				ShadowYoffset		=	menu_images[ImageNumber].ImageShadowYposn;		
			    	
				SetupSpriteDATA(menu_images[ImageNumber].ImageNumber); 
				DisplayDESTINATION	=	background_buffer;	//psudo_buffer;	


			if ( ( menu_images[ImageNumber].ImageState & SMALL ) ==0 )
			{
				if ( (menu_images[ImageNumber].ImageState & SHADOWimageON)!=0 )			
					DrawSPRITEshadow();
					DrawSPRITE();
			}

			if ( ( menu_images[ImageNumber].ImageState & SMALL ) !=0 )
			{
				if ( (menu_images[ImageNumber].ImageState & SHADOWimageON)!=0 )			
					DrawSmallSPRITEshadow();
					DrawSmallSPRITE();
			}
			

		}

	}			
	memcpy( psudo_buffer, background_buffer, background_buffer_LEN );

	  	  
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Display static labels to be displayed on menu.                                                                              บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

	int 	LabelNumber;
	short	TempXposn;
	short	TempYposn;
	
	for (int labelnum = 0; labelnum < MAX_LABELS; labelnum++)
	{

		if ( menu_data[menu_number].LabelLIST[labelnum]!=NULL )
		{
		       		LabelNumber		=	menu_data[menu_number].LabelLIST[labelnum]-1;	
				TextXposn		=	menu_labels[LabelNumber].LabelXposn;		
				TextYposn		=	menu_labels[LabelNumber].LabelYposn;		
				TempXposn		=	TextXposn;	
				TempYposn		=	TextYposn;	
				TextCOLOUR		=	menu_labels[LabelNumber].LabelColour;		

				DisplayDESTINATION	=	psudo_buffer;	
				FontDataADDR		=	sfont_buffer;	
				TiltFRAME		=	NULL;
				DisplaySTRING( GetSTRING(menu_labels[LabelNumber].TextLabel,NULL) , menu_labels[LabelNumber].LabelShadow );

				if ( (menu_labels[LabelNumber].LabelShadow & COPY_TO_BACK)!=0 )
				{
					DisplayDESTINATION	=	background_buffer;	
					TextXposn		=	TempXposn;					
					TextYposn		=	TempYposn;					
					DisplaySTRING( GetSTRING(menu_labels[LabelNumber].TextLabel,NULL) , menu_labels[LabelNumber].LabelShadow );
				}
		}

	}			

/*
#if ROLLING_DEMO!=OFF
	DisplayDESTINATION	=	psudo_buffer;	
	TextCOLOUR			= 175;
	TextXposn			= 320;
	TextYposn			= 4;
	FontDataADDR		= sfont_buffer;	
	TiltFRAME			= NULL;
	DisplaySTRING( "Actua Soccer Rolling Demo", SFONT|CENTREjustifyTEXT );
#else
#if USERAVEENGINE==YES
{
char string[]="RAVE\000";
	DisplayDESTINATION	=	psudo_buffer;	
	TextCOLOUR			= 175;
	TextXposn			= 0;
	TextYposn			= 20;
	FontDataADDR		= sfont_buffer;	
	TiltFRAME			= NULL;
	DisplaySTRING( string, SFONT );
}
#endif
#if FINAL
{
char string[]="F 1\000\000\000";
	DisplayDESTINATION	=	psudo_buffer;	
	TextCOLOUR			= 175;
	TextXposn			= 0;
	TextYposn			= 0;
	FontDataADDR		= sfont_buffer;	
	TiltFRAME			= NULL;
	if( FINAL>9)
		string[1] = 48 + (FINAL/10);
	string[2] = 48 + (FINAL%10);
	DisplaySTRING( string, SFONT );
}
#else
#if BETA
{
char string[]="Beta  1 ("__DATE__") ("__TIME__")";
	DisplayDESTINATION	=	psudo_buffer;	
	TextCOLOUR			= 175;
	TextXposn			= 0;
	TextYposn			= 0;
	FontDataADDR		= sfont_buffer;	
	TiltFRAME			= NULL;
	if( BETA>9)
		string[5] = 48 + (BETA/10);
	string[6] = 48 + (BETA%10);
	DisplaySTRING( string, SFONT );
}
#endif
#endif
#endif
*/

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Display specialist strings.                                                                                                 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

	ColourPOSN(MENU_A9,selected_team);


	int 	ArrayNumber;
	int 	StatTYPE;

	state	=	TRUE;

	for (int stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
	{
			
		if ( menu_data[menu_number].StringLIST[stringnum].string_type!=NULL )

		{
		       		ArrayNumber	=	menu_data[menu_number].StringLIST[stringnum].string_array;	
				TextXposn	=	menu_data[menu_number].StringLIST[stringnum].string_xposn;
				TextYposn	=	menu_data[menu_number].StringLIST[stringnum].string_yposn;
				TextFLAGS	=	menu_data[menu_number].StringLIST[stringnum].string_shadow;

			
			
				TextCOLOUR	=	menu_data[menu_number].StringLIST[stringnum].string_colour;

			if ( (menu_data[menu_number].StringLIST[stringnum].string_flags & TOGGLE_FLAG)!=0)
				
				TextCOLOUR	=	menu_data[menu_number].StringLIST[stringnum].string_mark_colour;





		if (menu_data[menu_number].StringLIST[stringnum].string_type==PLAYER_STAT)
			{
			StatTYPE	=	menu_data[menu_number].StringLIST[stringnum].stat_array;	
			DisplaySTARstats( GetSTATvalue(menu_data[menu_number].StringLIST[stringnum].string_type,ArrayNumber,StatTYPE) );
			}

			else
		
			{		
			
			char *Str;
			
			Str = GetSTRING( menu_data[menu_number].StringLIST[stringnum].string_type, ArrayNumber );

				if (state==TRUE)
					DisplaySTRING( Str, TextFLAGS );
			}
				    
		if ( (TextFLAGS & LEAGUE_DATA)!=0 & state==TRUE)
			DisplayLEAGUEdata(TextFLAGS);
		}
	}

		if ( menu_number==MENU_A16 )
		{
			TextXposn	=	A08xBigTAB-24;
			TextYposn	=	310;
			DisplayGOALscorers( CREDIT_TEAMa, match_info.team_a_score );
			TextXposn	=	(A08xBigTAB*2)+24+sprite_999width;
			TextYposn	=	310;
			DisplayGOALscorers( CREDIT_TEAMb, match_info.team_b_score );
		}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Reset sprite flags and draw sprites.                                                                                        บ   
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

	for (int spritenum = 0; spritenum < MAX_SPRITES; spritenum++)
	{
  	menu_data[menu_number].SpriteTABLE[spritenum].sprite_state&= (65535-OLD_SPRITE_FLAG);
	menu_data[menu_number].SpriteTABLE[spritenum].LastSpriteNo	=		NULL;
	}			
	Display_Sprites(menu_number);

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Display selector buttons.                                                                                                   บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

	for (int buttonnum = 0; buttonnum < MAX_BUTTONS; buttonnum++)
	{
  	menu_data[menu_number].ButtonLIST[buttonnum].button_flags&= (65535-OLD_SPRITE_FLAG-START_SPIN);
	menu_data[menu_number].ButtonLIST[buttonnum].LastButtonNo	=		NULL;
		
		if (menu_data[menu_number].ButtonLIST[buttonnum].button_type==SPIN_BUTTON)
			menu_data[menu_number].ButtonLIST[buttonnum].button_index = 	NULL;

	menu_data[menu_number].ButtonLIST[buttonnum].LastButtonNo	=		NULL;
	}			
	Animate_Buttons(menu_number);

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Copy Psudo Buffer to actual screen.                                                                                         บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
	BlitBufferToScreen((double *) psudo_buffer);
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Highlight number of participating teams on kits for cup competition.                                                        บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Do_cupsetup_highlights()
{
	int	res_offset;

	if ( current_menu==MENU_A2 )
	{
//		if (match_info.menu_res==LO)
//			res_offset	=	4;
//		else	
			res_offset	=	0;

		if (batch_info.number_of_cup_teams==4)
			{
		menu_data[MENU_A2].SpriteTABLE[1+res_offset].sprite_state|=	ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[2+res_offset].sprite_state&=	65535-ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[3+res_offset].sprite_state&=	65535-ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[4+res_offset].sprite_state&=	65535-ACTIVE; 
	       		}
		if (batch_info.number_of_cup_teams==8)
			{
		menu_data[MENU_A2].SpriteTABLE[2+res_offset].sprite_state|=	ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[1+res_offset].sprite_state&=	65535-ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[3+res_offset].sprite_state&=	65535-ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[4+res_offset].sprite_state&=	65535-ACTIVE; 
			}
		if (batch_info.number_of_cup_teams==16)
			{
		menu_data[MENU_A2].SpriteTABLE[3+res_offset].sprite_state|=	ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[1+res_offset].sprite_state&=	65535-ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[2+res_offset].sprite_state&=	65535-ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[4+res_offset].sprite_state&=	65535-ACTIVE; 
			}
		if (batch_info.number_of_cup_teams==32)
			{
		menu_data[MENU_A2].SpriteTABLE[4+res_offset].sprite_state|=	ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[1+res_offset].sprite_state&=	65535-ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[2+res_offset].sprite_state&=	65535-ACTIVE; 
		menu_data[MENU_A2].SpriteTABLE[3+res_offset].sprite_state&=	65535-ACTIVE; 
			}
	}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Setup_cup_teams(number_of_cup_teams)                                                                                        บ
//บ																 บ
//บ																 บ
//บ		Sets up best teams for cup competition depending on how many teams have been selected by user to participate.    บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Setup_cup_teams(int number_of_cup_teams)
{
int	team_num;
	
	if (restore_cup_data[0]!=-1)
		{
		for (int clr_no = 0; clr_no < MAX_TEAMS-1; clr_no++)
			{
			menu_data[MENU_A3].StringLIST[clr_no].string_flags&= 	65535-TOGGLE_FLAG;
			}
		for (int index_no = 0; index_no < number_of_cup_teams; index_no++)
			{
			team_num	=	restore_cup_data[index_no];
			if ( team_num != -1 )
				menu_data[MENU_A3].StringLIST[team_num].string_flags|= TOGGLE_FLAG;
			}				 	
		}
	else
		{
		for (int index_no = 0; index_no < MAX_TEAMS-1; index_no++)
			{
			menu_data[MENU_A3].StringLIST[index_no].string_flags&= 	65535-TOGGLE_FLAG;
			if	(game_data[index_no].ranking < number_of_cup_teams)
				menu_data[MENU_A3].StringLIST[index_no].string_flags|= 	TOGGLE_FLAG;
			}
		}
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  SubstitutePlayers( int team_no, int player1, int player2 )                                                                  บ
//บ																 บ
//บ																 บ
//บ		Substitutes two players.                                                                                         บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	SubstituePlayers( int team_no, int player1, int player2)
{
		int	temp_team;
		temp_team	=	selected_team;
		selected_team 	=	team_no;
		game_data[team_no].players[player1].flags&=	255-SUBSTITUTE;
		game_data[team_no].players[player2].flags&=	255-SUBSTITUTE;
		swap_players	( player1, player2 );
		selected_team	=	temp_team;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  swap_players(int player1,int player2)                                                                                       บ
//บ																 บ
//บ																 บ
//บ		Swaps positions for two given players from a given team.                                                         บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	swap_players(int player1,int player2)
{
	player_info	swap_buffer;
	memcpy(&swap_buffer,&game_data[selected_team].players[player1],sizeof(player_info));
	memcpy(&game_data[selected_team].players[player1],&game_data[selected_team].players[player2],sizeof(player_info));
	memcpy(&game_data[selected_team].players[player2],&swap_buffer,sizeof(player_info));
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Initialise_environment(int menu_number)                                                                                     บ
//บ																 บ
//บ																 บ
//บ		Initialises all enviroment variables.                                                                            บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Initialise_environment()
{
		match_info.sky_toggle		=	setup.detail.sky;
		match_info.stadium_toggle	=	setup.detail.stadia;
		match_info.line_toggle		=	setup.detail.lines;
		match_info.vidi_toggle		=	match_info.vidi;
		match_info.players_toggle	=	setup.detail.players;
		match_info.pitch_toggle		=	setup.detail.pitch;
		match_info.res_toggle		=	setup.start_res;
		match_info.camera_toggle	=	match_info.camera;
		match_info.size_toggle		=	setup.screen_size;
		match_info.audio_toggle		=	match_info.audio;
		match_info.timeit    		=	NULL;

	 	match_info.crowd		=	menu_data[MENU_A14].ButtonLIST[0].button_index*163;       
	 	match_info.commentary		=	menu_data[MENU_A14].ButtonLIST[1].button_index*163; 
	 	match_info.master		=	menu_data[MENU_A14].ButtonLIST[2].button_index*163;   
	 	match_info.pitch		=	menu_data[MENU_A14].ButtonLIST[3].button_index*163;
	 	match_info.music		=	menu_data[MENU_A14].ButtonLIST[4].button_index*163;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Setup_no_of_teams()                                                                              				 บ
//บ																 บ
//บ																 บ
//บ		Sets up flag indicating number of teams taking part in next competition.                                         บ
//บ																 บ
//บ																 บ
//บ			0	=	4 teams	  \										 บ
//บ			1	=	8 teams	   \ CUP COMPETITION								 บ
//บ			2	=      16 teams	   /										 บ
//บ			3	=      32 teams	  /										 บ
//บ			4	=      44 teams	  -> LEAGUE									 บ
//บ			5       =      friendly											 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Setup_no_of_teams()
{
	menu_data[MENU_A1].ButtonLIST[0].button_flags&=	65535-ACTIVE;

	if ( match_info.CompetitionType==FRIENDLY || match_info.CompetitionType==NETWORK || match_info.CompetitionType==PRACTICE )
		{
		menu_data[MENU_A8].ButtonLIST[1].button_flags|=	ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[2].button_flags|=	ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[3].button_flags|=	ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[4].button_flags|=	ACTIVE;	

//		if (match_info.menu_res==HI)
			{
			menu_data[MENU_A8].SpriteTABLE[3].sprite_xposn	=	(320-(sprite123width/2));	
			menu_data[MENU_A16].SpriteTABLE[3].sprite_xposn	=	(320-(sprite123width/2));	
			}
//		else
//			{
//			menu_data[MENU_A8].SpriteTABLE[3].sprite_xposn	=	(320-(sprite123width/2))-4;	
//		menu_data[MENU_A16].SpriteTABLE[3].sprite_xposn	=	(320-(sprite123width/2))-4;	
//			}
		

		menu_data[MENU_A8].SpriteTABLE[3].sprite_yposn	=	A08yOFF+32+52;
		menu_data[MENU_A16].SpriteTABLE[3].sprite_yposn	=	A08yOFF+32+52;
		NoOfTeamsFlag	=	5;


			if ( match_info.CompetitionType==FRIENDLY || match_info.CompetitionType==PRACTICE )
			{
				menu_data[MENU_A8].ButtonLIST[5].button_flags|=	ACTIVE;	
				menu_data[MENU_A8].ButtonLIST[6].button_flags|=	ACTIVE;	
			}
			else
			{
				menu_data[MENU_A8].ButtonLIST[5].button_flags&=	65535-ACTIVE;	
				menu_data[MENU_A8].ButtonLIST[6].button_flags&=	65535-ACTIVE;	
			}

		}
	if ( match_info.CompetitionType==LEAGUE )
		{
		menu_data[MENU_A8].ButtonLIST[1].button_flags&=	65535-ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[2].button_flags&=	65535-ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[3].button_flags&=	65535-ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[4].button_flags&=	65535-ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[5].button_flags|=	ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[6].button_flags|=	ACTIVE;	
		menu_data[MENU_A8].SpriteTABLE[3].sprite_xposn	=	(320-(sprite122width/2));	
		menu_data[MENU_A8].SpriteTABLE[3].sprite_yposn	=	A08yOFF+52;   
		menu_data[MENU_A16].SpriteTABLE[3].sprite_xposn	=	(320-(sprite122width/2));	
		menu_data[MENU_A16].SpriteTABLE[3].sprite_yposn	=	A08yOFF+52;   
		NoOfTeamsFlag	=	4;
		}


	if ( match_info.CompetitionType==CUP )
	{
		menu_data[MENU_A8].ButtonLIST[1].button_flags&=	65535-ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[2].button_flags&=	65535-ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[3].button_flags&=	65535-ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[4].button_flags&=	65535-ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[5].button_flags|=	ACTIVE;	
		menu_data[MENU_A8].ButtonLIST[6].button_flags|=	ACTIVE;	
		menu_data[MENU_A8].SpriteTABLE[3].sprite_xposn	=	(320-(sprite124width/2));	
		menu_data[MENU_A8].SpriteTABLE[3].sprite_yposn	=	A08yOFF+52;       
		menu_data[MENU_A16].SpriteTABLE[3].sprite_xposn	=	(320-(sprite124width/2));	
		menu_data[MENU_A16].SpriteTABLE[3].sprite_yposn	=	A08yOFF+52;       
		menu_data[MENU_A1].ButtonLIST[0].button_flags|=	ACTIVE;

		if ( batch_info.number_of_cup_teams==4 )
			NoOfTeamsFlag	=	0;
		if ( batch_info.number_of_cup_teams==8 )
			NoOfTeamsFlag	=	1;
		if ( batch_info.number_of_cup_teams==16 )
			NoOfTeamsFlag	=	2;
		if ( batch_info.number_of_cup_teams==32 )
			NoOfTeamsFlag	=	3;
	}		
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Setup_possible_choice_teams()                                                                      		         บ
//บ																 บ
//บ																 บ
//บ		Sets up flags, allowing user to select their chosen team                                                         บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Setup_possible_choice_teams()
{
	if (NoOfTeamsFlag!=5)
	{
		int	choiceset	=	0;

		for (int choicenum = 0; choicenum < MAX_TEAMS-1; choicenum++)
		{

		menu_data[MENU_A15].SpriteTABLE[choicenum].sprite_state&=	65535-ACTIVE;																
		menu_data[MENU_A15].StringLIST[choicenum].string_type	=	NULL;

			if ( (menu_data[MENU_A3].StringLIST[choicenum].string_flags & TOGGLE_FLAG)!=0 ||
			      match_info.CompetitionType==LEAGUE )

			{
				menu_data[MENU_A15].StringLIST[choiceset].string_shadow =       choose_data[NoOfTeamsFlag].choose[choiceset].str_flags;	
				menu_data[MENU_A15].StringLIST[choiceset].string_array	=	choicenum;																
				menu_data[MENU_A15].StringLIST[choiceset].string_type	=	choose_data[NoOfTeamsFlag].choose[choiceset].type;																
				menu_data[MENU_A15].StringLIST[choiceset].string_xposn	=	choose_data[NoOfTeamsFlag].choose[choiceset].xposn;																
				menu_data[MENU_A15].StringLIST[choiceset].string_yposn	=	choose_data[NoOfTeamsFlag].choose[choiceset].yposn;																
				menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_state|=	ACTIVE;																
				menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_flags =       choose_data[NoOfTeamsFlag].choose[choiceset].spr_flags;	
				menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_xposn =       choose_data[NoOfTeamsFlag].choose[choiceset].spr_xposn;	
				menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_yposn =       choose_data[NoOfTeamsFlag].choose[choiceset].spr_yposn;	

				menu_data[MENU_A15].StringLIST[choiceset].BoundingBoxLeft   =     choose_data[NoOfTeamsFlag].choose[choiceset].BoundingBoxLeft;	
				menu_data[MENU_A15].StringLIST[choiceset].BoundingBoxTop    =     choose_data[NoOfTeamsFlag].choose[choiceset].BoundingBoxTop;	
				menu_data[MENU_A15].StringLIST[choiceset].BoundingBoxRight  =     choose_data[NoOfTeamsFlag].choose[choiceset].BoundingBoxRight;	
				menu_data[MENU_A15].StringLIST[choiceset].BoundingBoxBottom =     choose_data[NoOfTeamsFlag].choose[choiceset].BoundingBoxBottom;	

				menu_data[MENU_A15].StringLIST[choiceset].CopyAreaX   =     choose_data[NoOfTeamsFlag].choose[choiceset].CopyAreaX;	
				menu_data[MENU_A15].StringLIST[choiceset].CopyAreaY   =     choose_data[NoOfTeamsFlag].choose[choiceset].CopyAreaY;	
				menu_data[MENU_A15].StringLIST[choiceset].CopyWidth   =     choose_data[NoOfTeamsFlag].choose[choiceset].CopyWidth;	
				menu_data[MENU_A15].StringLIST[choiceset].CopyHeight  =     choose_data[NoOfTeamsFlag].choose[choiceset].CopyHeight;	

				int	offset	=	0;
				
				if ( (game_data[choicenum].player_control & PLAYER1)!=0 )
				{
					menu_images[IMG57].ImageXposn	=	menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_xposn + choose_data[NoOfTeamsFlag].offsets[offset].x_off;	
					menu_images[IMG57].ImageYposn	=	menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_yposn + choose_data[NoOfTeamsFlag].offsets[offset].y_off;	
					menu_data[MENU_A15].ImageLIST[1]=	IMG58;
					offset++;
				}

			      	if ( (game_data[choicenum].player_control & PLAYER2)!=0 )
				{
					menu_images[IMG58].ImageXposn	=	menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_xposn + choose_data[NoOfTeamsFlag].offsets[offset].x_off;	
					menu_images[IMG58].ImageYposn	=	menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_yposn + choose_data[NoOfTeamsFlag].offsets[offset].y_off;
					menu_data[MENU_A15].ImageLIST[2]=	IMG59;
					offset++;
				}

				if ( (game_data[choicenum].player_control & PLAYER3)!=0 )
				{
					menu_images[IMG59].ImageXposn	=	menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_xposn + choose_data[NoOfTeamsFlag].offsets[offset].x_off;;	
					menu_images[IMG59].ImageYposn	=	menu_data[MENU_A15].SpriteTABLE[choiceset].sprite_yposn + choose_data[NoOfTeamsFlag].offsets[offset].y_off;;	
					menu_data[MENU_A15].ImageLIST[3]=	IMG60;
					offset++;
				}

		 	choiceset++;
			}
		}

	}

//	menu_data[MENU_A15].LabelLIST[0]	=	LAB61+PlayerCount;
}

void	reset_net_variables()
{
	NetworkType				=	NULL;
	NetworkType_toggle			=	NetworkType;
	MarkSquadPlayer	   			=	255;
					
	for (int stringnum = 0; stringnum < 22; stringnum++)
		{
		menu_data[MENU_A18].StringLIST[stringnum].string_flags &= 65535-NET_FLAG;
		}
}

void	ColourPOSN( int menu_number, int team )
{

}


