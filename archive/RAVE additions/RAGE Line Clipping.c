#include "Mac Vars.h"

#if USERAVEENGINE==YES

#include "RAGE Line Clipping.h"

#include "3deng.h"

#undef EXTERN
#define EXTERN extern
#include "RAGE Polygon Clipping.h"

static int get_outcode ( float x , float y )
{
int out=0;

	if ( x < WINDOW_MIN_X )
		out|=LEFT;
	if ( x >= WINDOW_MAX_X )
		out|=RIGHT;
	if ( y < WINDOW_MIN_Y )
		out|=TOP;
	if ( y >= WINDOW_MAX_Y)
		out|=BOTTOM;
	return ( out );
}

inline void float_swap ( float * a , float * b )
{
float c = *a;

	*a=*b; *b=c;
}

inline void int_swap ( int * a , int * b )
{
int c = *a;

	*a=*b; *b=c;
}

int RAGE_ClipLine( float * x1 , float * y1 , float * x2 , float * y2 )
{
int outcode1 , outcode2;

	for ( ; ; )
		{
		outcode1=get_outcode ( *x1 , *y1 );
		outcode2=get_outcode ( *x2 , *y2 );
		if ( !outcode1 && !outcode2 )
			return ( LINE_VISIBLE );
		if ( outcode1 & outcode2 )
			return ( LINE_INVISIBLE );
		if ( outcode1==0 )
			{
		 	int_swap ( &outcode1 , &outcode2 );	
		 	float_swap ( x1 , x2 );	
		 	float_swap ( y1 , y2 );	
			}
		if ( outcode1&LEFT )
			{
			*y1= *y1+( (0-*x1)*(*y2-*y1) ) / (*x2-*x1);
			*x1=0;
			}
		else if ( outcode1&RIGHT )
			{
			*y1= *y1+( (*x1-WINDOW_MAX_X)*(*y2-*y1) ) / (*x1-*x2);
			*x1=WINDOW_MAX_X-1;
			}
		else if ( outcode1&TOP )
			{
			*x1= *x1+( (0-*y1)*(*x2-*x1) ) / (*y2-*y1);
			*y1=0;
			}
		else if ( outcode1&BOTTOM )
			{
			*x1= *x1+( (*y1-WINDOW_MAX_Y)*(*x2-*x1) ) / (*y1-*y2);
			*y1=WINDOW_MAX_Y-1;
			}
		}
}
#endif



