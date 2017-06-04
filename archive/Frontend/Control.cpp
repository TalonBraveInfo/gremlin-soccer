#include "Frontend Vars.h"
#include "Control.h"

#undef EXTERN
#define EXTERN extern
#include "Audio.h"
#include "Blitter.h"
#include "Front Menu.h"
#include "Front Variables.h"
#include "Intronet.h"
#include "Memory.h"
#include "Menudisp.h"
#include "Mouse.h"
#include "Not Written Yet.h"
#include "Palette.h"
#include "Results.h"
#include "Slot.h"
#include "Sprite.h"
#include "Sprocket Input.h"
#include "The Frontend.h"
#include "Use DrawSprockets.h"

#if USERAVEENGINE==YES
#include "RAGE Starter Code.h"
#endif

extern char PC_speed;

buff_info mbuff = {NULL, 640, 400, 640, 400, 1, 1, NULL};

int	ESCkey[]={
	 		-1,    		// QUIT_BUTTON,  		// 0
		GOTO_START,		// 1	
		GOTO_START,		// 2
		GOTO_START,		// 3
		GOTO_START,		// 4
		GOTO_START,		// 5
		QUIT_CNTRL,		// 6
		GOTO_START,		// 7
		GOTO_START,		// 8
		GOTO_START,		// 9
		GOTO_START,		// 10
		GOTO_START,		// 11
		GOTO_START,		// 12
		GOTO_START,		// 13
		GOTO_START,		// 14
		GOTO_START,		// 15
		GOTO_START,		// 16
		GOTO_START,		// 17
 			-1,		// 18
		GOTO_START,		// 19
		GOTO_START,		// 20
		GOTO_START,		// 21
		GOTO_START,		// 22
		GOTO_START,		// 23
		GOTO_START,		// 24
		QUIT_BUTTON,		// 25
		GOTO_START,		// 26
		GOTO_START,		// 27
		GOTO_START,		// 28
		GOTO_START,		//
		GOTO_START,		//
		GOTO_START,		//
		GOTO_START,		//
		};

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_button control(int menu_number)                                                                                          บ
//บ																 บ
//บ																 บ
//บ		Checks to see if user has clicked on a menu button and performs correct procedure if a button has been pressed.  บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Do_button_control(int menu_number)
{
menu *thisMenu = &menu_data[menu_number];

	//***********************************************************************************************************

		if (match_info.CompetitionType==CUP && PaletteFlag==1		 	 // slight fudge, used to stop overlaying of
		    && OverlayFlag!=NULL && batch_info.match_number!=-1)		 // sprites, DO NOT REMOVE....
		{								 
		 	setup.team_a					=	batch_info.cup_team_a;
			setup.team_b					=	batch_info.cup_team_b;
			menu_data[MENU_A8].SpriteTABLE[3].LastSpriteNo	=	NULL;
			menu_data[MENU_A8].SpriteTABLE[2].LastSpriteNo	=	NULL;
			menu_data[MENU_A8].SpriteTABLE[1].LastSpriteNo	=	NULL;
			menu_data[MENU_A8].SpriteTABLE[0].LastSpriteNo	=	NULL;
		  	menu_update					= 	UPDATE_DISPLAY;
			OverlayFlag					=	NULL;
		}
	
	//***********************************************************************************************************

		if (match_info.CompetitionType==NETWORK &&
		    Team_A!=-1 &&
		    Team_B!=-1 &&
		    menu_number==MENU_A8 &&
		    new_menu==MENU_A8
					)

		{
			I_Chose_Teams			=	NO;
			new_menu			= 	MENU_A18;
			PaletteFlag 			= 	PALETTE_FADE_DOWN;
			menu_data[MENU_A8].ButtonLIST[0].button_flags|= START_SPIN;
			MarkSquadPlayer 		=	255;
			setup.team_a			=	Team_A;
			setup.team_b			=	Team_B;
			setup.team_b_kit		=	team_b_kit[ ((setup.team_a*MAX_TEAMS)+setup.team_b) ];
			match_info.venue		=	setup.team_a;
			menu_images[67].ImageNumber	=	(setup.team_a)+USA_KIT_IMAGE;
			menu_images[66].ImageNumber	=	(setup.team_b_kit)+USA_KIT_IMAGE;
			SortSQUAD(setup.team_a);
			SortSQUAD(setup.team_b);
			TickerPause();
		}

	//***********************************************************************************************************




	if (PaletteFlag==NULL)
	{

//		ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//		บ                                                                           บ
//		บ  Scans through button data to see if user has clicked on a legal button.  บ
//		บ									    บ
//		ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 



	for (int buttonnum = 0; buttonnum < MAX_BUTTONS && MouseBUTTONS; buttonnum++)
		{
	     if ( thisMenu->ButtonLIST[buttonnum].button_type!=NULL 
		     && (thisMenu->ButtonLIST[buttonnum].button_flags & ACTIVE)!=0
		      && (MouseFlags & MOUSE_OFF)==0)
			{
			if ( ClickXposn > thisMenu->ButtonLIST[buttonnum].BoundingBoxLeft
				&& ClickXposn < thisMenu->ButtonLIST[buttonnum].BoundingBoxRight
		       	 && ClickYposn > thisMenu->ButtonLIST[buttonnum].BoundingBoxTop
			      && ClickYposn < thisMenu->ButtonLIST[buttonnum].BoundingBoxBottom
		       	   && Button_pressed==NULL)
				{
				if ( (thisMenu->ButtonLIST[buttonnum].button_flags & HALF_SPIN)==0
				    && (thisMenu->ButtonLIST[buttonnum].button_flags & START_SPIN)==0)
					{
					if ( MouseBUTTONS == LEFT_BUTTON)
						{
						Button_pressed	=	thisMenu->ButtonLIST[buttonnum].button_left_select;
						spin_button	=	buttonnum;
						break;
						}
//					if ( MouseBUTTONS == RIGHT_BUTTON)
//						{
//						Button_pressed	=	thisMenu->ButtonLIST[buttonnum].button_right_select;
//						spin_button	=	buttonnum;
//						}
					}
				}
			}
		}

//	if (  ( (!CheckMusic())  && new_menu==MENU_A0 && SoundCard!=0 && GDVavailable!=NULL ) ||

	if ( ( new_menu==MENU_A0 && !GDVtimer))
		{
		GDVtimer		--;
		PaletteFlag 	= 	PALETTE_FADE_DOWN;
		Button_pressed	=	NULL;
		OverFlowFlag 	= 	FALSE;

		batch_info.DEMOflag++;
		batch_info.DEMOflag&=	128+7;	// 7 levels of demo mode.
					
	 	if ( !(batch_info.DEMOflag & 1))
			{
//			if ( GDVavailable!=NULL && 1 && (match_info.language==English || match_info.language==French || match_info.language==Norwegian) )
//				{
//				new_menu = 	PLAY_GDV;
//				batch_info.DEMOflag&=	7;
//				}
//			else
				{
				batch_info.DEMOflag++;
				batch_info.DEMOflag&=	128+7;	// 7 levels of demo mode.
				}
			}			
		if ( (batch_info.DEMOflag & 1))
			{
			MouseFlags |= MOUSE_OFF;
			new_menu = 	MENU_A23;	//PLAY_MATCH;
			batch_info.DEMOflag |= 128;
			}
		}

	if ( (Button_pressed==DEBOUNCE_BUTTONS && MouseBUTTONS==NULL) || OverFlowFlag==TRUE )
		{
		Button_pressed	=	NULL;
		OverFlowFlag 	= 	FALSE;
		}


	if ( MouseBUTTONS == NULL )
		Button_pressed	=	NULL;

//		ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//		บ                                                                            บ
//		บ  Now perform correct procedure depending on which button has been pressed. บ
//		บ									     บ
//		ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

		check_for_tga();

//		if (match_info.CompetitionType==NETWORK && Team_A!=-1 && Team_B!=-1 && menu_number==MENU_A8)
//		{
//			I_Chose_Teams			=	NO;
//			new_menu			= 	MENU_A18;
//			PaletteFlag 			= 	PALETTE_FADE_DOWN;
//			menu_data[MENU_A8].ButtonLIST[0].button_flags|= START_SPIN;
//			MarkSquadPlayer 		=	255;
//			setup.team_a			=	Team_A;
//			setup.team_b			=	Team_B;
//			setup.team_b_kit		=	team_b_kit[ ((setup.team_a*MAX_TEAMS)+setup.team_b) ];
//			menu_images[67].ImageNumber	=	(setup.team_a)+USA_KIT_IMAGE;
//			menu_images[66].ImageNumber	=	(setup.team_b_kit)+USA_KIT_IMAGE;
//			SortSQUAD(setup.team_a);
//			SortSQUAD(setup.team_b);
//			TickerPause();
//		}
//



		if ( match_info.CompetitionType==NETWORK && Endnetwork==ON )
		{
int i;

			Starts	=	0;

			for ( i=0; i < network_on; i++ )
			{
				if (NetTeams[i] >= 2) Starts++;
			}


			if	(Starts==network_on && network_on>1)			
			{

				SendNetOKAY();
				while (( NETseed=Polling_Network())<0 ) ;  // (Add escape key?)
				netsetup_on=FALSE;

				// Remove start flags from team data

				for ( i=0; i<network_on; i++ )
					NetTeams[i]-=2;

 			MouseFlags|=	MOUSE_OFF;
 			new_menu	= MENU_A23;	//PLAY_MATCH;
			PaletteFlag 	= PALETTE_FADE_DOWN;
			}


		}			
		
		if( Button_pressed == NULL)
			return;
		
		if (Button_pressed==MOVE_SLIDE_BAR)
			{

		int	butnum	=	0;
	 
 			int	NewSlideValue	=	ClickXposn-(thisMenu->ButtonLIST[spin_button].button_xposn);

			if ( NewSlideValue < SLIDE_BAR_XOFF )
				NewSlideValue	=	SLIDE_BAR_XOFF;
			if ( NewSlideValue > 200+SLIDE_BAR_XOFF )
				NewSlideValue	=	200+SLIDE_BAR_XOFF;
			thisMenu->ButtonLIST[spin_button].button_index	=	NewSlideValue-SLIDE_BAR_XOFF;
		       	thisMenu->ButtonLIST[spin_button].LastButtonNo	=	NULL;
			Button_pressed		=	NULL; 		
			}

		else if (Button_pressed == TEAM_4_SELECTED || Button_pressed == TEAM_8_SELECTED || Button_pressed == TEAM_16_SELECTED || Button_pressed == TEAM_32_SELECTED)
	     	{
	        for (int index_no = 0; index_no < 33; index_no++)
	  			restore_cup_data[index_no]	=	-1;

			if (Button_pressed==TEAM_4_SELECTED)
				batch_info.number_of_cup_teams	=	4;
			else if (Button_pressed==TEAM_8_SELECTED)
				batch_info.number_of_cup_teams	=	8;
			else if (Button_pressed==TEAM_16_SELECTED)
				batch_info.number_of_cup_teams	=	16;
			else
				batch_info.number_of_cup_teams	=	32;
	
			Button_pressed	=	NULL; 		
			Setup_cup_teams(batch_info.number_of_cup_teams);
     		MouseDeBOUNCE	= 	TRUE;

			}
			
/*
		else if (Button_pressed==INCREASE_SELECTED_PLAYER)
			{
			if (--selected_player<0)
				selected_player = 21;
			menu_update	= UPDATE_DISPLAY;
		    MouseDeBOUNCE 	= TRUE;
			}
*/

		else if (Button_pressed==DECREASE_SELECTED_PLAYER)
			{
			if (++selected_player==22)
				selected_player = 0;
			menu_update	= UPDATE_DISPLAY;
     		MouseDeBOUNCE 	= TRUE;
			}

		else if (Button_pressed==INCREASE_SELECTED_TEAM)
		{
			if (selected_team < ((MAX_TEAMS-2)) )						
			{
				selected_team++;				
				menu_update	= 	UPDATE_DISPLAY;
			     	MouseDeBOUNCE 	= 	TRUE;
			}
			else
				selected_team	=	0;
				menu_update	= 	UPDATE_DISPLAY;
			     	MouseDeBOUNCE 	= 	TRUE;
		}

		else if (Button_pressed==DECREASE_SELECTED_TEAM)
		{
			if (selected_team>0)						
			{
				selected_team--;				
				menu_update	= 	UPDATE_DISPLAY;
			     	MouseDeBOUNCE 	= 	TRUE;
			}
			else
				selected_team	=	(MAX_TEAMS-2);				
				menu_update	= 	UPDATE_DISPLAY;
			     	MouseDeBOUNCE 	= 	TRUE;
		}


		else if (Button_pressed==INCREASE_SELECTED_REFEREE)
		{
			if (match_info.referee< (16+16) )						
			{
				match_info.referee++;				
				menu_update	= UPDATE_DISPLAY;
		     		MouseDeBOUNCE 	= TRUE;
			}
			else
				match_info.referee = 0;
				menu_update	= UPDATE_DISPLAY;
		     		MouseDeBOUNCE 	= TRUE;
		}

		else if (Button_pressed==DECREASE_SELECTED_REFEREE)
		{
			if (match_info.referee >= 1)						
			{
				match_info.referee--;				
				menu_update	= UPDATE_DISPLAY;
		     		MouseDeBOUNCE 	= TRUE;
			}
			else
				match_info.referee     	= (16+16);				
				menu_update		= UPDATE_DISPLAY;
		     		MouseDeBOUNCE 		= TRUE;
		}

		else if (Button_pressed==INCREASE_TEAMa || Button_pressed==INCREASE_TEAMb ||
				Button_pressed==DECREASE_TEAMa || Button_pressed==DECREASE_TEAMb )
			{
int TempCTRL1 = game_data[setup.team_a].player_control; 
int TempCTRL2 = game_data[setup.team_b].player_control; 

			compute_a = TRUE;
			compute_b = TRUE;
			game_data[setup.team_a].player_control = NULL;
			game_data[setup.team_b].player_control = NULL;

			if( Button_pressed==INCREASE_TEAMa)
				{
int new_team = setup.team_a+1;

				if ( new_team > ((MAX_TEAMS-2)))
					new_team -= ((MAX_TEAMS-1));						
				if 	(new_team == setup.team_b)
					new_team += 1;
				if ( new_team > ((MAX_TEAMS-2)))
					new_team -= ((MAX_TEAMS-1));						
      
				setup.team_a = new_team;
   				menu_update = UPDATE_DISPLAY;
				}	
	
			else if( Button_pressed==DECREASE_TEAMa)
				{
int new_team = setup.team_a-1;

				if ( new_team < 0)
					new_team += ((MAX_TEAMS-1));						
				if 	(new_team==setup.team_b)
					new_team--;
				if ( new_team < 0)
					new_team += ((MAX_TEAMS-1));						
				setup.team_a = new_team;
      			menu_update = UPDATE_DISPLAY;
				}
	
			else if( Button_pressed==INCREASE_TEAMb)
				{
int new_team = setup.team_b+1;

				if ( new_team > ((MAX_TEAMS-2)))
					new_team -= ((MAX_TEAMS-1));						
				if 	(new_team == setup.team_a)
					new_team++;
				if ( new_team > ((MAX_TEAMS-2)))
					new_team -= ((MAX_TEAMS-1));						
      
				setup.team_b = new_team;
   				menu_update = UPDATE_DISPLAY;
				}
	
			else if( Button_pressed==DECREASE_TEAMb)
				{
int new_team = setup.team_b-1;

				if ( new_team < 0)
					new_team += ((MAX_TEAMS-1));						
				if 	(new_team==setup.team_a)
					new_team --;
				if ( new_team < 0)
					new_team += ((MAX_TEAMS-1));						

				setup.team_b = new_team;
   				menu_update = UPDATE_DISPLAY;
				}

			game_data[setup.team_a].player_control	=	TempCTRL1; 
			game_data[setup.team_b].player_control	=	TempCTRL2; 
			menu_data[MENU_A8].SpriteTABLE[3].LastSpriteNo	=	NULL;
			menu_data[MENU_A8].SpriteTABLE[2].LastSpriteNo	=	NULL;
			menu_data[MENU_A8].SpriteTABLE[1].LastSpriteNo	=	NULL;
			menu_data[MENU_A8].SpriteTABLE[0].LastSpriteNo	=	NULL;
			MouseDeBOUNCE 					= 	TRUE;

			match_info.venue	=	setup.team_a;
			}



#ifdef TWOBUTTONS
		else if ( Button_pressed==FRWD_SKY_DETAIL || Button_pressed==BACK_SKY_DETAIL )
			{
			match_info.sky_toggle^=	ON;
			MouseDeBOUNCE 		=	TRUE;
			if (Button_pressed==FRWD_SKY_DETAIL )
				{
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
				thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
				}
			else	
	   			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#else
		else if ( Button_pressed==FRWD_SKY_DETAIL)
			{
			match_info.sky_toggle^=	ON;
			MouseDeBOUNCE 		=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			}
#endif

#ifdef TWOBUTTONS
		else if ( Button_pressed==FRWD_STADIUM_DETAIL || Button_pressed==BACK_STADIUM_DETAIL)
			{
			match_info.stadium_toggle^=	ON;
	  		MouseDeBOUNCE 		=	TRUE;

			if (Button_pressed==FRWD_STADIUM_DETAIL )
				{
	   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
    			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
				}
			else	
	   			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
		}
#else
		else if ( Button_pressed==FRWD_STADIUM_DETAIL)
			{
			match_info.stadium_toggle^=	ON;
	   		MouseDeBOUNCE 		=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			}
#endif

#ifdef TWOBUTTONS
		else if ( Button_pressed==FRWD_LINE_DETAIL || Button_pressed==BACK_LINE_DETAIL)
			{
			match_info.line_toggle ^= ON;
	   		MouseDeBOUNCE = TRUE;
			if (Button_pressed==FRWD_LINE_DETAIL )
				{
	   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
    			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
				}
			else	
				thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#else
		else if ( Button_pressed==FRWD_LINE_DETAIL)
			{
			match_info.line_toggle^=	ON;
	     	MouseDeBOUNCE 		=	TRUE;
			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			}
#endif

#ifdef TWOBUTTONS
		else if ( Button_pressed==FRWD_VIDI_WALL || Button_pressed==BACK_VIDI_WALL )
			{
			match_info.vidi_toggle^=	ON;
     		MouseDeBOUNCE 		=	TRUE;

			if (Button_pressed==FRWD_VIDI_WALL )
				{
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
				thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
				}
			else	
       			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#else
		else if ( Button_pressed==FRWD_VIDI_WALL )
			{
#if USERAVEENGINE==YES
			if( UseRaveEngine)
#endif
				{
				match_info.vidi_toggle^=	ON;
		   		MouseDeBOUNCE 		=	TRUE;
   				thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
				}
			}
#endif

#ifdef TWOBUTTONS
		else if ( Button_pressed==FRWD_PLAYERS_DETAIL || Button_pressed==BACK_PLAYERS_DETAIL )
			{
			match_info.players_toggle^=	ON;
     		MouseDeBOUNCE 		=	TRUE;

			if (Button_pressed==FRWD_PLAYERS_DETAIL )
				{
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
				thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
				}
			else	
       			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#else
		else if ( Button_pressed==FRWD_PLAYERS_DETAIL)
			{
			match_info.players_toggle^=	ON;
	   		MouseDeBOUNCE 		=	TRUE;
			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			}
#endif
		else if ( Button_pressed==FRWD_PITCH_DETAIL )
			{
			++match_info.pitch_toggle;
			if ( ++match_info.pitch_toggle > 2)
				match_info.pitch_toggle	=	NULL;
	     	MouseDeBOUNCE 	=	TRUE;
      		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			}

#ifdef TWOBUTTONS
		else if ( Button_pressed==BACK_PITCH_DETAIL )
			{
			if ( --match_info.pitch_toggle < 0)
				match_info.pitch_toggle	=	2;
     		MouseDeBOUNCE 	=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#endif

		else if ( Button_pressed==FRWD_RES) // || Button_pressed==BACK_RES )
			{
#if USERAVEENGINE==YES
			if( UseRaveEngine)
#endif
				{
				match_info.res_toggle^=	ON;
	     		MouseDeBOUNCE 		=	TRUE;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
				}
			}

		else if ( Button_pressed==FRWD_CAMERA )
			{
			if ( ++match_info.camera_toggle > 6)
				match_info.camera_toggle	=	NULL;
     		MouseDeBOUNCE 	=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags |= START_SPIN;
			}

#ifdef TWOBUTTONS
		else if ( Button_pressed==BACK_CAMERA )
			{
			if ( --match_info.camera_toggle < 0)
				match_info.camera_toggle	=	6;

	     		MouseDeBOUNCE 	=	TRUE;
       			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#endif

#ifdef TWOBUTTONS
		else if ( Button_pressed==BACK_SIZE )
			{
			if ( --match_info.size_toggle < 0)
				match_info.size_toggle	=	(11-3) ;
     		MouseDeBOUNCE 	=	TRUE;
       		thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#endif

		if ( Button_pressed==FRWD_SIZE )
			{
#if USERAVEENGINE==YES
			if( UseRaveEngine)
#endif
				{
				if ( ++match_info.size_toggle > (11-3) )
					match_info.size_toggle	=	NULL;
				MouseDeBOUNCE 	=	TRUE;
   				thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
				}
			}

#ifdef TWOBUTTONS
		if ( Button_pressed==FRWD_AUDIO && SoundCard!=0 )
			{
			if ( --match_info.audio_toggle < 0)
				match_info.audio_toggle	=	2;
     		MouseDeBOUNCE 	=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#endif

		if ( Button_pressed==BACK_AUDIO && SoundCard )
			{
			if ( ++match_info.audio_toggle > 2)
				match_info.audio_toggle	=	NULL;
     		MouseDeBOUNCE 	=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			}

		if ( Button_pressed==FRWD_NoOfPLAYERS )
			{
			if (match_info.CompetitionType!=NETWORK)
				{
				match_info.NoOfPlayers_toggle++;
#if FOURPLAYERS
				match_info.NoOfPlayers_toggle&=	3;
#else
				match_info.NoOfPlayers_toggle&=	1;
#endif
				}
			else
				{
				batch_info.Port_toggle++;
				batch_info.Port_toggle&= 1;		// 7;
				}
     		MouseDeBOUNCE 	=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
//			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
			}

/*
		if ( Button_pressed==BACK_NoOfPLAYERS )
			{
			if (match_info.CompetitionType!=NETWORK)
				{
				match_info.NoOfPlayers_toggle--;
				match_info.NoOfPlayers_toggle&=	3;
	    		MouseDeBOUNCE 	=	TRUE;
	    		thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
				}
			else			
				{
				batch_info.Port_toggle--;
				batch_info.Port_toggle&= 7;
	   			MouseDeBOUNCE 	=	TRUE;
	   			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
				}
			}
*/

		if ( Button_pressed==FRWD_GameType) //  || Button_pressed==BACK_GameType )
			{
			match_info.GameType_toggle^=	1;
	   		MouseDeBOUNCE 	=	TRUE;
//			if ( Button_pressed==FRWD_GameType )
//				{
      			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
//				thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
//				}
//			else
//    			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}

		if ( Button_pressed==FRWD_NETWORK || (RetestNet==TRUE && net_cd_in==TRUE) )
			{
			if (net_cd_in==TRUE)
				{
				if ( NetworkType_toggle == 0)
					{
					NetworkType_toggle++;
     				MouseDeBOUNCE 	=	TRUE;
	      			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
//					thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
					Endnetwork	=	ON;
					Button_pressed	=	NULL;
					}
				if	(TeamChoice < 2)
					{
					TeamChoice+=2;
					SendPlayerChoice();
					TickerPause();
					}
				}
			else
				{
				TextCOLOUR	=	175;
				TextXposn	=	320;
				TextYposn	=	4;
				CopyXposn	=	TextXposn-128-48;
				CopyYposn	=	TextYposn;
				CopyHEIGHT	=	20;
				CopyWIDTH	=	256+96;
				RestorePSUDObuffer();
				DisplaySTRING( GetSTRING( CD_TEXT,0 ), SHADOWtextON|SFONT|CENTREjustifyTEXT );
				Add_to_copy_list( CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
				RetestNet	=	TRUE; 			
				cd_in	=	CDPresent();
				if (cd_in!=0)
					SendNETTeamInfo();	
				}
			}

		if ( Button_pressed==FRWD_COMPETITION && batch_info.rolling_demo==OFF)
			{
			match_info.CompetitionType_toggle++;
			if ( match_info.CompetitionType_toggle > Competition_limit)
				match_info.CompetitionType_toggle	=	NULL;
     		MouseDeBOUNCE 	=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
//			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;

			if ( (match_info.CompetitionType_toggle==NETWORK || match_info.CompetitionType_toggle==NULL) && Competition_limit==NETWORK)
				{
      			menu_data[MENU_A0].ButtonLIST[2].button_flags|= START_SPIN;
//				menu_data[MENU_A0].ButtonLIST[2].button_flags&= 65535-BACK_SPIN;
				}			
			}

/*
		if ( Button_pressed==FRWD_COMPETITION && batch_info.rolling_demo!=OFF && Competition_limit==NETWORK)
			{
			match_info.CompetitionType_toggle^=NETWORK;
			if ( match_info.CompetitionType_toggle > Competition_limit)
				match_info.CompetitionType_toggle	=	NULL;
	     		MouseDeBOUNCE 	=	TRUE;
      			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
			if ( (match_info.CompetitionType_toggle==NETWORK || match_info.CompetitionType_toggle==NULL) &&
				Competition_limit==NETWORK)
				{
    			menu_data[MENU_A0].ButtonLIST[2].button_flags|= START_SPIN;
				menu_data[MENU_A0].ButtonLIST[2].button_flags&= 65535-BACK_SPIN;
				}			
			}
*/

/*
		if ( Button_pressed==BACK_COMPETITION)
			{
			match_info.CompetitionType_toggle--;
			if ( match_info.CompetitionType_toggle < 0)
				match_info.CompetitionType_toggle	= Competition_limit;
	     		MouseDeBOUNCE 	=	TRUE;
       			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);

			if ( (match_info.CompetitionType_toggle==NETWORK || match_info.CompetitionType_toggle==(NETWORK-1)) &&
				Competition_limit==NETWORK)
				{
      			menu_data[MENU_A0].ButtonLIST[2].button_flags|= START_SPIN;
				menu_data[MENU_A0].ButtonLIST[2].button_flags&= 65535-BACK_SPIN;
				}			
			}

		if ( Button_pressed==BACK_COMPETITION && batch_info.rolling_demo!=OFF && Competition_limit==NETWORK )
			{
			match_info.CompetitionType_toggle^=NETWORK;
			if ( match_info.CompetitionType_toggle < 0)
				match_info.CompetitionType_toggle	=	Competition_limit;
	     		MouseDeBOUNCE 	=	TRUE;
       			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			if ( (match_info.CompetitionType_toggle==NETWORK || match_info.CompetitionType_toggle==0) &&
				Competition_limit==NETWORK)
				{
   				menu_data[MENU_A0].ButtonLIST[2].button_flags|= START_SPIN;
				menu_data[MENU_A0].ButtonLIST[2].button_flags&= 65535-BACK_SPIN;
				}			
			}
*/

		if (Button_pressed==DECREASE_SELECTED_FORMATION)
			{
//			formation_toggle++;
			if ( ++formation_toggle == MAX_FORMATIONS) formation_toggle=0;	 //SJL
			menu_update	= UPDATE_DISPLAY;
	     	MouseDeBOUNCE 	= TRUE;
	       	thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
//	       	thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
			}

	
#ifdef TWOBUTTONS
		if (Button_pressed==INCREASE_SELECTED_FORMATION)
			{
//			formation_toggle--;
			if ( --formation_toggle<0) formation_toggle=MAX_FORMATIONS-1; //SJL
			menu_update	= UPDATE_DISPLAY;
		    MouseDeBOUNCE 	= TRUE;
       		thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#endif

		if (Button_pressed==GOTO_SAVE)
			{
#if ROLLING_DEMO == OFF
			GDVtimer	= DEMO_TIME;
			new_menu	= MENU_A0;
			PaletteFlag 	= PALETTE_FADE_DOWN;
	     		MouseDeBOUNCE 	= TRUE;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			write_data_to_slot(SlotNumber);
			new_menu	= last_menu;	    		/// *****    ?? Added this     *****
#endif
			}

		if (Button_pressed==GOTO_LOAD)
			{		
#if ROLLING_DEMO == OFF
			GDVtimer	= DEMO_TIME;
			new_menu	= MENU_A0;
			PaletteFlag 	= PALETTE_FADE_DOWN;
     		MouseDeBOUNCE 	= TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			load_data_from_slot(SlotNumber);
#endif
			}		 	

		if (Button_pressed==PARTICIPATING_DONE)
			{
			int	table_posn;
			table_posn	=	0;

			for (int team_num = 0; team_num < MAX_TEAMS; team_num++)
				{
				if ( (menu_data[MENU_A3].StringLIST[team_num].string_flags & TOGGLE_FLAG)!=0)
					{
					restore_cup_data[table_posn]	=	team_num;
					table_posn++;
					}
				}				 	
			Button_pressed	=	GOTO_MENU_A0;
			}

#if 0
		if (Button_pressed==QUIT_CNTRL)
			{
		 	if (calibrate_flag==255 && redefine_flag==255)
				Button_pressed	=	GOTO_START;
			else
				{
		 		for (int trn=0; trn<6; trn++)
					{
					if ( (match_info.control_methods[MarkControlType-1]) == KEYBOARD)
						batch_info.keys_used[trn]	=	copykeys[trn];
#if TWOKEY==YES
					if ( (match_info.control_methods[MarkControlType-1]) == KEYBOARD2)
						batch_info.keys_used[trn+6]	=	copykeys[trn];
#endif
					}
				
				CopyXposn		=	redefine_data[0].string_xposn-130;
				CopyYposn		=	redefine_data[0].string_yposn-40;
				CopyHEIGHT		=	110;
				CopyWIDTH		=	588;
		 		RestorePSUDObuffer();
		 		Add_to_copy_list( CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
				calibrate_flag		=	255;
				redefine_flag		=	255;
				MouseFlags&=	65535-MOUSE_OFF;
				menu_data[MENU_A6].StringLIST[MarkControlType-1].string_flags|=		HIGHLIGHTED_TEXT;	
				menu_data[MENU_A6].StringLIST[MarkControlType-1].string_flags&=		65535-HOVERING_OVER_TEXT;
				MarkControlType		=	0;
				Button_pressed		=	NULL;		 
				}
    		MouseDeBOUNCE 	= TRUE;
			}
#endif





		if (Button_pressed==GOTO_MENU_A0 || Button_pressed==GOTO_START)
		{		
			if (Button_pressed==GOTO_MENU_A0)
	       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;

			GDVtimer	= DEMO_TIME;
			new_menu	= MENU_A0;
			PaletteFlag 	= PALETTE_FADE_DOWN;
	     		MouseDeBOUNCE 	= TRUE;
			MouseFlags&=	65535-MOUSE_OFF;
			reset_scores();
			reset_net_variables();
			reset_league_teams(); 
			Setup_cup_teams(batch_info.number_of_cup_teams);

				InitialiseMan	=	GRM;
				InitialiseFlag	=	0;
		
		}		 	


		if (Button_pressed==DONE_LOAD || Button_pressed==DONE_CNTRL)
			{		
			new_menu	= last_menu;
			PaletteFlag 	= PALETTE_FADE_DOWN;
     		MouseDeBOUNCE 	= TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			}		 	


		if (Button_pressed==GOTO_MENU_A1)
		{
			new_menu = MENU_A1;
			PaletteFlag 	= PALETTE_FADE_DOWN;
   			thisMenu->ButtonLIST[spin_button].button_flags |= START_SPIN;
		}
//#if ROLLING_DEMO!=OFF
//		if (Button_pressed==GOTO_MENU_A24)
//			new_menu	= MENU_A24;
//		if (Button_pressed==GOTO_MENU_A25)
//			new_menu	= MENU_A25;
//		if (Button_pressed==GOTO_MENU_A24 || Button_pressed==GOTO_MENU_A25 || Button_pressed==GOTO_MENU_A1)
//		{		
//			PaletteFlag 	= PALETTE_FADE_DOWN;
//   		MouseDeBOUNCE 	= TRUE;
//		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
//		}		 	
//#endif
		if (Button_pressed==GOTO_MENU_A2)
		{		
			new_menu	= MENU_A2;
			PaletteFlag 	= PALETTE_FADE_DOWN;

			for (int resetspr = 1; resetspr < 5; resetspr++)
				{      
//				if (match_info.menu_res==HI)
					menu_data[MENU_A2].SpriteTABLE[resetspr].sprite_state&=	65535-ACTIVE; 
//				else
//					menu_data[MENU_A2].SpriteTABLE[resetspr+4].sprite_state&=	65535-ACTIVE; 
				}


       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}		 	

		if (Button_pressed==GOTO_MENU_A3)
		{		
			new_menu			= MENU_A3;
			PaletteFlag 		= PALETTE_FADE_DOWN;
       		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}
					 	
		if (Button_pressed==GOTO_MENU_A4)
		{		
			new_menu			= MENU_A4;
			PaletteFlag 		= PALETTE_FADE_DOWN;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}


		if (Button_pressed==GOTO_MENU_A5)
		{		
			new_menu			= MENU_A5;
			PaletteFlag 		= PALETTE_FADE_DOWN;
       		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}


		if ( Button_pressed==GOTO_MENU_A6 )
		{
#if 0
			last_menu			=	current_menu;
			new_menu 			= 	MENU_A6;
			PaletteFlag	 		= 	PALETTE_FADE_DOWN;
			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			calibrate_flag		=	255;
			redefine_flag	 	=	255;
			CarryControl		=	NULL;
			which_key_message	=	NULL;
			MarkControlType		=	NULL;
#else
#if ROLLING_DEMO == OFF
			RevertToMac();
			ShowCursor();
			Input_Configure();
			HideCursor();
			RevertToGame();
#endif
#endif
		}


#if 0
		if ( Button_pressed==SETUP_CNTRL )
		{
			menu_data[MENU_A6].ButtonLIST[0].button_flags|=	HALF_SPIN;
					
			if ( match_info.control_methods[MarkControlType-1] >= JOYSTICK1 )
				{
				InitCalibration(match_info.control_methods[MarkControlType-1]);
				calibrate_flag  		= 0;
				redefine_flag  		= 255;
				MouseFlags		   |= MOUSE_OFF;
				}
			else // if ( match_info.control_methods[MarkControlType/*-1*/] < JOYSTICK1 )
				{				
				reprint_redefine_message=	1;
				calibrate_flag		= 255;
				redefine_flag		= 0;
				which_key_message	= 1;
				MouseFlags		   |= MOUSE_OFF;

				if ( (match_info.control_methods[MarkControlType-1]) == KEYBOARD)
					{
					memcpy(copykeys, batch_info.keys_used, 6);
					memset(batch_info.keys_used, 0xff, 6);
					}
#if TWOKEY==YES
				if ( (match_info.control_methods[MarkControlType-1]) == KEYBOARD2)
					{
					memcpy(copykeys, batch_info.keys_used+6, 6);
					memset(batch_info.keys_used+6, 0xff, 6);
					}
#endif
				}							

			MouseDeBOUNCE 	= TRUE;
		}
#endif	    
		if (Button_pressed==GOTO_MENU_A17)
		{		
			new_menu	= MENU_A17;
			PaletteFlag 	= PALETTE_FADE_DOWN;
	     		MouseDeBOUNCE 	= TRUE;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			InitialiseMan	=	GetWinningLeagueTeam();
			InitialiseFlag	=	1;
		}		 	


		if (Button_pressed==GOTO_MENU_A7)
			{
#if ROLLING_DEMO == OFF
			last_menu	=	current_menu;
			new_menu 	= 	MENU_A7;
			PaletteFlag 	= 	PALETTE_FADE_DOWN;
			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			MarkSlotNumber	=	NULL;
#endif
			}


		if (Button_pressed==NEXT_SEASON)
			{		
			batch_info.round_up_page	=	0;
			batch_info.roundup_games	=	0;
			batch_info.PlayerCount		=	match_info.NoOfPlayers+1;	// Richard Added
			Button_pressed	=	GOTO_MENU_A15;
		 	SortNEWdivisions();
			menu_data[MENU_A11].ButtonLIST[0].button_left_select	=	DONE_LEAGUE_DISPLAY;
//			menu_data[MENU_A11].ButtonLIST[0].button_right_select	=	DONE_LEAGUE_DISPLAY;
			menu_data[MENU_A12].ButtonLIST[0].button_left_select	=	DONE_LEAGUE_DISPLAY;
//			menu_data[MENU_A12].ButtonLIST[0].button_right_select	=	DONE_LEAGUE_DISPLAY;
			menu_data[MENU_A13].ButtonLIST[0].button_left_select	=	DONE_LEAGUE_DISPLAY;
//			menu_data[MENU_A13].ButtonLIST[0].button_right_select	=	DONE_LEAGUE_DISPLAY;
			menu_data[MENU_A22].ButtonLIST[0].button_left_select	=	DONE_ROUNDUP; 
//			menu_data[MENU_A22].ButtonLIST[0].button_right_select	=	DONE_ROUNDUP;
			}	


		if (Button_pressed==DONE_CUP_DISPLAY)
		{		
			PaletteFlag 	= PALETTE_FADE_DOWN;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;

			if ( match_info.GameType!=ARCADE)
				Button_pressed	=	GOTO_MENU_A8;

			else
			{
				batch_info.roundup_games++;	//added
				new_menu			= 	PLAY_MATCH;
				PaletteFlag 			= 	PALETTE_FADE_DOWN;
       				thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
				batch_info.OldCTRL1 	  =	-1;
				batch_info.OldCTRL2   	  =	-1;
				reset_scores();
				batch_info.match_number	=	SortNEXTfixture( batch_info.match_number, match_info.CompetitionType);

				if (batch_info.match_number==-1 && match_info.CompetitionType==CUP)
					{
					new_menu	=	MENU_A19;
					InitialiseMan	=	batch_info.winners;
					InitialiseFlag	=	1;
					}

				if (  (game_data[batch_info.cup_team_a].player_control!=NULL ||
					game_data[batch_info.cup_team_b].player_control!=NULL) &&
					 new_menu!=MENU_A19 )
						new_menu =	MENU_A8;

				if ( batch_info.roundup_games > batch_info.RoundPrint )
					{
					new_menu			=	MENU_A22;
			 		batch_info.roundup_games	=	NULL;
					}
			}		 	
		}


		if (Button_pressed==DONE_LEAGUE_DISPLAY)
		{		
			PaletteFlag 	= PALETTE_FADE_DOWN;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;

			if ( match_info.GameType!=ARCADE)
				Button_pressed	=	GOTO_MENU_A8;
			else

			{
				batch_info.roundup_games++;
				reset_scores();
				batch_info.OldCTRL1     	=	-1;
				batch_info.OldCTRL2     	=	-1;
				batch_info.match_number	=	SortNEXTfixture(batch_info.match_number, match_info.CompetitionType);
				new_menu	=	PLAY_MATCH;

				if ( game_data[setup.team_a].player_control!=NULL ||
				     game_data[setup.team_b].player_control!=NULL)
					new_menu	=	MENU_A8;

				if ( batch_info.roundup_games >7 )
				{
					new_menu	=	MENU_A22;
			 		batch_info.roundup_games	=	NULL;
				}
			}

		}



		if (Button_pressed==DONE_ROUNDUP)
		{		

			if (match_info.CompetitionType!=CUP)
			{
				reset_scores();
				batch_info.OldCTRL1     	=	-1;
				batch_info.OldCTRL2     	=	-1;
				batch_info.match_number	=	SortNEXTfixture(batch_info.match_number, match_info.CompetitionType);
			}

				new_menu     	= 	PLAY_MATCH;
		       
				if ( game_data[setup.team_a].player_control!=NULL ||
				     game_data[setup.team_b].player_control!=NULL)
					new_menu	=	MENU_A8;


				if (batch_info.match_number==-1 && match_info.CompetitionType==LEAGUE)
					{
					new_menu	=	MENU_A17;
					InitialiseMan	=	GetWinningLeagueTeam();
					InitialiseFlag	=	1;
					}
				
				if (batch_info.match_number==-1 && match_info.CompetitionType==CUP)
					{
					new_menu	=	MENU_A19;
					InitialiseMan	=	batch_info.winners;
					InitialiseFlag	=	1;
					}
				PaletteFlag 			= 	PALETTE_FADE_DOWN;
       				thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}
			




		if (Button_pressed==RETURN_TO_MENU_A8)
		{		
			new_menu			= 	MENU_A8;
			PaletteFlag 			= 	PALETTE_FADE_DOWN;
       		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			batch_info.OldCTRL1    			=	-1;
			batch_info.OldCTRL2   	  		=	-1;
			reset_scores();
		}		 	



		if (Button_pressed==GOTO_MENU_A8)
		{		
			new_menu			= 	MENU_A8;
			PaletteFlag 			= 	PALETTE_FADE_DOWN;
       		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			batch_info.OldCTRL1     			=	-1;
			batch_info.OldCTRL2   	  		=	-1;
			reset_scores();
			batch_info.match_number	=	SortNEXTfixture(batch_info.match_number, match_info.CompetitionType);

			get_cup_venue();
			
			if (batch_info.match_number==-1 && match_info.CompetitionType==LEAGUE)
				{
				new_menu	=	MENU_A17;
				InitialiseMan	=	GetWinningLeagueTeam();
				InitialiseFlag	=	1;
				}
			if (batch_info.match_number==-1 && match_info.CompetitionType==CUP)
				{
				new_menu	=	MENU_A19;
				InitialiseMan	=	batch_info.winners;
				InitialiseFlag	=	1;
				}
		}		 	



		if (Button_pressed==GOTO_MENU_A9)
		{		
			if	(game_data[selected_team].player_control == NULL)

				new_menu	=	MENU_A21;
			else
				new_menu	=	MENU_A9;

			PaletteFlag 	= PALETTE_FADE_DOWN;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			formation_toggle=	game_data[selected_team].formation;
			MarkSquadPlayer	=	NULL;
		}		 	

		if (Button_pressed==GOTO_MENU_A11)
		{		
			batch_info.Ranking_Division=	0;
			new_menu	= MENU_A11;
			PaletteFlag 	= PALETTE_FADE_DOWN;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}		 	

		if (Button_pressed==GOTO_MENU_A12)
		{	
			batch_info.Ranking_Division=	1;
			new_menu	= MENU_A12;
			PaletteFlag 	= PALETTE_FADE_DOWN;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}		 	

		if (Button_pressed==GOTO_MENU_A13)
		{		
			batch_info.Ranking_Division=	2;
			new_menu	= MENU_A13;
			PaletteFlag 	= PALETTE_FADE_DOWN;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}		 	

		if (Button_pressed==GOTO_LEAGUE)
		{		
			new_menu	= MENU_A11+batch_info.Ranking_Division;
			PaletteFlag 	= PALETTE_FADE_DOWN;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}		 	

		if (Button_pressed==GOTO_MENU_A14)
		{		
			new_menu	= MENU_A14;
			PaletteFlag 	= PALETTE_FADE_DOWN;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}		 	

		if (Button_pressed==GOTO_MENU_A22)
		{		
			new_menu	= MENU_A22;
			PaletteFlag 	= PALETTE_FADE_DOWN;
       			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}

			
		if ( Button_pressed==CHOOSE_TEAMS && match_info.CompetitionType==NETWORK )		//	NETWORK GAME...
			{
			if (no_cd==FALSE)
				cd_in	=	CDPresent();
			else
				cd_in	=	1;

			menu_data[MENU_A8].ButtonLIST[7].button_flags&= 	65535-ACTIVE;
			menu_data[MENU_A8].SpriteTABLE[6].sprite_state|=	ACTIVE; 

			Init_Network_Game();		// Initialises Team_A, Team_B, TeamChoice & PlayerChoice and starts network

			if(batch_info.Port_toggle)
				{
				Boolean flag;
						
				RevertToMac();
				flag = JoinGame();
				RevertToGame();
				if( flag)
					return;
				}
						
			new_menu	= 	MENU_A8;
			compute_a  	=	TRUE;
			compute_b  	=	TRUE;
			PaletteFlag 	= 	PALETTE_FADE_DOWN;
		    thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			batch_info.OldCTRL1     	=	-1;
			batch_info.OldCTRL2     	=	-1;
			batch_info.match_number	=	SortNEXTfixture(batch_info.match_number, match_info.CompetitionType);
			game_data[setup.team_a].player_control	= NULL;
			game_data[setup.team_b].player_control	= NULL; 

			for (int cl=0; cl < 8; cl++)
				menu_data[MENU_A8].StringLIST[cl+3].string_type	= NULL;
			}

		if ( Button_pressed==CHOOSE_TEAMS && (match_info.CompetitionType>FRIENDLY && match_info.CompetitionType==LEAGUE ||
			 match_info.CompetitionType>FRIENDLY && match_info.CompetitionType==CUP) )
		{		
       			menu_data[MENU_A8].ButtonLIST[7].button_flags&= 	65535-ACTIVE;
			menu_data[MENU_A8].SpriteTABLE[6].sprite_state|=	ACTIVE; 
			batch_info.PlayerCount	= 	0;
			Button_pressed	=	GOTO_MENU_A15;
		
				for (int choicenum = 0; choicenum < MAX_TEAMS; choicenum++)
				{	game_data[choicenum].player_control	=	NULL;	}
	
			menu_data[MENU_A15].ImageLIST[1]	=	NULL;
			menu_data[MENU_A15].ImageLIST[2]	=	NULL;
			menu_data[MENU_A15].ImageLIST[3]	=	NULL;

			batch_info.match_number			=	-1;
			batch_info.round_up_page		=	0;
			batch_info.cup_match_number		=	-1;
		}


		if ( Button_pressed==CHOOSE_TEAMS && ( match_info.CompetitionType==FRIENDLY || match_info.CompetitionType==PRACTICE ))
		{
#if ROLLING_DEMO == OFF
       		menu_data[MENU_A8].ButtonLIST[7].button_flags&= 	65535-ACTIVE;
			menu_data[MENU_A8].SpriteTABLE[6].sprite_state|=	ACTIVE; 
			new_menu	= 	MENU_A8;
			compute_a   	=	TRUE;
			compute_b   	=	TRUE;
			PaletteFlag 	= 	PALETTE_FADE_DOWN;
       		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			batch_info.OldCTRL1     	=	-1;
			batch_info.OldCTRL2     	=	-1;
			batch_info.match_number	=	SortNEXTfixture(batch_info.match_number, match_info.CompetitionType);

			game_data[setup.team_a].player_control	= friendly_controls[match_info.NoOfPlayers];
			game_data[setup.team_b].player_control	= friendly_controls[match_info.NoOfPlayers+4];		
#else
			new_menu = MENU_A23;
#endif
		}

		if (Button_pressed==GOTO_MENU_A15)
		{		
			Players_Team_Choice = 255;
			Setup_possible_choice_teams();
			PaletteFlag = PALETTE_FADE_DOWN;
       		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;

			if ( batch_info.PlayerCount>match_info.NoOfPlayers )
				{
				new_menu = MENU_A8;
				batch_info.OldCTRL1 = batch_info.OldCTRL2 = -1;
				batch_info.match_number = SortNEXTfixture(batch_info.match_number, match_info.CompetitionType);
				
//				;******* ARCADE OPTION SELECTED *******

				if ( (match_info.GameType==NULL && match_info.CompetitionType!=CUP && game_data[setup.team_a].player_control==0 && game_data[setup.team_b].player_control==0 )
				  || (match_info.GameType==NULL && match_info.CompetitionType==CUP && game_data[batch_info.cup_team_a].player_control==0 && game_data[batch_info.cup_team_b].player_control==0 ))
					{			
//					cup_match_number=	0;
					new_menu	= 	PLAY_MATCH;
					batch_info.roundup_games	=	NULL;	
					}
				}				
			else
				{
				new_menu	= 	MENU_A15;
				rerun_menu	=	1;
				}
			menu_data[MENU_A15].LabelLIST[0]	=	LAB62+batch_info.PlayerCount;
			batch_info.PlayerCount++;
		}		 	

		if (Button_pressed==START_MATCH && match_info.CompetitionType<NETWORK)
		{		
			if (match_info.GameType==SIMULATION && game_data[setup.team_a].player_control==NULL && game_data[setup.team_b].player_control==NULL)
				{
				new_menu	= PLAY_MATCH;
				PaletteFlag 	= PALETTE_FADE_DOWN;
    			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
				}
			else
				{
				if (no_cd==FALSE)
					cd_in	=	CDPresent();
				else
					cd_in	=	1;

				if (cd_in!=NULL)
					{
					SuspendAudio = true;
					StopMusic();
					MouseFlags|=	MOUSE_OFF;
					new_menu	= MENU_A23;	//PLAY_MATCH;
					PaletteFlag 	= PALETTE_FADE_DOWN;
    				thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
					}
				else
					{
					TextCOLOUR	=	175;
					TextXposn	=	320;
					TextYposn	=	400;
					CopyXposn	=	TextXposn-128-48;
					CopyYposn	=	TextYposn;
					CopyHEIGHT	=	20;
					CopyWIDTH	=	256+96;
					RestorePSUDObuffer();
					DisplaySTRING( GetSTRING( CD_TEXT,0 ), SHADOWtextON|SFONT|CENTREjustifyTEXT );
					Add_to_copy_list( CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
					}
				}
		}

		if (Button_pressed==START_MATCH && match_info.CompetitionType==NETWORK)
		{		
			I_Chose_Teams			=	NO;
			new_menu			= 	MENU_A18;
			PaletteFlag 			= 	PALETTE_FADE_DOWN;
			menu_data[MENU_A8].ButtonLIST[0].button_flags|= START_SPIN;
			MarkSquadPlayer 		=	255;
			Team_A				=	setup.team_a;
			Team_B				=	setup.team_b;
			Endnetwork		   	=	OFF;
			setup.team_b_kit		=	team_b_kit[ ((setup.team_a*MAX_TEAMS)+setup.team_b) ];
			match_info.venue		=	setup.team_a;
			menu_images[67].ImageNumber	=	(setup.team_a)+USA_KIT_IMAGE;
			menu_images[66].ImageNumber	=	(setup.team_b_kit)+USA_KIT_IMAGE;
			SortSQUAD(setup.team_a);
			SortSQUAD(setup.team_b);
			if(!batch_info.Port_toggle)
				{
				RevertToMac();
				HostGame();
				RevertToGame();
//				SendNETTeamInfo();
				}
		}		 	

		if ( Button_pressed==TEAMa_SQUAD || Button_pressed==TEAMb_SQUAD )
		{		
			new_menu		= 	MENU_A9;

			PaletteFlag 	= PALETTE_FADE_DOWN;
       		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			MarkSquadPlayer	= NULL;

			if ( Button_pressed==TEAMa_SQUAD )
				selected_team	=	setup.team_a;	
			else
				selected_team	=	setup.team_b;	

			if	(game_data[selected_team].player_control == NULL)
				new_menu		= 	MENU_A21;

			formation_toggle	=	game_data[selected_team].formation;
		}		 	

		if ( Button_pressed==FRWD_TIME )
		{
			match_info.time_toggle++;
			if ( match_info.time_toggle > 4)
				match_info.time_toggle	=	NULL;

    		MouseDeBOUNCE 	=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
		}

#ifdef TWOBUTTONS
		if ( Button_pressed==BACK_TIME )
		{
			match_info.time_toggle--;
			if ( match_info.time_toggle < 0)
				match_info.time_toggle	=	4;

     		MouseDeBOUNCE 	=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
		}
#endif

		if ( Button_pressed==FRWD_WIND )
		{
			match_info.wind_toggle++;
			if ( match_info.wind_toggle > 3)
				match_info.wind_toggle	=	NULL;

	   		MouseDeBOUNCE 	=	TRUE;
    		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
		}

#ifdef TWOBUTTONS
		if ( Button_pressed==BACK_WIND )
		{
			match_info.wind_toggle--;
			if ( match_info.wind_toggle < 0)
				match_info.wind_toggle	=	3;

	   		MouseDeBOUNCE 	=	TRUE;
    		thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
		}
#endif

#ifdef TWOBUTTONS
		if ( Button_pressed==FRWD_OFFSIDE || Button_pressed==BACK_OFFSIDE )
		{
			match_info.offside_toggle^=	ON;
	   		MouseDeBOUNCE 		=	TRUE;

			if (Button_pressed==FRWD_OFFSIDE )
				{
	   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
    			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
				}
			else	
	   			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
		}
#else
		if ( Button_pressed==FRWD_OFFSIDE )
		{
			match_info.offside_toggle^=	ON;
	   		MouseDeBOUNCE 		=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}
#endif

#ifdef TWOBUTTONS
		if ( Button_pressed==FRWD_SUBS || Button_pressed==BACK_SUBS )
		{
			match_info.substitutes_toggle^=	ON;
     		MouseDeBOUNCE 		=	TRUE;

			if (Button_pressed==FRWD_SUBS )
				{
		       	thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
       			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
				}
			else	
		    	thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
		}
#else
		if ( Button_pressed==FRWD_SUBS )
		{
			match_info.substitutes_toggle^=	ON;
     		MouseDeBOUNCE 		=	TRUE;
	       	thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}
#endif

#ifdef TWOBUTTONS
		if ( Button_pressed==FRWD_FREEKICKS || Button_pressed==BACK_FREEKICKS )
		{
			match_info.freekicks_toggle^=	ON;
     		MouseDeBOUNCE 		=	TRUE;

			if (Button_pressed==FRWD_FREEKICKS )
				{
	   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
    			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
				}
			else	
	   			thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
			}
#else
		if ( Button_pressed==FRWD_FREEKICKS )
		{
			match_info.freekicks_toggle^=	ON;
	   		MouseDeBOUNCE 		=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}
#endif

#ifdef TWOBUTTONS
		if ( Button_pressed==FRWD_BOOKINGS || Button_pressed==BACK_BOOKINGS )
		{
			match_info.bookings_toggle^=	ON;
	   		MouseDeBOUNCE 		=	TRUE;

			if (Button_pressed==FRWD_BOOKINGS )
				{
	    		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
    			thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
				}
			else	
	    		thisMenu->ButtonLIST[spin_button].button_flags|= (START_SPIN+BACK_SPIN);
		}
#else
		if ( Button_pressed==FRWD_BOOKINGS )
		{
			match_info.bookings_toggle^=	ON;
     		MouseDeBOUNCE 		=	TRUE;
   			thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
		}
#endif

		if (Button_pressed==QUIT_BUTTON || Button_pressed==DOS_QUIT)
		{		
			if (Button_pressed==DOS_QUIT)
			{
			   	MouseDeBOUNCE 		=	TRUE;
	       	   		thisMenu->ButtonLIST[spin_button].button_flags|= START_SPIN;
			   	thisMenu->ButtonLIST[spin_button].button_flags&= 65535-BACK_SPIN;
			}
	 	new_menu	= QUIT;
//	 	PaletteFlag 	= PALETTE_FADE_DOWN;
		}		 	
	}
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Update_formation(int menu_number)                                                                                           บ
//บ																 บ
//บ																 บ
//บ		Updates spinning formation button with correct formation type.                                                   บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Update_formation(int current_menu)
{
	if (current_menu==MENU_A9)
	{
	       if (menu_data[MENU_A9].ButtonLIST[1].button_index==8)
			display_formation	=	game_data[selected_team].formation;
	}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Update_environment(int menu_number)                                                                                          บ
//บ																 บ
//บ																 บ
//บ		Updates all environment values.                                                                                  บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Update_environment(int current_menu)
{
menu *thisMenu = &menu_data[ current_menu];

	if (current_menu==MENU_A5)
		{
		if (thisMenu->ButtonLIST[0].button_index==8)
			setup.detail.sky	=	match_info.sky_toggle;
		if (thisMenu->ButtonLIST[1].button_index==8)
			setup.detail.stadia	=	match_info.stadium_toggle;
		if (thisMenu->ButtonLIST[2].button_index==8)
			setup.detail.lines	=	match_info.line_toggle;
		if (thisMenu->ButtonLIST[3].button_index==8)
			match_info.vidi		=	match_info.vidi_toggle;
		if (thisMenu->ButtonLIST[4].button_index==8)
			setup.detail.players	=	match_info.players_toggle;
		if (thisMenu->ButtonLIST[5].button_index==8)
			setup.detail.pitch	=	match_info.pitch_toggle;
		if (thisMenu->ButtonLIST[6].button_index==8)
			setup.start_res		=	match_info.res_toggle;
		if (thisMenu->ButtonLIST[7].button_index==8)
			match_info.camera	=	match_info.camera_toggle;
		if (thisMenu->ButtonLIST[8].button_index==8)
			setup.screen_size	=	match_info.size_toggle;
		}
	else if (current_menu==MENU_A4)
		{
		if (thisMenu->ButtonLIST[0].button_index==8)
			match_info.offside	=	match_info.offside_toggle;
		if (thisMenu->ButtonLIST[1].button_index==8)
			match_info.substitutes	=	match_info.substitutes_toggle;
		if (thisMenu->ButtonLIST[2].button_index==8)
			match_info.freekicks	=	match_info.freekicks_toggle;
		if (thisMenu->ButtonLIST[3].button_index==8)
			net_half = match_info.time = match_info.time_toggle;
		if (thisMenu->ButtonLIST[4].button_index==8)
			match_info.bookings	=	match_info.bookings_toggle;
		if (thisMenu->ButtonLIST[5].button_index==8)
			match_info.wind		=	match_info.wind_toggle;
		}
	else if (current_menu==MENU_A14)
		{
		match_info.CROWD		=	thisMenu->ButtonLIST[0].button_index;	
		match_info.COMMENTRY	=	thisMenu->ButtonLIST[1].button_index;	
		match_info.MASTER		=	thisMenu->ButtonLIST[2].button_index;	
		match_info.PITCH		=	thisMenu->ButtonLIST[3].button_index;	
		match_info.MUSIC		=	thisMenu->ButtonLIST[4].button_index;	
		match_info.crowd		=	thisMenu->ButtonLIST[0].button_index*163;   // this multipication rounds upto 32600.
 		match_info.commentary	=	thisMenu->ButtonLIST[1].button_index*163;   // the value should really be 163.835 to
 		match_info.master		=	thisMenu->ButtonLIST[2].button_index*163;   // round upto 32767.
 		match_info.pitch		=	thisMenu->ButtonLIST[3].button_index*163;
		match_info.music		=	thisMenu->ButtonLIST[4].button_index*163;
		if (thisMenu->ButtonLIST[7].button_index==8)
			match_info.audio	=	match_info.audio_toggle;
		}
	else if (current_menu==MENU_A9)
		{
		if (thisMenu->ButtonLIST[1].button_index==8)
			game_data[selected_team].formation	=	formation_toggle;
		}
	else if (current_menu==MENU_A0)
		{
		if (thisMenu->ButtonLIST[2].button_index==8 && match_info.CompetitionType_toggle!=NETWORK)
			match_info.NoOfPlayers	=	match_info.NoOfPlayers_toggle;
		if (thisMenu->ButtonLIST[2].button_index==8 && match_info.CompetitionType_toggle==NETWORK)
			{
			match_info.NoOfPlayers	=	batch_info.Port_toggle+4;
			net_game_no		=	batch_info.Port_toggle;
			}
		if (thisMenu->ButtonLIST[3].button_index==8)
			match_info.GameType	=	match_info.GameType_toggle;
		if (thisMenu->ButtonLIST[1].button_index==8)
			match_info.CompetitionType	=	match_info.CompetitionType_toggle;
		if (match_info.CompetitionType==NETWORK)
			ESCkey[8]	=	-1;
		else	
			ESCkey[8]	=	GOTO_START;
      	}
	else if (current_menu==MENU_A18 && menu_data[MENU_A18].ButtonLIST[0].button_index==8 && Endnetwork==ON )
		{
		NetworkType	=	NetworkType_toggle;
//		if	(TeamChoice < 2)
//			{
//			TeamChoice+=2;
//			SendPlayerChoice();
//			TickerPause();
//		}
		}
	match_info.music	=	menu_data[MENU_A14].ButtonLIST[4].button_index*163;
	UpdateVolumeLevels();	  				// volume levels should continuously be updated.
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_text_editing(int menu_number)                                                                                            บ
//บ																 บ
//บ																 บ
//บ		Allows user to edit a text string.                                                                               บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Do_text_editing(int menu_number)
{
menu *thisMenu = &menu_data[menu_number];
//Boolean	reprint_string	=	NULL;
BYTE	key;
BYTE	SngLen;
BYTE	SngCnt;

	if	( (MouseFlags & EDIT_TEXT) )
		{		
       	ArrayNumber		=	thisMenu->StringLIST[EditStringNum].string_array;	
		TextBuffer   	=	GetSTRING(thisMenu->StringLIST[EditStringNum].string_type,ArrayNumber);

		if (kbhit)
			{
			SngLen = strlen	(TextBuffer);
			key=Getchar();
			switch(key)
		  		{
		  		case(0x08):	// Delete
			  		if ( SngLen>=1 && CursorXposn>0 )
			  			{
		  				SngCnt = CursorXposn;
		  				while( SngCnt<thisMenu->StringLIST[EditStringNum].max_string_chars ) 
							{
			  				TextBuffer[SngCnt-1]	=	TextBuffer[SngCnt];
			  				SngCnt++;
//							reprint_string		=	ON;
			  				}
			  			TextBuffer[SngCnt-1]	=	0;
			  			CursorXposn--;
			  			}
					break;
		  		
				case(0x0d): // Carriage return
				case(0x03):
					MouseFlags &= 65535-EDIT_TEXT;
					key_debounce |= TRUE;
					MouseDeBOUNCE = TRUE;
					if (menu_number==MENU_A1)
						game_data[selected_team].players[ArrayNumber].goal_index = 0;
					break;
									
		  		case(0x1c): // Left
					if(CursorXposn)
						{
			   			CursorXposn--;
//						reprint_string = ON;
						}
					break;
							  		
		  		case(0x1d):
					if(CursorXposn<SngLen)
						{
						CursorXposn++;
//						reprint_string = ON;
						}
					break;
							  		
		  		default:
		  			if (key>=32 && key<=122 && SngLen<thisMenu->StringLIST[EditStringNum].max_string_chars && (FindLengthOfSTRING( TextBuffer, key, NULL )) 
		  										< thisMenu->StringLIST[EditStringNum].max_string_size )
						{
						if (key<91 || key>96)
							{
							TextBuffer[SngLen+1] = 0;
							SngCnt = SngLen;
							while(SngCnt>CursorXposn) // || SngCnt==0) 
			  					{									  
			  					TextBuffer[SngCnt]	=	TextBuffer[SngCnt-1];
			  					SngCnt--;
//								reprint_string = ON;
								}
		  		 			TextBuffer[CursorXposn]	=	key;

							if (CursorXposn==SngLen)
								{
				     			CursorXposn = strlen (TextBuffer);
//								reprint_string = ON;
								}
							else
								{
					     		CursorXposn++;
//								reprint_string = ON;
								}
							}		
						}
					break;
		
	  			}
			}
		
//		if(reprint_string==ON)
			{
			TextXposn	=	thisMenu->StringLIST[EditStringNum].string_xposn;
			TextYposn	=	thisMenu->StringLIST[EditStringNum].string_yposn;
			TextCOLOUR	=	29;
  		    thisMenu->StringLIST[EditStringNum].string_flags |= HIGHLIGHTED_TEXT;	
			CopyXposn	=	thisMenu->StringLIST[EditStringNum].CopyAreaX;
			CopyYposn	=	thisMenu->StringLIST[EditStringNum].CopyAreaY;
			CopyWIDTH	=	thisMenu->StringLIST[EditStringNum].CopyWidth;
			CopyHEIGHT	=	thisMenu->StringLIST[EditStringNum].CopyHeight;
			RestorePSUDObuffer();
			CursorXdisplay	= DisplaySTRING( GetSTRING(thisMenu->StringLIST[EditStringNum].string_type,ArrayNumber), thisMenu->StringLIST[EditStringNum].string_shadow);
			if((MouseFlags & EDIT_TEXT)!=0 && (pulsating_colour & 8) !=0 )
				{
				TextCOLOUR	=	CURSOR_COLOUR;
				TextXposn	=	CursorXdisplay;
				DisplaySTRING("[",thisMenu->StringLIST[EditStringNum].string_shadow);		
				}
			Add_to_copy_list( thisMenu->StringLIST[EditStringNum].CopyAreaX,
							  thisMenu->StringLIST[EditStringNum].CopyAreaY,
							  thisMenu->StringLIST[EditStringNum].CopyWidth,
							  thisMenu->StringLIST[EditStringNum].CopyHeight);
			}
		}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Animate_participating_flags(int menu_number)                                                                                บ
//บ																 บ
//บ																 บ
//บ		Animates flag on which cursor is overlayed (this is only used on MENU_A3).                                       บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Animate_participating_flags(int	menu_number)
{
	if ( menu_number==MENU_A3 || menu_number==MENU_A15)
	{
		for (int flagnum = 0; flagnum < MAX_TEAMS-1; flagnum++)
		{
			if ( (menu_data[menu_number].StringLIST[flagnum].string_flags & HOVERING_OVER_TEXT)== 0)
				{
				menu_data[menu_number].SpriteTABLE[flagnum].sprite_state|=	FREEZE;
				menu_data[menu_number].SpriteTABLE[flagnum].FrameCounter =	0;
				}
			else
				menu_data[menu_number].SpriteTABLE[flagnum].sprite_state&=	65535-FREEZE;
		}
	}
}

static Boolean InBox( string_info *thisMenu)
{
	if( ClickXposn > thisMenu->BoundingBoxLeft && ClickXposn < thisMenu->BoundingBoxRight)
		if( ClickYposn > thisMenu->BoundingBoxTop && ClickYposn < thisMenu->BoundingBoxBottom)
			return true;
			
	return false;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_participating_selection(int menu_number)                                                                                 บ
//บ																 บ
//บ																 บ
//บ		Allows user to select teams which are to participate in cup competition (MENU_A3).                               บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Do_participating_selection(int menu_number)
{
	if ( menu_number==MENU_A3 )
	{
		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	
		int	stringnum, Reprint_string;
		int	no_of_selected_teams	=	0;

				for (stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
				{
						if ( (menu_data[MENU_A3].StringLIST[stringnum].string_flags & TOGGLE_FLAG)!=0)
							no_of_selected_teams++;	
				}

			
			if ( no_of_selected_teams==batch_info.number_of_cup_teams) 
				menu_data[MENU_A3].ButtonLIST[0].button_flags&=	65535-HALF_SPIN;
			else	
				menu_data[MENU_A3].ButtonLIST[0].button_flags|=	HALF_SPIN;


		for (stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
			{
			Reprint_string = NULL;
			menu_data[MENU_A3].StringLIST[stringnum].string_flags&=	65535-HOVERING_OVER_TEXT;

			if ( menu_data[MENU_A3].StringLIST[stringnum].string_type!=NULL
				&& InBox( &menu_data[MENU_A3].StringLIST[stringnum]) )
//				&& ClickXposn > menu_data[MENU_A3].StringLIST[stringnum].BoundingBoxLeft
//			      && ClickXposn < menu_data[MENU_A3].StringLIST[stringnum].BoundingBoxRight
//			       && ClickYposn > menu_data[MENU_A3].StringLIST[stringnum].BoundingBoxTop
//			        && ClickYposn < menu_data[MENU_A3].StringLIST[stringnum].BoundingBoxBottom)
				{
				menu_data[MENU_A3].StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;
				if	( MouseBUTTONS==LEFT_BUTTON)
					{
					menu_data[MENU_A3].StringLIST[stringnum].string_flags ^= TOGGLE_FLAG;
					Reprint_string	=	TRUE;
					MouseDeBOUNCE 	= 	TRUE;

					if ( menu_data[MENU_A3].StringLIST[stringnum].string_flags&TOGGLE_FLAG)
						{
						if( no_of_selected_teams == batch_info.number_of_cup_teams )
							menu_data[MENU_A3].StringLIST[stringnum].string_flags ^= TOGGLE_FLAG;
						}
					}
/*
				if ( MouseBUTTONS==RIGHT_BUTTON && (menu_data[MENU_A3].StringLIST[stringnum].string_flags & TOGGLE_FLAG)!=0)
					{
					menu_data[MENU_A3].StringLIST[stringnum].string_flags&=	65535-TOGGLE_FLAG;
					Reprint_string	=	TRUE;
					MouseDeBOUNCE 	= 	TRUE;
					}
*/
				if ( (menu_data[MENU_A3].StringLIST[stringnum].string_flags & TOGGLE_FLAG)!=0)
					TextCOLOUR	=	175;	//menu_data[MENU_A3].StringLIST[stringnum].string_mark_colour;
				else
					TextCOLOUR	=	menu_data[MENU_A3].StringLIST[stringnum].string_colour;

				menu_data[MENU_A3].StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
				}

		if ( (menu_data[MENU_A3].StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)!=0 
		     && (menu_data[MENU_A3].StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)==0)
			{ 
				if ( (menu_data[MENU_A3].StringLIST[stringnum].string_flags & TOGGLE_FLAG)!=0)
					TextCOLOUR	=	175;	//BRIGHT_WHITE;
				else
					TextCOLOUR	=	BRIGHT_GRAY;

				menu_data[MENU_A3].StringLIST[stringnum].string_flags|=	HIGHLIGHTED_TEXT;
				Reprint_string	=	TRUE;
			}

		if ( (menu_data[MENU_A3].StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)==0 
		     && (menu_data[MENU_A3].StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)!=0)
			{ 
				if ( (menu_data[MENU_A3].StringLIST[stringnum].string_flags & TOGGLE_FLAG)!=0)
					TextCOLOUR	=	menu_data[MENU_A3].StringLIST[stringnum].string_mark_colour;
				else
					TextCOLOUR	=	menu_data[MENU_A3].StringLIST[stringnum].string_colour;
				menu_data[MENU_A3].StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
				Reprint_string	=	TRUE;
			}

				if ( Reprint_string==TRUE )
				{
		       		ArrayNumber	=	menu_data[MENU_A3].StringLIST[stringnum].string_array;	
				TextXposn	=	menu_data[MENU_A3].StringLIST[stringnum].string_xposn;
				TextYposn	=	menu_data[MENU_A3].StringLIST[stringnum].string_yposn;
				CopyXposn	=	menu_data[MENU_A3].StringLIST[stringnum].CopyAreaX;
				CopyYposn	=	menu_data[MENU_A3].StringLIST[stringnum].CopyAreaY;
				CopyWIDTH	=	menu_data[MENU_A3].StringLIST[stringnum].CopyWidth;
				CopyHEIGHT	=	menu_data[MENU_A3].StringLIST[stringnum].CopyHeight;
		
				RestorePSUDObuffer();

	DisplaySTRING( GetSTRING(menu_data[MENU_A3].StringLIST[stringnum].string_type,ArrayNumber),
		        	 menu_data[MENU_A3].StringLIST[stringnum].string_shadow);

			Add_to_copy_list(menu_data[MENU_A3].StringLIST[stringnum].CopyAreaX,
                                         menu_data[MENU_A3].StringLIST[stringnum].CopyAreaY,
				         menu_data[MENU_A3].StringLIST[stringnum].CopyWidth,
                                         menu_data[MENU_A3].StringLIST[stringnum].CopyHeight);
			       }
		}
	}
}



//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_choice_selection(int menu_number)                                                                                        บ 
//บ																 บ
//บ																 บ
//บ		Allows user to select teams they wish to control (MENU_A15).                                                     บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Do_choice_selection(int menu_number)
{
menu *thisMenu;
int	stringnum, Reprint_string;
int	PlayerSetMask,array;

	if ( menu_number==MENU_A15 )
		{
		thisMenu = &menu_data[MENU_A15];
		
		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	

		if	(batch_info.PlayerCount==1)	
			PlayerSetMask	=	PLAYER1;
		else if	(batch_info.PlayerCount==2)	
			PlayerSetMask	=	PLAYER2;
		else if	(batch_info.PlayerCount==3)	
			PlayerSetMask	=	PLAYER3;
		else if	(batch_info.PlayerCount==4)	
			PlayerSetMask	=	PLAYER4;

		if ( Players_Team_Choice!=	255 ) 
			thisMenu->ButtonLIST[0].button_flags&=	65535-HALF_SPIN;
		else	
			thisMenu->ButtonLIST[0].button_flags|=	HALF_SPIN;
 
		for (stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
			{
			Reprint_string						  =	NULL;
			thisMenu->StringLIST[stringnum].string_flags&=	65535-HOVERING_OVER_TEXT;

		    if ( thisMenu->StringLIST[stringnum].string_type!=NULL
				&& InBox( &thisMenu->StringLIST[stringnum]))
//				&& ClickXposn > thisMenu->StringLIST[stringnum].BoundingBoxLeft
//			     && ClickXposn < thisMenu->StringLIST[stringnum].BoundingBoxRight
//			      && ClickYposn > thisMenu->StringLIST[stringnum].BoundingBoxTop
//			       && ClickYposn < thisMenu->StringLIST[stringnum].BoundingBoxBottom)
				{	
				thisMenu->StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;

				if	( MouseBUTTONS==LEFT_BUTTON) //  || MouseBUTTONS==RIGHT_BUTTON )
					{					
					if ( Players_Team_Choice!=255 )
						{
						thisMenu->StringLIST[Players_Team_Choice].string_flags|=	HIGHLIGHTED_TEXT;
						thisMenu->StringLIST[Players_Team_Choice].string_flags&=	65535-HOVERING_OVER_TEXT;
						array = thisMenu->StringLIST[Players_Team_Choice].string_array;
						game_data[array].player_control &= 65535-PlayerSetMask;
						}
					Players_Team_Choice	=	stringnum;									
				    thisMenu->StringLIST[Players_Team_Choice].string_flags&=	65535-HIGHLIGHTED_TEXT;
				    thisMenu->StringLIST[Players_Team_Choice].string_flags|=	HOVERING_OVER_TEXT;
				    array = thisMenu->StringLIST[Players_Team_Choice].string_array;
					game_data[array].player_control |= PlayerSetMask;
					Reprint_string		=	TRUE;
					MouseDeBOUNCE 		= 	TRUE;
					}

				if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)!=0 
					&& (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)==0)
					{ 
					TextCOLOUR	=	BRIGHT_WHITE;
					if ( stringnum==Players_Team_Choice )
						TextCOLOUR	=	175;	//BRIGHT_GREEN;
					thisMenu->StringLIST[stringnum].string_flags|=	HIGHLIGHTED_TEXT;
			    	Reprint_string	=	TRUE;
					}
				}

			if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)==0 
				&& (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)!=0)
				{ 
				TextCOLOUR	=	DULL_WHITE;
				if ( stringnum==Players_Team_Choice )
					TextCOLOUR	=	175;	//DULL_GREEN;
				thisMenu->StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
				Reprint_string	=	TRUE;
				}

			if ( Reprint_string==TRUE )
				{
	       		ArrayNumber = thisMenu->StringLIST[stringnum].string_array;	
				TextXposn = thisMenu->StringLIST[stringnum].string_xposn;
				TextYposn =	thisMenu->StringLIST[stringnum].string_yposn;
				CopyXposn = thisMenu->StringLIST[stringnum].CopyAreaX;
				CopyYposn = thisMenu->StringLIST[stringnum].CopyAreaY;
				CopyWIDTH = thisMenu->StringLIST[stringnum].CopyWidth;
				CopyHEIGHT = thisMenu->StringLIST[stringnum].CopyHeight;
				RestorePSUDObuffer();
				DisplaySTRING( GetSTRING(thisMenu->StringLIST[stringnum].string_type,ArrayNumber), thisMenu->StringLIST[stringnum].string_shadow);
				Add_to_copy_list(thisMenu->StringLIST[stringnum].CopyAreaX,
                   				 thisMenu->StringLIST[stringnum].CopyAreaY,
								 thisMenu->StringLIST[stringnum].CopyWidth,
								 thisMenu->StringLIST[stringnum].CopyHeight);
		       }
			}
		}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_edit_team_data(menu_number)                                                                                              บ
//บ																 บ
//บ																 บ
//บ		Allows user to modify team data (MENU_A1).                                                                       บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Do_edit_team_data(int menu_number)	
{
menu *thisMenu;
int	stringnum, Reprint_string;

	if ( menu_number==MENU_A1 && (MouseFlags & EDIT_TEXT)==0)
		{
		thisMenu = &menu_data[MENU_A1];
		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	

		for (stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
			{
			Reprint_string = NULL;
			thisMenu->StringLIST[stringnum].string_flags&=	65535-HOVERING_OVER_TEXT;

			if ( thisMenu->StringLIST[stringnum].string_type!=NULL
				&& InBox( &thisMenu->StringLIST[stringnum]))
//			     && ClickXposn > thisMenu->StringLIST[stringnum].BoundingBoxLeft
//			      && ClickXposn < thisMenu->StringLIST[stringnum].BoundingBoxRight
//			       && ClickYposn > thisMenu->StringLIST[stringnum].BoundingBoxTop
//			        && ClickYposn < thisMenu->StringLIST[stringnum].BoundingBoxBottom)
				{
				thisMenu->StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;

				if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)!=0 
					&& (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)==0
					 && (thisMenu->StringLIST[stringnum].string_flags & EDITABLE_TEXT)!=0)
					{ 
					TextCOLOUR	=	26;
					thisMenu->StringLIST[stringnum].string_flags|=	HIGHLIGHTED_TEXT;
					Reprint_string	=	TRUE;
					}
				if	( MouseBUTTONS==LEFT_BUTTON)  
					{
					EditStringNum = stringnum;
					MouseFlags|=EDIT_TEXT;
					ArrayNumber = thisMenu->StringLIST[EditStringNum].string_array;	
					TextBuffer = GetSTRING(thisMenu->StringLIST[EditStringNum].string_type,ArrayNumber);
			     	CursorXposn = strlen(TextBuffer);
					}
				}

			if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)==0 
				&& (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)!=0
				 && (thisMenu->StringLIST[stringnum].string_flags & EDITABLE_TEXT)!=0)
				{ 
				TextCOLOUR	=	thisMenu->StringLIST[stringnum].string_colour;
				thisMenu->StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
				Reprint_string	=	TRUE;
				}
				
			if ( menu_update==UPDATE_DISPLAY && (thisMenu->StringLIST[stringnum].string_flags & REPRINT_TEXT)!=0 ) 
				{
				TextCOLOUR = thisMenu->StringLIST[stringnum].string_colour;
				Reprint_string = TRUE;
				}

			if ( Reprint_string==TRUE )
				{
		       	ArrayNumber = thisMenu->StringLIST[stringnum].string_array;	
				TextXposn	= thisMenu->StringLIST[stringnum].string_xposn;
				TextYposn	= thisMenu->StringLIST[stringnum].string_yposn;
				CopyXposn	= thisMenu->StringLIST[stringnum].CopyAreaX;
				CopyYposn	= thisMenu->StringLIST[stringnum].CopyAreaY;
				CopyWIDTH	= thisMenu->StringLIST[stringnum].CopyWidth;
				CopyHEIGHT	= thisMenu->StringLIST[stringnum].CopyHeight;
				RestorePSUDObuffer();
				DisplaySTRING( GetSTRING(thisMenu->StringLIST[stringnum].string_type,ArrayNumber), thisMenu->StringLIST[stringnum].string_shadow);
				Add_to_copy_list(thisMenu->StringLIST[stringnum].CopyAreaX, thisMenu->StringLIST[stringnum].CopyAreaY,
								thisMenu->StringLIST[stringnum].CopyWidth, thisMenu->StringLIST[stringnum].CopyHeight);
				}
			}
		}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_match_info_screen(menu_number)                                                                                           บ
//บ																 บ
//บ																 บ
//บ		Displays teams involved in next game (MENU_A8).                                                                  บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Do_match_info_screen(int menu_number)	
{
menu *thisMenu;
int	stringnum, Reprint_string;

	if ( menu_number==MENU_A8)
		{
		thisMenu = &menu_data[MENU_A8];
		I_Chose_Teams = YES;

		if	( game_data[setup.team_a].player_control != NULL || game_data[setup.team_b].player_control != NULL)
			thisMenu->ButtonLIST[8].button_flags&=	65535-HALF_SPIN;
		else
			thisMenu->ButtonLIST[8].button_flags|=	HALF_SPIN;
 
 		if (match_info.CompetitionType==PRACTICE)
			{
    		game_data[setup.team_a].player_control|=
	    	game_data[setup.team_b].player_control;
    		game_data[setup.team_b].player_control	=	0;
			}

		if (match_info.CompetitionType!=NETWORK) 	// forget players when selecting netgame.............
			{
			if	( batch_info.OldCTRL1!=game_data[setup.team_a].player_control )
				{
				compute_a = TRUE;
				compute_b = TRUE;
				batch_info.OldCTRL1 = game_data[setup.team_a].player_control;
				menu_update = UPDATE_DISPLAY;

				for (int ctrlnum = 0; ctrlnum < 4; ctrlnum++)
					{
					thisMenu->StringLIST[ctrlnum+3].string_type	= control_table[batch_info.OldCTRL1].controlLIST[ctrlnum].control_type;		
					thisMenu->StringLIST[ctrlnum+3].string_array = control_table[batch_info.OldCTRL1].controlLIST[ctrlnum].control_mask;		
					thisMenu->StringLIST[ctrlnum+3].string_yposn = control_table[batch_info.OldCTRL1].controlLIST[ctrlnum].control_yoff+270;		
					thisMenu->StringLIST[ctrlnum+3].BoundingBoxTop = control_table[batch_info.OldCTRL1].controlLIST[ctrlnum].control_yoff+270;		
					thisMenu->StringLIST[ctrlnum+3].BoundingBoxBottom = control_table[batch_info.OldCTRL1].controlLIST[ctrlnum].control_yoff+270+24;		
					}
				}

			if	( batch_info.OldCTRL2!=game_data[setup.team_b].player_control )
				{
				compute_a = TRUE;
				compute_b = TRUE;
				batch_info.OldCTRL2 = game_data[setup.team_b].player_control;
				menu_update = UPDATE_DISPLAY;

				for (int ctrlnum = 0; ctrlnum < 4; ctrlnum++)
					{
					thisMenu->StringLIST[ctrlnum+7].string_type = control_table[batch_info.OldCTRL2].controlLIST[ctrlnum].control_type;
					thisMenu->StringLIST[ctrlnum+7].string_array = control_table[batch_info.OldCTRL2].controlLIST[ctrlnum].control_mask;
					thisMenu->StringLIST[ctrlnum+7].string_yposn = control_table[batch_info.OldCTRL2].controlLIST[ctrlnum].control_yoff+270;
					thisMenu->StringLIST[ctrlnum+7].BoundingBoxTop = control_table[batch_info.OldCTRL2].controlLIST[ctrlnum].control_yoff+270;
					thisMenu->StringLIST[ctrlnum+7].BoundingBoxBottom = control_table[batch_info.OldCTRL2].controlLIST[ctrlnum].control_yoff+270+24;		
					}
				}
	  		}

		for (stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
			{
			Reprint_string = NULL;
			if (match_info.CompetitionType==FRIENDLY)	// || match_info.CompetitionType==NETWORK)
		    	{
				thisMenu->StringLIST[stringnum].string_flags&=	65535-HOVERING_OVER_TEXT;

		       	if ( thisMenu->StringLIST[stringnum].string_type!=NULL
					&& thisMenu->StringLIST[stringnum].string_type!=COMPUTER_TEXT
					 && InBox( &thisMenu->StringLIST[stringnum]))
//					&& ClickXposn > thisMenu->StringLIST[stringnum].BoundingBoxLeft
//			      	 && ClickXposn < thisMenu->StringLIST[stringnum].BoundingBoxRight
//					  && ClickYposn > thisMenu->StringLIST[stringnum].BoundingBoxTop
//					   && ClickYposn < thisMenu->StringLIST[stringnum].BoundingBoxBottom)
					{	
					thisMenu->StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;

					if ((thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)==0)
						{ 
						TextCOLOUR = 175;
						thisMenu->StringLIST[stringnum].string_flags|=	HIGHLIGHTED_TEXT;
						Reprint_string = TRUE;
						}
						
					if ( MouseBUTTONS==LEFT_BUTTON) // || MouseBUTTONS==RIGHT_BUTTON )
						{					
			    		game_data[setup.team_a].player_control ^= thisMenu->StringLIST[stringnum].string_array;	 
			    		game_data[setup.team_b].player_control ^= thisMenu->StringLIST[stringnum].string_array;	 
						MouseDeBOUNCE = TRUE;
						Reprint_string = TRUE;
						}
					}
		    	}

			if ( ((thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)==0 
				&& (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)!=0) || menu_update==UPDATE_DISPLAY)
				{ 
				TextCOLOUR = thisMenu->StringLIST[stringnum].string_colour;
				thisMenu->StringLIST[stringnum].string_flags &= 65535-HIGHLIGHTED_TEXT;
				Reprint_string = TRUE;
				}

			if ( Reprint_string==TRUE || menu_update==UPDATE_DISPLAY)
				{
		       	ArrayNumber = thisMenu->StringLIST[stringnum].string_array;	
				TextXposn = thisMenu->StringLIST[stringnum].string_xposn;
				TextYposn = thisMenu->StringLIST[stringnum].string_yposn;
				CopyXposn = thisMenu->StringLIST[stringnum].CopyAreaX;
				CopyYposn = thisMenu->StringLIST[stringnum].CopyAreaY;
				CopyWIDTH = thisMenu->StringLIST[stringnum].CopyWidth;
				CopyHEIGHT = thisMenu->StringLIST[stringnum].CopyHeight;
				RestorePSUDObuffer();
				if ( thisMenu->StringLIST[stringnum].string_type!=NULL )	
					DisplaySTRING( GetSTRING(thisMenu->StringLIST[stringnum].string_type,ArrayNumber), thisMenu->StringLIST[stringnum].string_shadow);
				Add_to_copy_list(thisMenu->StringLIST[stringnum].CopyAreaX, thisMenu->StringLIST[stringnum].CopyAreaY,
								thisMenu->StringLIST[stringnum].CopyWidth, thisMenu->StringLIST[stringnum].CopyHeight);
				}
			}

		menu_update	=	NULL;
			
		if ( compute_a == TRUE && game_data[setup.team_a].player_control==NULL )
			SortSQUAD(setup.team_a);
		if ( compute_b == TRUE && game_data[setup.team_b].player_control==NULL )
			SortSQUAD(setup.team_b);

		compute_a = FALSE;
		compute_b = FALSE;
		}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_squad_selection(menu_number)                                                                                             บ
//บ																 บ
//บ																 บ
//บ		Allows user to modify squad selection (MENU_A9).                                                                 บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Do_squad_selection(int menu_number)	
{
menu *thisMenu = &menu_data[menu_number];

	if ( menu_number==MENU_A9)
	{
		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	

		int	stringnum, Reprint_string;

//		ColourPOSN(MENU_A9,selected_team);

		for (stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
		{
		
		Reprint_string						  =	NULL;


		thisMenu->StringLIST[stringnum].string_flags&=	65535-HOVERING_OVER_TEXT;

		       	if ( thisMenu->StringLIST[stringnum].string_type!=NULL
				&& InBox( &thisMenu->StringLIST[stringnum]))
//			     && ClickXposn > thisMenu->StringLIST[stringnum].BoundingBoxLeft
//			      && ClickXposn < thisMenu->StringLIST[stringnum].BoundingBoxRight
//			       && ClickYposn > thisMenu->StringLIST[stringnum].BoundingBoxTop
//			        && ClickYposn < thisMenu->StringLIST[stringnum].BoundingBoxBottom)
				 
			{	

			thisMenu->StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;


				if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)!=0 
				     && (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)==0
				      && PaletteFlag<3)
                                      
					{ 

						TextCOLOUR	=	BRIGHT_WHITE;
 					if ( (MarkSquadPlayer-1)==stringnum)
						TextCOLOUR	=	175;



						thisMenu->StringLIST[stringnum].string_flags|=	HIGHLIGHTED_TEXT;
						Reprint_string	=	TRUE;
					}



/*
						if	( (MouseBUTTONS==RIGHT_BUTTON) &&
							 (MarkSquadPlayer==NULL	|| MarkSquadPlayer-1==stringnum))
						{					
						selected_player		= 	stringnum;
						new_menu		= 	MENU_A10;
						PaletteFlag 		= 	PALETTE_FADE_DOWN;
						MarkSquadPlayer		=	NULL;
						thisMenu->StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
						thisMenu->StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;


							if  (MarkSquadPlayer!=NULL)
								thisMenu->StringLIST[MarkSquadPlayer-1].string_flags|= HIGHLIGHTED_TEXT;
					       		
						}

						if	( MouseBUTTONS==RIGHT_BUTTON && (MarkSquadPlayer-1)!=stringnum && MarkSquadPlayer!=NULL)  
						{					
						swap_players(MarkSquadPlayer-1,stringnum);

					thisMenu->StringLIST[MarkSquadPlayer-1].string_flags|= 	HIGHLIGHTED_TEXT;	
					thisMenu->StringLIST[stringnum].string_flags&=		65535-HIGHLIGHTED_TEXT;	

					thisMenu->SpriteTABLE[stringnum].LastSpriteNo		=	STADIUM_IMAGE;
					thisMenu->SpriteTABLE[MarkSquadPlayer-1].LastSpriteNo	=	STADIUM_IMAGE;

						MarkSquadPlayer		= 	NULL;
						MouseDeBOUNCE	 	= 	TRUE;
						Reprint_string		=	TRUE;
						}
*/
						if	( MouseBUTTONS==LEFT_BUTTON)
							{
							if( !MarkSquadPlayer)
								{
								thisMenu->StringLIST[stringnum].string_flags|=		HIGHLIGHTED_TEXT;	
								thisMenu->StringLIST[stringnum].string_flags&=		65535-HOVERING_OVER_TEXT;
								MarkSquadPlayer		= 	stringnum+1;
								Reprint_string		=	TRUE;
								}
							else if ((MarkSquadPlayer-1)!=stringnum)  
								{					
								swap_players(MarkSquadPlayer-1,stringnum);

								thisMenu->StringLIST[MarkSquadPlayer-1].string_flags|= 	HIGHLIGHTED_TEXT;	
								thisMenu->StringLIST[stringnum].string_flags&=		65535-HIGHLIGHTED_TEXT;	

								thisMenu->SpriteTABLE[stringnum].LastSpriteNo		=	STADIUM_IMAGE;
								thisMenu->SpriteTABLE[MarkSquadPlayer-1].LastSpriteNo	=	STADIUM_IMAGE;

								MarkSquadPlayer		= 	NULL;
								Reprint_string		=	TRUE;
								}
							else if( (MarkSquadPlayer-1) == stringnum)
								{
								selected_player		= 	stringnum;
								new_menu			= 	MENU_A10;
								PaletteFlag 		= 	PALETTE_FADE_DOWN;
								thisMenu->StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
								thisMenu->StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;
								thisMenu->StringLIST[stringnum].string_flags|= HIGHLIGHTED_TEXT;
								MarkSquadPlayer		=	NULL;
								}
							MouseDeBOUNCE	 	= 	TRUE;
							}


			}


			if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)==0 
			     && (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)!=0 )

		  	{
				if ( (MarkSquadPlayer-1)==stringnum)
					TextCOLOUR	=	175;	//thisMenu->StringLIST[stringnum].string_mark_colour;
				else
					TextCOLOUR	=	thisMenu->StringLIST[stringnum].string_colour;

				thisMenu->StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
				Reprint_string	=	TRUE;
			}

			if ( menu_update==UPDATE_DISPLAY 
			     && (thisMenu->StringLIST[stringnum].string_flags & REPRINT_TEXT)!=0 ) 
			{
					TextCOLOUR	=	thisMenu->StringLIST[stringnum].string_colour;
					Reprint_string	=	TRUE;
			}


				if ( Reprint_string==TRUE )
				{
		       		ArrayNumber	=	thisMenu->StringLIST[stringnum].string_array;	
				TextXposn	=	thisMenu->StringLIST[stringnum].string_xposn;
				TextYposn	=	thisMenu->StringLIST[stringnum].string_yposn;
				CopyXposn	=	thisMenu->StringLIST[stringnum].CopyAreaX;
				CopyYposn	=	thisMenu->StringLIST[stringnum].CopyAreaY;
				CopyHEIGHT	=	thisMenu->StringLIST[stringnum].CopyHeight;
				CopyWIDTH	=	thisMenu->StringLIST[stringnum].CopyWidth;

			     if ( (thisMenu->StringLIST[stringnum].string_flags & SKIP_PSUDO_RESTORE)==0 ) 
					RestorePSUDObuffer();


	DisplaySTRING( GetSTRING(thisMenu->StringLIST[stringnum].string_type,ArrayNumber),
		        	 thisMenu->StringLIST[stringnum].string_shadow);

					if (CopyWIDTH!=NULL ||
					 (thisMenu->StringLIST[stringnum].string_flags & SKIP_COPY_DOWN)==0)
					{
			Add_to_copy_list(thisMenu->StringLIST[stringnum].CopyAreaX,
                                         thisMenu->StringLIST[stringnum].CopyAreaY,
				         thisMenu->StringLIST[stringnum].CopyWidth,
                                         thisMenu->StringLIST[stringnum].CopyHeight);

					 }

			 	}

		}

	}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  View_auto_selected_team(menu_number)                                                                                        บ
//บ																 บ
//บ																 บ
//บ		Allows user to view an auto-selected team (MENU_A21).                                                            บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	View_auto_selected_team(int menu_number)	
{
menu *thisMenu;

	if ( menu_number==MENU_A21)
	{
		thisMenu = &menu_data[menu_number];

		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	
		int	stringnum, Reprint_string;

		for (stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
		{
		
		Reprint_string						  =	NULL;


		thisMenu->StringLIST[stringnum].string_flags&=	65535-HOVERING_OVER_TEXT;

		       	if ( thisMenu->StringLIST[stringnum].string_type!=NULL
				&& InBox( &thisMenu->StringLIST[stringnum]))
//			     && ClickXposn > thisMenu->StringLIST[stringnum].BoundingBoxLeft
//			      && ClickXposn < thisMenu->StringLIST[stringnum].BoundingBoxRight
//			       && ClickYposn > thisMenu->StringLIST[stringnum].BoundingBoxTop
//			        && ClickYposn < thisMenu->StringLIST[stringnum].BoundingBoxBottom)
				 
			{	

			thisMenu->StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;


				if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)!=0 
				     && (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)==0
				      && PaletteFlag<3)
                                      
					{ 

						TextCOLOUR	=	BRIGHT_WHITE;
						thisMenu->StringLIST[stringnum].string_flags|=	HIGHLIGHTED_TEXT;
						Reprint_string	=	TRUE;
					}



						if	( (MouseBUTTONS==LEFT_BUTTON))	// || MouseBUTTONS==RIGHT_BUTTON) ) 
						{					
						selected_player		= 	stringnum;
						new_menu		= 	MENU_A10;
						PaletteFlag 		= 	PALETTE_FADE_DOWN;
						MarkSquadPlayer		=	NULL;
						thisMenu->StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
						thisMenu->StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;
						}
			}


			if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)==0 
			     && (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)!=0 )

		  	{
				TextCOLOUR	=	thisMenu->StringLIST[stringnum].string_colour;
				thisMenu->StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
				Reprint_string	=	TRUE;
			}

			if ( menu_update==UPDATE_DISPLAY 
			     && (thisMenu->StringLIST[stringnum].string_flags & REPRINT_TEXT)!=0 ) 
			{
					TextCOLOUR	=	thisMenu->StringLIST[stringnum].string_colour;
					Reprint_string	=	TRUE;
			}


				if ( Reprint_string==TRUE )
				{
		       		ArrayNumber	=	thisMenu->StringLIST[stringnum].string_array;	
				TextXposn	=	thisMenu->StringLIST[stringnum].string_xposn;
				TextYposn	=	thisMenu->StringLIST[stringnum].string_yposn;
				CopyXposn	=	thisMenu->StringLIST[stringnum].CopyAreaX;
				CopyYposn	=	thisMenu->StringLIST[stringnum].CopyAreaY;
				CopyHEIGHT	=	thisMenu->StringLIST[stringnum].CopyHeight;
				CopyWIDTH	=	thisMenu->StringLIST[stringnum].CopyWidth;

			     if ( (thisMenu->StringLIST[stringnum].string_flags & SKIP_PSUDO_RESTORE)==0 ) 
					RestorePSUDObuffer();


	DisplaySTRING( GetSTRING(thisMenu->StringLIST[stringnum].string_type,ArrayNumber),
		        	 thisMenu->StringLIST[stringnum].string_shadow);

					if (CopyWIDTH!=NULL ||
					 (thisMenu->StringLIST[stringnum].string_flags & SKIP_COPY_DOWN)==0)
					{
			Add_to_copy_list(thisMenu->StringLIST[stringnum].CopyAreaX,
                                         thisMenu->StringLIST[stringnum].CopyAreaY,
				         thisMenu->StringLIST[stringnum].CopyWidth,
                                         thisMenu->StringLIST[stringnum].CopyHeight);

					 }

			 	}
		}
	}
}



//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_save_load_selection(menu_number)                                                                                         บ
//บ																 บ
//บ																 บ
//บ		Allows user to choose a slot for loading and saving (MENU_A7).                                                   บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Do_save_load_selection(int menu_number)	
{
menu *thisMenu;

	if ( menu_number==MENU_A7 && (MouseFlags & EDIT_TEXT)==0 )
		{
		thisMenu = &menu_data[menu_number];

		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	
		int	stringnum, Reprint_string;

		if ( MarkSlotNumber==NULL || PaletteFlag!=0)
			{
			thisMenu->ButtonLIST[1].button_flags|=	HALF_SPIN;
			thisMenu->ButtonLIST[2].button_flags|=	HALF_SPIN;
			}
		else	
			{
			thisMenu->ButtonLIST[2].button_flags&=	65535-HALF_SPIN;
			SlotNumber	=	MarkSlotNumber-1;
			GetSLOTinfo();

			if ( SlotExists!=NULL) 
				thisMenu->ButtonLIST[1].button_flags&=	65535-HALF_SPIN;
			else
				thisMenu->ButtonLIST[1].button_flags|=	HALF_SPIN;
			}

		for (stringnum = 0; stringnum < 8+1; stringnum++)		// was MAX STRINGS
			{
			Reprint_string = NULL;
			thisMenu->StringLIST[stringnum].string_flags&=	65535-HOVERING_OVER_TEXT;

			if ( thisMenu->StringLIST[stringnum].string_type!=NULL
				&& InBox( &thisMenu->StringLIST[stringnum]))
//				&& ClickXposn > thisMenu->StringLIST[stringnum].BoundingBoxLeft
//				&& ClickXposn < thisMenu->StringLIST[stringnum].BoundingBoxRight
//				&& ClickYposn > thisMenu->StringLIST[stringnum].BoundingBoxTop
//				&& ClickYposn < thisMenu->StringLIST[stringnum].BoundingBoxBottom)
				{	
				thisMenu->StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;

				if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)!=0 
					&& (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)==0
				    && PaletteFlag<3)
				    { 
					TextCOLOUR	=	BRIGHT_WHITE;
 					if ( (MarkSlotNumber-1)==stringnum)
						TextCOLOUR	=	175;
					thisMenu->StringLIST[stringnum].string_flags|=	HIGHLIGHTED_TEXT;
					Reprint_string	=	TRUE;
					}
				if( MouseBUTTONS==LEFT_BUTTON && (MarkSlotNumber-1)!=stringnum)  
					{
					if (stringnum==8)
						{
						EditStringNum	=	stringnum;
						MouseFlags|=EDIT_TEXT;
		       			ArrayNumber	=	NULL;
						TextBuffer   	=	GetSTRING( SLOT_TITLE, NULL );
			     		CursorXposn	=	strlen	(TextBuffer);
						MouseDeBOUNCE	 	= 	TRUE;
						}
					else
						{
						if	( MarkSlotNumber )
							thisMenu->StringLIST[MarkSlotNumber-1].string_flags|=	HIGHLIGHTED_TEXT;
						MarkSlotNumber		= 	stringnum+1;
						thisMenu->StringLIST[stringnum].string_flags|=		HIGHLIGHTED_TEXT;	
						thisMenu->StringLIST[stringnum].string_flags&=		65535-HOVERING_OVER_TEXT;
						MouseDeBOUNCE	 	= 	TRUE;
						Reprint_string		=	TRUE;
						}
					}
				}

			if ( (thisMenu->StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)==0 
				&& (thisMenu->StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)!=0 )
		  		{
				if ( (MarkSlotNumber-1)==stringnum)
					TextCOLOUR	=	175;	//thisMenu->StringLIST[stringnum].string_mark_colour;
				else
					TextCOLOUR	=	thisMenu->StringLIST[stringnum].string_colour;

				thisMenu->StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
				Reprint_string	=	TRUE;
				}

			if ( menu_update==UPDATE_DISPLAY 
				&& (thisMenu->StringLIST[stringnum].string_flags & REPRINT_TEXT)!=0 ) 
				{
				TextCOLOUR	=	thisMenu->StringLIST[stringnum].string_colour;
				Reprint_string	=	TRUE;
				}

			if ( Reprint_string==TRUE )
				{
		    	ArrayNumber	=	thisMenu->StringLIST[stringnum].string_array;	
				TextXposn	=	thisMenu->StringLIST[stringnum].string_xposn;
				TextYposn	=	thisMenu->StringLIST[stringnum].string_yposn;
				CopyXposn	=	thisMenu->StringLIST[stringnum].CopyAreaX;
				CopyYposn	=	thisMenu->StringLIST[stringnum].CopyAreaY;
				CopyHEIGHT	=	thisMenu->StringLIST[stringnum].CopyHeight;
				CopyWIDTH	=	thisMenu->StringLIST[stringnum].CopyWidth;
				
				if ( (thisMenu->StringLIST[stringnum].string_flags & SKIP_PSUDO_RESTORE)==0 ) 
					RestorePSUDObuffer();

				DisplaySTRING( GetSTRING(thisMenu->StringLIST[stringnum].string_type,ArrayNumber), thisMenu->StringLIST[stringnum].string_shadow);

				if (CopyWIDTH!=NULL || (thisMenu->StringLIST[stringnum].string_flags & SKIP_COPY_DOWN)==0)
					{
					Add_to_copy_list(thisMenu->StringLIST[stringnum].CopyAreaX, thisMenu->StringLIST[stringnum].CopyAreaY,
											thisMenu->StringLIST[stringnum].CopyWidth, thisMenu->StringLIST[stringnum].CopyHeight);
					}
				}
			}
		}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_control_selection(menu_number)                                                                                             บ
//บ																 บ
//บ																 บ
//บ		Allows user to modify control methods (MENU_A6).                                                                 บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

#if 0
void	Do_control_selection(int menu_number)	
{
		int	stringnum, Reprint_string;
		char	temp_cntrl;
		int	cntrlx,cntrly;

	cntrlx	=	MouseXposn;



	if (match_info.menu_res==HI)
	{
		cntrly	=	MouseYposn;
		cntrlx	=	MouseXposn;
	}	
	else
	{
		cntrly	=	MouseYposn*2;
		cntrlx	=	MouseXposn*2;
	}



	if ( menu_number==MENU_A6 && calibrate_flag==255 && redefine_flag==255)
		{
		menu_data[MENU_A6].SpriteTABLE[0].sprite_state&=	65535-ACTIVE; 

		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	

		if ( (MarkControlType==NULL || redefine_flag!=255 || calibrate_flag!=255) 
		     || ((MarkControlType-1)>match_info.NoOfPlayers && match_info.CompetitionType!=NETWORK)
		     || (match_info.CompetitionType==NETWORK && MarkControlType-1!= 0)
		) 
			menu_data[MENU_A6].ButtonLIST[0].button_flags|=	HALF_SPIN;

		if ( MarkControlType!=NULL && calibrate_flag==255
		     && ( ((MarkControlType-1)<=match_info.NoOfPlayers && match_info.CompetitionType!=NETWORK)
		     || (match_info.CompetitionType==NETWORK && MarkControlType-1== 0))
				
			 )
			menu_data[MENU_A6].ButtonLIST[0].button_flags&=	65535-HALF_SPIN;







			if (MarkControlType!=0)
			{
				CopyXposn	=	menu_data[MENU_A6].StringLIST[10].CopyAreaX;
				CopyYposn	=	menu_data[MENU_A6].StringLIST[10].CopyAreaY;
				CopyHEIGHT	=	menu_data[MENU_A6].StringLIST[10].CopyHeight;
				CopyWIDTH	=	menu_data[MENU_A6].StringLIST[10].CopyWidth;
				RestorePSUDObuffer();

				{		
					if (CopyWIDTH!=NULL)
						Add_to_copy_list(menu_data[MENU_A6].StringLIST[10].CopyAreaX,
                        		         menu_data[MENU_A6].StringLIST[10].CopyAreaY,
						 menu_data[MENU_A6].StringLIST[10].CopyWidth,
                		                 menu_data[MENU_A6].StringLIST[10].CopyHeight);
				}
			}


		for (stringnum = 0; stringnum < 4; stringnum++)
		{
		
		Reprint_string						  =	NULL;
		menu_data[MENU_A6].StringLIST[stringnum].string_flags&=	65535-HOVERING_OVER_TEXT;

		       	if ( menu_data[MENU_A6].StringLIST[stringnum].string_type!=NULL
				&& InBox( &menu_data[MENU_A6].StringLIST[stringnum]))
//			     && ClickXposn > menu_data[MENU_A6].StringLIST[stringnum].BoundingBoxLeft
//			      && ClickXposn < menu_data[MENU_A6].StringLIST[stringnum].BoundingBoxRight
//			       && ClickYposn > menu_data[MENU_A6].StringLIST[stringnum].BoundingBoxTop
//			        && ClickYposn < menu_data[MENU_A6].StringLIST[stringnum].BoundingBoxBottom)
				 
			{	

			menu_data[MENU_A6].StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;


				if ( (menu_data[MENU_A6].StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)!=0 
				     && (menu_data[MENU_A6].StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)==0
				      && PaletteFlag<3)
                                      
					{ 

						TextCOLOUR	=	BRIGHT_WHITE;
 					if ( (MarkControlType-1)==stringnum)
						TextCOLOUR	=	175;
					menu_data[MENU_A6].StringLIST[stringnum].string_flags|=	HIGHLIGHTED_TEXT;
						Reprint_string	=	TRUE;
					}


			// swaps over control methods
			//		   was  RIGHT

		
			if	( MouseBUTTONS==LEFT_BUTTON && (MarkControlType-1)!=stringnum && MarkControlType!=NULL && CarryControl!=0)  
				{					
				temp_cntrl				=	match_info.control_methods[stringnum];
				match_info.control_methods[stringnum]	=	match_info.control_methods[MarkControlType-1];
				match_info.control_methods[MarkControlType-1]	=	temp_cntrl;;
				thisMenu->StringLIST[MarkControlType-1].string_flags|= 	HIGHLIGHTED_TEXT;	
				thisMenu->StringLIST[stringnum].string_flags&=		65535-HIGHLIGHTED_TEXT;	
				menu_data[MENU_A6].SpriteTABLE[stringnum].LastSpriteNo		=	10;
				menu_data[MENU_A6].SpriteTABLE[MarkControlType-1].LastSpriteNo	=	10;
				MarkControlType		= 	NULL;
				CarryControl		=	NULL;
				MouseDeBOUNCE	 	= 	TRUE;
				Reprint_string		=	TRUE;
				MouseBUTTONS&=			65535-LEFT_BUTTON;
				}

			if	( (MouseBUTTONS==LEFT_BUTTON && CarryControl==1) || MouseBUTTONS==RIGHT_BUTTON)
				{
					MouseDeBOUNCE	 	= 	TRUE;
					Reprint_string		=	TRUE;
					CarryControl		=	0;
					MouseBUTTONS&=			65535-LEFT_BUTTON;
				}		

			if	( MouseBUTTONS==LEFT_BUTTON && CarryControl==0)
				{					
					if	( MarkControlType!=NULL )
						menu_data[MENU_A6].StringLIST[MarkControlType-1].string_flags|=	HIGHLIGHTED_TEXT;

				MarkControlType		= 	stringnum+1;
				menu_data[MENU_A6].StringLIST[stringnum].string_flags|=		HIGHLIGHTED_TEXT;	
				menu_data[MENU_A6].StringLIST[stringnum].string_flags&=		65535-HOVERING_OVER_TEXT;
				MouseDeBOUNCE	 	= 	TRUE;
				Reprint_string		=	TRUE;
				menu_data[MENU_A6].StringLIST[10].string_type	=	CONTROL_STATE;	
				menu_data[MENU_A6].StringLIST[10].string_array	=
					menu_data[MENU_A6].StringLIST[MarkControlType-1].string_array;
				CarryControl		=	1;
				MouseBUTTONS&=			65535-LEFT_BUTTON;
				}


			}

			if ( (MarkControlType-1)==stringnum)
				TextCOLOUR	=	175;
			else
				TextCOLOUR	=	menu_data[MENU_A6].StringLIST[stringnum].string_colour;

			Reprint_string	=	TRUE;
	       		ArrayNumber	=	menu_data[MENU_A6].StringLIST[stringnum].string_array;	
			TextXposn	=	menu_data[MENU_A6].StringLIST[stringnum].string_xposn;
			TextYposn	=	menu_data[MENU_A6].StringLIST[stringnum].string_yposn;
			CopyXposn	=	menu_data[MENU_A6].StringLIST[stringnum].CopyAreaX;
			CopyYposn	=	menu_data[MENU_A6].StringLIST[stringnum].CopyAreaY;
			CopyHEIGHT	=	menu_data[MENU_A6].StringLIST[stringnum].CopyHeight;
			CopyWIDTH	=	menu_data[MENU_A6].StringLIST[stringnum].CopyWidth;
  			RestorePSUDObuffer();

	DisplaySTRING( GetSTRING(menu_data[MENU_A6].StringLIST[stringnum].string_type,ArrayNumber),
		        	 menu_data[MENU_A6].StringLIST[stringnum].string_shadow);

				if (CopyWIDTH!=NULL)
				   {
			Add_to_copy_list(menu_data[MENU_A6].StringLIST[stringnum].CopyAreaX,
                                         menu_data[MENU_A6].StringLIST[stringnum].CopyAreaY,
				         menu_data[MENU_A6].StringLIST[stringnum].CopyWidth,
                                         menu_data[MENU_A6].StringLIST[stringnum].CopyHeight);
				    }


			if (MarkControlType!=0 && 
				CarryControl!=NULL &&
				cntrly > (StatYoff+4+(1*StatYadd)-8) &&
				cntrly < (StatYoff+4+(4*StatYadd)+30) &&
				cntrlx > StatXoff+200 &&
				cntrlx < StatXoff+462
					   )
			{
				menu_data[MENU_A6].StringLIST[10].string_yposn	=
					cntrly;
				menu_data[MENU_A6].StringLIST[10].CopyAreaY	=
					cntrly;

		       		ArrayNumber	=	menu_data[MENU_A6].StringLIST[10].string_array;	
				TextCOLOUR	=	BRIGHT_WHITE;
				TextXposn	=	menu_data[MENU_A6].StringLIST[10].string_xposn;
				TextYposn	=	menu_data[MENU_A6].StringLIST[10].string_yposn;

				DisplaySTRING( GetSTRING(menu_data[MENU_A6].StringLIST[10].string_type,ArrayNumber),
				        	 menu_data[MENU_A6].StringLIST[10].string_shadow);
				Add_to_copy_list(menu_data[MENU_A6].StringLIST[10].string_xposn,
                       		                 menu_data[MENU_A6].StringLIST[10].string_yposn,
					         menu_data[MENU_A6].StringLIST[10].CopyWidth,
               		                         menu_data[MENU_A6].StringLIST[10].CopyHeight);
			}

			else
				CarryControl	=	NULL;


		}

	}
}
#endif



//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Redefine_keyboard(menu_number)                                                                                              บ
//บ																 บ
//บ																 บ
//บ		Requests keyboard entry so user can redefine keys (MENU_A6).                                                     บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

#if 0
static BYTE KeysPressed(BYTE *keys);

static BYTE KeysPressed(BYTE *keys)
{
BYTE *keyMapp;
int keyTemp, keysPressed;
int i;

	GetKeys(keyMap); keyMapp = (BYTE *)&keyMap; keyTemp=0; keysPressed=0;
	for( i=0; i<128; i++) 
	  {
	  if(*keyMapp&0x80)
	    {
	    *keys++ = keyTemp; keysPressed++;
	    }
	  *keyMapp <<= 1; keyTemp++;
	  if( (i&7)==7)
	    keyMapp++;
	  }

	return keysPressed;
}

void	Redefine_keyboard(int menu_number)
{
int		key, chk;
BYTE	keys[16];

	if ( menu_number==MENU_A6 && redefine_flag!=255 )
		{
		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	

		switch(which_key_message)
			{
			case 1:
					TextCOLOUR	=	BRIGHT_CYAN;
	       			ArrayNumber	=	redefine_flag;	
					TextXposn	=	redefine_data[ArrayNumber].string_xposn;
					TextYposn	=	redefine_data[ArrayNumber].string_yposn;
					CopyXposn	=	TextXposn-130;
					CopyYposn	=	TextYposn;
					CopyHEIGHT	=	20;
					CopyWIDTH	=	140;
	 				RestorePSUDObuffer();
					DisplaySTRING( GetSTRING( REQUEST_TEXT, ArrayNumber), SHADOWtextON|SFONT|RIGHTjustifyTEXT);
					Add_to_copy_list(CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
					which_key_message = 2;
					break;

			case 2:
			case 4:
					if(!KeysPressed(keys))
						which_key_message++;
					break;

			case 3:
					key = KeysPressed(keys);
					if(!key)
						break;
#if TWOKEY==YES
					for (chk=0; chk<12; chk++)
#else
					for (chk=0; chk<6; chk++)
#endif
						if(batch_info.keys_used[chk]==keys[0] || !LegalKEY[keys[0]])
							key=2;
					if(key==1)
						{
						key = keys[0];
						ArrayNumber	=	redefine_flag;	
				 		TextCOLOUR	=	BRIGHT_GREEN;
						TextXposn	=	redefine_data[ArrayNumber].string_xposn+8;
						TextYposn	=	redefine_data[ArrayNumber].string_yposn;
						CopyXposn	=	TextXposn-1;
						CopyYposn	=	TextYposn;
						CopyHEIGHT	=	20;
						CopyWIDTH	=	116+8;
			 			RestorePSUDObuffer();
						DisplaySTRING( GetSTRING( CHOSEN_KEY, key), SHADOWtextON|SFONT);
						Add_to_copy_list(CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
						batch_info.keys_used[ ((match_info.control_methods[MarkControlType-1]*6)+redefine_flag)] = key;
						which_key_message ++;
						}
					break;

			case 5:
					which_key_message = 1;
					redefine_flag++;
					if(redefine_flag>5)
						{
						which_key_message = 0;
						CopyXposn = redefine_data[0].string_xposn-130;
						CopyYposn = redefine_data[0].string_yposn;
						CopyHEIGHT = 70;
						CopyWIDTH = 588;
						RestorePSUDObuffer();
						redefine_flag = 255;
						reprint_redefine_message = 1;
						menu_data[MENU_A6].StringLIST[MarkControlType].string_flags |= HIGHLIGHTED_TEXT;
						menu_data[MENU_A6].StringLIST[MarkControlType].string_flags &= 65535-HOVERING_OVER_TEXT;
						MarkControlType = 0;
						MouseFlags &= 65535-MOUSE_OFF;
						Add_to_copy_list(CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
						}
					break;
			}

		if ( reprint_redefine_message!=NULL )
			{
		 	TextCOLOUR	=	menu_data[MENU_A6].StringLIST[9].string_colour;
	   		ArrayNumber	=	menu_data[MENU_A6].StringLIST[9].string_array;	
			TextXposn	=	menu_data[MENU_A6].StringLIST[9].string_xposn;
			TextYposn	=	menu_data[MENU_A6].StringLIST[9].string_yposn;
			CopyXposn	=	menu_data[MENU_A6].StringLIST[9].CopyAreaX;
			CopyYposn	=	menu_data[MENU_A6].StringLIST[9].CopyAreaY;
			CopyHEIGHT	=	menu_data[MENU_A6].StringLIST[9].CopyHeight;
			CopyWIDTH	=	menu_data[MENU_A6].StringLIST[9].CopyWidth;
	 		RestorePSUDObuffer();
			DisplaySTRING( GetSTRING(menu_data[MENU_A6].StringLIST[9].string_type,ArrayNumber), menu_data[MENU_A6].StringLIST[9].string_shadow);
			Add_to_copy_list(menu_data[MENU_A6].StringLIST[9].CopyAreaX, menu_data[MENU_A6].StringLIST[9].CopyAreaY,
							 menu_data[MENU_A6].StringLIST[9].CopyWidth, menu_data[MENU_A6].StringLIST[9].CopyHeight);
			reprint_redefine_message	=	NULL;
			}
		}
}
#endif

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Calibrate_joystick(menu_number)                                                                                             บ
//บ																 บ
//บ																 บ
//บ		Requests joystick movement so that calibrations can be made (MENU_A6).                                           บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

#if 0
void	Calibrate_joystick(int menu_number)
{
int	stringnum, Reprint_string;

	if ( menu_number==MENU_A6 && calibrate_flag!=255 )
	{
			menu_data[MENU_A6].SpriteTABLE[0].sprite_state|=	ACTIVE; 

		if ( match_info.control_methods[MarkControlType-1] == JOYSTICK1 )
			{
//			x1ok 	  = 1;	
//			y1ok 	  = 2;	
//			bitaccept = x1ok+y1ok;
			CalibrateJoy(0);

				if (x1ok!=0 && y1ok!=0)
					cal0	=	1;
				if (x1ok==0 || y1ok==0)
					cal0	=	NULL;
				
			}		
		if ( match_info.control_methods[MarkControlType-1] == JOYSTICK2 )
			{
//			x2ok 	  = 4;	
//			y2ok 	  = 8;	
//			bitaccept = x2ok+y2ok;
			CalibrateJoy(1);
				if (x2ok!=0 && y2ok!=0)
					cal1	=	1;
				if (x2ok==0 || y2ok==0)
					cal1	=	NULL;
				
			}
#if TWOKEY==NO
		if ( match_info.control_methods[MarkControlType-1] == JOYSTICK3 )
			{
//			x2ok 	  = 4;	
//			y2ok 	  = 8;	
//			bitaccept = x2ok+y2ok;
			CalibrateJoy(2);
				if (x2ok!=0 && y2ok!=0)
					cal1	=	1;
				if (x2ok==0 || y2ok==0)
					cal1	=	NULL;
				
			}
#endif

		if ( print_joy_message!=NULL )
			{
		 	TextCOLOUR	=	menu_data[MENU_A6].StringLIST[8].string_colour;
	       		ArrayNumber	=	menu_data[MENU_A6].StringLIST[8].string_array;	
			TextXposn	=	menu_data[MENU_A6].StringLIST[8].string_xposn;
			TextYposn	=	menu_data[MENU_A6].StringLIST[8].string_yposn;
			CopyXposn	=	menu_data[MENU_A6].StringLIST[8].CopyAreaX;
			CopyYposn	=	menu_data[MENU_A6].StringLIST[8].CopyAreaY;
			CopyHEIGHT	=	menu_data[MENU_A6].StringLIST[8].CopyHeight;
			CopyWIDTH	=	menu_data[MENU_A6].StringLIST[8].CopyWidth;
	 		RestorePSUDObuffer();

			DisplaySTRING( GetSTRING(menu_data[MENU_A6].StringLIST[8].string_type,ArrayNumber),
				        	 menu_data[MENU_A6].StringLIST[8].string_shadow);

			Add_to_copy_list(menu_data[MENU_A6].StringLIST[8].CopyAreaX,
                                         menu_data[MENU_A6].StringLIST[8].CopyAreaY,
				         menu_data[MENU_A6].StringLIST[8].CopyWidth,
                                         menu_data[MENU_A6].StringLIST[8].CopyHeight);

			print_joy_message	=	NULL;
			}
		}

		if (calibrate_flag==8)
		{
			calibrate_flag		=	255;
			menu_data[MENU_A6].StringLIST[MarkControlType-1].string_flags|=		HIGHLIGHTED_TEXT;	
			menu_data[MENU_A6].StringLIST[MarkControlType-1].string_flags&=		65535-HOVERING_OVER_TEXT;
			MarkControlType		=	0;
			MouseFlags&=	65535-MOUSE_OFF;
		}
}
#endif

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  View_player_stats(menu_number)                                                                                              บ
//บ																 บ
//บ																 บ
//บ		Allows user to view individual players statistics (MENU_A10).                                                    บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	View_player_statistics(int menu_number)
{
int change_stat;
menu *thisMenu;

	if ( menu_number==MENU_A10 )
		{
		thisMenu = &menu_data[menu_number];

		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	

		for (int stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
			{
			if (ClickXposn > thisMenu->StringLIST[stringnum].BoundingBoxLeft
				&& ClickXposn < thisMenu->StringLIST[stringnum].BoundingBoxRight
				&& ClickYposn > thisMenu->StringLIST[stringnum].BoundingBoxTop
				&& ClickYposn < thisMenu->StringLIST[stringnum].BoundingBoxBottom
				&& MouseBUTTONS!=0 && menu_update!=UPDATE_DISPLAY
				&& batch_info.cheat_mode == true)
				{
				change_stat	= ( ((ClickXposn-164 )/19)*5)+5 ;
				if (change_stat>100)
					change_stat	=	100;
				if (thisMenu->StringLIST[stringnum].stat_array == FLAIR)
					game_data[selected_team].players[selected_player].flair = change_stat;
				if (thisMenu->StringLIST[stringnum].stat_array == ACCURACY)
					game_data[selected_team].players[selected_player].accuracy = change_stat;
				if (thisMenu->StringLIST[stringnum].stat_array == CONTROL)
					game_data[selected_team].players[selected_player].control = change_stat;
				if (thisMenu->StringLIST[stringnum].stat_array == PACE)
					game_data[selected_team].players[selected_player].pace = change_stat;
				if (menu_data[MENU_A10].StringLIST[stringnum].stat_array == VISION)
					game_data[selected_team].players[selected_player].vision = change_stat;
				if (thisMenu->StringLIST[stringnum].stat_array == POWER)
					game_data[selected_team].players[selected_player].power = change_stat;
				if (thisMenu->StringLIST[stringnum].stat_array == STAMINA)
					game_data[selected_team].players[selected_player].stamina = change_stat;
				if (thisMenu->StringLIST[stringnum].stat_array == DISCIPLINE)
					game_data[selected_team].players[selected_player].discipline = change_stat;
				menu_update = UPDATE_DISPLAY;
				}
			if ( menu_update==UPDATE_DISPLAY && (thisMenu->StringLIST[stringnum].string_flags & REPRINT_TEXT)!=0 ) 
				{
				TextCOLOUR	=	thisMenu->StringLIST[stringnum].string_colour;
	       		ArrayNumber	=	thisMenu->StringLIST[stringnum].string_array;	
				TextXposn	=	thisMenu->StringLIST[stringnum].string_xposn;
				TextYposn	=	thisMenu->StringLIST[stringnum].string_yposn;
				CopyXposn	=	thisMenu->StringLIST[stringnum].CopyAreaX;
				CopyYposn	=	thisMenu->StringLIST[stringnum].CopyAreaY;
				CopyHEIGHT	=	thisMenu->StringLIST[stringnum].CopyHeight;
				CopyWIDTH	=	thisMenu->StringLIST[stringnum].CopyWidth;
				RestorePSUDObuffer();

				if (thisMenu->StringLIST[stringnum].string_type==PLAYER_STAT)
					{
					int	StatTYPE	=	thisMenu->StringLIST[stringnum].stat_array;	
					DisplaySTARstats( GetSTATvalue(thisMenu->StringLIST[stringnum].string_type,ArrayNumber,StatTYPE) );
					}
				else
					DisplaySTRING( GetSTRING(thisMenu->StringLIST[stringnum].string_type,ArrayNumber), thisMenu->StringLIST[stringnum].string_shadow);

				Add_to_copy_list(thisMenu->StringLIST[stringnum].CopyAreaX,
								 thisMenu->StringLIST[stringnum].CopyAreaY,
								 thisMenu->StringLIST[stringnum].CopyWidth,
								 thisMenu->StringLIST[stringnum].CopyHeight);
			 	}
			}
		}
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  View_match_setup(menu_number)                                                                                               บ
//บ																 บ
//บ																 บ
//บ		Allows user to view match setup options (MENU_A4).                                                               บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	View_match_setup(int menu_number)
{
menu *thisMenu;

	if ( menu_number==MENU_A4 )
		{
		thisMenu = &menu_data[menu_number];

		ref_vision += ref_vision_add;
		ref_disc += ref_disc_add;

		if ( ref_vision<1 || ref_vision>98)
			ref_vision_add *= -1;
		if ( ref_disc<1 || ref_disc>98)
			ref_disc_add *= -1;

		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	

		for (int stringnum = 0; stringnum < MAX_STRINGS; stringnum++)
			{
			if ( (menu_update==UPDATE_DISPLAY && (thisMenu->StringLIST[stringnum].string_flags & REPRINT_TEXT)!=0) 
			     || ( match_info.referee > (15+16) && stringnum==2 ) || ( match_info.referee > (15+16) && stringnum==3 )	)
				{
				TextCOLOUR	=	thisMenu->StringLIST[stringnum].string_colour;
		       	ArrayNumber	=	thisMenu->StringLIST[stringnum].string_array;	
				TextXposn	=	thisMenu->StringLIST[stringnum].string_xposn;
				TextYposn	=	thisMenu->StringLIST[stringnum].string_yposn;
				CopyXposn	=	thisMenu->StringLIST[stringnum].CopyAreaX;
				CopyYposn	=	thisMenu->StringLIST[stringnum].CopyAreaY;
				CopyHEIGHT	=	thisMenu->StringLIST[stringnum].CopyHeight;
				CopyWIDTH	=	thisMenu->StringLIST[stringnum].CopyWidth;
				RestorePSUDObuffer();

				if (thisMenu->StringLIST[stringnum].string_type==PLAYER_STAT)
					{
					int	StatTYPE	=	thisMenu->StringLIST[stringnum].stat_array;	
					DisplaySTARstats( GetSTATvalue(thisMenu->StringLIST[stringnum].string_type,ArrayNumber,StatTYPE) );
					}
				else
					DisplaySTRING( GetSTRING(thisMenu->StringLIST[stringnum].string_type,ArrayNumber),
								        	 thisMenu->StringLIST[stringnum].string_shadow);

					Add_to_copy_list(thisMenu->StringLIST[stringnum].CopyAreaX,
            			             thisMenu->StringLIST[stringnum].CopyAreaY,
				        			 thisMenu->StringLIST[stringnum].CopyWidth,
                         			 thisMenu->StringLIST[stringnum].CopyHeight);
				}
			}
		}

}








//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_net_player_selection(menu_number)                                                                                        บ
//บ																 บ
//บ																 บ
//บ		Allows network user to select which player they wish to control (MENU_A18).                                      บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

void	Do_net_player_selection(int menu_number)	
{
char	NumberBUFFER[5];
char	auto1,auto2;
int		i;		

	if ( menu_number==MENU_A18 )
	{
		DisplaySOURCE			=	background_buffer;	
		DisplayDESTINATION		=	psudo_buffer;	
		int	stringnum, Reprint_string;
		int	firstsend = OFF;

		

			if ( MarkSquadPlayer==255 )
			{
			menu_data[MENU_A18].ButtonLIST[0].button_flags|= HALF_SPIN;
			menu_data[MENU_A18].ButtonLIST[0].button_index = 8;
			}

		for (stringnum = 0; stringnum < 22; stringnum++)
		{menu_data[MENU_A18].StringLIST[stringnum].string_flags&=	65535-NET_FLAG;}

		auto1	=	0;
		auto2	=	0;
	
		for (int i=0;i<network_on;i++)
		{
			if	(NetTeams[i]!=-1)
			{
				stringnum	=	(  ( (NetTeams[i] & 1)*11)+Players[i])-1;
				
				if (stringnum==0)
					auto1++;
				if (stringnum==11)
					auto2++;

				if (stringnum!=0 && stringnum!=11)
					menu_data[MENU_A18].StringLIST[stringnum].string_flags|=	NET_FLAG;

				if ( (stringnum==0 && auto1>1) || (stringnum==11 && auto2>1) )
					menu_data[MENU_A18].StringLIST[stringnum].string_flags|=	NET_FLAG;
				



			}		
		}

		for (stringnum = 0; stringnum < 22; stringnum++)
			{
			Reprint_string = NULL;
			menu_data[MENU_A18].StringLIST[stringnum].string_flags&=	65535-HOVERING_OVER_TEXT;

		    if ( menu_data[MENU_A18].StringLIST[stringnum].string_type!=NULL
				&& InBox( &menu_data[MENU_A18].StringLIST[stringnum]))
//			     && ClickXposn > menu_data[MENU_A18].StringLIST[stringnum].BoundingBoxLeft
//			      && ClickXposn < menu_data[MENU_A18].StringLIST[stringnum].BoundingBoxRight
//			       && ClickYposn > menu_data[MENU_A18].StringLIST[stringnum].BoundingBoxTop
//			        && ClickYposn < menu_data[MENU_A18].StringLIST[stringnum].BoundingBoxBottom)
				 
				{	
				// HIGHTLIGHT PLAYER WHEN MOUSE CURSOR IS OVER THERE NAME....
				if	(NetworkType_toggle==0)
					menu_data[MENU_A18].StringLIST[stringnum].string_flags|=	HOVERING_OVER_TEXT;

				if ( (menu_data[MENU_A18].StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)!=0 
				     && (menu_data[MENU_A18].StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)==0
				      && (menu_data[MENU_A18].StringLIST[stringnum].string_flags & NET_FLAG)==0 
				       && PaletteFlag<3)
				       { 
						if ( (MarkSquadPlayer-1)==stringnum)
							TextCOLOUR = 175;
						else
							TextCOLOUR = BRIGHT_WHITE;

						menu_data[MENU_A18].StringLIST[stringnum].string_flags|=	HIGHLIGHTED_TEXT;
						Reprint_string	=	TRUE;
						}
				if	( MouseBUTTONS==LEFT_BUTTON && (MarkSquadPlayer-1)!=stringnum && 
					((menu_data[MENU_A18].StringLIST[stringnum].string_flags & NET_FLAG)==0) && 
					NetworkType_toggle==0 && network_on>1)
					{					
					if	( MarkSquadPlayer!=NULL )
						menu_data[MENU_A18].StringLIST[MarkSquadPlayer-1].string_flags|=	HIGHLIGHTED_TEXT;
					MarkSquadPlayer = stringnum+1;
					menu_data[MENU_A18].StringLIST[stringnum].string_flags|= HIGHLIGHTED_TEXT;	
					menu_data[MENU_A18].StringLIST[stringnum].string_flags&= 65535-HOVERING_OVER_TEXT;
					menu_data[MENU_A18].ButtonLIST[0].button_flags&=	 65535-HALF_SPIN;
					MouseDeBOUNCE = TRUE;
					Reprint_string = TRUE;

	 				if (firstsend == OFF)
						{
				     	if (stringnum>10)
							{
							TeamChoice = 1;
							PlayerChoice = stringnum-10;
							}
						else
							{
							TeamChoice = 0;
							PlayerChoice = stringnum+1;
							}
						SendPlayerChoice();
						TickerPause();
						firstsend = ON;
						}
					}
				}


			if ( ( (menu_data[MENU_A18].StringLIST[stringnum].string_flags & HOVERING_OVER_TEXT)==0 
			     && (menu_data[MENU_A18].StringLIST[stringnum].string_flags & HIGHLIGHTED_TEXT)!=0)

			     || ( (menu_data[MENU_A18].StringLIST[stringnum].string_flags & NET_FLAG)!=0 
				  && (menu_data[MENU_A18].StringLIST[stringnum].string_flags & TOGGLE_FLAG)==0)
		
			     || ( (menu_data[MENU_A18].StringLIST[stringnum].string_flags & NET_FLAG)==0 
				  && (menu_data[MENU_A18].StringLIST[stringnum].string_flags & TOGGLE_FLAG)!=0)
				 )



		  	{
				if ( (MarkSquadPlayer-1)==stringnum)
				{
					TextCOLOUR	=	175;	//menu_data[MENU_A18].StringLIST[stringnum].string_mark_colour;
					menu_data[MENU_A18].StringLIST[stringnum].string_flags|=	TOGGLE_FLAG;
				}


				else
				{
				 	if	( (menu_data[MENU_A18].StringLIST[stringnum].string_flags & NET_FLAG)!=0) 
						{
						TextCOLOUR	=	menu_data[MENU_A18].StringLIST[stringnum].string_mark_colour;
						menu_data[MENU_A18].StringLIST[stringnum].string_flags|=	TOGGLE_FLAG;
						}
				      	else
						{
						TextCOLOUR	=	menu_data[MENU_A18].StringLIST[stringnum].string_colour;
						menu_data[MENU_A18].StringLIST[stringnum].string_flags&=	65535-TOGGLE_FLAG;
						}
				}

				menu_data[MENU_A18].StringLIST[stringnum].string_flags&=	65535-HIGHLIGHTED_TEXT;
				Reprint_string	=	TRUE;
			}


				if ( Reprint_string==TRUE )
				{
		       		ArrayNumber	=	menu_data[MENU_A18].StringLIST[stringnum].string_array;	
				TextXposn	=	menu_data[MENU_A18].StringLIST[stringnum].string_xposn;
				TextYposn	=	menu_data[MENU_A18].StringLIST[stringnum].string_yposn;
				CopyXposn	=	menu_data[MENU_A18].StringLIST[stringnum].CopyAreaX;
				CopyYposn	=	menu_data[MENU_A18].StringLIST[stringnum].CopyAreaY;
				CopyHEIGHT	=	menu_data[MENU_A18].StringLIST[stringnum].CopyHeight;
				CopyWIDTH	=	menu_data[MENU_A18].StringLIST[stringnum].CopyWidth;

			     if ( (menu_data[MENU_A18].StringLIST[stringnum].string_flags & SKIP_PSUDO_RESTORE)==0 ) 
					RestorePSUDObuffer();

	DisplaySTRING( GetSTRING(menu_data[MENU_A18].StringLIST[stringnum].string_type,ArrayNumber),
		        	 menu_data[MENU_A18].StringLIST[stringnum].string_shadow);

					if (CopyWIDTH!=NULL ||
					 (menu_data[MENU_A18].StringLIST[stringnum].string_flags & SKIP_COPY_DOWN)==0)
					{
			Add_to_copy_list(menu_data[MENU_A18].StringLIST[stringnum].CopyAreaX,
                                         menu_data[MENU_A18].StringLIST[stringnum].CopyAreaY,
				         menu_data[MENU_A18].StringLIST[stringnum].CopyWidth,
                                         menu_data[MENU_A18].StringLIST[stringnum].CopyHeight);

					 }
			 	}
		}



		if 	(new_menu!=PLAY_MATCH)
		{	

			ItalicFont   	=	0;
			FontDataADDR 	=	sfont_buffer;	
			CopyXposn	=	(320+(
						( FindLengthOfSTRING( GetSTRING(NO_NET_PLAYS_TEXT, 0),
						NULL, SHADOWtextON|CENTREjustifyTEXT|SFONT) ) /2))+8;
			TextXposn	=	CopyXposn;  
			CopyYposn	=	A09yPOS+14+(13*A09yOFFSET);
			TextYposn	=	CopyYposn;  
			CopyWIDTH	=	48;	
			CopyHEIGHT	=	28;
			RestorePSUDObuffer();

			TextCOLOUR	=	BRIGHT_YELLOW;
			itoa	( network_on, NumberBUFFER, 10 );			
			DisplaySTRING( NumberBUFFER, SHADOWtextON|SFONT );

			Add_to_copy_list(CopyXposn, A09yPOS+14+(13*A09yOFFSET), 48, 28);

			Starts	=	0;

				for ( i=0; i < network_on; i++ )
				{
					if (NetTeams[i] >= 2)
						 Starts++;
				} 

			CopyXposn	=	320+ ((FindLengthOfSTRING(
						GetSTRING(CHOOSE_TEXT, 0), NULL,
						SHADOWtextON|CENTREjustifyTEXT|SFONT ))/2)+8;
			CopyYposn	=	A09yPOS+32+(13*A09yOFFSET);
			CopyWIDTH	=	48;	
			CopyHEIGHT	=	28;
			RestorePSUDObuffer();

			TextXposn	=	CopyXposn;  
			TextYposn	=	CopyYposn;  
			TextCOLOUR	=	BRIGHT_GREEN;
			itoa	( (network_on-Starts), NumberBUFFER, 10);			
			DisplaySTRING( NumberBUFFER, SHADOWtextON|SFONT );
			Add_to_copy_list(CopyXposn, A09yPOS+32+(13*A09yOFFSET), 40, 28);
		}

	}
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Do_juggling_man(menu_number)                                                                                                บ
//บ																 บ
//บ																 บ
//บ		Displays juggling man (MENU_A0).                                                                                 บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Do_juggling_man(int menu_number)	
{
float	an = angle;

	DisplaySOURCE		= background_buffer;	
	DisplayDESTINATION	= psudo_buffer;	

	if(!DrawMan)
		{
		switch(menu_number)
			{
			case(MENU_A0):
					CopyXposn		= 185;
					CopyWIDTH		= 150;
					CopyYposn		= 84;
					CopyHEIGHT		= 214;
					mbuff.buff_start= (BYTE *)psudo_buffer-4-60;
					break;
			case(MENU_A17):
				 	CopyXposn		= 430;
				 	CopyWIDTH		= 164;
					CopyYposn		= 100;
					CopyHEIGHT		= 240;
					mbuff.buff_start= (BYTE *)psudo_buffer-4-190+400+(40*640);	
					break;
			case(MENU_A19):
					CopyXposn		= 42;
				 	CopyWIDTH		= 164;
					CopyYposn		= 85;
					CopyHEIGHT		= 230;
					mbuff.buff_start= (BYTE *)psudo_buffer-4-60-128+(24*640);	
					an += .75;
					break;
			default:
					return;
			}
			
//		if( flag)
			{
			if ( (anim+=(1./300)) >= 1 )
				anim-=	1;
			RestorePSUDObuffer();
			drawman(&mbuff, anim, an, 82);
			Add_to_copy_list(CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
			}
//		flag = !flag;
		}
}
// while (!(keyMap[1]&0x00002000));
//	while ((keyMap[1]&0x00002000)) GetKeys(keyMap);

void	check_for_tga()
{
	if ( bGameOver && (current_menu==MENU_A18 || current_menu==MENU_A8) && (match_info.CompetitionType== NETWORK) )
  		{
  		Quit_Network_Play();
		new_menu = MENU_A0;
  		}

	if (!OldKEY)
		{
		if ((keyMap[1]&0x00002000))
			{
			OldKEY	=	1;
			Button_pressed	=	NULL;
			spin_button	=	NULL;
			if (ESCkey[current_menu]==-1 && match_info.CompetitionType!=NETWORK && 1 && current_menu!=MENU_A0) 
				Button_pressed = GOTO_START;

			if ( ESCkey[current_menu]!=-1 )
				Button_pressed = ESCkey[current_menu];

			if ( current_menu==MENU_A8 && (match_info.CompetitionType== NETWORK))
				{
//				Quit_Network_Play();
				Button_pressed = GOTO_START;
				}

			if ( ESCkey[current_menu]==-1 && current_menu==MENU_A18 && (match_info.CompetitionType== NETWORK) )
		  		{
		  		Quit_Network_Play();
		  		Button_pressed = GOTO_START;
		  		}

			if (Button_pressed==GOTO_START && tune==0)
				StopMusic();
	    	}
	  	}
	
	if (OldKEY)
		{
		if (!(keyMap[1]&0x00002000))
	    	OldKEY	=	0;
		}
 #if 0
 	if ( keys[15]==NULL )
		lastTGAstate	=	NULL;

	// Only if 'Making of' GDV is to be played

 	if	(match_info.tga_enable!=TRUE && lastTGAstate==NULL && GDVavailable!=NULL && current_menu==MENU_A0 &&
		(match_info.language==English || match_info.language==French || match_info.language==Norwegian) && 1)

 	{
	 	if ( keys[15]!=NULL)
		{
		GDVtimer	=	DEMO_TIME;
		PaletteFlag 	= 	PALETTE_FADE_DOWN;
		Button_pressed	=	NULL;
		OverFlowFlag 	= 	FALSE;
 		new_menu 	= 	PLAY_GDV;
			lastTGAstate	=	TRUE;      
		}
	}

 	if	(match_info.tga_enable==TRUE)
 	{
	 	if ( keys[15]!=NULL && lastTGAstate==NULL )
		{
 			WriteTGAfile();
			lastTGAstate	=	TRUE;      
		}
	}
#endif

}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  GetWinningLeagueTeam()                                                                                                      บ
//บ																 บ
//บ		Returns team number for winning league team.                                                                     บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
int	GetWinningLeagueTeam()
{
	int winning_team	=	NULL;
	for (int team=0; team < MAX_TEAMS-1; team++)
	{
		if ( ((game_data[team].division*16)+game_data[team].position)==(DIV1*16)+POS01 )
			winning_team	=	team;
	}
	return (winning_team);
}

#ifdef WHEEL
//ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//บ
//บ  Do_number_input(int menu_number)
//บ
//บ		Allows user to input protection wheel number.
//บ
//ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
void	Do_number_input(int menu_number)
{
char key[1];
int	reprint_string	=	NULL;
char	code_number;
int	wheel_posn;

	if	( (MouseFlags & ENTER_NUMBER)!=0 && menu_number==MENU_A24 && 0 && match_info.language==English)
	{		
		TextCOLOUR	=	BRIGHT_WHITE;
		TextBuffer   	=	GetSTRING(menu_data[MENU_A24].StringLIST[0].string_type, 0);

		if (kbhit)
		{
		key[0] = Getchar();
//			if ( (key[0] = getch()) == 0)
//				key[1] = getch();

	     		int  SngLen	=	strlen	(TextBuffer);

			  	if (key[0]!=0)
			  	{			
		
			  		if ( SngLen>=1 && key[0]==8 && CursorXposn>0 )
			  		{

			  		int	SngCnt		=	CursorXposn;

			  			while	(SngCnt<2) 
			  			{
			  			TextBuffer[SngCnt-1]	=	TextBuffer[SngCnt];
			  			SngCnt++;
						reprint_string		=	ON;
			  			}
			  		TextBuffer[SngCnt-1]	=	0;
			  		CursorXposn--;
			  		}

			  		if (key[0]>=48 && key[0]<=57 
                                            && SngLen<2
                                             && (FindLengthOfSTRING( TextBuffer, key[0], NULL )) < 64
				  	      )

				     	if (key[0]<91 || key[0]>96)
			  		{
							
			  		TextBuffer[SngLen+1]	=	0;
			  		int	SngCnt		=	SngLen;

			  			while	(SngCnt>CursorXposn || SngCnt==0) 
			  			{									  
			  			TextBuffer[SngCnt]	=	TextBuffer[SngCnt-1];
			  			SngCnt--;
						reprint_string		=	ON;
			  	       		}
	
		  		 	TextBuffer[CursorXposn]	=	key[0];

						if (CursorXposn==SngLen)
							{
					     		CursorXposn	=	strlen	(TextBuffer);
							reprint_string		=	ON;
							}
						else
							{
					     		CursorXposn++;
							reprint_string		=	ON;
							}
					}		
			
					if (key[0]==13)
					{
						MouseFlags&= 65535-ENTER_NUMBER;
						key_debounce|=	TRUE;
						code_number	=	0;

						if (TextBuffer[0]>47 &&	TextBuffer[0]<58 && (TextBuffer[1]<48 || TextBuffer[1]>57) )
							code_number	=	( TextBuffer[0]-48 );			    			
						if (TextBuffer[0]>47 &&	TextBuffer[0]<58 && TextBuffer[1]>47 && TextBuffer[1]<58 )
							code_number	=	(((TextBuffer[0]-48)*10) + (TextBuffer[1]-48) );			    			
						wheel_posn	=  	(5*CodeWheelWindows[WindowNumber]) + 
									CodeWheelWindowsOffs[WindowNumber]; 						
						wheel_posn+=	5*(16-(WheelInner+WheelOuter) );

					if ( CodeWheelNumbers[wheel_posn]==code_number )
						{
						GDVtimer	= DEMO_TIME;
						new_menu	= MENU_A0;
						PaletteFlag 	= PALETTE_FADE_DOWN;
				     		MouseDeBOUNCE 	= TRUE;
						MouseFlags&=	65535-MOUSE_OFF-ENTER_NUMBER;
						reset_scores();
						reset_net_variables();
						reset_league_teams(); 
						Setup_cup_teams(batch_info.number_of_cup_teams);
						InitialiseMan	=	GRM;
						InitialiseFlag	=	0;
						}

						else

						{
							InitialiseCodeWheel();
							MouseFlags|=		MOUSE_OFF;
							MouseFlags|=		ENTER_NUMBER;
							new_menu	= 	MENU_A24;
							rerun_menu	=	1;
							PaletteFlag 	= 	PALETTE_FADE_DOWN;
							TextBuffer[0]	=	NULL;
						}							

					}
	  			}
					if (key[0]==0)
					{			
				       		if (key[1]==0x4B && CursorXposn>0)
							{
					       		CursorXposn--;
							reprint_string		=	ON;
							}
						if (key[1]==0x4D && CursorXposn<SngLen)
							{
							CursorXposn++;
							reprint_string		=	ON;
							}
					}

		}

		{

		TextXposn	=	menu_data[MENU_A24].StringLIST[0].string_xposn;
		TextYposn	=	menu_data[MENU_A24].StringLIST[0].string_yposn;
  	      	menu_data[MENU_A24].StringLIST[0].string_flags	=
			menu_data[MENU_A24].StringLIST[0].string_flags | HIGHLIGHTED_TEXT;	
		CopyXposn	=	menu_data[MENU_A24].StringLIST[0].CopyAreaX;
		CopyYposn	=	menu_data[MENU_A24].StringLIST[0].CopyAreaY;
		CopyWIDTH	=	menu_data[MENU_A24].StringLIST[0].CopyWidth;
		CopyHEIGHT	=	menu_data[MENU_A24].StringLIST[0].CopyHeight;
	
		RestorePSUDObuffer();

	CursorXdisplay	= DisplaySTRING( GetSTRING(menu_data[MENU_A24].StringLIST[0].string_type, 0),
	        	 menu_data[MENU_A24].StringLIST[0].string_shadow);

		if	( (MouseFlags & ENTER_NUMBER)!=0 && (pulsating_colour & 8) !=0 )
			{
			TextXposn	=	CursorXdisplay;
			DisplaySTRING("[",menu_data[MENU_A24].StringLIST[0].string_shadow);		
			}

		Add_to_copy_list(
			menu_data[MENU_A24].StringLIST[0].CopyAreaX,
			menu_data[MENU_A24].StringLIST[0].CopyAreaY,
			menu_data[MENU_A24].StringLIST[0].CopyWidth,
			menu_data[MENU_A24].StringLIST[0].CopyHeight
			);
		}
	}
		if (wheelgoes>=4)
		{
			bomb_message|=	WHEEL_ERROR;
		 	new_menu     =	QUIT;
		}
}

//ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ 
//บ
//บ  Do_text_input(int menu_number)
//บ
//บ		Allows user to input protection text from manual.
//บ
//ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ 
void	Do_text_input(int menu_number)
{
char key[1];
int	reprint_string	=	NULL;
char	code_number;
int	wheel_posn;

	if	( (MouseFlags & ENTER_NUMBER)!=0 && menu_number==MENU_A24 && 0 && match_info.language==German)
	{		
		TextCOLOUR	=	BRIGHT_WHITE;
		TextBuffer   	=	GetSTRING(menu_data[MENU_A24].StringLIST[1].string_type, 0);

		if (kbhit)
		{
		key[0] = Getchar();
//			if ( (key[0] = getch()) == 0)
//				key[1] = getch();

	     		int  SngLen	=	strlen	(TextBuffer);

			  	if (key[0]!=0)
			  	{			
		
			  		if ( SngLen>=1 && key[0]==8 && CursorXposn>0 )
			  		{

			  		int	SngCnt		=	CursorXposn;

			  			while	(SngCnt<2) 
			  			{
			  			TextBuffer[SngCnt-1]	=	TextBuffer[SngCnt];
			  			SngCnt++;
						reprint_string		=	ON;
			  			}

			  		TextBuffer[SngCnt-1]	=	0;
			  		CursorXposn--;
				  			
			  		}

			  		if (key[0]>=32 && key[0]<=122 
                                            && SngLen<18
                                             && (FindLengthOfSTRING( TextBuffer, key[0], NULL )) < 200
				  	      )

				     	if (key[0]<91 || key[0]>96)
			  		{
							
			  		TextBuffer[SngLen+1]	=	0;
			  		int	SngCnt		=	SngLen;

			  			while	(SngCnt>CursorXposn || SngCnt==0) 
			  			{									  
			  			TextBuffer[SngCnt]	=	TextBuffer[SngCnt-1];
			  			SngCnt--;
						reprint_string		=	ON;
			  	       		}
	
		  		 	TextBuffer[CursorXposn]	=	key[0];
					if ( TextBuffer[CursorXposn]>96 && TextBuffer[CursorXposn]<123 )
			  		 	TextBuffer[CursorXposn]-=	(97-65);
						

						if (CursorXposn==SngLen)
							{
					     		CursorXposn	=	strlen	(TextBuffer);
							reprint_string		=	ON;
							}
						else
							{
					     		CursorXposn++;
							reprint_string		=	ON;
							}
					}		
			
					if (key[0]==13)
					{
						char	enter_game,end_check,char_check;
						enter_game	=	TRUE;						
						end_check	=	NULL;
						char_check	=	0;						

			  		 	TextBuffer[CursorXposn]	=	0;
						MouseFlags&= 65535-ENTER_NUMBER;
						key_debounce|=	TRUE;
						
 						while	( end_check==NULL )
						{	
							if (TextBuffer[char_check]!=manual[german_man].text[char_check])
							{
								enter_game	=	FALSE;					
								end_check	=	-1;
							}
							if (TextBuffer[char_check]==0 && manual[german_man].text[char_check]==0)
								end_check	=	-1;
							if ( (TextBuffer[char_check]==0 || manual[german_man].text[char_check]==0) &&
							     end_check==NULL)
							{
								enter_game	=	FALSE;					
								end_check	=	-1;
							}

							char_check++;
		
							if (char_check>17)
							{
								enter_game	=	FALSE;					
								end_check	=	-1;
							}
						}


					if ( enter_game==TRUE )
						{
						GDVtimer	= DEMO_TIME;
						new_menu	= MENU_A0;
						PaletteFlag 	= PALETTE_FADE_DOWN;
				     		MouseDeBOUNCE 	= TRUE;
						MouseFlags&=	65535-MOUSE_OFF-ENTER_NUMBER;
						reset_scores();
						reset_net_variables();
						reset_league_teams(); 
						Setup_cup_teams(batch_info.number_of_cup_teams);
						InitialiseMan	=	GRM;
						InitialiseFlag	=	0;
						}

						else

						{
							InitialiseCodeWheel();
							MouseFlags|=		MOUSE_OFF;
							MouseFlags|=		ENTER_NUMBER;
							new_menu	= 	MENU_A24;
							rerun_menu	=	1;
							PaletteFlag 	= 	PALETTE_FADE_DOWN;
							TextBuffer[0]	=	NULL;
						}							

					}



	  			}
					if (key[0]==0)
					{			
				       		if (key[1]==0x4B && CursorXposn>0)
							{
					       		CursorXposn--;
							reprint_string		=	ON;
							}
						if (key[1]==0x4D && CursorXposn<SngLen)
							{
							CursorXposn++;
							reprint_string		=	ON;
							}
					}

		}

		{

		TextXposn	=	menu_data[MENU_A24].StringLIST[1].string_xposn;
		TextYposn	=	menu_data[MENU_A24].StringLIST[1].string_yposn;
  	      	menu_data[MENU_A24].StringLIST[1].string_flags	=
			menu_data[MENU_A24].StringLIST[1].string_flags | HIGHLIGHTED_TEXT;	
		CopyXposn	=	menu_data[MENU_A24].StringLIST[1].CopyAreaX;
		CopyYposn	=	menu_data[MENU_A24].StringLIST[1].CopyAreaY;
		CopyWIDTH	=	menu_data[MENU_A24].StringLIST[1].CopyWidth;
		CopyHEIGHT	=	menu_data[MENU_A24].StringLIST[1].CopyHeight;
	
		RestorePSUDObuffer();

	CursorXdisplay	= DisplaySTRING( GetSTRING(menu_data[MENU_A24].StringLIST[1].string_type, 0),
	        	 menu_data[MENU_A24].StringLIST[1].string_shadow);

		if	( (MouseFlags & ENTER_NUMBER)!=0 && (pulsating_colour & 8) !=0 )
			{
			TextXposn	=	CursorXdisplay;
			DisplaySTRING("[",menu_data[MENU_A24].StringLIST[1].string_shadow);		
			}

			Add_to_copy_list(
			menu_data[MENU_A24].StringLIST[1].CopyAreaX,
			menu_data[MENU_A24].StringLIST[1].CopyAreaY,
			menu_data[MENU_A24].StringLIST[1].CopyWidth,
			menu_data[MENU_A24].StringLIST[1].CopyHeight
			);
		}

	}


	if (wheelgoes>=4)
	{
		bomb_message|=	WHEEL_ERROR;
	 	new_menu     =	QUIT;
	}
}
#endif
