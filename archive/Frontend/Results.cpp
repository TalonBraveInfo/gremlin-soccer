#include "Frontend Vars.h"
#include "Results.h"

#undef EXTERN
#define EXTERN extern
#include "Memory.h"
#include "Front Menu.h"
#include "Menudisp.h"
#include "Not Written Yet.h"
#include "Results.h"
#include "Unmangle.h"
#include "Front Variables.h"

extern void GOAL_SCORED(int a,int b, int c);

static short		TabX;
static short		lineY;

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Display league table data for a given team.                                                                                 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	DisplayLEAGUEdata(int TextFLAGS)
{
	char			NumberBUFFER[5];

	TextXposn	=	PLAYEDxPOS;
	TextCOLOUR	=	BRIGHT_YELLOW;
	itoa	( game_data[SelectedLEAGUEteam].played ,NumberBUFFER,10);			
	DisplaySTRING( NumberBUFFER, TextFLAGS);

	TextXposn	=	WONxPOS;
	itoa	( game_data[SelectedLEAGUEteam].won ,NumberBUFFER,10);			
	DisplaySTRING( NumberBUFFER, TextFLAGS);

	TextXposn	=	DREWxPOS;
	itoa	( game_data[SelectedLEAGUEteam].drew ,NumberBUFFER,10);			
	DisplaySTRING( NumberBUFFER, TextFLAGS);

	TextXposn	=	LOSTxPOS;
	itoa	( game_data[SelectedLEAGUEteam].lost ,NumberBUFFER,10);			
	DisplaySTRING( NumberBUFFER, TextFLAGS);

	TextXposn	=	FORxPOS;
	itoa	( game_data[SelectedLEAGUEteam].goals_for ,NumberBUFFER,10);			
	DisplaySTRING( NumberBUFFER, TextFLAGS);

	TextXposn	=	AGAINSTxPOS;
	itoa	( game_data[SelectedLEAGUEteam].goals_against ,NumberBUFFER,10);			
	DisplaySTRING( NumberBUFFER, TextFLAGS);

	TextXposn	=	PTSxPOS;
	itoa	( game_data[SelectedLEAGUEteam].points ,NumberBUFFER,10);			
	DisplaySTRING( NumberBUFFER, TextFLAGS);

	TextXposn	=	GOALdiffxPOS;
	itoa	( game_data[SelectedLEAGUEteam].goal_diff ,NumberBUFFER,10);			
	
	if 	( game_data[SelectedLEAGUEteam].goal_diff > -1)
		DisplaySTRING( "+", TextFLAGS);

	DisplaySTRING( NumberBUFFER, TextFLAGS);

}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Sort through team data calculating points and goal difference values.	                                                 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	DoLEAGUEtables()
{

	for (TEAMa = 0; TEAMa < MAX_TEAMS-1; TEAMa++)
	{
		game_data[TEAMa].points	= (batch_info.PointsForWin * game_data[TEAMa].won) + game_data[TEAMa].drew;
		game_data[TEAMa].goal_diff = (game_data[TEAMa].goals_for - game_data[TEAMa].goals_against);
	}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Recalculate league tables.	All three calculated in one go!!!!                                                               บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
	int	swap;

	for (int scans = 0; scans < MAX_TEAMS-1; scans++)
	{

		for (TEAMa = 0; TEAMa < MAX_TEAMS-1; TEAMa++)
		{
			for (TEAMb = 0; TEAMb < MAX_TEAMS-1; TEAMb++)
			{
				if (TEAMa != TEAMb)
				{

					if (game_data[TEAMa].division == game_data[TEAMb].division)
		     			{

						swap	= FALSE;
					
						if (game_data[TEAMa].points < game_data[TEAMb].points
						    && game_data[TEAMa].position < game_data[TEAMb].position)
							swap	= TRUE;
					
						if (game_data[TEAMa].points == game_data[TEAMb].points
						    && game_data[TEAMa].goal_diff < game_data[TEAMb].goal_diff
						     && game_data[TEAMa].position < game_data[TEAMb].position)
							swap	= TRUE;

						if (game_data[TEAMa].points == game_data[TEAMb].points
						    && game_data[TEAMa].goal_diff == game_data[TEAMb].goal_diff
						     && game_data[TEAMa].won < game_data[TEAMb].won
						      && game_data[TEAMa].position < game_data[TEAMb].position)
							swap	= TRUE;

						if ( game_data[TEAMa].points == game_data[TEAMb].points
						    && game_data[TEAMa].goal_diff == game_data[TEAMb].goal_diff
						     && game_data[TEAMa].won < game_data[TEAMb].won
						      && game_data[TEAMa].position < game_data[TEAMb].position)
							swap	= TRUE;

						if (swap==TRUE)
							swapteamsPOSN();
					}
				}		   
			}
		}

	}
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Swap team A's league position with that of team B's.                                                                        บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	swapteamsPOSN()
{
	int	flag			=	game_data[TEAMa].position;
	game_data[TEAMa].position	=	game_data[TEAMb].position;
	game_data[TEAMb].position	=	flag;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Resets teams division and position numbers when game is restarted.                                                          บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	reset_league_teams()
{
	for (int teamnum=0; teamnum < MAX_TEAMS-1; teamnum++)
		{ 
		game_data[teamnum].division	=	restore_league_data[teamnum].division;
		game_data[teamnum].position	=	restore_league_data[teamnum].position;
		}

	menu_data[MENU_A11].ButtonLIST[0].button_left_select	=	DONE_LEAGUE_DISPLAY;
//	menu_data[MENU_A11].ButtonLIST[0].button_right_select	=	DONE_LEAGUE_DISPLAY;
	menu_data[MENU_A12].ButtonLIST[0].button_left_select	=	DONE_LEAGUE_DISPLAY;
//	menu_data[MENU_A12].ButtonLIST[0].button_right_select	=	DONE_LEAGUE_DISPLAY;
	menu_data[MENU_A13].ButtonLIST[0].button_left_select	=	DONE_LEAGUE_DISPLAY;
//	menu_data[MENU_A13].ButtonLIST[0].button_right_select	=	DONE_LEAGUE_DISPLAY;
	menu_data[MENU_A22].ButtonLIST[0].button_left_select	=	DONE_ROUNDUP; 
//	menu_data[MENU_A22].ButtonLIST[0].button_right_select	=	DONE_ROUNDUP;

	batch_info.match_number=-1;

}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Sets up next fixture.                                                                                                       บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
int	SortNEXTfixture(int match_number, int CompType)
{

	if ( match_number==-1 && (CompType==FRIENDLY || CompType==PRACTICE) )
	{
		reset_scores();
	}


	
	if ( match_number==-1 && CompType==LEAGUE)	// LEAGUE COMPETITION
	{
		initialise_matches();

		for (int teamnum=0; teamnum < MAX_TEAMS-1; teamnum++)
		{ game_data[teamnum].fixture_no = (game_data[teamnum].division*16)+game_data[teamnum].position;	}

		for (int roundup=0; roundup < 650; roundup++)
		{
				results[roundup].result_data.team_a_score	=	255;	 
				results[roundup].result_data.team_b_score	=	255;	 
			      	results[roundup].result_data.extra		=	NULL;
			      	results[roundup].result_data.penalties		=	NULL;
				results[roundup].result_data.team_a_penalties	=	NULL;	 
				results[roundup].result_data.team_b_penalties	=	NULL;	 

			for (int teamnum=0; teamnum < MAX_TEAMS-1; teamnum++)
			{
				if ( game_data[teamnum].fixture_no == fixtures[roundup].fixture_data.home_team )
					results[roundup].result_data.team_a	=	game_data[teamnum].team_number;

				if ( game_data[teamnum].fixture_no == fixtures[roundup].fixture_data.away_team )
					results[roundup].result_data.team_b	=	game_data[teamnum].team_number;
			}
	    	}

		if( Language==English ||  Language==French)
			menu_data[MENU_A22].ImageLIST[5]	=	IMG97;
		else
			menu_data[MENU_A22].ImageLIST[5]	=	NULL;
		match_number	=	0;
	}


	if ( match_number==-1 && CompType==NETWORK )	// NETWORK GAME...
	{
		setup.team_a	=	0;
		setup.team_b	=	1;
		reset_scores();
		match_number	=	0;
	}


	if ( match_number==-1 && CompType==CUP )	// CUP COMPETITION...
	{

			for (int stringnum = 0; stringnum < MAX_TEAMS-1; stringnum++)
			{
					game_data[stringnum].cup_key =	NULL;
			      	if ( (menu_data[MENU_A3].StringLIST[stringnum].string_flags & TOGGLE_FLAG)!=0)
					game_data[stringnum].cup_key =	-1;	

			}


		batch_info.Round_counter	=	batch_info.number_of_cup_teams;
	      	choose_cup_games();

		match_number	=	0;
		if( Language==English ||  Language==French)
			menu_data[MENU_A22].ImageLIST[5]	=	IMG96;
		else
			menu_data[MENU_A22].ImageLIST[5]	=	NULL;
		
		batch_info.cup_tie		=	0;

			if ( batch_info.number_of_cup_teams == 32 )
			{
				batch_info.Round_index	=	0;
				batch_info.RoundPrint	=	7;
			}
			if ( batch_info.number_of_cup_teams == 16 )
			{
				batch_info.Round_index	=	5;
				batch_info.RoundPrint	=	7;
			}
			if ( batch_info.number_of_cup_teams == 8 )
			{
				batch_info.Round_index	=	6;
				batch_info.RoundPrint	=	7;
			}
			if ( batch_info.number_of_cup_teams == 4 )
			{
				batch_info.Round_index	=	7;
				batch_info.RoundPrint	=	3;
			}
				batch_info.cup_match_number=	0;

		for (int roundup=0; roundup < 650; roundup++)
		{
				results[roundup].result_data.team_a_score	=	255;	 
				results[roundup].result_data.team_b_score	=	255;	 
			      	results[roundup].result_data.team_a		=	NULL;
			      	results[roundup].result_data.team_b		=	NULL;
			      	results[roundup].result_data.extra		=	NULL;
			      	results[roundup].result_data.penalties		=	NULL;
				results[roundup].result_data.team_a_penalties	=	NULL;	 
				results[roundup].result_data.team_b_penalties	=	NULL;	 
	    	}

	}

	if ( CompType==LEAGUE )
	{
		for (int teamnum=0; teamnum < MAX_TEAMS-1; teamnum++)
		{
			if ( game_data[teamnum].fixture_no == fixtures[match_number].fixture_data.home_team )
				setup.team_a	=	game_data[teamnum].team_number;
			if ( game_data[teamnum].fixture_no == fixtures[match_number].fixture_data.away_team )
				setup.team_b	=	game_data[teamnum].team_number;
	    	}

		match_info.venue	=	setup.team_a;

		if ( (signed char)fixtures[match_number].fixture_data.home_team==-1 )
			match_number	=	-1;
	}






	if ( CompType==CUP )
	{
		if (batch_info.Round_counter!=2)
		{		

			if	( (cup_games[batch_info.cup_tie]==-1) || (cup_games[batch_info.cup_tie+1]==-1) )
			{
				batch_info.Round_counter	=	batch_info.Round_counter/2;
			      	choose_cup_games();
				batch_info.Round_index++;
				batch_info.cup_tie		=	0;

					batch_info.RoundPrint	=	-1;
				if (batch_info.Round_counter==16)
					batch_info.RoundPrint	=	7;
				if (batch_info.Round_counter==8)
					batch_info.RoundPrint	=	7;
				if (batch_info.Round_counter==4)
					batch_info.RoundPrint	=	3;
				if (batch_info.Round_counter==2)
					batch_info.RoundPrint	=	1;
			}

		match_info.penalties	=	NULL;
		match_info.extra 	=	NULL;
		reset_scores();
		batch_info.cup_team_a 	=	cup_games[batch_info.cup_tie];
		batch_info.cup_team_b 	=	cup_games[batch_info.cup_tie+1];
		OverlayFlag		=	-1;
		}

		else
			match_number	=	-1;

		get_cup_venue();
	}


	return	(match_number);
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Calculates neutral referee for network game.                                                                                บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	recalc_referee()
{
	int	legal_referee	=	FALSE;

	if (match_info.CompetitionType==NETWORK)
	{
		match_info.match_referee = ( ((setup.team_a+1)*MAX_TEAMS) + setup.team_b) & 15+16;

	 	while	( legal_referee==FALSE )
		{	
			if  ( referee_data[match_info.match_referee].country != setup.team_a &&
		              referee_data[match_info.match_referee].country != setup.team_b )
				legal_referee	=	TRUE;
			else				
			{
				match_info.match_referee++;
			 	match_info.match_referee&= 15+16;
			}
		}
	}

	else

	{
	 	while	( legal_referee==FALSE )
		{	
		    if (match_info.referee<16+16)
		    {
				match_info.match_referee = match_info.referee;
				legal_referee	=	TRUE;
		    }
			else
		    {
			match_info.match_referee = Random_RS() & 16+15;
			if  ( referee_data[match_info.match_referee].country != setup.team_a &&
		              referee_data[match_info.match_referee].country != setup.team_b )
				legal_referee	=	TRUE;
		    }   					

		}
	}

	match_info.referee_vision	=	referee_data[match_info.match_referee].vision;	
	match_info.referee_discipline	=	referee_data[match_info.match_referee].discipline;	
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Initialises league program.                                                                                                 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void initialise_matches()
{
	for (TEAMa = 0; TEAMa < MAX_TEAMS-1; TEAMa++)
	{
		 if ( game_data[TEAMa].division == DIV1)
			game_data[TEAMa].team_no = game_data[TEAMa].position;
		 if ( game_data[TEAMa].division == DIV2)
			game_data[TEAMa].team_no = game_data[TEAMa].position+14;
		 if ( game_data[TEAMa].division == DIV3)
			game_data[TEAMa].team_no = game_data[TEAMa].position+14+16;

		game_data[TEAMa].played		= 	0;
		game_data[TEAMa].won		= 	0;
		game_data[TEAMa].drew		= 	0;
		game_data[TEAMa].lost		= 	0;
		game_data[TEAMa].goals_for	= 	0;
		game_data[TEAMa].goals_against	= 	0;
		game_data[TEAMa].points		= 	0;
		game_data[TEAMa].goal_diff	= 	0;

	}
}



//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Choose cup fixtures.                                                                                                        บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void choose_cup_games()
{

		int	team_to_go;
		team_to_go	=	0;

			for (int matchnum = 0; matchnum < 1000; matchnum++)
			{
				int	team_try	=	Random_RS() & 63;

 				if ( (game_data[team_try].cup_key!=NULL) && (team_try < MAX_TEAMS) )
				{
					cup_games[team_to_go]		=	team_try;
					game_data[team_try].cup_key	=	NULL;
					team_to_go++;					
				}
			}

			if (team_to_go!=batch_info.Round_counter)
			{
				for (int stringnum = 0; stringnum < MAX_TEAMS-1; stringnum++)
			
	 				if ( (game_data[stringnum].cup_key!=NULL))
				{
					cup_games[team_to_go]		=	stringnum;
					game_data[stringnum].cup_key	=	NULL;
					team_to_go++;					
				}
			}

	   	cup_games[team_to_go]	=	-1;
	   	cup_games[team_to_go+1]	=	-1;
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  User pressed ESC while in match, we must now generate a result against the user.                                            บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	quit_current_match()
{
	int	match_result, goes, attacker, whos_to_win;
	match_result		=	FALSE;
	goes			=	match_info.return_mins;



	if (game_data[setup.team_a].player_control==NULL)
		whos_to_win	=	0;
	else		
		whos_to_win	=	1;


	if (game_data[setup.team_a].player_control!=NULL && game_data[setup.team_b].player_control!=NULL
		 && match_info.return_mins!=-1 )
		{
			if   (match_info.team_a_score==match_info.team_b_score)
				{
					match_info.penalties	=	1;
					match_info.extra	=	1;
			       		match_info.team_a_penalties = Random_RS() & 3;	
			       		match_info.team_b_penalties = Random_RS() & 3;	

			 		while	( match_info.team_a_penalties==match_info.team_b_penalties )
					{	
						if ( (Random_RS()&1) == 0 )
			       			   match_info.team_a_penalties++;	
						else
			       			   match_info.team_b_penalties++;	
					}
				}
			match_result	=	TRUE;
		}


	if ( match_info.CompetitionType==FRIENDLY || 
             match_info.CompetitionType==NETWORK || 
             match_info.CompetitionType==PRACTICE )
			match_result	=	TRUE;

	else								// addition
		{
			if ( match_info.extra==NULL && match_info.penalties==NULL && goes>88 && 
				(match_info.team_a_score!=match_info.team_b_score) )
					match_result	=	TRUE;
			if ( match_info.extra!=NULL && match_info.penalties==NULL && goes>118 && 
				(match_info.team_a_score!=match_info.team_b_score) )
					match_result	=	TRUE;
		}






	if ( (match_info.CompetitionType==LEAGUE || match_info.CompetitionType==CUP) && match_info.return_mins!=-1)		
	{
		while	( match_result!=TRUE )
		{

			if (match_info.CompetitionType==LEAGUE )
			{
				if ( (game_data[setup.team_a].player_control!=NULL && game_data[setup.team_b].player_control!=NULL) )
					match_result	=	TRUE;
				if ( (game_data[setup.team_a].player_control!=NULL && game_data[setup.team_b].player_control==NULL) &&
				   (match_info.team_a_score<match_info.team_b_score ) )
					match_result	=	TRUE;
				if ( (game_data[setup.team_b].player_control!=NULL && game_data[setup.team_a].player_control==NULL) &&
				   (match_info.team_b_score<match_info.team_a_score ) )
		 			match_result	=	TRUE;
			}
	
			if ( match_info.CompetitionType==CUP )
			{
				if ( (game_data[setup.team_a].player_control!=NULL && game_data[setup.team_b].player_control==NULL) &&
				   (match_info.team_a_score<match_info.team_b_score ) )
						match_result	=	TRUE;
				if ( (game_data[setup.team_b].player_control!=NULL && game_data[setup.team_a].player_control==NULL) &&
				   (match_info.team_b_score<match_info.team_a_score ) )
						match_result	=	TRUE;
	
				if ( ( game_data[setup.team_a].player_control!=NULL && game_data[setup.team_b].player_control==NULL ) &&
				   ( match_info.team_a_score==match_info.team_b_score ) &&
				   ( match_info.team_a_penalties < match_info.team_b_penalties ) )
						match_result	=	TRUE;
	
				if ( ( game_data[setup.team_b].player_control!=NULL && game_data[setup.team_a].player_control==NULL ) &&
				   ( match_info.team_b_score==match_info.team_a_score ) &&
				   ( match_info.team_b_penalties < match_info.team_a_penalties ) )
						match_result	=	TRUE;
			}

	
			if (match_result==FALSE)
			{
			
				if ( (match_info.CompetitionType==LEAGUE) ||
				     (match_info.CompetitionType==CUP &&
				      match_info.extra==NULL && match_info.penalties==NULL) )	

				{
					if (goes<60)
						goes+=	(Random_RS()&7);

					attacker = (Random_RS()&7)+3;

		    			if ( whos_to_win==NULL )
		    				GOAL_SCORED(NULL, attacker, goes);
		    			else
		    				GOAL_SCORED(NULL, attacker+11, goes);

					goes++;

					if ( (game_data[setup.team_a].player_control!=NULL && game_data[setup.team_b].player_control==NULL) &&
					   (match_info.team_a_score<match_info.team_b_score ) )
							match_result	=	TRUE;
					if ( (game_data[setup.team_b].player_control!=NULL && game_data[setup.team_a].player_control==NULL) &&
					   (match_info.team_b_score<match_info.team_a_score ) )
							match_result	=	TRUE;

					if (goes>89 && match_result!=TRUE)
							match_info.extra	=	1;
				}






				if ( match_info.CompetitionType==CUP && match_info.extra!=NULL && match_info.penalties==NULL )
				{
					if (goes<100)
						goes+=	(Random_RS()&3);

					attacker = (Random_RS()&7)+3;

		    			if ( whos_to_win==NULL )
		    				GOAL_SCORED(NULL, attacker, goes);
		    			else
		    				GOAL_SCORED(NULL, attacker+11, goes);
					goes++;

				if ( (game_data[setup.team_a].player_control!=NULL && game_data[setup.team_b].player_control==NULL) &&
				   (match_info.team_a_score<match_info.team_b_score ) )
						match_result	=	TRUE;
				if ( (game_data[setup.team_b].player_control!=NULL && game_data[setup.team_a].player_control==NULL) &&
				   (match_info.team_b_score<match_info.team_a_score ) )
						match_result	=	TRUE;

					if (goes>119 && match_result!=TRUE)
						match_info.penalties	=	1;
				}


				if ( match_info.CompetitionType==CUP && match_info.extra!=NULL && match_info.penalties!=NULL )
				{
		    			if (game_data[setup.team_a].player_control==NULL)
			       			   match_info.team_a_penalties++;	
					else
			       			   match_info.team_b_penalties++;	
				}
			}
		}
	}
}




//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Calculates the result of a game between any two teams.                                                                      บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	calculate_match()
{
		match_info.extra		=	NULL;
		match_info.penalties		=	NULL;
		match_info.team_a_penalties	=	-1;
		match_info.team_b_penalties	=	-1;

	for (int goes=1; goes < 90; goes++)
	{
	if	( (Random_RS()&1)==0 )
		attemptGOAL( setup.team_a, setup.team_b, goes);
	else
		attemptGOAL( setup.team_b, setup.team_a, goes);
	}

	if ( match_info.CompetitionType==CUP && ( match_info.team_a_score==match_info.team_b_score) )
	{
		match_info.extra	=	-1;

		for (int goes=91; goes < 120; goes++)
	
		{
		if	( (Random_RS()&1)==0 )
			attemptGOAL( setup.team_a, setup.team_b, goes);
		else
			attemptGOAL( setup.team_b, setup.team_a, goes);
		}
	}


		// UNFORTUNATLY PENALTY SHOOT OUTS ARE TOTALLY RANDOM.....


	if ( match_info.CompetitionType==CUP && ( match_info.team_a_score==match_info.team_b_score)  )
	{
		match_info.penalties	=	-1;

		match_info.team_a_penalties	=	(Random_RS() & 3);
		match_info.team_b_penalties	=	(Random_RS() & 3);
	
		while	( (match_info.team_a_penalties==match_info.team_b_penalties) )
		{
			match_info.team_b_penalties	=	(Random_RS() & 3);
			match_info.team_a_penalties	=	(Random_RS() & 3);
		}
	}		
}


void	attemptGOAL( int team_a, int team_b, int time )
{
	int	rand_midfielder	,midfielder,mid_skill,rand_defender,defender,def_skill,gkp_skill,rand_attacker;
	int	penalty_chance,attacking_plyr,attacker,att_skill,defadd,midadd;
	
	midfielder	=	NULL;
	defender	=	NULL;
	rand_attacker	=	Random_RS()&255;		// random player  0 - 15;
	penalty_chance	=	rand_attacker;
	attacking_plyr	=	(rand_attacker&=15);	// used to decide on player attacking depending on position.
	attacker	=	NULL;			// actual player attacking	NULL = None.	

	gkp_skill	=	calculate_player_skill( team_b, 0, formation_data[game_data[team_b].formation].formations[0].position_type );	

			//	CALCULATE ATTACKING PLAYER

	if	( attacking_plyr < 11 )	
	{
		if	(formation_data[game_data[team_a].formation].formations[attacking_plyr].position_type==FD)
			attacker	=	attacking_plyr;
		if	(formation_data[game_data[team_a].formation].formations[attacking_plyr].position_type==MD &&
			 (rand_attacker&31)==attacking_plyr)
			attacker	=	attacking_plyr;
		if	(formation_data[game_data[team_a].formation].formations[attacking_plyr].position_type==DF &&
			 (rand_attacker&63)==attacking_plyr)
			attacker	=	attacking_plyr;
	}



			//	IF AN ATTACKER HAS BEEN FOUND THEN PERFORM RUN.....


	
	if	(attacker!=NULL)
	{
		att_skill	=	calculate_player_skill( team_a, attacker, formation_data[game_data[team_a].formation].formations[attacker].position_type );	
		
			// ADJUSTMENTS MADE TO STATS DEPENDING ON GOALS SCORED....

				if	(team_a==setup.team_a)
				{
					att_skill-=	match_info.team_a_score*4;
					gkp_skill+=	match_info.team_a_score*3;
					defadd	  =	match_info.team_a_score*3;
					midadd	  =	match_info.team_a_score*3;
				}
					else
				{
					att_skill-=	match_info.team_b_score*4;
					gkp_skill+=	match_info.team_b_score*3;
					defadd	  =	match_info.team_b_score*3;
					midadd	  =	match_info.team_b_score*3;
				}


			// 	ATTEMPT TO FIND MIDFIELD PLAYER....

		for (int midman=0; midman < 5; midman++)
		{
			if (midfielder==NULL)
				rand_midfielder	=	Random_RS()&15;		// random player  0 - 15;

			if	(rand_midfielder < 11)
			{
				if	(formation_data[game_data[team_b].formation].formations[rand_midfielder].position_type==MD)
					midfielder	=	rand_midfielder;
			}
		}

			//	IF A MIDFIELDER HAS BEEN FOUND THEN GET READY FOR TACKLE....
		

		if	(midfielder!=NULL)
		{
			mid_skill	=	calculate_player_skill( team_b, midfielder, formation_data[game_data[team_b].formation].formations[midfielder].position_type );	
			mid_skill+=		midadd;

			if (mid_skill>att_skill)
				attacker = NULL;

		}			
			//	ATTACKER HAS SKINNED MIDFIELDER.....

		if (attacker!=NULL)


			// 	ATTEMPT TO FIND DEFENDER PLAYER....

		for (int defman=0; defman < 8; defman++)
		{
			if (defender==NULL)
				rand_defender	=	Random_RS()&7;		// random player  0 - 15;
	     		
				if	(formation_data[game_data[team_b].formation].formations[rand_defender].position_type==DF)
					defender	=	rand_midfielder;
		}

			//	IF A DEFENDER HAS BEEN FOUND THEN GET READY FOR TAKLE....
		
		
		if	(defender==NULL)
			attacker	=	NULL;
		else
		{
			def_skill	=	calculate_player_skill( team_b, defender, formation_data[game_data[team_b].formation].formations[defender].position_type );	
			def_skill+=		defadd;
			
			if (def_skill>att_skill)
				attacker = NULL;
		}			


		if (attacker!=NULL)
		{
			int	shot	=	Random_RS()&510;


		    	//	IF KEEPER IS RATED BETTER THAN ATTACKER THEN GIVE ATTACKER SOME CHANCE

			
			if	(gkp_skill>att_skill)
				att_skill	=	gkp_skill+3;			

			if	(gkp_skill>shot || shot>att_skill)
				attacker = NULL;


			if (attacker!=NULL)
			{
				int	timed	=	time;

			//	HEY REF THAT WAS DIGUSTING....PENALTY, SURLY...

				if	( (penalty_chance>28 && penalty_chance<58) &&
					  (game_data[team_a].players[attacker].discipline >
					  game_data[team_b].players[defender].discipline) )
						timed|=	256;


				if	(team_a==setup.team_a)

					GOAL_SCORED(NULL, attacker, timed);
				else
					GOAL_SCORED(NULL, attacker+11, timed);
			}
		}
			
	}
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Sets up goal data after a goal has been scored, for later use when displaying scorers.                                      บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
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

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Calculates a players skill, depending on his stats and chosen position of play on field.                                    บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
int	calculate_player_skill( int team_no, int position, int pitch_posn )
{
		switch ( pitch_posn )
		{
		case(GK):
			return(
			game_data[team_no].players[position].accuracy+
			(game_data[team_no].players[position].control/2)+
			(game_data[team_no].players[position].pace/2)+
			(game_data[team_no].players[position].power/4)+
			((100-game_data[team_no].players[position].discipline)/4)+
			(game_data[team_no].players[position].vision/4) );
			break;

		case(DF):
			return(
			game_data[team_no].players[position].power+
			((100-game_data[team_no].players[position].discipline)/2)+
			(game_data[team_no].players[position].pace/2)+
			(game_data[team_no].players[position].flair/4)+
			(game_data[team_no].players[position].stamina/4)+
			(game_data[team_no].players[position].vision/4) );
			break;

		case(MD):
			return(
			game_data[team_no].players[position].flair+
			(game_data[team_no].players[position].control/2)+
			(game_data[team_no].players[position].pace/2)+
			(game_data[team_no].players[position].vision/4)+
			(game_data[team_no].players[position].stamina/4)+
			(game_data[team_no].players[position].accuracy/4) );
			break;

		case(FD):
			return(
			game_data[team_no].players[position].pace+
			(game_data[team_no].players[position].accuracy/2)+
			(game_data[team_no].players[position].flair/2)+
			(game_data[team_no].players[position].control/4)+
			(game_data[team_no].players[position].stamina/4)+
			(game_data[team_no].players[position].power/4) );
			break;
		}
	
	return(NULL);
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Reset table holding data for goals and scorers.                                                                             บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	reset_scores()
{
		// RESET BOTH TEAMS SCORES...

			match_info.team_a_score		=	NULL;
			match_info.team_b_score		=	NULL;

		// RESET TABLE HOLDING SCORERS...

			for (int table = 0; table < MAX_GOALS+1; table++)

			{
				goals[table].goal_data.used	=	NULL;
				goals[table].goal_data.time	=	NULL;
				goals[table].goal_data.scorer	=	NULL;
			}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Display goal scorers for both teams.                                                                                        บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//

void	DisplayGOALscorers( char credit, int teams_goals )
{
	char	comma_flag;
	short	scorer, which_way;
	char	NumberBUFFER[5];
		

	lineY	=	0;
	TabX	=	TextXposn;

		// RESET GOAL DISPLAYED FLAG, SO ALL GOALS ARE SCANED....


	for (int reset_display = 0; reset_display < MAX_GOALS; reset_display++)
				{goals[reset_display].goal_data.used&=	255-GOAL_DISPLAYED;}



		// RUN THIS LOOP UNTIL NO MORE GOALS ARE TO BE DISPLAYED....

	while	( teams_goals!=0 )
	{
			scorer		=	-1;

		for (int goalnum = 0; goalnum < MAX_GOALS; goalnum++)
		{

			// FIND NAME OF FIRST GOAL SCORER...

			comma_flag	=	OFF;

			if ( (goals[goalnum].goal_data.used & credit)!=0 && (goals[goalnum].goal_data.used & GOAL_DISPLAYED)==0 )
			{
				TextXposn	=	TabX;								

					// *** GOAL !!! ***
				
				if ( (goals[goalnum].goal_data.time & O_G)==0 && lineY<MAX_LINES)
				{
					which_way	=	0;
					scorer		=	goals[goalnum].goal_data.scorer;										
					DisplaySTRING( FindGOALSCORERSname(credit,scorer), 
							SHADOWtextON|SFONT);
				}
			       	
				else
					// *** OWN GOAL ***
				{
					which_way	=	512;
					scorer		=	goals[goalnum].goal_data.scorer;										
					
					if (lineY<MAX_LINES)
						DisplaySTRING( FindGOALSCORERSname( (credit^(CREDIT_TEAMa+CREDIT_TEAMb)), scorer ), 
						SHADOWtextON|SFONT);
				}
				TextXposn+=	10;
				CheckEndOfLine();
			}









		
			if (scorer != -1)
		 	{

		// DISPLAY ALL GOALS SCORED BY THIS PLAYER.....

				for (int times = 0; times < MAX_GOALS; times++)
				{

				   if ( (goals[times].goal_data.used & credit)!=0 &&
					(goals[times].goal_data.used & GOAL_DISPLAYED)==0 &&
					goals[times].goal_data.scorer==scorer &&
					(goals[times].goal_data.time & O_G)==which_way &&	
					TextYposn < (310+(5*24)) )
					{

							if ( comma_flag==ON && lineY<MAX_LINES)
								DisplaySTRING( ", ", SHADOWtextON|SFONT); 

							CheckEndOfLine();

							itoa	( goals[times].goal_data.time & 255, NumberBUFFER, 10);
							
							if (lineY<MAX_LINES)
								DisplaySTRING( NumberBUFFER, SHADOWtextON|SFONT); 
						      	
							if ( (goals[times].goal_data.time & PEN)!=0 && lineY<MAX_LINES)
								DisplaySTRING( GetText(PEN_TEXT), SHADOWtextON|SFONT); 
							if ( (goals[times].goal_data.time & O_G)!=0 && lineY<MAX_LINES)
								DisplaySTRING( GetText(OG_TEXT), SHADOWtextON|SFONT); 

							goals[times].goal_data.used|=	GOAL_DISPLAYED;
							comma_flag	=	ON;
							teams_goals--;
			    		}
			    	}

					if (comma_flag==ON)
					{
						lineY++;
						TextYposn+=	24;
					}
			}
				if (scorer == -1)
					teams_goals	=	0;
		}			
	}
}




//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Checks for end of line and bottom bounding area when displaying scorers.                                                    บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//

void	CheckEndOfLine()
{
	if (TextXposn > (TabX+170) )
	{
	TextYposn+=	24;
	lineY++;
	TextXposn=	TabX;				
	}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Look for name of goal scorer using both players squad number and the team to whom the goal is credited.                     บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
char*	FindGOALSCORERSname( char credit, int player )
{
	int	team;
	int	array_number	=	NULL;

 	if	( credit==CREDIT_TEAMa )
		team	=	setup.team_a;		
	else
		team	=	setup.team_b;		

	for (int playnum = 0; playnum < 22; playnum++)
	{
		if	( game_data[team].players[playnum].squad_number==player )	
     			array_number	=	playnum;
	}

	return	( game_data[team].players[array_number].name+game_data[team].players[array_number].goal_index );
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Control relegation and promotion stuff.                                                                                     บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	SortNEWdivisions()
{

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
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Selects squad for computer controlled team.                                                                                 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	SortSQUAD(int team)
{
	if (match_info.CompetitionType==NETWORK)
	{
		for (int player = 0; player < 11+4; player++)		
		{
			if	( game_data[team].players[player].squad_number!=player )
			{
				for (int search = 0; search < 22; search++)		
				{
					if	( game_data[team].players[search].squad_number==player )
						swap_players(search, player);
				}
			}
		}
	}

	else
	
	{
			int	old_select	=	selected_team;
			selected_team	=	team;
			int	pitch_posn;
			int	player_skill;
       	
		// ** GET DEFAULT FORMATION FOR TEAM ***
       	
			int	team_formation	=	game_data[team].computer_formation;
			
		// ** SETUP FORMATION TYPE WITHIN ACTUAL GAME DATA ***	
       	
			formation_toggle		=	team_formation;	
			game_data[team].formation	=	team_formation;
       	
       	
		for (int times = 0; times <2; times++)
		{
       	
		// ** LOOP THROUGH FIRST ELEVEN PLAYERS TO FIND BEST PLAYERS TO FILL POSITIONS ***	
       	
			for (int player = 0; player < 11; player++)		
			{

		// ** GET IDEAL PITCH POSITION FOR PLAYER DEPENDING ON DEFAULT TEAM FORMATION *** 
	
			pitch_posn		=	formation_data[team_formation].formations[player].position_type;	

		// ** IF PLAYER IS OUT OF POSITION THEN FIND BETTER POSITIONED PLAYER ***
	       	
				if	( game_data[team].players[player].position != pitch_posn )
			       	{
			       		int	better_flag	=	FALSE;
					int	better_plyr	=	player+1;	
			
					while	( better_flag!=TRUE )
					{
						if	( game_data[team].players[better_plyr].position == pitch_posn )
						{
						swap_players(better_plyr, player);
						better_flag	=	TRUE;
						}
	
						if	( game_data[team].players[better_plyr].position != pitch_posn )
	
						{
						better_plyr++;
							if (better_plyr>21)
								better_flag	=	TRUE;
						}
					}
	
				}
	
	
		// ** NOW SEE IF A HIGHER SKILLED PLAYER IS AVAILABLE ***
	
			player_skill	=	calculate_player_skill( team, player, pitch_posn );	
				
				for (int skillfull = player+1; skillfull < 22; skillfull++)		
				{
					if	( game_data[team].players[skillfull].position == pitch_posn &&
						   player_skill < calculate_player_skill( team, skillfull, pitch_posn ) )
					{
							swap_players(skillfull, player);
					}
				}
			}
		}
			selected_team	=	old_select;
	}
}



//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Determins if user has selected arcade and auto game is required.                                                            บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//


void	SortARCADEleagueGAME()
{
	int	old_match_number;


		if ( match_info.GameType==ARCADE)
	{
			if ( (game_data[setup.team_a].player_control==NULL &&
			      game_data[setup.team_b].player_control==NULL) ||
				((signed char)fixtures[batch_info.match_number].fixture_data.home_team==-1 ||
				batch_info.match_number>603)		//fix for German bug, only 603 matches, so ...
			
		)

		{ 
		
			batch_info.roundup_games++;
			batch_info.league_rndup	=	batch_info.roundup_games;
			old_match_number=	batch_info.match_number;

			reset_scores();
			batch_info.OldCTRL1     	=	-1;
			batch_info.OldCTRL2     	=	-1;
			batch_info.match_number	=	SortNEXTfixture(batch_info.match_number, match_info.CompetitionType);

			if ((batch_info.match_number==-1)||(batch_info.match_number>603))
			{
				batch_info.match_number = -1;
				menu_data[MENU_A11].ButtonLIST[0].button_left_select	=	GOTO_MENU_A17; 
//				menu_data[MENU_A11].ButtonLIST[0].button_right_select	=	GOTO_MENU_A17;
				menu_data[MENU_A12].ButtonLIST[0].button_left_select	=	GOTO_MENU_A17; 
//				menu_data[MENU_A12].ButtonLIST[0].button_right_select	=	GOTO_MENU_A17;
				menu_data[MENU_A13].ButtonLIST[0].button_left_select	=	GOTO_MENU_A17; 
//				menu_data[MENU_A13].ButtonLIST[0].button_right_select	=	GOTO_MENU_A17;
				menu_data[MENU_A22].ButtonLIST[0].button_left_select	=	GOTO_MENU_A11; 
//				menu_data[MENU_A22].ButtonLIST[0].button_right_select	=	GOTO_MENU_A11;
			}
				
			else

			{
				menu_data[MENU_A11].ButtonLIST[0].button_left_select	=	DONE_LEAGUE_DISPLAY;
//				menu_data[MENU_A11].ButtonLIST[0].button_right_select	=	DONE_LEAGUE_DISPLAY;
				menu_data[MENU_A12].ButtonLIST[0].button_left_select	=	DONE_LEAGUE_DISPLAY;
//				menu_data[MENU_A12].ButtonLIST[0].button_right_select	=	DONE_LEAGUE_DISPLAY;
				menu_data[MENU_A13].ButtonLIST[0].button_left_select	=	DONE_LEAGUE_DISPLAY;
//				menu_data[MENU_A13].ButtonLIST[0].button_right_select	=	DONE_LEAGUE_DISPLAY;
				menu_data[MENU_A22].ButtonLIST[0].button_left_select	=	DONE_ROUNDUP; 
//				menu_data[MENU_A22].ButtonLIST[0].button_right_select	=	DONE_ROUNDUP;
			}
			
			current_menu		=	PLAY_MATCH;

			if ( game_data[setup.team_a].player_control!=NULL ||
			     game_data[setup.team_b].player_control!=NULL)
		       		{
					current_menu		=	MENU_A8;
				}


			if ( batch_info.roundup_games >7 || batch_info.match_number==-1)
				{
					current_menu		=	MENU_A22;

					if (batch_info.match_number==-1)
						batch_info.round_up_page	=	(old_match_number&(65535-7));
			 		batch_info.roundup_games		=	NULL;
				}

		}
	}
}



//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Sets up andy player flags needed for both teams.                                                                            บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	setup_player_data(int team_no)
{
	for (int player = 0; player < 22; player++)		
	{game_data[team_no].players[player].flags	=	0;}

	game_data[team_no].players[11].flags	=	SUBSTITUTE;
	game_data[team_no].players[12].flags	=	SUBSTITUTE;
	game_data[team_no].players[13].flags	=	SUBSTITUTE;
	game_data[team_no].players[14].flags	=	SUBSTITUTE;
}							



void	get_cup_venue()
{
	if (match_info.CompetitionType==CUP)
	{
		int	legal_venue	=	FALSE;
		match_info.venue	=	( ( ( batch_info.cup_team_a+1)*MAX_TEAMS) + batch_info.cup_team_b) & 63;

		while	( legal_venue==FALSE )
		{
			if ( match_info.venue < MAX_TEAMS-1 && 
			     match_info.venue != batch_info.cup_team_a && 
			     match_info.venue != batch_info.cup_team_b )
				legal_venue	=	TRUE;
		   	else	
			{
				match_info.venue++;
				match_info.venue&=	63;
			}
		}
	}
}
