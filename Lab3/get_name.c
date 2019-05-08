#include <stdio.h>
#include <stdlib.h>

char* get_name( void )
{
  printf( "Please enter your name: " );

 
  char line[1024];
  
 
  if( fgets( line, 1024, stdin ) == 0 ) // we ALWAYS check for I/O errors
  {
    perror( "failed to read a name" );
    exit(1);
  }
  
  return line; 
}	

void stuff()
{

  int stuff[1000];
  
  for( int i=0; i<1000; i++ )
    stuff[i] = rand();
}


int main( void )
{
  char* name = get_name();


  printf( "Your name is %s\n", name );

  stuff();


  printf( "Your name is %s\n", name );

  return 0;
}	       
