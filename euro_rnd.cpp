#include <stdlib.h>
#include "eurodefs.h"
#include "euro_fxd.h"
#include "euro.equ"
#include "euro_sym.h"
#include "euro_def.h"
#include "euro_var.h"
#include "defines.h"

//********************************************************************************************************************************

//������������������������������������������������������������������������ͻ
//�                                                                        �
//� Random number method 1 -> originates from Mike Hart, slightly modified �
//�                                                                        �
//������������������������������������������������������������������������ͼ

short GetRnd1() {
    long rnd = EUROseed1;

    if (rnd == 0)
        rnd = 0x024272;
    if (rnd > 2147483648) {
        rnd += rnd;
        rnd ^= 0x01d872b45;
    } else
        rnd += rnd;

    EUROseed1 = rnd + 7;
    return ((short) EUROseed1);
}

//********************************************************************************************************************************

//����������������������ͻ
//�                      �
//� Watcom Random number �
//�                                                             �
//�������������������������������������������������������������ͼ

unsigned short GetRnd2() {
    return ((unsigned short) rand());
}

//********************************************************************************************************************************

//�������������������������������������������������������������ͻ
//�                                                             �
//� Random number method 3 -> originates from Zool GameGear Z80 �
//�                                                             �
//�������������������������������������������������������������ͼ

unsigned short GetRnd3() {
    short t2 = (short) (EUROseed3 * 32);
    short t3 = (short) ((EUROseed3 * 16) - EUROseed3);
    t3 = (short) ((((((t3 - t2) * 8) + EUROseed3) * 4) + EUROseed3) + 0x01d872b45);
    EUROseed3 = (unsigned short) t3;
    return (unsigned short) (t3);
}

//********************************************************************************************************************************
