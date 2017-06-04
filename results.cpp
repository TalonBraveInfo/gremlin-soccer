#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "euro_def.h"

#include "defines.h"
#include "3deng.h"
#include "video.h"
#include "menu.h"
#include "control.h"
#include "unmangle.h"
#include "gamedata.h"
#include <math.h>

extern int SelectedLEAGUEteam;

void swapteamsPOSN();

void randomize();

void initialise_matches();

void CheckEndOfLine();

int calculate_player_skill(int team_no, int position, int pitch_pos);

void attemptGOAL(int team_a, int team_b, int time);

extern void GOAL_SCORED(int team, int scorer, int time);

void reset_scores();

char *FindGOALSCORERSname(char credit, int player);

void choose_cup_games();

extern int formdata;
int rand_seed, seed;
int TEAMa, TEAMb;
extern int Button_pressed;
extern char OverlayFlag;
extern int formation_toggle;
extern int selected_team;
extern short TabX, lineY;
extern int current_menu;

void get_cup_venue();

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Resets teams division and position numbers when game is restarted.                                                          �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
void reset_league_teams() {
}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Sets up next fixture.                                                                                                       �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
int SortNEXTfixture(int match_number, int CompType) {
    return (match_number);
}


//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Calculates neutral referee for network game.                                                                                �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
void recalc_referee() {
}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Initialises league program.                                                                                                 �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
void initialise_matches() {
}


//������������������������������������������������������������������������������������������������������������������������������ͻ
//�                                                                                                                              �
//�  Choose cup fixtures.                                                                                                        �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
void choose_cup_games() {
}


//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  User pressed ESC while in match, we must now generate a result against the user.                                            �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
void quit_current_match() {
}


//������������������������������������������������������������������������������������������������������������������������������ͻ
//�                                                                                                                              �
//�  Calculates the result of a game between any two teams.                                                                      �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
void calculate_match() {
}


//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Sets up goal data after a goal has been scored, for later use when displaying scorers.                                      �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
//void	GOAL_SCORED( int team, int scorer, int time )
//{
//	int	goal_slot	=	-1;
//	int	goal_count	=	0;
//
//		// FIND AN EMPTY GOAL SLOT WITHIN GOAL DATA...
//
//		while	( goal_slot==-1 )
//		{
//					
//			if ( goals[goal_count].goal_data.used == NULL )
//			{
//			 	goal_slot				=	goal_count;
//				goals[goal_slot].goal_data.used		=	ACTIVE;				
//			}
//		     	
//			else
//		
//			{
//			goal_count++;
//			
//				if ( goal_count>90 )
//				{
//					goals[0].goal_data.used	=	NULL;
//					goal_count		=	0;
//				}
//			}			
//		}
//
//
//	goals[goal_slot].goal_data.time		=	time+1;				
//
//		// CALCULATE NORMAL GOAL....
//
//
//		if	( (time & O_G)==0 )
//		{
//			
//			if ( scorer<11 )
//			{
//				goals[goal_slot].goal_data.scorer	=	game_data[setup.team_a].players[scorer].squad_number;	//was scorer-1
//				goals[goal_slot].goal_data.used|=		CREDIT_TEAMa;
//				match_info.team_a_score++;
//			}
//			else
//			{
//				goals[goal_slot].goal_data.scorer	=	game_data[setup.team_b].players[scorer-11].squad_number;   //was scorer-12
//				goals[goal_slot].goal_data.used|=		CREDIT_TEAMb;
//				match_info.team_b_score++;
//			}
//		}
//
//
//		// CALCULATE OWN GOAL....
//
//		if	( (time & O_G)!=0 )
//		{
//
//		goals[goal_slot].goal_data.used		=	O_G >> 8;				
//
//			if ( scorer<11 )     
//			{
//				goals[goal_slot].goal_data.scorer	=	game_data[setup.team_a].players[scorer].squad_number;	     //was scorer-1
//				goals[goal_slot].goal_data.used|=		CREDIT_TEAMb;
//				match_info.team_b_score++;
//			}
//
//			else
//			{
//				goals[goal_slot].goal_data.scorer	=	game_data[setup.team_b].players[scorer-11].squad_number;     //was scorer-12
//				goals[goal_slot].goal_data.used|=		CREDIT_TEAMa;
//				match_info.team_a_score++;
//			}
//		}
//}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Calculates a players skill, depending on his stats and chosen position of play on field.                                    �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
int calculate_player_skill(int team_no, int position, int pitch_posn) {
    switch (pitch_posn) {
        case (GK):
            return (
                    game_data[team_no].players[position].accuracy +
                    (game_data[team_no].players[position].control / 2) +
                    (game_data[team_no].players[position].pace / 2) +
                    (game_data[team_no].players[position].power / 4) +
                    ((100 - game_data[team_no].players[position].discipline) / 4) +
                    (game_data[team_no].players[position].vision / 4));

        case (DF):
            return (
                    game_data[team_no].players[position].power +
                    ((100 - game_data[team_no].players[position].discipline) / 2) +
                    (game_data[team_no].players[position].pace / 2) +
                    (game_data[team_no].players[position].flair / 4) +
                    (game_data[team_no].players[position].stamina / 4) +
                    (game_data[team_no].players[position].vision / 4));

        case (MD):
            return (
                    game_data[team_no].players[position].flair +
                    (game_data[team_no].players[position].control / 2) +
                    (game_data[team_no].players[position].pace / 2) +
                    (game_data[team_no].players[position].vision / 4) +
                    (game_data[team_no].players[position].stamina / 4) +
                    (game_data[team_no].players[position].accuracy / 4));

        case (FD):
            return (
                    game_data[team_no].players[position].pace +
                    (game_data[team_no].players[position].accuracy / 2) +
                    (game_data[team_no].players[position].flair / 2) +
                    (game_data[team_no].players[position].control / 4) +
                    (game_data[team_no].players[position].stamina / 4) +
                    (game_data[team_no].players[position].power / 4));

        default:
            return 0;
    }
}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Reset table holding data for goals and scorers.                                                                             �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
void reset_scores() {
    // RESET BOTH TEAMS SCORES...

    match_info.team_a_score = match_info.team_b_score = 0;

    // RESET TABLE HOLDING SCORERS...

    for (int table = 0; table < 91; table++) {
        goals[table].goal_data.used = 0;
        goals[table].goal_data.time = goals[table].goal_data.scorer = 0;
    }
}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Display goal scorers for both teams.                                                                                        �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//

void DisplayGOALscorers(char credit, int teams_goals) {
}




//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Checks for end of line and bottom bounding area when displaying scorers.                                                    �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//

void CheckEndOfLine() {
#ifdef IMPLEMENT_ME
    if (TextXposn > (TabX+170) )
    {
        TextYposn+=	24;
        lineY++;
        TextXposn=	TabX;
    }
#endif
}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Look for name of goal scorer using both players squad number and the team to whom the goal is credited.                     �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
char *FindGOALSCORERSname(char credit, int player) {
    int team;
    int array_number = 0;

    if (credit == CREDIT_TEAMa)
        team = setup.team_a;
    else
        team = setup.team_b;

    for (int playnum = 0; playnum < 22; playnum++) {
        if (game_data[team].players[playnum].squad_number == player)
            array_number = playnum;
    }

    return (game_data[team].players[array_number].name + game_data[team].players[array_number].goal_index);
}


//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Control relegation and promotion stuff.                                                                                     �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
void SortNEWdivisions() {
#ifdef IMPLEMENT_ME
    int	team1,team2,team3,team4,team5,team6,team7,team8,team9,team10;

    for (int nametm = 0; nametm < MAX_TEAMS-1; nametm++)
    {
        int	check	=	(game_data[nametm].division*16)+game_data[nametm].position;

        if ( check == ((DIV1*16)+POS13) )
            team1	=	nametm;
        if ( check == ((DIV1*16)+POS14) )
            team2	=	nametm;

        if ( check == ((DIV2*16)+POS14) )
            team3	=	nametm;
        if ( check == ((DIV2*16)+POS15) )
            team4	=	nametm;
        if ( check == ((DIV2*16)+POS16) )
            team5	=	nametm;

        if ( check == ((DIV2*16)+POS01) )
            team6	=	nametm;
        if ( check == ((DIV2*16)+POS02) )
            team7	=	nametm;

        if ( check == ((DIV3*16)+POS01) )
            team8	=	nametm;
        if ( check == ((DIV3*16)+POS02) )
            team9	=	nametm;
        if ( check == ((DIV3*16)+POS03) )
            team10	=	nametm;
    }
    game_data[team1].division	=	DIV2;
    game_data[team1].position	=	POS01;
    game_data[team2].division	=	DIV2;
    game_data[team2].position	=	POS02;

    game_data[team3].division	=	DIV3;
    game_data[team3].position	=	POS01;
    game_data[team4].division	=	DIV3;
    game_data[team4].position	=	POS02;
    game_data[team5].division	=	DIV3;
    game_data[team5].position	=	POS03;

    game_data[team6].division	=	DIV1;
    game_data[team6].position	=	POS13;
    game_data[team7].division	=	DIV1;
    game_data[team7].position	=	POS14;

    game_data[team8].division	=	DIV2;
    game_data[team8].position	=	POS14;
    game_data[team9].division	=	DIV2;
    game_data[team9].position	=	POS15;
    game_data[team10].division	=	DIV2;
    game_data[team10].position	=	POS16;
#endif
}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Selects squad for computer controlled team.                                                                                 �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//
void SortSQUAD(int team) {
#ifdef IMPLEMENT_ME
    if (match_info.CompetitionType == NETWORK) {
        for (int player = 0; player < 11 + 4; player++) {
            if (game_data[team].players[player].squad_number != player) {
                for (int search = 0; search < 22; search++) {
                    if (game_data[team].players[search].squad_number == player)
                        swap_players(search, player);
                }
            }
        }
    } else {
        int old_select = selected_team;
        selected_team = team;
        int pitch_posn;
        int player_skill;

        // ** GET DEFAULT FORMATION FOR TEAM ***

        int team_formation = game_data[team].computer_formation;

        // ** SETUP FORMATION TYPE WITHIN ACTUAL GAME DATA ***

        formation_toggle = team_formation;
        game_data[team].formation = team_formation;


        for (int times = 0; times < 2; times++) {

            // ** LOOP THROUGH FIRST ELEVEN PLAYERS TO FIND BEST PLAYERS TO FILL POSITIONS ***

            for (int player = 0; player < 11; player++) {

                // ** GET IDEAL PITCH POSITION FOR PLAYER DEPENDING ON DEFAULT TEAM FORMATION ***

                pitch_posn = formation_data[team_formation].formations[player].position_type;

                // ** IF PLAYER IS OUT OF POSITION THEN FIND BETTER POSITIONED PLAYER ***

                if (game_data[team].players[player].position != pitch_posn) {
                    int better_flag = FALSE;
                    int better_plyr = player + 1;

                    while (better_flag != TRUE) {
                        if (game_data[team].players[better_plyr].position == pitch_posn) {
                            swap_players(better_plyr, player);
                            better_flag = TRUE;
                        }

                        if (game_data[team].players[better_plyr].position != pitch_posn) {
                            better_plyr++;
                            if (better_plyr > 21)
                                better_flag = TRUE;
                        }
                    }

                }


                // ** NOW SEE IF A HIGHER SKILLED PLAYER IS AVAILABLE ***

                player_skill = calculate_player_skill(team, player, pitch_posn);

                for (int skillfull = player + 1; skillfull < 22; skillfull++) {
                    if (game_data[team].players[skillfull].position == pitch_posn &&
                        player_skill < calculate_player_skill(team, skillfull, pitch_posn)) {
                        swap_players(skillfull, player);
                    }
                }
            }
        }
        selected_team = old_select;
    }
#endif
}



//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Determins if user has selected arcade and auto game is required.                                                            �
//�																 �
//������������������������������������������������������������������������������������������������������������������������������ͼ 
//

void SortARCADEleagueGAME() {
}


