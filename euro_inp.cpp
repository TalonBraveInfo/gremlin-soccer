#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "eurodefs.h"
#include "euro_fxd.h"
#include "euro.equ"
#include "euro_sym.h"
#include "euro_def.h"
#include "euro_var.h"
#include "euro_gen.h"
#include "euro_grf.h"
#include "euro_dsk.h"
#include "euro_fix.h"
#include "euro_sel.h"
#include "euro_inf.h"
#include "euro_cnt.h"
#include "euro_usr.h"
#include "euro_net.h"
#include "euro_spt.h"

#include "defines.h"

extern char return_doskey;



//********************************************************************************************************************************

short DoTextINPUT(char *string, short cursor, short MaxChars, char input, char state) {
#ifdef IMPLEMENT_ME
    return_doskey = TRUE;

    strcpy(TextEditBuffer, string);
    size_t StringLength = strlen(string);

    if (kbhit()) {

        if ((KeyInput[0] = (char) getch()) == 0)
            KeyInput[1] = (char) getch();

        // Function Key Controlers

        if (KeyInput[0] == 0) {

            //����������������������������������������ͻ
            //�               LEFT ARROW               �
            //����������������������������������������ͼ

            if (KeyInput[1] == L_ARROW && cursor > 0)
                cursor--;

            //����������������������������������������ͻ
            //�              RIGHT ARROW               �
            //����������������������������������������ͼ

            if (KeyInput[1] == R_ARROW && cursor < StringLength)
                cursor++;

            //����������������������������������������ͻ
            //�                  HOME                  �
            //����������������������������������������ͼ

            if (KeyInput[1] == HOME)
                cursor = 0;

            //����������������������������������������ͻ
            //�                  END                   �
            //����������������������������������������ͼ

            if (KeyInput[1] == END)
                cursor = (short) StringLength;

            //����������������������������������������ͻ
            //�                DELETE                  �
            //����������������������������������������ͼ

            if (KeyInput[1] == DELETE && cursor < StringLength)
                for (short c = cursor; c < StringLength + 1; c++) { TextEditBuffer[c] = TextEditBuffer[c + 1]; }
        } else

            // Normal Key Control

        {

            //����������������������������������������ͻ
            //�               BACKSPACE                �
            //����������������������������������������ͼ

            if (KeyInput[0] == B_SPACE && cursor > 0) {
                for (short c = cursor; c < StringLength + 1; c++) { TextEditBuffer[c - 1] = TextEditBuffer[c]; }
                cursor--;
            }


            //����������������������������������������ͻ
            //�                 RETURN                 �
            //����������������������������������������ͼ

            if (KeyInput[0] == RETURN)
                EuroTextEditState = 0;

            //����������������������������������������ͻ
            //�            NORMAL KEYPRESS             �
            //����������������������������������������ͼ

            if (KeyInput[0] > 31 &&
                KeyInput[0] < 128 &&
                StringLength < MaxChars &&
                state == ENABLE_INPUT) {
                if ((input == NORMAL) || (input == DIAL && LegalDial[KeyInput[0]] < 128)) {
                    if (cursor < (StringLength + 1))
                        for (short c = (short) (StringLength + 3); c > cursor; c--) { TextEditBuffer[c] = TextEditBuffer[c - 1]; }
                    TextEditBuffer[cursor] = KeyInput[0];
                    cursor++;
                }
            }
        }

        return_doskey = FALSE;
    }

    return (cursor);
#else
    return 0;
#endif
}

