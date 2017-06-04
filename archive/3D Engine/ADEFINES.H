//#define	COVER_DEMO			TRUE

struct match_player {

// Player General...
	int tm_player;
	float tm_x, tm_xdis, tm_y, tm_ydis, tm_z, tm_zdis;
	float mface_x,mface_y;
	short mface_time;
	char mface;
	float tm_dist;
	int tm_pos;
	int tm_limbo;
	short guy_on;
	char control;
	char tm_srng;
	signed char tm_off;
	char tm_stopped;
	char tm_trap;
	short special;
	short tm_strike;
	float tm_stime;
	short tm_ftime;
	short ball_state;
	short tm_fpass_type;
	short tm_fpass_to;
	char draw_me;
	short shirt;

// Player Attributes...
	int tm_rate;		//Speed.
	int tm_pow;			//Physical Power.
	int tm_cont;		//Ball Control.
	int tm_flair;		//Flair.
	int tm_vis;			//Vision.
	int tm_ac;			//Accuracy.
	int tm_stam;		//Stamina.
	int tm_disc;		//Discipline.

// Match Stats...
	int tm_book;		//Bookings.
	int tm_fouls;		//Fouls Committed.
	int tm_tacks;		//Tackles attempted.
	int tm_twon;		//Tackles won.
	int tm_shots;		//Shots attempted.
	int tm_saved;		//Shots saved.
	int tm_goals;		//Goals scored.
	int tm_pass;		//Passes attempted.
	int tm_pwon;		//Passes completed.
	int tm_inj;			//Injury type.
	int tm_posst;		//Time in possession.

// Animation Data...
	int tm_spr, turn_dir, face_dir, dir_mode;
	float tm_frm,tm_fstep;
	unsigned short tm_anim;
	unsigned char tm_hcol,tm_htype;
	float tm_mcspd;
	float ls_anim,ls_frm;
	float contact;
	char tm_newanim;
	char tm_barge;
	
// Action Data...
	int tm_act, tm_poss, tm_wall, tm_leave, tm_mark;
	int go_dist, go_cnt;
	float go_txdis,go_tydis,go_tx,go_ty,go_xoff,go_yoff,tm_jump;
	char go_stop;
	char go_step;
	char tm_notme;
	
// Player Intelligence...
	int int_move, int_cnt, mess_num, mess_cnt;
	int tm_comm,tm_ccnt;

};

#if DEBUGGING==YES
#define	DEMO_TIME			300
#else
#define	DEMO_TIME			1800
#endif
#define	SOUND_ERROR			2
#define	CONFIG_ERROR		4
#define	MOUSE_ERROR			8
#define	MATCH_ERROR			256

#define	KEYS					0xff

//#define	UP_KEY				2
//#define	DN_KEY				3
//#define	LF_KEY				0
//#define	RT_KEY				1
//#define	F1_KEY				4
//#define	F2_KEY				5

#define	English				0
#define	French				1
#define	German				2

#define  FRONT_END_TUNE "editscrn"

//#define 	PI	 					3.1415

//#define	SEQU_ADDR			0x3c4
//#define	CRTC_ADDR 			0x3d4

//#define	REAL_SPEED			20
//#define	MAX_USERS			20
//#define	TIMER_FRAC			10
//#define	TIMER_SPEED			(TIMER_FRAC*REAL_SPEED)

#define	MEG4					0
#define	MEG8					1

#define 	ON 	 				1
#define 	OFF 					255

#define	LO						0
#define	HI						1
#define	MED					1
#define	HIGH					2

#define	YES					1
#define	NO						0

#define	FRIENDLY				0
#define	LEAGUE				1
#define	CUP					2
#define	PRACTICE				3
#define	NETWORK				4

//#define	background_buffer_LEN	640*480 
//#define	psudo_buffer_LEN			(640*480)+1
//#define	sprite_buffer_LEN			993000 
//#define	spool_buffer_LEN			670000
//#define	unpack_buffer_LEN			48100
//#define	sfont_buffer_LEN			36500
//#define	mfont_buffer_LEN			42000 
//#define	bfont_buffer_LEN			42000 
//#define	texture_buffer_LEN   	12800
//#define	proptab_buffer_LEN		7000

#define	ARCADE				0
#define	SIMULATION			1


#define	PLAYER1				1
#define	PLAYER2				2
#define	PLAYER3				4
#define	PLAYER4				8

#define	PEN			  		256
#define	O_G					512
#define	CREDIT_TEAMa	 	4
#define	CREDIT_TEAMb	 	8
#define	GOAL_DISPLAYED		16

#define	USA 					0
#define	RUS					1
#define	SPN					2
#define	BUL					3
#define	BEL					4
#define	DEN					5
#define	NIR					6
#define	TUN					7
#define	ZAM					8
#define	SWZ					9
#define	CAM					10
#define	SKR					11
#define	ITA					12
#define	MOR					13
#define	ENG					14
#define	SCO					15
#define	WAL					16
#define	EGY					17
#define	COL					18
#define	SWE					19
#define	ARG					20
#define	EIR					21
#define	HOL					22
#define	FIN					23
#define	SLV					24
#define	IVR					25
#define	GHA					26
#define	ROM					27
#define	GER					28
#define	GRE					29
#define	NOR					30
#define	SAU					31
#define	FRA					32
#define	POL					33
#define	JAP					34
#define	URU					35
#define	BRA					36
#define	NIG					37
#define	MEX					38
#define	CZE					39
#define	ICE					40
#define	POR					41
#define	CHI					42
#define	BOL					43
#define  GRM					44

#define	WHT			  		45
#define	BLU			  		46

#define	F_4_3_3				0
#define	F_5_3_2				1
#define	F_6_3_1				2
#define	F_4_2_4				3
#define	F_5_1_4				4
#define	F_4_0_6				5
#define	F_3_1_6				6
#define	F_4_1_5				7
#define	F_5_2_3				8
#define	F_4_4_2				9

#ifndef TRUE
#define TRUE 					1
#define FALSE 					0
#endif
#define LARGE					0
#define SMALL					8
#define SHADOW					2

#define 	ACTIVE				1
#define 	INACTIVE				0
#define 	DELETE_OLD_SPRITE	2
#define 	OLD_SPRITE_FLAG	4
#define 	FREEZE				16*2
#define	REMOVE				32*2	
#define	INVISIBLE			64*2
#define	HALF_SPIN			128*2
#define	START_SPIN			256*2
#define	SINGLE_SPIN		 	512*2
#define	BACK_SPIN		 	1024*2
#define	MINI_BUTTON			2048*2
#define	STANDARD_BUTTON	4096*2
#define	SpriteON				8192*2

#define  PALETTE_FADE_UP	1
#define  PALETTE_FADE_DOWN	3

#define  REPL_BKG				1
#define  EDIT_TEXT			2
#define	MOUSE_OFF			4
#define  MARK_TEXT			16


#define  LEFT_BUTTON			1
#define  RIGHT_BUTTON 		2

#define SHADOWtextOFF			0
#define SHADOWtextON				1
#define RIGHTjustifyTEXT		2
#define SFONT						4
#define MFONT						8
#define BFONT						16
#define CAPS						32
#define TIGHTEN					64
#define CHISEL			  	   	128
#define SILVER_TEXTURE	   	512
#define COPY_TO_BACK		   	1024
#define CENTREjustifyTEXT		4096
#define BUTTONcentreJUSTIFY	32768

									
#define SHADOWimageON  		1
#define SHADOWimageOFF		0

#define MENU_1					1
#define MENU_2					2
#define MENU_3					3
#define MENU_4					4
#define MENU_5					5
#define MENU_6					6
#define MENU_7					7
#define MENU_8					8
#define MENU_9					9
#define MENU_10				10

#define	CURSOR_COLOUR		((9*16)+0)
//#define	BLACK					((0*16)+1)
#define	GREY					(((1*16)+0)-6)
#define	CYAN					((11*16)+12)
#define	GREEN					((11*16)+10)
#define	GREEN2				((4*16)+4)
#define	BRIGHTER_GREEN2	((4*16)+10)

#define	BRIGHT_WHITE		((1*16)+15)
#define	DULL_WHITE			((1*16)+10)
#define	BRIGHT_GRAY			((1*16)+5)
#define	DULL_GRAY			((1*16)+0)
#define	BRIGHT_GREEN		((11*16)+9)
#define	DULL_GREEN			((11*16)+10)

#define	BRIGHT_GREY			((1*16)+0)
#define	BRIGHT_YELLOW	 	((11*16)+7)
#define	BRIGHT_CYAN			((11*16)+11)

#define	BRIGHT_GREEN		((11*16)+9)
#define	BRIGHT_RED			((7*16)+12)

#define	RED_TEXT						130
#define	GREEN_STAR					75
#define	YELW_STAR					146
#define	RED_STAR						111
#define	MARK_TEXT_COLOUR			20
#define	SELECTED_TEXT_COLOUR		BRIGHT_CYAN
#define	MAX_IMAGES					18
#define	MAX_STRINGS					44
#define	MAX_LABELS					40
#define	MAX_BUTTONS					12
#define	MAX_SPRITES					44
#define	MAX_FORMATIONS				10
#define	MAX_COPIES 					74

 
#define	COACH_TEXT					1
#define	FLAIR_TEXT					2
#define	ACCURACY_TEXT				3
#define	CNTRL_TEXT					4
#define	PACE_TEXT					5
#define	VISION_TEXT					6
#define	POWER_TEXT					7
#define	STAMINA_TEXT				8
#define	DISCIPLINE_TEXT  			9
#define	PLAY_STATS_TEXT			10
#define	SKILL_TEXT					11
#define	PERC_0_TEXT					12
#define	PERC_50_TEXT				13
#define	PERC_100_TEXT				14
#define	EDIT_DATA_TEXT				15
#define	SQUAD_CHOOSE_TEXT			16
#define	ONE_TXT						17
#define	TWO_TXT						18
#define	THREE_TXT					19
#define	FOUR_TXT						20
#define	FIVE_TXT						21
#define	SIX_TXT						22
#define	SEVEN_TXT					23
#define	EIGHT_TXT					24
#define	NINE_TXT						25
#define	TEN_TXT						26
#define	ELEVEN_TXT					27
#define	TWELVE_TXT					28
#define	THIRTEEN_TXT				29
#define	FOURTEEN_TXT				30
#define	FIFTEEN_TXT					31
#define	SIXTEEN_TXT					32
#define	SEVENTEEN_TXT 				33
#define	EIGHTEEN_TXT	 			34
#define	NINETEEN_TXT	 			35
#define	TWENTY_TXT		 			36
#define	TWENTYONE_TXT	 			37
#define	TWENTYTWO_TXT	 			38
#define	ENVIRONMENT_TEXT			39
#define	PLY1_SELECT_TEXT			40
#define	PLY2_SELECT_TEXT			41
#define	PLY3_SELECT_TEXT			42
#define	PLY4_SELECT_TEXT			43
#define	COMMENTARY_TEXT 			44
#define	PARTICIPATING_TEXT		45
#define	NO_TEAMS_TEXT				46	
#define	SKY_TXT						47
#define	STADIUM_TXT					48
#define	LINE_TXT						49		
#define	VIDEO_TXT					50
#define	PLY_DET_TEXT				51
#define	PTCH_DET_TEXT				52
#define	RES_TXT						53
#define	CAM_TEXT						54
#define	SCRN_TEXT					55
#define	CROWD_TEXT					56
#define	COMM_TEXT					57
#define	MSTR_TEXT					58
#define	PITCH_TXT					59
#define	MUSIC_TXT					60
#define	AUDIO_TXT					61
#define	AUDIO_SND_TEXT				62
#define	MATCH_TEXT					63
#define	VENUE_TXT					64
#define	LGE_TBL_TEXT				65
#define	RANK_A_TEXT					66
#define	RANK_B_TEXT					67
#define	RANK_C_TEXT					68
#define	RESULT_TEXT					69
#define	END_SEASON_TEXT			70
#define	CHAMPS_TEXT					71
#define	RELIGATED_TEXT				72
#define	PROMOTED_TEXT				73
#define	REL_B_TEXT					74
#define	PRO_C_TEXT					75
#define	NO_NET_PLAYS_TEXT			76
#define	CHOOSE_TEXT					77
#define	CUP_WINNERS_TEXT			78
#define	RUNNERS_UP_TEXT			79
#define	CONTROLS_TEXT				80
#define	MEDIA_TEXT					81
#define	RULES_TEXT					82
#define	CALIBRATION_TEXT			83
#define	OFFSIDE_TXT					84
#define	SUBS_TXT						85
#define	FREEKICKS_TXT				86
#define	GAME_LEN_TEXT				87
#define	BOOKING_TXT					88
#define	WIND_TXT						89
#define	QUIT_TEXT 					90
#define	DETAIL_TEXT					91
#define	START_TEXT					92
#define	CUSTOM_TEXT					93

#define	SAVE_TEXT 					94
#define	LOAD_TEXT 					95
#define	MATCH_SETUP_TXT			96
#define	CONTROL_TEXT				97
#define	SELECTION_TEXT				98
#define	NEXT_TEXT					99
#define	DONE_TEXT					100
#define	SETUP_TXT					101
#define	AUTOMAN_TEXT				102
#define	GROUP_A_TEXT				103
#define	GROUP_B_TEXT				104
#define	GROUP_C_TEXT				105
#define	SOUND_TEXT					106
#define	RANDOM_TEXT					107
#define	FRIENDLY_TEXT				108
#define	EXTRA_TIME_TEXT			109
#define	WON_TEXT						110
#define	ON_PENS_TEXT				111
#define	NETWORK_GAME_TEXT			112
#define	COMPUTER_TEXT				113
#define	PLAYER_ONE_TEXT 			114
#define	PLAYER_TWO_TEXT		   115
#define	PLAYER_THREE_TEXT			116
#define	PLAYER_FOUR_TEXT			117
#define	OFF_TEXT						118
#define	ON_TEXT						119
#define	LOW_TEXT						120
#define	HIGH_TEXT					121
#define	MED_TEXT						122
#define	WIRE_TEXT					123
#define	FAR_TEXT						124
#define	PLAN_TEXT  					125
#define	GLINE_TEXT					126
#define	ISO_TEXT						127
#define	PLYR_TEXT					128
#define	REF_TEXT						129
#define	MONO_TEXT					130
#define	THREEd_TEXT					131
#define	ARCADE_TEXT					132
#define	SIMULATION_TEXT			133
#define	LEAGUE_TEXT					134
#define	CUP_TEXT						135
#define	DONE_TEXT2					136
#define	WAITING_TEXT				137
#define	KEY1_TEXT					138
#define	KEY2_TEXT					139
#define	JOY1_TEXT					140
#define	JOY2_TEXT					141
#define	MOUSE_TEXT					142
#define	GRAV1_TEXT					143
#define	GRAV2_TEXT					144
#define	RND1_TEXT					145
#define	RND2_TEXT					146
#define	QUTR_TEXT					147
#define	SEMI_TEXT					148
#define	FINAL_TEXT					149
#define	DIVISION1_TEXT				150
#define	DIVISION2_TEXT				151
#define	DIVISION3_TEXT				152
#define	After_Extra_TEXT			153
#define	Pd_TEXT						154
#define	Won_TEXT						155
#define	Drew_TEXT					156
#define	Lost_TEXT					157
#define	For_TEXT						158
#define	Against_TEXT				159
#define	Pts_TEXT						160
#define	GoalDiff_TEXT				161
#define	TEXT1							162							
#define	TEXT2							163
#define	TEXT3							164
#define	TEXT4							165
#define	TEXT5							166
#define	TEXT6							167
#define	TEXT7							168
#define	TEXT8							169
#define	TEXT9							170
#define	TEXT10						171
#define	TEXT11						172
#define	COACH_TEXT2					173
#define	TEAM_SELECT_TEXT			174
#define	SLOT_TITLE_TEXT			175
#define	PLAYR_TEXT					176
#define	CONTROL_METHOD_TEXT		177
#define	ROUND_UP_TEXT				178
#define	NET_SELECT_TEXT			179
#define	CENTRE_TEXT					180
#define	NEW_TEXT						181
#define	ON_PENALTIES_TEXT 		182
#define	ON_PENALTIES_TEXT2 		183
#define	CUP_WINNERS_TEXTa			184
#define	CUP_WINNERS_TEXTb			185
#define	NOT_USED_TEXT				186
#define	UNTITLED_TEXT				187
#define	NETWORK_ABORT_TEXT		188
#define	NETWORK_SYNC_TEXT			189
#define	LOADING_TEXT				190
#define	PRACTICE_TEXT				191
#define	REQUEST_DIR_TEXT			192	// 6 entries here
#define	CD_TEXT						198


#define	RESULT_TEAM_NAMEa			204
#define	RESULT_TEAM_NAMEb			205
#define	RESULT_TEAMa			  	206
#define	RESULT_TEAMb			  	207
#define	ROUNDUP_CONCLUSION 		208
#define	PLAYER_NAME_WITH_POSN	209
#define	PLAYER_STAT					210
#define	SELECTED_PLAYER_NAME		211
#define	SELECTED_TEAM_NAME		212
#define	PLAYER_FORMATION			213
#define	LEAGUE_TEAM					214
#define	PARTICIPATING_TEAM_NAME	215
#define	CHOOSE_TEAM_NAME			216
#define	FORMATION_TEXT		 		224
#define	SKY_TEXT						226
#define	STADIUM_TEXT	  			227
#define	PITCH_TEXT	  				228
#define	PLAYER_TEXT		  			229
#define	LINE_TEXT	  				230
#define	VIDI_TEXT	  				232
#define	RES_TEXT	  					233
#define	CAMERA_TEXT	  				234
#define	SIZE_TEXT	  				235
#define	AUDIO_TEXT	  				237
#define	NoOfPLAYERS_TEXT		  	241
#define	GAMEtype_TEXT		  		242
#define	COMPETITION_TEXT		  	244
#define	TEAM_NAMEa			 		243		
#define	TEAM_NAMEb			 		245
#define	VENUE_TEXT				  	246
#define	TEAM_NAMEa_SCORE	 		255
#define	TEAM_NAMEb_SCORE			256
#define	TEAMa_SCORER 				257
#define	TEAMb_SCORER				258
#define	GAMETYPE_TEXT	  			259
#define	TEAM_SEASON_END		 	260
#define	PLAYER_NAME_TEAMa			261
#define	PLAYER_NAME_TEAMb			262
#define	NETWORK_TEXT		  		264
#define	WINNERS_NAME		 		265
#define	RUNNERS_UP_NAME	 		266
											
#define  ONE_TEXT                267
#define  TWO_TEXT                268
#define  THREE_TEXT              269
#define  FOUR_TEXT               270
#define  CONTROL_1_TEXT          271
#define  CONTROL_2_TEXT				272
#define  CONTROL_3_TEXT				273
#define  CONTROL_4_TEXT				274
//#define  REDEF_TEXT 					275
//#define  JOYSTICK_TEXT				276
#define  OFFSIDE_TEXT				277
#define  SUBS_TEXT					278
#define  FREEKICKS_TEXT				279
#define  TIME_TEXT					280
#define  BOOKING_TEXT				281
#define  WIND_TEXT					282
#define	REFEREE_NAME			 	283
#define	REFEREE_COUNTRY		 	284
#define	SLOT_NAME					285
#define	SLOT_STATE					286
#define	SLOT_TITLE					287
#define	PLAYER_LABEL		 		288
#define	CONTROL_STATE	 			289
#define	CALIBRATE_TEXT				290		  		
#define	PLAYER_NAME					291
#define	KEY_TYPE					 	292
#define	COACH_NAME					293
#define	REQUEST_TEXT				294
#define	CHOSEN_KEY					295
#define	REDEFINE_TEXT				296
#define RAVE_TEXT					336

#define	HIGHLIGHTED_TEXT			1
#define	EDITABLE_TEXT				2
#define	REPRINT_TEXT 				4
#define	SELECTABLE_TEXT			8
#define	SKIP_PSUDO_RESTORE		16
#define	SKIP_COPY_DOWN				32
#define	TOGGLE_FLAG			 		64
#define	HOVERING_OVER_TEXT	 	128
#define	NET_FLAG						512

// definitions used for special print stuff!!!

#define	LEAGUE_DATA				16384		//128
#define	SCORER_DATA				8192		//128

#define	PLAYER_NAME_LEN				19
#define	COACH_NAME_LEN					18+5
//#define	PLAYER_MAX_PIXEL_LEN			(240-28)
#define	COACH_MAX_PIXEL_LEN			(300-18)+32
#define	TEAM_NAME_LEN					22
#define	NickNAME_LEN					12

#ifdef COVER_DEMO
#define	MAX_TEAMS						2
#else
#define	MAX_TEAMS						45
#endif

#define 	MAX_GOALS						91	
#define	MAX_LINES				  		5
												
#define	KIT_BUTTON						100
#define	ACTUA_BUTTON					101
#define	WAVE_BUTTON						102
#define	FLAG_BUTTON	 					103
#define	CLICK_BUTTON	 				104
#define	SILVER_CUP_BUTTON				105
#define	TEAMS_BUTTON					106
#define	TEST_BUTTON						107
#define	SLIDE_BAR	 					108
#define	SPIN_BUTTON	 					109
#define	UP_ARROW_BUTTON				110
#define	DOWN_ARROW_BUTTON				111
#define	SELECTION_BUTTON				112
#define	REF_BUTTON						113

#define	PLAYER_STAT_ICON				1
#define	TEAM_FLAG_ICON					2
#define	SILVER_CUP						3
#define	TEAMS_4_LIGHT	 				4
#define	TEAMS_8_LIGHT	 				5
#define	TEAMS_16_LIGHT	 				6
#define	TEAMS_32_LIGHT	 				7
#define	SPIN_BORDER						8
#define	SLIDER							9
#define	ACTUA_LOGO						10
#define	CHOICE_FLAG_ICON				11
#define	TEAM_BIG_FLAGa					12
#define	TEAM_BIG_FLAGb					13
#define	VERSUS_TEAM_IMAGE				14
#define	COMPETITION_IMAGE				15
#define	TEAM_KITa						16
#define	TEAM_KITb						17
#define	GOLD_CUP	  						18
#define	SERIES_IMAGE					19
#define	REF_FLAG_ICON	 				20
#define	JOYSTICK_ICON					21
#define	GREMLIN_INTERACTIVE			22
#define	RESULT_FLAG_ICON				23
#define	SMALL_V_IMAGE			  		24

#define	MENU_A0							0
#define	MENU_A1							1
#define	MENU_A2							2
#define	MENU_A3							3
#define	MENU_A4							4
#define	MENU_A5							5
#define	MENU_A6							6
#define	MENU_A7							7
#define	MENU_A8							8
#define	MENU_A9							9
#define	MENU_A10							10
#define	MENU_A11							11
#define	MENU_A12							12
#define	MENU_A13							13
#define	MENU_A14							14
#define	MENU_A15							15
#define	MENU_A16							16
#define	MENU_A17							17
#define	MENU_A18							18
#define	MENU_A19							19
#define	MENU_A21							20
#define	MENU_A22							21
#define	MENU_A23							22
#if 0
#define	MENU_A20							23
#endif
#define	MENU_A24							23
//#if ROLLING_DEMO!=OFF
//#define	MENU_A25							25
//#endif

#define	INCREASE_SELECTED_PLAYER		26
#define	DECREASE_SELECTED_PLAYER		27
#define	INCREASE_SELECTED_TEAM			28
#define	DECREASE_SELECTED_TEAM			29
#define	INCREASE_SELECTED_FORMATION	30
#define	DECREASE_SELECTED_FORMATION	31

#define	FRWD_SKY_DETAIL					32
#define	BACK_SKY_DETAIL					33
#define	FRWD_STADIUM_DETAIL				34
#define	BACK_STADIUM_DETAIL				35
#define	FRWD_LINE_DETAIL					36
#define	BACK_LINE_DETAIL					37
#define	FRWD_VIDI_WALL						38
#define	BACK_VIDI_WALL						39
#define	FRWD_PLAYERS_DETAIL				40
#define	BACK_PLAYERS_DETAIL				41
#define	FRWD_PITCH_DETAIL					42
#define	BACK_PITCH_DETAIL					43
#define	FRWD_RES								44
#define	BACK_RES								45
#define	FRWD_CAMERA							46
#define	BACK_CAMERA							47
#define	FRWD_SIZE							48
#define	BACK_SIZE							49
#define	FRWD_AUDIO							50
#define	BACK_AUDIO							51
#define	FRWD_NoOfPLAYERS					52
#define	BACK_NoOfPLAYERS					53
#define	FRWD_GameType						54
#define	BACK_GameType						55
#define	FRWD_COMPETITION		  			56
#define	BACK_COMPETITION		  			57
#define	TEAMa_SQUAD							58
#define	TEAMb_SQUAD							59
#define	FRWD_NETWORK		 				60

#define	FRWD_OFFSIDE						61
#define	BACK_OFFSIDE						62
#define	FRWD_SUBS							63
#define	BACK_SUBS							64
#define	FRWD_FREEKICKS						65
#define	BACK_FREEKICKS						66
#define	FRWD_TIME							67
#define	BACK_TIME							68
#define	FRWD_BOOKINGS						69
#define	BACK_BOOKINGS						70
#define	FRWD_WIND							71
#define	BACK_WIND							72

#define	GOTO_MENU_A0			 		   80
#define	GOTO_MENU_A1			 		   81
#define	GOTO_MENU_A2			 		   82
#define	GOTO_MENU_A3			 		   83
#define	GOTO_MENU_A4			 		   84
#define	GOTO_MENU_A5			 		   85
#define	GOTO_MENU_A6			 		   86
#define	GOTO_MENU_A7			 		   87
#define	GOTO_MENU_A8			 		   88
#define	GOTO_MENU_A9			 		   89
#define	GOTO_MENU_A10			 		   90
#define	GOTO_MENU_A11			 		   91
#define	GOTO_MENU_A12			 		   92
#define	GOTO_MENU_A13			 		   93
#define	GOTO_MENU_A14			 		   94
#define	GOTO_MENU_A15			 		   95
#define	GOTO_MENU_A16			 		   96
#define	GOTO_MENU_A17			 		   97
#define	GOTO_MENU_A18			 		   98
#define	GOTO_MENU_A19			 		   99
#define	GOTO_MENU_A20			 		   200
#define	SETUP_CNTRL							201
#define	DONE_CNTRL							202
#define	GOTO_MENU_A22			 		   203
#define	DONE_LEAGUE_DISPLAY				204
#define	DONE_CUP_DISPLAY					205
#define	GOTO_START							206
#define	QUIT_CNTRL							207
#define	PARTICIPATING_DONE				208
#define GOTO_MENU_A24					220

//#if ROLLING_DEMO!=OFF
//#define GOTO_MENU_A25					221
//#endif

#define	START_MATCH							100
#define	PLAY_MATCH							101
#define	QUIT_BUTTON							102
#define	CHOOSE_TEAMS				  		103
#define	INCREASE_TEAMa						104
#define	DECREASE_TEAMa						105
#define	INCREASE_TEAMb						106
#define	DECREASE_TEAMb						107
#define	GOTO_LEAGUE							108
#define	NEXT_SEASON						  	109

#define	TEAM_4_SELECTED	 				110
#define	TEAM_8_SELECTED	 				111
#define	TEAM_16_SELECTED	 				112
#define	TEAM_32_SELECTED	 				113


#define	MOVE_SLIDE_BAR				 		114
#define	DONE_ROUNDUP		 				115
#define  PLAY_GDV								116
//#define  FRWD_CONTROL_3						117
//#define  FRWD_CONTROL_4						118

//#define  BACK_CONTROL_1						119
//#define  BACK_CONTROL_2						120
//#define  BACK_CONTROL_3						121
//#define  BACK_CONTROL_4						122

#define	DECREASE_SELECTED_REFEREE	 	123
#define	INCREASE_SELECTED_REFEREE	 	124
#define	GOTO_SAVE							125
#define	GOTO_LOAD							126
#define	DONE_LOAD							127


#define	DEBOUNCE_BUTTONS					128

#define	NO_MOUSE								254
#define	QUIT									255
#define	UPDATE_DISPLAY						1

#define	TAB									4
#define	NCOACH								(75+TAB)
#define	N01									(15+TAB)
#define	N02									(18+TAB)
#define	N03									(18+TAB)
#define	N04									(18+TAB)
#define	N05									(17+TAB)
#define	N06									(18+TAB)
#define	N07									(18+TAB)
#define	N08									(18+TAB)
#define	N09									(18+TAB)
#define	N10									(27+TAB)
#define	N11									(24+TAB)
#define	N12									(27+TAB)
#define	N13									(27+TAB)
#define	N14									(27+TAB)
#define	N15									(26+TAB)
#define	N16									(27+TAB)
#define	N17									(27+TAB)
#define	N18									(27+TAB)
#define	N19									(27+TAB)
#define	N20									(30+TAB)
#define	N21									(27+TAB)
#define	N22									(30+TAB)

#define	PAGEnameX							600		// x coord for page name.
#define	PAGEnameY							(40-2)	// x coord for page name.

#define	LeftHEADx							130
#define	LeftHEADy							40

#define	SLIDE_BAR_XOFF						16
#define	SLIDE_BAR_YOFF						18
#define	SLIDE_BAR_WIDTH					200
#define	SLIDE_BAR_HEIGHT					9

#define	A01xTAB								26			// x coord for start of first column.
#define	A01yPOS								110		// y coord for start of first row.
#define	A01xINDENT							6			// x indentation for each column entry.
#define	A01yOFFSET							23			// y indetaction/offset between eack row.
#define	A01xTABcolumn						280		// x offset from first column to second column.

#define	A2xTAB								(640-(4*sprite76width)) /5

#define	A03xTAB								8			// x coord for start of first column.
#define	A03yPOS								82			// y coord for start of first row.
#define	A03xOFFSET							158		// x offset for next flag.
#define	A03yOFFSET							30			// y offset for next flag.
#define	STAR_CHAR							92			// charater assigned for star graphic.
#define	A03yINDENT							4			// indent in y from top of flag for team name.
#define	A03xINDENT							50			// indent in x from right edge of flag for team name.


#define	MINIxOFF								90
#define	MINIyOFF								35
#define	SNDxOFF								20
#define	SNDyOFF								35

#define	A5left			((640-(sprite84width*3))/4)
#define	A5centre			(2*((640-(sprite84width*3))/4))+sprite84width
#define	A5right			(3*((640-(sprite84width*3))/4))+(2*sprite84width)
#define	A14right			(2*((640-(sprite115width*2))/3))+(1*sprite115width)

#define	TABx4TEAMS		((640-(sprite_S62width*2))/3)
#define	TABx8TEAMS		((640-(sprite_S62width*4))/5)
#define	TABx16TEAMS		((640-(sprite_S62width*4))/5)
#define	TABx32TEAMS		((640-( (sprite_S62width/2)*5) )/10)

#define	A15yINDENT							-2
#define	A15yPOS								88			// y coord for start of first row.


#define	A5rowOFFSET							100
#define	A5row1								100
#define	A5row2								A5row1+A5rowOFFSET
#define	A5row3								A5row2+A5rowOFFSET
#define	A5row4								A5row3+A5rowOFFSET

#define	A5xTAB		 						(640-(2*(sprite84width+50) )) /4
#define	A5yTAB		 						80

#define	A08yOFF		 						110
#define	A08xTAB								640/4
#define	A08xBigTAB	  						(640-(2*sprite_999width)) /3

#define	A09xTAB								(8+24)	// x coord for start of first column.
#define	A09yPOS								(94-7)	// y coord for start of first row.
#define	A09xINDENT							5			// x indentation for each column entry.
#define	A09yOFFSET							22			// y indetaction/offset between eack row.
#define	A09xTABcolumn						(295-8)	// x offset from first column to second column.
#define	BEST_STAT_Xoff				  		26			// x offset from number label for best stat icon.

#define	CompYposn							100		// y position of competition label.

#define	A21yPOS								98
#define	A21yOFF								41

#define	LGETABxTAB							(8+24)				// x coord for start of first column.
#define	LGETAByPOS							(100-2) 				// y coord for start of first row.
#define	LGETAByOFFSET						19						// y indetaction/offset between eack row.
#define	RESbarYoff							8						// y offset addition for table bar splitter.
#define	PLAYEDxPOS					 		300					// x offset for number of games played by team.
#define	WONxPOS					 			(PLAYEDxPOS+35)	// x offset for number of games won by team.)
#define	DREWxPOS					 			(WONxPOS+35)		// x offset for number of games drawn by team.
#define	LOSTxPOS					 			(DREWxPOS+35)		// x offset for number of games lost by team.
#define	FORxPOS					 			(LOSTxPOS+35)		// x offset for number of no of goals scored by team.
#define	AGAINSTxPOS					 	  	(FORxPOS+35)		// x offset for number of no of goals let in by team.
#define	PTSxPOS					 		  	(AGAINSTxPOS+35)	// x offset for number of no of point given to team.
#define	GOALdiffxPOS			  		  	(PTSxPOS+35)		// x offset for goal difference of team

#define	FORM_PITCH_xOFF	  				296					// x coord for formation pitch.
#define	FORM_PITCH_yOFF	  				(91-6)				// y coord for formation pitch.

#define	COACHoffset							96

struct button_info {
	int			button_type;
	int			button_index;
	int			button_flags;
	short			button_xposn;
	short			button_yposn;
	short			buttonShadow_xposn;
	short			buttonShadow_yposn;
	int			button_left_select;
	int			button_right_select;
	short 		BoundingBoxLeft;
	short 		BoundingBoxTop;
	short 		BoundingBoxRight;
	short 		BoundingBoxBottom;
	int			FrameCounter;
	int			FrameSpeed;
	int			NoOfFrames;
	short			CopyWidth;
	short			CopyHeight;
	int			LastButtonNo;
	int			border_frame;
	int			button_text;
	
            		 };


#define		ButtonCentre_X	((640-sprite84width)/2)
#define		ButtonCentre_Y	((480-sprite84height)-10)	
#define		ButtonLeft_X	8
#define		ButtonLeft_Y	((480-sprite84height)-10)	
#define		ButtonRight_X	((640-sprite84width)-8)
#define		ButtonRight_Y	((480-sprite84height)-10)	

#define     ButtonRight2_X ((640-sprite84width)-18)
#define     ButtonRight3_X ((640-sprite84width)-38)
#define     ButtonRight4_X ((640-sprite84width)-68)


struct sprite_info {
	int			sprite_state;
	int			sprite_flags;
	int			sprite_type;
	short			sprite_xposn;
	short			sprite_yposn;
	short			spriteShadow_xposn;
	short			spriteShadow_yposn;
	short			CopyAreaX;
	short			CopyAreaY;
	short			CopyWidth;
	short			CopyHeight;
	int			LastSpriteNo;
	int			FrameCounter;
	int			FrameSpeed;
	int			NoOfFrames;
	int			NewSpriteFrame;
            		 };



struct string_info	{
					int	string_type;
					int	string_array;
					int	stat_array;
					int	string_flags;
					short	string_xposn;
					short	string_yposn;
					short	string_colour;
					short string_mark_colour;
					int	string_shadow;
					int	max_string_chars;		// int
					int	max_string_size;
					short BoundingBoxLeft;
					short BoundingBoxTop;
					short BoundingBoxRight;
					short BoundingBoxBottom;
					short	CopyAreaX;
					short	CopyAreaY;
					short	CopyWidth;
					short	CopyHeight;
	     					};

typedef struct {

	int				BkgBITMAPfile;
	int				HeaderBITMAPfile;
	short				HeaderXposn;
	short				HeaderYposn;
	int				PaletteDATAfile;
	short				ImageLIST[MAX_IMAGES];
	short				LabelLIST[MAX_LABELS];
	string_info		StringLIST[MAX_STRINGS];
	button_info		ButtonLIST[MAX_BUTTONS];
	sprite_info		SpriteTABLE[MAX_SPRITES];	
					}menu;


struct control_data	{
	int				control_type;
	short				control_yoff;
	char				control_mask;
						};

typedef	struct	{
	control_data	 controlLIST[4];
					}controls;



typedef struct {

	unsigned	long	offset;
	unsigned	long	size;
					}offset_file;


typedef struct {
	short	CopyAreaX;
	short	CopyAreaY;
	short	CopyWidth;
	short	CopyHeight;
		       	}copydata;

#define		LAB01		1
#define		LAB02		2
#define		LAB03		3
#define		LAB04		4
#define		LAB05		5
#define		LAB06		6
#define		LAB07		7
#define		LAB08		8
#define		LAB09		9
#define		LAB10		10
#define		LAB11		11
#define		LAB12		12
#define		LAB13		13
#define		LAB14		14
#define		LAB15		15
#define		LAB16		16
#define		LAB17		17
#define		LAB18		18
#define		LAB19		19
#define		LAB20		20
#define		LAB21		21
#define		LAB22		22
#define		LAB23		23
#define		LAB24		24
#define		LAB25		25
#define		LAB26		26
#define		LAB27		27
#define		LAB28		28
#define		LAB29		29
#define		LAB30		30
#define		LAB31		31
#define		LAB32		32
#define		LAB33		33
#define		LAB34		34
#define		LAB35		35
#define		LAB36		36
#define		LAB37		37
#define		LAB38		38
#define		LAB39		39
#define		LAB40		40
#define		LAB41		41
#define		LAB42		42
#define		LAB43		43
#define		LAB44		44
#define		LAB45		45
#define		LAB46		46
#define		LAB47		47
#define		LAB48		48
#define		LAB49		49
#define		LAB50		50
#define		LAB51		51
#define		LAB52		52
#define		LAB53		53
#define		LAB54		54
#define		LAB55		55
#define		LAB56		56
#define		LAB57		57
#define		LAB58		58
#define		LAB59		59
#define		LAB60		60
#define		LAB61		61
#define		LAB62		62
#define		LAB63		63
#define		LAB64		64
#define		LAB65		65
#define		LAB66		66
#define		LAB67		67
#define		LAB68		68
#define		LAB69		69
#define		LAB70		70
#define		LAB71		71
#define		LAB72		72
#define		LAB73		73
#define		LAB74		74
#define		LAB75		75
#define		LAB76		76
#define		LAB77		77
#define		LAB78		78
#define		LAB79		79
#define		LAB80		80
#define		LAB81		81
#define		LAB82		82
#define		LAB83		83
#define		LAB84		84
#define		LAB85		85
#define		LAB86		86
#define		LAB87		87
#define		LAB88		88
#define		LAB89		89
#define		LAB90		90
#define		LAB91		91
#define		LAB92		92
#define		LAB93		93
#define		LAB94		94
#define		LAB95		95
#define		LAB96		96
#define		LAB97		97
#define		LAB98		98
#define		LAB99		99
#define		LAB100	100
#define		LAB101	101
#define		LAB102	102
#define		LAB103	103
#define		LAB104	104
#define		LAB105	105
#define		LAB106	106
#define		LAB107	107
#define		LAB108	108
#define		LAB109	109
#define		LAB110	110
#define		LAB111	111
#define		LAB112	112
#define		LAB113	113
#define		LAB114	114
#define		LAB115	115
#define		LAB116	116
#define		LAB117	117
#define		LAB118	118
#define		LAB119	119
#define		LAB120	120
#define		LAB121	121
#define		LAB122	122
#define		LAB123	123
#define		LAB124	124
#define		LAB125	125
#define		LAB126	126
#define		LAB127	127
#define		LAB128	128
#define		LAB129	129
#define		LAB130	130
#define		LAB131	131
#define		LAB132	132
#define		LAB133	133
#define		LAB134	134
#define		LAB135	135
#define		LAB136	136

#define     LAB137  137
#define     LAB138  138
#define     LAB139  139
#define     LAB140  140
#define     LAB141  141
#define     LAB142  142
#define     LAB143  143
#define     LAB144  144
#define     LAB145  145
#define     LAB146  146
#define     LAB147  147
#define     LAB148  148
#define     LAB149  149
#define     LAB150  150
#define     LAB151  151
#define     LAB152  152
#define     LAB153  153
#define     LAB154  154
#define     LAB155  155
#define     LAB156  156
#define     LAB157  157
#define     LAB158  158
#define     LAB159  159
#define     LAB160  160
#define     LAB161  161
#define     LAB162  162
#define     LAB163  163
#define     LAB164  164
#define     LAB165  165
#define     LAB166  166
#define     LAB167  167
#define     LAB168  168
#define     LAB169  169
#define     LAB170  170
#define		LAB171	171
#define		LAB172	172
#define		LAB173	173
#define		LAB174	174
#define		LAB175	175
#define		LAB176	176
#define		LAB177	177
#define		LAB178	178
#define		LAB179	179

typedef struct {

	short			LabelXposn;
	short			LabelYposn;
	short			LabelColour;
	char			TextLabel;
	char			LabelText[98];
	int			LabelShadow;

            	}label;


#define		IMG01	1
#define		IMG02	2
#define		IMG03	3
#define		IMG04	4
#define		IMG05	5
#define		IMG06	6
#define		IMG07	7
#define		IMG08	8
#define		IMG09	9
#define		IMG10	10
#define		IMG11	11
#define		IMG12	12
#define		IMG13	13
#define		IMG14	14
#define		IMG15	15
#define		IMG16	16
#define		IMG17	17
#define		IMG18	18
#define		IMG19	19
#define		IMG20	20
#define		IMG21	21
#define		IMG22	22
#define		IMG23	23
#define		IMG24	24
#define		IMG25	25
#define		IMG26	26
#define		IMG27	27
#define		IMG28	28
#define		IMG29	29
#define		IMG30	30
#define		IMG31	31
#define		IMG32	32
#define		IMG33	33
#define		IMG34	34
#define		IMG35	35
#define		IMG36	36
#define		IMG37	37
#define		IMG38	38
#define		IMG39	39
#define		IMG40	40
#define		IMG41	41
#define		IMG42	42
#define		IMG43	43
#define		IMG44	44
#define		IMG45	45
#define		IMG46	46
#define		IMG47	47
#define		IMG48	48
#define		IMG49	49
#define		IMG50	50
#define		IMG51	51
#define		IMG52	52
#define		IMG53	53
#define		IMG54	54
#define		IMG55	55
#define		IMG56	56
#define		IMG57	57
#define		IMG58	58
#define		IMG59	59
#define		IMG60	60
#define		IMG61	61
#define		IMG62	62
#define		IMG63	63
#define		IMG64	64
#define		IMG65	65
#define		IMG66	66
#define		IMG67	67
#define		IMG68	68
#define		IMG69	69
#define		IMG70	70
#define     IMG71 71
#define     IMG72 72
#define     IMG73 73
#define     IMG74 74
#define     IMG75 75
#define     IMG76 76
#define     IMG77 77
#define     IMG78 78
#define     IMG79 79
#define     IMG80 80
#define     IMG81 81
#define     IMG82 82
#define     IMG83 83
#define     IMG84 84
#define     IMG85 85
#define     IMG86 86
#define     IMG87 87
#define     IMG88 88
#define     IMG89 89
#define     IMG90 90
#define     IMG91 91
#define     IMG92 92
#define     IMG93 93
#define     IMG94 94
#define     IMG95 95
#define     IMG96 96
#define     IMG97 97
#define     IMG98 98
#define     IMG99 99

typedef struct {

	short			ImageXposn;
	short			ImageYposn;
	short			ImageShadowXposn;
	short			ImageShadowYposn;
	int			ImageNumber;
	int			ImageState;

            	}image;


#define	MOUSE_IMAGE			0
#define	MOUSE_IMAGE_L		1
#define	MOUSE_IMAGE_R		2
#define	FLAIR_IMAGE			3
#define	ACCURACY_IMAGE		4
#define	CONTROL_IMAGE		5
#define	PACE_IMAGE			6
#define	VISION_IMAGE 		7
#define	POWER_IMAGE 		8
#define	STAMINA_IMAGE 		9
#define	DISCIPLINE_IMAGE 	10
#define	STATS_BAR_IMAGE	11
#define	USA_KIT_IMAGE		12
#define	RUS_KIT_IMAGE		13
#define	SPN_KIT_IMAGE		14
#define	BUL_KIT_IMAGE		15
#define	BEL_KIT_IMAGE		16
#define	DEN_KIT_IMAGE		17
#define	NIR_KIT_IMAGE		18
#define	TUN_KIT_IMAGE		19
#define	ZAM_KIT_IMAGE		20
#define	SWZ_KIT_IMAGE		21
#define	CAM_KIT_IMAGE		22
#define	SKR_KIT_IMAGE		23
#define	ITA_KIT_IMAGE		24
#define	MOR_KIT_IMAGE		25
#define	ENG_KIT_IMAGE		26
#define	SCO_KIT_IMAGE		27
#define	WAL_KIT_IMAGE		28
#define	EGY_KIT_IMAGE		29
#define	COL_KIT_IMAGE		30
#define	SWE_KIT_IMAGE		31
#define	ARG_KIT_IMAGE		32
#define	EIR_KIT_IMAGE		33
#define	HOL_KIT_IMAGE		34
#define	FIN_KIT_IMAGE		35
#define	SLV_KIT_IMAGE		36
#define	IVR_KIT_IMAGE		37
#define	GHA_KIT_IMAGE		38
#define	ROM_KIT_IMAGE		39
#define	GER_KIT_IMAGE		40
#define	GRE_KIT_IMAGE		41
#define	NOR_KIT_IMAGE		42
#define	SAU_KIT_IMAGE		43
#define	FRA_KIT_IMAGE		44
#define	POL_KIT_IMAGE		45
#define	JAP_KIT_IMAGE		46
#define	URU_KIT_IMAGE		47
#define	BRA_KIT_IMAGE		48
#define	NIG_KIT_IMAGE		49
#define	MEX_KIT_IMAGE		50
#define	CZE_KIT_IMAGE		51
#define	ICE_KIT_IMAGE		52
#define	POR_KIT_IMAGE		53
#define	CHI_KIT_IMAGE		54
#define	BOL_KIT_IMAGE		55
#define  GRM_KIT_IMAGE		56

#define  WHT_KIT_IMAGE		57
#define  BLU_KIT_IMAGE		58

#define	STATS_HEAD_IMAGE	57+2
#define	ACTUA_FLAG_IMAGE	58+2
#define	FORM_PITCH_IMAGE	59+2
#define	STADIUM_IMAGE 		60+2
#define	ENV_BAR_IMAGE		61+2
#define	RESULT_BAR_IMAGE	62+2
#define	CLICK_IMAGE			63+2
#define	SILVER_CUP_IMAGE	64+2	
#define	TEAMS_4				77+2
#define	TEAMS_8				78+2
#define	TEAMS_16				79+2
#define	TEAMS_32				80+2
#define	TEAMS_4_HIGHLGT	81+2
#define	TEAMS_8_HIGHLGT	82+2
#define	TEAMS_16_HIGHLGT	83+2
#define	TEAMS_32_HIGHLGT	84+2
#define	SPIN_BUTTON_IMAGE	85+2
									  
#define	MINI_SPIN_IMAGE	(SPIN_BUTTON_IMAGE+15)
#define	GREEN_BAR_IMAGE	(MINI_SPIN_IMAGE+15)
#define	SLIDE_BAR_IMAGE	(GREEN_BAR_IMAGE+1)
#define	SLIDE_IMAGE	  		(SLIDE_BAR_IMAGE+1)

#define	PLAYER1_IMAGE		(SLIDE_IMAGE+1)
#define	PLAYER2_IMAGE		(PLAYER1_IMAGE+1)
#define	PLAYER3_IMAGE		(PLAYER2_IMAGE+1)
#define	PLAYER4_IMAGE		(PLAYER3_IMAGE+1)

#define	VERSUS_IMAGE		(PLAYER4_IMAGE+1)
#define	GOLD_CUP_BIG		(VERSUS_IMAGE+1)
#define	BIG_BALL_IMAGE		(GOLD_CUP_BIG+1)
#define	SILVER_CUP_BIG		(BIG_BALL_IMAGE+1)

#define	UP_ARROW_IMAGE		(SILVER_CUP_BIG+1)
#define	DOWN_ARROW_IMAGE	(UP_ARROW_IMAGE+1)
#define	SELECTION_IMAGE	(DOWN_ARROW_IMAGE+1)

#define	GOLD_CUP_IMAGE		(SELECTION_IMAGE+1)
#define	SERIES_LOGO			(GOLD_CUP_IMAGE+14)

#define  DISK_IMAGE			(SERIES_LOGO+1)
#define  BOOTS_IMAGE			(DISK_IMAGE+1)
#define  RULES_IMAGE			(BOOTS_IMAGE+1)
#define  SMALL_GREEN_IMAGE (RULES_IMAGE+1)
#define  SMALL_GREM_LOGO   (SMALL_GREEN_IMAGE+1)
#define  JOYSTICK_IMAGE    (SMALL_GREM_LOGO+1)

#define	REFS_KIT_IMAGE		(JOYSTICK_IMAGE+1)
#define	REFS_BAR_IMAGE		(REFS_KIT_IMAGE+1)
#define	VR_IMAGE				(REFS_BAR_IMAGE+1)
#define	VRDISK_IMAGE  		(VR_IMAGE+1)

#define	USA_FLAG				(VRDISK_IMAGE+1)
#define	RUSSIA_FLAG			(USA_FLAG+8)
#define	SPAIN_FLAG			(RUSSIA_FLAG+8)
#define	BULGARIA_FLAG		(SPAIN_FLAG+8)
#define	BELGIUM_FLAG		(BULGARIA_FLAG+8)
#define	DENMARK_FLAG		(BELGIUM_FLAG+8)
#define	N_IRELAND_FLAG		(DENMARK_FLAG+8)
#define	TUNISIA_FLAG		(N_IRELAND_FLAG+8)
#define	ZAMBIA_FLAG			(TUNISIA_FLAG+8)
#define	SWITZERLAND_FLAG	(ZAMBIA_FLAG+8)
#define	CAMEROON_FLAG		(SWITZERLAND_FLAG+8)
#define	KOREA_FLAG			(CAMEROON_FLAG+8)
#define	ITALY_FLAG			(KOREA_FLAG+8)
#define	MOROCCO_FLAG		(ITALY_FLAG+8)
#define	ENGLAND_FLAG		(MOROCCO_FLAG+8)
#define	SCOTLAND_FLAG		(ENGLAND_FLAG+8)
#define	WALES_FLAG			(SCOTLAND_FLAG+8)
#define	EGYPT_FLAG			(WALES_FLAG+8)
#define	COLUMBIA_FLAG		(EGYPT_FLAG+8)
#define	SWEDEN_FLAG			(COLUMBIA_FLAG+8)
#define	ARGENTINA_FLAG		(SWEDEN_FLAG+8)
#define	EIRE_FLAG			(ARGENTINA_FLAG+8)
#define	HOLLAND_FLAG		(EIRE_FLAG+8)
#define	FINLAND_FLAG		(HOLLAND_FLAG+8)
#define	SLOVAKIA_FLAG		(FINLAND_FLAG+8)
#define	IVORY_FLAG			(SLOVAKIA_FLAG+8)
#define	GHANA_FLAG			(IVORY_FLAG+8)
#define	ROMANIA_FLAG		(GHANA_FLAG+8)
#define	GERMANY_FLAG		(ROMANIA_FLAG+8)
#define	GREECE_FLAG			(GERMANY_FLAG+8)
#define	NORWAY_FLAG			(GREECE_FLAG+8)
#define	SAUDI_FLAG			(NORWAY_FLAG+8)
#define	FRANCE_FLAG			(SAUDI_FLAG+8)
#define	POLAND_FLAG			(FRANCE_FLAG+8)
#define	JAPAN_FLAG			(POLAND_FLAG+8)
#define	URUGUAY_FLAG		(JAPAN_FLAG+8)
#define	BRAZIL_FLAG			(URUGUAY_FLAG+8)
#define	NIGERIA_FLAG		(BRAZIL_FLAG+8)
#define	MEXICO_FLAG			(NIGERIA_FLAG+8)
#define	CZECH_FLAG			(MEXICO_FLAG+8)
#define	ICELAND_FLAG		(CZECH_FLAG+8)
#define	PORTUGAL_FLAG		(ICELAND_FLAG+8)
#define	CHINA_FLAG			(PORTUGAL_FLAG+8)
#define	BOLIVIA_FLAG		(CHINA_FLAG+8)
#define	GREMLIN_FLAG		(BOLIVIA_FLAG+8)
#define	ACTUA_FLAG			(GREMLIN_FLAG)
#define	SPOOL_START			(USA_FLAG)
#define	BIG_FLAG				(ACTUA_FLAG+8)
#define	BIG_FLAG_s			(BIG_FLAG+45)

#define		POS01		0
#define		POS02		1
#define		POS03		2
#define		POS04		3
#define		POS05		4
#define		POS06		5
#define		POS07		6
#define		POS08		7
#define		POS09		8
#define		POS10		9
#define		POS11		10
#define		POS12		11
#define		POS13		12
#define		POS14		13
#define		POS15		14
#define		POS16		15
#define		DIV1		0
#define		DIV2		1
#define		DIV3		2
							
typedef struct {

	short			spriteWidth;
	short			spriteHeight;
	long			spriteOffset;

            	}sprite;

#define	PACE					0
#define	POWER					1
#define	CONTROL				2
#define	FLAIR					3
#define	VISION				4
#define	ACCURACY				5
#define	STAMINA				6
#define	DISCIPLINE			7
#define	REFS_VISION			8
#define	REFS_DISCIPLINE	9

#define	SUBSTITUTE 			1
#define	DISCIPLINARY_PTS	2


typedef	struct 
{
	char			name[PLAYER_NAME_LEN+1];
	char			goal_index;

	char			pace;
	char			power;
	char			control;
	char			flair;
	char			vision;
	char			accuracy;
	char			stamina;
	char			discipline;

	char 			flags;

	char			squad_number;
	char			position;	
	char			skin_tone;
} player_info;

struct referee_info
{
	char			name[PLAYER_NAME_LEN+1];
	char			vision;
	char			discipline;
	short 		country;
};

struct	restore_data
{
	int			division;
	int			position;	
};	


struct team_info
{
	char 			name[TEAM_NAME_LEN+1];
	char 			coachname[COACH_NAME_LEN+1];
	int			division;
	int			position;	
	int			played;
	int			won;
	int			drew;
	int			lost;
	int			goals_for;
	int			goals_against;
	int			points;
	int			goal_diff;
	int			team_no;		
	char 			Nickname[NickNAME_LEN+1];
	int			ranking,team_number;
	char			player_control,fixture_no;
	int			big_flag;
	int			formation;
	int			auto_formation;
	int			cup_key;
	char 			country_code[3];	// Country Code for Samples
	int			computer_formation;
	player_info	players[22];

};

#define	PITCH_WID		269
#define	PITCH_HI			169

struct formation_info
{
	char 			formation_no[3];
	short			formation_xposn;
	short			formation_yposn;
	int			formation_flags;
	char			position_type;
};

#define			GK			0
#define			DF			1
#define			MD			2
#define			FD			3

struct team_formation
{
	formation_info	formations[22];
};


struct	swap_player_buffer
{
	player_info	players[1];
};	


struct 	redefine_info
{
					short	string_xposn;
					short	string_yposn;
};

	#include "Sprite Defines.h"

struct choose_setup
{
	int			str_flags;
	int			spr_flags;
	char			type;
	short			xposn;
	short			yposn;
	short			spr_xposn;
	short			spr_yposn;
	short 		BoundingBoxLeft;
	short 		BoundingBoxTop;
	short 		BoundingBoxRight;
	short 		BoundingBoxBottom;
	short			CopyAreaX;
	short			CopyAreaY;
	short			CopyWidth;
	short			CopyHeight;
};

struct choose_offsets
{
	short			x_off;
	short			y_off;
};
struct choose_info
{
	choose_offsets	offsets[3];
	choose_setup	choose[44];
};


//				DATA STRUCTURES TO BE SAVED


typedef struct {
					int	cheat_mode;
					int	Port_toggle;
					int	Ranking_Division;
					int 	PointsForWin;
					int	match_number;
					int	round_up_page;
					char	roundup_games;
					char	league_rndup;
					int	cup_tie; 
					int	Round_index;
					int	Round_counter;
					int	RoundPrint;
					int	cup_match_number;
					char	GDVres;
 					char	winners;
					char	runners_up;
					short	cup_team_a;
					short	cup_team_b;
					int	OldCTRL1, OldCTRL2;
					int	number_of_cup_teams;
					int	gdv_gran;
 					char	which_gdv;
 
					int	keys_used[12];
				
            	}batch_data;				


typedef struct {

	short			sky_toggle;
	short			stadium_toggle;
	short			line_toggle;
	short			vidi_toggle;
	short			players_toggle;
	short			pitch_toggle;
	short			res_toggle;
	short			camera_toggle;
	short			size_toggle;
	short			audio_toggle;

	short			menu_res;
	short			camera;
	short			audio;
	int				crowd;
	int				pitch;
	int				commentary;
	int				music;
	int				master;

	short			timeit;											 	
	short			vidi;

	char			match_number;	 		// match/league week number.	  -1 = needs initialising.
	int				team_a_score;			// score for team_a
	int				team_b_score;			// score for team_b

	int				penalties;
	int 			extra;

	int				team_a_penalties;
	int				team_b_penalties;
	int				venue;
	char			tac_1;
	char			tac_2;

	short			offside;
	short			substitutes;
	short			freekicks;
	short			time;
	short			bookings;
	short			wind;

	short			offside_toggle;
	short			substitutes_toggle;
	short			freekicks_toggle;
	short			time_toggle;
	short			bookings_toggle;
	short			wind_toggle;

	int				CompetitionType;
	int				CompetitionType_toggle;
	int				NoOfPlayers;
	int				NoOfPlayers_toggle;
	int				GameType;
	int				GameType_toggle;

	int				CROWD;
	int				COMMENTRY;
	int				MASTER;
	int				PITCH;
	int				MUSIC;

	int				referee;
	int				match_referee;
	int				referee_vision;
	int				referee_discipline;

	char			control_methods[4];
	char			tga_enable;
	
	int				return_mins;
	int				rand;	
  	char			language;
											
            	}match_data;				








struct fixture_info	{
					int	home_team;
					int	away_team;
					int	league_table;
	     					};

typedef struct {
					fixture_info		fixture_data;	
					}fixture_table;



struct result_info	{
					int	team_a_score;
					int	team_b_score;
					int	team_a;
					int	team_b;
					int	penalties;
					int 	extra;
					int	team_a_penalties;
					int	team_b_penalties;
	     					};

typedef struct {
					result_info		result_data;	
					}result_table;







struct goal_info	{
					char	used;
					int	scorer;
					int	time;
	     			  	};

typedef struct		{

					goal_info		goal_data;	

						}goal_table;




typedef struct {
					int control_p1;
					int control_p2;
					int control_p3;
					int control_p4;
					}a_control_table;
