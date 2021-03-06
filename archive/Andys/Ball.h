EXTERN float get_angle(float x,float y,float d);
EXTERN void get_xydis_from_ang(float a,float d);
EXTERN float get_s_angle(float z,float d);
EXTERN void get_zdis_from_ang(float a,float d);
EXTERN void stop_ball_spin(void);
EXTERN void swerve_xyz(void);
EXTERN void inc_swerve(void);
EXTERN void get_aftert_spin(void);
EXTERN void add_spin_fx(void);
EXTERN void move_ball(void);
EXTERN void grav_ball(void);
EXTERN void ball_friction(void);
EXTERN void roll_ball(void);
EXTERN void ball_trajectory(void);
EXTERN void get_ball_zone(void);
EXTERN void launch_ball(int p);
EXTERN void reset_shot(void);
EXTERN void new_shot(int p);
EXTERN void reset_ball(void);
EXTERN void respot_ball(void);
EXTERN void shot_passed(void);
EXTERN void stadium_bounds(void);
EXTERN void pitch_bounds(void);
EXTERN void rebound_post(void);
EXTERN void rebound_bar(void);
EXTERN void own_goal(void);
EXTERN void good_goal(void);
EXTERN void hit_goal_post(void);
EXTERN void hit_cross_bar(void);
EXTERN void hit_high_side_net(void);
EXTERN void hit_low_side_net(void);
EXTERN void hit_top_net(void);
EXTERN void hit_inside_back_net(void);
EXTERN void hit_inside_back_net_r(void);
EXTERN void hit_inside_top_net(void);
EXTERN void hit_inside_high_side(void);
EXTERN void hit_inside_low_side(void);
EXTERN short real_player(short p);
EXTERN short standard_player(short p);
EXTERN short country(char t);
EXTERN void go_right_goal(void);
EXTERN void go_left_goal(void);
EXTERN void outside_of_net(float f,float y,float z);
EXTERN void is_it_a_goal(void);
EXTERN void ball_collision(void);
EXTERN void oball_collision(void);
EXTERN void get_ball_speed(void);
EXTERN void ball_limbo(int p,float c);
EXTERN void ball_possession(void);
EXTERN void process_ball(void);
