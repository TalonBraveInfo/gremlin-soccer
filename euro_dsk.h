#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>

// DAT offset file format type
// Values are little endian
struct offset_file_entry {
    uint32_t offset;
    uint32_t size;
};

std::vector<offset_file_entry> load_offset_file(const std::string &filename);

extern	FILE 			*fp2;
extern	signed int 	ReadLine( FILE *, char * );
extern	void			ReadDataOffsetFile( const char *);
extern	void			ReadData(int, const char *, BYTE * );
extern	void			LoadTexturePage(int, const char *, unsigned char, texture_info * );
extern	void			LoadPalette(int, const char *, int );
extern	void			LoadTactics(int, const char *, int *);
