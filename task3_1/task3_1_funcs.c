#include "task3_1_funcs.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char* StrChr( const char* str, char c )
{
	if( str == NULL )
	{
		return NULL;
	}

	while( *str )
	{
		if( *str == c )
		{
			return (char*)str;
		}
	}
	return NULL;
}

size_t StrLen( const char* str )
{
	size_t i;
	if( str == NULL )
	{
		return 0;
	}
	for( i=0; ; i++ )
	{
		if( *str == 0 )
		{
			break;
		}
		str++;
	}
	return i;
}

bool IsGraph( char chr )
{
	return chr >= 0x21 && chr <= 0x7E;
}

bool IsDigit( char chr )
{
	return chr >= 0x30 && chr <= 0x39;
}

bool IsUpper( char chr )
{
	return chr >= 0x41 && chr <= 0x5A;
}

bool IsLower( char chr )
{
	return chr >= 0x61 && chr <= 0x7A;
}

bool IsAlpha( char chr )
{
	return IsUpper(chr) || IsLower(chr);
}

bool IsAlnum( char chr )
{
	return IsDigit(chr) || IsAlpha(chr);
}

char* FindMaxWord( const char* str )
{
	size_t maxLen;
	const char* maxWord, *word;

	if( str == NULL )
	{
		return 0;
	}

	maxLen = 0;
	maxWord = str;

	while( *str )
	{
		size_t len;
		while( IsAlnum(*str) == false )
		{
			str++;
		}
		word = str;
		len = 0;
		while( IsAlnum(*str++) == true )
		{
			len++;
		}
		if( len > maxLen )
		{
			maxWord = word;
			maxLen = len;
		}
	}

	return (char*)maxWord;
}

#define BUF_LEN 256

char* Input( void )
{
	char buffer[BUF_LEN];
	char *str=NULL;
	size_t lastLen;

	puts( "Enter some text:" );
	
	lastLen = 0;

	for( ; ; )
	{
		size_t len;
		char *tmp;
		fgets( buffer, BUF_LEN, stdin );
		len = StrLen( buffer );
		//buffer[len - 1] = 0;

		if( len == 1 )
		{
			break;
		}

		if( buffer[len - 1] == '\n' )
		{
			len--;
		}

		tmp = realloc( str, lastLen + len + 1 );
		if( tmp == NULL )
		{
			free( str );
			return NULL;
		} 
		else
		{
			str = tmp;
		}
		memcpy( str + lastLen, buffer, len );
		lastLen += len;
		str[lastLen] = 0;
	}

	return str;
}

#undef BUF_LEN