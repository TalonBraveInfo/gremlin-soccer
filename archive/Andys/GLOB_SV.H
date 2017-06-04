/****************************************************************************
******************************************************************************/

// Team Players Data...

match_player teams[22];
mtime match_time;
officials refs[3];
bubbles speech_tab[26];
wall wguys[5];
user_vectors users_dir[MAX_NET_USERS];	// Declared in glob_var.h, as usual

// End of structs...

float setp_x;
float setp_y;

short setp_wait_cnt;
char fframe=FALSE;
char kick_off;
char sel_circle[22];
short burst_timer[5];
short keep_timer;
char stop_clock;
char keep_dive;

short hold_up_play;
char wall_is_up;
short card_is_out;

short int crowd_mood_a;
short int crowd_mood_b;

float possession;
float poss_held;

char arrow_on;

int logic_cnt;

char ball_move;

int first_bounce;
int swerve;
int spin_cnt;
int spin_ball;
int prediction;
int set_xyspin;
int set_zspin;
float ball_horz_ang;
float ball_vert_ang;

float max_sw_factor;
float swerve_factor;
char rebound_ball;
char headed_ball;
char say_names;
char fired_a_shot;
char comm_pass;
char comm_pass_type;

float keeper_spd;
short keeper_down;
int keeper_will_save;
char keeper_on_grnd;
float keeper_contact;
char ball_in_goal;
char ball_in_hands;
short game_action;
int throw_cnt;
int team_a_goals;
int team_b_goals;
char last_goal;
char scorer_running;
int just_scored;
int just_thrown;
int goal_scorer;
int pass_type;
int kick_type;
int receiver;
char cross_now;
char auto_select;
char must_face;
short must_face_time;
float must_face_x;
float must_face_y;
char must_shoot;
char chip_pass;
char must_pass;
char must_punt;
char keeper_a_in_box;
char keeper_b_in_box;
int keeper_steps;
short save_block;
float save_xoff;
float save_yoff;
float save_zoff;
float shot_speed;

int scr_x;
int scr_y;
int ball_speed;
int ball_int_speed;
int interceptor_a;
int interceptor_b;
int in_cross_area;
float close_in_number;

int shooter;
int ball_inair;
int super_shot;
int opponents_near_holder;
int opponents_really_close;
int ball_poss;
int sender_1_2;
int ball_still;
int last_touch;
int want_pass;
int before;
int support_me;
int pre_kp_touch;
int prev_touch;

int ball_limbo_p;
char ball_limbo_on;
float ball_limbo_c;

int ball_released;
int cannot_pick_up;
short forced;
short last_user_a;
short last_user_b;
short last_plr_a;
short last_plr_b;
short players_off_a;
short players_off_b;

int want_pass_stat;
int ball_zone1;
int ball_zone2;
int ball_out_of_play;

short receiver_a;
short receiver_b;

int ready_centre;
char shot_attempt;

char force_select;
short heading_ball;
char flag;

char rep_camera;
char sub_camera;
char allow_replay;

int replay_pos;
int old_rep_pos;
int replay_cnt;

int pitch_sprs;

short lp_user;
short fixed_net_user;
short auto_users_list_a[10];
short auto_users_a;
short auto_users_list_b[10];
short auto_users_b;
short play_ball_a;
short play_ball_b;
char new_select;
char auto_intercept;
char closest;

short f1_down;
short f2_down;

char spec_kick_type;
float setp_hgt;
float setp_power;
float setp_kick_x;
float setp_kick_y;
float setp_bxd;
float setp_byd;
float setp_bzd;

short user_taker;
short user_taker2;

char user_controlled;
char user_plr;
char after_touch_on;
char drive_shot;
char newk_shot;

// Set Piece Stuff...

// Wall data...
float wallx;
float wally;
int men_in_wall;

float keeper_pos_x;
float keeper_pos_y;

int centre_guy_1;
int centre_guy_2;

char in_range;
char in_header_rng;
char in_shot_rng;
int taker_x;
int taker_y;

char penalty_shot;
short penalties;
char penalty_game;
short home_pens_left;
short away_pens_left;
short penalty_counter;
short pen_taker_a;
short pen_taker_b;
char penalty_team;
int penalty_taker;
int penalty_taker_a;
int penalty_taker_b;

int setp_taker;
int fkick_taker;
int fkick_taker_a;
int fkick_taker_b;

int gkick_taker;
int goal_kicker_a;
int goal_kicker_b;

int corner_taker;
int corn_kicker_a;
int corn_kicker_b;
int ktaker;
int bad_guy;
char direct_fk;

char play_advantage;

char set_piece_on;

int throw_in_taker;
int main_man;

int player_num;
int savex;
int savey;
int savez;
char shot_acknowledged;
int shot_pending;
int real_shot;

short shot_missed;
short shot_saved;

float opp_dir_tab[11][3];
int drib_opps;


char stop_and_face;
float x_face;
float y_face;

char offside_now;
char can_be_offside;

int ref_accuracy;
int ref_strictness;
int ref_wait;

int tussle_tab[23];
int *tussle_ptr;


// Sound Fx. flags etc...

// Sample Data... 

char *Sample[32];

int crowd_a;
int crowd_b;

char kickoff;

char end_game;
char team_a;
char team_b;
char last_centre;
char need_result;
short injury_time;

char special_move;
char match_half;

// General Control variables...

short opt_user;
short opt_team;
char options_on;
short line_up;
short player_being_subbed;
short player_on_off;
short player_coming_on;
char booking;
short subbing_now;
char first_update;

// Ball fx.

float newdx;
float newdy;

short wind_on;
short wind_d_trend;
short wind_s_trend;
float wind_x;
float wind_y;
float wind_speed;
float init_wind_x;
float init_wind_y;
float init_wind_speed;
float wind_var_ang;

char tactics_a;
char tactics_b;
char old_tac_a;
char old_tac_b;

/******************************************************************************
******************************************************************************/

// Randomize variables...

short rand1_tab[5];
short rand2_tab[6];

short *afr1;
short *afr2;

char andys_random;

// Global Match Variables...

// Man to man marking table....

int man2man[10][2];
char man2man_a;
char man2man_b;

short next_mins;
int time_factor;
char clock_running;

char demo_match;

char arrow_guy;

short rand_seed;
short seed;
float man_down;

int match_tactics1[32*2+6][10][2];
int match_tactics2[32*2+6][10][2];

int launch_type;
float launch_x;
float launch_y;
float	ballxdis;
float ballydis;
float ballzdis;
float ballx;
float bally;
float ballz;
float ballx_out;
float bally_out;
float ballz_out;
float b_xoff;
float b_yoff;
float b_zoff;
float save_ballx;
float save_bally;
float save_ballz;
int save_ball_poss;
short good_poss;

float eff_ballx;
float eff_bally;
float eff_ballz;
float prev_ballx;
float prev_bally;
float prev_ballz;
float ns_ballx;
float ns_bally;
float ns_ballz;
float ball_zspin;
float ball_xyspin;
float full_zspin;
float full_xyspin;
float shoot_x;
float shoot_y;

int nearest_a;
int nearest_b;
int old_ltouch;
int old_ball_poss;
char use_ball_limit;
short near_path_a;
short near_path_b;
int zone1_x;
int zone1_y;
int zone2_x;
int zone2_y;
int incident_x;
int incident_y;
int difficulty;
char match_mode;
char last_match_mode;
int dead_ball_cnt;
int defense_a;
int defense_b;

float poss_mode;

float ball_pred_tab[50][3];
float ns_ball_pred_tab[50][3];

// User Interface...

short ball_travel;
short select_cnt;

char already_there;
char reselection;


char offside_on;
