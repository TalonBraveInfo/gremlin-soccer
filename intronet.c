
#if 0 // Not used, probably legacy code for older ActuaSoccer?

#ifdef IMPLEMENT_ME
#include "c:\netnow\hmistd.h"
#include "c:\netnow\netnow.h"
#include "c:\netnow\vdata.h"
#include "c:\netnow\vchat.h"
#endif
//#include "digi.h"
#include "cgdv.h"
#include "defines.h"
#include "euro_net.h"


#define    YES              1
#define    NO               0
#define    FRIENDLY         0
#define    LEAGUE           1
#define    CUP              2
#define    PRACTICE         3
#define    NETWORK          4

extern int x1ok;
extern int y1ok;
extern int x2ok;
extern int y2ok;
extern int bitaccept;

extern volatile int Team_A, Team_B;
extern unsigned short joy1_cnt_x, joy1_cnt_y;
extern unsigned short joy2_cnt_x, joy2_cnt_y;
extern int joy1_max_x, joy1_max_y, joy1_min_x, joy1_min_y;
extern int joy2_max_x, joy2_max_y, joy2_min_x, joy2_min_y;

short DIGIdrvh;

char calibrate_flag;
unsigned short max_x;
unsigned short min_x;
unsigned short max_y;
unsigned short min_y;
int slide_x;
int slide_y;
char print_joy_message, print_red_message;

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Checks to see if network is on and if so allows NETWORK option to appear as a competition type.                             �
//�																                                                                              �
//������������������������������������������������������������������������������������������������������������������������������ͼ 

int CheckFORnet() {
#ifdef IMPLEMENT_ME
    if ( ( hmiNETNOWInitSystem( 16 ) != _NETNOW_NO_ERROR) )
        return	(NETWORK-1);
    else
#endif
    return (NETWORK);
}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Deinitialises netstuff if it was previously initialised...                                                                  �
//�																                                                                              �
//������������������������������������������������������������������������������������������������������������������������������ͼ 

void DeinitialiseNET(int netflag) {
#ifdef IMPLEMENT_ME
    if (netflag==NETWORK)
        hmiNETNOWUnInitSystem();
#endif
}


//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Sets up variables indicating that network game is to begin....                                                              �
//�																                                                                              �
//������������������������������������������������������������������������������������������������������������������������������ͼ 

void Init_Network_Game() {
#ifdef IMPLEMENT_ME
    Start_Network_Game();
#endif
//	printf("Initialises Team_A, Team_B, TeamChoice & PlayerChoice and starts network\n");
}

//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Tells network which two countries are to take part in netgame...                                                            �
//�																                                                                              �
//������������������������������������������������������������������������������������������������������������������������������ͼ 

void SendNETTeamInfo() {
    SendTeamInfo();
//	printf("\nTeam %d plays team %d\n",Team_A,Team_B);
}


//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Short delay before any more netinfo can be sent...                                                                          �
//�																                                                                              �
//������������������������������������������������������������������������������������������������������������������������������ͼ 

void TickerPause() {
//		printf("ticker....delay\n");
    TickPause();
}


//������������������������������������������������������������������������������������������������������������������������������ͻ 
//�                                                                                                                              �
//�  Send data indicating which player user is to control....                                                                    �
//�																                                                                              �
//������������������������������������������������������������������������������������������������������������������������������ͼ 

void SendPlayerChoice() {
    SendPlayerInfo();
}

void InitCalibration(int j) {
#ifdef IMPLEMENT_ME
    max_x = 0;
    min_x = 65535;
    max_y = 0;
    min_y = 65535;
    calibrate_flag = NULL;
    print_joy_message = 1;

    x1ok = 1;
    y1ok = 2;
    x2ok = 4;
    y2ok = 8;
    bitaccept = x1ok + y1ok + x2ok + y2ok;
#endif
}

void CalibrateJoy(int j) {
#ifdef IMPLEMENT_ME
    unsigned short x, y;
    unsigned char butt;

//		x1ok			=	1;	  
//		y1ok			=	2;	  
//		x2ok			=	4;	  
//		y2ok			=	8;	  
//		bitaccept	=	15;  

    if (calibrate_flag == 2 || calibrate_flag == 3) {
        if (!j)
            read_joystick(0, &joy1_cnt_x, &joy1_cnt_y, &butt);
        else
            read_joystick(1, &joy2_cnt_x, &joy2_cnt_y, &butt);
    }


    if (calibrate_flag == 3 && (butt & 3) != 0) {

//			if (!j)
//				{
//					joy1_cnt_x	=	x;
//					joy1_cnt_y	=	y;
//				}				
//			else
//				{
//					joy2_cnt_x	=	x;
//					joy2_cnt_y	=	y;
//				}				
//			
        print_joy_message = 1;
        calibrate_flag = 8;        //255;
    }


    if (calibrate_flag == 2 && (butt & 3) == 0)
        calibrate_flag = 3;

    if (calibrate_flag == NULL)
        calibrate_flag++;

    if (calibrate_flag == 1) {
        read_joystick(j, &x, &y, &butt);

        if (x > max_x)
            max_x = x;
        if (x < min_x)
            min_x = x;
        if (y > max_y)
            max_y = y;
        if (y < min_y)
            min_y = y;

        if ((butt & 3) != 0) {
            print_joy_message = 1;
            calibrate_flag = 2;

            if (!j) {
                joy1_max_x = max_x;
                joy1_max_y = max_y;
                joy1_min_x = min_x;
                joy1_min_y = min_y;
            } else {
                joy2_max_x = max_x;
                joy2_max_y = max_y;
                joy2_min_x = min_x;
                joy2_min_y = min_y;
            }
        }
    }
#endif
}

#endif
