EXTERN int matherr(struct exception *);
#if GAME_DEBUG==ON
EXTERN void AF_randomize( char *x, int y);
#else
EXTERN void af_randomize(void);
#endif
EXTERN void random_vector(float &a,float &b);
EXTERN int rand_range(int range);
EXTERN float calc_dist(float x,float y);

EXTERN int RandCounter;
