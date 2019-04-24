#pragma clang diagnostic ignored "-Weverything"
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
    temp_8 = (unsigned int)78u;
    temp_36 = ( (unsigned int)3175u) - ( (unsigned int)78u);
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
    

    temp_37 =  *( ( unsigned int * )(temp_57));
    temp_80 = (unsigned char)0u;
    temp_38 = ( *( ( unsigned char * )(temp_58))) > ( (unsigned char)0u);
    temp_39 = ( *( ( unsigned char * )(temp_59))) > ( (unsigned char)0u);
    temp_40 = ( *( ( unsigned char * )(temp_60))) > ( (unsigned char)0u);
    temp_41 = ( *( ( unsigned char * )(temp_61))) > ( (unsigned char)0u);
    temp_42 = ( *( ( unsigned char * )(temp_62))) > ( (unsigned char)0u);
    temp_43 = ( *( ( unsigned char * )(temp_63))) > ( (unsigned char)0u);
    temp_44 = ( *( ( unsigned char * )(temp_64))) > ( (unsigned char)0u);
    temp_45 = ( *( ( unsigned char * )(temp_65))) > ( (unsigned char)0u);
    temp_81 = ( char const ** )(temp_66);
    temp_46 = *( ( char const ** )(temp_66));
    temp_47 =  *( ( unsigned int * )(temp_67));
    temp_48 =  *( ( unsigned int * )(temp_68));
    temp_49 = ( *( ( unsigned char * )(temp_69))) > ( (unsigned char)0u);
    temp_78 = ( unsigned char * )(temp_70);
    temp_79 = *( ( unsigned char * )(temp_70));
    temp_50 = ( *( ( unsigned char * )(temp_70))) > ( (unsigned char)0u);
    temp_51 =  *( ( int * )(temp_71));
    temp_52 =  *( ( unsigned int * )(temp_72));
    temp_53 =  *( ( int * )(temp_73));
    temp_82 =  ( int * )(temp_74);
    temp_54 =  *( ( int * )(temp_74));
    temp_55 =  *( ( unsigned int * )(temp_75));
    temp_77 =  ( unsigned int * )(temp_76);
    temp_56 =  *( ( unsigned int * )(temp_76));
    temp_87 = (unsigned int) 0;
    temp_88 = (unsigned int) 0;
    temp_89 = (unsigned int) 0;
    temp_90 = (unsigned int) 0;
    temp_91 = (unsigned int) 0;
    temp_113 = ( void ** )(temp_112);
    temp_114 = (unsigned int) 1;
    *temp_113 = ( &temp_37);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  1;
    *temp_113 = ( &temp_38);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  2;
    *temp_113 = ( &temp_39);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  3;
    *temp_113 = ( &temp_40);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  4;
    *temp_113 = ( &temp_41);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  5;
    *temp_113 = ( &temp_42);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  6;
    *temp_113 = ( &temp_43);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  7;
    *temp_113 = ( &temp_44);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  8;
    *temp_113 = ( &temp_45);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  9;
    *temp_113 = ( &temp_46);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  10;
    *temp_113 = ( &temp_47);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  11;
    *temp_113 = ( &temp_48);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  12;
    *temp_113 = ( &temp_49);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  13;
    *temp_113 = ( &temp_50);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  14;
    *temp_113 = ( &temp_51);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  15;
    *temp_113 = ( &temp_52);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  16;
    *temp_113 = ( &temp_53);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  17;
    *temp_113 = ( &temp_54);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  18;
    *temp_113 = ( &temp_55);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  19;
    *temp_113 = ( &temp_56);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  20;
    *temp_113 = ( &temp_83);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  21;
    *temp_113 = ( &temp_84);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  22;
    *temp_113 = ( &temp_85);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  23;
    *temp_113 = ( &temp_86);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  24;
    *temp_113 = ( &temp_87);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  25;
    *temp_113 = ( &temp_88);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  26;
    *temp_113 = ( &temp_89);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  27;
    *temp_113 = ( &temp_90);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  28;
    *temp_113 = ( &temp_91);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  29;
    *temp_113 = ( &temp_77);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  30;
    *temp_113 = ( &temp_78);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  31;
    *temp_113 = ( &temp_79);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  32;
    *temp_113 = ( &temp_80);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  33;
    *temp_113 = ( &temp_81);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  34;
    *temp_113 = ( &temp_82);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  35;
    *temp_113 = ( &temp_57);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  36;
    *temp_113 = ( &temp_58);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  37;
    *temp_113 = ( &temp_59);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  38;
    *temp_113 = ( &temp_60);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  39;
    *temp_113 = ( &temp_61);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  40;
    *temp_113 = ( &temp_62);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  41;
    *temp_113 = ( &temp_63);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  42;
    *temp_113 = ( &temp_64);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  43;
    *temp_113 = ( &temp_65);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  44;
    *temp_113 = ( &temp_66);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  45;
    *temp_113 = ( &temp_67);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  46;
    *temp_113 = ( &temp_68);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  47;
    *temp_113 = ( &temp_69);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  48;
    *temp_113 = ( &temp_70);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  49;
    *temp_113 = ( &temp_71);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  50;
    *temp_113 = ( &temp_72);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  51;
    *temp_113 = ( &temp_73);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  52;
    *temp_113 = ( &temp_74);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  53;
    *temp_113 = ( &temp_75);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  54;
    temp_115 =  &temp_76;
    *temp_113 = ( &temp_76);
    temp_113 = ( void ** )(temp_112) +(unsigned int)  55;
    temp_116 = (unsigned int) 1;
    #ifdef __cplusplus
    try
    #endif
    {
        
	}
        temp_38 = (unsigned int) 0;
        temp_39 = true;
        temp_40 = true;
        temp_86 = (unsigned int) 1810;
        temp_37 =  temp_37  -(unsigned int)  1810;
        temp_41 = true;
        temp_42 = false;
        temp_43 = true;
        temp_44 = false;
        temp_86 = (unsigned int) 108;
        temp_37 =  temp_37  -(unsigned int)  108;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 997;
        temp_84 = (unsigned int) 997;
        temp_85 = (unsigned int) 361;
        temp_84 = (unsigned int) 1358;
        temp_86 = ( unsigned int )(unsigned int) 1358;
        temp_37 =  temp_37 + ( ( ( ( ( ((unsigned int)  361) + ( ( (( ( ((unsigned int)  1) & ( ((unsigned int)  27) + ((unsigned int)  106))) != ((unsigned int)  0)))) * ((unsigned int)  997))) ) & 0xFFFFFFFF ) ));
        temp_45 = true;
        temp_86 = (unsigned int) 783;
        temp_37 =  temp_37  -(unsigned int)  783;
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967307];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967349];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967402];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_132 =  ( unsigned int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967308];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967350];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967403];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_126 =  ( int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967309];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967351];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967404];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_134 =  ( unsigned int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967310];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967352];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967405];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_136 =  ( bool * )(temp_119);
        temp_135 =  *( ( bool * )(temp_119));
        temp_131 = ( unsigned int )( *temp_126);
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967311];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967353];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967406];
        temp_117 = temp_117 ^ temp_118;
        temp_133 = ( unsigned int ) ( ( ( temp_117 ) &(unsigned int)  0xFFFFFFFF ) );
        *temp_132 = ( *temp_126);
        *temp_134 =  ( ( ( ( temp_117 ) &(unsigned int)  0xFFFFFFFF ) ));
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967312];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967354];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967407];
        temp_117 = temp_117 ^ temp_118;
        temp_37 =  temp_117;
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967313];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967355];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967408];
        temp_117 = temp_117 ^ temp_118;
        temp_117 =  temp_117 * ( (( *( ( bool * )(temp_119)))));
        temp_37 =  temp_37  +  temp_117;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 1;
        temp_84 = (unsigned int) 1;
        temp_85 = (unsigned int) 6;
        temp_84 = (unsigned int) 5;
        temp_86 = (unsigned int) 1048;
        temp_37 =  temp_37  -(unsigned int)  1048;
        temp_86 = (unsigned int) 2291;
        temp_37 =  temp_37  -(unsigned int)  2291;
        temp_84 = ( unsigned int )(unsigned int) 0;
        temp_85 = (unsigned int) 1240;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 84;
        temp_84 = (unsigned int) 84;
        temp_86 = ( unsigned int )(unsigned int) 84;
        temp_37 =  temp_37 + ( ( ( ( ( ((unsigned int)  84) + ( ( (((unsigned int)  0))) * ((unsigned int)  1240))) ) & 0xFFFFFFFF ) ));
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967319];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967361];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967414];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_136 =  ( bool * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967320];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967362];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967415];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_126 =  ( int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967321];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967363];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967416];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_138 =  ( bool * )(temp_119);
        temp_137 =  *( ( bool * )(temp_119));
        temp_135 = ( *temp_126);
        *temp_136 = ( *temp_126);
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967322];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967364];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967417];
        temp_117 = temp_117 ^ temp_118;
        temp_37 =  temp_117;
        temp_117 =  omni_virtualcode_121[(unsigned int) 4294967323];
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967365];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 4294967418];
        temp_117 = temp_117 ^ temp_118;
        temp_117 =  temp_117 * ( (( *( ( bool * )(temp_119)))));
        temp_37 =  temp_37  +  temp_117;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 42062722;
        temp_84 = (unsigned int) 42062722;
        temp_85 = (unsigned int) 42062714;
        temp_84 = -(unsigned int) 8;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 219785297;
        temp_84 = (unsigned int) 219785297;
        temp_85 = (unsigned int) 219785235;
        temp_84 = -(unsigned int) 62;
        temp_86 = (unsigned int) 2880;
        temp_37 =  temp_37  -(unsigned int)  2880;
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 1002;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 795;
        temp_84 = (unsigned int) 795;
        temp_86 = ( unsigned int )(unsigned int) 795;
        temp_37 =  temp_37 + ( ( ( ( ( ((unsigned int)  795) + ( ( (( ( ( ( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1002))) ) & 0xFFFFFFFF ) ));
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 417293888;
        temp_84 = (unsigned int) 417293888;
        temp_85 = (unsigned int) 417293886;
        temp_84 = -(unsigned int) 2;
        temp_86 = (unsigned int) 662;
        temp_37 =  temp_37  -(unsigned int)  662;
        temp_84 = ( unsigned int )(unsigned int) 0;
        temp_85 = (unsigned int) 1709;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 659;
        temp_84 = (unsigned int) 659;
        temp_86 = ( unsigned int )(unsigned int) 659;
        temp_37 =  temp_37 + ( ( ( ( ( ((unsigned int)  659) + ( ( (((unsigned int)  0))) * ((unsigned int)  1709))) ) & 0xFFFFFFFF ) ));
        temp_86 = (unsigned int) 253;
        temp_37 =  temp_37  -(unsigned int)  253;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 1668;
        temp_84 = (unsigned int) 1668;
        temp_85 = (unsigned int) 475;
        temp_84 = (unsigned int) 2143;
        temp_86 = ( unsigned int )(unsigned int) 2143;
        temp_37 =  temp_37 + ( ( ( ( ( ((unsigned int)  475) + ( ( (( ( ( ((unsigned int)  0) ==(unsigned int)  0 ))))) * ((unsigned int)  1668))) ) & 0xFFFFFFFF ) ));
        temp_38 = true;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 2;
        temp_84 = (unsigned int) 2;
        temp_85 = (unsigned int) 12;
        temp_84 = (unsigned int) 10;
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 28;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 1765;
        temp_84 = (unsigned int) 1765;
        temp_86 = ( unsigned int )(unsigned int) 1765;
        temp_37 =  temp_37 - ( ( ( ( ( ((unsigned int)  1765) + ( ( (( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 )))) * ((unsigned int)  28))) ) & 0xFFFFFFFF ) ));
        temp_81 = ( char const ** )(temp_66);
        temp_46 = *( ( char const ** )(temp_66));
        temp_117 =  omni_virtualcode_121[(unsigned int) 8589934620];
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884901958];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 8589934715];
        temp_117 = temp_117 ^ temp_118;
        temp_37 =  temp_117;
        temp_117 =  omni_virtualcode_121[(unsigned int) 8589934621];
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884901959];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 8589934716];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_126 =  ( int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 8589934622];
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884901960];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 8589934717];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_128 =  ( int * )(temp_119);
        temp_125 = ( int )printf( ( char const * )( *( ( char const ** )(temp_66))) );
        temp_117 =  omni_virtualcode_121[(unsigned int) 8589934623];
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884901961];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 8589934718];
        temp_117 = temp_117 ^ temp_118;
        temp_127 =  ( int )( ( ptrdiff_t )( ( temp_117 ) &(unsigned int)  0xFFFFFFFF ) );
        *temp_126 =  temp_125;
        *temp_128 =  ( ( int )( ( ptrdiff_t )( ( temp_117 ) &(unsigned int)  0xFFFFFFFF ) ));
        temp_117 =  omni_virtualcode_121[(unsigned int) 8589934624];
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884901962];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 8589934719];
        temp_117 = temp_117 ^ temp_118;
        temp_37 =  temp_117;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 124041415;
        temp_84 = (unsigned int) 124041415;
        temp_85 = (unsigned int) 2186595946;
        temp_84 = (unsigned int) 2062554531;
        temp_54 =  ( int )( ( ptrdiff_t )( ( ( ((unsigned int)  2186595946) - ( ( (( ( ((unsigned int)  0) ==(unsigned int)  0 )))) * ((unsigned int)  124041415))) ) & 0xFFFFFFFF ) );
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 1;
        temp_84 = (unsigned int) 1;
        temp_85 = (unsigned int) 17;
        temp_84 = (unsigned int) 18;
        temp_86 = (unsigned int) 1291;
        temp_37 = ( temp_117) -(unsigned int)  1291;
        temp_86 = (unsigned int) 1088;
        temp_37 = ( temp_117) -(unsigned int)  203;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 463;
        temp_84 = (unsigned int) 463;
        temp_85 = (unsigned int) 945;
        temp_84 = (unsigned int) 1408;
        temp_86 = ( unsigned int )(unsigned int) 1408;
        temp_37 =  ( ( ( temp_117) - ((unsigned int)  1291)) + ((unsigned int)  1088)) + ( ( ( ( ( ((unsigned int)  945) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  463))) ) & 0xFFFFFFFF ) ));
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 4743;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 4294967278;
        temp_84 = (unsigned int) 4294967278;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 320789479;
        temp_84 = (unsigned int) 320789479;
        temp_85 = (unsigned int) 320789461;
        temp_84 = -(unsigned int) 18;
        temp_86 = (unsigned int) 670;
        temp_37 =  ( ( ( ( temp_117) - ((unsigned int)  1291)) + ((unsigned int)  1088)) + ( ( ( ( ( ((unsigned int)  945) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  463))) ) & 0xFFFFFFFF ) ))) + ((unsigned int)  670);
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 49;
        temp_84 = (unsigned int) 49;
        temp_85 = (unsigned int) 632;
        temp_84 = (unsigned int) 681;
        temp_86 = ( unsigned int )(unsigned int) 681;
        temp_37 =  ( ( ( ( ( temp_117) - ((unsigned int)  1291)) + ((unsigned int)  1088)) + ( ( ( ( ( ((unsigned int)  945) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  463))) ) & 0xFFFFFFFF ) ))) + ((unsigned int)  670)) + ( ( ( ( ( ((unsigned int)  632) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  49))) ) & 0xFFFFFFFF ) ));
        temp_86 = (unsigned int) 1871;
        temp_37 =  ( ( ( ( ( ( temp_117) - ((unsigned int)  1291)) + ((unsigned int)  1088)) + ( ( ( ( ( ((unsigned int)  945) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  463))) ) & 0xFFFFFFFF ) ))) + ((unsigned int)  670)) + ( ( ( ( ( ((unsigned int)  632) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  49))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  1871);
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 198;
        temp_84 = (unsigned int) 198;
        temp_85 = (unsigned int) 1588;
        temp_84 = (unsigned int) 1786;
        temp_86 = ( unsigned int )(unsigned int) 1786;
        temp_37 =  ( ( ( ( ( ( ( temp_117) - ((unsigned int)  1291)) + ((unsigned int)  1088)) + ( ( ( ( ( ((unsigned int)  945) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  463))) ) & 0xFFFFFFFF ) ))) + ((unsigned int)  670)) + ( ( ( ( ( ((unsigned int)  632) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  49))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  1871)) + ( ( ( ( ( ((unsigned int)  1588) + ( ( (( ( ( ( 0) == 0 ))))) * ((unsigned int)  198))) ) & 0xFFFFFFFF ) ));
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884901921];
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869259];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884902016];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_126 =  ( int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884901922];
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869260];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884902017];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_128 =  ( int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884901923];
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869261];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884902018];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_136 =  ( bool * )(temp_119);
        temp_135 =  *( ( bool * )(temp_119));
        *temp_126 =  ( ( int )(( *temp_128)));
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884901924];
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869262];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884902019];
        temp_117 = temp_117 ^ temp_118;
        temp_37 =  temp_117;
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884901925];
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869263];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 12884902020];
        temp_117 = temp_117 ^ temp_118;
        temp_117 =  temp_117 * ( (( *( ( bool * )(temp_119)))));
        temp_37 =  temp_37  +  temp_117;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 1550;
        temp_84 = (unsigned int) 1550;
        temp_85 = (unsigned int) 1530;
        temp_84 = -(unsigned int) 20;
        temp_124 = (unsigned int) 17179869189;
        temp_120 = true;
        temp_86 = (unsigned int) 655;
        temp_37 =  temp_37  -(unsigned int)  655;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 2749;
        temp_84 = (unsigned int) 2749;
        temp_85 = (unsigned int) 3143;
        temp_84 = (unsigned int) 394;
        temp_86 = ( unsigned int )(unsigned int) 394;
        temp_37 =  temp_37 + ( ( ( ( ( ((unsigned int)  3143) - ( ( (( ( ( ( temp_42 ==(unsigned int) (unsigned int)  0 )) & temp_124) != ( 0)))) * ((unsigned int)  2749))) ) & 0xFFFFFFFF ) ));
        temp_86 = (unsigned int) 1608;
        temp_37 =  temp_37  +(unsigned int)  1608;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 251;
        temp_84 = (unsigned int) 251;
        temp_85 = (unsigned int) 953;
        temp_84 = (unsigned int) 702;
        temp_86 = ( unsigned int )(unsigned int) 702;
        temp_37 =  temp_37 + ( ( ( ( ( ((unsigned int)  953) - ( ( (( ( ( ((unsigned int)  0) ==(unsigned int)  0 ))))) * ((unsigned int)  251))) ) & 0xFFFFFFFF ) ));
        temp_86 = (unsigned int) 2291;
        temp_37 =  temp_37  -(unsigned int)  2291;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 1240;
        temp_84 = (unsigned int) 1240;
        temp_85 = (unsigned int) 84;
        temp_84 = (unsigned int) 1324;
        temp_86 = ( unsigned int )(unsigned int) 1324;
        temp_37 =  temp_37 + ( ( ( ( ( ((unsigned int)  84) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1240))) ) & 0xFFFFFFFF ) ));
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884902015];
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836540];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869189];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_126 =  ( int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884902016];
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836541];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869190];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_128 =  ( int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884902017];
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836542];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869191];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_130 =  ( int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884902018];
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836543];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869192];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_132 =  ( unsigned int * )(temp_119);
        temp_129 =  *temp_130;
        temp_125 =  *temp_126;
        // The next string is really just an assignment on 32bit platform
        temp_125 =  ( int )( ( size_t )( temp_125 ) + ( ( ( size_t )( temp_125 ) <<(unsigned int)  31 ) <<(unsigned int)  1 ) + ( ( ( ( size_t )( temp_125 ) << 31 ) << 1 ) >>(unsigned int)  15 ) );
        temp_127 = ( *temp_130) +  temp_125;
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884902019];
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836544];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869193];
        temp_117 = temp_117 ^ temp_118;
        temp_131 = ( unsigned int ) ( ( ( temp_117 ) &(unsigned int)  0xFFFFFFFF ) );
        *temp_126 =  temp_125;
        *temp_128 =  ( ( *temp_130) + temp_125);
        *temp_132 =  ( ( ( ( temp_117 ) &(unsigned int)  0xFFFFFFFF ) ));
        temp_117 =  omni_virtualcode_121[(unsigned int) 12884902020];
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836545];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 17179869194];
        temp_117 = temp_117 ^ temp_118;
        temp_37 =  temp_117;
        temp_40 = false;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 2;
        temp_84 = (unsigned int) 2;
        temp_85 = (unsigned int) 115;
        temp_84 = (unsigned int) 113;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 223;
        temp_84 = (unsigned int) 223;
        temp_85 = (unsigned int) 1996;
        temp_84 = (unsigned int) 2219;
        temp_86 = ( unsigned int )(unsigned int) 2219;
        temp_37 =  ( temp_117) + ( ( ( ( ( ((unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ));
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 1793779649;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 4294967275;
        temp_84 = (unsigned int) 4294967275;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 2;
        temp_84 = (unsigned int) 2;
        temp_85 = (unsigned int) 23;
        temp_84 = (unsigned int) 25;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 78813763;
        temp_84 = (unsigned int) 78813763;
        temp_85 = (unsigned int) 78813728;
        temp_84 = -(unsigned int) 35;
        temp_86 = (unsigned int) 3643;
        temp_37 =  ( ( temp_117) + ( ( ( ( ( ((unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643);
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 1351;
        temp_84 = (unsigned int) 1351;
        temp_85 = (unsigned int) 1376;
        temp_84 = (unsigned int) 25;
        temp_86 = ( unsigned int )(unsigned int) 25;
        temp_37 =  ( ( ( temp_117) + ( ( ( ( ( ((unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ));
        temp_52 = ( unsigned int )(temp_51);
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 1;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 20;
        temp_84 = (unsigned int) 20;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 415941454;
        temp_84 = (unsigned int) 415941454;
        temp_85 = (unsigned int) 415941449;
        temp_84 = -(unsigned int) 5;
        temp_86 = (unsigned int) 104;
        temp_37 =  ( ( ( ( temp_117) + ( ( ( ( ( ((unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  104);
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 199;
        temp_84 = (unsigned int) 199;
        temp_85 = (unsigned int) 3594;
        temp_84 = (unsigned int) 3395;
        temp_86 = ( unsigned int )(unsigned int) 3395;
        temp_37 =  ( ( ( ( ( temp_117) + ( ( ( ( ( ((unsigned int) (unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  104)) + ( ( ( ( ( ((unsigned int)  3594) - ( ( (( ( ( ( ( 0) == 0 )))))) * ( 199))) ) & 0xFFFFFFFF ) ));
        temp_86 = (unsigned int) 2451;
        temp_37 =  ( ( ( ( ( ( temp_117) + ( ( ( ( ( ((unsigned int) (unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  104)) + ( ( ( ( ( ((unsigned int)  3594) - ( ( (( ( ( ( ( 0) == 0 )))))) * ( 199))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2451);
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 1196;
        temp_84 = (unsigned int) 1196;
        temp_85 = (unsigned int) 562;
        temp_84 = (unsigned int) 1758;
        temp_86 = ( unsigned int )(unsigned int) 1758;
        temp_37 =  ( ( ( ( ( ( ( temp_117) + ( ( ( ( ( ((unsigned int) (unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  104)) + ( ( ( ( ( ((unsigned int)  3594) - ( ( (( ( ( ( ( 0) == 0 )))))) * ( 199))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2451)) + ( ( ( ( ( ((unsigned int)  562) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1196))) ) & 0xFFFFFFFF ) ));
        temp_86 = (unsigned int) 2474;
        temp_37 =  ( ( ( ( ( ( ( ( temp_117) + ( ( ( ( ( ((unsigned int) (unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  104)) + ( ( ( ( ( ((unsigned int)  3594) - ( ( (( ( ( ( ( 0) == 0 )))))) * ( 199))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2451)) + ( ( ( ( ( ((unsigned int)  562) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1196))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2474);
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 193;
        temp_84 = (unsigned int) 193;
        temp_85 = (unsigned int) 3494;
        temp_84 = (unsigned int) 3301;
        temp_86 = ( unsigned int )(unsigned int) 3301;
        temp_37 =  ( ( ( ( ( ( ( ( ( temp_117) + ( ( ( ( ( ((unsigned int) (unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  104)) + ( ( ( ( ( ((unsigned int)  3594) - ( ( (( ( ( ( ( 0) == 0 )))))) * ( 199))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2451)) + ( ( ( ( ( ((unsigned int)  562) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1196))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2474)) + ( ( ( ( ( ((unsigned int)  3494) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  193))) ) & 0xFFFFFFFF ) ));
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 2;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 33;
        temp_84 = (unsigned int) 33;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 109;
        temp_84 = (unsigned int) 109;
        temp_85 = (unsigned int) 423;
        temp_84 = (unsigned int) 314;
        temp_86 = ( unsigned int )(unsigned int) 314;
        temp_37 =  ( ( ( ( ( ( ( ( ( ( temp_117) + ( ( ( ( ( ((unsigned int) (unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  104)) + ( ( ( ( ( ((unsigned int)  3594) - ( ( (( ( ( ( ( 0) == 0 )))))) * ( 199))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2451)) + ( ( ( ( ( ((unsigned int)  562) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1196))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2474)) + ( ( ( ( ( ((unsigned int)  3494) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  193))) ) & 0xFFFFFFFF ) ))) - ( ( ( ( ( ((unsigned int)  423) - ( ( (( ( ( 0) == 0 )))) * ((unsigned int)  109))) ) & 0xFFFFFFFF ) ));
        temp_86 = (unsigned int) 2038;
        temp_37 =  ( ( ( ( ( ( ( ( ( ( ( temp_117) + ( ( ( ( ( ((unsigned int) (unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  104)) + ( ( ( ( ( ((unsigned int)  3594) - ( ( (( ( ( ( ( 0) == 0 )))))) * ( 199))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2451)) + ( ( ( ( ( ((unsigned int)  562) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1196))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2474)) + ( ( ( ( ( ((unsigned int)  3494) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  193))) ) & 0xFFFFFFFF ) ))) - ( ( ( ( ( ((unsigned int)  423) - ( ( (( ( ( 0) == 0 )))) * ((unsigned int)  109))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2038);
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 895;
        temp_84 = (unsigned int) 895;
        temp_85 = (unsigned int) 1446;
        temp_84 = (unsigned int) 551;
        temp_86 = ( unsigned int )(unsigned int) 551;
        temp_37 =  ( ( ( ( ( ( ( ( ( ( ( ( temp_117) + ( ( ( ( ( ((unsigned int) (unsigned int)  1996) + ( ( (( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))))) * ((unsigned int)  223))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  3643)) + ( ( ( ( ( ((unsigned int)  1376) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1351))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  104)) + ( ( ( ( ( ((unsigned int)  3594) - ( ( (( ( ( ( ( 0) == 0 )))))) * ( 199))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2451)) + ( ( ( ( ( ((unsigned int)  562) + ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  1196))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2474)) + ( ( ( ( ( ((unsigned int)  3494) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  193))) ) & 0xFFFFFFFF ) ))) - ( ( ( ( ( ((unsigned int)  423) - ( ( (( ( ( 0) == 0 )))) * ((unsigned int)  109))) ) & 0xFFFFFFFF ) ))) - ((unsigned int)  2038)) + ( ( ( ( ( ((unsigned int)  1446) - ( ( (( ( ( ( ( ( ( ( ( ( ( ( ( 0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ((unsigned int)  895))) ) & 0xFFFFFFFF ) ));
        temp_117 =  omni_virtualcode_121[(unsigned int) 21474836524];
        temp_118 =  omni_virtualcode_121[(unsigned int) 34359738454];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836619];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_132 =  ( unsigned int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 21474836525];
        temp_118 =  omni_virtualcode_121[(unsigned int) 34359738455];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836620];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_126 =  ( int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 21474836526];
        temp_118 =  omni_virtualcode_121[(unsigned int) 34359738456];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836621];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_134 =  ( unsigned int * )(temp_119);
        temp_117 =  omni_virtualcode_121[(unsigned int) 21474836527];
        temp_118 =  omni_virtualcode_121[(unsigned int) 34359738457];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836622];
        temp_117 = temp_117 ^ temp_118;
        temp_119 =  temp_112[ temp_117 ];
        temp_136 =  ( bool * )(temp_119);
        temp_135 =  *( ( bool * )(temp_119));
        temp_125 =  *temp_126;
        temp_131 = ( unsigned int )( *temp_126);
        temp_117 =  omni_virtualcode_121[(unsigned int) 21474836528];
        temp_118 =  omni_virtualcode_121[(unsigned int) 34359738458];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836623];
        temp_117 = temp_117 ^ temp_118;
        temp_133 = ( unsigned int ) ( ( ( temp_117 ) &(unsigned int)  0xFFFFFFFF ) );
        *temp_132 = ( *temp_126);
        *temp_134 =  ( ( ( ( temp_117 ) &(unsigned int)  0xFFFFFFFF ) ));
        temp_117 =  omni_virtualcode_121[(unsigned int) 21474836529];
        temp_118 =  omni_virtualcode_121[(unsigned int) 34359738459];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836624];
        temp_117 = temp_117 ^ temp_118;
        temp_37 =  temp_117;
        temp_117 =  omni_virtualcode_121[(unsigned int) 21474836530];
        temp_118 =  omni_virtualcode_121[(unsigned int) 34359738460];
        temp_117 = temp_117 ^ temp_118;
        temp_118 =  omni_virtualcode_121[(unsigned int) 21474836625];
        temp_117 = temp_117 ^ temp_118;
        temp_118 = ( unsigned int ) (( *( ( bool * )(temp_119))));
        temp_117 =  temp_117 * ( (( *( ( bool * )(temp_119)))));
        temp_37 =  temp_37  +  temp_117;
        temp_56 = (unsigned int) 3756156282;
        temp_86 = (unsigned int) 1585;
        temp_37 =  temp_37  -(unsigned int)  1585;
        temp_49 = (temp_51);
        temp_54 =  (int)(unsigned int) 2062554531;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 7;
        temp_84 = (unsigned int) 7;
        temp_85 = (unsigned int) 72;
        temp_84 = (unsigned int) 79;
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 4294967276;
        temp_84 = (unsigned int) 4294967276;
        temp_86 = (unsigned int) 538;
        temp_37 =  temp_37  +(unsigned int)  538;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 151;
        temp_85 = (unsigned int) 1080;
        temp_84 = (unsigned int) 1081;
        temp_86 = ( unsigned int )(unsigned int) 1081;
        temp_37 =  temp_37 + ( ( ( ( ( ((unsigned int)  1080) + ( (( ( ( ( ( ( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 )) == 0 )) == 0 )) == 0 ))))) ) & 0xFFFFFFFF ) ));
        // The next string is really just an assignment on 32bit platform
        temp_54 =  ( int )( ( size_t )( temp_54 ) + ( ( ( size_t )( temp_54 ) <<(unsigned int)  31 ) <<(unsigned int)  1 ) + ( ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) >>(unsigned int)  15 ) );
        temp_41 = true;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 4;
        temp_85 = (unsigned int) 34;
        temp_84 = (unsigned int) 38;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 22;
        temp_84 = (unsigned int) 22;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 26;
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 8;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 113;
        temp_84 = (unsigned int) 113;
        temp_86 = ( unsigned int )(unsigned int) 113;
        temp_37 =  temp_37 - ( ( ( ( ( ((unsigned int)  113) + ( ( (( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 ))))) * ((unsigned int)  8))) ) & 0xFFFFFFFF ) ));
        // The next string is really just an assignment on 32bit platform
        temp_54 =  ( int )( ( size_t )( temp_54 ) + ( ( ( size_t )( temp_54 ) <<(unsigned int)  31 ) <<(unsigned int)  1 ) + ( ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) >>(unsigned int)  15 ) );
        temp_41 = true;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 4;
        temp_85 = (unsigned int) 34;
        temp_84 = (unsigned int) 38;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 22;
        temp_84 = (unsigned int) 22;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 26;
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 8;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 113;
        temp_84 = (unsigned int) 113;
        temp_86 = ( unsigned int )(unsigned int) 113;
        temp_37 =  temp_37 - ( ( ( ( ( ((unsigned int)  113) + ( ( (( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 ))))) * ((unsigned int)  8))) ) & 0xFFFFFFFF ) ));
        // The next string is really just an assignment on 32bit platform
        temp_54 =  ( int )( ( size_t )( temp_54 ) + ( ( ( size_t )( temp_54 ) <<(unsigned int)  31 ) <<(unsigned int)  1 ) + ( ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) >>(unsigned int)  15 ) );
        temp_41 = true;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 4;
        temp_85 = (unsigned int) 34;
        temp_84 = (unsigned int) 38;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 22;
        temp_84 = (unsigned int) 22;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 26;
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 8;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 113;
        temp_84 = (unsigned int) 113;
        temp_86 = ( unsigned int )(unsigned int) 113;
        temp_37 =  temp_37 - ( ( ( ( ( ((unsigned int)  113) + ( ( (( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 ))))) * ((unsigned int)  8))) ) & 0xFFFFFFFF ) ));
        // The next string is really just an assignment on 32bit platform
        temp_54 =  ( int )( ( size_t )( temp_54 ) + ( ( ( size_t )( temp_54 ) <<(unsigned int)  31 ) <<(unsigned int)  1 ) + ( ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) >>(unsigned int)  15 ) );
        temp_41 = true;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 4;
        temp_85 = (unsigned int) 34;
        temp_84 = (unsigned int) 38;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 22;
        temp_84 = (unsigned int) 22;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 26;
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 8;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 113;
        temp_84 = (unsigned int) 113;
        temp_86 = ( unsigned int )(unsigned int) 113;
        temp_37 =  temp_37 - ( ( ( ( ( ((unsigned int)  113) + ( ( (( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 ))))) * ((unsigned int)  8))) ) & 0xFFFFFFFF ) ));
        // The next string is really just an assignment on 32bit platform
        temp_54 =  ( int )( ( size_t )( temp_54 ) + ( ( ( size_t )( temp_54 ) <<(unsigned int)  31 ) <<(unsigned int)  1 ) + ( ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) >>(unsigned int)  15 ) );
        temp_41 = true;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 4;
        temp_85 = (unsigned int) 34;
        temp_84 = (unsigned int) 38;
        temp_122 = (unsigned int) 25769804068;
        temp_123 = (unsigned int) 42949673033;
        temp_84 = ( unsigned int )true;
        temp_85 = (unsigned int) 22;
        temp_84 = (unsigned int) 22;
        temp_85 = (unsigned int) 4;
        temp_84 = (unsigned int) 26;
        temp_117 = ( unsigned int )(unsigned int) 26;
        temp_124 = (unsigned int) 30064771300;
        temp_84 = ( unsigned int )false;
        temp_85 = (unsigned int) 8;
        temp_84 = (unsigned int) 0;
        temp_85 = (unsigned int) 113;
        temp_84 = (unsigned int) 113;
        temp_86 = ( unsigned int )(unsigned int) 113;
        temp_37 =  temp_37 - ( ( ( ( ( ((unsigned int)  113) + ( ( (( ( ( ( ( ( ( ((unsigned int)  0) ==(unsigned int)  0 )))) == 0 ))))) * ((unsigned int)  8))) ) & 0xFFFFFFFF ) ));
    temp_77 =  ( unsigned int * )(temp_57);
    temp_78 = ( unsigned char * )(temp_58);
    temp_78 = ( unsigned char * )(temp_59);
    temp_78 = ( unsigned char * )(temp_60);
    temp_78 = ( unsigned char * )(temp_61);
    temp_78 = ( unsigned char * )(temp_62);
    temp_78 = ( unsigned char * )(temp_63);
    temp_78 = ( unsigned char * )(temp_64);
    temp_78 = ( unsigned char * )(temp_65);
    *temp_78 = true;
    temp_77 =  ( unsigned int * )(temp_67);
    temp_77 =  ( unsigned int * )(temp_68);
    temp_78 = ( unsigned char * )(temp_69);
    *temp_78 = (temp_51);
    temp_78 = ( unsigned char * )(temp_70);
    *temp_78 =  temp_50;
    temp_82 =  ( int * )(temp_71);
    *temp_82 =  temp_51;
    temp_77 =  ( unsigned int * )(temp_72);
    temp_82 =  ( int * )(temp_73);
    *temp_82 =  temp_53;
    temp_82 =  ( int * )(temp_74);
    *temp_82 =  temp_54;
    temp_77 =  ( unsigned int * )(temp_75);
    temp_77 =  ( unsigned int * )(temp_76);
    *temp_77 = (unsigned int) 3756156282;
    return;
}