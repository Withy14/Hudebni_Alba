#ifndef HUDBADB_H_INCLUDED
#define HUDBADB_H_INCLUDED

#define MAX_VELIKOST 1000

struct t_hudba
{
    char  interpret[MAX_VELIKOST];
    char  album[MAX_VELIKOST];
    int   rok;
    struct t_hudba* dalsi;
};

void add( char * interpret, char  * album, int rok, struct t_hudba ** uk_prvni );
void del( int rok, struct t_hudba ** uk_prvni );


#endif // HUDBADB_H_INCLUDED
