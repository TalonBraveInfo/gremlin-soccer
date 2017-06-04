#include "Andys Vars.h"
#include "Maths.h"

#undef EXTERN
#define EXTERN extern
#include "Football.h"

extern short *afr1;
extern short *afr2;

/******************************************************************************
*****************************************************************************/

//extern int matherr(struct exception *);

int matherr(struct exception *)
{
	end_game = true;
	return(0);
}

/******************************************************************************
*****************************************************************************/

#if GAME_DEBUG==ON
void AF_randomize( char *file, int line)
#else
void af_randomize()
#endif
{
#if GAME_DEBUG==ON
	fprintf( GameDebugFP, "Rand %s, %d, %x\n", file, line, rand_seed);
#endif

	if (andys_random)
	{
		rand_seed=(*afr1)^rand_seed+(*afr2)^rand_seed;
		*afr1=*afr1^((int)rand_seed);
		*afr2=*afr2^((int)-(rand_seed*rand_seed))+9;
		if (!(*(++afr1)))
			afr1=rand1_tab;
		if (!(*(++afr2)))
			afr2=rand2_tab;
		if( ++RandCounter==32)
			{
			RandCounter = 0;
			AF_randomize(__FILE__,__LINE__);
			}
	}
	else
	{
		rand_seed=rand_seed^rand();
	}

	seed=rand_seed&127;

}

/******************************************************************************
*****************************************************************************/

void random_vector(float &a,float &b)
{
	double n;
	signed short ang=rand_seed&65535;
	float ab=modf(((float)ang/PI),&n);
	a=cos(ab);
	b=sin(ab);
}

/******************************************************************************
*****************************************************************************/

// Returns a random value of ( 0 -> (Range-1) )

int rand_range(int range)
{
	int rs=(seed*range)/128;
	return(rs);
}

/******************************************************************************
*****************************************************************************/
 
float calc_dist(float x,float y)
{
	float r;
	r=sqrt((x*x)+(y*y));
	if (r>0.1)
		return(r);
	else
		return(0.1);
}


