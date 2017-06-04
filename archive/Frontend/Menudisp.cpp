#include "Frontend Vars.h"
#include "Menudisp.h"

#undef EXTERN
#define EXTERN extern
#include "2D_routines.h"
#include "Audio.h"
#include "Blitter.h"
#include "Memory.h"
#include "Font.h"
#include "Front Menu.h"
#include "Not Written Yet.h"
#include "Resource.h"
#include "Results.h"
#include "Sprite.h"
#include "Unmangle.h"
#include "Front Variables.h"

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Displays a string in a given font.                                                                                          บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
int DisplaySTRING (char *text,int state)
{
	ShadowXoffset	=	3;
	ShadowYoffset	=	3;

	if	( (state & SFONT)!=0 )
		{
		FontDataADDR		=	sfont_buffer;	
		ItalicFont		=	OFF;
		}

	if	( (state & MFONT)!=0 )
		{
		FontDataADDR		=	mfont_buffer;	
//		if (match_info.menu_res==HI)
				ItalicFont		=	ON;
		}

	if	( (state & BFONT)!=0 )
		{
		FontDataADDR		=	bfont_buffer;	
		ItalicFont		=	ON;

			if	( (state & SILVER_TEXTURE)!=0 )
				TextureSOURCE	=	texture_buffer+(336*19);	
			else
				TextureSOURCE	=	texture_buffer;	
		}

			TextureOffset	=	0;

	if	( (state & RIGHTjustifyTEXT)!=0 )
		TextXposn	= 	TextXposn-(FindLengthOfSTRING( text, NULL, state)); 

	if	( (state & CENTREjustifyTEXT)!=0 )
		TextXposn	= 	TextXposn-((FindLengthOfSTRING( text, NULL, state)/2) ); 

	if 	( (state & BUTTONcentreJUSTIFY)!=0 )
	{
		TextXposn	=	((TextXposn+(sprite84width/2)));
		TextXposn	= 	TextXposn-((FindLengthOfSTRING( text, NULL, state)/2) ); 
	}


		char 	c;

		if	( (state & SHADOWtextON)!=0 )
		{

			long	TemporyX,TemporyY;
			char	*TemporySTRING;
			TemporyX	=	TextXposn;
			TemporyY	=	TextYposn;
			TemporySTRING	=	text;
			LastChar    	=	255;


			c = *(TemporySTRING++);
			while	(c!=0) 	
				{
					if	( (state & CAPS)!=0
						    && c>96 && c<123)
							c	=	c-(97-65);					
				DisplayASCcharShadow(c);
		if	( (state & TIGHTEN)!=0 )
			TextXposn--;

				c = *(TemporySTRING++);
				}




			TextXposn	=	TemporyX;	
			TextYposn	=	TemporyY;	




		}

		int	cposn		=	0;
		int	CursorXoff	=	-1;
		LastChar    		=	255;
		
		c = *(text++);

		while	(c!=0) 	
			{

			if	( (state & CAPS)!=0
				    && c>96 && c<123)
					c	=	c-(97-65);					
		
				if (cposn==CursorXposn)		
				{			
				CursorXoff	=	TextXposn;
				}			 

					if ( (state & CHISEL)==0 )	
						DisplayASCchar(c);
					else
						ChiselASCchar(c);

		if	( (state & TIGHTEN)!=0 )
			TextXposn--;

		if	( (state & CHISEL)!=0 )
			TextXposn	=	TextXposn-3;
	
			c 	=	 *(text++);
			cposn++;
			}

				if (CursorXoff==-1)
				CursorXoff	=	TextXposn;

		return(CursorXoff);
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Sets the pixel length of any given string in any font style, as well as adding an extra given charater if needed.           บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
int FindLengthOfSTRING (char *text, char chr, int state)
{
LastChar    	=	255;
StringLength	=	0;
char	*TempBuffer	=	text;
char c;
		
		if	(chr!=NULL)
		{

			if	( (state & CAPS)!=0
				    && chr>96 && chr<123)
					chr	=	chr-(97-65);					
		get_string_length(chr);			

			if ((state & CHISEL)!=0)
			StringLength	=	StringLength-3;
		}
		
		c = *(TempBuffer++);
		while	(c!=0) 	
		{
			if	( (state & CAPS)!=0
				    && c>96 && c<123)
					c	=	c-(97-65);					

		get_string_length(c);			

			if ((state & CHISEL)!=0)
			StringLength	=	StringLength-3;

		c 	     =	 	*(TempBuffer++);
		}

	return(StringLength);
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Sets up sprite WIDTH, HEIGHT and BITMAP data for any requested sprite.                                                      บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void SetupSpriteDATA (int SpriteNumber)
{
//	if (match_info.menu_res==HI)
	{	
	 	SpriteWIDTH		=	sprite_table[SpriteNumber].spriteWidth;
 		SpriteHEIGHT	=	sprite_table[SpriteNumber].spriteHeight;
	}
//	else
//	{	
//	 	SpriteWIDTH		=	sprite_table_small[SpriteNumber].spriteWidth;
//		SpriteHEIGHT	=	sprite_table_small[SpriteNumber].spriteHeight;
//	}
 

		if (SpriteNumber > (SPOOL_START-1) )
		{
			if ( SpriteNumber != current_spool && SpriteNumber<BIG_FLAG )
			{

//			if (match_info.menu_res==HI)
				UnMangleMemToMem ( spool_buffer+( spool_index[(SpriteNumber-SPOOL_START) ]) , unpack_buffer );			
//			else
//				UnMangleMemToMem ( spool_buffer+( spool_index_small[(SpriteNumber-SPOOL_START) ]) , unpack_buffer );			

			current_spool = SpriteNumber;

				if (1)
					UpdateMusic();
			}

			if ( SpriteNumber>=BIG_FLAG )
			{

				if (match_info.menu_res==HI)
				{
				LoadBinaryDirect( unpack_buffer, RESTYPE_DATA, NORMRES(game_data[SpriteNumber-BIG_FLAG].big_flag));
// Load_data
// English, French		game_data[SpriteNumber-BIG_FLAG].big_flag,	"DATA.DAT",		unpack_buffer
// Norwegian			game_data[SpriteNumber-BIG_FLAG].big_flag,	"NORWAY.DAT",	unpack_buffer
// German				game_data[SpriteNumber-BIG_FLAG].big_flag,	"RANDATA.DAT",	unpack_buffer
// American, Canadian	game_data[SpriteNumber-BIG_FLAG].big_flag,	"VRDATA.DAT",	unpack_buffer

				SpriteNumber		=	BIG_FLAG;
				current_spool 		= 	NULL;
 				SpriteWIDTH			=	sprite_table[SpriteNumber].spriteWidth;
			 	SpriteHEIGHT		=	sprite_table[SpriteNumber].spriteHeight;
				if (1)
					UpdateMusic();
				}
//				else	
//				{
//				LoadBinaryDirect( unpack_buffer, RESTYPE_DATA, NORMRES(game_data[SpriteNumber-BIG_FLAG].big_flag+(45*8)));
//// Load_data
//// English, French		game_data[SpriteNumber-BIG_FLAG].big_flag+(45*8),	"DATA.DAT",		unpack_buffer
//// Norwegian			game_data[SpriteNumber-BIG_FLAG].big_flag+(45*8),	"NORWAY.DAT",	unpack_buffer
//// German				game_data[SpriteNumber-BIG_FLAG].big_flag+(45*8),	"RANDATA.DAT",	unpack_buffer
//// American, Canadian	game_data[SpriteNumber-BIG_FLAG].big_flag+(45*8),	"VRDATA.DAT",	unpack_buffer
//
//				SpriteNumber		=	BIG_FLAG;
//				current_spool 		= 	NULL;
//				SpriteWIDTH			=	sprite_table_small[SpriteNumber].spriteWidth;
//			 	SpriteHEIGHT		=	sprite_table_small[SpriteNumber].spriteHeight;
//				}

			}
			
		
//			if (match_info.menu_res==HI)
			 	SpriteBITMAP		=	unpack_buffer+sprite_table[SpriteNumber].spriteOffset;	
//			else
//			 	SpriteBITMAP		=	unpack_buffer+sprite_table_small[SpriteNumber].spriteOffset;	
		}
	
	else

		{	
//			if (match_info.menu_res==HI)
			 	SpriteBITMAP		=	sprite_buffer+sprite_table[SpriteNumber].spriteOffset;	
//			else
//			 	SpriteBITMAP		=	sprite_buffer+sprite_table_small[SpriteNumber].spriteOffset;	
		}


}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Display a row of stars, used as skill representation, depending on value entered with.                                      บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void DisplaySTARstats (int value)
{
	int	counter 	=	(value/5);
	int	ColCount	=	0;
	int	Star_Char	=	STAR_CHAR;
	FontDataADDR		=	sfont_buffer;	
	ItalicFont		=	OFF;

	while	(counter!=0) 	
		{
		DisplayASCchar(Star_Char); 	       
		counter--;

		ColCount++;

			if ( ColCount==8)
				Star_Char++;
			if ( ColCount==15)
				Star_Char++;
		}
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Display all sprites which are associated with current selected menu.                                                        บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
//
void	Display_Sprites(int menu_number)
{
int	TempSPRno;	
int	spritenum;									   
menu *thisMenu = &menu_data[ menu_number];

	DisplayDESTINATION	=	psudo_buffer;	

	for (spritenum = 0; spritenum < MAX_SPRITES; spritenum++)
	{

		Sprite		=	OFF;
		TempSPRno	=	NULL;

		if ( (thisMenu->SpriteTABLE[spritenum].sprite_state & ACTIVE)!=0)
		{
	
			if ( (thisMenu->SpriteTABLE[spritenum].sprite_state & FREEZE)==0)
			{
								
			tempFrame	=	(thisMenu->SpriteTABLE[spritenum].FrameCounter +
						  thisMenu->SpriteTABLE[spritenum].FrameSpeed);

			if (tempFrame >= thisMenu->SpriteTABLE[spritenum].NoOfFrames)				  
			tempFrame-=	 thisMenu->SpriteTABLE[spritenum].NoOfFrames;

			thisMenu->SpriteTABLE[spritenum].FrameCounter = tempFrame;
			}

			else	
		
			tempFrame	=	0;

			TempSPRno	=    	GetSPRITEnumber( thisMenu->SpriteTABLE[spritenum].sprite_type,
						spritenum,
						thisMenu->SpriteTABLE[spritenum].LastSpriteNo ); 

	 					
			thisMenu->SpriteTABLE[spritenum].NewSpriteFrame	=	TempSPRno;


		}


		if ( ((thisMenu->SpriteTABLE[spritenum].sprite_state & ACTIVE)==0 &&
		      (thisMenu->SpriteTABLE[spritenum].sprite_state & OLD_SPRITE_FLAG)!=0)
			|| Sprite==ON && (thisMenu->SpriteTABLE[spritenum].sprite_state & OLD_SPRITE_FLAG)!=0)

		 	{
			CopyXposn	=	thisMenu->SpriteTABLE[spritenum].CopyAreaX;
			CopyYposn	=	thisMenu->SpriteTABLE[spritenum].CopyAreaY;		
			CopyWIDTH	=	thisMenu->SpriteTABLE[spritenum].CopyWidth;			
			CopyHEIGHT	=	thisMenu->SpriteTABLE[spritenum].CopyHeight;			
			thisMenu->SpriteTABLE[spritenum].sprite_state&= (65535-OLD_SPRITE_FLAG);

//			if (match_info.menu_res==LO)	
//			{
//				CopyHEIGHT*=	2;
//				CopyWIDTH*=	2;
//			}

			RestorePSUDObuffer();
			Add_to_copy_list(
			CopyXposn,
			CopyYposn,
			CopyWIDTH, 
			CopyHEIGHT
			);
		       	thisMenu->SpriteTABLE[spritenum].LastSpriteNo	=	NULL;
			}

			if ( Sprite==ON && TempSPRno!=NULL )
				thisMenu->SpriteTABLE[spritenum].sprite_state|=	SpriteON;
			else
				thisMenu->SpriteTABLE[spritenum].sprite_state&=	65535-SpriteON;

	}




	for (spritenum = 0; spritenum < MAX_SPRITES; spritenum++)
		{
		if ( (thisMenu->SpriteTABLE[spritenum].sprite_state & ACTIVE)!=0 && (thisMenu->SpriteTABLE[spritenum].sprite_state & SpriteON)!=0)
			{		
			SpriteXposn		=	thisMenu->SpriteTABLE[spritenum].sprite_xposn;		
			SpriteYposn		=	thisMenu->SpriteTABLE[spritenum].sprite_yposn;		
			ShadowXoffset	=	thisMenu->SpriteTABLE[spritenum].spriteShadow_xposn;		
			ShadowYoffset	=	thisMenu->SpriteTABLE[spritenum].spriteShadow_yposn;		

 			SetupSpriteDATA( thisMenu->SpriteTABLE[spritenum].NewSpriteFrame ); 

			if ((thisMenu->SpriteTABLE[spritenum].sprite_flags & SMALL)!=0)
				{  
				if ((thisMenu->SpriteTABLE[spritenum].sprite_flags & SHADOW)!=0)
					{
					DrawSmallSPRITEshadow();
					ShadowXoffset	=	0;
					}
				DrawSmallSPRITE();
				SpriteWIDTH	 = SpriteWIDTH>>1;
				SpriteHEIGHT = SpriteHEIGHT>>1;
				}
			else
				{
				if ((thisMenu->SpriteTABLE[spritenum].sprite_flags & SHADOW)!=0)
					DrawSPRITEshadow();
				DrawSPRITE();
				}

			int	temp_hi,temp_wd;
			
			if ( match_info.menu_res==HI )
				{
				temp_wd	= (SpriteWIDTH+ShadowXoffset);
				temp_hi = (SpriteHEIGHT+ShadowYoffset);
				}
			else
				{
				temp_wd = SpriteWIDTH+(ShadowXoffset/2);
				temp_hi = 2;	//SpriteHEIGHT+(ShadowYoffset/2);
				}

			Add_to_copy_list( SpriteXposn, SpriteYposn, temp_wd, temp_hi);


			thisMenu->SpriteTABLE[spritenum].sprite_state 	   |= OLD_SPRITE_FLAG;
			thisMenu->SpriteTABLE[spritenum].CopyAreaX			=	SpriteXposn;
			thisMenu->SpriteTABLE[spritenum].CopyAreaY			=	SpriteYposn;
			thisMenu->SpriteTABLE[spritenum].CopyWidth			=	temp_wd;		// SpriteWIDTH+ShadowXoffset;

			if (match_info.menu_res==HI)	
				thisMenu->SpriteTABLE[spritenum].CopyHeight	=	temp_hi;		// SpriteHEIGHT+ShadowYoffset;
			else
				thisMenu->SpriteTABLE[spritenum].CopyHeight	=	SpriteHEIGHT+(ShadowYoffset/2);

			thisMenu->SpriteTABLE[spritenum].LastSpriteNo		=	thisMenu->SpriteTABLE[spritenum].NewSpriteFrame; 
			}
 		}
}


//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Animate selector buttons.                                                                                                   บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Animate_Buttons(int menu_number)
{
int	TempSPRno	=	NULL;
menu *thisMenu = &menu_data[ menu_number];

	DisplayDESTINATION	=	psudo_buffer;	
	DisplaySOURCE		=	background_buffer;	

	for (int buttonnum = 0; buttonnum < MAX_BUTTONS; buttonnum++)
		{
		if ( ((thisMenu->ButtonLIST[buttonnum].button_flags & ACTIVE)==0) &&
		      ((thisMenu->ButtonLIST[buttonnum].button_flags & OLD_SPRITE_FLAG)!=0) )
			{
			CopyXposn	=	thisMenu->ButtonLIST[buttonnum].button_xposn;
			CopyYposn	=	thisMenu->ButtonLIST[buttonnum].button_yposn;		
			CopyWIDTH	=	thisMenu->ButtonLIST[buttonnum].CopyWidth + thisMenu->ButtonLIST[buttonnum].buttonShadow_xposn;		
			CopyHEIGHT	=	thisMenu->ButtonLIST[buttonnum].CopyHeight+ thisMenu->ButtonLIST[buttonnum].buttonShadow_yposn;		
			thisMenu->ButtonLIST[buttonnum].button_flags&= (65535-OLD_SPRITE_FLAG);
			RestorePSUDObuffer();
			Add_to_copy_list( CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
	       	thisMenu->ButtonLIST[buttonnum].LastButtonNo	=	NULL;
			}

		if ( (thisMenu->ButtonLIST[buttonnum].button_flags & ACTIVE)!=0)
			{		
	       
			SpriteXposn		= thisMenu->ButtonLIST[buttonnum].button_xposn;		
			SpriteYposn		= thisMenu->ButtonLIST[buttonnum].button_yposn;		
			ShadowXoffset	= thisMenu->ButtonLIST[buttonnum].buttonShadow_xposn;		
			ShadowYoffset	= thisMenu->ButtonLIST[buttonnum].buttonShadow_yposn;		

			if ( (thisMenu->ButtonLIST[buttonnum].button_flags & FREEZE)==0)
				{
				tempFrame	=	(thisMenu->ButtonLIST[buttonnum].FrameCounter + thisMenu->ButtonLIST[buttonnum].FrameSpeed);
				if (tempFrame >= thisMenu->ButtonLIST[buttonnum].NoOfFrames)				  
					tempFrame-=	 thisMenu->ButtonLIST[buttonnum].NoOfFrames;
				thisMenu->ButtonLIST[buttonnum].FrameCounter = tempFrame;
				}
			else	
				tempFrame	=	0;

			TempSPRno = (tempFrame >>8) + (GetBUTTONnumber(thisMenu->ButtonLIST[buttonnum].button_type, 
						 thisMenu->ButtonLIST[buttonnum].button_index, thisMenu->ButtonLIST[buttonnum].button_flags));

			if ( TempSPRno!=thisMenu->ButtonLIST[buttonnum].LastButtonNo &&
			      (thisMenu->ButtonLIST[buttonnum].button_flags & INVISIBLE)==0)
				{
				SetupSpriteDATA(TempSPRno); 
			
				if ( (thisMenu->ButtonLIST[buttonnum].button_flags & OLD_SPRITE_FLAG)!=0
				     ||	(thisMenu->ButtonLIST[buttonnum].button_flags & REMOVE)!=0
					)
				 	{
					CopyXposn	=	thisMenu->ButtonLIST[buttonnum].button_xposn;
					CopyYposn	=	thisMenu->ButtonLIST[buttonnum].button_yposn;		
					CopyWIDTH	=	thisMenu->ButtonLIST[buttonnum].CopyWidth + thisMenu->ButtonLIST[buttonnum].buttonShadow_xposn;		
					CopyHEIGHT	=	thisMenu->ButtonLIST[buttonnum].CopyHeight+ thisMenu->ButtonLIST[buttonnum].buttonShadow_yposn;		
					thisMenu->ButtonLIST[buttonnum].button_flags&= (65535-OLD_SPRITE_FLAG);
					RestorePSUDObuffer();
					Add_to_copy_list( CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT );
					}

				if	((thisMenu->ButtonLIST[buttonnum].button_flags & SMALL)!=0)
					{  
					DrawSmallSPRITEshadow();
					DrawSmallSPRITE();
					SpriteWIDTH	=	SpriteWIDTH/2;
					}
				else
					{
			       	DrawSPRITEshadow();
					DrawSPRITE();
					}


				if	(thisMenu->ButtonLIST[buttonnum].button_text!=NULL)
					{
					FontDataADDR		=	bfont_buffer;	
					ItalicFont		=	ON;
					TiltFRAME		=	NULL;
					if	((thisMenu->ButtonLIST[buttonnum].button_flags & STANDARD_BUTTON)!=0)
						TextXposn	=	(thisMenu->ButtonLIST[buttonnum].button_xposn+(sprite84width/2))-2;								
					if	((thisMenu->ButtonLIST[buttonnum].button_flags & MINI_BUTTON)!=0)
						TextXposn	=	(thisMenu->ButtonLIST[buttonnum].button_xposn+( (sprite99width-4)/2));								
					TextXposn-=	( (FindLengthOfSTRING( GetSTRING(thisMenu->ButtonLIST[buttonnum].button_text,NULL), NULL,
				 	SHADOWtextOFF|BFONT|CHISEL )) /2);
					TextYposn	=	thisMenu->ButtonLIST[buttonnum].button_yposn;		
					if (thisMenu->ButtonLIST[buttonnum].button_type==SPIN_BUTTON)
						{
						TextYposn+=	spin_y_offsets[thisMenu->ButtonLIST[buttonnum].button_index];
						TiltFRAME =	thisMenu->ButtonLIST[buttonnum].button_index*4;	
						}
					DisplaySTRING( GetSTRING(thisMenu->ButtonLIST[buttonnum].button_text,NULL), (SHADOWtextOFF|BFONT|CHISEL) );
					}

		    	Add_to_copy_list( SpriteXposn, SpriteYposn, SpriteWIDTH, SpriteHEIGHT);
				thisMenu->ButtonLIST[buttonnum].button_flags|= OLD_SPRITE_FLAG;
				thisMenu->ButtonLIST[buttonnum].LastButtonNo	=	TempSPRno;
				}
			}


			if ( (thisMenu->ButtonLIST[buttonnum].button_type==SPIN_BUTTON
       			    && (thisMenu->ButtonLIST[buttonnum].button_flags & START_SPIN)!=0)

			    || (thisMenu->ButtonLIST[buttonnum].button_type==SPIN_BUTTON 				
			       && (thisMenu->ButtonLIST[buttonnum].button_flags & HALF_SPIN)!=0
				&& thisMenu->ButtonLIST[buttonnum].button_index < 8)
		
			    || (thisMenu->ButtonLIST[buttonnum].button_type==SPIN_BUTTON 				
			       && thisMenu->ButtonLIST[buttonnum].button_index !=0
				&& (thisMenu->ButtonLIST[buttonnum].button_flags & HALF_SPIN)==0)
				)

			{
				if ((thisMenu->ButtonLIST[buttonnum].button_flags & BACK_SPIN)==0)
				{
					thisMenu->ButtonLIST[buttonnum].button_index+=	2; 
					

					if (thisMenu->ButtonLIST[buttonnum].button_index > 14) 
					{
					thisMenu->ButtonLIST[buttonnum].button_index	=	0; 
					 thisMenu->ButtonLIST[buttonnum].button_flags&=		65535-HALF_SPIN;

						if ( (thisMenu->ButtonLIST[buttonnum].button_flags & SINGLE_SPIN)!=0)
							thisMenu->ButtonLIST[buttonnum].button_flags&=		65535-START_SPIN;
					}			
				}


				if ((thisMenu->ButtonLIST[buttonnum].button_flags & BACK_SPIN)!=0)
				{
					thisMenu->ButtonLIST[buttonnum].button_index-=	2; 

					if (thisMenu->ButtonLIST[buttonnum].button_index < 0) 
					{
					thisMenu->ButtonLIST[buttonnum].button_index	=	14; 
				     	}
						if (thisMenu->ButtonLIST[buttonnum].button_index	==	0) 
						{
						thisMenu->ButtonLIST[buttonnum].button_flags&=		65535-HALF_SPIN;
						if ( (thisMenu->ButtonLIST[buttonnum].button_flags & SINGLE_SPIN)!=0)
							thisMenu->ButtonLIST[buttonnum].button_flags&=		65535-START_SPIN;
						}
				}

		       	thisMenu->ButtonLIST[buttonnum].LastButtonNo	=	NULL;
			}
		
			if	(thisMenu->ButtonLIST[buttonnum].button_type==SLIDE_BAR)
				{
				thisMenu->SpriteTABLE[buttonnum].LastSpriteNo	=	NULL;

				CopyXposn	=	thisMenu->ButtonLIST[buttonnum].button_xposn+SLIDE_BAR_XOFF;
				CopyYposn	=	thisMenu->ButtonLIST[buttonnum].button_yposn+SLIDE_BAR_YOFF;		
				CopyWIDTH	=	SLIDE_BAR_WIDTH+2;
				CopyHEIGHT	=	SLIDE_BAR_HEIGHT+1;
				RestorePSUDObuffer();

				thisMenu->SpriteTABLE[buttonnum].sprite_xposn	=	
				thisMenu->ButtonLIST[buttonnum].button_xposn+SLIDE_BAR_XOFF+
				thisMenu->ButtonLIST[buttonnum].button_index-5;

				Add_to_copy_list( CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
				}
	}
}

static int BlocksToCopy = 0;

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Copy images from pusdo to actual screen using a copy list.                                                                  บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Dump_copy_list()
{
short *data = (short *)&copy_list[0];
	
	for (int listnum = 0; listnum < BlocksToCopy; listnum++)
		{
		CopyXposn = *data++;
		CopyYposn = *data++;
		CopyWIDTH = *data++;
		CopyHEIGHT = *data++;
		BlockCopy( (char *) psudo_buffer+((DisplayWidth*CopyYposn)+CopyXposn),
											CopyXposn , CopyYposn, CopyWIDTH , CopyHEIGHT);		
#if DEBUGGING==ON
//		_setcolor( 204);
//		_moveto( CopyXposn, CopyYposn);
//		_lineto( CopyXposn + CopyWIDTH, CopyYposn);
//		_lineto( CopyXposn + CopyWIDTH, CopyYposn + CopyHEIGHT);
//		_lineto( CopyXposn, CopyYposn + CopyHEIGHT);
//		_lineto( CopyXposn, CopyYposn );
#endif
		}

#if DEBUGGING==ON
	DumpLong(240, BlocksToCopy);
#endif

	BlocksToCopy = 0;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Adds an entry to copy down list.                                                                  				 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Add_to_copy_list(short X,short Y,short W,short H)
{
	copy_list[BlocksToCopy].CopyAreaX	=	X;
	copy_list[BlocksToCopy].CopyAreaY	=	Y;
	copy_list[BlocksToCopy].CopyWidth	=	W;
	copy_list[BlocksToCopy++].CopyHeight	=	H;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Clears all copy list entries.                                                                  				 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Clear_copy_list()
{
	BlocksToCopy = 0;
}




//===================================================


void	DisplayPROPORTION()
{
//		CopyXposn	=	0;
//		CopyYposn	=	460;
//		CopyWIDTH	=	50;
//		CopyHEIGHT	=	19;
//		RestorePSUDObuffer();
//
//	if (proportional_change==1)
//	{
//		TextXposn	=	0;
//		TextYposn	=	460;
//
//		char	*Prop	=	"AA";
//		Prop[0]	=	PropA+32;
//		Prop[1]	=	PropB+32;
//		DisplaySTRING	(Prop,MFONT);		
//
//	}
//	    	Add_to_copy_list(
//		0,460,50,19);
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Control slider bars.                                                                                                        บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Control_Sliders(int menu_number)
{
int	TempSPRno	=	NULL;
menu *thisMenu = &menu_data[menu_number];

	DisplayDESTINATION	=	psudo_buffer;	
	DisplaySOURCE		=	background_buffer;	

	for (int buttonnum = 0; buttonnum < MAX_BUTTONS; buttonnum++)
		{
		if	(thisMenu->ButtonLIST[buttonnum].button_type==SLIDE_BAR)
			{
			thisMenu->SpriteTABLE[buttonnum].LastSpriteNo	=	NULL;

			FloodXposn	=	thisMenu->ButtonLIST[buttonnum].button_xposn+SLIDE_BAR_XOFF;
			FloodYposn	=	thisMenu->ButtonLIST[buttonnum].button_yposn+SLIDE_BAR_YOFF;		
			FloodWIDTH	=	thisMenu->ButtonLIST[buttonnum].button_index;
			FloodHEIGHT	=	SLIDE_BAR_HEIGHT;
			FloodCOLOUR	=	(int) (FloodWIDTH/(200/28)+((6*16)-1));

			thisMenu->SpriteTABLE[buttonnum].sprite_xposn = (FloodXposn+FloodWIDTH)-8;
			if (FloodWIDTH>5)
				{ 
				FloodWIDTH-=	5;
				FloodAREA();
				}
			Add_to_copy_list( CopyXposn, CopyYposn, CopyWIDTH, CopyHEIGHT);
			}
		}
}
