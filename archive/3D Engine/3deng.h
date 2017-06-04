 					  
/********************************************************/														 
/*          3D ENGINE - Header File   17/01/95          */
/********************************************************/

#ifndef _3DENG_H_
#define _3DENG_H_


/**************/
/* DATA TYPES */

//Data size definitions
//use these as often as possible
typedef signed char byte;
typedef signed short word;
typedef signed int dword;
#ifndef BYTE
typedef unsigned char BYTE;
#endif
/*
#ifndef WORD
typedef unsigned short WORD;																 
#endif
#ifndef DWORD
typedef unsigned int DWORD;
#endif
*/
typedef float floatpt;

// Types used through 3D pipeline
typedef floatpt datapt;
typedef floatpt rotpt;
typedef dword scrpt;

// Word / Byte union
typedef union
	{
	struct {byte hiw, low;} d;
	word c;
	}
	dchar_u;

// DoubleWord / Word union
typedef union
	{
	struct {word hiw, low;} d;
	dword dw;
	}
	dword_u;



/**************/
/* MATH TYPES */

// General matrix type
typedef floatpt mat[4][4];

// Rotation matrix type (explicit for speed).
typedef union
	{
	mat arr;
	struct
		{
		floatpt r00,r01,r02,r03;
		floatpt r10,r11,r12,r13;
		floatpt r20,r21,r22,r23;
		}e;
	}
	qmat;



/*********************/
/* 3D GEOMETRY TYPES */

// 3D point & point-list types
typedef datapt *pt;
typedef datapt ptlist[];


// Face & face-list types
typedef word *face;
typedef word facelist[];


// Rotated point type
typedef rotpt *rpt;



/*********************/
/* 2D GEOMETRY TYPES */

// Screen point type
typedef struct
	{
	scrpt x,y;
	}
	pnt;

// Gourad screen point type
typedef struct
	{
	scrpt x,y,col;
	}
	ppnt;

// Screen point with z type (Bi-Quadratic mapping)
typedef struct
	{
	scrpt z,x,y;
	}
	zpnt;

// Screen polygon type (with average z for sort)
typedef struct
	{
	rotpt z;
	scrpt *pts;
	}
	pols;



/****************/
/* OBJECT TYPES */

// Object type
typedef struct
	{
	pt points;
	face faces;
	datapt x,y,z;
	floatpt crot,srot;
	}
	obj;

// Object list type
typedef struct
	{
	rotpt z;
	pols *polys;
	short nopols;
	}
	objs;

// Object detail level type
typedef struct
	{
	rotpt zscale; // min z/q for this detail level
	pt dpoints;
	face dfaces;
	}
	det;

// Object detail level list
typedef det detlist[];



/*****************/
/* SURFACE TYPES */

// Texture type
typedef dword texture[8]; // Assumes 4 pt textures, other nos of pts are padded out

// Polygon filter type
typedef BYTE filter[256];



/************************/
/* MOTION CAPTURE TYPES */

// Specific for players only
#define PLYRPTS 28

typedef datapt capfrm[PLYRPTS*3+1];

typedef struct
	{
	word cappts,capfrms;
	} mcap;



/*********************/
/* PLAYER INFO TYPES */

typedef struct
	{
	floatpt x,y,z,crot,srot,frame,fstep;
	short type,number,anim,sprite;
	BYTE htype,hcol;
	} plyrdat;

typedef struct
	{
	datapt *twnfrm;
	capfrm twnpts1,twnpts2;
	floatpt tween,tstep;
	short anim,animto;
	} plyrtwdat;



/**************/
/* MISC TYPES */

typedef struct
	{
	short sky;
	short stadia;
	short pitch;
	short players;
	short lines;
	short shadows;
	}
	detail_info;

// Setup data type
typedef struct
	{
	short M8;
	short team_a,team_b;
	short team_b_kit;
	short stadium;
	short vidi_type;
	short start_res;
	short screen_size;
	short verbose;
	detail_info detail; 
	}
	setup_info;

// Screen buffer info type
typedef struct
	{ 
	BYTE *buff_start;
	scrpt buff_wid,buff_hgt;
	scrpt clip_wid,clip_hgt;
	float scale_x,scale_y;
	void (*dump)(scrpt dispx,scrpt dispy);
	}
	buff_info;

// Extended screen buffer info type
typedef struct
	{ 
	BYTE *buff_start;
	BYTE *clip_end,*clip_endl;
	scrpt buff_wid,buff_hgt;
	scrpt clip_wid,clip_hgt,clip_widl,clip_hgtl;
	scrpt clip_xmid,clip_ymid;
	float scale_x,scale_y;
	void (*dump)(scrpt dispx,scrpt dispy);
	}
	buff_info_ext;

typedef struct {
	int pitchfile,pitchpfile;
	char skytypes[2];
	int tmdfile;
	int sb1file,sb2file;
	datapt s1x,s1y,s1z;
	int s1pfile,s1ffile;
	datapt s2x,s2y,s2z;
	int s2pfile,s2ffile;
	datapt s3x,s3y,s3z;
	int s3pfile,s3ffile;
	datapt s4x,s4y,s4z;
	int s4pfile,s4ffile;
	int st_w,st_l,st_h;
	short noloop;
	int loop[20];
	int vid1x,vid1y,vid1z;
	int vid2x,vid2y,vid2z;
	int tunlx,tunly,tunlz;
	int vmap;
	} 
	stad_info;

typedef struct {
	int headfile;
	int torsofile;
	int limbsfile;
	int nosfile;
	int palfile;
	int skinfile;
	int homepfile;
	int awaypfile;
	}
	teamk_info;



/***********************/
/* FUNCTION PROTOTYPES */
void InvertWord(BYTE *data, int howmany);
void InvertFloat(BYTE *data, int howmany);
void matcop(mat dest,mat src);
void matmul(mat m1,mat m2);
void matmultr(mat m1,mat m2);
void DrawTexture1(long w, BYTE *sc, BYTE *data, short pan);
void ground(float vr,float vwy,datapt vx,datapt vy,datapt vz);
float objdepd(obj *ob, det *detail);
void addpoly(face obf,word np,word col);
void addline(face obf,word col);
void add3dcmap(face obf,word col);
void add3demap(face obf,word col);
void addpolyc(face obf,word np,word col);
void addlinec(face obf,word col);
void addpols(obj *ob);
void addpolsc(obj *ob);
void addobjxy(obj *ob,floatpt cxrot,floatpt sxrot);
void addobjy(obj *ob);
void addobjyf(obj *ob);
void addobjyc(obj *ob);
void addobjn(obj *ob);
void addobjsp(datapt *sprpt, word *refpt);
void addobjnc(obj *ob);
void addobjf(obj *ob);
void addobjfc(obj *ob);
int objcmp(void const *obj1, void const *obj2);
int polcmp(void const *pol1, void const *pol2);
void dispols(void);
void dispolsn(void);
void dispolsnx(void);
void makefilter(filter filt,byte fr,byte fg,byte fb,float mr,float mg,float mb);
char *readbin(char *BinFile, BYTE *fPtr, dword *fLen);
int readfile(int fileno, BYTE *address);
char *readfileblock(int fileno, int blockno, int blocks, BYTE *address);
//void init_anim(anim_info &anim,int no);
//void stop_anim(anim_info &anim);
//void do_anim(anim_info &anim);
void do_extra_time_anim(int sp);
void do_foul_anim(int sp);
void do_full_time_anim(int sp);
void do_half_time_anim(int sp);
void do_penalty_anim(int sp);
void do_goal_anim(int sp);
void do_win_f_anim(int sp);
void do_win_g_anim(int sp);
void do_win_s_anim(int sp);
void draw_sprite(buff_info *buff,int sprite_no,int x,int y,BYTE col);
void draw_sprite_d(buff_info *buff,int sprite_no,int x,int y,BYTE col);
void draw_sprite_s(buff_info *buff,int sprite_no,int x,int y,BYTE col);
void draw_sprite_vf(buff_info *buff,int sprite_no,int x,int y,BYTE col);
void draw_sprite_r(buff_info *buff,int sprite_no,int x,int y,BYTE col);
void draw_sprite_hf(buff_info *buff,int sprite_no,int x,int y,BYTE col);
void draw_sprite_vhf(buff_info *buff,int sprite_no,int x,int y,BYTE col);
int string_len(int font_no,char *string);
int draw_string(buff_info *buff,int font_no,int x,int y,char *string,BYTE col,short just);
void draw_menu_box(buff_info *buff);
void goal_menu(buff_info *buff, int team, int player, int time);
void booked_menu(buff_info *buff, int team, int player);
void off_menu(buff_info *buff, int team, int player);
void direct_menu(buff_info *buff, int team);
void indirect_menu(buff_info *buff, int team);
void penalty_menu(buff_info *buff, int team);
void corner_menu(buff_info *buff, int team);
void throw_menu(buff_info *buff, int team);
void goalkick_menu(buff_info *buff, int team);
void kickoff_menu(buff_info *buff, int team);
void offside_menu(buff_info *buff, int team);
void injured_menu(buff_info *buff, int team, int player);
void ref_menu(buff_info *buff);
void GOAL_SCORED( int team, int scorer, int time );
void score_breakdown_l(buff_info *buff);
void score_breakdown_h(buff_info *buff);
void fulltime_menu(buff_info *buff);
void extratime_menu(buff_info *buff);
void halftime_menu(buff_info *buff);
void penalty_shootout_menu(buff_info *buff);
void final_score_menu(buff_info *buff);
void owngoal_menu(buff_info *buff, int team, int player, int time);
void draw_s_butt(buff_info *buff,int x,int y,char *string,BYTE col); // ,char *legend);
void draw_m_butt(buff_info *buff,int x,int y,char *string,BYTE col); // ,char *legend);
void draw_l_butt(buff_info *buff,int x,int y,char *string,BYTE col); // ,char *legend);
void options_menu(buff_info *buff, int team, int user_no);
void formation_menu(buff_info *buff, int team, int user_no);
void substitution_menu(buff_info *buff, int team, int user_no);
void replay_menu(buff_info *buff, int user_no);
void do_goal_menu(int team, int player, int time);
void do_booked_menu(int team, int player);
void do_off_menu(int team, int player);
void do_direct_menu(int team);
void do_indirect_menu(int team);
void do_penalty_menu(int team);
void do_corner_menu(int team);
void do_throw_menu(int team);
void do_goalkick_menu(int team);
void do_kickoff_menu(int team);
void do_offside_menu(int team);
void do_injured_menu(int team, int player);
void do_fulltime_menu(void);
void do_extratime_menu(void);
void do_halftime_menu(void);
void do_penalty_shootout_menu(void);
void do_final_score_menu(void);
void do_owngoal_menu(int team, int player, int time);
void do_options_menu(int team,int user_no);
void do_formation_menu(int team,int user_no);
void do_substitution_menu(int team,int user_no);
void do_replay_menu(int user_no);
void do_ref_menu(void);
int get_dir(int user_no);
void replay(buff_info *buffer,datapt viewx,datapt viewy,datapt viewz,datapt targx,datapt targy, datapt targz,datapt vdist,plyrdat *plyrtb,datapt *xyz_ptr,word *ref_ptr,int user_no);
void substitution(buff_info *buffer,datapt viewx,datapt viewy,datapt viewz,datapt targx,datapt targy, datapt targz,datapt vdist,plyrdat *plyrtb,datapt *xyz_ptr,word *ref_ptr,int team);
void formation(buff_info *buffer,datapt viewx,datapt viewy,datapt viewz,datapt targx,datapt targy, datapt targz,datapt vdist,plyrdat *plyrtb,datapt *xyz_ptr,word *ref_ptr,int user_no,int team);
void options(buff_info *buffer,datapt viewx,datapt viewy,datapt viewz,datapt targx,datapt targy, datapt targz,datapt vdist,plyrdat *plyrtb,datapt *xyz_ptr,word *ref_ptr,int user_no,int team);
void adjust_menu(void);
void render3d(buff_info *buffer,datapt viewx,datapt viewy,datapt viewz,datapt targx,datapt targy, datapt targz,datapt vdist,plyrdat *plyrtb,datapt *xyz_ptr,word *ref_ptr);
void dumpMCGAs(scrpt dispx,scrpt dispy);
void dumpScreen(scrpt dispx,scrpt dispy);
void dumpnull(scrpt dispx,scrpt dispy);
void dumpvidi1(scrpt dispx,scrpt dispy);
void initobj(obj *object,ptlist points,facelist faces,datapt x,datapt y,datapt z,floatpt crot,floatpt srot);
int init3d_gremlin(void);
void end3d_gremlin(void);
int timing(void);
void EndTiming(void);
void drawman(buff_info *buffer, float anim, float angle, int dist);
int initman(int team, int capture);
void endman(void);

extern buff_info main_buff;
extern buff_info LORES_buff;
extern buff_info HIRES_buff;

extern char *GetResString( int number);


#endif