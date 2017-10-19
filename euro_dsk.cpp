#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

#include "eurodefs.h"
#include "euro_fxd.h"
#include "mallocx.h"
#include "euro_sym.h"
#include "euro_def.h"
#include "euro_var.h"
#include "euro.equ"
#include "euro_dsk.h"

FILE *fp2;            // symbol creation file.

static std::vector<offset_file_entry> Offset_table;

//********************************************************************************************************************************

signed int ReadLine(FILE *fp, char *buf) {
    signed char c;
    buf[0] = 0;
    int nc = 0;

    while ((((c = (signed char) fgetc(fp)) != LF) && (c != EOF))) {

        if (c == LF || c == 255)
            *(buf++) = 0;
        else {
            *(buf++) = c;
            nc++;
        }
    }
    if (c == EOF) nc = -1;
    return (nc);
}

/* Loads an offset (.OFF) file and returns the offsets.
 * Throws on error.
*/
std::vector<offset_file_entry> load_offset_file(const std::string &filename) {
    std::vector<offset_file_entry> offsets;

    std::ifstream offset_fh;
    offset_fh.exceptions(std::ifstream::badbit);

    offset_fh.open(filename.c_str(), std::ifstream::binary);

    offset_file_entry ofe;
    while (!offset_fh.read((char*)(&ofe), sizeof(ofe)).eof()) {
        offsets.push_back(ofe);
    }

    return offsets;
}

DATFile::DATFile(const std::string &dat_filename, const std::string &off_filename) {
    this->dat_filename = dat_filename;
    this->off_filename = off_filename;

    offset_table = load_offset_file(off_filename);

    dat_fh.exceptions(std::ifstream::badbit);
    dat_fh.open(dat_filename.c_str(), std::ifstream::binary);
}

size_t DATFile::read_whole_chunk(unsigned chunk_no, void *buf, size_t bufsize) {
    if((chunk_no / 8) >= offset_table.size()) {
        fprintf(stderr, "Tried reading chunk %u/%u from %s\n", (chunk_no / 8), (unsigned)(offset_table.size()), dat_filename.c_str());
        return 0;
        abort();
    }

    chunk_no /= 8;

    size_t chunk_size   = offset_table[chunk_no].size;
    size_t chunk_offset = offset_table[chunk_no].offset;

    dat_fh.clear();

    dat_fh.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    dat_fh.seekg(chunk_offset);

    if(chunk_size > bufsize) {
        fprintf(stderr, "Warning: Reading %lu/%lu bytes from %s:%u\n",
                (unsigned long)(bufsize), (unsigned long)(chunk_size),
                dat_filename.c_str(), chunk_no);
    }

    size_t to_read = std::min(bufsize, chunk_size);

    dat_fh.exceptions(std::ifstream::badbit | std::ifstream::failbit | std::ifstream::eofbit);
    dat_fh.read((char*)(buf), to_read);

    return dat_fh.gcount();
}

size_t DATFile::read_partial_chunk(unsigned chunk_no, void *buf, size_t offset, size_t want_size) {
    if((chunk_no / 8) >= offset_table.size()) {
        abort();
    }

    chunk_no /= 8;

    if(offset > offset_table[chunk_no].size) {
        fprintf(stderr, "Warning: Tried reading past end of %s:%u\n", dat_filename.c_str(), chunk_no);
        return 0;
    }

    size_t chunk_size   = offset_table[chunk_no].size   - offset;
    size_t chunk_offset = offset_table[chunk_no].offset + offset;

    if(chunk_size < want_size)
    {
        fprintf(stderr, "Warning: Expected to read %lu bytes from %s:%u, but only %lu are available\n",
                (unsigned long)(want_size),
                dat_filename.c_str(), chunk_no,
                (unsigned long)(chunk_size));
    }

    dat_fh.clear();

    dat_fh.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    dat_fh.seekg(chunk_offset);

    size_t to_read = std::min(want_size, chunk_size);

    dat_fh.exceptions(std::ifstream::badbit | std::ifstream::failbit | std::ifstream::eofbit);
    dat_fh.read((char*)(buf), to_read);

    return dat_fh.gcount();
}

/* Replace the global offset table. This API is deprecated. */
void ReadDataOffsetFile(const char *filename) {
    try {
        Offset_table = load_offset_file(filename);
    }
    catch(const std::exception &e)
    {
        printf("Error loading Data Offset file %s: %s\n", filename, e.what());
    }
}

/* Read a file from a DAT file using the global offset table. This API is deprecated. */
void ReadData(int file, const char *filename, BYTE *buffer) {
    if((file / 8) >= Offset_table.size())
    {
        printf("Attempted to load file %d (%d), but Offset_table only has %lu elements\n",
               file, (file / 8), (unsigned long)(Offset_table.size()));
        return;
    }

    FILE *fd = fopen(filename, "rb");
    if (fd != nullptr) {
        long seek_pos = Offset_table[file / 8].offset;
        size_t file_size = Offset_table[file / 8].size;
        fseek(fd, seek_pos, SEEK_SET);
        fread(buffer, sizeof(BYTE), file_size, fd);
    } else
        printf("Error loading from Datafile.\n");

    fclose(fd);
}

//********************************************************************************************************************************

void LoadTexturePage(int file, const char *filename, unsigned char Page, texture_info *texture) {
    if (Page < TexturePagesAvailable)
        ReadData(file, filename, texture->page_start + (texture->page_width * texture->page_height * Page));
    else
        printf("ERROR... trying to access texture page: %d, when only %d page(s) exist\n",
               Page, TexturePagesAvailable);
}

//********************************************************************************************************************************

void LoadPalette(int file, const char *filename, int offset) {
    ReadData(file, filename, &PaletteBuffer[(offset * 3)]);
}

//********************************************************************************************************************************

void LoadTactics(int tactic, const char *filename, int *buffer) {
    ReadData((tactic * 8) + TAC_TAC_316, filename, (BYTE *) buffer);
}

//********************************************************************************************************************************

void SaveGameData(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp != nullptr) {
        fwrite(SquadInfo, sizeof(char), 16 * 20, fp);
        fwrite(FormationInfo, sizeof(char), 16, fp);
        fwrite(GroupDrawInfo, sizeof(char), 16, fp);
        fwrite(LeagueTable, sizeof(League_info), 16, fp);
        fwrite(&NoOfSubs, sizeof(char), 1, fp);
        fwrite(&WinPts, sizeof(char), 1, fp);
        fwrite(&DrawPts, sizeof(char), 1, fp);
        fwrite(&MatchNumber, sizeof(MatchNumber), 1, fp);
        fclose(fp);
    }
}

//********************************************************************************************************************************

void LoadGameData(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp != nullptr) {
        fread(SquadInfo, sizeof(char), 16 * 20, fp);
        fread(FormationInfo, sizeof(char), 16, fp);
        fread(GroupDrawInfo, sizeof(char), 16, fp);
        fread(LeagueTable, sizeof(League_info), 16, fp);
        fread(&NoOfSubs, sizeof(char), 1, fp);
        fread(&WinPts, sizeof(char), 1, fp);
        fread(&DrawPts, sizeof(char), 1, fp);
        fread(&MatchNumber, sizeof(MatchNumber), 1, fp);
        fclose(fp);
    }
}

//********************************************************************************************************************************



















