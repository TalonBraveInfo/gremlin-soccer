#include "Frontend Vars.h"
#include "Intronet.h"
#include <NetSprocket.h>

#undef EXTERN
#define EXTERN extern
#include "Blitter.h"
#include "Failure.h"
#include "Football.h"
#include "Front Variables.h"
#include "MallocX.h"
#include "More Control.h"
#include "Not Written Yet.h"
#include "Process Inputs.h"
#include "StringUtils.h"

extern short wConsoleNode;
extern volatile char in_game;
extern short rand_seed;			// From Game

static Boolean	bHostFlag = false;
static Boolean	bStartGame = false;
static Boolean	bGameRunning = false;

static int		iPlayersReady = 0;
static int		iPlayersMove = 0;

Str31		gameName = "\pActua Soccer";
Str31		gameName2 = "\pVR Soccer";
Str31		gameType = "\pSoccer Simulation";
Str31		gamePass = "\p";
Str31		playerName = "\pPlayer";
Str31		hostName = "\pHost";

NSpPlayerID	idMine;

#if NET_DEBUG == ON
FILE *NetDebugFile;

void OpenNetDebugFile()
{
	NetDebugFile = fopen("ASoccer.net","w+");
}

void CloseNetDebugFile()
{
	fclose( NetDebugFile);
}
#endif

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Checks to see if network is on and if so allows NETWORK option to appear as a competition type.                             บ
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

static void CheckNetworkError( OSStatus status)
{
	if( status<0)
		switch( status)
			{
			case( -30380):
					Fail( status, __FILE__, __LINE__, false, "\pNetwork Address Already In Use");
					break;
			default:
					Fail( status, __FILE__, __LINE__, false, "\pNetwork Error");
					break;
			}
}

void Network_Play_Ready(void)			// Waits For All People To Be Ready
{
OSStatus	status;

	if( !gNetGame)
		return;

	if( bHostFlag)
		{
		while( !bGameOver && iPlayersReady<(network_on-1))
			Polling_Network();
		if( !bGameOver)
			{
//			status = NSpGame_EnableAdvertising( gNetGame, NULL, false);
//			CheckNetworkError( status);
			SendGameStart();
			}
		}
	else
		{
		SendPlayerReady();
		while( !bStartGame && !bGameOver)
			Polling_Network();
		}
}

void Quit_Network_Play()				// Game Finished
{
NSpMessageHeader message;
OSStatus	status;

	if( !gNetGame)
		return;

#if NET_DEBUG==ON
	fprintf(NetDebugFile, "Closing Network Game\n");
#endif

	NSpClearMessageHeader (&message);

	if( bHostFlag)
		{
		message.what			= kNSp_GameEnd;
		message.to				= kNSpAllPlayers;
		message.messageLen		= sizeof(NSpMessageHeader);
		status = NSpMessage_Send( gNetGame, &message, kNSpSendFlag_Normal);
		CheckNetworkError( status);
	
		while( network_on>1)
			Polling_Network();
		}

	status = NSpGame_Dispose( gNetGame, kNSpGameFlag_ForceTerminateGame );
	CheckNetworkError( status);
	gNetGame = NULL;

	network_on = 0;	
	bGameOver = false;
	bHostFlag = false;
}

void End_Network_Game()
{
	old_mf=TRUE;
	bGameOver = false;
	bHostFlag = false;
}

int	CheckFORnet()
{
OSStatus	status;
int			retValue = NETWORK-1;

	net_cd_in = cd_in;
	
	gNetGame = NULL;
	
//	If we actually have NetSprocket, do the initialization
	if ((NSpInitialize != NULL))
		{
		status = NSpInitialize(50, 200000, 100, 'ACTU', 0);
		if( status == noErr)
			{
			status = NSpInstallJoinRequestHandler(&MyJoinRequestHandler, NULL);
			retValue = NETWORK;
			}
		else
			CheckNetworkError( status);
		}

	return retValue;
}

//ษอออออออออออออออออออออออออออออออออออออออออออออ
//บ                                                                                                                              บ
//บ  HostGame - Advertises a Game on the Network
//บ																                                                                              บ
//ศอออออออออออออออออออออออออออออออออออออออออออออ
Boolean HostGame(void)
{
OSStatus	status = noErr;

#if NET_DEBUG==ON
//	SIOUXSettings.toppixel = 16;
//	SIOUXSettings.leftpixel = 640;
//	SIOUXSettings.columns = 30;
//	SIOUXSettings.rows = 60;
//	SIOUXSettings.autocloseonquit = true;
//	SIOUXSettings.asktosaveonclose = false;
//	printf("Hosting Game\n");
#endif
	Quit_Network_Play();

	if( Language == American || Language == Canadian)
		memcpy( gameName, gameName2, 31);

	atRef = NSpProtocol_CreateAppleTalk( gameName, gameType, 0, 0);
	ipRef = NSpProtocol_CreateIP( 5666, 0, 0);
		
	status = NSpProtocolList_New(NULL,  &protocolList);
	CheckNetworkError( status);
				
	if(status == noErr)
		{
		status = NSpProtocolList_Append( protocolList, atRef);
		CheckNetworkError( status);
		if(status == noErr)
			{
			status = NSpProtocolList_Append( protocolList, ipRef);
			CheckNetworkError( status);
			if(status == noErr)
				{
				ShowCursor();
				status = NSpDoModalHostDialog( protocolList, gameName, hostName, gamePass, NULL);
				HideCursor();
		    	BlitBufferToScreen( (double *) psudo_buffer);
				if(status == 1)		// OK pressed
					{
					status = NSpGame_Host( &gNetGame, protocolList, 8, gameName, gamePass, playerName, 0, kNSpClientServer, 0);
					if( status == noErr)
						{
						bHostFlag = true;
						idMine = NSpPlayer_GetMyID( gNetGame);
						wConsoleNode = network_on;
						}
					else
						CheckNetworkError( status);
					}
				NSpProtocolList_Dispose( protocolList);
				}
			}
		
		}

	return gNetGame == NULL;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  JoinGame - Allows Player To Join A Hosted Game
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 

Boolean JoinGame(void)
{
OSStatus status = noErr;
NSpAddressReference address;

	Quit_Network_Play();

	ShowCursor();
	address = NSpDoModalJoinDialog( gameType, "\pAvailable Games:", playerName, gamePass, NULL);
	HideCursor();
   	BlitBufferToScreen( (double *) psudo_buffer);
	if( address)
		{
		status = NSpGame_Join( &gNetGame, address, playerName, gamePass, 0, 0, NULL, 0);
		if( status == noErr)
			{
			Polling_Network();
			idMine = NSpPlayer_GetMyID( gNetGame);
			wConsoleNode = network_on;
			}
		else
			CheckNetworkError( status);
		}

	NSpReleaseAddressReference( address);

	return address == 0;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Deinitialises netstuff if it was previously initialised...                                                                  บ
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	DeinitialiseNET(int netflag)
{
	Quit_Network_Play();
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Sets up variables indicating that network game is to begin....                                                              บ
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void Init_Network_Game()
{
int i;

	net_error = 0;
	
	bGameOver = false;
	bStartGame = false;
	bGameRunning = false;
	
	iPlayersReady = 0;
	iPlayersMove = 0;

	TeamChoice		= 0;
	PlayerChoice	= 0;
	Team_A			= -1;
	Team_B			= -1;

	for (i=0;i<MAX_NET_USERS;i++)
		{
		Players[i] = -1;
		NetTeams[i] = -1;
		}
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Tells network which two countries are to take part in netgame...                                                            บ
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	SendNETTeamInfo()
{
OSStatus status;
NetMessage message;

	if( !gNetGame)
		return;

	NSpClearMessageHeader (&message.header);

	message.header.what				= kNSp_TeamHeader;
	message.header.to				= kNSpAllPlayers;
	message.header.messageLen		= sizeof(NetMessage);

	message.TeamHeader.Team_A		= Team_A;
	message.TeamHeader.Team_B		= Team_B;
	message.TeamHeader.HalfLength	= net_half;
	message.TeamHeader.CdIn			= cd_in;

	status = NSpMessage_Send( gNetGame, &message.header, kNSpSendFlag_Normal | kNSpSendFlag_SelfSend);
	CheckNetworkError( status);
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Short delay before any more netinfo can be sent...                                                                          บ
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	TickerPause()
{
//	TickPause();
//	printf("ticker....delay\n");
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Send data indicating which player user is to control....                                                                    บ
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	SendPlayerChoice()
{
OSStatus status;
NetMessage message;

	if( !gNetGame)
		return;

	NSpClearMessageHeader (&message.header);

	message.header.what						= kNSp_PlayerSelect;
	message.header.to						= kNSpAllPlayers;
	message.header.messageLen				= sizeof(NetMessage);

	message.PlayerSelection.PlayerChoice	= PlayerChoice;
	message.PlayerSelection.TeamChoice		= TeamChoice;
	
	status = NSpMessage_Send( gNetGame, &message.header, kNSpSendFlag_Normal | kNSpSendFlag_SelfSend);
	CheckNetworkError( status);
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  All users have selected teams and players....                                                                               บ
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	SendNetOKAY()
{
/*
OSStatus status;
NetMessage message;

	if( !gNetGame)
		return;

	NSpClearMessageHeader (&message.header);
	
	message.header.what			= kNSp_OkayHeader;
	message.header.to			= kNSpAllPlayers;
	message.header.messageLen	= sizeof(NetMessage);

	status = NSpMessage_Send( gNetGame, &message.header, kNSpSendFlag_Normal);
	CheckNetworkError( status);
*/
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  All Games Should Start Now
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void SendPlayerReady()
{
OSStatus status;
NetMessage message;

	if( !gNetGame)
		return;

#if NET_DEBUG==ON
//	printf( "PlayerReady\n");
#endif

	NSpClearMessageHeader (&message.header);
	
	message.header.what			= kNSp_PlayerReady;
	message.header.to			= kNSpAllPlayers;
	message.header.messageLen	= sizeof(NetMessage);

	status = NSpMessage_Send( gNetGame, &message.header, kNSpSendFlag_Normal);
	CheckNetworkError( status);
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  All Games Should Start Now
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void SendGameStart()
{
OSStatus status;
NetMessage message;

	if( !gNetGame)
		return;

#if NET_DEBUG==ON
	fprintf( NetDebugFile, "GameStart\n");
#endif

	NSpClearMessageHeader (&message.header);
	
	message.header.what			= kNSp_StartGame;
	message.header.to			= kNSpAllPlayers;
	message.header.messageLen	= sizeof(NetMessage);

	status = NSpMessage_Send( gNetGame, &message.header, kNSpSendFlag_Normal);
	if( status == noErr)
		bGameRunning = true;

	CheckNetworkError( status);
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Send Each Players Data To Host
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void SendPlayerData( PlayerData *data)
{
OSStatus status;
NetMessage message;

	if( !gNetGame)
		return;

	NSpClearMessageHeader (&message.header);
	
	message.PlayerData.X_f1 = data->X_f1;
	message.PlayerData.Y_f2 = data->Y_f2;
	message.GameSeed		= rand_seed;
	
	message.header.messageLen	= sizeof(NetMessage);
	message.header.what			= kNSp_PlayerData;		// Normal Data Packet
	message.header.to			= kNSpAllPlayers;
	status = NSpMessage_Send( gNetGame, &message.header, kNSpSendFlag_Normal|kNSpSendFlag_SelfSend);

	CheckNetworkError( status);
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Send All Players Data From Host To Everybody
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void SendRunLoop()
{
OSStatus status;
NetMessage message;

	if( !gNetGame)
		return;

	NSpClearMessageHeader (&message.header);

	message.header.messageLen	= sizeof(NetMessage);
	message.header.what			= kNSp_RunLoop;
	message.header.to			= kNSpAllPlayers;
	status = NSpMessage_Send( gNetGame, &message.header, kNSpSendFlag_Normal | kNSpSendFlag_SelfSend);

	CheckNetworkError( status);
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Misc Routines For Player Management
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
static int FindPlayer( BYTE playerId)
{
int i;

	for( i=0; i<network_on; i++)
		{
		if( NetIds[i] == playerId)
			return i;
		}
	
	return -1;
}

static void AddPlayerToList( BYTE playerId)
{
	if( FindPlayer( playerId) != -1)
		return;
		
	NetIds[network_on] = playerId;
	NetTeams[network_on] = -1;
	network_on++;
}

static void DeletePlayer( BYTE playerId)
{
int thisPlayer = FindPlayer( playerId);
int i;

	if( playerId == -1)
		return;
	
	NetIds[thisPlayer] = -1;
	NetTeams[thisPlayer] = -1;	
	for( i=thisPlayer; i<network_on-1; i++)
		{
		NetIds[i] = NetIds[i+1];
		Players[i] = Players[i+1];
		NetTeams[i] = NetTeams[i+1];
		}
	network_on--;
}

pascal Boolean MyJoinRequestHandler(NSpGameReference inGame, NSpJoinRequestMessage *message, void* inContext, Str255 outReason)
{
#if NET_DEBUG==ON
	fprintf(NetDebugFile, "Join Request\n");
	fprintf(NetDebugFile, "      Player Id     %d\n", message->header.from);
#endif
	if( !memcmp(message->customData, gamePass, message->customDataLen))
		{
		if( bGameRunning)
			memcpy( outReason, "\pSorry, Game Running", 200);
		else
			return true;
		}
	else
		memcpy( outReason, "\pPassword Does Not Match", 200);
	
	return false;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Polls all network machines....                                                                                              บ
//บ																                                                                              บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
int Polling_Network()
{
OSStatus status;
NSpMessageHeader *message;

#if DEBUGGING==ON
//	DumpLong( 310, Team_A);
//	DumpLong( 320, Team_B);

	DumpLong( 300, network_on);
	DumpLong( 310, iPlayersMove);
	DumpLong( 320, wConsoleNode);

	DumpLong( 350, NetIds[0]);
	DumpLong( 360, Players[0]);
	DumpLong( 370, NetTeams[0]);
	DumpLong( 380, (PlayerMovements[ 0].X_f1<<16)|PlayerMovements[ 0].Y_f2);

	DumpLong( 400, NetIds[1]);
	DumpLong( 410, Players[1]);
	DumpLong( 420, NetTeams[1]);
	DumpLong( 430, (PlayerMovements[1].X_f1<<16)|PlayerMovements[1].Y_f2);
	
	DumpLong( 450, writeptr);
	DumpLong( 460, readptr);
#endif

	while( (message = NSpMessage_Get( gNetGame)) != NULL)
		{
		switch( message->what)
			{
			case kNSpJoinRequest:
					break;
			case kNSpJoinApproved:
#if NET_DEBUG==ON
	  				fprintf(NetDebugFile, "Join Approved\n");
#endif
					break;
			case kNSpJoinDenied:
#if NET_DEBUG==ON
	  				fprintf(NetDebugFile, "Join Denied\n");
#endif
					NSpGame_Dispose( gNetGame, kNSpGameFlag_ForceTerminateGame);
					gNetGame = NULL;
					Fail( 0x0000, __FILE__, __LINE__, false, ((NSpJoinDeniedMessage *)message)->reason);
					bGameOver = true;
					break;
			case kNSpPlayerJoined:
					ProcessPlayerJoined( (NSpPlayerJoinedMessage *)message);
					break;
			case kNSpPlayerLeft:
					ProcessPlayerLeft( (NSpPlayerLeftMessage *)message);
					break;
			case kNSpHostChanged:
#if NET_DEBUG==ON
	  				fprintf(NetDebugFile, "Host Changed\n");
#endif
					bGameOver = true;
					break;
			case kNSpGameTerminated:
					ProcessGameTerminated( (NSpGameTerminatedMessage *)message);
					break;
			case kNSp_TeamHeader:
					ProcessTeamHeader( (NetMessage *)message);
					break;
			case kNSp_OkayHeader:
#if NET_DEBUG==ON
	  				fprintf(NetDebugFile, "Okay Header\n");
#endif
					break;
			case kNSp_GameEnd:
#if NET_DEBUG==ON
	  				fprintf(NetDebugFile, "Game Over\n");
#endif
					bGameOver = true;
					net_error = -1;
					break;
			case kNSp_PlayerSelect:
					ProcessPlayerSelect( (NetMessage *)message);
					break;
			case kNSp_PlayerReady:
#if NET_DEBUG==ON
	  				fprintf(NetDebugFile, "Player Now Ready\n");
#endif
					iPlayersReady++;
					break;
			case kNSp_StartGame:
#if NET_DEBUG==ON
//	  				printf( "Start Game\n");
	  				fprintf(NetDebugFile, "Start Game\n");
#endif
					bStartGame = true;
					break;
			case kNSp_PlayerData:
					ProcessPlayerData( (NetMessage *)message);
					break;
			case kNSp_RunLoop:
					ProcessRunLoop( (NetMessage *)message);
					break;
			}
		NSpMessage_Release( gNetGame, message);
		}
	wConsoleNode = FindPlayer( NSpPlayer_GetMyID( gNetGame) );
	if( bGameOver)
		in_game = false;

			
	return 1;
}

void ProcessPlayerJoined( NSpPlayerJoinedMessage *message)
{
OSStatus status;
NSpPlayerEnumerationPtr players;
int i;

#if NET_DEBUG==ON
//	printf( "Joined %d\n", message->playerInfo.id);
	fprintf(NetDebugFile, "Player Joined\n");
	fprintf(NetDebugFile, "      Player Count  %d\n", message->playerCount);
	fprintf(NetDebugFile, "      Player Id     %d\n", message->playerInfo.id);
#endif
	for( i=0;i<network_on;i++)
		NetIds[i] = NetTeams[i] = Players[i] = -1;

	status = NSpPlayer_GetEnumeration( gNetGame, &players);
	network_on = 0;
	
	if( status ==noErr)
		{
		for( i=0; i<players->count; i++)
			AddPlayerToList( players->playerInfo[i]->id);
		network_on = players->count;
		}
	else
		CheckNetworkError( status);
	if( bHostFlag)
		SendNETTeamInfo();
}

void ProcessPlayerLeft( NSpPlayerLeftMessage *message)
{
int thisPlayer = FindPlayer( message->playerID);

#if NET_DEBUG==ON
//	printf( "Left %d\n", message->playerID);
	fprintf(NetDebugFile, "Player Left\n");
	fprintf(NetDebugFile, "      Player Count  %d\n", message->playerCount);
	fprintf(NetDebugFile, "      Player Id     %d\n", message->playerID);
#endif
	if( bGameRunning)
		ProcessDeletePlayer( thisPlayer);
	DeletePlayer( message->playerID);
}

void ProcessGameTerminated( NSpGameTerminatedMessage *message)
{
#if NET_DEBUG==ON
//	printf( "Game Over\n");
	fprintf(NetDebugFile, "Game Terminated\n");
#endif
	in_game = false;
}

void ProcessTeamHeader( NetMessage *message)
{
#if NET_DEBUG==ON
//	printf( "Team Header\n");
	fprintf(NetDebugFile, "Team Header\n");
	fprintf(NetDebugFile, "      Team A    %d\n", message->TeamHeader.Team_A);
	fprintf(NetDebugFile, "      Team B    %d\n", message->TeamHeader.Team_B);
	fprintf(NetDebugFile, "      Net Half  %d\n", message->TeamHeader.HalfLength);
	fprintf(NetDebugFile, "      Cd In     %d\n", message->TeamHeader.CdIn);
#endif
	Team_A		= message->TeamHeader.Team_A;
	Team_B		= message->TeamHeader.Team_B;
	net_half	= message->TeamHeader.HalfLength;
	if( message->TeamHeader.CdIn)
		net_cd_in = true;
}

void ProcessPlayerSelect( NetMessage *message)
{
int thisPlayer = FindPlayer( message->header.from);

#if NET_DEBUG==ON
//	printf( "Select %d %d %d\n", message->header.from, message->PlayerSelection.PlayerChoice, message->PlayerSelection.TeamChoice);
	fprintf(NetDebugFile, "Player Select\n");
	fprintf(NetDebugFile, "       Player Id   %d\n", message->header.from);
	fprintf(NetDebugFile, "       Player      %d\n", message->PlayerSelection.PlayerChoice);
	fprintf(NetDebugFile, "       Team        %d\n", message->PlayerSelection.TeamChoice);
#endif

	if( thisPlayer>-1)
		{
		NetTeams[ thisPlayer] = message->PlayerSelection.TeamChoice;
		Players[ thisPlayer] = message->PlayerSelection.PlayerChoice;
		}
}

void ProcessPlayerData( NetMessage *message)
{
int thisPlayer = FindPlayer( message->header.from);

#if NET_DEBUG==ON
//	printf( "Data %d %x %x\n", message->header.from, message->PlayerData.X_f1, message->PlayerData.Y_f2 );
	fprintf(NetDebugFile, "Player Data\n");
	fprintf(NetDebugFile, "       Player Id   %d\n", message->header.from);
	fprintf(NetDebugFile, "       X           %04X\n", message->PlayerData.X_f1);
	fprintf(NetDebugFile, "       Y           %04X\n", message->PlayerData.Y_f2);
#endif
	if( thisPlayer!=-1)
		{
		PlayerMovements[ thisPlayer].X_f1 = message->PlayerData.X_f1;
		PlayerMovements[ thisPlayer].Y_f2 = message->PlayerData.Y_f2;
		iPlayersMove++;
		if( rand_seed != message->GameSeed)
			{
			in_game = false;
			net_error = -2;
			}
		}	
}

void ProcessRunLoop( NetMessage *message)
{
#if NET_DEBUG==ON
	fprintf(NetDebugFile, "Run Loop Of Game\n");
#endif
	ProcessNetMessages( (short *)PlayerMovements);
	iPlayersMove = 0;
}

void NetworkUserControl(void)
{
PlayerData Me;

	get_user_inputs();
	Me.X_f1 = (ProcessX(Inputs.Player1_X, Inputs.Player1_Y) & 0xfffe) | Inputs.Player1_S;
	Me.Y_f2 = (ProcessY(Inputs.Player1_X, Inputs.Player1_Y) & 0xfffe) | Inputs.Player1_P;

	if( bHostFlag)
		{
		while( iPlayersMove < (network_on-1) && network_on>1 && in_game)
			Polling_Network();
		SendPlayerData( &Me);
		SendRunLoop();
		}
	else
		SendPlayerData( &Me);
}

