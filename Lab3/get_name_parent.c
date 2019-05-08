#include <stdio.h>
#include <stdlib.h>

void get_name( char line[], int maxlen )
{
  printf( "Please enter your name: " );


  if( fgets( line, maxlen, stdin ) == 0 ) 
  {
    perror( "failed to read a name" );
    exit(1);
  }
}	

void stuff()
{

  int stuff[1000];
  
  for( int i=0; i<1000; i++ )
    stuff[i] = rand();
}

int main( void )
{
  char name[1024];
  get_name( name, 1024 );


  printf( "Your name is %s", name );

  stuff();


  printf( "Your name is %s", name );

  return 0;
}	       
