#ifndef TASK3_1_FUNCS_H
#define TASK3_1_FUNCS_H

#ifndef __cplusplus
typedef unsigned char bool;
#define true ((bool)1)
#define false ((bool)0)
#endif /* __cplusplus */

#ifndef NULL
#define NULL (void*)0
#endif /* NULL */

#ifndef _SIZE_T_DEFINED
#ifdef  _WIN64
typedef unsigned long long int    size_t;
#else
typedef unsigned int   size_t;
#endif
#define _SIZE_T_DEFINED
#endif

char* StrChr( const char* str, char c );
size_t StrLen( const char* str );
bool IsGraph( char chr );
bool IsDigit( char chr );
bool IsUpper( char chr );
bool IsLower( char chr );
bool IsAlpha( char chr );
bool IsAlnum( char chr );

char* FindMaxWord( const char* str );

char* Input( void );

#endif /* TASK3_1_FUNCS_H */