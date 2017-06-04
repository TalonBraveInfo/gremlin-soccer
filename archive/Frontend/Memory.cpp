#include "Frontend Vars.h"
#include "Memory.h"

#undef EXTERN
#define EXTERN extern
#include "Blitter.h"
#include "FileUtils.h"
#include "Front Variables.h"
#include "Mallocx.h"
#include "Not Written Yet.h"
#include "Resource.h"
#include "Use DrawSprockets.h"

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  DeAllocate_memory()                                                                                                           บ
//บ																 บ
//บ																 บ
//บ		DeAllocates memory used by menu.                                                                                  บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	DeAllocate_memory()
{
	FreeX(filter_buffer);
	FreeX(proptab_buffer);
	FreeX(texture_buffer);
	FreeX(sfont_buffer);
	FreeX(bfont_buffer);
	FreeX(mfont_buffer);
	FreeX(unpack_buffer);
	FreeX(background_buffer);
	FreeX(spool_buffer);
	FreeX(sprite_buffer);

	HeapPurge();

	sprite_buffer = spool_buffer = texture_buffer = sfont_buffer = NULL;
	bfont_buffer = mfont_buffer = unpack_buffer = background_buffer = NULL;
	proptab_buffer = NULL;
}

//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป 
//บ                                                                                                                              บ
//บ  Allocate_memory()                                                                                                           บ
//บ																 บ
//บ																 บ
//บ		Allocates memory for menu data.                                                                                  บ
//บ																 บ
//บ																 บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ 
void	Allocate_memory()
{
	UseResFile(dataResFile);
	
	filter_buffer = (BYTE *)LoadBinary( RESTYPE_DATA, NORMRES(BIN_FILTER));
	proptab_buffer = (BYTE *)LoadBinary( RESTYPE_DATA, NORMRES(BIN_PROPTAB));
	texture_buffer = (BYTE *)LoadBinary( RESTYPE_DATA, NORMRES(BIN_TEXTURE));
	sfont_buffer = (BYTE *)LoadBinary( RESTYPE_DATA, NORMRES(BIN_SFONT));
	bfont_buffer = (BYTE *)LoadBinary( RESTYPE_DATA, NORMRES(BIN_BFONT));
	mfont_buffer = (BYTE *)LoadBinary( RESTYPE_DATA, NORMRES(BIN_MFONT));
	spool_buffer = (BYTE *)LoadBinary( RESTYPE_DATA, NORMRES(BIN_BIGSPOOL));
	sprite_buffer = (BYTE *)LoadBinary( RESTYPE_DATA, NORMRES(BIN_SPRITE));
	background_buffer = (BYTE *) MallocX( background_buffer_LEN );
	unpack_buffer = (BYTE *) MallocX( unpack_buffer_LEN );

	psudo_buffer = (BYTE *)screenptr;
	UseResFile(mainResFile);
}
