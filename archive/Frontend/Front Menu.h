EXTERN char		   *GetSTRING(int string_type,int array_number);
EXTERN int			GetSTATvalue(int string_type,int array_number,int stat_type);
EXTERN int			GetSPRITEnumber(int sprite_type,int number,int LastSpriteNO);
EXTERN int			GetBUTTONnumber(int button_type, int button_index, int button_flags);
EXTERN void			Do_cupsetup_highlights();
EXTERN void			Initialise_menu(int menu_number);
EXTERN void			swap_players(int player1,int player2);
EXTERN void			Setup_cup_teams(int number_of_cup_teams);
EXTERN void			Initialise_environment();
EXTERN void			Initialise_rolling_demo();
EXTERN void			Setup_no_of_teams();
EXTERN void			Setup_possible_choice_teams();
EXTERN void			SubstituePlayers( int team_no, int player1, int player2);
EXTERN void			reset_net_variables();
EXTERN void			ColourPOSN( int menu_number, int team );
EXTERN char			*GetText(int text_number, int base=textMain);
