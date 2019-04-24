/*
 Copyright (C) Information Equipment co.,LTD.
 All rights reserved.
 Code by JaeHyuk Cho <mailto:minzkn@infoeq.com>
 CVSTAG="$Header: /usr/local/mutihost/joinc/modules/moniwiki/data/text/RCS/Code_2fC_2fbase64,v 1.2 2007/01/24 02:16:30 root Exp root $"

 - Simple is best !
*/

#if !defined(__def_mzapi_source_base64_c__)
#define __def_mzapi_source_base64_c__ "base64.c"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#include <string.h>

#if !defined(__mzapi_peek_vector__)
# define __mzapi_peek_vector__(m_cast,m_base,m_sign,m_offset)         ((m_cast)(((unsigned char *)(m_base)) m_sign (size_t)(m_offset)))
#endif
#if !defined(mzapi_peek_byte)
# define mzapi_peek_byte(m_base,m_offset)                             (*__mzapi_peek_vector__(unsigned char *,m_base,+,m_offset))
#endif
#if !defined(mzapi_poke_byte)
# define mzapi_poke_byte(m_base,m_offset,m_value)                     (*__mzapi_peek_vector__(unsigned char *,m_base,+,m_offset)) = (unsigned char)(m_value)
#endif

static unsigned long (__mzapi_decode_base64__)(int s_character);
char * (mzapi_encode_base64)(const char * s_string);
char * (mzapi_decode_base64)(const char * s_string);
int main(int s_argc, char **s_argv);

static unsigned long (__mzapi_decode_base64__)(int s_character) 
{
      if((s_character) >= ((int)'a'))return((((unsigned long)(s_character)) - ((unsigned long)'a')) + 26lu); 
 else if((s_character) >= ((int)'A'))return(((unsigned long)(s_character)) - ((unsigned long)'A'));
 else if((s_character) >= ((int)'0'))return((((unsigned long)(s_character)) - ((unsigned long)'0')) + 52lu);
 else if((s_character) == ((int)'+'))return(62lu);
 else if((s_character) == ((int)'/'))return(63lu);
 return(0lu);
}

char * (mzapi_encode_base64)(const char * s_string)
{
 static const unsigned char c_alpha_table[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
 char * s_result;
 size_t s_length = strlen(s_string), s_source_offset = (size_t)0, s_target_offset = (size_t)0;
 unsigned long s_value;
 int s_quad, s_trip;
 s_result = (char *)malloc((((s_length + ((size_t)2)) / ((size_t)3)) << 2) + ((size_t)1));
 if(s_result == ((char *)0))return((char *)0);
 while(s_source_offset < s_length)
 {
  s_value = ((unsigned long)(mzapi_peek_byte((void *)s_string, s_source_offset) & ((int)0xff))) << 8; 
  if((s_source_offset + ((size_t)1)) < s_length)
  {
   s_value |= (unsigned long)(mzapi_peek_byte((void *)s_string, s_source_offset + ((size_t)1)) & ((int)0xff)); 
   s_trip = (int)1;
  }
  else s_trip = (int)0;
  s_value <<= 8;
  if((s_source_offset + ((size_t)2)) < s_length)
  {
   s_value |= (unsigned long)(mzapi_peek_byte((void *)s_string, s_source_offset + ((size_t)2)) & ((int)0xff)); 
   s_quad = (int)1;
  }
  else s_quad = (int)0;
  mzapi_poke_byte((void *)s_result, s_target_offset + ((size_t)3), (int)c_alpha_table[(s_quad == (int)1) ? (s_value & 0x3flu) : 64]);
  s_value >>= 6;
  mzapi_poke_byte((void *)s_result, s_target_offset + ((size_t)2), (int)c_alpha_table[(s_trip == (int)1) ? (s_value & 0x3flu) : 64]);
  s_value >>= 6;
  mzapi_poke_byte((void *)s_result, s_target_offset + ((size_t)1), (int)c_alpha_table[s_value & 0x3flu]);
  s_value >>= 6;
  mzapi_poke_byte((void *)s_result, s_target_offset, (int)c_alpha_table[s_value & 0x3flu]);
  s_source_offset += (size_t)3, s_target_offset += (size_t)4;
 }
 mzapi_poke_byte((void *)s_result, s_target_offset, (int)'\0');
 return(s_result);
}

char * (mzapi_decode_base64)(const char * s_string)
{
 char * s_result;
 size_t s_length = strlen(s_string), s_source_offset = (size_t)0, s_target_offset = (size_t)0;
 unsigned long s_value;
 s_result = (char *)malloc((((s_length + ((size_t)3)) >> 2) * ((size_t)3)) + ((size_t)1));
 if(s_result == ((char *)0))return((char *)0);
 while(s_source_offset < s_length)
 {
  s_value  = ((__mzapi_decode_base64__(mzapi_peek_byte((void *)s_string, s_source_offset)) & 0x3flu) << 18) |
             ((__mzapi_decode_base64__(mzapi_peek_byte((void *)s_string, s_source_offset + ((size_t)1))) & 0x3flu) << 12) |
             ((__mzapi_decode_base64__(mzapi_peek_byte((void *)s_string, s_source_offset + ((size_t)2))) & 0x3flu) << 6) |
             (__mzapi_decode_base64__(mzapi_peek_byte((void *)s_string, s_source_offset + ((size_t)3))) & 0x3flu);
  mzapi_poke_byte((void *)s_result, s_target_offset++, (int)((s_value >> 16) & 0xfflu));
  if(mzapi_peek_byte((void *)s_string, s_source_offset + ((size_t)2)) != ((int)'='))
  {
   mzapi_poke_byte((void *)s_result, s_target_offset++, (int)((s_value >> 8) & 0xfflu));
   if(mzapi_peek_byte((void *)s_string, s_source_offset + ((size_t)3)) != ((int)'='))mzapi_poke_byte((void *)s_result, s_target_offset++, (int)(s_value & 0xfflu));
  } 
  s_source_offset += (size_t)4;
 }
 mzapi_poke_byte((void *)s_result, s_target_offset, (int)'\0');
 return(s_result);
}


/// OBFUSCATED BY OMNI OBFUSCATOR V1.2.1712.19, SEED VALUE: 898482980


/// OMNI GENERATED COMMON CODE FOR ALL FUNCTIONS

// Common file to be included before obfuscation
// NOTE: This file could be changed between versions. You should include it from obfuscator directory
#ifndef __OMNI_COMMON_INCLUDED
#define __OMNI_COMMON_INCLUDED

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#ifndef __GNUC__
#define __attribute__( x )
#define __attribute( x )
#endif

#ifndef __cplusplus

// C frontend basic support
#ifndef bool
typedef unsigned char bool;
#define false 0
#define true 1
#endif

#define OMNI_INLINE_FUNCTION static
#define OMNI_GLOBAL_SCOPE
#define OMNI_THROWS

#else

#define OMNI_INLINE_FUNCTION inline
#define OMNI_GLOBAL_SCOPE ::

// Throw support for MSVC 7.0+
#if defined _MSC_VER && _MSC_VER >= 1300
#define OMNI_THROWS   throw(...)
#else
#define OMNI_THROWS		
#endif

// Placement new support in case of new is not included.
#if !defined USE_STD_NEW && !defined __PLACEMENT_NEW_INLINE && !defined _NEW && !defined __NEW__
inline void *operator new( size_t size, void *p ) { return p; };
inline void operator delete(void *, void * ) { };
#endif

#endif

// int64 support
#if defined _MSC_VER && _MSC_VER < 1310
#define OMNI__INT64 __int64
#define OMNI__CONST64(X) X##i64
#else
#define OMNI__INT64 long long
#define OMNI__CONST64(X) X##LL
#endif

// Abs functions
OMNI_INLINE_FUNCTION OMNI__INT64 omni_abs64( OMNI__INT64 a )
{
	return a < 0 ? -a : a;
}

OMNI_INLINE_FUNCTION ptrdiff_t omni_ptrdiffabs( ptrdiff_t a )
{
	return a < 0 ? -a : a;
}

OMNI_INLINE_FUNCTION long double omni_ldabs( long double a )
{
	return a < 0. ? -a : a;
}

// Assertion function
static void __omni_assert( bool b ) { b; }

// Support for MSVC standard library
#ifdef _MSC_VER

#if _MSC_VER < 1400
#ifdef __cplusplus
inline void *operator new[]( size_t size ) { return operator new( size ); }
inline void operator delete[]( void *ptr ) { operator delete( ptr ); }
#endif
#endif

#if _MSC_VER >= 1400
#define _iob __iob_func()
#endif

#define __errno_location _errno

#pragma warning( disable: 4100 4101 4102 4189 4302 4311 4312 4700 4701 4702 4800 )

#endif

// Builtin functions support for VC
#ifdef _MSC_VER
#ifdef HUGE_VAL
inline double __builtin_huge_val() { return HUGE_VAL; }
#endif
#endif

// Support for GCC (from GCC windows.h)
#ifdef __GNUC__
#ifndef _fastcall
#define _fastcall __attribute__((fastcall))
#endif
#ifndef __fastcall
#define __fastcall __attribute__((fastcall))
#endif
#ifndef _stdcall
#define _stdcall __attribute__((stdcall))
#endif
#ifndef __stdcall
#define __stdcall __attribute__((stdcall))
#endif
#ifndef _cdecl
#define _cdecl __attribute__((cdecl))
#endif
#ifndef __cdecl
#define __cdecl __attribute__((cdecl))
#endif
#ifndef __declspec
#define __declspec(e) __attribute__((e))
#endif
#ifndef _declspec
#define _declspec(e) __attribute__((e))
#endif
#endif

#endif




// Obfuscated function
int main( int s_argc_0, char **s_argv_1 )
{
    int D3060_2;
    char **D3065_3;
    unsigned OMNI__INT64 D3066_4;
    int D3067_5;
    OMNI_GLOBAL_SCOPE FILE *D3068_6;
    char *D3069_7;
    unsigned OMNI__INT64 D3070_8;
    int D3071_9;
    OMNI_GLOBAL_SCOPE FILE *D3072_10;
    char *D3073_11;
    unsigned OMNI__INT64 D3074_12;
    int D3075_13;
    OMNI_GLOBAL_SCOPE FILE *D3076_14;
    int D3077_15;
    static char s_default_16[41] = "This is base64 test function - by minzkn";
    char *s_this_17;
    char *s_encode_18;
    char *s_decode_19;
    bool temp_20;
    int temp_21;
    char **temp_22;
    unsigned OMNI__INT64 temp_23;
    char *temp_24;
    size_t temp_25;
    OMNI_GLOBAL_SCOPE FILE *temp_28;
    int temp_29;
    int temp_30;
    char const *temp_32 = "original: \"%s\" (%d)\n";
    char *temp_33;
    bool temp_35;
    char *temp_36;
    size_t temp_37;
    OMNI_GLOBAL_SCOPE FILE *temp_38;
    int temp_39;
    int temp_40;
    char const *temp_41 = "encode  : \"%s\" (%d)\n";
    char *temp_42;
    bool temp_44;
    char *temp_45;
    size_t temp_46;
    OMNI_GLOBAL_SCOPE FILE *temp_47;
    int temp_48;
    int temp_49;
    char const *temp_50 = "decode  : \"%s\" (%d)\n";
    
    L1:
    L0:
    goto L2;
    
    L2:
    temp_21 = (int)1;
    temp_20 = s_argc_0 > temp_21;
    if (temp_20) goto L4; else goto L6;
    
    L4:
    temp_23 = (unsigned OMNI__INT64)1u;
    temp_22 = s_argv_1 + temp_23;
    D3065_3 = (char **)temp_22;
    temp_24 = *D3065_3;
    s_this_17 = (char *)temp_24;
    goto L8;
    
    L6:
    s_this_17 = ( char * )(s_default_16);
    goto L8;
    
    L8:
    temp_25 = ( size_t )strlen( ( char const * )s_this_17 );
    D3066_4 = ( unsigned OMNI__INT64 )(temp_25);
    D3067_5 = ( int )(D3066_4);
    temp_29 = (int)1;
    temp_28 = &_iob[ temp_29 ];
    D3068_6 = (OMNI_GLOBAL_SCOPE FILE *)temp_28;
    temp_30 = ( int )fprintf( ( OMNI_GLOBAL_SCOPE FILE * )D3068_6, ( char const * )temp_32, s_this_17, D3067_5 );
    temp_33 = ( char * )mzapi_encode_base64( ( char const * )s_this_17 );
    D3069_7 = (char *)temp_33;
    s_encode_18 = (char *)D3069_7;
    temp_36 = (char *)0u;
    temp_35 = s_encode_18 != temp_36;
    if (temp_35) goto L10; else goto L20;
    
    L10:
    temp_37 = ( size_t )strlen( ( char const * )s_encode_18 );
    D3070_8 = ( unsigned OMNI__INT64 )(temp_37);
    D3071_9 = ( int )(D3070_8);
    temp_39 = (int)1;
    temp_38 = &_iob[ temp_39 ];
    D3072_10 = (OMNI_GLOBAL_SCOPE FILE *)temp_38;
    temp_40 = ( int )fprintf( ( OMNI_GLOBAL_SCOPE FILE * )D3072_10, ( char const * )temp_41, s_encode_18, D3071_9 );
    temp_42 = ( char * )mzapi_decode_base64( ( char const * )s_encode_18 );
    D3073_11 = (char *)temp_42;
    s_decode_19 = (char *)D3073_11;
    temp_45 = (char *)0u;
    temp_44 = s_decode_19 != temp_45;
    if (temp_44) goto L14; else goto L18;
    
    L14:
    temp_46 = ( size_t )strlen( ( char const * )s_decode_19 );
    D3074_12 = ( unsigned OMNI__INT64 )(temp_46);
    D3075_13 = ( int )(D3074_12);
    temp_48 = (int)1;
    temp_47 = &_iob[ temp_48 ];
    D3076_14 = (OMNI_GLOBAL_SCOPE FILE *)temp_47;
    temp_49 = ( int )fprintf( ( OMNI_GLOBAL_SCOPE FILE * )D3076_14, ( char const * )temp_50, s_decode_19, D3075_13 );
    free( ( void * )s_decode_19 );
    goto L18;
    
    L18:
    free( ( void * )s_encode_18 );
    goto L20;
    
    L20:
    D3077_15 = (int)0;
    return D3077_15;
    
}




#endif

/* End of source */
