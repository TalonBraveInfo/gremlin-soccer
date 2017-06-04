#include "Frontend Vars.h"
#include "The Frontend.h"

#undef EXTERN
#define EXTERN extern
extern void init_team(void);
#include "Audio.h"
#include "Apple Menu.h"
#include "Blitter.h"
#include "Config.h"
#include "Control.h"
#include "Digi.h"
#include "Event.h"
#include "FileUtils.h"
#include "Flc Player.h"
#include "Init.h"
#include "Intronet.h"
#include "Memory.h"
#include "Mouse.h"
#include "Front Menu.h"
#include "Menudisp.h"
#include "Not Written Yet.h"
#include "Palette.h"
#include "Play.h"
#include "Results.h"
#include "Unmangle.h"
#include "Use DrawSprockets.h"
#include "Front Variables.h"
//#include "Rave Defines.h"
#include "Sprocket Input.h"
#include "Vbl.h"

extern int match(int argc, char **argv);
extern int performance;
extern void init_keyboard(void);
extern void init_users(void);

// STATICS
char		menu_initialised = OFF;
int			keep_demo_time;
int			keep_demo_Gtype;
int			keep_demo_teama;
int			keep_demo_teamb;
int			keep_demo_comp;
short		keep_demo_offside;
short		keep_demo_subs;
short		keep_demo_freekicks;
short		keep_demo_bookings;
short		keep_demo_wind;
int			keep_demo_referee;
int			keep_demo_penalties;
int			keep_demo_extra;
char		PC_speed = 31;
int			AutoSTARTgame;
char		team_a_okay, team_b_okay;
char		keep_language;
int			TimerHandle;
Boolean		MouseRange;

long TeamChecksums[MAX_TEAMS];

long ChecksumTeam( int team)
{
long checksum =0;

	for( int player = 0; player<22; player++)
		for( int a =0; a<PLAYER_NAME_LEN; a++)
			checksum += game_data[ team].players[ player].name[ a];
	return checksum;
}

static void ChecksumTeams()
{
	for( int a=0; a<MAX_TEAMS; a++)
		TeamChecksums[a] = ChecksumTeam( a);
}

void	BeginGame(void)
{
int tickcount, cnt;
Boolean RESET_MEMORY = true;
Handle temp;

	Frontend = true;
	version_number	=	1;
//	sub_version		=	0;
//	day				=	24;
//	month			=	5;
//	year			=	1996;

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Checks to see make sure a mouse driver is present before continuing.                                                        �
//�												                                 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 

#if DEBUGGING==ON
	DSpContext_FadeGammaIn( theContext, NULL);
#endif

	mainResFile = CurResFile();
	
	temp = GetResource( 'ACTU', 128);
	Language = **temp;
	DisposeHandle( temp);

	// Load In The Game Data Depending On The Language
	temp = nil; cnt = Language+1001;
	while( !temp)
		temp = GetResource( 'ACTU' , --cnt);
	HLockHi( temp);
	memcpy( &game_data, (char *)*temp, GetHandleSize(temp));
	DisposeHandle(temp);

	ChecksumTeams();

	// Test To See If The Resource File Exists */
	bomb_message = OpenResourceFile( RESNAME2, &dataResFile);
	bomb_message |= OpenResourceFile( RESNAME, &dataResFile2);
#if USERAVEENGINE==YES
	bomb_message |= OpenResourceFile( "\pRAVE Extras", &dataResRave);
#endif

	MousePresent();					// checks to see if mouse is present. If not then menu bombs

	cd_in = GetFirstCDDrive();

//	batch_info.GDVres		=	HI;

	ref_disc				=   50;
	ref_disc_add			=   1;
	ref_vision				=   50;
	ref_vision_add			=   -1;
	newgame					=	0;
//	redefine_flag	 		=	255;
//	calibrate_flag			=	255;
	CarryControl			=	NULL;
//	x1ok					=	NULL;	
//	y1ok					=	NULL;	
//	x2ok					=	NULL;
//	y2ok					=	NULL;	
//	bitaccept				=	NULL; 
	batch_info.cheat_mode 	=	0;
#if ROLLING_DEMO == OFF
	batch_info.rolling_demo	=	OFF;
#else
	batch_info.rolling_demo	=	ON;
#endif
	match_info.menu_res  	=	HI;
	match_info.language 	=	Language;
	no_cd					=	FALSE;
	keyboard				=	0;
	MouseFlags				=	NULL;
	MouseDeBOUNCE			=	0;

//#if FLOPPY==YES && ROLLING_DEMO!=OFF
//	if (batch_info.floppy==YES)
//	  {
//#ifdef WHEEL
//	  InitialiseCodeWheel();
//#endif
//	  current_menu		=	MENU_A24;    
//	  new_menu		=	current_menu;
//	  MouseFlags|=			MOUSE_OFF;
//	  MouseFlags|=			ENTER_NUMBER;
//	  }
//#endif

//	if (batch_info.rolling_demo!=OFF)
//	  no_cd = TRUE;

/*
		printf	("ACTUA SOCCER	final version: %d.%d	%d/%d/%d\n",version_number,sub_version,day,month,year);

  	if ( (match_info.language==English || match_info.language==French || match_info.language==Norwegian)
	      && batch_info.floppy==NO && batch_info.rolling_demo==Off)
		printf	("ACTUA SOCCER	final version: %d.%d	%d/%d/%d\n",version_number,sub_version,day,month,year);

  	if (match_info.language==German && batch_info.floppy==NO && batch_info.rolling_demo==Off)
		printf	("RAN SOCCER	final version: %d.%d	%d/%d/%d\n",version_number,sub_version,day,month,year);

  	if ( (match_info.language==English || match_info.language==French) && batch_info.floppy==NO && batch_info.rolling_demo==English)
		printf	("ACTUA SOCCER	demo version: %d.%d	%d/%d/%d\n",version_number,sub_version,day,month,year);

  	if (match_info.language==German && batch_info.floppy==NO && batch_info.rolling_demo==German)
		printf	("RAN SOCCER	demo version: %d.%d	%d/%d/%d\n",version_number,sub_version,day,month,year);

  	if ( (match_info.language==English) && batch_info.floppy==YES && batch_info.rolling_demo==Off)
		printf	("ACTUA SOCCER	floppy-disk version: %d.%d	%d/%d/%d\n",version_number,sub_version,day,month,year);

  	if ( (match_info.language==American || match_info.language==Canadian) && batch_info.floppy==NO && batch_info.rolling_demo==Off)
		printf	("VR SOCCER	final version: %d.%d	%d/%d/%d\n",version_number,sub_version,day,month,year);
*/

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Before going any further we must make alterations to any relevent country data at this point.                               �
//�												                                 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 

		setup.team_a	=	game_data[0].team_number;	//0 initialy set up teams as:  USA v's RUSSIA
		setup.team_b	=	game_data[1].team_number;	//1

#if ROLLING_DEMO != OFF
//			menu_data[MENU_A0].ButtonLIST[3].button_left_select	=	GOTO_MENU_A23;
//		if (batch_info.rolling_demo!=OFF)
//			{
//			menu_data[MENU_A0].ButtonLIST[3].button_left_select	=	GOTO_MENU_A24;
//			menu_data[MENU_A0].ButtonLIST[3].button_right_select	=	GOTO_MENU_A24;
//			menu_data[MENU_A0].ButtonLIST[5].button_left_select	=	GOTO_MENU_A24;
//			menu_data[MENU_A0].ButtonLIST[5].button_right_select	=	GOTO_MENU_A24;
//			menu_data[MENU_A0].ButtonLIST[6].button_left_select	=	GOTO_MENU_A24;
//			menu_data[MENU_A0].ButtonLIST[6].button_right_select	=	GOTO_MENU_A24;
//			menu_data[MENU_A0].ButtonLIST[8].button_left_select	=	GOTO_MENU_A24;
//			menu_data[MENU_A0].ButtonLIST[8].button_right_select	=	GOTO_MENU_A24;
//			menu_data[MENU_A8].ButtonLIST[1].button_type	=	NULL;
//			menu_data[MENU_A8].ButtonLIST[2].button_type	=	NULL;
//			menu_data[MENU_A8].ButtonLIST[3].button_type	=	NULL;
//			menu_data[MENU_A8].ButtonLIST[4].button_type	=	NULL;
//			memcpy(&game_data[setup.team_a], &game_data[0], sizeof(team_info));
//			memcpy(&game_data[setup.team_b], &game_data[1], sizeof(team_info));
//			}
#endif

		for (int NewCntrys=0; NewCntrys<MAX_TEAMS; NewCntrys++)
			{
			if(batch_info.rolling_demo==OFF)
				{
//				if (match_info.language==French)
//	 				{
					strcpy	(game_data[NewCntrys].name,     GetText( NewCntrys, textCountryNames) );
					strcpy	(game_data[NewCntrys].Nickname, GetText( NewCntrys, textNickNames));
//					}
//				if (match_info.language==German)
//					{
//					strcpy	(game_data[NewCntrys].name,     GermanCountryNames[NewCntrys]);
//					strcpy	(game_data[NewCntrys].Nickname, GermanNickNames[NewCntrys]);
//					}
//				if (match_info.language==Norwegian)
//					{
//					strcpy	(game_data[NewCntrys].name,     NorwegianCountryNames[NewCntrys]);
//					strcpy	(game_data[NewCntrys].Nickname, NorwegianNickNames[NewCntrys]);
//					}
				}
			}
/*
		if (match_info.language==German && batch_info.rolling_demo==OFF)
			{
			strcpy	(game_data[GER].coachname, GermanTeamNames[0]);
			for (int trn = 0; trn < 22; trn++)
			{strcpy	(game_data[GER].players[trn].name, GermanTeamNames[trn+1]);}
			}
*/
		PaletteFlag							=	0;

		InitialiseMan						=	-1;
		DrawMan								=	-1;
		menu_initialised					= 	OFF; 

		keep_demo_teama						=	setup.team_a;
		keep_demo_teamb						=	setup.team_b;

		PC_speed							=	timing();

		setup.team_a						=	keep_demo_teama;
		setup.team_b						=	keep_demo_teamb;

		GDVtimer							=	DEMO_TIME;

		batch_info.cup_match_number			=	-1;
		batch_info.DEMOflag					=	0;
//		batch_info.keys_used[UP_RED]		=	0x1e;		// A
//		batch_info.keys_used[DN_RED]		=	0x2c;		// Z
//		batch_info.keys_used[LF_RED]		=	0x33;		// <
//		batch_info.keys_used[RT_RED]		=	0x34;		// >
//		batch_info.keys_used[F1_RED]		=	0x10;		// Q
//		batch_info.keys_used[F2_RED]		=	0x35;		// /
#if TWOKEYS==YES
//		batch_info.keys_used[UP_RED+6]		=	-0x48;		// Arrow Up
//		batch_info.keys_used[DN_RED+6]		=	-0x50;		// Arrow Dn
//		batch_info.keys_used[LF_RED+6]		=	-0x4b;		// Arrow Lf
//		batch_info.keys_used[RT_RED+6]		=	-0x4d;		// Arrow Rt
//		batch_info.keys_used[F1_RED+6] 		=	0x52;		// 0(num)
//		batch_info.keys_used[F2_RED+6] 		=	0x53;		// .(num)
#endif
		batch_info.match_number				=	-1;
		batch_info.which_gdv				=	0;
		batch_info.number_of_cup_teams		=	32;
		batch_info.Port_toggle				=	NULL;
		batch_info.round_up_page			=	0;

		match_info.bookings					=	1;
		match_info.bookings_toggle 			=	1;
		match_info.camera					=	NULL;
		match_info.commentary				=	NULL;
		match_info.CompetitionType			=	FRIENDLY;
		match_info.CompetitionType_toggle	=	FRIENDLY;
#if TWOKEY==YES
		match_info.control_methods[0]		=	KEYBOARD;
		match_info.control_methods[1]		=	KEYBOARD2;
		match_info.control_methods[2]		=	JOYSTICK1;
		match_info.control_methods[3]		=	JOYSTICK2;
#else
//		match_info.control_methods[0]		=	KEYBOARD;
//		match_info.control_methods[1]		=	JOYSTICK1;
//		match_info.control_methods[2]		=	JOYSTICK2;
//		match_info.control_methods[3]		=	JOYSTICK3;
#endif
		match_info.crowd					=	NULL;
		match_info.freekicks				=	1;
		match_info.freekicks_toggle  		=	1;
		match_info.GameType					=	ARCADE;
		match_info.GameType_toggle			=	ARCADE;
		match_info.master					=	NULL;
		match_info.menu_res					=	HI;
	 	match_info.music					=	NULL;
		match_info.NoOfPlayers				=	NULL;
		match_info.NoOfPlayers_toggle		=	NULL;
		match_info.offside					=	0;
		match_info.offside_toggle			=	0;
		match_info.pitch					=	NULL;
		match_info.referee					=	16+16;
		match_info.substitutes				=	1;
		match_info.substitutes_toggle		=	1;
		match_info.time						=	0;
		match_info.time_toggle 				=	match_info.time;
		match_info.timeit					=	1;
		match_info.vidi						=	0;
		match_info.wind						=	0;
		match_info.wind_toggle				=	0;

//		music_fade_flag	 	 				=	NULL;			

		setup.M8							=   0;	// AvailableMemory > 7000;
		setup.detail.sky    				=	detail_defaults[PC_speed].sky;	
		setup.detail.stadia 				=	detail_defaults[PC_speed].stadia;
		setup.detail.pitch  				=	detail_defaults[PC_speed].pitch;
		setup.detail.players				=	detail_defaults[PC_speed].players;
		setup.detail.lines  				=	detail_defaults[PC_speed].lines;
		setup.detail.shadows				=	detail_defaults[PC_speed].shadows;
		setup.screen_size   				=	screen_defaults[PC_speed];
		setup.stadium						=	1;
		setup.start_res   					=	1;
		setup.team_a						=	keep_demo_teama;
		setup.team_b						=	keep_demo_teamb;
		setup.vidi_type   					=	NULL;

		if (batch_info.rolling_demo==OFF)
			{
			match_info.GameType				=	SIMULATION;
			match_info.GameType_toggle		=	SIMULATION;
			}
		
//		SoundCard = InitialiseMIDI();

//		if (SoundCard==0)
//			{	
//			match_info.audio = match_info.audio_toggle = 0;
//			menu_data[MENU_A14].ButtonLIST[0].button_index	=	0;
//			menu_data[MENU_A14].ButtonLIST[1].button_index	=	0;
//			menu_data[MENU_A14].ButtonLIST[2].button_index	=	0;
//			menu_data[MENU_A14].ButtonLIST[3].button_index	=	0;
//			menu_data[MENU_A14].ButtonLIST[4].button_index	=	0;
//			}
//		else
			{	
			match_info.audio = match_info.audio_toggle = 2;
			menu_data[MENU_A14].ButtonLIST[0].button_index	=	150;	// crowd
			menu_data[MENU_A14].ButtonLIST[1].button_index	=	150;	// commen
			menu_data[MENU_A14].ButtonLIST[2].button_index	=	160;	// master
			menu_data[MENU_A14].ButtonLIST[3].button_index	=	200;	// pitch
			menu_data[MENU_A14].ButtonLIST[4].button_index	=	180;	// music
			if (match_info.language==Norwegian)
				{
				menu_data[MENU_A14].ButtonLIST[1].button_index	=	200;	// commen
				menu_data[MENU_A14].ButtonLIST[0].button_index	=	110;	// crowd
				}
			}

#if USERAVEENGINE==YES
			if( !UseRaveEngine)
				{
				menu_data[ MENU_A6].ButtonLIST[11].button_type = NULL;
				}
			else
				{
				menu_data[ MENU_A5].ButtonLIST[ 3].button_type = NULL;
				menu_data[ MENU_A5].ImageLIST[ 3] = NULL;
				menu_data[ MENU_A5].LabelLIST[ 4] = NULL;
				menu_data[ MENU_A5].ButtonLIST[ 6].button_type = NULL;
				menu_data[ MENU_A5].ImageLIST[ 6] = NULL;
				menu_data[ MENU_A5].LabelLIST[ 7] = NULL;
				menu_data[ MENU_A5].ButtonLIST[ 8].button_type = NULL;
				menu_data[ MENU_A5].ImageLIST[ 8] = NULL;
				menu_data[ MENU_A5].LabelLIST[ 9] = NULL;
				}
#endif

		net_half							=	match_info.time;
					
//		cal0								=	NULL;
//		cal1								=	NULL;
		net_game_no							=	0;
//		cd_in								=	TRUE;
		SuspendAudio						=	false;

		reset_net_variables();
		reset_league_teams();

		network_on	=	0;
		netsetup_on  	=	0;
		audio_version=TRUE; 
		InitialiseTimer();			// Initialise timers for sound drivers	(see ANDY or LAURENT)..

		if (go_audio())
			{
			UnInitialiseTimer();
			bomb_message |= SOUND_ERROR;
			}

		// Timer stuff

		ftick		=	VblTicks	=	0;
		game_speed	=	REAL_SPEED;
		readptr		=	writeptr	=	count	=	0;
//		AddTimer(TIMER_SPEED,nethandler,&TimerHandle);

//		Set_palette_to_black();

   		Competition_limit = CheckFORnet();		// The network inialise is only called to check if a

		RESET_MEMORY	=	true;
		OverlayFlag		=	NULL;

		if (bomb_message!=0)
			{
			new_menu	=	QUIT;
			goto MAJOR_ERROR;		
			}

		read_config_file();

		batch_info.PointsForWin	=	3;
		
		match_info.menu_res 	=	HI;
		DisplayWidth			=	640;
		header_y				=	13*640;
		ActuaMEMflag			=	HI;
		background_buffer_LEN	=	640*480; 
//		psudo_buffer_LEN		=	(640*480)+1;
//		sprite_buffer_LEN		=	993000; 
//		spool_buffer_LEN		=	600000;
		unpack_buffer_LEN		=	48100;

//		Palette_buffer		=	palette_buffer;
	
		if (bomb_message!=0)
			{
			new_menu	=	QUIT;
			goto MAJOR_ERROR;		
			}

		while	( new_menu!=QUIT && new_menu!=NO_MOUSE )
			{
			if( RESET_MEMORY)
				{
				if (batch_info.which_gdv==0)
					{
					PlayGDV();
					batch_info.which_gdv = 1;
	    			}
	    		else
	    			Set_palette_to_black();

//				Set_palette_to_black();
				Initialise_environment();
				Allocate_memory();

				InitialiseMan	=	GRM;
				InitialiseFlag	=	0;
//				Load_menu_data();

				ItalicSpaceTable	=	(short *)proptab_buffer;
				Filter_Table		=	filter_buffer;
				SuspendAudio 	=	false;
				RESET_MEMORY	=	false;
				}

			Setup_cup_teams(batch_info.number_of_cup_teams);

			last_ticks		=	NULL;
			AutoSTARTgame 	=	NULL;
			SuspendAudio	=	false;
			RetestNet		=	FALSE;

#if DEBUGGING==ON
			DSpContext_FadeGammaIn( theContext, NULL);
#endif

			while	( new_menu!=QUIT && new_menu!=PLAY_MATCH && new_menu!=PLAY_GDV && new_menu!=DEMO_MODE)
				{
				if( !strcmp(game_data[0].coachname,"Pound A Bottle"))
					batch_info.cheat_mode = 1;
				else
					batch_info.cheat_mode = 0;
				
				if (bomb_message!=0)
					{
					new_menu	=	QUIT;
					goto MAJOR_ERROR;		
					}

				if (InitialiseMan != -1 && PaletteFlag==0 && (new_menu==MENU_A0 || new_menu==MENU_A19 || new_menu==MENU_A17))
					{
					if (DrawMan==0)
						endman();    
					DrawMan = initman( InitialiseMan, InitialiseFlag);
					if	(DrawMan==-1)
			  			{
			  			new_menu = QUIT;
			  			goto MAJOR_ERROR;
			  			}
					}

				Clear_copy_list();
				Initialise_menu(current_menu);	
				PaletteFlag	=	PALETTE_FADE_UP;
				if( bomb_message)
					{
					new_menu	=	QUIT;
					goto MAJOR_ERROR;		
					}
					
				if ( batch_info.PlayerCount>match_info.NoOfPlayers )
					menu_data[MENU_A15].ButtonLIST[0].button_text	=	DONE_TEXT;
				else
	  				menu_data[MENU_A15].ButtonLIST[0].button_text	=	NEXT_TEXT;
				menu_data[MENU_A15].ButtonLIST[0].button_index		=	8;

				MouseFlags &= (MOUSE_OFF+ENTER_NUMBER);
				Button_pressed = NULL;

				tickcount = TickCount();
		
				while	( ( current_menu==new_menu || PaletteFlag!=NULL ) )
					{
					do
						{
						Process_keyboard();
						} while	((TickCount()-tickcount)<(TIMER_SPEED/30));
					tickcount = TickCount();
		  
#if DEBUGGING==ON
			DumpLong(10, (MouseXposn<<16) | MouseYposn);
			DumpLong(20, current_menu);
			DumpLong(30, new_menu);
			DumpLong(40, PaletteFlag);
			
			DumpLong(50, VblTicks);
			DumpLong(60, TicksPerSecond);
			DumpLong(70, performance);
			
			DumpLong(80, (long)gNetGame);
			if( keyMap[3]&0x00000200)
				DebugStr("\pDebugger Break");
			
//			DebugSoundChannels();
#endif

	  		count = 0;
			pulsating_colour++;
					
			UpdateMusic();

			Do_cupsetup_highlights();					// highlights number of selected teams on shirts (MENU_A2).

			Random_RS();			    				// automatically updates Random_RS seed.
			Get_mouse_data();			 				// reads mouse data and erases last displayed mouse cursor.
			Process_keyboard();

			ClickXposn	=	MouseXposn;
			ClickYposn	=	MouseYposn;
		
			Do_choice_selection(current_menu);			// allows user to select their team.
			Do_participating_selection(current_menu);   // controls users choices for particiating cup-teams (MENU_A3).
			Do_edit_team_data(current_menu);	    	// controls users modification of team data (MENU_A1).
	 		Do_squad_selection(current_menu);	    	// controls users modification of squad/formation (MENU_A9).
	 		Do_save_load_selection(current_menu);	    // allows user to choose load/save slot (MENU_A7).
//			Do_control_selection(current_menu);			// allows user to change control methods (MENU_A6).
			Do_net_player_selection(current_menu);    	// allows net-user to select which player to control.
//			Do_juggling_man(current_menu);				// display juggling man.
	 		View_player_statistics(current_menu);  		// controls users selection for statistics viewer (MENU_A10).
			View_auto_selected_team(current_menu);		// allows user to view stats on auto-selected team.
			View_match_setup(current_menu);				// displays referee and match setup options.
			Update_formation(current_menu);				// controls updating of formation button.
			Update_environment(current_menu); 			// controls updating of enviroment data.
			Animate_Buttons(current_menu);				// update any buttom images which have altered since last frame.
			Display_Sprites(current_menu);				// update any sprites which have altered since last frame.
//			Calibrate_joystick(current_menu);			// allows user to calibrate a joystick.
//			Redefine_keyboard(current_menu);			// allows user to redefine keys.
			Do_match_info_screen(current_menu);			// display screen for next match.
			menu_update	=	NULL;		      			// switch off compulsary print flag.
			Control_Sliders(current_menu);				// update any sliders bars which have altered since last frame.
			Animate_participating_flags(current_menu);	// animates any flags which are pointed to by cursor (MENU_A3).	
			Do_juggling_man(current_menu);
			Display_mouse_cursor();						// redraws mouse cursor to psudo screen.
	 		Do_text_editing(current_menu);				// allows users to edit a selected text string.
			Do_button_control(current_menu); 	    	// controls menu button selection.			
#ifdef WHEEL
			Do_number_input(current_menu);				// allows user to enter protection number.
			Do_text_input(current_menu);				// allows user to enter protection number.
#endif
			Setup_no_of_teams();						// sets up flag indicating number of teams participating in game.
			Dump_copy_list();     						// dumps data from copy list to actual screen.

			if ( PaletteFlag )
				FadeThePalette();						// fades up palette.
 			else if(current_menu!=MENU_A17)
				PulsateColour(pulsating_colour);	 	// dumps pulsating colour to palette (colour: 175).

			if( gNetGame)
				Polling_Network();

//			if	( music_fade_flag==NULL )
//				{
//		 		match_info.music	=	MusicVolume*163;
//				MusicVolume += 2;
//		 		if (music_volume>=menu_data[MENU_A14].ButtonLIST[4].button_index)
//	 	 			music_fade_flag	=	1;
//				}				

			if( bMusicPlaying)
				PLAYER_SetVolume( MUSICCHANNEL, MusicVolume);

//			if 	( match_info.menu_res==LO )
//				{
//				DisplayDESTINATION	=	psudo_buffer;	
//				copy_PSUDOtoACTUALscreen();
//				FlipDISPLAYpage();
//				}

			if ( rerun_menu!=0 && PaletteFlag==NULL)	// if new menu is same as current menu and needs
				current_menu	=	-1;	        		// to rerun then this fools program into letting it.

			if ( current_menu==MENU_A23 && PaletteFlag==NULL)
				{
		 		if ( (batch_info.DEMOflag & 128))
					new_menu	=	DEMO_MODE;
				else
					new_menu	=	PLAY_MATCH;
				}
			}

		current_menu	=	new_menu;
		rerun_menu    	=	NULL;
		}
		
	if (current_menu==PLAY_GDV)
		{
		StopMusic();
		SuspendAudio = true;

   		if (DrawMan==0)
	     	endman();    
     	DrawMan	=	-1;
     	DeAllocate_memory();
		init_keyboard();
		init_users();
		init_team();

		PlayGDV();
		RESET_MEMORY	=	true;
		current_menu	=	MENU_A0;
		new_menu	=	current_menu;
		}
#if ROLLING_DEMO == OFF
	else if (current_menu==DEMO_MODE)	// Demo Mode
#else
	else if(current_menu == DEMO_MODE || current_menu == PLAY_MATCH)
#endif
		{
		MouseFlags |= MOUSE_OFF;

		StopMusic();
		SuspendAudio = true;

		keep_demo_teama				=	setup.team_a;
		keep_demo_teamb				=	setup.team_b;
		keep_demo_referee			=	match_info.referee;
		keep_demo_time				=	match_info.time;
		keep_demo_Gtype				=	match_info.GameType;
		keep_demo_comp				=	match_info.CompetitionType;
		keep_demo_offside			=	match_info.offside;
		keep_demo_subs				=	match_info.substitutes;
		keep_demo_penalties			=	match_info.penalties;
		keep_demo_extra				=	match_info.extra;
		keep_demo_freekicks			=	match_info.freekicks;
		keep_demo_bookings			=	match_info.bookings;
		keep_demo_wind				=	match_info.wind;
		keep_language				=	match_info.language;

		batch_info.DEMOflag		   &=	127;
		team_a_okay					=	FALSE;
		team_b_okay					=	FALSE;

		// PICK RANDOM TEAMS TO TAKE PART IN DEMO
		
#if ROLLING_DEMO == OFF
//		setup.team_a		=	demo_data[batch_info.DEMOflag+(8*match_info.language)].team_a;
//		setup.team_b		=	demo_data[batch_info.DEMOflag+(8*match_info.language)].team_b;
		setup.team_a		=	demo_data[0].team_a;
		setup.team_b		=	demo_data[0].team_b;
#else
		setup.team_a		=	game_data[14].team_number;	// 14 England
		setup.team_b		=	game_data[15].team_number;	// 15 Scotland
#endif

//		match_info.rand		=	demo_data[batch_info.DEMOflag+(8*match_info.language)].random;
//		setup.stadium		=	demo_data[batch_info.DEMOflag+(8*match_info.language)].stadium;
//		match_info.referee	=	demo_data[batch_info.DEMOflag+(8*match_info.language)].referee;
		match_info.rand		=	demo_data[0].random;
		setup.stadium		=	demo_data[0].stadium;
		match_info.referee	=	demo_data[0].referee;
		

		// RESET CONTROLS SO PLAYERS ARE NOT IN CONTROL.

		setup.team_b_kit	=	team_b_kit[ ((setup.team_a*MAX_TEAMS)+setup.team_b) ];
		game_data[setup.team_a].player_control = NULL;
		game_data[setup.team_b].player_control = NULL;

		// RESET ANY RELEVENT MEMORY DATA.
			
     	if (DrawMan==0)
	     	endman();    
     	DrawMan	=	-1;
     	DeAllocate_memory();

		init_keyboard();

		init_users();

		if (!network_on)
			old_mf	=	TRUE;
		else
			old_mf	=	FALSE;

		match_info.tac_1	=	game_data[setup.team_a].formation;	
		match_info.tac_2	=	game_data[setup.team_b].formation;	

		setup_player_data(setup.team_a);
		setup_player_data(setup.team_b);

		recalc_referee();
		match_info.team_a_score		=	0;
		match_info.team_b_score		=	0;
		match_info.team_a_penalties	=	0;
		match_info.team_b_penalties	=	0;

		match_info.time				=	0;
		match_info.GameType			=	SIMULATION;
		match_info.CompetitionType	=	FRIENDLY;
		match_info.offside			=	0;
		match_info.substitutes		=	0;
		match_info.penalties		=	0;
		match_info.extra			=	0;
		match_info.freekicks		=	1;
		match_info.bookings			=	1;
		match_info.wind				=	1;

		if (keyboard==0)
			InitialiseMOUSE();
		
		if (keep_language==American)
			match_info.language = English;
		else if (keep_language==Canadian)	
			match_info.language = French;
			
		init_team();
		reset_scores();

		Frontend = false;
		match( 128, NULL);
//extern void DumpAllMaps(void);
//		DumpAllMaps();
		Frontend = true;
		GDVtimer = DEMO_TIME;
				
		match_info.time				=	keep_demo_time;
		match_info.GameType			=	keep_demo_Gtype;
		match_info.CompetitionType	=	keep_demo_comp;
		match_info.offside			=	keep_demo_offside;
		match_info.substitutes		=	keep_demo_subs;
		match_info.penalties		=	keep_demo_penalties;
		match_info.extra			=	keep_demo_extra;
		match_info.freekicks		=	keep_demo_freekicks;
		match_info.bookings			=	keep_demo_bookings;
		match_info.wind				=	keep_demo_wind;
		match_info.language			=	keep_language;
		match_info.referee			=	keep_demo_referee;
		setup.team_a				=	keep_demo_teama;
		setup.team_b				=	keep_demo_teamb;

		MouseFlags				   &=	~MOUSE_OFF;
		Set_palette_to_black();

		RESET_MEMORY				=	true;
		current_menu				=	MENU_A0;
      	new_menu					=	current_menu;
		}

#if ROLLING_DEMO == OFF
	else if (current_menu==PLAY_MATCH)	// Match Mode
			{	// Joolz
			if (match_info.CompetitionType==CUP)
				{
				setup.team_a	=	batch_info.cup_team_a;
				setup.team_b	=	batch_info.cup_team_b;
				}
			if    (	((game_data[setup.team_a].player_control==NULL && game_data[setup.team_b].player_control==NULL) &&
				    (match_info.CompetitionType!=NETWORK && match_info.CompetitionType!=FRIENDLY)) )
				{
				calculate_match();			
				RESET_MEMORY	=	false;
				}
		   	else
				{
				SuspendAudio = true;
				StopMusic();

				if (DrawMan==0)
				   	endman();    
				DrawMan	=	-1;
				DeAllocate_memory();
				init_keyboard();
				init_users();
				init_team();

//					key_togs[0x2f]=match_info.vidi;
				setup.stadium=1;

				if (!network_on)
					old_mf	=	TRUE;
				else
					old_mf	=	FALSE;

				match_info.tac_1	=	game_data[setup.team_a].formation;	
				match_info.tac_2	=	game_data[setup.team_b].formation;	

				setup_player_data(setup.team_a);
				setup_player_data(setup.team_b);
				recalc_referee();

				if (match_info.CompetitionType==NETWORK)
					{
					match_info.rand					= 3543;
					match_info.offside	       		= 0;
					match_info.offside_toggle      	= 0;
					match_info.wind		       		= 0;
					match_info.wind_toggle      	= 0;
					match_info.substitutes	       	= 1;
					match_info.substitutes_toggle  	= 1;
					match_info.bookings	       		= 1;
					match_info.bookings_toggle     	= 1;
					match_info.freekicks	       	= 1;
					match_info.freekicks_toggle    	= 1;
					match_info.GameType	       		= 0;
					match_info.GameType_toggle     	= 0;
					}
				else
					match_info.rand	=	Random_RS();

//				x1ok		=	NULL;
//				x2ok		=	NULL;
//				y1ok		=	NULL;
//				y1ok		=	NULL;
//				bitaccept	=	NULL;

//				if (cal0!=NULL)
//					{			
//					x1ok 	  = 1;	
//					y1ok 	  = 2;	
//					bitaccept|= (x1ok+y1ok);
//					}
//
//				if (cal1!=NULL)
//					{			
//					x2ok 	  = 4;	
//					y2ok 	  = 8;	
//					bitaccept|= (x2ok+y2ok);
//					}

				setup.stadium	=	match_info.venue;

//				key1[UP_KEY]	=	InsertKey(batch_info.keys_used[UP_RED]);	//0x1e;	       
//				key1[DN_KEY]	=	InsertKey(batch_info.keys_used[DN_RED]);	//0x2c;	       
//				key1[LF_KEY]	=	InsertKey(batch_info.keys_used[LF_RED]);	//0x33;	       
//				key1[RT_KEY]	=	InsertKey(batch_info.keys_used[RT_RED]);	//0x34;	       
//				key1[F1_KEY]	=	InsertKey(batch_info.keys_used[F1_RED]);	//0x10;	       
//				key1[F2_KEY]	=	InsertKey(batch_info.keys_used[F2_RED]);	//0x35;	      

#if TWOKEY==YES
//				key2[UP_KEY]	=	InsertKey(batch_info.keys_used[UP_RED+6]);	//-0x48;    
//				key2[DN_KEY]	=	InsertKey(batch_info.keys_used[DN_RED+6]);	//-0x50;    
//				key2[LF_KEY]	=	InsertKey(batch_info.keys_used[LF_RED+6]);	//-0x4b;    
//				key2[RT_KEY]	=	InsertKey(batch_info.keys_used[RT_RED+6]);	//-0x4d;    
//				key2[F1_KEY]	=	InsertKey(batch_info.keys_used[F1_RED+6]);	//0x52;	    
//				key2[F2_KEY]	=	InsertKey(batch_info.keys_used[F2_RED+6]);	//0x53;	    
#endif
				reset_scores();
				match_info.team_a_score		=	0;
				match_info.team_b_score		=	0;
				match_info.team_a_penalties	=	0;
				match_info.team_b_penalties	=	0;
				match_info.penalties		=	0;
				match_info.extra		=	0;

	 			if (keyboard==0)
					InitialiseMOUSE();

				keep_language	=	match_info.language;

				if (keep_language==American)
					match_info.language	=	English;
				else if (keep_language==Canadian)	
					match_info.language	=	French;

				while( Button())
					;
					
//				ClearScreen();
				Input_Activate(true);
				Frontend = false;
				match( 0, NULL);
				Frontend = true;
				GDVtimer = DEMO_TIME;
				Input_Activate(false);
				
				match_info.language	=	keep_language;

				quit_current_match();
				MouseFlags&=	65535-MOUSE_OFF;
				Set_palette_to_black();
				
      			RESET_MEMORY	=	true;
				}

			if ( match_info.CompetitionType==NETWORK )
				{
				End_Network_Game();
				current_menu		=	MENU_A16;
				menu_data[MENU_A16].ButtonLIST[0].button_left_select	=	GOTO_MENU_A0; 
//				menu_data[MENU_A16].ButtonLIST[0].button_right_select	=	GOTO_MENU_A0; 
				}
		
			else if ( match_info.CompetitionType==FRIENDLY || match_info.CompetitionType==PRACTICE)
				{
				current_menu		=	MENU_A16;
				menu_data[MENU_A16].ButtonLIST[0].button_left_select	=	GOTO_MENU_A0; 
//				menu_data[MENU_A16].ButtonLIST[0].button_right_select	=	GOTO_MENU_A0; 
				}

			else if ( match_info.CompetitionType==LEAGUE )
				{
				results[batch_info.match_number].result_data.team_a_score	=	match_info.team_a_score;	 
				results[batch_info.match_number].result_data.team_b_score	=	match_info.team_b_score;	 
				results[batch_info.match_number].result_data.team_a    		=	setup.team_a;	 
				results[batch_info.match_number].result_data.team_b  	  	=	setup.team_b;	 
				game_data[setup.team_a].played++;
				game_data[setup.team_b].played++;
				game_data[setup.team_a].goals_for+=	match_info.team_a_score;
				game_data[setup.team_b].goals_for+=	match_info.team_b_score;
				game_data[setup.team_a].goals_against+=	match_info.team_b_score;
				game_data[setup.team_b].goals_against+=	match_info.team_a_score;
				if (match_info.team_a_score > match_info.team_b_score)
					{
					game_data[setup.team_a].won++;
					game_data[setup.team_b].lost++;
					}					
				else if (match_info.team_b_score > match_info.team_a_score)
					{
					game_data[setup.team_b].won++;
					game_data[setup.team_a].lost++;
					}					
				else if (match_info.team_b_score==match_info.team_a_score)
					{
					game_data[setup.team_a].drew++;
					game_data[setup.team_b].drew++;
					}					

				batch_info.Ranking_Division  		   	=	fixtures[batch_info.match_number].fixture_data.league_table;	
				current_menu					=	MENU_A16;
				menu_data[MENU_A16].ButtonLIST[0].button_left_select	=	GOTO_LEAGUE; 
//				menu_data[MENU_A16].ButtonLIST[0].button_right_select	=	GOTO_LEAGUE; 
						
			    menu_data[MENU_A8].ButtonLIST[7].button_flags|= 	ACTIVE;
				menu_data[MENU_A8].SpriteTABLE[6].sprite_state&=	65535-ACTIVE; 

				DoLEAGUEtables();
				batch_info.match_number++;
				SortARCADEleagueGAME();
				}

			else if ( match_info.CompetitionType==CUP )
				{
				results[batch_info.cup_match_number].result_data.team_a_score	=	match_info.team_a_score;	 
				results[batch_info.cup_match_number].result_data.team_b_score	=	match_info.team_b_score;	 
				results[batch_info.cup_match_number].result_data.team_a    	=	batch_info.cup_team_a;	 
				results[batch_info.cup_match_number].result_data.team_b    	=	batch_info.cup_team_b;	 
				results[batch_info.cup_match_number].result_data.extra		=	match_info.extra;	 
				results[batch_info.cup_match_number].result_data.penalties		=	match_info.penalties;	 
				results[batch_info.cup_match_number].result_data.team_a_penalties	=	match_info.team_a_penalties;	 
				results[batch_info.cup_match_number].result_data.team_b_penalties	=	match_info.team_b_penalties;	 


			// THESE TWO LINES SORT ESC KEY ON CUP COMPETITION BUG FROM DESTROYING GAME.... 
			//	Not an ideal solution....
		
				game_data[batch_info.cup_team_a].cup_key	=	  -1;
				game_data[batch_info.cup_team_b].cup_key	=	NULL;


				if ( match_info.team_a_score > match_info.team_b_score )
					{
					game_data[batch_info.cup_team_a].cup_key	=	  -1;
					game_data[batch_info.cup_team_b].cup_key	=	NULL;
					batch_info.winners		=	batch_info.cup_team_a;
					batch_info.runners_up  	       	=	batch_info.cup_team_b;
					}
				else if (match_info.team_b_score > match_info.team_a_score)
					{
					game_data[batch_info.cup_team_a].cup_key	=	NULL;
					game_data[batch_info.cup_team_b].cup_key	=	  -1;
					batch_info.winners    		=	batch_info.cup_team_b;
					batch_info.runners_up  	       	=	batch_info.cup_team_a;
					}					
				else if (match_info.team_b_score == match_info.team_a_score)
					{
					if (match_info.team_a_penalties > match_info.team_b_penalties)
						{
				   		game_data[batch_info.cup_team_a].cup_key	=	  -1;
				   		game_data[batch_info.cup_team_b].cup_key	=	NULL;
						batch_info.winners	      	=	batch_info.cup_team_a;
						batch_info.runners_up     	=	batch_info.cup_team_b;
						}
					else if (match_info.team_b_penalties > match_info.team_a_penalties)
					   	{
						game_data[batch_info.cup_team_a].cup_key	=	NULL;
						game_data[batch_info.cup_team_b].cup_key	=	  -1;
						batch_info.winners		=	batch_info.cup_team_b;
						batch_info.runners_up     	=	batch_info.cup_team_a;
						}
					}					

				menu_data[MENU_A16].ButtonLIST[0].button_left_select	=	DONE_CUP_DISPLAY; 
//				menu_data[MENU_A16].ButtonLIST[0].button_right_select	=	DONE_CUP_DISPLAY; 
				menu_data[MENU_A8].ButtonLIST[7].button_flags|= 	ACTIVE;
				menu_data[MENU_A8].SpriteTABLE[6].sprite_state&=	65535-ACTIVE; 
				batch_info.cup_tie+=		2;
				batch_info.cup_match_number++;
				current_menu		=	MENU_A16;
     
				if (game_data[batch_info.cup_team_a].player_control==NULL && game_data[batch_info.cup_team_b].player_control==NULL )
					{
					batch_info.roundup_games++;
					if ( match_info.GameType==ARCADE)
						{
						current_menu			= 	PLAY_MATCH;
						PaletteFlag 			= 	PALETTE_FADE_DOWN;
						batch_info.OldCTRL1 		=	-1;
						batch_info.OldCTRL2   		=	-1;
						reset_scores();
						batch_info.match_number		=	SortNEXTfixture(batch_info.match_number, match_info.CompetitionType);

						if (game_data[batch_info.cup_team_a].player_control!=NULL || game_data[batch_info.cup_team_b].player_control!=NULL )
							current_menu			= 	MENU_A8;

						if ( batch_info.roundup_games > batch_info.RoundPrint || batch_info.match_number==-1)
							{
							if ( batch_info.match_number == -1 )
								batch_info.RoundPrint	=	0;
							current_menu		=	MENU_A22;
							batch_info.roundup_games		=	NULL;
							}
						}
					}
				}
			new_menu		=	current_menu;
			}
#endif
		}

	write_config_file();

MAJOR_ERROR:
	if( dataResFile) CloseResFile( dataResFile);
	if( dataResFile2) CloseResFile( dataResFile2);
#if USERAVEENGINE==YES
	if( dataResRave) CloseResFile( dataResRave);
#endif
	
	if (new_menu==QUIT)
		{	

	 	DeinitialiseNET(Competition_limit);			// net game can be played.....

    	if (DrawMan==0)
   		endman();    
   		DrawMan	=	-1;

		DeAllocate_memory();

//		RemoveTimer(TimerHandle);

		if (audio_version)
			UnInitialiseDIGI();

		UnInitialiseTimer();
		}
}



/******************************************************************************
*****************************************************************************/

int go_audio()
{
// Initialise Audio Config...
	

	if(InitialiseDIGI(22050, 0)) // setup.verbose?IDF_VERBOSE:0))			// Initialise Digital Sound Drivers
		return(EXIT_FAILURE);
	return(FALSE);
}

//
// Software Piracy Protection Pumpkin Gobbler for ACTUA SOCCER
//
//*************************************************************************************************
//
// Checks for the Actua Soccer CD
//
//*************************************************************************************************
int CDPresent(void)
{
	return GetFirstCDDrive();
}

//*************************************************************************************************
//
// Checks to see if there is a CD Drive connected.
//
// returns TRUE if CD Connected and fills in First CD Drive and NumCDdrives
//	        FALSE if nothing there
//
//*************************************************************************************************
int GetFirstCDDrive()
{
	if( Language == American || Language == Canadian)
		{
#if BETA
		bSoccerDiskIn = FindCD( nil, &vRefNum, &drvrRefNum);
#else
		bSoccerDiskIn = FindCD( "\pVR Soccer", &vRefNum, &drvrRefNum);
#endif
		}
	else
		{
#if BETA
		bSoccerDiskIn = FindCD( nil, &vRefNum, &drvrRefNum);
#else
		bSoccerDiskIn = FindCD( "\pActua Soccer", &vRefNum, &drvrRefNum);
#endif
		}
	
	return bSoccerDiskIn;
}

/***********************************************************************\
    * name:     FindCD                                                    
    * descr:    Return true if there is a CD-ROM volume mounted in the    
    *           computer. Returns the vRefNum and drvrRefNum for this     
    *           volume.                                                   
\***********************************************************************/
#define PARANOID_CD_CHECK       0
Boolean FindCD( StringPtr discName, short * vRefNum, short * drvrRefNum )
{
HVolumeParam        hp;
Str255              volumeName;
OSErr               err;
short               index;
Boolean             online;
unsigned long       volSize;
    
	*vRefNum = 0;
    *drvrRefNum = 0;

    //  Find a CD that matches our criteria
    
    index = 0;
    
    do
    	{
        hp.ioVolIndex   = ++index;
        hp.ioNamePtr    = volumeName;
        hp.ioVRefNum    = 0;
        
        err = PBHGetVInfoSync( (HParmBlkPtr) &hp );
        if ( err == noErr )
        	{
            //  If we specified a name for the CD, then it must match
            //  We use case-sensitive because a CD name can't change!
                
            if ( discName == nil || EqualString( volumeName, discName, true, true ) )
            	{
                AuxDCE **       dCtl;
                Ptr             theDrvr;
                StringPtr       drvrName;
                
                //  See if the driver we found for the disc
                //  is the .AppleCD driver. If so, we are cool.
                
                dCtl = (AuxDCE **) GetDCtlEntry( hp.ioVDRefNum );
                if ( dCtl )
                	{
                    if ( (**dCtl).dCtlFlags & 0x40 )
                        // handle-based
                        theDrvr = *(Handle) (**dCtl).dCtlDriver;
                    else
                        // pointer-based
                        theDrvr = (**dCtl).dCtlDriver;
                    drvrName = (StringPtr) theDrvr + 18;
                    
                    //  If NOT .AppleCD, then just go on to next volume
                    if ( ! EqualString( drvrName, "\p.AppleCD", true, true ) )
                        continue;
	                }

				// Optional - for the slightly more paranoid, you can
				// verify that the disc is online, and that the volume size is appropriate

#if PARANOID_CD_CHECK
                online = hp.ioVDrvInfo > 0;
                volSize = (unsigned long) hp.ioVNmAlBlks * (unsigned long) hp.ioVAlBlkSiz;
                
                if ( online && ( volSize >= MIN_CD_DATA_SIZE ) && ( volSize <= MAX_CD_DATA_SIZE ) )
#endif
	                {
                    *vRefNum = hp.ioVRefNum;
                    *drvrRefNum = hp.ioVDRefNum;
                    return true;
    	            }
	            }
	        }
		} while ( err == noErr );
    
        //  If error, any error, then volume is not there
        //  Volume is not right, return false
        
	return false;
}

//*************************************************************************************************
//
// Check for a single file on a drive
//
//*************************************************************************************************
int CheckCD(int CD)
{
	return 1;
}

//int	InsertKey(int SourceKEY)
//{
// 	if (SourceKEY>127)
//	{
//	 	SourceKEY-=	128;
//		SourceKEY=	-SourceKEY;
//	}
//	return	(SourceKEY);
//}

#ifdef WHEEL
void	InitialiseCodeWheel()
{
	CursorXposn	=	0;
 	WheelOuter	=	(Random_RS()&15);
 	WheelInner	=	(Random_RS()&15);
 	WindowNumber	=	(Random_RS()&31);
	wheelgoes++;
	
	char	legal_manual	=	FALSE;

 	while	( legal_manual==FALSE )
	{	
	  german_man	=	(Random_RS()&63);
  	  if  ( german_man<50 )
  		legal_manual	=	TRUE;
	}
}
#endif

char Getchar()
{
  	kbhit = false;
	
	return thekey;
}

#if 0

void Process_keyboard()
{
int normal = 0x00, mask = 0x80, a, key;
char *keysmap;
char modifiers[4]={0,0,0,0};
char keys[16], keypressed;
static lastkey = 0;
static debounce = 10;
	
	GetKeys( keyMap);
	FlushEvents( everyEvent, 0x0000);
	
	keysmap = (char *)&keyMap;
	for(a=0;a<128;a++)
		{
		if( *keysmap & mask)
			{
			if( LegalKEY[a])
				{
				key = KEYtext[a];
				if( key>=128 && key<=130)
					modifiers[ key-128] = true;
				else if( key==141)
					modifiers[ 3] = true;
				else if( key>128)
					;
				else
					keys[normal++] = key;
				}
			}
		mask>>=1;
		if(!mask)
			{
			keysmap++; mask = 0x80;
			}			
		}
	if( !normal)
		{
		lastkey = 0;
		debounce = 10;
		}
	if( normal==1)
		{
		if( lastkey!=keys[0])
			{
			thekey = lastkey = keys[0];
			if( !modifiers[2] && (thekey>='A' && thekey<='Z'))
				thekey +=32;
			debounce = 1;
			}
		else
			{
			if( debounce)
				debounce--;
			else
				{
				if( (keys[0] == '.' || keys[0] == 'Q') && modifiers[3])
					new_menu = QUIT;
				kbhit = true;
				debounce = 10;
				}
			}
		}
}

#else

void Process_keyboard()
{
EventRecord	theEvent;
long		menuResult;
short		partCode;
short		result = gotNoEvent;
char		ch;
WindowPtr	theWindow;
WindowPtr	whichWindow;
GrafPtr		savePort;

	GetKeys(keyMap);
		
// keyDownMask			= 8;			{key-down event	(bit 3)}
// keyUpMask			= 16;			{key-up event	(bit 4)}
// autoKeyMask			= 32;			{auto-key event	(bit 5)}
// updateMask			= 64;			{update event	(bit 6)}
// diskMask				= 128;		{disk-inserted event 	(bit 7)}
// activMask			= 256;		{activate event	(bit 8)}
// highLevelEventMask	= 1024;		{high-level event 	(bit 10)}
// osMask				= -32768

	if(WaitNextEvent( everyEvent, &theEvent, 0, nil ))
		{
		switch ( theEvent.what )
	  		{
	  		case mouseDown:
//	  				ClickXposn = theEvent.where.v;
//	  				ClickYposn = theEvent.where.h;
	  		case mouseUp:
	  				break;
	  		case keyDown:
					ObscureCursor();
			case autoKey:
					theWindow = FrontWindow();
				  	kbhit = true;
	  				thekey = theEvent.message & charCodeMask;
	  				if( (((theEvent.modifiers & cmdKey) !=0 ) && (thekey =='.' || thekey == (char)113)))
	  					new_menu = QUIT;
					break;
			case updateEvt:
					theWindow = (WindowPtr) theEvent.message;
//					GetPort(&savePort);
//					SetPort(theWin);
					BeginUpdate( myWindow);
//					BlitBufferToScreen( (double *) psudo_buffer);
					EndUpdate( myWindow);
//					SetPort(savePort);
					break;
			case activateEvt:
					theWindow = (WindowPtr) theEvent.message;
//					printf("Activate %d\n", ((WindowPeek) theWindow)->refCon);
					if (((WindowPeek) theWindow)->refCon == wMyWindow)
						{
						HideCursor();
						BlitBufferToScreen( (double *) psudo_buffer);
						}
				default:
					FlushEvents( everyEvent, 0);
					break;
	  		}
	  	}
}
#endif

void nethandler(void)
{
}
