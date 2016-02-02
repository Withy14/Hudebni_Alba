#include "HudbaDB.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct t_hudba * prvni = NULL;

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system ("clear");
#endif
}

void OnAdd()
{
    char my_interpret[MAX_VELIKOST], my_album[MAX_VELIKOST], my_tmpyear[MAX_VELIKOST];
    int my_year = 0; /**
                      *  minimalni osetreni pro nespravny rok,
                      */
    printf("\nInterpret : ");
    scanf(" %[^\n]s", my_interpret);
    printf("\nAlbum : ");
    scanf(" %[^\n]s", my_album);
    printf("\nRok : ");
    scanf(" %[^\n]s", my_tmpyear);
    sscanf(my_tmpyear,"%d", &my_year);
    add( my_interpret, my_album, my_year, &prvni );
}

void OnDel()
{
    int my_year;

    printf("\nRok : ");
    scanf("%d", &my_year);
    del( my_year, &prvni );
}

void ShowMusic()
{
    struct t_hudba * aktMusic = prvni;
    printf("\n\n");
    while ( aktMusic )
    {
        printf( "%s: %s, %d\n", aktMusic->interpret, aktMusic->album, aktMusic->rok );
        aktMusic = aktMusic->dalsi;
    }
    fflush(stdin);
    getchar();
}


int main()
{
    char  cmd;

    do
    {
        clear_screen();
        printf("A: Pridat     ");
        printf("D: Smazat     ");
        printf("P: Tisk     ");
        printf("Q: Konec\n\n");

        fflush(stdin);
        cmd = tolower(getchar());
        switch (cmd)
        {
        case 'a':
            OnAdd();
            break;
        case 'd':
            OnDel();
            break;
        case 'p':
            ShowMusic();
            break;
        }
        getchar(); /** vycisti buffer, narozdil od ffluch(stdin) funguje i v Unix systemech */
    }
    while(cmd != 'q');
    return 0;
}
