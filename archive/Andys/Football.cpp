#include "Andys Vars.h"
#include "Football.h"

#undef EXTERN
#define EXTERN extern
#include "3D_upd2.h"
#include "Actions.h"
#include "Andy Menu.h"
#include "Ball.h"
#include "Ballint.h"
#include "Blitter.h"
#include "Control.h"
#include "Display.h"
#include "Intell.h"
#include "Intronet.h"
#include "Mallocx.h"
#include "Maths.h"
#include "More Control.h"
#include "My_Audio.h"
#include "Palette.h"
#include "Play.h"
#include "Process Inputs.h"
#include "Rules.h"
#include "User.h"
#include "Use DrawSprockets.h"
//#include "Use RaveEngine.h"
#include "Vbl.h"

#include "Audio.h"
#include "A Front.h"
#include "A Unwritten.h"

//#include "2D_routines.h"

extern void end3d_rave(void);
extern Boolean UseRaveEngine;

KeyMap lastkeyMap;

#if DEBUGGING==ON
#define ShowRoutine(X)		SShowRoutine(X)
static void SShowRoutine( int flag)
{
static int value[10];

	return;
	value[9] = value[8];
	value[8] = value[7];
	value[7] = value[6];
	value[6] = value[5];
	value[5] = value[4];
	value[4] = value[3];
	value[3] = value[2];
	value[2] = value[1];
	value[1] = value[0];
	value[0] ^= flag;
	
	for( int a=0;a<10;a++)
		DumpLong( 600+(10*a), value[a]);
}
#else
#define ShowRoutine(X)		;
#endif

#define REPLAY_SECONDS		15

/******************************************************************************/
// 
// Actua Soccer.    1.9.94
//
//	Programmed by Andy Findlay.
//
/******************************************************************************
******************************************************************************/
//#include "global.h"

//#include "editor.h"
//#include "time.h"
//#include "front.h"
//#include "mallocx.h"

extern int net_var_start;
extern int net_var_end;

extern int winrange;
extern int Vbytesperline;

extern setup_info setup;
extern buff_info main_buff,vidi_buff;

extern match_data match_info;

extern team_info game_data[];

short time_table[]={5,10,20,40,90};

extern plyrdat *replay_tab;

//#define NET_A

//#include "audio.h"							// SOS header

extern volatile int ux1,ux2;
extern volatile short net_error;

extern volatile char net_half;

/******************************************************************************
******************************************************************************/

#include "defines.h"
#include "glob_var.h"

extern float set_camera_height;
extern float set_camera_dist;

int num_of_users=1;
/******************************************************************************
*****************************************************************************/

/*
void checksum()
{
	short *v=(short *)&var_start;
	short sum=0;
	do
	{
		sum^=*v;
		v++;
	}while(v<(short *)&var_end);

	sprintf(check_str,"%d",sum);
	display_message(check_str);
}
*/

/******************************************************************************
******************************************************************************/
int pen_cnt=100;

void make_mtable(int t1,int t2)
{
	float d,min_d,x,y,gx;
	int p;

	for (int j=t2; j<t2+10; j++)
	{
		teams[j-1].tm_mark=FALSE;
	}

	if (t2<12)
// Team A goals...
		gx=0;
	else
// Team B goals...
		gx=pitch_len;

	for (int a=t1; a>t1-10; a--)
	{
// Can't mark guy on ball...
		if ((a!=main_man) && (teams[a-1].guy_on>0))
		{
			x=teams[a-1].tm_x;
			y=teams[a-1].tm_y;
			p=0;

			if (calc_dist(gx-x,cntspot_y-y)<MUST_MARK_DIST)
// Close enough to be a threat!!!
			{
				min_d=5000;
				for (int i=t2; i<t2+10; i++)
				{
					if ((teams[i-1].guy_on>0) && (!teams[i-1].tm_wall)
						&& (!teams[i-1].tm_mark))
					{
						if (i<12)
							d=calc_dist(x-match_tactics1[ball_zone1][i-2][0],
								   		y-match_tactics1[ball_zone1][i-2][1]);
						else
							d=calc_dist((pitch_len-x)-match_tactics2[ball_zone2][i-13][0],
								   		(pitch_wid-y)-match_tactics2[ball_zone2][i-13][1]);
						if (d<min_d)
						{
							min_d=d;
							p=i;
						}
					}
				}
			}

			if (p)
			{
				d=calc_dist(gx-x,cntspot_y-y);

// How tightly they mark depends on discipline...
				x+=(prat*(gx-x)*((192-teams[p-1].tm_disc)/64)/d);
				y+=(prat*(cntspot_y-y)*((192-teams[p-1].tm_disc)/64)/d);

				teams[p-1].tm_mark=a;

				if (p>11)
					p-=11;
				man2man[p-2][0]=(int)x;
				man2man[p-2][1]=(int)y;
			}
		}
	}
}

/******************************************************************************
******************************************************************************/

// Process Various control flags on each logic cycle...

void process_flags()
{
// Text message counter...
	if (new_text)
		new_text--;

// Used for offside rule...
	if (ball_released)
		if (ball_released>0)
			ball_released--;
		else
			ball_released++;

	if (play_advantage)
	{
// Referee has seen an indiscretion but is waiting to see who collects ball...

		if (ball_poss)
		{
// Some-one has collected ball!!!

			if ((ball_poss<12 && bad_guy>11) || (ball_poss>11 && bad_guy<12))
			{
// Favoured team has it!

				play_advantage=FALSE;
			}
			else
			{
// Fouling team has it! (no advantage gained!)
				retake_foul();
			}
		}
	}

	if (just_thrown)
		if (last_touch==throw_in_taker)
			just_thrown--;
		else
			just_thrown=FALSE;

	switch(match_mode)
	{
		case(IF_KICK_B):
		case(DF_KICK_B):
		case(CORNER_TL):
		case(CORNER_BL):
			man2man_a=TRUE;
			man2man_b=FALSE;
			break;

		case(IF_KICK_A):
		case(DF_KICK_A):
		case(CORNER_TR):
		case(CORNER_BR):
			man2man_b=TRUE;
			man2man_a=FALSE;
			break;

		default:
			man2man_a=FALSE;
			man2man_b=FALSE;
			break;
	}

	if (man2man_b)
// Team B marking table...
	{
		make_mtable(11,13);
	}
	else
	{
		if (man2man_a)
// Team A marking table...
		{
			make_mtable(22,2);
		}
	}
}

/******************************************************************************
*****************************************************************************/

void init_line_up()
{
	line_up=LINE_UP_DELAY+40;
}

/******************************************************************************
*****************************************************************************/

short convert_control(char c)
{
	switch(c)
	{
		case(0):
			return(KEY1_CTRL);
			break;

		case(1):
			return(KEY2_CTRL);
			break;

#if FOURPLAYERS
		case(2):
			return(JOY1_CTRL);
			break;

		case(3):
			return(JOY2_CTRL);
			break;
#endif
//
//		case(4):
//			return(LOGPAD_CTRL);
//			break;
	}
	return(0);
}

/******************************************************************************
*****************************************************************************/

short conv_conts_back(char c)
{
	switch(c)
	{
		case(KEY1_CTRL):
			return 0;

		case(KEY2_CTRL):
			return 1;

#if FOURPLAYERS
		case(JOY1_CTRL):
			return 2;

		case(JOY2_CTRL):
			return 3;
#endif
//
//		case(LOGPAD_CTRL):
//			return(4);
//			break;
	}
	return(0);
}

/******************************************************************************
*****************************************************************************/

void init_rand()
{
	andys_random=TRUE;
// Get it from front-end...
	rand_seed=match_info.rand;

	afr1=rand1_tab;
	afr2=rand2_tab;

	memcpy(&rand1_tab,&rand1_setup,sizeof(short)*5);
	memcpy(&rand2_tab,&rand2_setup,sizeof(short)*6);
}

/******************************************************************************
*****************************************************************************/

// Initialise zero vars...

extern char cross_on;

void initialise_vars()
{
	int i;

	for (i=0; i<5; i++)
	{
		burst_timer[i]=0;
	}

	for (i=0; i<22; i++)
	{
		sel_circle[i]=0;
	}

	not_ahead=FALSE;
	kick_off=TRUE;
	forced=0;
	keep_timer=0;
	player_on_off=FALSE;
	player_being_subbed=FALSE;
	sub_pending=FALSE;
	booking=FALSE;

	stop_clock=FALSE;
	card_is_out=0;
	demo_match=FALSE;

	keep_dive=FALSE;
	hold_up_play=0;
	cross_on=FALSE;
	wall_is_up=FALSE;
	
	comsetp=0;

	init_rand();

// Timing Vars...

	updates=0;
	old_count=0;

	crowd_mood_a=0;
	crowd_mood_b=0;

	possession=0;
	poss_held=0;

	for (i=0; i<11; i++)
	{
		strike[i].t=0;
		strike[i].free=0;
		strike[i].ptype=0;
		strike[i].pplr=0;
		strike[i].gt=0;
		strike[i].x=0;
		strike[i].y=0;
		strike[i].atime=0;
		strike[i].stop=0;
	}

	first_time_it=FALSE;
	auto_select=FALSE;

	seconds=0;

	arrow_on=0;

	logic_cnt=0;

	ball_move=FALSE;

	first_bounce=0;
	swerve=0;
	spin_cnt=0;
	spin_ball=0;
	prediction=FALSE;
	set_xyspin=0;
	set_zspin=0;

	ball_horz_ang=0;
	ball_vert_ang=0;
	max_sw_factor=0;
	swerve_factor=0;
	rebound_ball=0;
	headed_ball=0;
	say_names=TRUE;
	fired_a_shot=0;
	comm_pass=0;
	comm_pass_type=0;

	keeper_spd=0;
	keeper_down=FALSE;
	keeper_will_save=FALSE;
	keeper_on_grnd=FALSE;
	keeper_contact=0;
	ball_in_goal=FALSE;
	ball_in_hands=FALSE;
	game_action=FALSE;
	throw_cnt=0;
	team_a_goals=0;
	team_b_goals=0;
	last_goal=0;
	scorer_running=FALSE;
	just_scored=0;
	just_thrown=0;
	goal_scorer=0;
	pass_type=0;
	kick_type=0;
	receiver=0;
	cross_now=0;
	must_face=FALSE;
	must_face_time=0;
	must_face_x=0;
	must_face_y=0;
	must_shoot=FALSE;
	chip_pass=FALSE;
	must_pass=FALSE;
	must_punt=FALSE;

	keeper_a_in_box=0;
	keeper_b_in_box=0;
	keeper_steps=0;
	save_block=0;
	save_xoff=0;
	save_yoff=0;
	save_zoff=0;
	shot_speed=0;
	scr_x=0;
	scr_y=0;
	ball_speed=0;
	ball_int_speed=0;
	interceptor_a=0;
	interceptor_b=0;
	in_cross_area=0;
	close_in_number=0;
	shooter=0;
	ball_inair=1;
	super_shot=0;
	opponents_near_holder=0;
	opponents_really_close=0;
	int ball_poss=0;
	sender_1_2=0;
	ball_still=0;
	last_touch=0;
	want_pass=0;
	before=0;
	support_me=0;
	pre_kp_touch=0;
	prev_touch=0;

	ball_limbo_p=0;
	ball_limbo_on=FALSE;
	ball_limbo_c=0;

	ball_released=0;
	cannot_pick_up=0;
	last_user_a=0;
	last_user_b=0;
	last_plr_a=0;
	last_plr_b=0;
	players_off_a=0;
	players_off_b=0;

	want_pass_stat=0;
	ball_zone1=0;
	ball_zone2=0;
	ball_out_of_play=0;

	receiver_a=0;
	receiver_b=0;

	ready_centre=0;
	shot_attempt=0;

	force_select=0;
	heading_ball=0;
	flag=0;

	rep_camera=0;
	sub_camera=0;
	allow_replay=0;

	replay_pos=0;
	old_rep_pos=0;
	replay_cnt=0;

	pitch_sprs=0;

	fixed_net_user=0;

	memset(&auto_users_list_a,0,sizeof(auto_users_list_a));
	memset(&auto_users_list_b,0,sizeof(auto_users_list_b));
	auto_users_a=0;
	auto_users_b=0;

	play_ball_a=0;
	play_ball_b=0;

	new_select=0;
	auto_intercept=0;
	closest=0;

	f1_down=0;
	f2_down=0;

	spec_kick_type=0;
	setp_hgt=0;
	setp_power=0;
	setp_kick_x=0;
	setp_kick_y=0;
	setp_bxd=0;
	setp_byd=0;
	setp_bzd=0;
		
	user_taker=0;
	user_controlled=0;
	user_plr=0;
	after_touch_on=FALSE;
	drive_shot=0;

	wallx=0;
	wally=0;
	men_in_wall=0;

	for (i=0; i<5; i++)
	{
		wguys[i].guy=0;
		wguys[i].x=0;
		wguys[i].y=0;
	}

	keeper_pos_x=0;
	keeper_pos_y=0;

	centre_guy_1=0;
	centre_guy_2=0;

	in_range=0;
	in_header_rng=0;
	in_shot_rng=0;
	taker_x=0;
	taker_y=0;

	bad_guy=0;
	direct_fk=FALSE;

	play_advantage=0;

	set_piece_on=0;

	shot_acknowledged=FALSE;
	shot_pending=FALSE;
	real_shot=FALSE;
	shot_missed=0;
	shot_saved=0;

	for (i=0; i<10; i++)
	{
		opp_dir_tab[i][0]=0;
		opp_dir_tab[i][1]=0;
		opp_dir_tab[i][2]=0;
	}

	offside_now=0;

	memset(&tussle_tab,0,sizeof(tussle_tab));

	ball_travel=0;
	select_cnt=10;

	in_game=1;
	end_game = false;
	analogue=1;

	ballxdis=12.0, ballydis=2.0, ballzdis=10.0;
	ballx=cntspot_x, bally=cntspot_y, ballz=ball_diam/2;
	prev_ballx=0.0*16, prev_bally=30.0*16, prev_ballz=ball_diam/2;
	ns_ballx=0.0, ns_bally=0.0, ns_ballz=ball_diam/2;
	ball_zspin=0;
	ball_xyspin=0;
	full_zspin=0;
	full_xyspin=0;
	shoot_x=0;
	shoot_y=0;

	nearest_a=0,nearest_b=0,old_ltouch=-1,old_ball_poss=-1;
	use_ball_limit=0;
	near_path_a=0;
	near_path_b=0;
	zone1_x=0;
	zone2_x=0;
	zone1_y=0;
	zone2_y=0;
	incident_x=0;
	incident_y=0;
	difficulty=0;
	match_mode=0;
	dead_ball_cnt=0;
	defense_a=0;
	defense_b=0;
	poss_mode=0;

	for (i=0; i<50; i++)
	{
		ball_pred_tab[i][0]=ballx;
		ball_pred_tab[i][1]=bally;
		ball_pred_tab[i][2]=ballz;
		ns_ball_pred_tab[i][0]=ballx;
		ns_ball_pred_tab[i][1]=bally;
		ns_ball_pred_tab[i][2]=ballz;
	}

	delay_cnt=40;
	play_nums_on=0;
	fframe=FALSE;
	frames=0;
	frms_per_sec=0;
	last_second=0;

	old_clock=0;

}

/******************************************************************************
*****************************************************************************/

void init_user_controls()
{
#ifdef FRONT_END
	num_of_users=0;
#endif

	short home_plrs=game_data[setup.team_a].player_control;
	short away_plrs=game_data[setup.team_b].player_control;
	short plrs=0;
	short c;

	short pnum=0;

	for (short i=1; i<16; i<<=1)
	{
		pnum++;
		if (home_plrs&i)
		{
// User...
			plrs++;
			c=convert_control(match_info.control_methods[pnum-1]);
			add_team_user(-1,c);
		}

		if (away_plrs&i)
		{
// User...
			plrs++;
			c=convert_control(match_info.control_methods[pnum-1]);
			add_team_user(-2,c);
		}
	}
}

/******************************************************************************
*****************************************************************************/
extern short dataResFile, mainResFile;

void load_new_tactics()
{
int resnum;
Handle theData;
short oldRes = CurResFile();

	UseResFile(dataResFile);
	
	if (tactics_a!=old_tac_a)
		{
		switch(tactics_a)
			{
			case(F_4_3_3):	//				fp1=fopen("tac_433.tac","rb");
					resnum = 132;
					break;
			case(F_5_3_2):	//				fp1=fopen("tac_532.tac","rb");
					resnum = 135;
					break;
			case(F_6_3_1):	//				fp1=fopen("tac_631.tac","rb");
					resnum = 137;
					break;
			case(F_4_2_4):	//				fp1=fopen("tac_424.tac","rb");
					resnum = 131;
					break;
			case(F_5_1_4):	//				fp1=fopen("tac_514.tac","rb");
					resnum = 134;
					break;
			case(F_4_0_6):	//				fp1=fopen("tac_406.tac","rb");
					resnum = 129;
					break;
			case(F_3_1_6):	//				fp1=fopen("tac_316.tac","rb");
					resnum = 128;
					break;
			case(F_4_1_5):	//				fp1=fopen("tac_415.tac","rb");
					resnum = 130;
					break;
			case(F_5_2_3):	//				fp1=fopen("tac_523.tac","rb");
					resnum = 135;
					break;
			case(F_4_4_2):	//				fp1=fopen("tac_442.tac","rb");
					resnum = 133;
					break;
			}
			
		theData = GetResource( RESTYPE_TAC, resnum);	// Team A tactics...
		if (!(match_half&1))
			memcpy(match_tactics1, *theData, 5600);
		else
			memcpy(match_tactics2, *theData, 5600);
		ReleaseResource(theData);
		}

	if (tactics_b!=old_tac_b)
		{
		switch(tactics_b)
			{
			case(F_4_3_3):	//				fp1=fopen("tac_433.tac","rb");
					resnum = 132;
					break;
			case(F_5_3_2):	//				fp1=fopen("tac_532.tac","rb");
					resnum = 135;
					break;
			case(F_6_3_1):	//				fp1=fopen("tac_631.tac","rb");
					resnum = 137;
					break;
			case(F_4_2_4):	//				fp1=fopen("tac_424.tac","rb");
					resnum = 131;
					break;
			case(F_5_1_4):	//				fp1=fopen("tac_514.tac","rb");
					resnum = 134;
					break;
			case(F_4_0_6):	//				fp1=fopen("tac_406.tac","rb");
					resnum = 129;
					break;
			case(F_3_1_6):	//				fp1=fopen("tac_316.tac","rb");
					resnum = 128;
					break;
			case(F_4_1_5):	//				fp1=fopen("tac_415.tac","rb");
					resnum = 130;
					break;
			case(F_5_2_3):	//				fp1=fopen("tac_523.tac","rb");	
					resnum = 135;
					break;
			case(F_4_4_2):	//				fp1=fopen("tac_442.tac","rb");
					resnum = 133;
					break;
			}
		theData = GetResource( RESTYPE_TAC, resnum); // Team B tactics...
		if (!(match_half&1))
			memcpy(match_tactics2, *theData, 5600);
		else
			memcpy(match_tactics1, *theData, 5600);
		ReleaseResource(theData);
		}
	
	old_tac_a=tactics_a;
	old_tac_b=tactics_b;
	
	UseResFile( oldRes);
}


/******************************************************************************
*****************************************************************************/

void init_match()
{
	sub_pending=0;

//	key_togs[0x0a]=match_info.vidi;

// Initialise Penalty Shoot-out...
	penalties=0;
	home_pens_left=5;
	away_pens_left=5;
	penalty_game=FALSE;
	penalty_team=FALSE;
	penalty_counter=0;
	pen_taker_a=11;
	pen_taker_b=22;

	first_update=TRUE;

	reset_ball();

	opt_user=0;
	subbing_now=FALSE;

	replay_seconds=0;
	replay_tab = (plyrdat *)MallocX(REPLAY_SECONDS*ncb*20*sizeof(plyrdat));
	if(replay_tab)
	  replay_seconds = REPLAY_SECONDS;  

	auto_intercept=TRUE;
	end_game= false;
	in_game = true;
	allow_replay=FALSE;
	match_time.min=0;
	match_time.sec=0;
	next_mins=0;

	just_scored=0;
	set_piece_on=0;
	team_a_goals=0;
	team_b_goals=0;

	if (!network_on)
		init_user_controls();

	need_result=(match_info.CompetitionType==2);
	clock_running=FALSE;
	team_a=0;
	team_b=1;
	match_half=0;
	last_centre=0;
	init_line_up();

/*** Setup Tactics ***/
	tactics_a=match_info.tac_1;
	tactics_b=match_info.tac_2;
	old_tac_a=-1;		// Force new tactical load!
	old_tac_b=-1;
	load_new_tactics();

	ref_accuracy=match_info.referee_vision;
	ref_strictness=match_info.referee_discipline;
}

/******************************************************************************
******************************************************************************/

#define COUNTRIES 44

void init_player_stats(short p)
{
	p--;
	short ps;
	if (match_info.GameType)
	{
// Simulation Mode!!!
		if ((!(match_half&1) && p<11)
			  || (match_half&1 && p>10))
		{
// Team A...
			if (!(match_half&1))
			{
				ps=p;
			}
			else
			{
				ps=p-11;
			}

			teams[p].tm_rate=game_data[setup.team_a].players[ps].pace+28;
			teams[p].tm_pow=game_data[setup.team_a].players[ps].power+28;
			teams[p].tm_cont=game_data[setup.team_a].players[ps].control+28;
			teams[p].tm_flair=game_data[setup.team_a].players[ps].flair+28;
			teams[p].tm_vis=game_data[setup.team_a].players[ps].vision+28;
			teams[p].tm_ac=game_data[setup.team_a].players[ps].accuracy+28;
			teams[p].tm_stam=game_data[setup.team_a].players[ps].stamina+28;
			teams[p].tm_disc=game_data[setup.team_a].players[ps].discipline+28;
		}
		else
		{
// Team B...
			if (match_half&1)
			{
				ps=p;
			}
			else
			{
				ps=p-11;
			}

			teams[p].tm_rate=game_data[setup.team_b].players[ps].pace+28;
			teams[p].tm_pow=game_data[setup.team_b].players[ps].power+28;
			teams[p].tm_cont=game_data[setup.team_b].players[ps].control+28;
			teams[p].tm_flair=game_data[setup.team_b].players[ps].flair+28;
			teams[p].tm_vis=game_data[setup.team_b].players[ps].vision+28;
			teams[p].tm_ac=game_data[setup.team_b].players[ps].accuracy+28;
			teams[p].tm_stam=game_data[setup.team_b].players[ps].stamina+28;
			teams[p].tm_disc=game_data[setup.team_b].players[ps].discipline+28;
		}
	}
	else
	{
// Arcade Mode!!!
		int rank=game_data[setup.team_a].ranking;
		short avg=50+(1.4*(COUNTRIES-rank-1));  // 50 - 110

		teams[p].tm_rate=30+(avg/2);
		teams[p].tm_pow=avg;
		teams[p].tm_cont=avg;
		teams[p].tm_flair=avg;
		teams[p].tm_vis=avg;
		teams[p].tm_ac=avg;
		teams[p].tm_stam=avg;
		teams[p].tm_disc=avg;
	}

	teams[p].shirt=player_coming_on;
	teams[p].tm_trap=FALSE;
}

/******************************************************************************
******************************************************************************/

void process_subs()
{
	if (player_being_subbed)
	{
// Player has been selected and should come off!
		if (!teams[player_being_subbed-1].guy_on)
		{
// He's off the park... (Bring on new guy!)
			init_player_stats(player_being_subbed);
			teams[player_being_subbed-1].int_move=FALSE;
			teams[player_being_subbed-1].int_cnt=FALSE;
			reset_ideas(&teams[player_being_subbed-1]);
			player_being_subbed=FALSE;
			teams[player_on_off-1].guy_on=TRUE;
			player_on_off=-player_on_off;			// Coming on!
			init_off_int(&teams[(-player_on_off)-1]);
		}
	}
	else
	{
		if (!player_on_off && sub_pending && (match_mode>=CORNER_TL && match_mode<=DF_KICK_B)
			 && !kickoff)
		{
			opt_user=100;		// Substitute instead of options...

// Some-one is trying to make a substitution...(Who?)
			if (sub_pending&1)
				opt_team=0;
			else
				opt_team=1;
		}
	}
}

/******************************************************************************
*****************************************************************************/

void variable_wind()
{
// Variable speed and direction around initial settings...

// Do dir.
	if (wind_d_trend>0)
	{
// Wind current dir gets further from initial setting...
		wind_d_trend--;
		if (wind_var_ang<0)
			wind_var_ang-=(MAX_WIND_CHANGE*seed/128);
		else
			wind_var_ang+=(MAX_WIND_CHANGE*seed/128);

		wind_x=(init_wind_x*cos(wind_var_ang))-(init_wind_y*sin(wind_var_ang));
		wind_y=(init_wind_y*cos(wind_var_ang))+(init_wind_x*sin(wind_var_ang));
	}
	else
	{
		if (wind_d_trend<0)
		{
// Wind current dir returns to initial setting...
			wind_d_trend++;
			if (wind_var_ang<0)
				wind_var_ang+=(MAX_WIND_CHANGE*seed/128);
			else
				wind_var_ang-=(MAX_WIND_CHANGE*seed/128);

			wind_x=(init_wind_x*cos(wind_var_ang))-(init_wind_y*sin(wind_var_ang));
			wind_y=(init_wind_y*cos(wind_var_ang))+(init_wind_x*sin(wind_var_ang));
		}
		else
		{
// New trend...
			if (ABS(wind_var_ang*128/PI)<seed)
				wind_d_trend=WIND_BLUSTERINESS;
			else
				wind_d_trend=-WIND_BLUSTERINESS;
		}
	}
	
	AF_randomize(__FILE__,__LINE__);

// Do speed.
	if (wind_s_trend>0)
	{
// Increment difference in speed...
		wind_s_trend--;
		if ((wind_speed-init_wind_speed)<0)
		{
			wind_speed-=(MAX_WIND_S_CHANGE*seed/128);
			if (wind_speed<0)
				wind_speed=0;
		}
		else
		{
			wind_speed+=(MAX_WIND_S_CHANGE*seed/128);
			if (wind_speed>128)
				wind_speed=128;
		}
	}
	else
	{
		if (wind_s_trend<0)
		{
// Decrement difference in speed...
			wind_s_trend++;
			if ((wind_speed-init_wind_speed)<0)
			{
				wind_speed+=(MAX_WIND_S_CHANGE*seed/128);
				if (wind_speed>128)
					wind_speed=128;
			}
			else
			{
				wind_speed-=(MAX_WIND_S_CHANGE*seed/128);
				if (wind_speed<0)
					wind_speed=0;
			}
		}
		else
		{
// New trend...
			if (ABS(wind_speed-init_wind_speed)<(seed/2))
				wind_s_trend=WIND_GUSTINESS;
			else
				wind_s_trend=-WIND_GUSTINESS;
		}
	}
}

/******************************************************************************
******************************************************************************/

int coo=0;
char gkey=0;
	  
void do_logic()
{
ShowRoutine(0x00000001);
	if(last_match_mode != match_mode)
		{
		if( stop_clock && (last_match_mode==CENTRE_A || last_match_mode==CENTRE_B) && !match_mode)
			stop_clock = false;
		last_match_mode = match_mode;
		}

ShowRoutine(0x00000002);
	init_pitch_sprites();
ShowRoutine(0x00000002);

// Normal logic mode.
/*
	if (!match_mode)
	{
		if (!--pen_cnt)
			force_penalty();
	}
*/
	logic_cnt++;
	fframe=(fframe) ? 0:1;
ShowRoutine(0x00000004);
	AF_randomize(__FILE__, __LINE__);
ShowRoutine(0x00000004);

ShowRoutine(0x00000008);
	process_subs();
ShowRoutine(0x00000008);

	if (wind_on<0)
		variable_wind();		// Get current wind parameters...

ShowRoutine(0x00000010);
	process_ball();
ShowRoutine(0x00000010);

ShowRoutine(0x00000020);
	match_rules();
ShowRoutine(0x00000020);

ShowRoutine(0x00000040);
	keeper_boxes();
ShowRoutine(0x00000040);

ShowRoutine(0x00000080);
	player_distances();
ShowRoutine(0x00000080);

ShowRoutine(0x00000100);
	get_nearest();		// near_path_a, near_path_b
ShowRoutine(0x00000100);

ShowRoutine(0x00000200);
	get_opp_near_ball(ball_poss);
ShowRoutine(0x00000200);

ShowRoutine(0x00000400);
	process_speech();
ShowRoutine(0x00000400);

ShowRoutine(0x00000800);
	process_comments();
ShowRoutine(0x00000800);

ShowRoutine(0x00001000);
	process_flags();
ShowRoutine(0x00001000);

ShowRoutine(0x00002000);
	process_teams();
ShowRoutine(0x00002000);

ShowRoutine(0x00004000);
	new_users();
ShowRoutine(0x00004000);

ShowRoutine(0x00008000);
	select_all_hlites();
ShowRoutine(0x00008000);

ShowRoutine(0x00010000);
	process_offs();
ShowRoutine(0x00010000);

	if (!match_mode && comsetp)
		--comsetp;
ShowRoutine(0x00000001);
}

/******************************************************************************
*****************************************************************************/

void stop_mf_time()
{
/*
	int cl=clock();
	int c=cl/CLOCKS_PER_SEC;
	last_second=c;
	old_clock=cl;
*/
	oldcnt=count-1;
}

/******************************************************************************
*****************************************************************************/

void pause_game()
{
	do
		{
		if( !demo_match)
			{
			get_user_inputs();
			process_user_inputs();
			writeptr = (++writeptr&511);
			convert_inputs();
			readptr = (++readptr&511);
			}
		update_3d();
		} while (paused && in_game);
	display_message("");
	paused = false;
#if DEBUGGING == ON
	if( match_time.min <= 43)
		match_time.min = 43;
	else if( match_time.min <= 87)
		match_time.min = 87;			
	else if( match_time.min <=103)
		match_time.min = 103;
	else if( match_time.min <=118)
		match_time.min = 118;
#endif

	stop_mf_time();
}

/******************************************************************************
*****************************************************************************/
void process_keys()
{
KeyMap newkeyMap;

	if (!demo_match)	// || debug)
		{
		if (paused)
			pause_game();
		}
	else
		{
		GetKeys( newkeyMap);
/*
#if USERAVEENGINE==YES
		if( memcmp( newkeyMap, lastkeyMap, sizeof(KeyMap)))
			{
			if( newkeyMap[0] & 0x100000)
				gYaw++;
			if( newkeyMap[0] & 0x1000000)
				gYaw--;
			if( newkeyMap[0] & 0x200000)
				gPitch++;
			if( newkeyMap[0] & 0x2000000)
				gPitch--;
			if( newkeyMap[0] & 0x400000)
				gRoll++;
			if( newkeyMap[0] & 0x4000000)
				gRoll--;
			if( newkeyMap[0] & 0x800000)
				cx++;
			if( newkeyMap[0] & 0x8000000)
				cx--;
			gYaw = (gYaw+360) % 360;
			gPitch = (gPitch+360) % 360;
			gRoll = (gRoll+360) % 360;
			}
		newkeyMap[0] &= ~(0x100000|0x1000000|0x200000|0x2000000|0x400000|0x4000000|0x800000|0x8000000);
#endif
*/
		if( memcmp( newkeyMap, lastkeyMap, sizeof(KeyMap)))
			end_game=TRUE;
		memcpy( lastkeyMap, newkeyMap, sizeof(KeyMap));
		}
}

/******************************************************************************
*****************************************************************************/

void animate_players()
{
int i;

	for (i=0; i<players; i++)
	{
		teams[i].tm_frm+=teams[i].tm_fstep;
	}

	for (i=0; i<3; i++)
	{
	 	refs[i].frm+=refs[i].fstep;
	}
}

/******************************************************************************
*****************************************************************************/

#if 0
void update_2d()
{
	if	(plot_buffer)
		plot_cnta=1;
	else
		plot_cntb=1;

	_setplotaction(_GPSET);
	process_butts();
	_setplotaction(_GXOR);
	if (Mouse.b&&1)
		mouse_fired();
	draw_ball();
	draw_team();
	draw_buffer();

	plot_buffer=!plot_buffer;
	draw_buffer();
	delay(delay_cnt);
	panel_data();
}

#endif

/******************************************************************************
*****************************************************************************/

void reset_possession()
{
	poss_held=0;
	possession=0;
}

/******************************************************************************
*****************************************************************************/

void accumulate_possession()
{
	if (ball_poss>11)
	{
// Team b. currently has possession...
		poss_held+=(0.0001+(ABS(poss_held)/30));
		if (poss_held>0.5)
			poss_held=0.5;
	}
	else
	{
		if (ball_poss)
// Team a. currently has possession...
		{
			poss_held-=(0.0001+(ABS(poss_held)/30));
			if (poss_held<-0.5)
				poss_held=-0.5;
		}
	}
	
	if (!ball_poss)
	{
// Ball is free...(tend slowly towards 0)
		poss_held+=(-poss_held/60);
	}

	possession+=poss_held;
	if (possession>1)
		possession=1;
	if (possession<-1)
		possession=-1;
}

/******************************************************************************
*****************************************************************************/

void process_crowd_noise()
{
	if (shot_missed)
	{
		if (shot_missed<0)
		{
// Missed by a long way...
			shot_missed++;
			if (last_touch<12)
			{
// team A shot...
				crowd_mood_a=CN_BOO;
				crowd_mood_b=CN_LAUGH;
			}
			else
			{
// team B shot...
				crowd_mood_a=CN_LAUGH;
				crowd_mood_b=CN_BOO;
			}
		}
		else
		{
// Near missed...
			shot_missed--;
			if (last_touch<12)
			{
// team A shot...
				crowd_mood_a=CN_MISS;
				crowd_mood_b=CN_PENSIVE;
			}
			else
			{
// team B shot...
				crowd_mood_a=CN_PENSIVE;
				crowd_mood_b=CN_MISS;
			}
		}
	}
	else
	{
		if (shot_saved)
		{
// Shot stopped...
			shot_saved--;
			if (last_touch<12)
			{
// team A save...
				crowd_mood_a=CN_SAVE;
				crowd_mood_b=CN_MISS;
			}
			else
			{
// team B save...
				crowd_mood_a=CN_MISS;
				crowd_mood_b=CN_SAVE;
			}
		}
		else	
		{
			if (card_is_out)
			{
				card_is_out--;
				crowd_mood_a=CN_FOWL;
				crowd_mood_b=CN_FOWL;
			}
			else
			{
				if (match_half>10)
				{
// End of Game...
					crowd_mood_a=CN_EXCITED;
					crowd_mood_b=CN_EXCITED;
				}
				else
				{
					switch(match_mode)
					{
						case(NORMAL_PLAY):
				
							if (shot_pending && shot_acknowledged)
							{
// Keeper is reacting to incoming ball...
								if (ballx<prat*40 && ballxdis<0 && last_touch>11)
								{
// Ball coming left (from team B)...
									crowd_mood_a=CN_PENSIVE;
									crowd_mood_b=CN_EXCITED;
								}
								if (ballx>(pitch_len-(prat*40)) && ballxdis>0 && last_touch<12)
								{
// Ball coming right (from team A)...
									crowd_mood_a=CN_EXCITED;
									crowd_mood_b=CN_PENSIVE;
								}
							}
							else
							{
								accumulate_possession();
					
								if (ball_in_hands && (ball_poss==KP_A || ball_poss==KP_B))
								{
// Keepers ball...(calm)
									crowd_mood_a=CN_NORMAL;
									crowd_mood_b=CN_NORMAL;
								}
								else
								{
									if ((ballx>(cntspot_x-prat*16)) && (ballx<(cntspot_x+prat*16)))
									{
// In mid-field...
										crowd_mood_a=CN_NORMAL;
										crowd_mood_b=CN_NORMAL;
									}
									else
									{
										if (ballx<=(cntspot_x-prat*16))
										{
// Near Goal A...
											if (possession>0.5)
											{
// Team B has good possession...
												crowd_mood_a=CN_PENSIVE;
												crowd_mood_b=CN_EXCITED;
											}
											else
											{
												if (possession<-0.5)
												{
// Defending team A has it under control...
													crowd_mood_a=CN_NORMAL;
													crowd_mood_b=CN_NORMAL;
												}
												else
												{
// No one team has it under control...
													crowd_mood_a=CN_NORMAL;
													crowd_mood_b=CN_ENCOURAGING;
												}
											}
										}
										else
										{
// Near Goal B...
											if (possession<-0.5)
											{
// Team A has good possession...
												crowd_mood_a=CN_EXCITED;
												crowd_mood_b=CN_PENSIVE;
											}
											else
											{
												if (possession>0.5)
												{
// Defending team B has it under control...
													crowd_mood_a=CN_NORMAL;
													crowd_mood_b=CN_NORMAL;
												}
												else
												{
// No one team has it under control...
													crowd_mood_a=CN_ENCOURAGING;
													crowd_mood_b=CN_NORMAL;
												}
											}
										}
									}
								}
		
								if (just_scored)
								{
// someone has scored a goal...
									if (ballx<cntspot_x)
									{
// Team A. goal...
										if (goal_scorer>11)
										{
// Team B scores good goal!
											crowd_mood_a=CN_PENSIVE;
											crowd_mood_b=CN_CELEBRATE;
										}
										else
										{
// Team A scores own goal!
											crowd_mood_a=CN_BOO;
											crowd_mood_b=CN_CELEBRATE;
										}						
									}
									else
									{
// Team B. goal...
										if (goal_scorer<12)
										{
// Team A scores good goal!
											crowd_mood_a=CN_CELEBRATE;
											crowd_mood_b=CN_PENSIVE;
										}
										else
										{
// Team B scores own goal!
											crowd_mood_a=CN_CELEBRATE;
											crowd_mood_b=CN_BOO;
										}						
									}
								}
							}
							break;
		
						case(DF_KICK_B):
							if (!men_in_wall)			// Not in shooting range!
							{
								if ((ballx>(cntspot_x-prat*16)) && (ballx<(cntspot_x+prat*16)))
								{
// In mid-field...
									crowd_mood_a=CN_NORMAL;
									crowd_mood_b=CN_NORMAL;
								}
								else
								{
									if (ballx<=(cntspot_x-prat*16))
									{
// Near Goal A...
										crowd_mood_a=CN_PENSIVE;
										crowd_mood_b=CN_ENCOURAGING;
									}
									else
									{
// Near Own Goal B...
										crowd_mood_a=CN_NORMAL;
										crowd_mood_b=CN_NORMAL;
									}
								}
								break;
							}
		
						case(CORNER_TL):	
						case(CORNER_BL):	
							crowd_mood_a=CN_PENSIVE;
							crowd_mood_b=CN_EXCITED;
							break;
					
						case(DF_KICK_A):
							if (!men_in_wall)			// Not in shooting range!
							{
								if ((ballx>(cntspot_x-prat*16)) && (ballx<(cntspot_x+prat*16)))
								{
// In mid-field...
									crowd_mood_a=CN_NORMAL;
									crowd_mood_b=CN_NORMAL;
								}
								else
								{
									if (ballx>=(cntspot_x+prat*16))
									{
// Near Goal B...
										crowd_mood_a=CN_ENCOURAGING;
										crowd_mood_b=CN_PENSIVE;
									}
									else
									{
// Near Own Goal A...
										crowd_mood_a=CN_NORMAL;
										crowd_mood_b=CN_NORMAL;
									}
								}
								break;
							}
						
						case(CORNER_TR):	
						case(CORNER_BR):	
							crowd_mood_a=CN_EXCITED;
							crowd_mood_b=CN_PENSIVE;
							break;
		
						case(GOAL_KICK_TL):
						case(GOAL_KICK_TR):
						case(GOAL_KICK_BL):
						case(GOAL_KICK_BR):
							crowd_mood_a=CN_NORMAL;
							crowd_mood_b=CN_NORMAL;
							reset_possession();
							break;
		
						case(IF_KICK_A):
						case(THROW_IN_A):
							if ((ballx>(cntspot_x-prat*16)) && (ballx<(cntspot_x+prat*16)))
							{
// In mid-field...
								crowd_mood_a=CN_NORMAL;
								crowd_mood_b=CN_NORMAL;
							}
							else
							{
								if (ballx>=(cntspot_x+prat*16))
								{
// Near Goal B...
									crowd_mood_a=CN_ENCOURAGING;
									crowd_mood_b=CN_PENSIVE;
								}
								else
								{
// Near Own Goal A...
									crowd_mood_a=CN_NORMAL;
									crowd_mood_b=CN_NORMAL;
								}
							}
							break;
		
						case(IF_KICK_B):
						case(THROW_IN_B):
							if ((ballx>(cntspot_x-prat*16)) && (ballx<(cntspot_x+prat*16)))
							{
// In mid-field...
								crowd_mood_a=CN_NORMAL;
								crowd_mood_b=CN_NORMAL;
							}
							else
							{
								if (ballx<=(cntspot_x-prat*16))
								{
// Near Goal A...
									crowd_mood_a=CN_PENSIVE;
									crowd_mood_b=CN_ENCOURAGING;
								}
								else
								{
// Near Own Goal B...
									crowd_mood_a=CN_NORMAL;
									crowd_mood_b=CN_NORMAL;
								}
							}
							break;
		
						case(PEN_KICK_A):
						case(PEN_KICK_B):
						case(SWAP_ENDS):
							crowd_mood_a=CN_EXCITED;
							crowd_mood_b=CN_EXCITED;
							break;
					
						case(CENTRE_A):
						case(CENTRE_B):
							reset_possession();
							if (kickoff)
							{
								crowd_mood_a=CN_EXCITED;
								crowd_mood_b=CN_EXCITED;
							}
							else
							{
								crowd_mood_a=CN_NORMAL;
								crowd_mood_b=CN_NORMAL;
							}
							break;
					}
				}
			}
		}
	}
}

/******************************************************************************
*****************************************************************************/

char nothing_happening()
{
// 	if (ball_limbo_on)		// Joolz (Saturn)
//		return(FALSE);

	if (!match_mode && !just_scored)
		{	// In Play...
		if (shot_pending || dead_ball_cnt || game_action)
			return(FALSE);			// Crucial moment!
		return(TRUE);
		}
	else
		{
		if (match_mode<=CORNER_BR || match_mode>=PEN_KICK_A)
			return(FALSE);			// Crucial moment!
		else if ((match_mode==DF_KICK_B || match_mode==DF_KICK_A) && men_in_wall)
			return(FALSE);			// Crucial moment!
		else
			return(TRUE);
		}
}

/******************************************************************************
*****************************************************************************/

void watch_match_time()
{
	if (match_info.CompetitionType==PENALTIES)
	{
// Practice penalties...
		if (!penalty_game)
		{
			if (team_a_goals!=team_b_goals)
			{
// Someone has won shoot-out...
				if (match_half<11)
				{
// Initialise end of penalty shoot-out...
					last_goal=0;
					match_mode=SWAP_ENDS;
					init_match_mode();
					do_full_time_anim(0);
					match_info.team_a_penalties=team_a_goals;
					match_info.team_b_penalties=team_b_goals;
					do_final_score_menu();
					match_half=11;			// End game!
					PlayCommentaryMessage(TI_FULLTIME);
					next_mins=0;
				}
			}
			else
			{
// Initialise penalty shoot-out...
				match_info.penalties=TRUE;
				penalty_game=TRUE;
				team_a_goals=0;
				team_b_goals=0;
				match_info.team_a_penalties=team_a_goals;
				match_info.team_b_penalties=team_b_goals;
				do_penalty_shootout_menu();
				next_mins=0;
			}
		}
	}
	else
	{
	 	if (match_time.min>=(45+injury_time) && !match_half && nothing_happening())
		{
// End of first half! (It's a game of two halves...)
#if ROLLING_DEMO == OFF
			match_mode=SWAP_ENDS;
			last_goal=0;
			init_match_mode();
			play_fx(PS_HALFTIMEWHISTLE,refs[0].x,refs[0].y);
			do_half_time_anim(0);
			do_halftime_menu();
			PlayCommentaryMessage(TI_HALFTIME);
			kickoff=TRUE;
			next_mins=45;
			if (practice)
				match_half=12;
#else
			last_goal=0;
			match_mode=SWAP_ENDS;
			init_match_mode();
			play_fx(PS_FULLTIMEWHISTLE,refs[0].x,refs[0].y);
			do_full_time_anim(0);
			do_fulltime_menu();
			PlayCommentaryMessage(TI_FULLTIME);
			match_half=11;			// End game!
			next_mins=0;
#endif
		}
		else
		{
			if (match_time.min>=(90+injury_time) && match_half==1 && nothing_happening())
			{
// End of full time! (Not half mate...)
				last_goal=0;
				match_mode=SWAP_ENDS;
				init_match_mode();
				play_fx(PS_FULLTIMEWHISTLE,refs[0].x,refs[0].y);

				if (need_result && team_a_goals==team_b_goals)
				{
					do_extra_time_anim(0);
					do_extratime_menu();
					match_info.extra=TRUE;
					kickoff=TRUE;
					next_mins=90;
				}
				else
				{
					do_full_time_anim(0);
					do_fulltime_menu();
					PlayCommentaryMessage(TI_FULLTIME);
					match_half=11;			// End game!
					next_mins=0;
				}
			}
			else
			{
				if (need_result && match_time.min>=(90+15+injury_time)
				 	&& match_half==2 && nothing_happening())
// End of first half of extra time! (It's a game with more halves...)
				{
					last_goal=0;
					match_mode=SWAP_ENDS;
					init_match_mode();
					do_half_time_anim(0);
					do_halftime_menu();
					play_fx(PS_HALFTIMEWHISTLE,refs[0].x,refs[0].y);
					kickoff=TRUE;
					next_mins=105;
				}
				else
				{
					if (!penalty_game && need_result && match_time.min>=(90+30+injury_time)
					 	&& match_half==3 && nothing_happening())
// End of full extra time!
					{
						play_fx(PS_FULLTIMEWHISTLE,refs[0].x,refs[0].y);
						if (need_result && team_a_goals==team_b_goals)
						{
							match_info.penalties=TRUE;
							penalty_game=TRUE;
							team_a_goals=0;
							team_b_goals=0;
							match_info.team_a_penalties=team_a_goals;
							match_info.team_b_penalties=team_b_goals;
							do_penalty_shootout_menu();
							next_mins=0;
						}
						else
						{
							last_goal=0;
							match_mode=SWAP_ENDS;
							init_match_mode();
							do_full_time_anim(0);
							if (match_info.penalties)
							{
								match_info.team_a_penalties=team_a_goals;
								match_info.team_b_penalties=team_b_goals;
								do_final_score_menu();
							}
							else
								do_fulltime_menu();
							match_half=11;			// End game!
							PlayCommentaryMessage(TI_FULLTIME);
							next_mins=0;
						}
					}
				}
			}
		}
	}
}

/******************************************************************************
*****************************************************************************/

void setup_alarm()
{
	mf_fixed=FALSE;
	alarm=FALSE;					// Debug alarm on/off.
	watch=TRUE;
	stop_min=45;
	stop_sec=1;						// Debug alarm stop.
}

/******************************************************************************
*****************************************************************************/

void init_wind()
{
// Wind stuff...
	if (match_info.wind)
	{
		init_wind_x=1;
		init_wind_y=0;
		wind_x=init_wind_x;
		wind_y=init_wind_y;
		init_wind_speed=match_info.wind*30;   // (30,60,90)
		wind_speed=init_wind_speed;
		wind_var_ang=0;
		wind_d_trend=0;
		wind_s_trend=0;

		AF_randomize(__FILE__,__LINE__);
		if (!(seed&3))
			wind_on=-TRUE;		// Variable wind!
		else
			wind_on=TRUE;

		wind_on=TRUE;
	}
	else
		wind_on=FALSE;
}

/******************************************************************************
*****************************************************************************/

// Get your grubby mits off these routines Andy!

void NetUserInit()
{
int ctrl;

	if (network_on)
	{
		// Network init users
		for (int i=0;i<network_on;i++)
		{
			if (i==wConsoleNode)
				ctrl=convert_control(match_info.control_methods[0]);
			else
				ctrl=NET_CTRL;

			if ( !NetTeams[i])
				if (Players[i]==1)
					add_team_user(TEAM_A,ctrl);
				else
					add_fixed_user(Players[i],ctrl);
			else
				if (Players[i]==1)
					add_team_user(TEAM_B,ctrl);
				else
					add_fixed_user(Players[i]+11,ctrl);
		}
	}
}

int otick;
void TimerInit()
{
	ftick=0;
	otick=tick=VblTicks=0;
	old_count=count;

//	if (!old_mf)
//		{
//		get_user_inputs();
//		process_user_inputs();
//		writeptr++;
//		}

	while(tick==otick)
		;
}

/******************************************************************************
*****************************************************************************/

void reset_front()
{
	for (int i=0; i<sizeof(cam_array); i++)
	{
		if (camera==cam_array[i])
		{
			match_info.camera=i;
			match_info.camera_toggle=i;
			break;
		}
	}
}

/*
extern float camera_x, camera_y, camera_z;

#define MAX_W 200

static void do_walkaround_logic()
{
static mode = 0;
static float cx = 440.0;
static float cy = 400.0;
static float cz = 75.0;

	camera = 3;

	if( ! (mode & 63))
		{
		switch( mode>>6)
			{
			case 0:
					cx = -250; cy = -250;
					break;
			case 1:
			case 2:
			case 3:
			case 4:
					cx += 445;
					break;
			case 5:
			case 6:
			case 7:
			case 8:
					cy += 325;
					break;
			case 9:
			case 10:
			case 11:
			case 12:
					cx -= 445;
					break;
			case 13:
			case 14:
			case 15:
			case 16:
					cy -= 325;
					break;
			case 17:
					mode = -1;
			}
		}
	mode ++;
	camera_x = cx;
	camera_y = cy;
	camera_z = cz;
}
*/

#if GAME_DEBUG==ON
static int loop_count;
static Boolean Record = true;
#endif

/******************************************************************************
*****************************************************************************/
int match(int argc, char **argv)
{
int match_err=FALSE;
float cd=set_camera_dist;
float ch=set_camera_height;

	RandCounter = 0;

	initialise_vars();

#if GAME_DEBUG==ON
	GameDebugFP = fopen("Game.debug","w+");
	loop_count = 0;
#endif

#ifdef NET_GAME
	// Pseudo net initialisation (not normally used)
	NetTest();
#endif

	if (network_on)
		{
		time_factor=time_table[net_half];		// Real minutes duration.
		old_mf=FALSE;
		}
	else
		{
		time_factor=time_table[match_info.time];	// Real minutes duration.
		old_mf=TRUE;
		}
		
	if (match_info.CompetitionType==PRACTICE)
		offside_on=FALSE;
	else
		offside_on=match_info.offside;

	// Set up default camera...
	camera=cam_array[match_info.camera];
	change_cam(camera);
	set_camera_dist=cd;
	set_camera_height=ch;

	// Set up audio...
	audio_version=(char)match_info.audio;

	// Debugging alarm...
	setup_alarm();
	
	set_normal_color(WHITE);

	say_names=TRUE;

#if ROLLING_DEMO != OFF
	time_factor=4;
#endif

	init_wind();

	gravity=0.60;

	on_3d=TRUE;
	close_in_number=2;
	goal_kicker_a=1;
	goal_kicker_b=12;

	fkick_taker_a=0;
	fkick_taker_b=0;

	corn_kicker_a=0;
	corn_kicker_b=0;

	init_officials();

	init_match();
	
	if (init_3d()<0)
		goto ERR_3D;

	if (audio_version)
		{
		InitMatchAudio(rand_seed);
		if (!LoadPitchSamples())
			if (!LoadTeamSamples(setup.team_a,HOME_TEAM))
				if (!LoadTeamSamples(setup.team_b,AWAY_TEAM))
					{
					LoadCommentarySamples();
					StartCrowd(HOME_TEAM);
					StartCrowd(AWAY_TEAM);
					}
		}

	// Pseudo net user initialisation (not normally used)
	NetUserInit();

	// Wait for everyone to get here, set timer & machine factor...
	readptr=writeptr=0;
	Network_Play_Ready();

	if (audio_version)
		PlayWelcomeMessage();

	// Various timing initialisations for network (DO NOT MOVE)
	TimerInit();
	mf_scale=omf_scale=0.5;
	MF=1;
	old_clock=clock();
	oldcnt=count;

	// Main program loop...

	do_ref_menu();

	if( argc)
		{
		demo_match=TRUE;
		GetKeys( lastkeyMap);
		}

	ClearBuffer();
	ClearScreen();
	PaletteFlag = PALETTE_FADE_UP;	
	while ((in_game && !Button() && !end_game) || PaletteFlag)
		{
		if( PaletteFlag)
			FadeThePalette();
		Frames++;
#if DEBUGGING == ON
		if( keyMap[3]&0x00000200)
			DebugStr("\pDebugger Break");
#endif

#if GAME_DEBUG==ON
//		fprintf( GameDebugFP, " Loop  %d, %x\n", ++loop_count, rand_seed);
#endif

		if (!old_mf)		// New logical loop
			{
				int ttick=tick;
				int tftick=ftick;

				if ((mf_fixed) || (!on_3d) || (!watch && alarm))
					ttick=tick=otick+1,tftick=ftick=0,mf_scale=omf_scale=0;

				mf_scale=(float)tftick/TIMER_SPEED;
				MF=(ttick+mf_scale)-(otick+omf_scale);
				omf_scale=mf_scale;
				log_factor=MF;						// Passed to 3d (Logic cycles/update)

				for (float i=otick; i<ttick && in_game; i++)
					{
					process_crowd_noise();
					if (audio_version)
	  					{
						process_crowd_noise();
						UpdateCrowd(crowd_mood_a,team_a);
						UpdateCrowd(crowd_mood_b,team_b);
						UpdateCommentary();
						}

					if(readptr==writeptr)
						{
						int ptick=tick;
						int pftick=ftick;
						NetworkUserControl();
						do	{
							Polling_Network();
							} while (readptr==writeptr && in_game);
						tick=ptick;
						ftick=pftick;
						}

					convert_inputs();
					++readptr&=511;
					if (!replay_cnt && !line_up)
						{
						do_logic();
						}
					else
						if (line_up)
							{
							line_up--;
							animate_players();
							if (!line_up)
								{
								match_mode=CENTRE_A;
								init_match_mode();
								}
							}

					new_update_coords();
//					process_replay();		// No Replay Allowed
					watch_match_time();
					}
				otick=ttick;
			}
		else
			{
			if ((mf_fixed) || (!on_3d) || (!watch && alarm))
				MF=1;

			mf_scale+=MF;
			log_factor=MF;				// Passed to 3d(Logic cycles/update)

			for (float i=(mf_scale); (i>1); i=i-1)
				{
				process_crowd_noise();
				if (audio_version)
	 				{
					process_crowd_noise();
					UpdateCrowd(crowd_mood_a,team_a);
					UpdateCrowd(crowd_mood_b,team_b);
					UpdateCommentary();
					}

				if( !demo_match)
					{
					get_user_inputs();
					process_user_inputs();
					writeptr = (++writeptr&511);
					convert_inputs();
					readptr = (++readptr&511);
					}
				if (!line_up)
					{
//					do_walkaround_logic();
					do_logic();
					}
				else
					{
					line_up--;
					animate_players();
					if (!line_up)
						{
						match_mode=CENTRE_A;
						init_match_mode();
						}
					}

				new_update_coords();
				process_replay();
				watch_match_time();
				mf_scale=mf_scale-1;
				}
			}

		if (!(!watch && alarm))
			{
			realtime_coords();
			process_pitch_sprs();

			update_3d();
			if (old_mf)
				frame_count();
			else
				updates++;
			process_keys();
			}

		if( end_game)
			break;
	}

#if GAME_DEBUG==ON
	fclose( GameDebugFP);
#endif

	// Remove network (if appropriate)
	Quit_Network_Play();

	if (audio_version)
		StopAudio();


#if USERAVEENGINE==YES
	if( UseRaveEngine)
		end3d_rave();
#endif
	end3d_gremlin();

	if(replay_seconds)
	  FreeX(replay_tab);

	// Inform front end on times...
	if (end_game)
		match_info.return_mins=-1;
	else
		match_info.return_mins=match_time.min;		

	if (audio_version)
		{
		FreeCommentarySamples();
		FreeTeamSamples(AWAY_TEAM);
		FreeTeamSamples(HOME_TEAM);
		FreePitchSamples();
		HeapPurge();
		}

	// Give back front end enviroment stuff...
	reset_front();

	return(FALSE);		// No errors...

/************ ERRORS *************/
ERR_3D:
	// Remove network (if appropriate)
	Quit_Network_Play();

	match_err+=256;
	goto RETURN_ERR;

RETURN_ERR:
	return(match_err);
}

void ProcessOptUser( int opt_user)
{
	if (!network_on && !player_on_off && !line_up && match_mode!=SWAP_ENDS)
		{
		if (opt_user)
			{
			if (users[opt_user-1].type==-1)
				opt_team=team_a;
			else
				{
				if (users[opt_user-1].type==-2)
					{
					opt_team=team_b;
					}
				else
					{
					if (users[opt_user-1].type<12)
						{
						opt_team=team_a;
						}
					else
						{
						opt_team=team_b;
						}
					}
				}
			}
		}
}

void ProcessNetMessages( short *data)
{
int i, p;

	for( i=0; i<MAX_NET_USERS; i++)
		users_dir_i[writeptr][i].x_f1 = users_dir_i[writeptr][i].y_f2 = 0x0000; // Nothing
	for (i=0; i<network_on; i++)
		{
		users_dir_i[writeptr][i].x_f1 = data[0];
		users_dir_i[writeptr][i].y_f2 = data[1];
		data +=2;
		}
	++writeptr&=511;
}

void ProcessDeletePlayer( int player)
{
	delete_net_user( player+1);
}

