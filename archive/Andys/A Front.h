#include "fdefs.h"

//				DATA STRUCTURES TO BE SAVED

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
	int			crowd;
	int			pitch;
	int			commentary;
	int			music;
	int			master;

	short			timeit;											 	
	short			vidi;

	char			match_number;	 		// match/league week number.	  -1 = needs initialising.
	int			team_a_score;			// score for team_a
	int			team_b_score;			// score for team_b

	int			penalties;
	int 			extra;

	int			team_a_penalties;
	int			team_b_penalties;
	int			venue;
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

	int			CompetitionType;
	int			CompetitionType_toggle;
	int			NoOfPlayers;
	int			NoOfPlayers_toggle;
	int			GameType;
	int			GameType_toggle;

	int			CROWD;
	int			COMMENTRY;
	int			MASTER;
	int			PITCH;
	int			MUSIC;

	int			referee;
	int			match_referee;
	int			referee_vision;
	int			referee_discipline;

	char			control_methods[4];
	char			tga_enable;
	
	int			return_mins;
	int			rand;	
  	char			language;
											
            	}match_data;				



struct player_info
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

	char			flags;

	char			squad_number;
	char			position;	
	char			skin_tone;

};

struct referee_info
{
	char			name[PLAYER_NAME_LEN+1];
	int			vision;
	int			discipline;
	short 		country;
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



