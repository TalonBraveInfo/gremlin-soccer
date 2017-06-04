EXTERN void init_keyboard(void);
EXTERN void delete_net_user(int u);
EXTERN void add_team_user(short t,short c);
EXTERN void add_fixed_user(short p,short c);
EXTERN void clear_all_fixed(void);
EXTERN void init_users(void);
EXTERN void go_button(void);
EXTERN void mouse_fired(void);
EXTERN void process_butts(void);
EXTERN void convert_inputs(void);
EXTERN void clear_auto(short u);
EXTERN void clear_all_autos(void);
EXTERN void reset_f_held(void);
EXTERN short user_keeper_a(void);
EXTERN short user_keeper_b(void);
EXTERN short user_taker_a(short p);
EXTERN short user_taker_b(short p);
EXTERN void auto_select_a(short u);
EXTERN void auto_select_b(short u);
EXTERN void reselect_a(void);
EXTERN void reselect_b(void);
EXTERN void reselect(void);
EXTERN void reselect_all_users(void);
#ifdef FORCE_SELECT
EXTERN void force_users(void);
#endif
EXTERN void new_users(void);
