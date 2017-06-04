enum {	kNSp_TeamHeader = 0x00112233, /*kNSp_GameHeader,*/ kNSp_OkayHeader, /*kNSp_PauseHeader,*/
		kNSp_GameEnd, kNSp_PlayerSelect, kNSp_PlayerReady, kNSp_StartGame, 
		kNSp_PlayerData, kNSp_RunLoop};

typedef struct 	{	BYTE	Team_A;
					BYTE	Team_B;
					BYTE	HalfLength;
					BYTE	CdIn;
				} TeamHeader;
					
typedef struct	{
					BYTE	PlayerChoice;
					BYTE	TeamChoice;	
				} PlayerSelection;

typedef struct	{
					short X_f1;
					short Y_f2;
				} PlayerData;
				
typedef struct  {
				NSpMessageHeader		header;
				short					GameSeed;
				union	{
						TeamHeader		TeamHeader;
						PlayerSelection	PlayerSelection;
						PlayerData		PlayerData;
						};	
				} NetMessage;
				
#if NET_DEBUG==ON
EXTERN void OpenNetDebugFile(void);
EXTERN void CloseNetDebugFile(void);
#endif
EXTERN void Network_Play_Ready(void);
EXTERN void Quit_Network_Play(void);
EXTERN void End_Network_Game(void);
EXTERN int	CheckFORnet(void);
EXTERN void	DeinitialiseNET(int netflag);
EXTERN void	Init_Network_Game(void);
EXTERN void	SendNETTeamInfo(void);
EXTERN void	TickerPause(void);
EXTERN void	SendPlayerChoice(void);
EXTERN void	SendNetOKAY(void);
EXTERN void SendPlayerReady(void);
EXTERN void SendGameStart(void);
EXTERN void SendPlayerData(PlayerData *data);
EXTERN void SendRunLoop( void);
EXTERN int	Polling_Network(void);

EXTERN Boolean HostGame(void);
EXTERN Boolean JoinGame(void);
EXTERN pascal Boolean MyJoinRequestHandler(NSpGameReference inGame, NSpJoinRequestMessage *inMessage, void* inContext, Str255 outReason);

EXTERN void ProcessJoinRequest( NSpPlayerJoinedMessage *message);
EXTERN void ProcessPlayerJoined( NSpPlayerJoinedMessage *message);
EXTERN void ProcessPlayerLeft( NSpPlayerLeftMessage *message);
EXTERN void ProcessGameTerminated( NSpGameTerminatedMessage *message);
EXTERN void ProcessTeamHeader( NetMessage *message);
EXTERN void ProcessPlayerSelect( NetMessage *message);
EXTERN void ProcessPlayerData( NetMessage *message);
EXTERN void ProcessRunLoop( NetMessage *message);

EXTERN void NetworkUserControl(void);

EXTERN Boolean						bGameOver;
EXTERN NSpProtocolReference			atRef;
EXTERN NSpProtocolReference			ipRef;
EXTERN NSpProtocolListReference		protocolList;
EXTERN NSpGameReference				gNetGame;

EXTERN PlayerData PlayerMovements[MAX_NET_USERS];
