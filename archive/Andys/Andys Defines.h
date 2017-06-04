/* Conditional Compilation */

//#undef EURO96

//#define STOP_TIME_WASTING
#define FORCE_SELECT
//#define NET_DEBUG
//#define CROWD
//#define NET_GAME
//#define FRONT_END
//#define ECTS
//#define ONE_MACHINE		// head to head!
//#define COVERDISK
//#define MEG4
//#define DEMO
//#define SUPPORT_LP
//#define WAYNE
//#define SAVE_GAME

// DEFININITIONS

#define SAVE_GAME_SIZE (25000)		// Bytes...

// Font colours.

#define WHITE 31
#define BLACK 0
#define TEAM1COL 32
#define TEAM2COL 56

// Commentary Trigger Defines

#define GOOD_SWERVE (0.038)
#define LONG_PASS_DIST (prat*34)
#define HAS_BALL_DELAY 4

// Front End Defines

#define FRIENDLY 0
#define LEAGUE 1
#define CUP 2
#define PRACTICE 3
#define NETWORK 4
#define PENALTIES 5

// Formations.

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

// Memory Stuff.

#define MEM8 3000000

// Maths
#define D2RAD PI/180

// Match situations.

#define NORMAL_PLAY 0
#define CORNER_TL 1
#define CORNER_TR 2
#define CORNER_BL 3
#define CORNER_BR 4
#define CENTRE_A 5
#define CENTRE_B 6
#define GOAL_KICK_TL 7
#define GOAL_KICK_BL 8
#define GOAL_KICK_TR 9
#define GOAL_KICK_BR 10
#define THROW_IN_A 11
#define THROW_IN_B 12
#define IF_KICK_A 13
#define IF_KICK_B 14
#define DF_KICK_A 15
#define DF_KICK_B 16
#define PEN_KICK_A 17
#define PEN_KICK_B 18
#define SWAP_ENDS 19
#define GAME_FINISHED 20

// Set-Piece situations.

#define SETP_CORNER 1
#define SETP_THROW 2
#define SETP_CENTRE 3
#define SETP_PENALTY 4
#define SETP_IFKICK 5
#define SETP_DFKICK 6
#define SETP_GKICK 7

#define SPACT_FPASS 1
#define SPACT_HPASS 2
#define SPACT_TEE_UP 3
#define SPACT_DPASS 4
#define SPACT_GRND 5
#define SPACT_CHIP 6
#define SPACT_DRIVE 7
#define SPACT_KICK 8
#define SPACT_NEWK 9

/*******************/
// Player Actions. //
/*******************/

// Types of strike on ball...

#define KT_PASS 1
#define KT_PUNT 2
#define KT_SHOOT 3

// Set-piece moves

#define PASS_FEET 1
#define PASS_HEAD 2
#define TEE_UP 3
#define DRIVE_SHOT 4
#define SHOOT 5
#define PUNT 6

#define STAND_ACT 0
#define RUN_ACT 1
#define TURN_ACT 2
#define TACKLE_ACT 3
#define JUMP_ACT 4
#define FALL_ACT 5
#define RISE_ACT 6
#define STRIKE_ACT 7
#define RIDE_ACT 8
#define WIND_ACT 9
#define SAVE_ACT 10
#define THROW_ACT 11
#define KPHOLD_ACT 12
#define OFF_ACT 12
#define STRUCKB_ACT 13
#define STEAL_ACT 14
#define KICK_ACT 15
#define CELEB_ACT 16
#define CONTROL_ACT 17
#define WAIT_ACT 18
#define PICKUP_ACT 19
#define STOP_ACT 20

#define KP_A 1
#define KP_B 12

// Officials Intentions.

#define LM_GO_RIGHT 1
#define LM_GO_LEFT -1

// Player Intentions.

#define I_INTERCEPT 1
#define I_DRIBBLE 2
#define I_CLOSE_DOWN 3
#define I_SAVE_WAIT 4
#define I_HEADER 5
#define I_THROW 6
#define I_OFF 7
#define I_RUN_ON 8
#define I_STEAL 9
#define I_GET_UP 10
#define I_KP_BUSY 11
#define I_KICKED 12
#define I_RECEIVE 13
#define I_BARGE 14
#define I_RUNUP 15
#define I_CELEB 16

// Player Comments.

#define SAY_FOUL 1
#define SAY_PASS 2
#define SAY_12 3
#define SAY_SHIT 4
#define SAY_PUNT 5
#define SAY_CROSS 6
#define SAY_GIVE 7
#define SAY_OFFSIDE 8
#define SAY_ADV 9
#define SAY_PENALTY 10
#define SAY_REF 11
#define SAY_TIMEW 12

// Dimensions and ranges.

#define ncb (22+3+1)

#define IM_THERE_DIST 2
#define SUB_DELAY (16*REAL_SPEED)
#define KP_OFFLINE 16
#define KICK_AHEAD_ANG (0.966)		// Around 15 degrees
#define CLOSE_ANG_DIST (prat*16)
#define MIN_HEADER_POW 192.0
#define MIN_HEADER_RNG (4.0*prat)
#define MIN_PASS_DIST (prat*8.0)
#define MIN_SHOOT_DIST (prat*12.0)
#define OPTIMUM_PASS (prat*10.0)
#define BESIDE_BALL 5
//#define MAX_USERS 20
//#define MAX_NET_USERS 20
#define MAX_3D_SPRS 100
#define PLAYER_HEIGHT 25
#define TOUCHB_BOX 8
#define HEADER_CONTACT 8
#define SAVE_CONTACT 16.
#define KP_SAVE_MARGIN 2.4
#define SAVE_ACC 64
#define KEEPB_BOX 20
#define VISION_MULT 5
#define AT_FEET_DIST 10
#define IN_HANDS_DIST 10
#define DANGER_AREA (8.0*prat)
#define MEGA_DANGER_AREA (2.0*prat)
#define DRIB_DANGER_AREA (13.0*prat)
#define BETWEEN_DIST (3.0*prat)
#define LOW_PASS_DIST (18.0*prat)
#define KP_MIN_PASS_DIST (10.0*prat)
#define MUST_RUN_DIST (8.0*prat)
#define GO_TO_POS_DIST (0.8*prat)
#define CALL_DIST (60.0*prat)
#define TACKLE_TURNS 30
#define FALL_TURNS 24
#define SAVE_TURNS 4
#define PLAYER_SIZE (1.0*prat)
#define UNIT 1.0
#define TUNIT 32767
#define DIAG 0.7071068
#define TDIAG 23170
#define STEP_RANGE (3.8*prat)
#define AIR_FRICTION (0.986)
#define GRND_FRICTION (0.965)
#define INCIDENT_DIST (prat*10)
#define PASS_ACC_ARC 0.1
#define MAX_XY_CSW 0.12
#define MAX_Z_CSW 0.12
#define MAX_XY_USW 0.14
#define MAX_Z_USW 0.12
#define SW_HOLD_FACTOR 4.0
#define FACING_ANGLE 0.95	//18 degrees
#define STEAL_DIST (6.0*prat)
#define STEAL_BODY_DIST (1.5*prat)
#define STEAL_FOOT_DIST (0.5*prat)
#define REBOUND_FACTOR 0.8
#define MUST_MARK_DIST (prat*32)
#define FSELECT_DIST (prat*2)
#define SPEECH_SECS 3
#define OFFSIDE_REL_CNT 40
#define LONG_RANGE (prat*25)
#define MAX_CAM_DIF 140
#define LINE_UP_DELAY (7*REAL_SPEED)
#define MAX_GOOD_POSS 9000
#define MAX_SETP_WAIT (250*REAL_SPEED)

// FX.
#define INIT_SCALE 440.
#define IN_AIR_SPIN (-0.2)
#define MAX_WIND 1
#define MAX_WIND_CHANGE (0.4)	// 5 degrees
#define MAX_WIND_S_CHANGE (4.)
#define WIND_BLUSTERINESS 8
#define WIND_GUSTINESS 4

// Rates
#ifdef EURO96
#define SCORE_WAIT 220
#else
#define SCORE_WAIT 140
#endif

#define FALL_RATE 4
#define TACKLE_DECEL (0.92)
#define SAVE_DECEL (0.75)
#define PEN_SCORE_WAIT 60
#define CENTRE_WAIT 125

//#define REAL_SPEED 20
//#define TIMER_FRAC 10
//#define TIMER_SPEED (TIMER_FRAC*REAL_SPEED)

#define VERT_BALL_DAMP 0.6
#define EFFECTIVE_TACK 16
#define CAM_MODE_BUFFER 30

// Probabilities.

#define SOCKS_PROB 15

#define MIN_HELP_CHANCE 2
#define MIN_PASS_PROB 125
#define MAX_PASS_PROB 5
#define MIN_RUN_PROB 16
#define MIN_PUNT_PROB 3
#define MIN_SHOOT_PROB 4
#define TACKLE_PROB 64
#define GREED_FACTOR 100

// Input control types.

enum { NO_CTRL, JOY1_CTRL, JOY2_CTRL, KEY1_CTRL, KEY2_CTRL, NET_CTRL };
//#define NO_CTRL 0
//#define JOY1_CTRL 1
//#define JOY2_CTRL 2
//#define MOUSE_CTRL 3
//#define KEY1_CTRL 4
//#define KEY2_CTRL 5
//#define NET_CTRL 6
//#define LOGPAD_CTRL 7
//#define GRAV1_CTRL 8
//#define GRAV2_CTRL 9

#define LP_A 1
#define LP_B 2
#define LP_L 4
#define LP_R 8
#define LP_C 16
#define LP_D 32

#define SPECIALK 128

#define UP_KEY 0
#define DN_KEY 1
#define LF_KEY 2
#define RT_KEY 3
#define F1_KEY 4
#define F2_KEY 5

// User play types.

#define COM 0
#define TEAM_A -1
#define TEAM_B -2

// User player highlight types.

#define HLITE_OFF 0
#define HLITE_NORM 1
#define HLITE_CROSS 2
#define HLITE_BALL 3
#define HLITE_SHOOT 4
#define HLITE_STAR 5
#define HLITE_SPECIAL 6

// Keeper Save Areas and Times...

#define SAVE_SPEED 20.		// Real speed is 20.

#define MC_AFOOTB_FS (1./(SAVE_SPEED*23/40))
#define MC_AFOOTC_FS (1./(SAVE_SPEED*86/40))
#define MC_ABODYB_FS (1./(SAVE_SPEED*53*24/54/40))		// sped up!
#define MC_ABODYC_FS (1./(SAVE_SPEED*43/40))
#define MC_AHEADB_FS (1./(SAVE_SPEED*27*48/65/40))		// sped up!
#define MC_AHEADC_FS (1./(SAVE_SPEED*46/40))
#define MC_AJUMPB_FS (1./(SAVE_SPEED*28/40))
#define MC_AJUMPC_FS (1./(SAVE_SPEED*38/40))

#define MC_BFOOTB_FS (1./(SAVE_SPEED*21/40))
#define MC_BFOOTC_FS (1./(SAVE_SPEED*42/40))
#define MC_BBODYB_FS (1./(SAVE_SPEED*27/40))
#define MC_BBODYC_FS (1./(SAVE_SPEED*43/40))
#define MC_BHEADB_FS (1./(SAVE_SPEED*32/40))		// sped up!
#define MC_BHEADC_FS (1./(SAVE_SPEED*36/40))
#define MC_BJUMPB_FS (1./(SAVE_SPEED*36/40))

#define MC_CFOOTB_FS (1./(SAVE_SPEED*49/40))
#define MC_CFOOTC_FS (1./(SAVE_SPEED*50/40))
#define MC_CBODYB_FS (1./(SAVE_SPEED*45*51/68/40))		// sped up!
#define MC_CBODYC_FS (1./(SAVE_SPEED*48/40))
#define MC_CHEADB_FS (1./(SAVE_SPEED*44/40))
#define MC_CJUMPB_FS (1./(SAVE_SPEED*47/40))

#define MC_SHOOT_FS (1./(20.*36/40))
#define MC_CHIP_FS (1./(20.*30/40))
#define MC_PASS_FS (1./(20.*33/40))
#define MC_CROSS_FS (1./(20.*36/40))
#define MC_VOLLEY_FS (1./(20.*30/40))
#define MC_TOE_FS (1./(20.*35/40))
#define MC_DIAGPASS_FS (1./(20.*33/40))
#define MC_DIAGBACK_FS (1./(20.*33/40))
#define MC_SIDEPASS_FS (1./(20.*32/40))
#define MC_BACKHEEL_FS (1./(20.*32/40))
#define MC_TRAP_FS (1./(20.*20/40))
#define MC_RIDE_FS (1./(20.*28/40))
#define MC_SOCKS_FS (1./(20.*68/40))
#define MC_TROTA_FS (1./(20.*32/40))
#define MC_RUN_FS (1./(20.*26/40))
#define MC_JOG_FS (1./(20.*29/40))
#define MC_BARGE_FS (1./(20.*27/40))
#define MC_THROWW_FS (1./(20.*13/40))
#define MC_SHAMEW_FS (1./(20.*33/40))
#define MC_LIE_FS (1./(20.*26/40))
#define MC_STAND_FS (1./(20.*39/40))
#define MC_S_HEAD_FS (1./(20.*31/40))		// Sped up from 51.
#define MC_J_HEAD_FS (1./(20.*42/40))		// Sped up from 52.
#define MC_D_HEAD_FS (1./(20.*38/40))
#define MC_DV_HEAD_FS (1./(20.*36/40))
#define MC_U_HEAD_FS (1./(20.*38/40))
#define MC_CHEST_FS (1./(20.*49/40))
#define MC_S_TACKLE_FS (1./(20.*50/40))		// Sped up from 98.
#define MC_STEAL_FS (1./(20.*17/40))
#define MC_OVERHEAD_FS (1./(20.*45/40))
#define MC_THROWL_FS (1./(20.*43/40))
#define MC_THROWS_FS (1./(20.*35/40))
#define MC_FALLR_FS (1./(20.*20/40))		// 34
#define MC_CELEB_FS (1./(20.*118/40))
#define MC_SHAME_FS (1./(20.*82/40))
#define MC_GETUP_FS (1./(20.*82/40))
#define MC_GETUPF_FS (1./(20.*87/40))
#define MC_STANDB_FS (1./(20.*29/40))
#define MC_BOUNCE_FS (1./(20.*43/40))
#define MC_KICKOUT_FS (1./(20.*68/40))
#define MC_HALFVOLL_FS (1./(20.*68/40))
#define MC_THROW_FS (1./(20.*59/40))
#define MC_ROLL_FS (1./(20.*81/40))
#define MC_RUNWITHB_FS (1./(20.*30/40))
#define MC_WAVEUP_FS (1./(20.*60/40))			// sped up from 120 to 60!
#define MC_PENALTY_FS (1./(20.*64/40))
#define MC_PLEAD_FS (1./(20.*128/40))
#define MC_STOS_FS (1./(20.*68/40))
#define MC_STOSB_FS (1./(20.*95/40))
#define MC_CRTOSTB_FS (1./(20.*55/40))
#define MC_PICKBALL_FS (1./(20.*43/40))
#define MC_DUCK_FS (1./(20.*62/40))
#define MC_FINGER_FS (1./(20.*27/40))
#define MC_KNEE_FS (1./(20.*41/40))
#define MC_PLANE_FS (1./(20.*45/40))
#define MC_MILLER_FS (1./(20.*45/40))
#define MC_BABY_FS (1./(20.*40/40))
#define MC_MOON_FS (1./(20.*38/40))				// sped up from 68
#define MC_PUMP_FS (1./(20.*30/40))
#define MC_REEVES_FS (1./(20.*49/40))


#define MC_PASS_DIST (10.14)						// Distance pass animation covers

#define SAVE_ZONE_A prat
#define SAVE_ZONE_B prat*2.5
#define SAVE_ZONE_C prat*4.5

#define SAVE_FEET_HGT prat
#define SAVE_CHEST_HGT prat*1.8
#define SAVE_HEAD_HGT prat*2.5
#define SAVE_JUMP_HGT prat*3.4

#define SAVE_AFOOTB_TIME (29.*SAVE_SPEED/120)
#define SAVE_AFOOTC_TIME (48.*SAVE_SPEED/120)
#define SAVE_ABODYB_TIME (24.*SAVE_SPEED/120)	// Modified 54
#define SAVE_ABODYC_TIME (39.*SAVE_SPEED/120)
#define SAVE_AHEADB_TIME (48.*SAVE_SPEED/120)	// Modified 65
#define SAVE_AHEADC_TIME (65.*SAVE_SPEED/120)
#define SAVE_AJUMPB_TIME (44.*SAVE_SPEED/120)
#define SAVE_AJUMPC_TIME (62.*SAVE_SPEED/120)

#define SAVE_BFOOTB_TIME (52.*SAVE_SPEED/120)
#define SAVE_BFOOTC_TIME (86.*SAVE_SPEED/120)
#define SAVE_BBODYB_TIME (29.*SAVE_SPEED/120)
#define SAVE_BBODYC_TIME (57.*SAVE_SPEED/120)
#define SAVE_BHEADB_TIME (36.*SAVE_SPEED/120)
#define SAVE_BHEADC_TIME (48.*SAVE_SPEED/120)
#define SAVE_BJUMPB_TIME (60.*SAVE_SPEED/120)

#define SAVE_CFOOTB_TIME (89.*SAVE_SPEED/120)
#define SAVE_CFOOTC_TIME (109.*SAVE_SPEED/120)
#define SAVE_CBODYB_TIME (51.*SAVE_SPEED/120)	// Modified 68
#define SAVE_CBODYC_TIME (70.*SAVE_SPEED/120)
#define SAVE_CHEADB_TIME (89.*SAVE_SPEED/120)
#define SAVE_CJUMPB_TIME (82.*SAVE_SPEED/120)

// Motion Capture Constants...

#define MC_RUN_SPD 3.19
#define MC_JOG_SPD 2.025
#define MC_S_TACK_TIME (226/120)
#define MC_PLANE_SPD (37.2*2/45)
#define MC_FINGER_SPD (22.9*2/27)
#define MC_CELEB_SPD (1.69)
#define MC_DUCK_SPD (10.3*2/62)

// Macros

#define SIGN(a) (a>=0 ? 1:0)
#define ABS(a) (((a)>=0) ? (a):-(a))
#define MAX(a,b) (((a)>=(b)) ? (a):(b))
#define MIN(a,b) (((a)>=(b)) ? (b):(a))
#define FEQS(a,b) ((((a)<((b)+0.001)) && ((a)>((b)-0.001))) ? 1:0)
#define AFEQS(a,b) ((((ABS(a))<(ABS(b)+0.001)) && ((ABS(a))>(ABS(b)-0.001))) ? 1:0)
#define NORM(a) ((a)<0 ? -1:1)
#define LIMIT(a,b,c) ((a)<(b) ? (b):((a)>(c) ? (c):(a)))

// Equation Macros

#define MAX_TURN ((PI*(14+((float)player->tm_rate/8)))/180)
#define MAX_TURN2 ((PI*(14+((float)teams[p_num-1].tm_rate/8)))/180)

//#define MAX_TURN (PI/2)
//#define MAX_TURN2 (PI/2)

// Sound Fx.

#define MAX_VOL_DIST (prat*4)

#define FX_WHISTLE1 1
#define FX_PASS 2
