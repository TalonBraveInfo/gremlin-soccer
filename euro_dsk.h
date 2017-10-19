#include <fstream>
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

class DATFile {
    private:
        std::string dat_filename;
        std::ifstream dat_fh;

        std::string off_filename;
        std::vector<offset_file_entry> offset_table;

    public:
        DATFile(const std::string &dat_filename, const std::string &off_filename);

        size_t read_whole_chunk(unsigned chunk_no, void *buf, size_t bufsize);
        size_t read_partial_chunk(unsigned chunk_no, void *buf, size_t offset, size_t want_size);

        size_t chunk_size(unsigned chunk_no) {
            return offset_table[chunk_no / 8].size;
        }
};

extern	FILE 			*fp2;
extern	signed int 	ReadLine( FILE *, char * );
extern	void			ReadDataOffsetFile( const char *);
extern	void			ReadData(int, const char *, BYTE * );
extern	void			LoadTexturePage(int, const char *, unsigned char, texture_info * );
extern	void			LoadPalette(int, const char *, int );
extern	void			LoadTactics(int, const char *, int *);
