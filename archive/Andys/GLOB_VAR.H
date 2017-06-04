/****************************************************************************
******************************************************************************/

char check_str[8];
char not_ahead;

float deb_data;

// Randomize variables...

short rand1_setup[]={0x5a79,0x12fa,0x3abc,0x21e3,0};
short rand2_setup[]={0xafaf,0x0123,0x4567,0x19ab,0xcdef,0};

extern char old_mf;
extern char sub_pending;

short new_text;
char *text_mess;

short cam_array[7]={8,0,1,2,14,4,7};

// Timing Vars...

short comsetp;

short updates=0;
int old_count=0;

intercept_data strike[11];

char first_time_it=FALSE;

int seconds=0;

// Capture timing vars...

float ft_ktm,ft_vtm,ft_dtm,ft_otm,ft_stm,ft_jtm,ft_ttm,ft_ctm,ft_utm;

extern unsigned char machine_no;

// Global Constants

short replay_seconds;
//char debug;

/*
butts us_buttons[]={{320-52,200-16,6,"EDITOR",0},{224,184,4,"GRID",0},
						  {320-44,200-36,1,"+",0},{320-24,200-36,1,"-",0},
						  {320-76,200-36,2,"NO",0},{320-24,200-64,1,">",0},
						  {320-24-24,200-64,1,"<",0},{320-48-24,200-64,1,"T",0},
						  {320-48-48,200-64,1,"B",0},{200-4,184,2,"3D",0}};

int max_butts=(sizeof(us_buttons)/sizeof(butts));
*/

// Pixel Colours.

char ball_col=7;
char shadow_col=1;
char team_a_col=3;
char team_b_col=4;

// Pitch sizes and environmental constants.
float bounce_dis=2.2;
float gravity=0.5;
int cntspot_x=80*16/2;
int cntspot_y=50*16/2;

float ball_diam=4.0;
int pitch_len=80*16, pitch_wid=50*16;
int halfway_line=40*16, scr_pinch=48;
int right_bounds=85*16;
int left_bounds=-5*16;
int lower_bounds=55*16;
int upper_bounds=-5*16;
float zone_wid=pitch_len/7;
float zone_hgt=pitch_wid/3;
float prat=(50.0*16/75);
int goal_height=(34);			//8 feet
int goal_depth=(28);				//8 feet
int post_width=2;					//5 inches approx.
int top_post_y=cntspot_y-(prat*4);
int bot_post_y=cntspot_y+(prat*4);

short var_start;
#include "glob_sv.h"
short var_end;

// Players.

int players=22;

int avg1_rate=78,avg1_power=74,avg1_bcontrol=84,avg1_flair=84,
		avg1_vision=74,avg1_accuracy=74,avg1_fitness=74,avg1_disc=74;

int avg2_rate=70,avg2_power=74,avg2_bcontrol=94,avg2_flair=74,
 		avg2_vision=74,avg2_accuracy=74,avg2_fitness=74,avg2_disc=74;

/******************************************************************************
******************************************************************************/

// Major control variables...

char audio_version=FALSE;
char vidi_wall_on=FALSE;

float MF;
float mf_scale;
float omf_scale;
float log_factor;
char mf_fixed;
char alarm,watch;
int stop_min;
int stop_sec;
char practice;
char team_a_on;
char team_b_on;

float camera_dist=250;

volatile char in_game = true;
char analogue=1;
char camera=9;
char old_cam=9;

char tweening=TRUE;
float zoom=200;

/******************************************************************************
******************************************************************************/

// Screen Buffer Stuff...
//int scr_a[100][4];
//int scr_b[100][4];
//int plot_cnta=1;
//int plot_cntb=1;
//int plot_buffer=0;


//int button_lit=0;
int delay_cnt=40;
int play_nums_on=0;

int oldcnt;
int frames=0;
int frms_per_sec=0;
int last_second=0;

//char *action;
int old_clock;

char on_3d=TRUE;

#pragma pack (1)

//extern volatile user_config users[MAX_NET_USERS];	// Declared in network.c


extern volatile user_vectors_i users_dir_i[512][MAX_NET_USERS];	// Declared in network.c

extern volatile int writeptr;
extern volatile int readptr;

extern int num_of_users;	// Currently in network.c



//////////////////
// Input devices
//////////////////

float ux,uy;		// User x,y,f1,f2,move
char uf1,uf2;
char um;

// Joysticks & keyboard, taken to network.c

//extern  signed char key1[6];
//extern  signed char key2[6];

//extern  unsigned short lp_cnt_x,lp_cnt_y;
//extern  unsigned short joy1_cnt_x,joy1_cnt_y;
//extern  unsigned short joy2_cnt_x,joy2_cnt_y;

//extern  int joy1_max_x,joy1_max_y,joy1_min_x,joy1_min_y;
//extern  int joy2_max_x,joy2_max_y,joy2_min_x,joy2_min_y;

//extern  volatile int joy1_x;
//extern  volatile int joy1_y;
//extern  volatile int joy1_fire;

//extern  volatile int joy2_x;
//extern  volatile int joy2_y;
//extern  volatile int joy2_fire;

//extern  volatile char joy1_move;
//extern  volatile char joy2_move;

//extern  char logpad_on;
//extern  char joystick1_on;
//extern  char joystick2_on;

//extern  char digital_joy1;
//extern  char digital_joy2;

/******************************************************************************
******************************************************************************/
