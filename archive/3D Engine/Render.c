#include "Mac Vars.h"

/********************************************************/
/*       3D ENGINE - Rendering Routines   17/1/95       */
/********************************************************/

//	Lines:
// 	Flat algorithm.
// Polygons:
// 	Flat, Filtered, Texture map, Transparent texture map
// 	and Gourad shading algorithms.
#define POLYGONIZE	0

#define POLY
#define POLYB
#define POLYF
#undef POLYG
#define POLYM
#define POLYL
#define POLYT
#undef POLYQ

/********************* HEADER FILES *********************/

#include <string.h>

#include "3deng.h"
#include "render.h"

#if USERAVEENGINE==YES
#include "Rave.h"
#include "RAGE Starter Code.h"
#endif

#undef EXTERN
#define EXTERN extern
#include "Blitter.h"
#include "Palette.h"
#include "RAGE Line Clipping.h"
#include "RAGE Polygon Clipping.h"

extern Boolean UseRaveEngine, Frontend;

extern filter *filters;

extern void hlinm(BYTE *scr, long w1);
extern void hlint(BYTE *scr, long w1);
extern void hlinl(BYTE *scr, long w1);

#include "8086 To PPC.h"
#include "3deng.h"

#define EXTERN extern
#include "2D_Routines.h"

static dword pxy[5]={ 0 };
static BYTE *data;

static VECTOR2D destVect[8];
static VECTOR2D dest2Vect[8];

static UVMAP defuvmap[ 4] = { { 0.0, 1.0}, { 1.0, 1.0}, { 1.0, 0.0}, { 0.0, 0.0} };
static UVMAP destuvMap[ 8];
static UVMAP destuvMap2[ 8];
static UVMAP srcuvMap[8];

static POLYGON src;
static POLYGON dest;
static POLYGON dest2;

#define BLANK		1

#if USERAVEENGINE==YES
typedef BYTE mappage[256*256];
extern mappage		*maps;

static TQATexture *FindTexture( BYTE *where)
{
int a=0;

	while( a<10)
		{
		if( maps[a] == where)
			return Texture_Maps[a];
		a++;
		}

	return Texture_Maps[10];
}
#endif

#ifdef __POWERPC__
asm void hlinm(BYTE *scr, long w1)
{
	lwz	r3, pxy
	lwz	EDX, 6(r3)	// edx
	lwz	EBX, 2(r3)	// ebx
	lwz	TEMP1, 10(r3)
	rlwimi	EBX, TEMP1, 0, 0, 15
	lwz	ESI, 14(r3)	// es1
	lwz	ECX, 10(r3)	// ecx
	lwz	TEMP1, 16(r3)
	rlwimi	ECX, TEMP1, 16, 0, 15

	lwz	SCREEN, scr
	lwz	TEMP0, w1
	lwz	DATA, data

	SUBBXCX(TEMP1, TEMP2)
	ADDEBXECX
	MOVBHDL
	ZEROCH(TEMP1)
	ADCDLCH(TEMP1)

@one
	TEST(TEMP1, SCREEN, 0x0003)
	beq	@not1

	MOVXBX(EAX)
	ADDEDXESI
	ADCEBXECX
	MOVBHDL
	ADCDLCH(TEMP1)
	stbu	EAX, -1(SCREEN)
	addi	TEMP0, TEMP0, -1
	cmpi	cr0, 0, TEMP0, 0
	beq	@less1
	b 	@one
@not1
	b @lpp1
@lpp	
	MOVXBX(EAX)
	ADDEDXESI
	ADCEBXECX
	MOVBHDL
	MOVXBX(TEMP1)
	MOVAH(TEMP1)
	ADCEDXESI
	ADCEBXECX
	MOVBHDL
	MOVXBX(TEMP1)
	MOVEAXL(TEMP1)
	ADCEDXESI
	ADCEBXECX
	MOVBHDL
	MOVXBX(TEMP1)
	MOVEAXH(TEMP1)
	ADCEDXESI
	ADCEBXECX
	MOVBHDL
	ADCDLCH(TEMP1)
	stwu	EAX, -4(SCREEN)
	addi	TEMP0,TEMP0, -4
@lpp1
	cmpi	cr0, 0, TEMP0, 4
	bge	@lpp
@less4
	cmpi	cr0, 0, TEMP0, 2
	blt	@less2
	MOVXBX(EAX)
	ADDEDXESI
	ADCEBXECX
	MOVBHDL
	MOVXBX(TEMP1)
	MOVAH(TEMP1)
	ADCEDXESI
	ADCEBXECX
	MOVBHDL
	ADCDLCH(TEMP1)
	sthu	EAX, -2(SCREEN)
	addi	TEMP0, TEMP0, -2
@less2	
	cmpi	cr0, 0, TEMP0, 1
	blt	@less1
	MOVXBX(EAX)
	stb	EAX,-1(SCREEN)
@less1
	blr
}

asm void hlint(BYTE *scr, long w1)
{
	lwz	r3, pxy
	lwz	EDX, 6(r3)	// edx
	lwz	EBX, 2(r3)	// ebx
	lwz	TEMP1, 10(r3)
	rlwimi	EBX, TEMP1, 0, 0, 15
	lwz	ESI, 14(r3)	// es1
	lwz	ECX, 10(r3)	// ecx
	lwz	TEMP1, 16(r3)
	rlwimi	ECX, TEMP1, 16, 0, 15

	lwz	SCREEN, scr
	lwz	TEMP0, w1
	lwz	DATA, data
	SUBBXCX(TEMP1, TEMP2)
	ADDEBXECX
	MOVBHDL
	ZEROCH(TEMP1)
	ADCDLCH(TEMP1)

@one
	TEST(TEMP1, SCREEN, 0x0003)
	beq	@not1

	addi	SCREEN, SCREEN, -1

	MOVXBX(EAX)
	cmpi	cr0, 0, EAX, BLANK
	beq	@l1
	addi	EAX, EAX, -1
	stb	EAX, 0(SCREEN)
@l1
	ADDEDXESI
	ADCEBXECX
	MOVBHDL
	ADCDLCH(TEMP1)
	
	addi	TEMP0, TEMP0, -1
	cmpi	cr0, 0, TEMP0, 0
	beq	@less1
	b	@one
@not1
//	TEST(TEMP1, SCREEN, 0x0002)
//	beq	@not2
//
//	addi	SCREEN, SCREEN, -2
//	addi	TEMP0, TEMP0, -2
//	
//	MOVXBX(EAX)
//	cmpi	cr0, 0, EAX, 1
//	beq	@l2
//	addi	EAX, EAX, -1
//	stb	EAX, 1(SCREEN)
//@l2
//	ADDEDXESI
//	ADCEBXECX
//	MOVBHDL
//	MOVXBX(EAX)
//	cmpi	cr0, 0, EAX, 1
//	beq	@l3
//	addi	EAX, EAX, -1
//	stb	EAX, 0(SCREEN)
//@l3
//	ADCEDXESI
//	ADCEBXECX
//	MOVBHDL
//	ADCDLCH(TEMP1)
@not2	
	cmpi	cr0, 0, TEMP0, 4
	blt	@less4
	
	addi	SCREEN, SCREEN , -4
	addi	TEMP0, TEMP0, -4
	
	MOVXBX(EAX)
	cmpi	cr0, 0, EAX, BLANK
	beq	@l4
	addi	EAX, EAX, -1
	stb	EAX, 3(SCREEN)
@l4
	ADDEDXESI
	ADCEBXECX
	MOVBHDL
	MOVXBX(EAX)
	cmpi	cr0, 0, EAX, BLANK
	beq	@l5
	addi	EAX, EAX, -1
	stb	EAX, 2(SCREEN)
@l5
	ADCEDXESI
	ADCEBXECX
	MOVBHDL
	MOVXBX(EAX)
	cmpi	cr0, 0, EAX, BLANK
	beq	@l6
	addi	EAX, EAX, -1
	stb	EAX, 1(SCREEN)
@l6
	ADCEDXESI
	ADCEBXECX
	MOVBHDL
	MOVXBX(EAX)
	cmpi	cr0, 0, EAX, BLANK
	beq	@l7
	addi	EAX, EAX, -1
	stb	EAX, 0(SCREEN)
@l7
	ADCEDXESI
	ADCEBXECX
	MOVBHDL
	ADCDLCH(TEMP1)
	b	@not2

@less4
	cmpi	cr0, 0, TEMP0, 2
	blt	@less2

	addi	SCREEN, SCREEN, -2
	addi	TEMP0, TEMP0, -2
	
	MOVXBX(EAX)
	cmpi	cr0, 0, EAX, BLANK
	beq	@l8
	addi	EAX, EAX, -1
	stb	EAX, 1(SCREEN)
@l8
	ADDEDXESI
	ADCEBXECX
	MOVBHDL
	MOVXBX(EAX)
	cmpi	cr0, 0, EAX, BLANK
	beq	@l9
	addi	EAX, EAX, -1
	stb	EAX, 0(SCREEN)
@l9
	ADCEDXESI
	ADCEBXECX
	MOVBHDL
	ADCDLCH(TEMP1)
	
@less2	
	cmpi	cr0, 0, TEMP0, 1
	blt	@less1

	MOVXBX(EAX)
	cmpi	cr0, 0, EAX, BLANK
	beq	@less1
	addi	EAX, EAX, -1
	stb	EAX, -1(SCREEN)
@less1
	blr
}

asm void hlinl(BYTE *scr, long w1)
{
	blr
}

#endif



/********************* EXTERNAL VARS ********************/

extern buff_info_ext render_buff;	// Extended info for rendering buffer



/********************* FUNCTION CODE ********************/

/********/
/* LINE */


void line(pnt *pts, word col)
{
#if USERAVEENGINE==YES
TQAVGouraud v[2];

	for ( int i=0; i<2 ; i++ )
		{
		v[i].x = pts[i].x;
		v[i].y = 479.0-pts[i].y;
		v[i].z = 0.0;
		v[i].invW = 1.0;
		v[i].r = ((palette_buffer16[col]>>10)&31)*(1.0/31.0);
		v[i].g = ((palette_buffer16[col]>>5 )&31)*(1.0/31.0);
		v[i].b = (palette_buffer16[col]&31)*(1.0/31.0);
		v[i].a = 1.0;
		}
	if( RAGE_ClipLine( &v[0].x, &v[0].y, &v[1].x, &v[1].y) != LINE_INVISIBLE)
		QADrawLine (gTheContext, &v[0], &v[1]);
#else
scrpt x1=pts[0].x,y1=pts[0].y,x2=pts[1].x,y2=pts[1].y;
scrpt	dx,dy,tx,ty;
dword_u ls;
dword ld;
BYTE *sc;

	ls.dw=0;
	if (x2>=x1)
		{
		dx=x2-x1+1;
		if (y2>=y1)
			{
			dy=y2-y1+1;
			if (dx>=dy)
				{			
				ld=(dx ? ((dword)dy<<16)/dx : 0);
				if ((unsigned)x1>=render_buff.clip_wid)
					if (x1>=0||x2<0) return; else {ls.dw=-x1*ld;y1+=ls.d.hiw;ls.d.hiw=0;x1=0;dx=x2+1;} 	
				if ((unsigned)y1>=render_buff.clip_hgt)
					if (y1>=0||y2<0) return; else {x1-=(tx=(((dword)y1<<16)+ls.dw+1)/ld-1);ls.dw-=tx*ld;y1=ls.d.hiw=0;dx+=tx;}
				sc=render_buff.clip_end+x1-y1*render_buff.buff_wid;
				if (x2>=render_buff.clip_wid) 
					{dx=render_buff.clip_wid-x1; if (y2>=render_buff.clip_hgt && (dy=(((dword)(render_buff.clip_hgt-y1)<<16)-ls.dw-1)/ld+1)<dx) dx=dy;}
				else
					if (y2>=render_buff.clip_hgt) dx=(((dword)(render_buff.clip_hgt-y1)<<16)-ls.dw-1)/ld+1;
				while	(--dx>=0)
					{*((sc++)-ls.d.hiw*render_buff.buff_wid)=col;ls.dw+=ld;}
				}
			else
				{
				ld=((dword)dx<<16)/dy;
				if ((unsigned)y1>=render_buff.clip_hgt)
					if (y1>=0||y2<0) return; else {ls.dw=-y1*ld;x1+=ls.d.hiw;ls.d.hiw=0;y1=0;dy=y2+1;}
				if ((unsigned)x1>=render_buff.clip_wid)
					if (x1>=0||x2<0) return; else {y1-=(ty=(((dword)x1<<16)+ls.dw+1)/ld-1);ls.dw-=ty*ld;x1=ls.d.hiw=0;dy+=ty;} 	
				sc=render_buff.clip_end+x1-y1*render_buff.buff_wid;
				if (x2>=render_buff.clip_wid) 
					{dy=(((dword)(render_buff.clip_wid-x1)<<16)-ls.dw-1)/ld+1; if (y2>=render_buff.clip_hgt && (dx=render_buff.clip_hgt-y1)<dy) dy=dx;}
				else
					if (y2>=render_buff.clip_hgt) dy=render_buff.clip_hgt-y1;
				while	(--dy>=0)
					{*(sc+ls.d.hiw)=col;sc-=render_buff.buff_wid;ls.dw+=ld;}
				}
			}
		else		
			{
			dy=y1-y2+1;
			if (dx>=dy)
				{
				ld=((dword)dy<<16)/dx;
				if ((unsigned)x1>=render_buff.clip_wid)
					if (x1>=0||x2<0) return; else {ls.dw=-x1*ld;y1-=ls.d.hiw;ls.d.hiw=0;x1=0;dx=x2+1;} 	
				if ((unsigned)y1>=render_buff.clip_hgt)
					if (y1<0||y2>=render_buff.clip_hgt) return; 
					else {x1+=(tx=(((dword)(y1-render_buff.clip_hgtl)<<16)-ls.dw-1)/ld+1);ls.dw+=tx*ld;y1=render_buff.clip_hgtl;ls.d.hiw=0;dx-=tx-1;}
				sc=render_buff.clip_end+x1-y1*render_buff.buff_wid;
				if (x2>=render_buff.clip_wid) 
					{dx=render_buff.clip_wid-x1;if (y2<0 && (dy=(((dword)y1<<16)-ls.dw-1)/ld+1)<dx) dx=dy;}    
				else
					if (y2<0) dx=(((dword)y1<<16)-ls.dw-1)/ld+1;
				while	(--dx>=0)
					{*((sc++)+ls.d.hiw*render_buff.buff_wid)=col;ls.dw+=ld;}
				}
			else
				{
				ld=((dword)dx<<16)/dy;
				if ((unsigned)y1>=render_buff.clip_hgt)
					if (y1<0||y2>=render_buff.clip_hgt) return; 
					else {ls.dw=(y1-render_buff.clip_hgtl)*ld;x1+=ls.d.hiw;ls.d.hiw=0;y1=render_buff.clip_hgtl;dy=y1-y2+1;}
				if ((unsigned)x1>=render_buff.clip_wid)
					if (x1>=0||x2<0) return; else {y1+=(ty=(((dword)x1<<16)+ls.dw+1)/ld-1);ls.dw-=ty*ld;x1=ls.d.hiw=0;dy+=ty;} 	
				sc=render_buff.clip_end+x1-y1*render_buff.buff_wid;
				if (x2>=render_buff.clip_wid) 
					{dy=(((dword)(render_buff.clip_wid-x1)<<16)-ls.dw-1)/ld+1;if (y2<0 && (dx=y1+1)<dy) dy=dx;}    
				else
					if (y2<0) dy=y1+1;
				while	(--dy>=0)
					{*(sc+ls.d.hiw)=col;sc+=render_buff.buff_wid;ls.dw+=ld;}
				}
			}
		}
   else
		{
		dx=x1-x2+1;
		if (y1>=y2)
			{
			dy=y1-y2+1;
			if (dx>=dy)
				{
				ld=((dword)dy<<16)/dx;
				if ((unsigned)x2>=render_buff.clip_wid)
					if (x2>=0||x1<0) return; else {ls.dw=-x2*ld;y2+=ls.d.hiw;ls.d.hiw=0;x2=0;dx=x1+1;}
				if ((unsigned)y2>=render_buff.clip_hgt)
					if (y2>=0||y1<0) return; else {x2-=(tx=(((dword)y2<<16)+ls.dw+1)/ld-1);ls.dw-=tx*ld;y2=ls.d.hiw=0;dx+=tx;}
				sc=render_buff.clip_end+x2-y2*render_buff.buff_wid;
				if (x1>=render_buff.clip_wid) 
					{dx=render_buff.clip_wid-x2; if (y1>=render_buff.clip_hgt && (dy=(((dword)(render_buff.clip_hgt-y2)<<16)-ls.dw-1)/ld+1)<dx) dx=dy;}    
				else
					if (y1>=render_buff.clip_hgt) dx=(((dword)(render_buff.clip_hgt-y2)<<16)-ls.dw-1)/ld+1;
				while	(--dx>=0)
					{*((sc++)-ls.d.hiw*render_buff.buff_wid)=col;ls.dw+=ld;}
				}
			else
				{
				ld=((dword)dx<<16)/dy;
				if ((unsigned)y2>=render_buff.clip_hgt)
					if (y2>=0||y1<0) return; else {ls.dw=-y2*ld;x2+=ls.d.hiw;ls.d.hiw=0;y2=0;dy=y1+1;}
				if ((unsigned)x2>=render_buff.clip_wid)
					if (x2>=0||x1<0) return; else {y2-=(ty=(((dword)x2<<16)+ls.dw+1)/ld-1);ls.dw-=ty*ld;x2=ls.d.hiw=0;dy+=ty;} 	
				sc=render_buff.clip_end+x2-y2*render_buff.buff_wid;
				if (x1>=render_buff.clip_wid) 
					{dy=(((dword)(render_buff.clip_wid-x2)<<16)-ls.dw-1)/ld+1; if (y1>=render_buff.clip_hgt && (dx=render_buff.clip_hgt-y2)<dy) dy=dx;}    
				else
					if (y1>=render_buff.clip_hgt) dy=render_buff.clip_hgt-y2;
				while	(--dy>=0)
					{*(sc+ls.d.hiw)=col;sc-=render_buff.buff_wid;ls.dw+=ld;}
				}
			}
		else		
			{
			dy=y2-y1+1;
			if (dx>=dy)
				{
				ld=((dword)dy<<16)/dx;
				if ((unsigned)x2>=render_buff.clip_wid)
					if (x2>=0||x1<0) return; else {ls.dw=-x2*ld;y2-=ls.d.hiw;ls.d.hiw=0;x2=0;dx=x1+1;} 	
				if ((unsigned)y2>=render_buff.clip_hgt)
					if (y2<0||y1>=render_buff.clip_hgt) return; else 
					{x2+=(tx=(((dword)(y2-render_buff.clip_hgtl)<<16)-ls.dw-1)/ld+1);ls.dw+=tx*ld;y2=render_buff.clip_hgtl;ls.d.hiw=0;dx-=tx-1;}
				sc=render_buff.clip_end+x2-y2*render_buff.buff_wid;
				if (x1>=render_buff.clip_wid) 
					{dx=render_buff.clip_wid-x2;if (y1<0 && (dy=(((dword)y2<<16)-ls.dw-1)/ld+1)<dx) dx=dy;}    
				else
					if (y1<0) dx=(((dword)y2<<16)-ls.dw-1)/ld+1;
				while	(--dx>=0)
					{*((sc++)+ls.d.hiw*render_buff.buff_wid)=col;ls.dw+=ld;}
				}
			else
				{
				ld=((dword)dx<<16)/dy;
				if ((unsigned)y2>=render_buff.clip_hgt)
					if (y2<0||y1>=render_buff.clip_hgt) return; else 
					{ls.dw=(y2-render_buff.clip_hgtl)*ld;x2+=ls.d.hiw;ls.d.hiw=0;y2=render_buff.clip_hgtl;dy=y2-y1+1;}
				if ((unsigned)x2>=render_buff.clip_wid)
					if (x2>=0||x1<0) return; else {y2+=(ty=(((dword)x2<<16)+ls.dw+1)/ld-1);ls.dw-=ty*ld;x2=ls.d.hiw=0;dy+=ty;} 	
				sc=render_buff.clip_end+x2-y2*render_buff.buff_wid;
				if (x1>=render_buff.clip_wid) 
					{dy=(((dword)(render_buff.clip_wid-x2)<<16)-ls.dw-1)/ld+1;if (y1<0 && (dx=y2+1)<dy) dy=dx;}    
				else
					if (y1<0) dy=y2+1;
				while	(--dy>=0)
					{*(sc+ls.d.hiw)=col;sc+=render_buff.buff_wid;ls.dw+=ld;}
				}
			}
		}
	}
#endif
}

/*******************/
/* FLAT POLYGONS A */

// Macro to initialise left 'Bresenham' step
#define lbres(label,endl)\
	olx=lx.dw;\
	if (!--leftl){label:;\
	if (leftp==rightp) {lx.dw=olx;goto endl;}\
	lx.d.hiw=(word)pts[leftp].x;\
	if (++leftp==np) leftp=0;\
	if ((leftl=(word)(pts[leftp].y-yp))<=0) if (leftl<0) return; else goto label;\
	ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);\
	ldx.d.low=0;\
	lx.d.low=0x0000;\
	if (ldx.dw<0) {ldx.d.hiw--;ldx.dw/=leftl+1;lx.dw+=ldx.dw;lx.d.hiw++;}\
	else {ldx.d.hiw++;ldx.dw/=leftl+1;} }
																       
// Macro to initialise right 'Bresenham' step
#define rbres(label,endl)\
	orx=rx.dw;\
	if (!--rightl){label:;\
	if (leftp==rightp) {lx.dw=olx;rx.dw=orx;goto endl;}\
	rx.d.hiw=(word)pts[rightp].x;\
	if (--rightp==-1) rightp=np-1;\
	if ((rightl=(word)(pts[rightp].y-yp))<=0) if (rightl<0) return; else goto label;\
	rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);\
	rdx.d.low=0; rx.d.low=0xffff;\
	if (rdx.dw>0) {rdx.d.hiw++;rdx.dw/=rightl+1;rx.dw+=rdx.dw;}\
	else {rdx.d.hiw--;rdx.dw/=rightl+1;rx.d.hiw++;} }


// Function code
#ifdef POLY
void poly(pnt *pts,word np,word col)
{
#if USERAVEENGINE==YES
TQAVGouraud v[8];

	src.vectors = (VECTOR2D *)pts;
	src.uvmap = (UVMAP *)defuvmap;
	src.numvectors = np;

	dest.vectors = (VECTOR2D *)destVect;
	dest.uvmap = (UVMAP *)destuvMap;
	xclippolygon( (POLYGON *)&src, (POLYGON *)&dest);

	if( dest.numvectors>=3)
		{
		dest2.vectors = (VECTOR2D *)dest2Vect;
		dest2.uvmap = (UVMAP *)destuvMap2;
		yclippolygon( (POLYGON *)&dest, (POLYGON *)&dest2);

		if( dest2.numvectors>=3)
			{
			for ( int i=0; i<dest2.numvectors ; i++ )
				{
				v[i].x = dest2.vectors[i].x;
				v[i].y = 479.0-dest2.vectors[i].y;
				v[i].z = 0.0;
				v[i].invW = 1.0;
				v[i].r = ((palette_buffer16[col]>>10)&31)*(1.0/31.0);
				v[i].g = ((palette_buffer16[col]>>5 )&31)*(1.0/31.0);
				v[i].b = (palette_buffer16[col]&31)*(1.0/31.0);
				v[i].a = 1.0;
				}
			QADrawVGouraud (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
			}
		}
#else
		{
dword_u lx,rx,ldx,rdx;
dword olx,orx;
word leftl,rightl;
word leftp=0,rightp;
scrpt yp,yl,yr;
scrpt tx1,ty1,tx2,ty2,tx3,ty3;
scrpt w;
BYTE *sc;

	// find min x/y max x/y
	// set leftp to point with smallest y
	// and do out of screen clip
	tx1=tx2=pts[0].x;
	ty1=ty2=pts[0].y;
	for (rightp=1;rightp<np;rightp++)
		{
		tx3=pts[rightp].x,ty3=pts[rightp].y;
		if (tx3>tx1) tx1=tx3;
		else if (tx3<tx2) tx2=tx3;
		if (ty3>ty1) ty1=ty3;
		else if (ty3<ty2) ty2=ty3,leftp=rightp;
		}
	if (tx1<0||ty1<0||tx2>=render_buff.clip_wid||ty2>=render_buff.clip_hgt) return;
	
	// top clipping
	if ((yp=pts[rightp=leftp].y)<0)
		{
		yl=yr=yp;
		ldx.d.low=rdx.d.low=0;
		lx.d.low=0x0000;
		rx.d.low=0xffff;
		do
			{lx.d.hiw=(word)pts[leftp].x;
			if (++leftp==np) leftp=0;
			yp=yl;
			}while ((yl=pts[leftp].y)<0);
		if	(yl==0)
			{do
				{lx.d.hiw=(word)pts[leftp].x;
				if (++leftp==np) leftp=0;
				yp=yl;
				}while ((yl=pts[leftp].y)==0);
			if (yl<0) return;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		if (ldx.dw<0) {ldx.d.hiw--;ldx.dw/=(leftl=(word)yl)-yp+1;lx.dw+=ldx.dw;lx.d.hiw++;}
		else {ldx.d.hiw++;ldx.dw/=(leftl=(word)yl)-yp+1;}
		lx.dw-=yp*ldx.dw;


		do
			{rx.d.hiw=(word)pts[rightp].x;
			if (--rightp==-1) rightp=np-1;
			yp=yr;
			}while ((yr=pts[rightp].y)<0);
		if	(yr==0)
			{do
				{rx.d.hiw=(word)pts[rightp].x;
				if (--rightp==-1) rightp=np-1;
				yp=yr;
				}while ((yr=pts[rightp].y)==0);
			if (yr<0) return;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		if (rdx.dw>0) {rdx.d.hiw++;rdx.dw/=(rightl=(word)yr)-yp+1;rx.dw+=rdx.dw;}
		else {rdx.d.hiw--;rdx.dw/=(rightl=(word)yr)-yp+1;rx.d.hiw++;}
		rx.dw-=yp*rdx.dw;

		yp=0;
		}

	// no top clipping
	else
		{
		lx.d.hiw=rx.d.hiw=(word)pts[leftp].x;
		lx.d.low=0x0000;
		rx.d.low=0xffff;
		ldx.d.low=rdx.d.low=0;

		flatl:;
		olx=lx.dw;
		if (++leftp==np) leftp=0;
		if ((leftl=(word)(pts[leftp].y-yp))==0)
			{if (leftp==rightp) {lx.dw=olx;goto endx;}
			lx.d.hiw=(word)pts[leftp].x;goto flatl;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		if (ldx.dw<0) {ldx.d.hiw--;ldx.dw/=leftl+1;lx.dw+=ldx.dw;lx.d.hiw++;}
		else {ldx.d.hiw++;ldx.dw/=leftl+1;}

		flatr:;
		orx=rx.dw;
		if (--rightp==-1) rightp=np-1;
		if ((rightl=(word)(pts[rightp].y-yp))==0)
			{if (leftp==rightp) {lx.dw=olx;rx.dw=orx;goto endx;};
			rx.d.hiw=(word)pts[rightp].x;goto flatr;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		if (rdx.dw>0) {rdx.d.hiw++;rdx.dw/=rightl+1;rx.dw+=rdx.dw;}
		else {rdx.d.hiw--;rdx.dw/=rightl+1;rx.d.hiw++;}
		}


	// polygon starting off screen (horizontally)
	while (lx.d.hiw>=render_buff.clip_wid||rx.d.hiw<=0)
		{
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbres(flatl1,endn)
	  	rbres(flatr1,endn)
		if (yp>=render_buff.clip_hgt) return;
		}

	
	// no left/right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipl;cliplx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto clipr;cliprx:;if (rx.d.hiw<=0) return;}
		if ((w=rx.d.hiw-lx.d.hiw)<=0) return;
		memset(render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid,col,w);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbres(flatl2a,endx)
		rbres(flatr2a,endx)
		}while (yp<render_buff.clip_hgt);
	return;
	endx:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto nclipl;ncliplx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto nclipr;ncliprx:;if (rx.d.hiw<=0) return;}
		if ((w=rx.d.hiw-lx.d.hiw)>0)
			memset(render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid,col,w);
		}
	endn:;
	return;
 
	
	// left clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto cliplx;clipl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto cliplr;cliplrx:;if (rx.d.hiw<=0) return;}
		if (rx.d.hiw<=0) return;
		memset(render_buff.clip_end-yp*render_buff.buff_wid,col,rx.d.hiw);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbres(flatl3a,endxl)
		rbres(flatr3a,endxl)
		}while (yp<render_buff.clip_hgt);
	return;
	endxl:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto ncliplx;nclipl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto ncliplr;ncliplrx:;if (rx.d.hiw<=0) return;}
		if (rx.d.hiw>0)
			memset(render_buff.clip_end-yp*render_buff.buff_wid,col,rx.d.hiw);
		}
	return;
 

	// right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto cliprl;cliprlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto cliprx;clipr:;if (rx.d.hiw<=0) return;}
		memset(render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid,col,render_buff.clip_wid-lx.d.hiw);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbres(flatl4a,endxr)
		rbres(flatr4a,endxr)
		}while (yp<render_buff.clip_hgt);
	return;
	endxr:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto ncliprl;ncliprlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto ncliprx;nclipr:;if (rx.d.hiw<=0) return;}
		memset(render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid,col,render_buff.clip_wid-lx.d.hiw);
		}
	return;


	// both sides clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto cliprlx;cliprl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto cliplrx;cliplr:;if (rx.d.hiw<=0) return;}
		memset(render_buff.clip_end-yp*render_buff.buff_wid,col,render_buff.clip_wid);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbres(flatl5a,endxlr)
		rbres(flatr5a,endxlr)
		}while (yp<render_buff.clip_hgt);
	return;
	endxlr:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto ncliprlx;ncliprl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto ncliplrx;ncliplr:;if (rx.d.hiw<=0) return;}
		memset(render_buff.clip_end-yp*render_buff.buff_wid,col,render_buff.clip_wid);
		}
	return;
	}
#endif
}
#endif

/*******************/
/* FLAT POLYGONS B */

// Macro to initialise left 'Bresenham' step
#define lbresb(label)\
	if (!--leftl){label:;\
	if (leftp==rightp) return;\
	lx.d.hiw=(word)pts[leftp].x;\
	if (++leftp==np) leftp=0;\
	if ((leftl=(word)(pts[leftp].y-yp))<=0) if (leftl<0) return; else goto label;\
	ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);\
	ldx.d.low=lx.d.low=0;\
	ldx.dw/=leftl;}
					
// Macro to initialise right 'Bresenham' step
#define rbresb(label)\
	if (!--rightl){label:;\
	if (leftp==rightp) return;\
	rx.d.hiw=(word)pts[rightp].x;\
	if (--rightp==-1) rightp=np-1;\
	if ((rightl=(word)(pts[rightp].y-yp))<=0) if (rightl<0) return; else goto label;\
	rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);\
	rdx.d.low=rx.d.low=0;\
	rdx.dw/=rightl;}


// Function code
#ifdef POLYB
void polyb(pnt *pts,word np,word col)
{
#if USERAVEENGINE==YES
	if( UseRaveEngine && !Frontend)
		{
TQAVGouraud v[32];

		src.vectors = (VECTOR2D *)pts;
		src.uvmap = (UVMAP *)defuvmap;
		src.numvectors = np;

		dest.vectors = (VECTOR2D *)destVect;
		dest.uvmap = (UVMAP *)destuvMap;
		xclippolygon( (POLYGON *)&src, (POLYGON *)&dest);

		if( dest.numvectors>=3)
			{
			dest2.vectors = (VECTOR2D *)dest2Vect;
			dest2.uvmap = (UVMAP *)destuvMap2;
			yclippolygon( (POLYGON *)&dest, (POLYGON *)&dest2);

			if( dest2.numvectors>=3)
				{
				for ( int i=0; i<dest2.numvectors ; i++ )
					{
					v[i].x = dest2.vectors[i].x;
					v[i].y = 479.0-dest2.vectors[i].y;
					v[i].z = 0.0;
					v[i].invW = 1.0;
					v[i].r = ((palette_buffer16[col]>>10)&31)*(1.0/31.0);
					v[i].g = ((palette_buffer16[col]>>5 )&31)*(1.0/31.0);
					v[i].b = (palette_buffer16[col]&31)*(1.0/31.0);
					v[i].a = 1.0;
					}
				QADrawVGouraud (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
				}
			}
		}
	else
#endif
		{
dword_u lx,rx,ldx,rdx;
word leftl,rightl;
word leftp=0,rightp;
scrpt yp,yl,yr;
scrpt tx1,ty1,tx2,ty2,tx3,ty3;
scrpt w;
BYTE *sc;

	// find min x/y max x/y
	// set leftp to point with smallest y
	// and do out of screen clip
	tx1=tx2=pts[0].x;
	ty1=ty2=pts[0].y;
	for (rightp=1;rightp<np;rightp++)
		{
		tx3=pts[rightp].x,ty3=pts[rightp].y;
		if (tx3>tx1) tx1=tx3;
		else if (tx3<tx2) tx2=tx3;
		if (ty3>ty1) ty1=ty3;
		else if (ty3<ty2) ty2=ty3,leftp=rightp;
		}
	if (tx1<0||ty1<0||tx2>=render_buff.clip_wid||ty2>=render_buff.clip_hgt) return;
	
	// top clipping
	if ((yp=pts[rightp=leftp].y)<0)
		{
		yl=yr=yp;
		ldx.d.low=lx.d.low=rdx.d.low=rx.d.low=0;
		do
			{lx.d.hiw=(word)pts[leftp].x;
			if (++leftp==np) leftp=0;
			yp=yl;
			}while ((yl=pts[leftp].y)<0);
		if	(yl==0)
			{do
				{lx.d.hiw=(word)pts[leftp].x;
				if (++leftp==np) leftp=0;
				yp=yl;
				}while ((yl=pts[leftp].y)==0);
			if (yl<0) return;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldx.dw/=(leftl=(word)yl)-yp;
		lx.dw-=yp*ldx.dw;

		do
			{rx.d.hiw=(word)pts[rightp].x;
			if (--rightp==-1) rightp=np-1;
			yp=yr;
			}while ((yr=pts[rightp].y)<0);
		if	(yr==0)
			{do
				{rx.d.hiw=(word)pts[rightp].x;
				if (--rightp==-1) rightp=np-1;
				yp=yr;
				}while ((yr=pts[rightp].y)==0);
			if (yr<0) return;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		rdx.dw/=(rightl=(word)yr)-yp;
		rx.dw-=yp*rdx.dw;

		yp=0;
		}

	// no top clipping
	else
		{
		lx.d.hiw=rx.d.hiw=(word)pts[leftp].x;
		lx.d.low=ldx.d.low=rx.d.low=rdx.d.low=0;

		flatlb:;
		if (++leftp==np) leftp=0;
		if ((leftl=(word)(pts[leftp].y-yp))==0)
			{if (leftp==rightp) return;
			lx.d.hiw=(word)pts[leftp].x;goto flatlb;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldx.dw/=leftl;

		flatrb:;
		if (--rightp==-1) rightp=np-1;
		if ((rightl=(word)(pts[rightp].y-yp))==0)
			{if (leftp==rightp) return;
			rx.d.hiw=(word)pts[rightp].x;goto flatrb;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
	 	rdx.dw/=rightl;
		}


	// polygon starting off screen (horizontally)
	while (lx.d.hiw>=render_buff.clip_wid||rx.d.hiw<0)
		{
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatl1)
	  	rbresb(flatr1)
		if (yp>=render_buff.clip_hgt) return;
		}

	
	// no left/right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto cliplb;cliplxb:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto cliprb;cliprxb:;if (rx.d.hiw<=0) return;}
		if ((w=rx.d.hiw-lx.d.hiw)<=0 && w<0) return;
		else 
			memset(render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid,col,w);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatl2)
		rbresb(flatr2)
		}while (yp<render_buff.clip_hgt);
	return;
 
	
	// left clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto cliplxb;cliplb:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto cliplrb;cliplrxb:;if (rx.d.hiw<=0) return;}
		if (rx.d.hiw<=0 && rx.d.hiw<0) return;
		else
			memset(render_buff.clip_end-yp*render_buff.buff_wid,col,rx.d.hiw);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatl3)
		rbresb(flatr3)						 
		}while (yp<render_buff.clip_hgt);
	return;
 

	// right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto cliprlb;cliprlxb:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto cliprxb;cliprb:;if (rx.d.hiw<=0) return;}
		memset(render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid,col,render_buff.clip_wid-lx.d.hiw);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatl4)
		rbresb(flatr4)						 
		}while (yp<render_buff.clip_hgt);
	return;


	// both sides clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto cliprlxb;cliprlb:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto cliplrxb;cliplrb:;if (rx.d.hiw<=0) return;}
		memset(render_buff.clip_end-yp*render_buff.buff_wid,col,render_buff.clip_wid);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatl5)
		rbresb(flatr5)
		}while (yp<render_buff.clip_hgt);
	return;
	}
}
#endif

/*******************/
/* FILTER POLYGONS */

// Function code
#ifdef POLYF
void polyf(pnt *pts,word np,filter col)
{
#if USERAVEENGINE==YES
TQAVGouraud v[32];

	src.vectors = (VECTOR2D *)pts;
	src.uvmap = (UVMAP *)defuvmap;
	src.numvectors = np;

	dest.vectors = (VECTOR2D *)destVect;
	dest.uvmap = (UVMAP *)destuvMap;
	xclippolygon( (POLYGON *)&src, (POLYGON *)&dest);

	if( dest.numvectors>=3)
		{
		dest2.vectors = (VECTOR2D *)dest2Vect;
		dest2.uvmap = (UVMAP *)destuvMap2;
		yclippolygon( (POLYGON *)&dest, (POLYGON *)&dest2);

		if( dest2.numvectors>=3)
			{
			for ( int i=0; i<dest2.numvectors ; i++ )
				{
				v[i].x = dest2.vectors[i].x;
				v[i].y = 479.0-dest2.vectors[i].y;
				v[i].z = 0.0;
				v[i].invW = 1.0;
				if( col == filters[0])
					v[i].r = v[i].g = v[i].b = 0.0;
				else
					v[i].r = v[i].g = v[i].b = 0.50;
				v[i].a = 0.25;
				}
			QADrawVGouraud (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
			}
		}
#else
	{
dword_u lx,rx,ldx,rdx;
word leftl,rightl;
word leftp=0,rightp;
scrpt yp,yl,yr;
scrpt tx1,ty1,tx2,ty2,tx3,ty3;
scrpt w;
BYTE *sc;

	// find min x/y max x/y
	// set leftp to point with smallest y
	// and do out of screen clip
	tx1=tx2=pts[0].x;
	ty1=ty2=pts[0].y;
	for (rightp=1;rightp<np;rightp++)
		{
		tx3=pts[rightp].x,ty3=pts[rightp].y;
		if (tx3>tx1) tx1=tx3;
		else if (tx3<tx2) tx2=tx3;
		if (ty3>ty1) ty1=ty3;
		else if (ty3<ty2) ty2=ty3,leftp=rightp;
		}
	if (tx1<0||ty1<0||tx2>=render_buff.clip_wid||ty2>=render_buff.clip_hgt) return;
	
	// top clipping
	if ((yp=pts[rightp=leftp].y)<0)
		{
		yl=yr=yp;
		ldx.d.low=lx.d.low=rdx.d.low=rx.d.low=0;
		do
			{lx.d.hiw=(word)pts[leftp].x;
			if (++leftp==np) leftp=0;
			yp=yl;
			}while ((yl=pts[leftp].y)<0);
		if	(yl==0)
			{do
				{lx.d.hiw=(word)pts[leftp].x;
				if (++leftp==np) leftp=0;
				yp=yl;
				}while ((yl=pts[leftp].y)==0);
			if (yl<0) return;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldx.dw/=(leftl=(word)yl)-yp;
		lx.dw+=(0)-yp*ldx.dw;

		do
			{rx.d.hiw=(word)pts[rightp].x;
			if (--rightp==-1) rightp=np-1;
			yp=yr;
			}while ((yr=pts[rightp].y)<0);
		if	(yr==0)
			{do
				{rx.d.hiw=(word)pts[rightp].x;
				if (--rightp==-1) rightp=np-1;
				yp=yr;
				}while ((yr=pts[rightp].y)==0);
			if (yr<0) return;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		rdx.dw/=(rightl=(word)yr)-yp;
		rx.dw+=(0)-yp*rdx.dw;

		yp=0;
		}

	// no top clipping
	else
		{
		lx.d.hiw=rx.d.hiw=(word)pts[leftp].x;
		lx.d.low=ldx.d.low=rx.d.low=rdx.d.low=0;

		flatfl:;
		if (++leftp==np) leftp=0;
		if ((leftl=(word)(pts[leftp].y-yp))==0)
			{if (leftp==rightp) return;
			lx.d.hiw=(word)pts[leftp].x;goto flatfl;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldx.dw/=leftl;
		lx.dw+=0;

		flatfr:;
		if (--rightp==-1) rightp=np-1;
		if ((rightl=(word)(pts[rightp].y-yp))==0)
			{if (leftp==rightp) return;
			rx.d.hiw=(word)pts[rightp].x;goto flatfr;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		rdx.dw/=rightl;
		rx.dw+=0;
		}


	// polygon starting off screen (horizontally)
	while (lx.d.hiw>=render_buff.clip_wid||rx.d.hiw<0)
		{
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatfl1)
	  	rbresb(flatfr1)
		if (yp>=render_buff.clip_hgt) return;
		}
	
 
	// no left/right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipfl;clipflx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>=render_buff.clip_wid)
			{goto clipfr;clipfrx:;if (rx.d.hiw<0) return;}
		if ((w=(word)(rx.d.hiw-lx.d.hiw))>0)
			{sc=render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid;
			do {*sc=col[*sc];sc++;} while (--w);}
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatfl2)
		rbresb(flatfr2)
		}while (yp<render_buff.clip_hgt);
	return;
 
	
	// left clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipflx;clipfl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>=render_buff.clip_wid)
			{goto clipflr;clipflrx:;if (rx.d.hiw<0) return;}
		if ((w=rx.d.hiw)>0)
			{sc=render_buff.clip_end-yp*render_buff.buff_wid;
			do {*sc=col[*sc];sc++;} while (--w);}
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatfl3)
		rbresb(flatfr3)						 
		}while (yp<render_buff.clip_hgt);
	return;
 

	// right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipfrl;clipfrlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<render_buff.clip_wid)
			{goto clipfrx;clipfr:;if (rx.d.hiw<0) return;}
		w=(word)(render_buff.clip_wid-lx.d.hiw);
		sc=render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid;
		do {*sc=col[*sc];sc++;} while (--w);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatfl4)
		rbresb(flatfr4)
		}while (yp<render_buff.clip_hgt);
	return;


	// both sides clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipfrlx;clipfrl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<render_buff.clip_wid)
			{goto clipflrx;clipflr:;if (rx.d.hiw<0) return;}
		w=(word)render_buff.clip_wid;
		sc=render_buff.clip_end-yp*render_buff.buff_wid;
		do {*sc=col[*sc];sc++;} while (--w);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		yp++;
		lbresb(flatfl5)
		rbresb(flatfr5)
		}while (yp<render_buff.clip_hgt);
	return;
	}
#endif	
}
#endif	

/***************************/
/* GOURAUD SHADED POLYGONS */

// Macro to initialise left 'Bresenham' step
#define lbresg(label)\
	if (!--leftl){label:;\
	if (leftp==rightp) return;\
	lx.d.hiw=(word)pts[leftp].x;\
	lc.d.hiw=(word)pts[leftp].col;\
	if (++leftp==np) leftp=0;\
	if ((leftl=(word)(pts[leftp].y-yp))==0) goto label;\
	ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);\
	ldc.d.hiw=(word)(pts[leftp].col-lc.d.hiw);\
	ldx.d.low=lx.d.low=ldc.d.low=lc.d.low=0;\
	ldx.dw/=leftl;\
	ldc.dw/=leftl;}


// Macro to initialise right 'Bresenham' step
#define rbresg(label)\
	if (!--rightl){label:;\
	if (leftp==rightp) return;\
	rx.d.hiw=(word)pts[rightp].x;\
	rc.d.hiw=(word)pts[rightp].col;\
	if (--rightp==-1) rightp=np-1;\
	if ((rightl=(word)(pts[rightp].y-yp))==0) goto label;\
	rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);\
	rdc.d.hiw=(word)(pts[rightp].col-rc.d.hiw);\
	rdx.d.low=rx.d.low=rdc.d.low=rc.d.low=0;\
	rdx.dw/=rightl;\
	rdc.dw/=rightl;}


// Function code
/*
#ifdef POLYG
void polyg(ppnt *pts,word np)
{
#if USERAVEENGINE==YES
	if( UseRaveEngine && !Frontend)
		{
TQAVGouraud v[32];
VECTOR2D destVect[32];
VECTOR2D dest2Vect[32];
POLYGON src;
POLYGON dest;
POLYGON dest2;

		src.vectors = (VECTOR2D *)pts;
		src.numvectors = np;
		dest.vectors = (VECTOR2D *)destVect;
		xclippolygon( (POLYGON *)&src, (POLYGON *)&dest);
		if( dest.numvectors>=3)
			{
			dest2.vectors = (VECTOR2D *)dest2Vect;
			yclippolygon( (POLYGON *)&dest, (POLYGON *)&dest2);
			if( dest2.numvectors>=3)
				{
				for ( int i=0; i<dest2.numvectors ; i++ )
					{
					v[i].x = dest2.vectors[i].x;
					v[i].y = 479.0-dest2.vectors[i].y;
					v[i].z = 0.0;
					v[i].r = ((palette_buffer16[col]>>10)&31)*(1.0/31.0);
					v[i].g = ((palette_buffer16[col]>>5 )&31)*(1.0/31.0);
					v[i].b = (palette_buffer16[col]&31)*(1.0/31.0);
					v[i].a = 1.0;
					}
				QADrawVGouraud (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
				}
			}
		}
	else
#endif
		{
dword_u lx,rx,ldx,rdx;
dword_u lc,rc,ldc,rdc,cx;
word leftl,rightl;
word leftp=0,rightp;
scrpt yp,yl,yr;
scrpt tx1,ty1,tx2,ty2,tx3,ty3;
scrpt w;
BYTE *sc;

	// find min x/y max x/y
	// set leftp to point with smallest y
	// and do out of screen clip
	tx1=tx2=pts[0].x;
	ty1=ty2=pts[0].y;
	for (rightp=1;rightp<np;rightp++)
		{
		tx3=pts[rightp].x,ty3=pts[rightp].y;
		if (tx3>tx1) tx1=tx3;
		else if (tx3<tx2) tx2=tx3;
		if (ty3>ty1) ty1=ty3;
		else if (ty3<ty2) ty2=ty3,leftp=rightp;
		}
	if (tx1<0||ty1<0||tx2>=render_buff.clip_wid||ty2>=render_buff.clip_hgt) return;
	
	// top clipping
	if ((yp=pts[rightp=leftp].y)<0)
		{
		yl=yr=yp;
		ldx.d.low=lx.d.low=ldc.d.low=lc.d.low=rdx.d.low=rx.d.low=rdc.d.low=rc.d.low=0;
		do
			{lx.d.hiw=(word)pts[leftp].x;
			lc.d.hiw=(word)pts[leftp].col;
			if (++leftp==np) leftp=0;
			yp=yl;
			}while ((yl=pts[leftp].y)<0);
		if	(yl==0)
			{do
				{lx.d.hiw=(word)pts[leftp].x;
				lc.d.hiw=(word)pts[leftp].col;
				if (++leftp==np) leftp=0;
				yp=yl;
				}while ((yl=pts[leftp].y)==0);
			if (yl<0) return;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldx.dw/=(ty1=(leftl=(word)yl)-yp);
		lx.dw-=yp*ldx.dw;
		ldc.d.hiw=(word)(pts[leftp].col-lc.d.hiw);
		ldc.dw/=ty1;
		lc.dw-=yp*ldc.dw;

		do
			{rx.d.hiw=(word)pts[rightp].x;
			rc.d.hiw=(word)pts[rightp].col;
			if (--rightp==-1) rightp=np-1;
			yp=yr;
			}while ((yr=pts[rightp].y)<0);
		if	(yr==0)
			{do
				{rx.d.hiw=(word)pts[rightp].x;
				rc.d.hiw=(word)pts[rightp].col;
				if (--rightp==-1) rightp=np-1;
				yp=yr;
				}while ((yr=pts[rightp].y)==0);
			if (yr<0) return;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		rdx.dw/=(ty1=(rightl=(word)yr)-yp);
		rx.dw-=yp*rdx.dw;
		rdc.d.hiw=(word)(pts[rightp].col-rc.d.hiw);
		rdc.dw/=ty1;
		rc.dw-=yp*rdc.dw;
	  
		yp=0;
		}

	// no top clipping
	else
		{
		lx.d.hiw=rx.d.hiw=(word)pts[leftp].x;
		lc.d.hiw=rc.d.hiw=(word)pts[leftp].col;
		ldx.d.low=lx.d.low=ldc.d.low=lc.d.low=rdx.d.low=rx.d.low=rdc.d.low=rc.d.low=0;

		flatgl:;
		if (++leftp==np) leftp=0;
		if ((leftl=(word)(pts[leftp].y-yp))==0)
			{if (leftp==rightp) return;lx.d.hiw=(word)pts[leftp].x;
			lc.d.hiw=(word)pts[leftp].col;goto flatgl;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldc.d.hiw=(word)(pts[leftp].col-lc.d.hiw);
		ldx.dw/=leftl;
		ldc.dw/=leftl;

		flatgr:;
		if (--rightp==-1) rightp=np-1;
		if ((rightl=(word)(pts[rightp].y-yp))==0)
			{if (leftp==rightp) return;rx.d.hiw=(word)pts[rightp].x;
			rc.d.hiw=(word)pts[rightp].col;goto flatgr;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		rdc.d.hiw=(word)(pts[rightp].col-rc.d.hiw);
		rdx.dw/=rightl;
		rdc.dw/=rightl;
		}


	// polygon starting off screen (horizontally)
	while (lx.d.hiw>=render_buff.clip_wid||rx.d.hiw<0)
		{
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		lc.dw+=ldc.dw;
		rc.dw+=rdc.dw;
		yp++;
		lbresg(flatgl1)
	  	rbresg(flatgr1)
		if (yp>=render_buff.clip_hgt) return;
		}
	
 
	// no left/right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipgl;clipglx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>=render_buff.clip_wid)
			{goto clipgr;clipgrx:;if (rx.d.hiw<0) return;}
		if ((w=(word)(rx.d.hiw-lx.d.hiw))>0)
			{tx1=(rc.dw-lc.dw)/w;
			cx.dw=lc.dw;
			sc=render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid;
			do	{*sc++=(BYTE)((cx.d.hiw&0xf8)+(pts[leftp].col&7));cx.dw+=tx1; }while (--w);}
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		lc.dw+=ldc.dw;
		rc.dw+=rdc.dw;
		yp++;
		lbresg(flatgl2)
		rbresg(flatgr2)
		}while (yp<render_buff.clip_hgt);
	return;
 
	
	// left clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipglx;clipgl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>=render_buff.clip_wid)
			{goto clipglr;clipglrx:;if (rx.d.hiw<0) return;}
		if ((w=rx.d.hiw)>0)
			{tx1=(rc.dw-lc.dw)/(rx.d.hiw-lx.d.hiw);
			cx.dw=lc.dw-lx.d.hiw*tx1;
			sc=render_buff.clip_end-yp*render_buff.buff_wid;
			do { *sc++=(BYTE)((cx.d.hiw&0xf8)+(pts[leftp].col&7));cx.dw+=tx1; }while (--w);}
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		lc.dw+=ldc.dw;
		rc.dw+=rdc.dw;
		yp++;
		lbresg(flatgl3)
		rbresg(flatgr3)						 
		}while (yp<render_buff.clip_hgt);
	return;
 

	// right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipgrl;clipgrlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<render_buff.clip_wid)
			{goto clipgrx;clipgr:;if (rx.d.hiw<0) return;}
		tx1=(rc.dw-lc.dw)/(rx.d.hiw-lx.d.hiw);
		cx.dw=lc.dw;
		sc=render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid;
		w=(word)(render_buff.clip_wid-lx.d.hiw);
		do	{ *sc++=(BYTE)((cx.d.hiw&0xf8)+(pts[leftp].col&7));cx.dw+=tx1; }while (--w);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		lc.dw+=ldc.dw;
		rc.dw+=rdc.dw;
		yp++;
		lbresg(flatgl4)
		rbresg(flatgr4)
		}while (yp<render_buff.clip_hgt);
	return;


	// both sides clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipgrlx;clipgrl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<render_buff.clip_wid)
			{goto clipglrx;clipglr:;if (rx.d.hiw<0) return;}
		tx1=(rc.dw-lc.dw)/(rx.d.hiw-lx.d.hiw);
		cx.dw=lc.dw-lx.d.hiw*tx1;
		sc=render_buff.clip_end-yp*render_buff.buff_wid;
		w=(word)render_buff.clip_wid;
		do	{ *sc++=(BYTE)((cx.d.hiw&0xf8)+(pts[leftp].col&7));cx.dw+=tx1; }while (--w);
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
		lc.dw+=ldc.dw;
		rc.dw+=rdc.dw;
		yp++;
		lbresg(flatgl5)
		rbresg(flatgr5)
		}while (yp<render_buff.clip_hgt);
	return;
	}
}
#endif
*/

/*****************************/
/* TEXTURE MAPPED POLYGONS B */

// Macro to initialise left 'Bresenham' step
#define lbresm(label)\
	if (!--leftl){label:;\
	if (leftp==rightp) return;\
	lx.d.hiw=(word)pts[leftp].x;\
	psx=startsx[leftp];\
	psy=startsy[leftp];\
	if (++leftp==np) leftp=0;\
	if ((leftl=(word)(pts[leftp].y-yp))==0) goto label;\
	ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);\
	ldx.d.low=lx.d.low=0;\
	ldx.dw/=leftl;\
	psdx=(startsx[leftp]-psx)/leftl;\
	psdy=(startsy[leftp]-psy)/leftl;}
	

// Macro to initialise right 'Bresenham' step
#define rbresm(label)\
	if (!--rightl){label:;\
	if (leftp==rightp) return;\
	rx.d.hiw=(word)pts[rightp].x;\
	pex=startsx[rightp];\
	pey=startsy[rightp];\
	if (--rightp==-1) rightp=np-1;\
	if ((rightl=(word)(pts[rightp].y-yp))==0) goto label;\
	rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);\
	rdx.d.low=rx.d.low=0;\
	rdx.dw/=rightl;\
	pedx=(startsx[rightp]-pex)/rightl;\
	pedy=(startsy[rightp]-pey)/rightl;}


/*****************************/
/* TEXTURE MAPPED POLYGONS A */

// Macro to initialise left 'Bresenham' step
#define lbresmx(label,endl)\
	olx=lx.dw;\
	if (!--leftl){label:;\
	if (leftp==rightp)  {lx.dw=olx;goto endl;}\
	lx.d.hiw=(word)pts[leftp].x;\
	psx=startsx[leftp];\
	psy=startsy[leftp];\
	if (++leftp==np) leftp=0;\
	if ((leftl=(word)(pts[leftp].y-yp))<=0) if (leftl<0) return; else goto label;\
	ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);\
	ldx.d.low=0;\
	lx.d.low=0;\
	if (ldx.dw<0) {ldx.d.hiw--;ldx.dw/=leftl+1;lx.dw+=ldx.dw;lx.d.hiw++;\
 	               psdx=(startsx[leftp]-psx)/(leftl+1);psx+=psdx;\
 	               psdy=(startsy[leftp]-psy)/(leftl+1);psy+=psdy;}\
	else {ldx.d.hiw++;ldx.dw/=leftl+1;\
	      psdx=(startsx[leftp]-psx)/(leftl+1);\
	      psdy=(startsy[leftp]-psy)/(leftl+1);} }
	

// Macro to initialise right 'Bresenham' step
#define rbresmx(label,endl)\
	orx=rx.dw;\
	if (!--rightl){label:;\
	if (leftp==rightp) {lx.dw=olx;rx.dw=orx;goto endl;}\
	rx.d.hiw=(word)pts[rightp].x;\
	pex=startsx[rightp];\
	pey=startsy[rightp];\
	if (--rightp==-1) rightp=np-1;\
	if ((rightl=(word)(pts[rightp].y-yp))<=0) if (rightl<0) return; else goto label;\
	rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);\
	rdx.d.low=0;\
	rx.d.low=-1;\
	if (rdx.dw>0) {rdx.d.hiw++;rdx.dw/=rightl+1;rx.dw+=rdx.dw;\
 	               pedx=(startsx[rightp]-pex)/(rightl+1);pex+=pedx;\
 	               pedy=(startsy[rightp]-pey)/(rightl+1);pey+=pedy;}\
	else {rdx.d.hiw--;rdx.dw/=rightl+1;rx.d.hiw++;\
	      pedx=(startsx[rightp]-pex)/(rightl+1);\
			pedy=(startsy[rightp]-pey)/(rightl+1);} }


// Function code
#ifdef POLYM
void polym(pnt *pts,word np,char *mapsel,dword *startsx,dword *startsy)
{
#if USERAVEENGINE==YES
static TQAVTexture v[8];

	for( int a=0; a<np; a++)
		{
		srcuvMap[a].u = ((startsx[a]>>16) & 255) * (1.0/255.0);
		srcuvMap[a].v = ((startsy[a]>>16) & 255) * (1.0/255.0);
		}
	
	src.vectors = (VECTOR2D *)pts;
	src.uvmap = (UVMAP *)srcuvMap;
	src.numvectors = np;

	dest.vectors = (VECTOR2D *)destVect;
	dest.uvmap = (UVMAP *)destuvMap;
	xclippolygon( (POLYGON *)&src, (POLYGON *)&dest);
	
	if( dest.numvectors>=3)
		{
		dest2.vectors = (VECTOR2D *)dest2Vect;
		dest2.uvmap = (UVMAP *)destuvMap2;
		yclippolygon( (POLYGON *)&dest, (POLYGON *)&dest2);

		if( dest2.numvectors>=3)
			{
			for ( int i=0 ; i<dest2.numvectors ; i++ )
				{
				v[i].x = dest2.vectors[i].x;
				v[i].y = 479.0-dest2.vectors[i].y;
				v[i].z = 0.0;
				v[i].invW = 1.0;
				v[i].a = 1.0;
				v[i].uOverW = dest2.uvmap[i].u;
				v[i].vOverW = 1.0-dest2.uvmap[i].v;
				}
			QASetPtr (gTheContext, kQATag_Texture, FindTexture( (BYTE *)mapsel));
			QADrawVTexture (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
#if POLYGONIZE
{
int i;
static float r=1.0, g=0.0;

			for ( i=0; i<dest2.numvectors-1 ; i++ )
				Fast_Line( v[ i].x, v[ i].y, v[ i+1].x, v[ i+1].y, r, g, 0.0);
			Fast_Line( v[ i].x, v[ i].y, v[ 0].x, v[ 0].y, r, g, 0.0);
			r = 1.0-r;
			g = 1.0-g;
}
#endif
			}
		}
#else
		{
dword_u lx,rx,ldx,rdx;
dword olx,orx;
word leftl,rightl;
word leftp=0,rightp;
scrpt yp,yl,yr;
scrpt tx1,ty1,tx2,ty2,tx3,ty3;
dword psx,psy,pex,pey,psdx,psdy,pedx,pedy;
word w1,w2;
BYTE *sc;
	
	data = (BYTE *)mapsel;

	// find min x/y max x/y
	// set leftp to point with smallest y
	// and do out of screen clip
	tx1=tx2=pts[0].x;
	ty1=ty2=pts[0].y;
	for (rightp=1;rightp<np;rightp++)
		{
		tx3=pts[rightp].x;
		ty3=pts[rightp].y;
		if (tx3>tx1)
			tx1=tx3;
		else if (tx3<tx2)
			tx2=tx3;
		if (ty3>ty1)
			ty1=ty3;
		else if (ty3<ty2) 
			{
			ty2=ty3;
			leftp=rightp;
			}
		}
	if (tx1<0||ty1<0||tx2>=render_buff.clip_wid||ty2>=render_buff.clip_hgt) return;
	
	// top clipping
	if ((yp=pts[rightp=leftp].y)<0)
		{
		yl=yr=yp;
		ldx.d.low=rdx.d.low=0;
		lx.d.low=0;
		rx.d.low=-1;
		do
			{
			lx.d.hiw=(word)pts[leftp].x;
			psx=startsx[leftp];
			psy=startsy[leftp];
			if (++leftp==np) 
				leftp=0;
			yp=yl;
			} while ((yl=pts[leftp].y)<0);
		if	(yl==0)
			{
			do
				{
				lx.d.hiw=(word)pts[leftp].x;
				psx=startsx[leftp];
				psy=startsy[leftp];
				if (++leftp==np)
					leftp=0;
				yp=yl;
				} while ((yl=pts[leftp].y)==0);
			if (yl<0) 
				return;
			}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		if (ldx.dw<0)
			{
			ldx.d.hiw--;
			ldx.dw/=(ty1=(leftl=(word)yl)-yp+1);
			lx.dw+=ldx.dw;lx.d.hiw++;
		    psdx=(startsx[leftp]-psx)/ty1;psx+=psdx;
            psdy=(startsy[leftp]-psy)/ty1;psy+=psdy;
            }
		else
			{
			ldx.d.hiw++;
			ldx.dw/=(ty1=(leftl=(word)yl)-yp+1);
			psdx=(startsx[leftp]-psx)/ty1;
            psdy=(startsy[leftp]-psy)/ty1;
            }
		lx.dw-=yp*ldx.dw;
		psx-=yp*psdx;
		psy-=yp*psdy;
		do
			{
			rx.d.hiw=(word)pts[rightp].x;
			pex=startsx[rightp];
			pey=startsy[rightp];
			if (--rightp==-1)
				rightp=np-1;
			yp=yr;
			} while((yr=pts[rightp].y)<0);
		if	(yr==0)
			{
			do
				{
				rx.d.hiw=(word)pts[rightp].x;
				pex=startsx[rightp];
				pey=startsy[rightp];
				if (--rightp==-1)
					rightp=np-1;
				yp=yr;
				} while((yr=pts[rightp].y)==0);
			if (yr<0) return;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		if (rdx.dw>0) {rdx.d.hiw++;rdx.dw/=(ty1=(rightl=(word)yr)-yp+1);rx.dw+=rdx.dw;
	                  pedx=(startsx[rightp]-pex)/ty1;pex+=pedx;
		               pedy=(startsy[rightp]-pey)/ty1;pey+=pedy;}
		else {rdx.d.hiw--;rdx.dw/=(ty1=(rightl=(word)yr)-yp+1);rx.d.hiw++;
	         pedx=(startsx[rightp]-pex)/ty1;
		      pedy=(startsy[rightp]-pey)/ty1;}
		rx.dw-=yp*rdx.dw;			  
		pex-=yp*pedx;
		pey-=yp*pedy;
	  
		yp=0;
		}

	// no top clipping
	else
		{
		lx.d.hiw=rx.d.hiw=(word)pts[leftp].x;
		lx.d.low=0;
		rx.d.low=-1;
		ldx.d.low=rdx.d.low=0;
		psx=pex=startsx[leftp];
		psy=pey=startsy[leftp];

		flatml:;
		olx=lx.dw;
		if (++leftp==np) leftp=0;
		if ((leftl=(word)(pts[leftp].y-yp))==0)
			{if (leftp==rightp) {lx.dw=olx;goto endxm;} lx.d.hiw=(word)pts[leftp].x;
			psx=startsx[leftp];psy=startsy[leftp];goto flatml;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		if (ldx.dw<0) {ldx.d.hiw--;ldx.dw/=leftl+1;lx.dw+=ldx.dw;lx.d.hiw++;
	 	               psdx=(startsx[leftp]-psx)/(leftl+1);psx+=psdx;
	 	               psdy=(startsy[leftp]-psy)/(leftl+1);psy+=psdy;}
		else {ldx.d.hiw++;ldx.dw/=leftl+1;
		      psdx=(startsx[leftp]-psx)/(leftl+1);
		      psdy=(startsy[leftp]-psy)/(leftl+1);}

		flatmr:;
		orx=rx.dw;
		if (--rightp==-1) rightp=np-1;
		if ((rightl=(word)(pts[rightp].y-yp))==0)
			{if (leftp==rightp) {lx.dw=olx;rx.dw=orx;goto endxm;} rx.d.hiw=(word)pts[rightp].x;
			pex=startsx[rightp];pey=startsy[rightp];goto flatmr;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		if (rdx.dw>0) {rdx.d.hiw++;rdx.dw/=rightl+1;rx.dw+=rdx.dw;
	 	               pedx=(startsx[rightp]-pex)/(rightl+1);pex+=pedx;
	 	               pedy=(startsy[rightp]-pey)/(rightl+1);pey+=pedy;}
		else {rdx.d.hiw--;rdx.dw/=rightl+1;rx.d.hiw++;
		      pedx=(startsx[rightp]-pex)/(rightl+1);
				pedy=(startsy[rightp]-pey)/(rightl+1);}
		}


	// polygon starting off screen (horizontally)
	while (lx.d.hiw>=render_buff.clip_wid||rx.d.hiw<=0)
		{
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresmx(flatml1,endnm)
	  	rbresmx(flatmr1,endnm)
		if (yp>=render_buff.clip_hgt) return;
		}
	
 
	// no left/right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipml;clipmlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto clipmr;clipmrx:;if (rx.d.hiw<=0) return;}
		if ((w1=rx.d.hiw-lx.d.hiw)<=0) {if (w1<0) return;}
		else
			{
			pxy[3]=(psx-pex)/w1;
			pxy[4]=(psy-pey)/w1;
			pxy[1]=pex;
			pxy[2]=pey;
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlinm(sc, w1);
			}
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresmx(flatml2,endxm)
		rbresmx(flatmr2,endxm)
		}while (yp<render_buff.clip_hgt);
	return;
	endxm:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto nclipml;nclipmlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto nclipmr;nclipmrx:;if (rx.d.hiw<=0) return;}
		if ((w1=rx.d.hiw-lx.d.hiw)>0)
			{
			pxy[3]=(psx-pex)/w1;
			pxy[4]=(psy-pey)/w1;
			pxy[1]=pex;
			pxy[2]=pey;
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlinm(sc, w1);
			}
		}
	endnm:;
	return;
 
	
	// left clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipmlx;clipml:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto clipmlr;clipmlrx:;if (rx.d.hiw<=0) return;}
		if ((w1=rx.d.hiw)<=0) {if (w1<0) return;}
		else
			{
			pxy[3]=(psx-pex)/(w2=rx.d.hiw-lx.d.hiw);
			pxy[4]=(psy-pey)/w2;
			pxy[1]=pex;
			pxy[2]=pey;
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlinm(sc, w1);
			}
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresmx(flatml3,endxlm)
		rbresmx(flatmr3,endxlm) 
		}while (yp<render_buff.clip_hgt);
	return;
 	endxlm:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto nclipmlx;nclipml:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto nclipmlr;nclipmlrx:;if (rx.d.hiw<=0) return;}
		if ((w1=rx.d.hiw)>0)
			{
			pxy[3]=(psx-pex)/(w2=rx.d.hiw-lx.d.hiw);
			pxy[4]=(psy-pey)/w2;
			pxy[1]=pex;
			pxy[2]=pey;
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlinm(sc, w1);
			}
		}
	return;


	// right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipmrl;clipmrlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto clipmrx;clipmr:;if (rx.d.hiw<=0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid-lx.d.hiw;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlinm(sc, w1);
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;			 
		yp++;
		lbresmx(flatml4,endxrm)
		rbresmx(flatmr4,endxrm)
		}while (yp<render_buff.clip_hgt);
	return;
	endxrm:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto nclipmrl;nclipmrlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto nclipmrx;nclipmr:;if (rx.d.hiw<=0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid-lx.d.hiw;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlinm(sc, w1);
		}
	return;


	// both sides clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipmrlx;clipmrl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto clipmlrx;clipmlr:;if (rx.d.hiw<=0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlinm(sc, w1);
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresmx(flatml5,endxlrm)
		rbresmx(flatmr5,endxlrm)
		}while (yp<render_buff.clip_hgt);
	return;
	endxlrm:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto nclipmrlx;nclipmrl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto nclipmlrx;nclipmlr:;if (rx.d.hiw<=0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlinm(sc, w1);
		}
	return;
	}
#endif
}
#endif

/***********************************/
/* LOOPING TEXTURE MAPPED POLYGONS */

// Function code
#ifdef POLYL
void polyl(pnt *pts,word np,char *mapsel,dword *startsx,dword *startsy)
{
#if USERAVEENGINE==YES
TQAVGouraud v[8];

	src.vectors = (VECTOR2D *)pts;
	src.uvmap = (UVMAP *)defuvmap;
	src.numvectors = np;

	dest.vectors = (VECTOR2D *)destVect;
	dest.uvmap = (UVMAP *)destuvMap;
	xclippolygon( (POLYGON *)&src, (POLYGON *)&dest);

	if( dest.numvectors>=3)
		{
		dest2.vectors = (VECTOR2D *)dest2Vect;
		dest2.uvmap = (UVMAP *)destuvMap2;
		yclippolygon( (POLYGON *)&dest, (POLYGON *)&dest2);

		if( dest2.numvectors>=3)
			{
			for ( int i=0; i<dest2.numvectors ; i++ )
				{
				v[i].x = dest2.vectors[i].x;
				v[i].y = 479.0-dest2.vectors[i].y;
				v[i].z = 0.0;
				v[i].invW = 1.0;
				v[i].r = 1.0;
				v[i].g = 1.0;
				v[i].b = 0.0;
				v[i].a = 1.0;
				}
			QADrawVGouraud (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
			}
		}
#else
	{
dword_u lx,rx,ldx,rdx;
word leftl,rightl;
word leftp=0,rightp;
scrpt yp,yl,yr;
scrpt tx1,ty1,tx2,ty2,tx3,ty3;
dword psx,psy,pex,pey,psdx,psdy,pedx,pedy;
//	static dword pxy[5]={0,0,0,0,0};
word w1,w2;
BYTE *sc;
	
	data = (BYTE *)mapsel;
	// find min x/y max x/y
	// set leftp to point with smallest y
	// and do out of screen clip
	tx1=tx2=pts[0].x;
	ty1=ty2=pts[0].y;
	for (rightp=1;rightp<np;rightp++)
		{
		tx3=pts[rightp].x,ty3=pts[rightp].y;
		if (tx3>tx1) tx1=tx3;
		else if (tx3<tx2) tx2=tx3;
		if (ty3>ty1) ty1=ty3;
		else if (ty3<ty2) ty2=ty3,leftp=rightp;
		}
	if (tx1<0||ty1<0||tx2>=render_buff.clip_wid||ty2>=render_buff.clip_hgt) return;
	
	// top clipping
	if ((yp=pts[rightp=leftp].y)<0)
		{
		yl=yr=yp;
		ldx.d.low=lx.d.low=rdx.d.low=rx.d.low=0;
		do
			{lx.d.hiw=(word)pts[leftp].x;
			psx=startsx[leftp];
			psy=startsy[leftp];
			if (++leftp==np) leftp=0;
			yp=yl;
			}while ((yl=pts[leftp].y)<0);
		if	(yl==0)
			{do
				{lx.d.hiw=(word)pts[leftp].x;
				psx=startsx[leftp];
				psy=startsy[leftp];
				if (++leftp==np) leftp=0;
				yp=yl;
				}while ((yl=pts[leftp].y)==0);
			if (yl<0) return;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldx.dw/=(ty1=(leftl=(word)yl)-yp);
		lx.dw+=(ldx.dw>>1)-yp*ldx.dw;
		psdx=(startsx[leftp]-psx)/ty1;
		psdy=(startsy[leftp]-psy)/ty1;
		psx+=(psdx>>1)-yp*psdx;
		psy+=(psdy>>1)-yp*psdy;

		do
			{rx.d.hiw=(word)pts[rightp].x;
			pex=startsx[rightp];
			pey=startsy[rightp];
			if (--rightp==-1) rightp=np-1;
			yp=yr;
			}while ((yr=pts[rightp].y)<0);
		if	(yr==0)
			{do
				{rx.d.hiw=(word)pts[rightp].x;
				pex=startsx[rightp];
				pey=startsy[rightp];
				if (--rightp==-1) rightp=np-1;
				yp=yr;
				}while ((yr=pts[rightp].y)==0);
			if (yr<0) return;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		rdx.dw/=(ty1=(rightl=(word)yr)-yp);
		rx.dw+=(rdx.dw>>1)-yp*rdx.dw;			  
	   pedx=(startsx[rightp]-pex)/ty1;
		pedy=(startsy[rightp]-pey)/ty1;
		pex+=(pedx>>1)-yp*pedx;
		pey+=(pedy>>1)-yp*pedy;
	  
		yp=0;
		}

	// no top clipping
	else
		{
		lx.d.hiw=rx.d.hiw=(word)pts[leftp].x;
		lx.d.low=ldx.d.low=rx.d.low=rdx.d.low=0;
		psx=pex=startsx[leftp];
		psy=pey=startsy[leftp];

		flatml:;
		if (++leftp==np) leftp=0;
		if ((leftl=(word)(pts[leftp].y-yp))==0)
			{if (leftp==rightp) return;lx.d.hiw=(word)pts[leftp].x;
			psx=startsx[leftp];psy=startsy[leftp];goto flatml;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldx.dw/=leftl;
		lx.dw+=ldx.dw>>1;
		psdx=(startsx[leftp]-psx)/leftl;
		psdy=(startsy[leftp]-psy)/leftl;
		psx+=psdx>>1;
		psy+=psdy>>1;

		flatmr:;
		if (--rightp==-1) rightp=np-1;
		if ((rightl=(word)(pts[rightp].y-yp))==0)
			{if (leftp==rightp) return;rx.d.hiw=(word)pts[rightp].x;
			pex=startsx[rightp];pey=startsy[rightp];goto flatmr;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		rdx.dw/=rightl;
		rx.dw+=rdx.dw>>1;
		pedx=(startsx[rightp]-pex)/rightl;
		pedy=(startsy[rightp]-pey)/rightl;
		pex+=pedx>>1;
		pey+=pedy>>1;
		}


	// polygon starting off screen (horizontally)
	while (lx.d.hiw>=render_buff.clip_wid||rx.d.hiw<0)
		{
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresm(flatml1)
	  	rbresm(flatmr1)
		if (yp>=render_buff.clip_hgt) return;
		}
	
 
	// no left/right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipml;clipmlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>=render_buff.clip_wid)
			{goto clipmr;clipmrx:;if (rx.d.hiw<0) return;}
		if ((w1=rx.d.hiw-lx.d.hiw)>0)
			{
			pxy[3]=(psx-pex)/w1;
			pxy[4]=(psy-pey)/w1;
			pxy[1]=(pex+(pxy[3]>>1));
			pxy[2]=(pey+(pxy[4]>>1));
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlinl(sc, w1);
			}
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresm(flatml2)
		rbresm(flatmr2)
		}while (yp<render_buff.clip_hgt);
	return;
 
	
	// left clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipmlx;clipml:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>=render_buff.clip_wid)
			{goto clipmlr;clipmlrx:;if (rx.d.hiw<0) return;}
		if ((w1=rx.d.hiw)>0)
			{
			pxy[3]=(psx-pex)/(w2=rx.d.hiw-lx.d.hiw);
			pxy[4]=(psy-pey)/w2;
			pxy[1]=(pex+(pxy[3]>>1));
			pxy[2]=(pey+(pxy[4]>>1));
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlinl(sc, w1);
			}
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresm(flatml3)
		rbresm(flatmr3)						 
		}while (yp<render_buff.clip_hgt);
	return;
 

	// right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipmrl;clipmrlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<render_buff.clip_wid)
			{goto clipmrx;clipmr:;if (rx.d.hiw<0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0.5)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid-lx.d.hiw;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlinl(sc, w1);
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;			 
		yp++;
		lbresm(flatml4)
		rbresm(flatmr4)
		}while (yp<render_buff.clip_hgt);
	return;


	// both sides clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipmrlx;clipmrl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<render_buff.clip_wid)
			{goto clipmlrx;clipmlr:;if (rx.d.hiw<0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0.5)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlinl(sc, w1);
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresm(flatml5)
		rbresm(flatmr5)
		}while (yp<render_buff.clip_hgt);
	return;
	}
#endif
}
#endif

#if USERAVEENGINE==YES
/*****************************************/
/* JOOLZ SPECIAL TEXTURE ROUTINE FOR THE PITCH */
// Function code


#if 0
void quad_subdivide ( pnt *pts , UVMAP *uvs, int depth )
{
TQAVTexture v[8];

	if ( depth==0 )
	{
	for ( int i=0; i<4 ; i++ )
		{
		v[i].x = pts[i].x;
		v[i].y = 479.0-pts[i].y;
		v[i].z = 0.0;
		v[i].invW = 1.0;
		v[i].a = 1.0;
		v[i].uOverW = uvs[i].u;
		v[i].vOverW = 1.0-uvs[i].v;
		}
	QASetPtr (gTheContext, kQATag_Texture, Texture_Maps[10]);
//	QADrawVTexture (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
	QADrawVTexture (gTheContext, 4, kQAVertexMode_Fan, &v[0], NULL);
	}
	else
	{
		pnt mids[4];
		pnt mid;
		pnt sub[4];
		UVMAP subuvs[4];
		int i;
		float half=(uvs[1].u-uvs[0].u)/2;
		
		for ( i=0 ; i!=4 ; i++ )
		{
			mids[i].x=pts[i].x+(pts[(i+1)&3].x-pts[i].x)/2;
			mids[i].y=pts[i].y+(pts[(i+1)&3].y-pts[i].y)/2;
		}
		mid.x=mids[0].x+(mids[2].x-mids[0].x)/2;
		mid.y=mids[0].y+(mids[2].y-mids[0].y)/2;

		depth--;

		subuvs[0].u=uvs[0].u;
		subuvs[0].v=uvs[0].v;
		subuvs[1].u=uvs[0].u+half;
		subuvs[1].v=uvs[0].v;
		subuvs[2].u=uvs[0].u+half;
		subuvs[2].v=uvs[0].v+half;
		subuvs[3].u=uvs[0].u;
		subuvs[3].v=uvs[0].v+half;

		sub[0]=pts[0];
		sub[1]=mids[0];
		sub[2]=mid;
		sub[3]=mids[3];
		quad_subdivide ( sub , subuvs , depth ); 

		subuvs[0].u=uvs[0].u+half;
		subuvs[0].v=uvs[0].v;
		subuvs[1].u=uvs[1].u;
		subuvs[1].v=uvs[1].v;
		subuvs[2].u=uvs[1].u;
		subuvs[2].v=uvs[1].v+half;
		subuvs[3].u=uvs[0].u+half;
		subuvs[3].v=uvs[0].v+half;

		sub[0]=mids[0];
		sub[1]=pts[1];
		sub[2]=mids[1];
		sub[3]=mid;
		quad_subdivide ( sub , subuvs , depth ); 

		subuvs[0].u=uvs[0].u+half;
		subuvs[0].v=uvs[0].v+half;
		subuvs[1].u=uvs[2].u;
		subuvs[1].v=uvs[1].v+half;
		subuvs[2].u=uvs[2].u;
		subuvs[2].v=uvs[2].v;
		subuvs[3].u=uvs[3].u+half;
		subuvs[3].v=uvs[3].v;

		sub[0]=mid;
		sub[1]=mids[1];
		sub[2]=pts[2];
		sub[3]=mids[2];
		quad_subdivide ( sub , subuvs , depth ); 

		subuvs[0].u=uvs[0].u;
		subuvs[0].v=uvs[0].v+half;
		subuvs[1].u=uvs[0].u+half;
		subuvs[1].v=uvs[0].v+half;
		subuvs[2].u=uvs[3].u+half;
		subuvs[2].v=uvs[3].v;
		subuvs[3].u=uvs[3].u;
		subuvs[3].v=uvs[3].v;

		sub[0]=mids[3];
		sub[1]=mid;
		sub[2]=mids[2];
		sub[3]=pts[3];
		quad_subdivide ( sub , subuvs , depth ); 
	}
}
#endif

void polyj(pnt *pts,word np)
{
TQAVTexture v[8];
 
//	np = 4;
//	pts[0].x = 276;	pts[0].y = 454;
//	pts[1].x = 420;	pts[1].y = 454;
//	pts[2].x = 420; pts[2].y = 1;	// -27;
//	pts[3].x = 193; pts[3].y = 1;	// -27;
//	pts[0].x = 37;	pts[0].y = 454;
//	pts[1].x = 420;	pts[1].y = 400;
//	pts[2].x = 516; pts[2].y = 20;	// -27;
//	pts[3].x = 276; pts[3].y = 1;	// -27;
	defuvmap[ 0].u = 0.0; defuvmap[ 0].v = 0.0;
	defuvmap[ 1].u = 1.0; defuvmap[ 1].v = 0.0;
	defuvmap[ 2].u = 1.0; defuvmap[ 2].v = 1.0;
	defuvmap[ 3].u = 0.0; defuvmap[ 3].v = 1.0;

//	if( np == 4)
//		{
//		quad_subdivide( pts, defuvmap, 0);
//		return;
//		}
		
#if DEBUGGING==YES
	DumpLong( 0, np);

	for( int a=0; a<np; a++)
		{
		DumpLong( 20 + (a*20), pts[a].x);
		DumpLong( 30 + (a*20), pts[a].y);
		}
#endif
	
		src.vectors = (VECTOR2D *)pts;
		src.uvmap = (UVMAP *)defuvmap;
		src.numvectors = np;

		dest.vectors = (VECTOR2D *)destVect;
		dest.uvmap = (UVMAP *)destuvMap;
		xclippolygon( (POLYGON *)&src, (POLYGON *)&dest);

		if( dest.numvectors>=3)
			{
			dest2.vectors = (VECTOR2D *)dest2Vect;
			dest2.uvmap = (UVMAP *)destuvMap2;
			yclippolygon( (POLYGON *)&dest, (POLYGON *)&dest2);

			if( dest2.numvectors>=3)
				{
				for ( int i=0; i<dest2.numvectors ; i++ )
					{
					v[i].x = dest2.vectors[i].x;
					v[i].y = 479.0-dest2.vectors[i].y;
					v[i].z = 0.0;
					v[i].invW = 1.0;
					v[i].a = 1.0;
					v[i].uOverW = dest2.uvmap[i].u;
					v[i].vOverW = 1.0-dest2.uvmap[i].v;
					}
				QASetPtr (gTheContext, kQATag_Texture, Texture_Maps[10]);
				QADrawVTexture (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
#if POLYGONIZE
{
int i;

				for ( i=0; i<dest2.numvectors-1 ; i++ )
					Fast_Line( v[ i].x, v[ i].y, v[ i+1].x, v[ i+1].y, 1.0, 0.0, 0.0);
				Fast_Line( v[ i].x, v[ i].y, v[ 0].x, v[ 0].y, 1.0, 0.0, 0.0);
}
#endif
				}
			}
}
#endif

/*****************************************/
/* TRANSPARENT TEXTURE MAPPED POLYGONS A */

// Function code
#ifdef POLYT
void polyt(pnt *pts,word np,char *mapsel,dword *startsx,dword *startsy)
{
#if USERAVEENGINE==YES
	if( UseRaveEngine && !Frontend)
		{
TQAVTexture v[8];

		for( int a=0; a<np; a++)
			{
			srcuvMap[a].u = ((startsx[a]>>16) & 255) * (1.0/255.0);
			srcuvMap[a].v = ((startsy[a]>>16) & 255) * (1.0/255.0);
			}
		
		src.vectors = (VECTOR2D *)pts;
		src.uvmap = (UVMAP *)srcuvMap;
		src.numvectors = np;

		dest.vectors = (VECTOR2D *)destVect;
		dest.uvmap = (UVMAP *)destuvMap;
		xclippolygon( (POLYGON *)&src, (POLYGON *)&dest);

		if( dest.numvectors>=3)
			{
			dest2.vectors = (VECTOR2D *)dest2Vect;
			dest2.uvmap = (UVMAP *)destuvMap2;
			yclippolygon( (POLYGON *)&dest, (POLYGON *)&dest2);

			if( dest2.numvectors>=3)
				{
				for ( int i=0; i<dest2.numvectors ; i++ )
					{
					v[i].x = dest2.vectors[i].x;
					v[i].y = 479.0-dest2.vectors[i].y;
					v[i].z = 0.0;
					v[i].invW = 1.0;
					v[i].a = 1.0;
					v[i].uOverW = dest2.uvmap[i].u;
					v[i].vOverW = 1.0-dest2.uvmap[i].v;
					}
				QASetInt (gTheContext, kQATag_Blend, kQABlend_Interpolate);
				QASetPtr (gTheContext, kQATag_Texture, FindTexture( (BYTE *)mapsel));
				QADrawVTexture (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
				QASetInt (gTheContext, kQATag_Blend, kQABlend_PreMultiply);
#if POLYGONIZE
{
static float r=1.0, g=0.0;
int i;

				for ( i=0; i<dest2.numvectors-1 ; i++ )
					Fast_Line( v[ i].x, v[ i].y, v[ i+1].x, v[ i+1].y, r, g, 0.0);
				Fast_Line( v[ i].x, v[ i].y, v[ 0].x, v[ 0].y, r, g, 0.0);
				r = 1.0 - r;
				g = 1.0 - g;
}
#endif
				}
			}
		}
	else
#endif
		{
dword_u lx,rx,ldx,rdx;
dword olx,orx;
word leftl,rightl;
word leftp=0,rightp;
scrpt yp,yl,yr;
scrpt tx1,ty1,tx2,ty2,tx3,ty3;
dword psx,psy,pex,pey,psdx,psdy,pedx,pedy;
word w1,w2;
BYTE *sc;

	data = (BYTE *)mapsel;

	// find min x/y max x/y
	// set leftp to point with smallest y
	// and do out of screen clip
	tx1=tx2=pts[0].x;
	ty1=ty2=pts[0].y;
	for (rightp=1;rightp<np;rightp++)
		{
		tx3=pts[rightp].x,ty3=pts[rightp].y;
		if (tx3>tx1) tx1=tx3;
		else if (tx3<tx2) tx2=tx3;
		if (ty3>ty1) ty1=ty3;
		else if (ty3<ty2) ty2=ty3,leftp=rightp;
		}
	if (tx1<0||ty1<0||tx2>=render_buff.clip_wid||ty2>=render_buff.clip_hgt) return;
	
	// top clipping
	if ((yp=pts[rightp=leftp].y)<0)
		{
		yl=yr=yp;
		ldx.d.low=rdx.d.low=0;
		lx.d.low=0;
		rx.d.low=-1;
		do
			{lx.d.hiw=(word)pts[leftp].x;
			psx=startsx[leftp];
			psy=startsy[leftp];
			if (++leftp==np) leftp=0;
			yp=yl;
			}while ((yl=pts[leftp].y)<0);
		if	(yl==0)
			{do
				{lx.d.hiw=(word)pts[leftp].x;
				psx=startsx[leftp];
				psy=startsy[leftp];
				if (++leftp==np) leftp=0;
				yp=yl;
				}while ((yl=pts[leftp].y)==0);
			if (yl<0) return;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		if (ldx.dw<0) {ldx.d.hiw--;ldx.dw/=(ty1=(leftl=(word)yl)-yp+1);lx.dw+=ldx.dw;lx.d.hiw++;
		               psdx=(startsx[leftp]-psx)/ty1;psx+=psdx;
                		psdy=(startsy[leftp]-psy)/ty1;psy+=psdy;}
		else {ldx.d.hiw++;ldx.dw/=(ty1=(leftl=(word)yl)-yp+1);
		      psdx=(startsx[leftp]-psx)/ty1;
            psdy=(startsy[leftp]-psy)/ty1;}
		lx.dw-=yp*ldx.dw;
		psx-=yp*psdx;
		psy-=yp*psdy;

		do
			{rx.d.hiw=(word)pts[rightp].x;
			pex=startsx[rightp];
			pey=startsy[rightp];
			if (--rightp==-1) rightp=np-1;
			yp=yr;
			}while ((yr=pts[rightp].y)<0);
		if	(yr==0)
			{do
				{rx.d.hiw=(word)pts[rightp].x;
				pex=startsx[rightp];
				pey=startsy[rightp];
				if (--rightp==-1) rightp=np-1;
				yp=yr;
				}while ((yr=pts[rightp].y)==0);
			if (yr<0) return;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		if (rdx.dw>0) {rdx.d.hiw++;rdx.dw/=(ty1=(rightl=(word)yr)-yp+1);rx.dw+=rdx.dw;
	                  pedx=(startsx[rightp]-pex)/ty1;pex+=pedx;
		               pedy=(startsy[rightp]-pey)/ty1;pey+=pedy;}
		else {rdx.d.hiw--;rdx.dw/=(ty1=(rightl=(word)yr)-yp+1);rx.d.hiw++;
	         pedx=(startsx[rightp]-pex)/ty1;
		      pedy=(startsy[rightp]-pey)/ty1;}
		rx.dw-=yp*rdx.dw;			  
		pex-=yp*pedx;
		pey-=yp*pedy;
	  
		yp=0;
		}

	// no top clipping
	else
		{
		lx.d.hiw=rx.d.hiw=(word)pts[leftp].x;
		lx.d.low=0;
		rx.d.low=-1;
		ldx.d.low=rdx.d.low=0;
		psx=pex=startsx[leftp];
		psy=pey=startsy[leftp];

		flatml:;
		olx=lx.dw;
		if (++leftp==np) leftp=0;
		if ((leftl=(word)(pts[leftp].y-yp))==0)
			{if (leftp==rightp) {lx.dw=olx;goto endxm;} lx.d.hiw=(word)pts[leftp].x;
			psx=startsx[leftp];psy=startsy[leftp];goto flatml;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		if (ldx.dw<0) {ldx.d.hiw--;ldx.dw/=leftl+1;lx.dw+=ldx.dw;lx.d.hiw++;
	 	               psdx=(startsx[leftp]-psx)/(leftl+1);psx+=psdx;
	 	               psdy=(startsy[leftp]-psy)/(leftl+1);psy+=psdy;}
		else {ldx.d.hiw++;ldx.dw/=leftl+1;
		      psdx=(startsx[leftp]-psx)/(leftl+1);
		      psdy=(startsy[leftp]-psy)/(leftl+1);}

		flatmr:;
		orx=rx.dw;
		if (--rightp==-1) rightp=np-1;
		if ((rightl=(word)(pts[rightp].y-yp))==0)
			{if (leftp==rightp) {lx.dw=olx;rx.dw=orx;goto endxm;} rx.d.hiw=(word)pts[rightp].x;
			pex=startsx[rightp];pey=startsy[rightp];goto flatmr;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		if (rdx.dw>0) {rdx.d.hiw++;rdx.dw/=rightl+1;rx.dw+=rdx.dw;
	 	               pedx=(startsx[rightp]-pex)/(rightl+1);pex+=pedx;
	 	               pedy=(startsy[rightp]-pey)/(rightl+1);pey+=pedy;}
		else {rdx.d.hiw--;rdx.dw/=rightl+1;rx.d.hiw++;
		      pedx=(startsx[rightp]-pex)/(rightl+1);
				pedy=(startsy[rightp]-pey)/(rightl+1);}
		}


	// polygon starting off screen (horizontally)
	while (lx.d.hiw>=render_buff.clip_wid||rx.d.hiw<=0)
		{
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresmx(flatml1,endnm)
	  	rbresmx(flatmr1,endnm)
		if (yp>=render_buff.clip_hgt) return;
		}
	
 
	// no left/right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipml;clipmlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto clipmr;clipmrx:;if (rx.d.hiw<=0) return;}
		if ((w1=rx.d.hiw-lx.d.hiw)<=0) {if (w1<0) return;}
		else
			{
			pxy[3]=(psx-pex)/w1;
			pxy[4]=(psy-pey)/w1;
			pxy[1]=pex;
			pxy[2]=pey;
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlint(sc, w1);
			}
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresmx(flatml2,endxm)
		rbresmx(flatmr2,endxm)
		}while (yp<render_buff.clip_hgt);
	return;
	endxm:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto nclipml;nclipmlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto nclipmr;nclipmrx:;if (rx.d.hiw<=0) return;}
		if ((w1=rx.d.hiw-lx.d.hiw)>0)
			{
			pxy[3]=(psx-pex)/w1;
			pxy[4]=(psy-pey)/w1;
			pxy[1]=pex;
			pxy[2]=pey;
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlint(sc, w1);
			}
		}
	endnm:;
	return;
 
	
	// left clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipmlx;clipml:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto clipmlr;clipmlrx:;if (rx.d.hiw<=0) return;}
		if ((w1=rx.d.hiw)<=0) {if (w1<0) return;}
		else
			{
			pxy[3]=(psx-pex)/(w2=rx.d.hiw-lx.d.hiw);
			pxy[4]=(psy-pey)/w2;
			pxy[1]=pex;
			pxy[2]=pey;
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlint(sc, w1);
			}
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresmx(flatml3,endxlm)
		rbresmx(flatmr3,endxlm) 
		}while (yp<render_buff.clip_hgt);
	return;
 	endxlm:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto nclipmlx;nclipml:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>render_buff.clip_wid)
			{goto nclipmlr;nclipmlrx:;if (rx.d.hiw<=0) return;}
		if ((w1=rx.d.hiw)>0)
			{
			pxy[3]=(psx-pex)/(w2=rx.d.hiw-lx.d.hiw);
			pxy[4]=(psy-pey)/w2;
			pxy[1]=pex;
			pxy[2]=pey;
			sc=render_buff.clip_end+rx.d.hiw-yp*render_buff.buff_wid;
			hlint(sc, w1);
			}
		}
	return;


	// right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipmrl;clipmrlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto clipmrx;clipmr:;if (rx.d.hiw<=0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid-lx.d.hiw;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlint(sc, w1);
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;			 
		yp++;
		lbresmx(flatml4,endxrm)
		rbresmx(flatmr4,endxrm)
		}while (yp<render_buff.clip_hgt);
	return;
	endxrm:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto nclipmrl;nclipmrlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto nclipmrx;nclipmr:;if (rx.d.hiw<=0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid-lx.d.hiw;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlint(sc, w1);
		}
	return;


	// both sides clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipmrlx;clipmrl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto clipmlrx;clipmlr:;if (rx.d.hiw<=0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlint(sc, w1);
		lx.dw+=ldx.dw;
		psx+=psdx,psy+=psdy;
		rx.dw+=rdx.dw;
		pex+=pedx,pey+=pedy;
		yp++;
		lbresmx(flatml5,endxlrm)
		rbresmx(flatmr5,endxlrm)
		}while (yp<render_buff.clip_hgt);
	return;
	endxlrm:;
	if (yp<render_buff.clip_hgt)
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto nclipmrlx;nclipmrl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<=render_buff.clip_wid)
			{goto nclipmlrx;nclipmlr:;if (rx.d.hiw<=0) return;}
		pxy[3]=(psx-pex)/(w1=rx.d.hiw-lx.d.hiw);
		pxy[4]=(psy-pey)/w1;
		pxy[1]=(pex+(tx2=rx.d.hiw-render_buff.clip_wid+0)*pxy[3]);
		pxy[2]=(pey+tx2*pxy[4]);
		w1=render_buff.clip_wid;
		sc=render_buff.clip_end+render_buff.clip_wid-yp*render_buff.buff_wid;
		hlint(sc, w1);
		}
	return;
	}
}
#endif

/***************************************/
/* BIQUADRATIC TEXTURE MAPPED POLYGONS */

// Macro to initialise left 'Bresenham' step

#define lbresq(label)\
	if (!--leftl){label:;\
	if (leftp==rightp) return;\
	lx.d.hiw=(word)pts[leftp].x;\
	zlo=pts[leftp].z;\
	psxo=startsx[leftp];\
	psyo=startsy[leftp];\
	if (++leftp==np) leftp=0;\
	if ((leftl=(word)(pts[leftp].y-yp))==0) goto label;\
	ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);\
	ldx.d.low=lx.d.low=0;\
	ldx.dw/=leftl;\
	zld=pts[leftp].z;\
	pl1=0;\
	pl2=zld*leftl;\
	zld-=zlo;\
	psdx=startsx[leftp]-psxo;\
	psdy=startsy[leftp]-psyo;}
	

// Macro to initialise right 'Bresenham' step
#define rbresq(label)\
	if (!--rightl){label:;\
	if (leftp==rightp) return;\
	rx.d.hiw=(word)pts[rightp].x;\
	zro=pts[rightp].z;\
	pexo=startsx[rightp];\
	peyo=startsy[rightp];\
	if (--rightp==-1) rightp=np-1;\
	if ((rightl=(word)(pts[rightp].y-yp))==0) goto label;\
	rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);\
	rdx.d.low=rx.d.low=0;\
	rdx.dw/=rightl;\
	zrd=pts[rightp].z;\
	pr1=0;\
	pr2=zrd*rightl;\
	zrd-=zro;\
	pedx=startsx[rightp]-pexo;\
	pedy=startsy[rightp]-peyo;}


/*
// Function code
#ifdef POLYQ
void polyq(zpnt *pts,word np,BYTE *map,dword *startsx,dword *startsy)
{
#if USERAVEENGINE==YES
	if( UseRaveEngine && !Frontend)
		{
TQAVGouraud v[32];
VECTOR2D destVect[32];
VECTOR2D dest2Vect[32];
POLYGON src;
POLYGON dest;
POLYGON dest2;

		src.vectors = (VECTOR2D *)pts;
		src.numvectors = np;
		dest.vectors = (VECTOR2D *)destVect;
		xclippolygon( (POLYGON *)&src, (POLYGON *)&dest);
		if( dest.numvectors >=3)
			{
			dest2.vectors = (VECTOR2D *)dest2Vect;
			yclippolygon( (POLYGON *)&dest, (POLYGON *)&dest2);
			if( dest2.numvectors >=3)
				{
				for ( int i=0; i<dest2.numvectors ; i++ )
					{
					v[i].x = dest2.vectors[i].x;
					v[i].y = 479.0-dest2.vectors[i].y;
					v[i].z = 0.0;
					v[i].invW = 1.0;
					v[i].r = 0.0;
					v[i].g = 1.0;
					v[i].b = 0.0;
					v[i].a = 1.0;
					}
				QADrawVGouraud (gTheContext, dest2.numvectors, kQAVertexMode_Fan, &v[0], NULL);
				}
			}
		}
	else
#endif
{
dword_u lx,rx,ldx,rdx;
word leftl,rightl;
word leftp=0,rightp;
scrpt yp,yl,yr;
scrpt tx1,ty1,tx2,ty2,tx3,ty3;
dword_u psx,psy;
dword pmx,pmy,pex,pey;
dword psdx,psdy,pedx,pedy;
dword psxo,psyo,pexo,peyo;
dword px1,px2,py1,py2;
dword pl1,pl2,pr1,pr2;
floatpt zl,zr,zlo,zro,zld,zrd;
floatpt pl,pr,zm;
word w1,w2;
BYTE *sc;

	// find min x/y max x/y
	// set leftp to point with smallest y
	// and do out of screen clip
	tx1=tx2=pts[0].x;
	ty1=ty2=pts[0].y;
	for (rightp=1;rightp<np;rightp++)
		{
		tx3=pts[rightp].x,ty3=pts[rightp].y;
		if (tx3>tx1) tx1=tx3;
		else if (tx3<tx2) tx2=tx3;
		if (ty3>ty1) ty1=ty3;
		else if (ty3<ty2) ty2=ty3,leftp=rightp;
		}
	if (tx1<0||ty1<0||tx2>=render_buff.clip_wid||ty2>=render_buff.clip_hgt) return;
	
	// top clipping
	if ((yp=pts[rightp=leftp].y)<0)
		{
		yl=yr=yp;
		ldx.d.low=lx.d.low=rdx.d.low=rx.d.low=0;
		do
			{lx.d.hiw=(word)pts[leftp].x;
			zlo=pts[leftp].z;
			psxo=startsx[leftp];
			psyo=startsy[leftp];
			if (++leftp==np) leftp=0;
			yp=yl;
			}while ((yl=pts[leftp].y)<0);
		if	(yl==0)
			{do
				{lx.d.hiw=(word)pts[leftp].x;
				zlo=pts[leftp].z;
				psxo=startsx[leftp];
				psyo=startsy[leftp];
				if (++leftp==np) leftp=0;
				yp=yl;
				}while ((yl=pts[leftp].y)==0);
			if (yl<0) return;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldx.dw/=(ty1=(leftl=(word)yl)-yp);
		lx.dw-=yp*ldx.dw;
		zld=pts[leftp].z;
		pl1=-yp*zlo;
		pl2=zld*ty1;
		zld-=zlo;
		pl2+=yp*zld;
		psdx=startsx[leftp]-psxo;
		psdy=startsy[leftp]-psyo;

		do
			{rx.d.hiw=(word)pts[rightp].x;
			zro=pts[rightp].z;
			pexo=startsx[rightp];
			peyo=startsy[rightp];
			if (--rightp==-1) rightp=np-1;
			yp=yr;
			}while ((yr=pts[rightp].y)<0);
		if	(yr==0)
			{do
				{rx.d.hiw=(word)pts[rightp].x;
				zro=pts[rightp].z;
				pexo=startsx[rightp];
				peyo=startsy[rightp];
				if (--rightp==-1) rightp=np-1;
				yp=yr;
				}while ((yr=pts[rightp].y)==0);
			if (yr<0) return;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		rdx.dw/=(ty1=(rightl=(word)yr)-yp);
		rx.dw-=yp*rdx.dw;			  
		zrd=pts[rightp].z;
		pr1=-yp*zro;
		pr2=zrd*ty1;
		zrd-=zro;
		pr2+=yp*zrd;
	   pedx=startsx[rightp]-pexo;
		pedy=startsy[rightp]-peyo;
	  
		yp=0;
		}

	// no top clipping
	else
		{
		lx.d.hiw=rx.d.hiw=(word)pts[leftp].x;
		lx.d.low=ldx.d.low=rx.d.low=rdx.d.low=0;
		zlo=zro=pts[leftp].z;
		psxo=pexo=startsx[leftp];
		psyo=peyo=startsy[leftp];

		flatql:;
		if (++leftp==np) leftp=0;
		if ((leftl=(word)(pts[leftp].y-yp))==0)
			{if (leftp==rightp) return;lx.d.hiw=(word)pts[leftp].x;
			zlo=pts[leftp].z;psxo=startsx[leftp];psyo=startsy[leftp];goto flatql;}
		ldx.d.hiw=(word)(pts[leftp].x-lx.d.hiw);
		ldx.dw/=leftl;
		zld=pts[leftp].z;
		pl1=0;
		pl2=zld*leftl;
		zld-=zlo;
		psdx=startsx[leftp]-psxo;
		psdy=startsy[leftp]-psyo;

		flatqr:;
		if (--rightp==-1) rightp=np-1;
		if ((rightl=(word)(pts[rightp].y-yp))==0)
			{if (leftp==rightp) return;rx.d.hiw=(word)pts[rightp].x;
			zro=pts[rightp].z;pexo=startsx[rightp];peyo=startsy[rightp];goto flatqr;}
		rdx.d.hiw=(word)(pts[rightp].x-rx.d.hiw);
		rdx.dw/=rightl;
		zrd=pts[rightp].z;
		pr1=0;
		pr2=zrd*rightl;
		zrd-=zro;
		pedx=startsx[rightp]-pexo;
		pedy=startsy[rightp]-peyo;
		}


	// polygon starting off screen (horizontally)
	while (lx.d.hiw>=render_buff.clip_wid||rx.d.hiw<0)
		{
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
 		pl1+=zlo;
 		pl2-=zld;
 		pr1+=zro;
		pr2-=zrd;
		yp++;
		lbresq(flatql1)
	  	rbresq(flatqr1)
		if (yp>=render_buff.clip_hgt) return;
		}
	
 					   
	// no left/right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipql;clipqlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>=render_buff.clip_wid)
			{goto clipqr;clipqrx:;if (rx.d.hiw<0) return;}
		if ((w1=rx.d.hiw-lx.d.hiw)>0)
			{				  
			sc=render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid;
			pl=(floatpt)pl1/pl2;
			pr=(floatpt)pr1/pr2;
			zl=zld*pl;
			zl+=zlo;
			psx.dw=psdx*pl;
			psx.dw+=psxo;
			psy.dw=psdy*pl;
			psy.dw+=psyo;
			zr=zrd*pr;
			zr+=zro;
			pex=pedx*pr;
			pex+=pexo;
			pey=pedy*pr;
			pey+=peyo;
			zm=zl/(zl+zr);
			pmx=psx.dw+(pex-psx.dw)*zm;
			pmy=psy.dw+(pey-psy.dw)*zm;
			px2=(psx.dw+pex-(pmx<<1))<<1;
			px1=(pex-psx.dw-px2)/w1;
			px2/=w1*w1;
			px1+=px2;
			px2<<=1;
			py2=(psy.dw+pey-(pmy<<1))<<1;
			py1=(pey-psy.dw-py2)/w1;
			py2/=w1*w1;
			py1+=py2;
			py2<<=1;
			for (;w1>0;w1--)
				{
				*sc++=*(map+(psy.d.hiw<<8)+psx.d.hiw);
				psx.dw+=px1;
				px1+=px2;
				psy.dw+=py1;
				py1+=py2;
				}
			}
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
  		pl1+=zlo;
  		pl2-=zld;
  		pr1+=zro;
  		pr2-=zrd;
		yp++;
		lbresq(flatql2)
		rbresq(flatqr2)
		}while (yp<render_buff.clip_hgt);
	return;
 
	
	// left clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipqlx;clipql:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw>=render_buff.clip_wid)
			{goto clipqlr;clipqlrx:;if (rx.d.hiw<0) return;}
		if ((w1=rx.d.hiw)>0)
			{
			sc=render_buff.clip_end-yp*render_buff.buff_wid;
			pl=(floatpt)pl1/pl2;
			pr=(floatpt)pr1/pr2;
			zl=zld*pl;
			zl+=zlo;
			psx.dw=psdx*pl;
			psx.dw+=psxo;
			psy.dw=psdy*pl;
			psy.dw+=psyo;
			zr=zrd*pr;
			zr+=zro;
			pex=pedx*pr;
			pex+=pexo;
			pey=pedy*pr;
			pey+=peyo;
			zm=zl/(zl+zr);
			pmx=psx.dw+(pex-psx.dw)*zm;
			pmy=psy.dw+(pey-psy.dw)*zm;
			px2=(psx.dw+pex-(pmx<<1))<<1;
			px1=(pex-psx.dw-px2)/(w2=rx.d.hiw-lx.d.hiw);
			px2/=w2*w2;
			psx.dw-=lx.d.hiw*px1-lx.d.hiw*lx.d.hiw*px2;
			px1-=px2*((lx.d.hiw<<1)-1);
			px2<<=1;
			py2=(psy.dw+pey-(pmy<<1))<<1;
			py1=(pey-psy.dw-py2)/w2;
			py2/=w2*w2;
			psy.dw-=lx.d.hiw*py1-lx.d.hiw*lx.d.hiw*py2;
			py1-=py2*((lx.d.hiw<<1)-1);
			py2<<=1;
			for (;w1>0;w1--)
				{
				*sc++=*(map+(psy.d.hiw<<8)+psx.d.hiw);
				psx.dw+=px1;
				px1+=px2;
				psy.dw+=py1;
				py1+=py2;
				}
			}
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
  		pl1+=zlo;
  		pl2-=zld;
 		pr1+=zro;
 		pr2-=zrd;
		yp++;
		lbresq(flatql3)
		rbresq(flatqr3)						 
		}while (yp<render_buff.clip_hgt);
	return;
 

	// right clipping
	do
		{
		if ((unsigned)lx.d.hiw>=render_buff.clip_wid)
			{goto clipqrl;clipqrlx:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<render_buff.clip_wid)
			{goto clipqrx;clipqr:;if (rx.d.hiw<0) return;}
		sc=render_buff.clip_end+lx.d.hiw-yp*render_buff.buff_wid;
		w1=render_buff.clip_wid-lx.d.hiw;
 		pl=(floatpt)pl1/pl2;
 		pr=(floatpt)pr1/pr2;
 		zl=zld*pl;
 		zl+=zlo;
		psx.dw=psdx*pl;
		psx.dw+=psxo;
		psy.dw=psdy*pl;
		psy.dw+=psyo;
		zr=zrd*pr;
		zr+=zro;
		pex=pedx*pr;
		pex+=pexo;
		pey=pedy*pr;
		pey+=peyo;
		zm=zl/(zl+zr);
		pmx=psx.dw+(pex-psx.dw)*zm;
		pmy=psy.dw+(pey-psy.dw)*zm;
		px2=(psx.dw+pex-(pmx<<1))<<1;
		px1=(pex-psx.dw-px2)/(w2=rx.d.hiw-lx.d.hiw);
		px2/=w2*w2;
		px1+=px2;
		px2<<=1;
		py2=(psy.dw+pey-(pmy<<1))<<1;
		py1=(pey-psy.dw-py2)/w2;
		py2/=w2*w2;
		py1+=py2;
		py2<<=1;
		for (;w1>0;w1--)
			{
			*sc++=*(map+(psy.d.hiw<<8)+psx.d.hiw);
			psx.dw+=px1;
			px1+=px2;
			psy.dw+=py1;
			py1+=py2;
			}
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
  		pl1+=zlo;
  		pl2-=zld;
  		pr1+=zro;
  		pr2-=zrd;
		yp++;
		lbresq(flatql4)
		rbresq(flatqr4)
		}while (yp<render_buff.clip_hgt);
	return;


	// both sides clipping
	do
		{
		if ((unsigned)lx.d.hiw<render_buff.clip_wid)
			{goto clipqrlx;clipqrl:;if (lx.d.hiw>=render_buff.clip_wid) return;}
		if ((unsigned)rx.d.hiw<render_buff.clip_wid)
			{goto clipqlrx;clipqlr:;if (rx.d.hiw<0) return;}
		sc=render_buff.clip_end-yp*render_buff.buff_wid;
		w1=render_buff.clip_wid;
		pl=(floatpt)pl1/pl2;
		pr=(floatpt)pr1/pr2;
		zl=zld*pl;
		zl+=zlo;
		psx.dw=psdx*pl;
		psx.dw+=psxo;
		psy.dw=psdy*pl;
		psy.dw+=psyo;
		zr=zrd*pr;
		zr+=zro;
		pex=pedx*pr;
		pex+=pexo;
		pey=pedy*pr;
		pey+=peyo;
		zm=zl/(zl+zr);
		pmx=psx.dw+(pex-psx.dw)*zm;
		pmy=psy.dw+(pey-psy.dw)*zm;
		px2=(psx.dw+pex-(pmx<<1))<<1;
		px1=(pex-psx.dw-px2)/(w2=rx.d.hiw-lx.d.hiw);
		px2/=w2*w2;
		psx.dw-=lx.d.hiw*px1-lx.d.hiw*lx.d.hiw*px2;
		px1+=px2;
		px2<<=1;
		py2=(psy.dw+pey-(pmy<<1))<<1;
		py1=(pey-psy.dw-py2)/w2;
		py2/=w2*w2;
		psy.dw-=lx.d.hiw*py1-lx.d.hiw*lx.d.hiw*py2;
		py1+=py2;
		py2<<=1;
		for (;w1>0;w1--)
			{
			*sc++=*(map+(psy.d.hiw<<8)+psx.d.hiw);
			psx.dw+=px1;
			px1+=px2;
			psy.dw+=py1;
			py1+=py2;
			}
		lx.dw+=ldx.dw;
		rx.dw+=rdx.dw;
  		pl1+=zlo;
  		pl2-=zld;
  		pr1+=zro;
  		pr2-=zrd;
		yp++;
		lbresq(flatql5)
		rbresq(flatqr5)
		}while (yp<render_buff.clip_hgt);
	return;
	}
#endif
*/
