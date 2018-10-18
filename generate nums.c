#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<math.h>
void createFile(FILE *fp,int noofr,char *str)
{
    int i, j ;
    fp = fopen ( str, "wb" ) ;
    if ( fp == NULL )
    {
        printf ( "Unable to create file." ) ;
        getch( ) ;
        exit ( 0 ) ;
    }
    for ( i = 0 ; i < noofr ; i++ )
    {
        j = rand ( ) ;
        fwrite ( &j, sizeof ( int ), 1, fp ) ;
        printf ( "%d\t", j ) ;
    }
    fclose ( fp ) ;
}
void main( )
{
    FILE *fp ;
    char str [ 67 ] ;
    int i, noofr, j ;
    printf ( "Enter file name: " ) ;
    scanf ( "%s", str ) ;
    printf ( "Enter number of records: " ) ;
    scanf ( "%d", &noofr ) ;
    createFile(fp,noofr,str); //create new file
    printf ( "\nFile is created. \nPress any key to continue." ) ;
}
