#include <stdio.h>


/// OBFUSCATED BY OMNI OBFUSCATOR V1.2.1712.19, SEED VALUE: 1502819753


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

static void omni_global_function( void *temp_57, void *temp_58, void *temp_59, void *temp_60, void *temp_61, void 
    *temp_62, void *temp_63, void *temp_64, void *temp_65, void *temp_66, void *temp_67, void *temp_68, void *temp_69, void 
    *temp_70, void *temp_71, void *temp_72, void *temp_73, void *temp_74, void *temp_75, void *temp_76 ) OMNI_THROWS;



// Obfuscated function
int main( void )
{
    char const *temp_4 = "Hello";
    bool temp_5;
    unsigned int temp_6;
    unsigned int temp_7;
    unsigned int temp_8;
    bool temp_12;
    bool temp_13;
    int temp_22;
    unsigned int temp_23;
    int temp_24;
    int temp_25;
    unsigned int temp_26;
    unsigned int temp_27;
    bool state0_28;
    bool state1_29;
    bool state2_30;
    bool state3_31;
    bool state4_32;
    bool state5_33;
    bool state6_34;
    bool state7_35;
    unsigned int temp_36;
    void *temp_92;
    void *temp_93;
    void *temp_94;
    void *temp_95;
    void *temp_96;
    void *temp_97;
    void *temp_98;
    void *temp_99;
    void *temp_100;
    void *temp_101;
    void *temp_102;
    void *temp_103;
    void *temp_104;
    void *temp_105;
    void *temp_106;
    void *temp_107;
    void *temp_108;
    void *temp_109;
    void *temp_110;
    void *temp_111;
    
    L77:
    L76:
    temp_36 = (unsigned int)3175u;
    temp_8 = (unsigned int)78u;
    temp_36 = temp_36 - temp_8;
    goto L80;
    
    L80:
    switch( temp_36)
    {
    case 3175u: goto L76;
    default: goto L79;
    }
    
    L79:
    {
        
        L78:
        temp_111 = &temp_27;
        temp_110 = &temp_26;
        temp_109 = &temp_25;
        temp_108 = &temp_24;
        temp_107 = &temp_23;
        temp_106 = &temp_22;
        temp_105 = &temp_13;
        temp_104 = &temp_12;
        temp_103 = &temp_7;
        temp_102 = &temp_6;
        temp_101 = &temp_4;
        temp_100 = &state7_35;
        temp_99 = &state6_34;
        temp_98 = &state5_33;
        temp_97 = &state4_32;
        temp_96 = &state3_31;
        temp_95 = &state2_30;
        temp_94 = &state1_29;
        temp_93 = &state0_28;
        temp_92 = &temp_36;
        omni_global_function( ( void * )temp_92, ( void * )temp_93, ( void * )temp_94, ( void * )temp_95, ( void * )temp_96, 
            ( void * )temp_97, ( void * )temp_98, ( void * )temp_99, ( void * )temp_100, ( void * )temp_101, 
            ( void * )temp_102, ( void * )temp_103, ( void * )temp_104, ( void * )temp_105, ( void * )temp_106, 
            ( void * )temp_107, ( void * )temp_108, ( void * )temp_109, ( void * )temp_110, ( void * )temp_111 );
        goto L84;
        
        L84:
        switch( temp_36)
        {
        case 1555u: goto L90;
        default: goto L86;
        }
        
        L86:
        return temp_24;
        
        L90:
        return temp_24;
        
    }

}




// Obfuscator generated function
static void omni_global_function( void *temp_57, void *temp_58, void *temp_59, void *temp_60, void *temp_61, void 
    *temp_62, void *temp_63, void *temp_64, void *temp_65, void *temp_66, void *temp_67, void *temp_68, void *temp_69, void 
    *temp_70, void *temp_71, void *temp_72, void *temp_73, void *temp_74, void *temp_75, void *temp_76 ) OMNI_THROWS
{
    unsigned int temp_37;
    bool temp_38;
    bool temp_39;
    bool temp_40;
    bool temp_41;
    bool temp_42;
    bool temp_43;
    bool temp_44;
    bool temp_45;
    char const *temp_46;
    unsigned int temp_47;
    unsigned int temp_48;
    bool temp_49;
    bool temp_50;
    int temp_51;
    unsigned int temp_52;
    int temp_53;
    int temp_54;
    unsigned int temp_55;
    unsigned int temp_56;
    bool temp_83;
    unsigned int temp_84;
    unsigned int temp_85;
    unsigned int temp_86;
    unsigned int temp_87;
    unsigned int temp_88;
    unsigned int temp_89;
    bool temp_90;
    bool temp_91;
    unsigned int *temp_77;
    unsigned char *temp_78;
    unsigned char temp_79;
    unsigned char temp_80;
    char const **temp_81;
    int *temp_82;
    void *temp_112[70];
    void **temp_113;
    size_t temp_114;
    void *temp_115;
    unsigned int temp_116;
    unsigned int temp_117;
    unsigned int temp_118;
    void *temp_119;
    bool temp_120;
    static unsigned int omni_virtualcode_121[148] = { 2286604837u, 3780993715u, 3545770887u, 1800916897u, 3384155828u, 1030196403u, 4001335495u, 1689400223u, 314795395u, 
        1474289952u, 450278448u, 1494146868u, 2803011307u, 3159870474u, 281858847u, 4223841913u, 2643455041u, 4142000035u, 
        1486593357u, 646256078u, 3699854445u, 4223899380u, 831679306u, 3692083121u, 1036224456u, 511328408u, 2350564645u, 
        3723433851u, 4226933936u, 671338348u, 957420513u, 2784497840u, 256379217u, 3080784902u, 1177865835u, 2356882318u, 
        4084278128u, 1974477560u, 2896175922u, 1931813673u, 3739718637u, 2056839627u, 2392786909u, 4204389526u, 1757722087u, 
        4081013625u, 1651430962u, 2531958370u, 4342233u, 867662157u, 3228890384u, 2579816689u, 1308105413u, 3324407931u, 
        4196893932u, 1509522755u, 2298577975u, 148579685u, 2147891972u, 3002252272u, 1393793972u, 394739464u, 284767384u, 
        918888455u, 1197340980u, 3521869500u, 2352530368u, 4006377960u, 4200058279u, 1498351809u, 2883270411u, 535831410u, 
        1102676799u, 339571098u, 1631329100u, 1314503625u, 847235437u, 2826792454u, 3824369043u, 1097997899u, 585075425u, 
        4195941895u, 2782570801u, 4225984667u, 2773742989u, 794320094u, 1560981175u, 3281320089u, 2425714337u, 2881881355u, 
        31250422u, 498100838u, 4187863951u, 321501009u, 3303600895u, 3449723748u, 866430984u, 1317891759u, 470289443u, 
        3674777651u, 3592651516u, 2134403175u, 3193270771u, 2312695477u, 3050610333u, 196485626u, 2670243648u, 1563757065u, 
        3853431131u, 2580371241u, 4078539548u, 495573395u, 3152849384u, 193464053u, 822225622u, 3430840561u, 3439768116u, 
        2301652126u, 234602753u, 2986034182u, 4038474097u, 1984759462u, 2069881964u, 1344985842u, 938732560u, 2024313038u, 
        2982502698u, 1853101846u, 4193826753u, 1951074071u, 604390795u, 276961300u, 3409823605u, 2390731202u, 2302532896u, 
        2067610316u, 2172356959u, 734851664u, 3586241978u, 902699871u, 816557038u, 4076576897u, 1026333546u, 27170351u, 
        772217299u, 3323375703u, 911645825u, 3864447452u };
    unsigned int temp_122;
    unsigned int temp_123;
    unsigned int temp_124;
    int temp_125;
    int *temp_126;
    int temp_127;
    int *temp_128;
    int temp_129;
    int *temp_130;
    unsigned int temp_131;
    unsigned int *temp_132;
    unsigned int temp_133;
    unsigned int *temp_134;
    bool temp_135;
    bool *temp_136;
    bool temp_137;
    bool *temp_138;
    
    L97:
    L96:
    temp_37 = (unsigned int)1154u;
    temp_77 = ( unsigned int * )(temp_57);
    temp_37 = *temp_77;
    temp_78 = ( unsigned char * )(temp_58);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_38 = temp_79 > temp_80;
    temp_78 = ( unsigned char * )(temp_59);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_39 = temp_79 > temp_80;
    temp_78 = ( unsigned char * )(temp_60);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_40 = temp_79 > temp_80;
    temp_78 = ( unsigned char * )(temp_61);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_41 = temp_79 > temp_80;
    temp_78 = ( unsigned char * )(temp_62);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_42 = temp_79 > temp_80;
    temp_78 = ( unsigned char * )(temp_63);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_43 = temp_79 > temp_80;
    temp_78 = ( unsigned char * )(temp_64);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_44 = temp_79 > temp_80;
    temp_78 = ( unsigned char * )(temp_65);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_45 = temp_79 > temp_80;
    temp_81 = ( char const ** )(temp_66);
    temp_46 = *temp_81;
    temp_77 = ( unsigned int * )(temp_67);
    temp_47 = *temp_77;
    temp_77 = ( unsigned int * )(temp_68);
    temp_48 = *temp_77;
    temp_78 = ( unsigned char * )(temp_69);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_49 = temp_79 > temp_80;
    temp_78 = ( unsigned char * )(temp_70);
    temp_79 = *temp_78;
    temp_80 = (unsigned char)0u;
    temp_50 = temp_79 > temp_80;
    temp_82 = ( int * )(temp_71);
    temp_51 = *temp_82;
    temp_77 = ( unsigned int * )(temp_72);
    temp_52 = *temp_77;
    temp_82 = ( int * )(temp_73);
    temp_53 = *temp_82;
    temp_82 = ( int * )(temp_74);
    temp_54 = *temp_82;
    temp_77 = ( unsigned int * )(temp_75);
    temp_55 = *temp_77;
    temp_77 = ( unsigned int * )(temp_76);
    temp_56 = *temp_77;
    temp_87 = (unsigned int)0u;
    temp_88 = (unsigned int)0u;
    temp_89 = (unsigned int)0u;
    temp_90 = (bool)0u;
    temp_91 = (bool)0u;
    temp_113 = ( void ** )(temp_112);
    temp_114 = (size_t)1u;
    temp_115 = &temp_37;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_38;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_39;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_40;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_41;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_42;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_43;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_44;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_45;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_46;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_47;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_48;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_49;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_50;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_51;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_52;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_53;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_54;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_55;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_56;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_83;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_84;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_85;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_86;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_87;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_88;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_89;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_90;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_91;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_77;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_78;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_79;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_80;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_81;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_82;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_57;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_58;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_59;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_60;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_61;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_62;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_63;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_64;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_65;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_66;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_67;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_68;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_69;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_70;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_71;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_72;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_73;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_74;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_75;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_115 = &temp_76;
    *temp_113 = temp_115;
    temp_113 = temp_113 + temp_114;
    temp_116 = (unsigned int)1u;
    goto L95;
    
    L98:
    temp_77 = ( unsigned int * )(temp_57);
    *temp_77 = temp_37;
    temp_78 = ( unsigned char * )(temp_58);
    *temp_78 = temp_38;
    temp_78 = ( unsigned char * )(temp_59);
    *temp_78 = temp_39;
    temp_78 = ( unsigned char * )(temp_60);
    *temp_78 = temp_40;
    temp_78 = ( unsigned char * )(temp_61);
    *temp_78 = temp_41;
    temp_78 = ( unsigned char * )(temp_62);
    *temp_78 = temp_42;
    temp_78 = ( unsigned char * )(temp_63);
    *temp_78 = temp_43;
    temp_78 = ( unsigned char * )(temp_64);
    *temp_78 = temp_44;
    temp_78 = ( unsigned char * )(temp_65);
    *temp_78 = temp_45;
    temp_77 = ( unsigned int * )(temp_67);
    *temp_77 = temp_47;
    temp_77 = ( unsigned int * )(temp_68);
    *temp_77 = temp_48;
    temp_78 = ( unsigned char * )(temp_69);
    *temp_78 = temp_49;
    temp_78 = ( unsigned char * )(temp_70);
    *temp_78 = temp_50;
    temp_82 = ( int * )(temp_71);
    *temp_82 = temp_51;
    temp_77 = ( unsigned int * )(temp_72);
    *temp_77 = temp_52;
    temp_82 = ( int * )(temp_73);
    *temp_82 = temp_53;
    temp_82 = ( int * )(temp_74);
    *temp_82 = temp_54;
    temp_77 = ( unsigned int * )(temp_75);
    *temp_77 = temp_55;
    temp_77 = ( unsigned int * )(temp_76);
    *temp_77 = temp_56;
    return;
    
    L95:
    #ifdef __cplusplus
    try
    #endif
    {
        
        L94:
        switch( temp_37)
        {
        case 3097u: goto L0;
        case 972u: goto L0;
        case 3260u: goto L0;
        case 3191u: goto L98;
        case 2277u: goto L98;
        case 1555u: goto L98;
        case 440u: goto L160;
        case 2867u: goto L160;
        case 957u: goto L158;
        case 2850u: goto L158;
        case 2653u: goto L156;
        case 1207u: goto L156;
        case 2523u: goto L154;
        case 2717u: goto L154;
        case 3847u: goto L152;
        case 3927u: goto L152;
        case 2750u: goto L150;
        case 3470u: goto L150;
        case 2114u: goto L148;
        case 3711u: goto L148;
        case 0u: goto L146;
        case 1494u: goto L146;
        case 1333u: goto L146;
        case 2728u: goto L144;
        case 415u: goto L144;
        case 1532u: goto L142;
        case 1561u: goto L142;
        case 3241u: goto L140;
        case 3788u: goto L140;
        case 3555u: goto L138;
        case 689u: goto L138;
        case 2837u: goto L138;
        case 3564u: goto L136;
        case 3034u: goto L136;
        case 5096u: goto L136;
        case 1535u: goto L134;
        case 2897u: goto L134;
        case 1921u: goto L134;
        case 1711u: goto L134;
        case 3421u: goto L132;
        case 3712u: goto L132;
        case 1657u: goto L130;
        case 3274u: goto L130;
        case 2377u: goto L128;
        case 2973u: goto L128;
        case 2976u: goto L128;
        case 3762u: goto L126;
        case 3602u: goto L126;
        case 543u: goto L124;
        case 335u: goto L124;
        case 2384u: goto L124;
        case 1754u: goto L122;
        case 2238u: goto L122;
        case 1783u: goto L120;
        case 170u: goto L120;
        case 3570u: goto L114;
        case 2085u: goto L114;
        case 5554u: goto L114;
        case 4972u: goto L114;
        case 1291u: goto L108;
        case 1861u: goto L108;
        case 701u: goto L74;
        case 2649u: goto L70;
        case 3748u: goto L68;
        case 887u: goto L68;
        case 2537u: goto L66;
        case 783u: goto L66;
        case 2033u: goto L64;
        case 1000u: goto L64;
        case 235u: goto L64;
        case 3686u: goto L62;
        case 2115u: goto L62;
        case 925u: goto L62;
        case 1529u: goto L60;
        case 3174u: goto L60;
        case 2664u: goto L60;
        case 1723u: goto L60;
        case 509u: goto L60;
        case 2873u: goto L58;
        case 3932u: goto L58;
        case 2291u: goto L58;
        case 1199u: goto L58;
        case 1716u: goto L58;
        case 3620u: goto L54;
        case 1312u: goto L54;
        case 1287u: goto L52;
        case 531u: goto L52;
        case 3579u: goto L52;
        case 1169u: goto L50;
        case 577u: goto L50;
        case 2808u: goto L48;
        case 1540u: goto L46;
        case 3124u: goto L46;
        case 935u: goto L42;
        case 756u: goto L42;
        case 3001u: goto L40;
        case 3378u: goto L40;
        case 33u: goto L38;
        case 1911u: goto L34;
        case 710u: goto L34;
        case 2554u: goto L30;
        case 145u: goto L30;
        case 2011u: goto L30;
        case 3543u: goto L30;
        case 3422u: goto L20;
        case 1205u: goto L20;
        case 4515u: goto L20;
        case 5006u: goto L20;
        case 3961u: goto L18;
        case 3362u: goto L18;
        case 2304u: goto L18;
        case 4418u: goto L18;
        case 5054u: goto L18;
        case 1481u: goto L16;
        case 952u: goto L16;
        case 1223u: goto L14;
        case 1353u: goto L14;
        case 1218u: goto L12;
        case 3843u: goto L12;
        case 3189u: goto L10;
        case 2103u: goto L10;
        case 2992u: goto L8;
        case 681u: goto L8;
        case 2214u: goto L8;
        case 4524u: goto L8;
        case 4427u: goto L8;
        case 3306u: goto L8;
        case 130u: goto L6;
        case 3468u: goto L6;
        case 2095u: goto L6;
        case 2496u: goto L4;
        case 3234u: goto L4;
        case 1322u: goto L4;
        case 3798u: goto L2;
        case 3448u: goto L2;
        case 4289u: goto L2;
        case 3571u: goto L2;
        case 3162u: goto L2;
        case 2464u: goto L98;
        case 633u: goto L98;
        case 1154u: goto L96;
        case 2916u: goto L96;
        default: goto L44;
        }
        
        L0:
        temp_123 = (unsigned int)57;
        temp_38 = (bool)0;
        temp_39 = ( bool )( temp_38 == 0 );
        temp_40 = (bool)temp_39;
        temp_122 = (unsigned int)122;
        temp_124 = (unsigned int)27;
        temp_86 = (unsigned int)1810;
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L2:
        temp_117 = (unsigned int)5u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)5u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)1u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)6u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)1048u;
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L4:
        temp_84 = ( unsigned int )(temp_44);
        temp_85 = (unsigned int)4743u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)4294967278u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)320789479u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)320789461u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967278u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)670u;
        temp_37 = temp_37 + temp_86;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)49u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)632u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L6:
        temp_52 = ( unsigned int )(temp_51);
        temp_84 = ( unsigned int )(temp_44);
        temp_85 = (unsigned int)1u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)20u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)415941454u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)415941449u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)3u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)104u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_41);
        temp_85 = (unsigned int)199u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)3594u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L8:
        // The next string is really just an assignment on 32bit platform
        temp_56 = ( unsigned int )( ( size_t )( temp_56 ) + ( ( ( size_t )( temp_56 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_56 ) << 31 ) << 1 ) >> 15 ) );
        temp_52 = temp_55 ^ temp_56;
        temp_117 = (unsigned int)4294967229u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)4294967254u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)7831u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)7799u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)1774u;
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L10:
        temp_41 = (bool)temp_42;
        temp_55 = (unsigned int)temp_42;
        temp_56 = (unsigned int)2435679782u;
        // The next string is really just an assignment on 32bit platform
        temp_56 = ( unsigned int )( ( size_t )( temp_56 ) + ( ( ( size_t )( temp_56 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_56 ) << 31 ) << 1 ) >> 15 ) );
        temp_117 = (unsigned int)4294967174u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)90u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)32u;
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)10u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)7u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)1u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)34u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)17u;
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)8u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)120u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_118 = (unsigned int)temp_42;
        temp_117 = temp_117 & temp_122;
        temp_120 = temp_117 != temp_118;
        temp_86 = (unsigned int)3169u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_120);
        temp_85 = (unsigned int)2620u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)2633u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L12:
        temp_52 = temp_55 ^ temp_56;
        temp_49 = ( bool )( temp_43 == 0 );
        temp_84 = ( unsigned int )(temp_42);
        temp_85 = (unsigned int)5u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)91u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)1u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)13u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)38u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_117 = (unsigned int)1u;
        temp_118 = (unsigned int)0u;
        temp_117 = temp_117 & temp_123;
        temp_120 = temp_117 != temp_118;
        temp_86 = (unsigned int)1111u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_120);
        temp_85 = (unsigned int)126u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)2416u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L14:
        temp_49 = ( bool )(temp_51);
        temp_54 = (int)2062554531u;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)7u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)72u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)4294967294u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_42);
        temp_85 = (unsigned int)4u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)4294967276u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)538u;
        temp_37 = temp_37 + temp_86;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)151u;
        temp_85 = temp_84 * temp_85;
        temp_85 = (unsigned int)1080u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L16:
        temp_53 = temp_51 - temp_54;
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)6u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)4294967195u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)49u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967278u;
        temp_124 = temp_124 + temp_117;
        temp_117 = (unsigned int)16u;
        temp_118 = (unsigned int)0u;
        temp_117 = temp_117 & temp_122;
        temp_120 = temp_117 != temp_118;
        temp_86 = (unsigned int)70u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_120);
        temp_85 = (unsigned int)2u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1778u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L18:
        temp_38 = (bool)temp_40;
        temp_117 = (unsigned int)57u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)34u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)44u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)2304u;
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L20:
        temp_38 = ( bool )( temp_44 == 0 );
        temp_117 = (unsigned int)10u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)10u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)2u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)12u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_42);
        temp_85 = (unsigned int)28u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1765u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L30:
        // The next string is really just an assignment on 32bit platform
        temp_56 = ( unsigned int )( ( size_t )( temp_56 ) + ( ( ( size_t )( temp_56 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_56 ) << 31 ) << 1 ) >> 15 ) );
        temp_117 = (unsigned int)4294967286u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)4294967286u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_43);
        temp_85 = (unsigned int)107878007u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)107877997u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_42);
        temp_85 = (unsigned int)165u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)2011u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L34:
        temp_52 = temp_55 ^ temp_56;
        temp_49 = (bool)temp_42;
        temp_117 = (unsigned int)33u;
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)1u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)62u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)43u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)1911u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_41);
        temp_85 = (unsigned int)668u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)701u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L38:
        temp_52 = ( unsigned int )(temp_49);
        temp_53 = temp_51 - temp_54;
        temp_117 = (unsigned int)4294967270u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)67u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967168u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)1450u;
        temp_37 = temp_37 + temp_86;
        temp_84 = ( unsigned int )(temp_41);
        temp_85 = (unsigned int)1866u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1938u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L40:
        temp_50 = (bool)temp_44;
        temp_45 = ( bool )( temp_43 == 0 );
        temp_53 = ( int )(temp_51);
        temp_117 = (unsigned int)11u;
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_42);
        temp_85 = (unsigned int)2u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)16u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)8u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)40u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_49 = ( bool )(temp_51);
        temp_41 = ( bool )( temp_45 == 0 );
        temp_84 = ( unsigned int )(temp_43);
        temp_85 = (unsigned int)159510813u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)2222065344u;
        temp_84 = temp_85 - temp_84;
        temp_54 = ( int )( ( ptrdiff_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        // The next string is really just an assignment on 32bit platform
        temp_54 = ( int )( ( size_t )( temp_54 ) + ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) >> 15 ) );
        temp_117 = (unsigned int)4294967175u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)26u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)35u;
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_44);
        temp_85 = (unsigned int)166u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)3001u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L42:
        temp_52 = temp_55 ^ temp_56;
        temp_53 = ( int )(temp_52);
        temp_117 = (unsigned int)107u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)18u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967277u;
        temp_124 = temp_124 + temp_117;
        temp_52 = ( unsigned int )(temp_54);
        temp_41 = ( bool )( temp_43 == 0 );
        temp_55 = ( unsigned int )( temp_43 == 0 );
        temp_56 = (unsigned int)2435679782u;
        temp_117 = (unsigned int)4294967228u;
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_43);
        temp_85 = (unsigned int)2u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)35u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967236u;
        temp_124 = temp_124 + temp_117;
        temp_117 = (unsigned int)1u;
        temp_118 = (unsigned int)0u;
        temp_117 = temp_117 & temp_124;
        temp_120 = temp_117 != temp_118;
        temp_86 = (unsigned int)443u;
        temp_37 = temp_37 + temp_86;
        temp_84 = ( unsigned int )(temp_120);
        temp_85 = (unsigned int)2146u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)162u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L44:
        // The next string is really just an assignment on 32bit platform
        temp_54 = ( int )( ( size_t )( temp_54 ) + ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) >> 15 ) );
        temp_41 = ( bool )( temp_44 == 0 );
        temp_84 = ( unsigned int )(temp_43);
        temp_85 = (unsigned int)4u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)34u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)2u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_43);
        temp_85 = (unsigned int)22u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)4u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)8u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)113u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L46:
        temp_45 = ( bool )( temp_38 == 0 );
        temp_50 = (bool)0u;
        temp_117 = (unsigned int)4294967193u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)43u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)1u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)26u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)997u;
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L48:
        temp_56 = (unsigned int)3756156282u;
        temp_117 = (unsigned int)4294967268u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)4294967268u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967268u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)1585u;
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L50:
        temp_52 = ( unsigned int )(temp_51);
        temp_47 = ( unsigned int )(temp_39);
        temp_48 = (unsigned int)13322615u;
        temp_47 = temp_47 * temp_48;
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)237515522u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)3769478897u;
        temp_84 = temp_85 - temp_84;
        temp_48 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_47 = temp_48 - temp_47;
        temp_56 = ( unsigned int )( ( size_t )( ( temp_47 ) & 0xFFFFFFFF ) );
        temp_84 = ( unsigned int )(temp_42);
        temp_85 = (unsigned int)1u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)10u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)10u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)10u;
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)55u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1440u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L52:
        temp_41 = (bool)temp_40;
        temp_42 = ( bool )( temp_41 == 0 );
        temp_43 = ( bool )( temp_42 == 0 );
        temp_44 = ( bool )( temp_43 == 0 );
        temp_117 = (unsigned int)19u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)4294967289u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)106u;
        temp_124 = temp_124 + temp_117;
        temp_117 = (unsigned int)1u;
        temp_118 = (unsigned int)0u;
        temp_117 = temp_117 & temp_124;
        temp_120 = temp_117 != temp_118;
        temp_86 = (unsigned int)108u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_120);
        temp_85 = (unsigned int)997u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)361u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L54:
        temp_117 = (unsigned int)100u;
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)42062722u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)42062714u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_43);
        temp_85 = (unsigned int)219785297u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)219785235u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)2880u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_44);
        temp_85 = (unsigned int)1002u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)795u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L58:
        temp_54 = (int)2062554531u;
        temp_84 = ( unsigned int )(temp_42);
        temp_85 = (unsigned int)7u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)4294967273u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)30u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)46u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)805u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L60:
        temp_40 = (bool)temp_42;
        temp_117 = (unsigned int)7u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)4294967295u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_41);
        temp_85 = (unsigned int)2u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)115u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_41);
        temp_85 = (unsigned int)223u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1996u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L62:
        // The next string is really just an assignment on 32bit platform
        temp_56 = ( unsigned int )( ( size_t )( temp_56 ) + ( ( ( size_t )( temp_56 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_56 ) << 31 ) << 1 ) >> 15 ) );
        temp_117 = (unsigned int)4294967252u;
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)1505u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1445u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)53u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)127u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_117 = (unsigned int)2u;
        temp_117 = (unsigned int)2u;
        temp_118 = ( unsigned int )( temp_38 == 0 );
        temp_117 = temp_117 & temp_122;
        temp_120 = temp_117 != temp_118;
        temp_86 = (unsigned int)3393u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_120);
        temp_85 = (unsigned int)330u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)994u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L64:
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)5436u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)4294967284u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)255968396u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)4294967211u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)2u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)0u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)1179u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_43);
        temp_85 = (unsigned int)624u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)433u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L66:
        temp_45 = ( bool )( temp_44 == 0 );
        temp_117 = (unsigned int)4294967166u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)3u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967269u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)783;
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L68:
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)1793779649u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)4294967275u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_43);
        temp_85 = (unsigned int)2u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)23u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)78813763u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)78813728u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)3643u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)1351u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1376u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L70:
        temp_52 = ( unsigned int )(temp_51);
        temp_117 = (unsigned int)4294967278u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)4294967248u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967268u;
        temp_124 = temp_124 + temp_117;
        temp_117 = (unsigned int)1u;
        temp_118 = (unsigned int)temp_42;
        temp_117 = temp_117 & temp_122;
        temp_120 = temp_117 != temp_118;
        temp_86 = (unsigned int)1218u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_120);
        temp_85 = (unsigned int)2227u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)2331u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L74:
        temp_117 = (unsigned int)89u;
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)1550u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1530u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967168u;
        temp_124 = temp_124 + temp_117;
        temp_117 = ( unsigned int )( temp_42 == 0 );
        temp_118 = (unsigned int)0u;
        temp_117 = temp_117 & temp_124;
        temp_120 = temp_117 != temp_118;
        temp_86 = (unsigned int)655u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_120);
        temp_85 = (unsigned int)2749u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)3143u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L108:
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)124041415u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)2186595946u;
        temp_84 = temp_85 - temp_84;
        temp_54 = ( int )( ( ptrdiff_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_117 = (unsigned int)18u;
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)1u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)17u;
        temp_84 = temp_85 + temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)18u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)1291u;
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L114:
        temp_40 = ( bool )( temp_41 == 0 );
        temp_117 = (unsigned int)75u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)4u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967246u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)3440u;
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L120:
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_126 = ( int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_128 = ( int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_130 = ( int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_132 = ( unsigned int * )(temp_119);
        temp_129 = *temp_130;
        temp_125 = *temp_126;
        // The next string is really just an assignment on 32bit platform
        temp_125 = ( int )( ( size_t )( temp_125 ) + ( ( ( size_t )( temp_125 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_125 ) << 31 ) << 1 ) >> 15 ) );
        temp_127 = temp_129 + temp_125;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_131 = ( unsigned int )( ( size_t )( ( temp_117 ) & 0xFFFFFFFF ) );
        *temp_126 = temp_125;
        *temp_128 = temp_127;
        *temp_132 = temp_131;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_37 = (unsigned int)temp_117;
        goto L94;
        
        L122:
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_132 = ( unsigned int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_126 = ( int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_134 = ( unsigned int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_136 = ( bool * )(temp_119);
        temp_135 = *temp_136;
        temp_125 = *temp_126;
        temp_131 = ( unsigned int )(temp_125);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_133 = ( unsigned int )( ( size_t )( ( temp_117 ) & 0xFFFFFFFF ) );
        *temp_132 = temp_131;
        *temp_134 = temp_133;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_37 = (unsigned int)temp_117;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = ( unsigned int )(temp_135);
        temp_117 = temp_117 * temp_118;
        temp_37 = temp_37 + temp_117;
        goto L94;
        
        L124:
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_136 = ( bool * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_126 = ( int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_138 = ( bool * )(temp_119);
        temp_137 = *temp_138;
        temp_125 = *temp_126;
        temp_135 = ( bool )(temp_125);
        *temp_136 = temp_135;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_37 = (unsigned int)temp_117;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = ( unsigned int )(temp_137);
        temp_117 = temp_117 * temp_118;
        temp_37 = temp_37 + temp_117;
        goto L94;
        
        L126:
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_126 = ( int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_128 = ( int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_136 = ( bool * )(temp_119);
        temp_135 = *temp_136;
        temp_127 = *temp_128;
        temp_125 = ( int )(temp_127);
        *temp_126 = temp_125;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_37 = (unsigned int)temp_117;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = ( unsigned int )(temp_135);
        temp_117 = temp_117 * temp_118;
        temp_37 = temp_37 + temp_117;
        goto L94;
        
        L128:
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_126 = ( int * )(temp_119);
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_119 = temp_112[ temp_117 ];
        temp_128 = ( int * )(temp_119);
        temp_125 = ( int )printf( ( char const * )temp_46 );
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_127 = ( int )( ( ptrdiff_t )( ( temp_117 ) & 0xFFFFFFFF ) );
        *temp_126 = temp_125;
        *temp_128 = temp_127;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_37 = (unsigned int)temp_117;
        goto L94;
        
        L130:
        temp_81 = ( char const ** )(temp_66);
        temp_46 = *temp_81;
        temp_117 = omni_virtualcode_121[ temp_122 ];
        temp_122 = temp_122 + temp_116;
        temp_118 = omni_virtualcode_121[ temp_123 ];
        temp_123 = temp_123 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_118 = omni_virtualcode_121[ temp_124 ];
        temp_124 = temp_124 + temp_116;
        temp_117 = temp_117 ^ temp_118;
        temp_37 = (unsigned int)temp_117;
        goto L94;
        
        L132:
        temp_117 = (unsigned int)4294967168u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)4294967264u;
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)14u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)2451u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)1196u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)562u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L134:
        temp_117 = (unsigned int)4294967186u;
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)417293888u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)417293886u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)52u;
        temp_124 = temp_124 + temp_117;
        temp_86 = (unsigned int)662u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)1709u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)659u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L136:
        temp_52 = ( unsigned int )(temp_51);
        temp_117 = (unsigned int)14u;
        temp_122 = temp_122 + temp_117;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)361829870u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)361829746u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_123 = temp_123 + temp_117;
        temp_117 = (unsigned int)4294967222u;
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)1044u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)3390u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L138:
        temp_117 = (unsigned int)33u;
        temp_122 = temp_122 + temp_117;
        temp_117 = (unsigned int)33u;
        temp_123 = temp_123 + temp_117;
        temp_84 = ( unsigned int )(temp_44);
        temp_85 = (unsigned int)2u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)33u;
        temp_84 = temp_85 - temp_84;
        temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_124 = temp_124 + temp_117;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)109u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)423u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 - temp_86;
        goto L94;
        
        L140:
        temp_86 = (unsigned int)2038u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)895u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1446u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L142:
        temp_86 = (unsigned int)253u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)1668u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)475u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L144:
        temp_86 = (unsigned int)2474u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)193u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)3494u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L146:
        temp_86 = (unsigned int)1088u;
        temp_37 = temp_37 + temp_86;
        temp_84 = ( unsigned int )(temp_45);
        temp_85 = (unsigned int)463u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)945u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L148:
        temp_86 = (unsigned int)743u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)895u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1278u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L150:
        temp_86 = (unsigned int)2291u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_38);
        temp_85 = (unsigned int)1240u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)84u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L152:
        temp_86 = (unsigned int)1871u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)198u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1588u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L154:
        temp_86 = (unsigned int)1892u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_41);
        temp_85 = (unsigned int)1649u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)909u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L156:
        temp_86 = (unsigned int)2140u;
        temp_37 = temp_37 - temp_86;
        temp_84 = ( unsigned int )(temp_39);
        temp_85 = (unsigned int)1351u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)1983u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L158:
        temp_86 = (unsigned int)871u;
        temp_37 = temp_37 + temp_86;
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)1684u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)286u;
        temp_84 = temp_85 + temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
        L160:
        temp_86 = (unsigned int)1608u;
        temp_37 = temp_37 + temp_86;
        temp_84 = ( unsigned int )(temp_40);
        temp_85 = (unsigned int)251u;
        temp_84 = temp_84 * temp_85;
        temp_85 = (unsigned int)953u;
        temp_84 = temp_85 - temp_84;
        temp_86 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF ) );
        temp_37 = temp_37 + temp_86;
        goto L94;
        
    }

    #ifdef __cplusplus
    catch( ... )
    {
        
        L101:
        L100:
        temp_77 = ( unsigned int * )(temp_57);
        *temp_77 = temp_37;
        temp_78 = ( unsigned char * )(temp_58);
        *temp_78 = temp_38;
        temp_78 = ( unsigned char * )(temp_59);
        *temp_78 = temp_39;
        temp_78 = ( unsigned char * )(temp_60);
        *temp_78 = temp_40;
        temp_78 = ( unsigned char * )(temp_61);
        *temp_78 = temp_41;
        temp_78 = ( unsigned char * )(temp_62);
        *temp_78 = temp_42;
        temp_78 = ( unsigned char * )(temp_63);
        *temp_78 = temp_43;
        temp_78 = ( unsigned char * )(temp_64);
        *temp_78 = temp_44;
        temp_78 = ( unsigned char * )(temp_65);
        *temp_78 = temp_45;
        temp_77 = ( unsigned int * )(temp_67);
        *temp_77 = temp_47;
        temp_77 = ( unsigned int * )(temp_68);
        *temp_77 = temp_48;
        temp_78 = ( unsigned char * )(temp_69);
        *temp_78 = temp_49;
        temp_78 = ( unsigned char * )(temp_70);
        *temp_78 = temp_50;
        temp_82 = ( int * )(temp_71);
        *temp_82 = temp_51;
        temp_77 = ( unsigned int * )(temp_72);
        *temp_77 = temp_52;
        temp_82 = ( int * )(temp_73);
        *temp_82 = temp_53;
        temp_82 = ( int * )(temp_74);
        *temp_82 = temp_54;
        temp_77 = ( unsigned int * )(temp_75);
        *temp_77 = temp_55;
        temp_77 = ( unsigned int * )(temp_76);
        *temp_77 = temp_56;
        throw ;
        
    }

    #endif
}

