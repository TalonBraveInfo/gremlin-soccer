extern	FILE 			*fp2;
extern	signed int 	ReadLine( FILE *, char * );
extern	void			ReadDataOffsetFile( const char *);
extern	void			ReadData(int, const char *, BYTE * );
extern	void			LoadTexturePage(int, const char *, unsigned char, texture_info * );
extern	void			LoadPalette(int, const char *, int );
extern	void			LoadTactics(int, const char *, int *);
