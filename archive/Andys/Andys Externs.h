/******************************************************************************
******************************************************************************/

//#include "Andy Menu.h"

extern char not_ahead;
extern short new_text;
extern char *text_mess;
extern char sel_circle[22];
extern short burst_timer[5];
extern short keep_timer;
extern char stop_clock;
extern char keep_dive;
extern short hold_up_play;
extern short comsetp;
extern char wall_is_up;
extern short card_is_out;

extern char old_mf;

extern int deb_1;
extern int deb_2;
extern int deb_1a;
extern int deb_2a;
extern int deb_x;
extern int deb_y;
extern int deb_a;
extern int deb_b;
extern int deb_c;
extern int deb_ic;
extern int deb_is;

extern float deb_data;

// Timing Vars...

extern short updates;
extern int old_count;

// Global Constants

// Sound Fx. flags etc...

extern short int crowd_mood_a;
extern short int crowd_mood_b;
extern float possession;
extern float poss_held;
extern char kickoff;

extern char demo_match;

struct intercept_data {
	short t;
	short free;
	short ptype;
	short pplr;
	short gt;
	float x;
	float y;
	float atime;
	char stop;
};

extern intercept_data strike[11];
extern char special_move;

// Capture timing vars...

extern float ft_ktm,ft_vtm,ft_dtm,ft_otm,ft_stm,ft_jtm,ft_ttm,ft_ctm,ft_utm;

extern unsigned char machine_no;
extern char end_game;
extern char team_a,team_b;
extern char last_centre;

extern char match_half;
extern char first_time_it;
extern char need_result;
extern short injury_time;

//#include "3deng.h"

// extern char debug;

struct butts {
	int x;
	int y;
	int w;
	char s[10];
	char l;
};

extern butts us_buttons[];

extern int max_butts;

// Pixel Colours.

extern char ball_col;
extern char shadow_col;
extern char team_a_col;
extern char team_b_col;

// General Control variables...

extern short opt_user,opt_team;
extern char options_on;
extern char sub_pending;
extern short replay_seconds;
extern short line_up;
extern short player_being_subbed;
extern short player_on_off;
extern short player_coming_on;
extern short subbing_now;
extern char booking;
extern char first_update;

// Ball fx.

extern float newdx,newdy;

extern short wind_on,wind_d_trend,wind_s_trend;
extern float wind_x,wind_y,wind_speed;
extern float init_wind_x,init_wind_y,init_wind_speed;
extern float wind_var_ang;

extern float bounce_dis;
extern float gravity;
extern int cntspot_x;
extern int cntspot_y;

// Pitch sizes.
extern int pitch_len, pitch_wid;
extern int halfway_line, scr_pinch;
extern int right_bounds;
extern int left_bounds;
extern int lower_bounds;
extern int upper_bounds;
extern float zone_wid;
extern float zone_hgt;
extern float prat;
extern int goal_height;	//8 feet
extern int goal_depth;		//8 feet
extern int post_width;					//5 inches approx.
extern int top_post_y;
extern int bot_post_y;

// Players.

extern int players;
extern int avg1_rate,avg1_power,avg1_bcontrol,avg1_flair,
		avg1_vision,avg1_accuracy,avg1_fitness,avg1_disc;
extern int avg2_rate,avg2_power,avg2_bcontrol,avg2_flair,
		avg2_vision,avg2_accuracy,avg2_fitness,avg2_disc;


/******************************************************************************
******************************************************************************/

// Major control variables...

extern char audio_version;

/******************************************************************************
******************************************************************************/

// Randomize variables...

extern short int rand1_tab[];
extern short int rand2_tab[];
extern char andys_random;


// Global Match Variables...

// Man to man marking table....

extern int man2man[10][2];
extern char man2man_a,man2man_b;

struct mtime{
		unsigned short min;
		float sec;
		};

extern int seconds;
extern mtime match_time;
extern short next_mins;

extern int time_factor;
extern char clock_running;

extern float MF;
extern float mf_scale;
extern float omf_scale;
extern char mf_fixed;
extern char alarm,watch;
extern int stop_min;
extern int stop_sec;
extern char practice;
extern char team_a_on;
extern char team_b_on;

extern char arrow_on;
extern char arrow_guy;

extern short rand_seed,seed;
extern int logic_cnt;
extern char ball_move;
extern float man_down;

extern int match_tactics1[32*2+6][10][2];
extern int match_tactics2[32*2+6][10][2];

extern int launch_type;
extern float launch_x,launch_y;
extern float ballxdis, ballydis, ballzdis;
extern float eff_ballx,eff_bally,eff_ballz;
extern float ballx, bally, ballz;
extern float ballx_out,bally_out,ballz_out;
extern float mcap_ballx,mcap_bally,mcap_ballz;
extern float save_ballx,save_bally,save_ballz;
extern int save_ball_poss;
extern short good_poss;

extern float b_xoff,b_yoff,b_zoff;
extern float prev_ballx, prev_bally, prev_ballz;
extern float ns_ballx, ns_bally, ns_ballz;
extern float ball_zspin, ball_xyspin;
extern float full_zspin, full_xyspin;
extern float shoot_x,shoot_y;

extern int first_bounce;
extern int swerve, spin_cnt, spin_ball, prediction;
extern float ball_horz_ang,ball_vert_ang;
extern float ball_diam;

extern float max_sw_factor,swerve_factor;
extern char rebound_ball;
extern char headed_ball;
extern char say_names;
extern char fired_a_shot;
extern char comm_pass,comm_pass_type;

extern float keeper_spd;
extern short keeper_down;
extern int keeper_will_save;
extern char keeper_on_grnd;
extern float keeper_contact;
extern int set_xyspin,set_zspin;
extern int throw_cnt;
extern char ball_in_goal;
extern char ball_in_hands;
extern short game_action;
extern int team_a_goals;
extern char last_goal;
extern int team_b_goals;
extern char scorer_running;
extern int just_scored;
extern int just_thrown;
extern int goal_scorer;
extern int pass_type;
extern int kick_type;
extern int receiver;
extern char cross_now;
extern char auto_select;
extern char must_face;
extern short must_face_time;
extern float must_face_x;
extern float must_face_y;
extern char must_shoot;
extern char chip_pass;
extern char must_pass;
extern char must_punt;
extern char keeper_a_in_box;
extern char keeper_b_in_box;
extern int keeper_steps;
extern short save_block;
extern float save_xoff,save_yoff,save_zoff;

extern float shot_speed;

extern int scr_x,scr_y,ball_speed,ball_int_speed;
extern int interceptor_a;
extern int interceptor_b;
extern int in_cross_area;
extern float close_in_number;

extern int ball_inair, super_shot, opponents_near_holder,opponents_really_close;
extern int ball_poss,sender_1_2,ball_still,last_touch,want_pass;
extern int before,support_me;
extern int cannot_pick_up;
extern int pre_kp_touch;
extern int prev_touch;

extern int ball_limbo_p;
extern char ball_limbo_on;
extern float ball_limbo_c;
extern int ball_released;
extern short forced;
extern short last_user_a;
extern short last_user_b;
extern short last_plr_a;
extern short last_plr_b;
extern short players_off_a;
extern short players_off_b;

extern int want_pass_stat,ball_zone1,ball_zone2,ball_out_of_play;
extern int nearest_a,nearest_b,old_ltouch,old_ball_poss;
extern char use_ball_limit;
extern short near_path_a,near_path_b;
extern short receiver_a,receiver_b;
extern int zone1_x,zone1_y,zone2_x,zone2_y;
extern int incident_x,incident_y;
extern int difficulty;
extern int ready_centre;

extern float ball_pred_tab[50][3];
extern float ns_ball_pred_tab[50][3];

extern int shooter;
extern char force_select;
extern short heading_ball;
extern char shot_attempt;
extern char flag;
extern volatile char in_game;
extern char analogue;
extern char match_mode;
extern char last_match_mode;
extern int dead_ball_cnt;
extern int defense_a,defense_b;

extern int savex,savey,savez;
extern char shot_acknowledged;
extern int shot_pending;
extern int real_shot;
extern char tweening;
extern short shot_missed;
extern short shot_saved;


/******************************************************************************
******************************************************************************/

// Screen Buffer Stuff...
//extern int scr_a[100][4];
//extern int scr_b[100][4];
//extern int plot_cnta;
//extern int plot_cntb;
//extern int plot_buffer;
extern int replay_pos;
extern int old_rep_pos;
extern int replay_cnt;
extern int pitch_sprs;

// Sprite Stuff...

extern float spr_coord_tab[MAX_3D_SPRS*3+1];
extern short spr_ref_tab[MAX_3D_SPRS];

// User Interface...

extern short ball_travel;
extern short select_cnt;

extern int button_lit;
extern int delay_cnt;
extern int play_nums_on;
//extern char *action;
extern char fframe;

extern float setp_x;
extern float setp_y;

extern short setp_wait_cnt;
extern int oldcnt;
extern int frames;
extern int frms_per_sec;
extern int game_speed;		// Currently declared in network.c
extern int last_second;
extern int old_clock;

#pragma pack (1)

struct user_config{
	short type;
	short control;
	int inp_x;
	int inp_y;
	int inp_ox;
	int inp_oy;
	short inp_fb;
	char chng;
	signed char plr;
	};

extern volatile user_config users[MAX_NET_USERS];	// Declared in network.c

struct user_vectors_i{
	short x_f1;
	short y_f2;
	};

extern volatile user_vectors_i users_dir_i[512][MAX_NET_USERS];	// Declared in network.c

#pragma pack (4)

extern volatile int writeptr;
extern volatile int readptr;

struct user_vectors{
	float x;
	float y;
	char m;
	char f;
	};

extern user_vectors users_dir[MAX_NET_USERS];	// Declared in glob_vars.h, as usual

extern short lp_user;
extern short fixed_net_user;
extern short auto_users_list_a[10];
extern short auto_users_a;
extern short auto_users_list_b[10];
extern short auto_users_b;
extern short play_ball_a;
extern short play_ball_b;
extern char new_select;
extern char auto_intercept;
extern char closest;


extern char user_controlled;
extern char user_plr;
extern char after_touch_on;
extern char drive_shot;
extern char newk_shot;
extern int num_of_users;	// Currently in network.c

extern short f1_down;
extern short f2_down;

extern char spec_kick_type;
extern float setp_hgt;
extern float setp_power;
extern float setp_kick_x;
extern float setp_kick_y;
extern float setp_bxd;
extern float setp_byd;
extern float setp_bzd;

extern short user_taker;
extern short user_taker2;

// Input devices

extern float ux,uy;		// User x,y,f1,f2,move
extern char uf1,uf2;
extern char um;

// Joysticks & keyboard, taken to network.c

//extern signed char key1[6];
//extern signed char key2[6];

//extern unsigned short joy1_cnt_x,joy1_cnt_y;
//extern unsigned short joy2_cnt_x,joy2_cnt_y;

//extern int joy1_max_x,joy1_max_y,joy1_min_x,joy1_min_y;
//extern int joy2_max_x,joy2_max_y,joy2_min_x,joy2_min_y;

//extern volatile int joy1_x;
//extern volatile int joy1_y;
//extern volatile int joy1_fire;

//extern volatile int joy2_x;
//extern volatile int joy2_y;
//extern volatile int joy2_fire;

//extern volatile char joy1_move;
//extern volatile char joy2_move;

//extern char joystick1_on;
//extern char joystick2_on;

//extern char digital_joy1;
//extern char digital_joy2;


extern char camera;
extern short new_cam;
extern char old_cam;
extern char rep_camera;
extern char sub_camera;
extern char allow_replay;
extern char already_there;
extern char reselection;
extern float camera_dist;
extern float poss_mode;

/******************************************************************************
******************************************************************************/

// Team Players Data...

// Wall data...
extern float wallx,wally;
extern int men_in_wall;
struct wall {
	int guy;
	float x,y;
};

extern wall wguys[];
extern float keeper_pos_x,keeper_pos_y;

extern char in_range,in_header_rng,in_shot_rng;
extern int taker_x,taker_y;

extern char penalty_shot;
extern short penalties;
extern char penalty_game;
extern short home_pens_left;
extern short away_pens_left;
extern short penalty_counter;
extern short pen_taker_a;
extern short pen_taker_b;
extern char penalty_team;
extern int penalty_taker;
extern int penalty_taker_a;
extern int penalty_taker_b;

extern int player_num;
extern int centre_guy_1;
extern int centre_guy_2;

extern int setp_taker;
extern int fkick_taker;
extern int fkick_taker_a;
extern int fkick_taker_b;

extern int gkick_taker;
extern int goal_kicker_a;
extern int goal_kicker_b;

extern int corner_taker;
extern int corn_kicker_a;
extern int corn_kicker_b;
extern int ktaker;
extern int bad_guy;
extern char direct_fk;

extern char play_advantage;

extern char set_piece_on;

extern int throw_in_taker;
extern int main_man;

extern float opp_dir_tab[11][3];
extern int drib_opps;

struct bubbles{int say;int cnt;};
extern bubbles speech_tab[26];

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
	float tm_frm, tm_fstep;
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

extern match_player teams[22];

extern float x_face,y_face;
extern char stop_and_face;

struct officials {
	float x,y,z,dir_x,dir_y,anim,frm,fstep,goto_x,goto_y;
	int act,go;
	short target;
	char newanim;

};

extern officials refs[3];
extern char offside_now;
extern char can_be_offside;
extern char offside_on;

extern int ref_accuracy;
extern int ref_strictness;
extern int ref_wait;

extern int tussle_tab[];
extern int *tussle_ptr;


extern float cth,sth;			// Current viewing angle...
extern  volatile int NetTeams[MAX_NET_USERS],Players[MAX_NET_USERS];
extern  volatile char paused;
//extern  char keys[256];
//extern  char key_togs[256];

extern  unsigned int NetworkHandle;
extern  short wConsoleNode;
extern  int network_on;
extern  volatile int count;
extern  volatile int ftick;
extern  volatile int tick;
extern  volatile int TeamOveride;
extern  volatile int PlayerOveride;
