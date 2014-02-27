#include "task3_1_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main( void )
{
	char *text, *word, *ptr;
	size_t len;

	text = Input();
	if( text == NULL )
	{
		puts( "Something wrong" );
		return 1;
	}

	ptr = word = FindMaxWord( text );
	len = 0;
	while( IsAlnum(*ptr++) )
	{
		len++;
	}

	word = memcpy( malloc( len + 1 ), word, len );
	if( word == NULL )
	{
		puts( "Memory is not enough" );
	}
	else
	{
		word[len] = 0;

		printf( "\"%s\" is the longest word\n", word );
		free( word );
	}
	free( text );

	return 0;
}