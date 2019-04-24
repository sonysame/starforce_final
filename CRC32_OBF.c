#include <stdio.h>
#include <string.h>

#define CRC32(crc,ch) (crc=(crc>>8)^crc32tab[(crc^(ch))&0xff])

static const unsigned int crc32tab[256]={
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
    0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
    0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
    0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
    0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
    0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
    0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
    0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
    0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
    0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
    0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
    0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
    0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
    0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
    0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
    0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
    0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
    0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
    0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
    0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
    0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
    0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
    0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
    0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
    0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
    0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
    0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
    0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
    0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
    0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
    0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
    0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
    0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
    0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
    0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
    0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
    0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
    0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
    0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
    0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
    0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
    0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
    0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
    0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
    0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
    0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
    0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
    0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
    0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
    0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
    0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
    0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
    0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
    0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
    0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
    0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
    0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
    0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
    0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
    0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
    0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
    0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d,
};

unsigned int crc32(char *);


/// OBFUSCATED BY OMNI OBFUSCATOR V1.2.1712.19, SEED VALUE: 101856395


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

static void omni_global_function( void *temp_69, void *temp_70, void *temp_71, void *temp_72, void *temp_73, void 
    *temp_74, void *temp_75, void *temp_76, void *temp_77, void *temp_78, void *temp_79, void *temp_80, void *temp_81, void 
    *temp_82, void *temp_83, void *temp_84, void *temp_85, void *temp_86, void *temp_87, void *temp_88, void *temp_89, void 
    *temp_90, void *temp_91, void *temp_92, void *temp_93 ) OMNI_THROWS;



// Obfuscated function
int main( int argc_0, char **argv_1 )
{
    char *test_5;
    char const *temp_6 = "This is Test program";
    int temp_9;
    char const *temp_11 = "%d\n";
    bool temp_12;
    unsigned int temp_13;
    unsigned int temp_14;
    unsigned int temp_15;
    bool temp_19;
    bool temp_20;
    char **temp_22;
    unsigned int temp_28;
    int temp_29;
    int temp_30;
    int temp_31;
    unsigned int temp_32;
    unsigned int temp_33;
    unsigned int temp_34;
    bool state0_35;
    bool state1_36;
    bool state2_37;
    bool state3_38;
    bool state4_39;
    bool state5_40;
    bool state6_41;
    bool state7_42;
    unsigned int temp_43;
    void *temp_111;
    void *temp_112;
    void *temp_113;
    void *temp_114;
    void *temp_115;
    void *temp_116;
    void *temp_117;
    void *temp_118;
    void *temp_119;
    void *temp_120;
    void *temp_121;
    void *temp_122;
    void *temp_123;
    void *temp_124;
    void *temp_125;
    void *temp_126;
    void *temp_127;
    void *temp_128;
    void *temp_129;
    void *temp_130;
    void *temp_131;
    void *temp_132;
    void *temp_133;
    void *temp_134;
    void *temp_135;
    
    L99:
    L98:
    temp_43 = (unsigned int)3620u;
    temp_15 = (unsigned int)3283;
    temp_43 = temp_43 - temp_15;
    goto L102;
    
    L102:
    switch( temp_43)
    {
    case 337u: goto L101;
    case 268u: goto L101;
    default: goto L98;
    }
    
    L101:
    {
        
        L100:
        temp_135 = &argv_1;
        temp_134 = &argc_0;
        temp_133 = &temp_34;
        temp_132 = &temp_33;
        temp_131 = &temp_32;
        temp_130 = &temp_31;
        temp_129 = &temp_30;
        temp_128 = &temp_29;
        temp_127 = &temp_28;
        temp_126 = &temp_22;
        temp_125 = &temp_20;
        temp_124 = &temp_19;
        temp_123 = &temp_11;
        temp_122 = &temp_9;
        temp_121 = &temp_6;
        temp_120 = &test_5;
        temp_119 = &state7_42;
        temp_118 = &state6_41;
        temp_117 = &state5_40;
        temp_116 = &state4_39;
        temp_115 = &state3_38;
        temp_114 = &state2_37;
        temp_113 = &state1_36;
        temp_112 = &state0_35;
        temp_111 = &temp_43;
        omni_global_function( ( void * )temp_111, ( void * )temp_112, ( void * )temp_113, ( void * )temp_114, ( void * )temp_115, 
            ( void * )temp_116, ( void * )temp_117, ( void * )temp_118, ( void * )temp_119, ( void * )temp_120, 
            ( void * )temp_121, ( void * )temp_122, ( void * )temp_123, ( void * )temp_124, ( void * )temp_125, 
            ( void * )temp_126, ( void * )temp_127, ( void * )temp_128, ( void * )temp_129, ( void * )temp_130, 
            ( void * )temp_131, ( void * )temp_132, ( void * )temp_133, ( void * )temp_134, ( void * )temp_135 );
        goto L106;
        
        L106:
        switch( temp_43)
        {
        case 933u: goto L112;
        case 330u: goto L112;
        default: goto L108;
        }
        
        L108:
        return temp_31;
        
        L112:
        return temp_31;
        
    }

}





unsigned int crc32(char *src){

    unsigned int crc=~0;
    int len=0,src_len;

    src_len=strlen(src);

    for(len+=src_len;src_len--;++src){

        CRC32(crc,*src);

    }

    return ~crc;

} 


// Obfuscator generated function
static void omni_global_function( void *temp_69, void *temp_70, void *temp_71, void *temp_72, void *temp_73, void 
    *temp_74, void *temp_75, void *temp_76, void *temp_77, void *temp_78, void *temp_79, void *temp_80, void *temp_81, void 
    *temp_82, void *temp_83, void *temp_84, void *temp_85, void *temp_86, void *temp_87, void *temp_88, void *temp_89, void 
    *temp_90, void *temp_91, void *temp_92, void *temp_93 ) OMNI_THROWS
{
    unsigned int temp_44;
    bool temp_45;
    bool temp_46;
    bool temp_47;
    bool temp_48;
    bool temp_49;
    bool temp_50;
    bool temp_51;
    bool temp_52;
    char *temp_53;
    char const *temp_54;
    int temp_55;
    char const *temp_56;
    bool temp_57;
    bool temp_58;
    char **temp_59;
    unsigned int temp_60;
    int temp_61;
    int temp_62;
    int temp_63;
    unsigned int temp_64;
    unsigned int temp_65;
    unsigned int temp_66;
    int temp_67;
    char **temp_68;
    bool temp_102;
    unsigned int temp_103;
    unsigned int temp_104;
    unsigned int temp_105;
    unsigned int temp_106;
    unsigned int temp_107;
    unsigned int temp_108;
    bool temp_109;
    bool temp_110;
    unsigned int *temp_94;
    unsigned char *temp_95;
    unsigned char temp_96;
    unsigned char temp_97;
    char **temp_98;
    char const **temp_99;
    int *temp_100;
    char ***temp_101;
    void *temp_136[84];
    void **temp_137;
    size_t temp_138;
    void *temp_139;
    unsigned int temp_140;
    unsigned int temp_141;
    unsigned int temp_142;
    void *temp_143;
    bool temp_144;
    static unsigned int omni_virtualcode_145[97] = { 3206114213u, 3409011120u, 2580183503u, 287063257u, 3089821288u, 642278202u, 3134920151u, 2355196788u, 2746317592u, 
        1770228477u, 1530032953u, 96587677u, 773690846u, 1352788978u, 1272921021u, 1503561965u, 1159660323u, 3634747731u, 
        2503168109u, 2794983997u, 363448464u, 1070525336u, 2260785041u, 1200628389u, 216804109u, 43972218u, 2908043187u, 
        3668487295u, 3579359429u, 3721727730u, 3573814171u, 1010886500u, 1604263200u, 3447097401u, 203378770u, 2331592236u, 
        3601954246u, 281082313u, 2671056162u, 565542897u, 2831220386u, 590690137u, 437896340u, 2677311244u, 2168209116u, 
        3264698340u, 1272579440u, 3757544213u, 1322777052u, 3957632419u, 1070316479u, 4286585062u, 1253488697u, 1713724765u, 
        2754402518u, 510251388u, 1142911328u, 3289919316u, 2221541656u, 2044165647u, 2007865875u, 2155750195u, 692600119u, 
        1783912598u, 1274186415u, 2599739075u, 262728249u, 4167112004u, 1760169201u, 1132939724u, 3666576447u, 1503258507u, 
        3974414446u, 3980530381u, 3395181499u, 1897469788u, 3839833308u, 4043378854u, 1402396770u, 3982921217u, 2187798363u, 
        1694091394u, 4198619005u, 1688936619u, 914667168u, 4025737541u, 1207392642u, 16809712u, 482211346u, 291068274u, 
        170511263u, 1644452658u, 1078932620u, 2944985769u, 767849170u, 1193189809u, 2557093162u };
    unsigned int temp_146;
    unsigned int temp_147;
    unsigned int temp_148;
    unsigned int temp_149;
    unsigned int *temp_150;
    unsigned int temp_151;
    unsigned int *temp_152;
    unsigned int temp_153;
    unsigned int *temp_154;
    bool temp_155;
    bool *temp_156;
    char **temp_157;
    char ***temp_158;
    int temp_159;
    int *temp_160;
    bool temp_161;
    bool *temp_162;
    bool temp_163;
    bool *temp_164;
    char *temp_165;
    
    L119:
    L118:
    temp_44 = (unsigned int)659u;
    temp_94 = ( unsigned int * )(temp_69);
    temp_44 = *temp_94;
    temp_95 = ( unsigned char * )(temp_70);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_45 = temp_96 > temp_97;
    temp_95 = ( unsigned char * )(temp_71);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_46 = temp_96 > temp_97;
    temp_95 = ( unsigned char * )(temp_72);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_47 = temp_96 > temp_97;
    temp_95 = ( unsigned char * )(temp_73);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_48 = temp_96 > temp_97;
    temp_95 = ( unsigned char * )(temp_74);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_49 = temp_96 > temp_97;
    temp_95 = ( unsigned char * )(temp_75);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_50 = temp_96 > temp_97;
    temp_95 = ( unsigned char * )(temp_76);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_51 = temp_96 > temp_97;
    temp_95 = ( unsigned char * )(temp_77);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_52 = temp_96 > temp_97;
    temp_98 = ( char ** )(temp_78);
    temp_53 = *temp_98;
    temp_99 = ( char const ** )(temp_79);
    temp_54 = *temp_99;
    temp_100 = ( int * )(temp_80);
    temp_55 = *temp_100;
    temp_99 = ( char const ** )(temp_81);
    temp_56 = *temp_99;
    temp_95 = ( unsigned char * )(temp_82);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_57 = temp_96 > temp_97;
    temp_95 = ( unsigned char * )(temp_83);
    temp_96 = *temp_95;
    temp_97 = (unsigned char)0u;
    temp_58 = temp_96 > temp_97;
    temp_101 = ( char *** )(temp_84);
    temp_59 = *temp_101;
    temp_94 = ( unsigned int * )(temp_85);
    temp_60 = *temp_94;
    temp_100 = ( int * )(temp_86);
    temp_61 = *temp_100;
    temp_100 = ( int * )(temp_87);
    temp_62 = *temp_100;
    temp_100 = ( int * )(temp_88);
    temp_63 = *temp_100;
    temp_94 = ( unsigned int * )(temp_89);
    temp_64 = *temp_94;
    temp_94 = ( unsigned int * )(temp_90);
    temp_65 = *temp_94;
    temp_94 = ( unsigned int * )(temp_91);
    temp_66 = *temp_94;
    temp_100 = ( int * )(temp_92);
    temp_67 = *temp_100;
    temp_101 = ( char *** )(temp_93);
    temp_68 = *temp_101;
    temp_106 = (unsigned int)0u;
    temp_107 = (unsigned int)0u;
    temp_108 = (unsigned int)0u;
    temp_109 = (bool)0u;
    temp_110 = (bool)0u;
    temp_137 = ( void ** )(temp_136);
    temp_138 = (size_t)1u;
    temp_139 = &temp_44;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_45;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_46;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_47;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_48;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_49;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_50;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_51;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_52;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_53;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_54;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_55;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_56;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_57;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_58;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_59;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_60;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_61;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_62;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_63;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_64;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_65;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_66;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_67;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_68;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_102;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_103;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_104;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_105;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_106;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_107;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_108;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_109;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_110;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_94;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_95;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_96;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_97;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_98;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_99;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_100;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_101;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_69;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_70;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_71;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_72;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_73;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_74;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_75;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_76;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_77;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_78;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_79;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_80;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_81;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_82;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_83;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_84;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_85;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_86;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_87;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_88;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_89;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_90;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_91;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_92;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_139 = &temp_93;
    *temp_137 = temp_139;
    temp_137 = temp_137 + temp_138;
    temp_140 = (unsigned int)1u;
    goto L117;
    
    L120:
    temp_94 = ( unsigned int * )(temp_69);
    *temp_94 = temp_44;
    temp_95 = ( unsigned char * )(temp_70);
    *temp_95 = temp_45;
    temp_95 = ( unsigned char * )(temp_71);
    *temp_95 = temp_46;
    temp_95 = ( unsigned char * )(temp_72);
    *temp_95 = temp_47;
    temp_95 = ( unsigned char * )(temp_73);
    *temp_95 = temp_48;
    temp_95 = ( unsigned char * )(temp_74);
    *temp_95 = temp_49;
    temp_95 = ( unsigned char * )(temp_75);
    *temp_95 = temp_50;
    temp_95 = ( unsigned char * )(temp_76);
    *temp_95 = temp_51;
    temp_95 = ( unsigned char * )(temp_77);
    *temp_95 = temp_52;
    temp_98 = ( char ** )(temp_78);
    *temp_98 = temp_53;
    temp_100 = ( int * )(temp_80);
    *temp_100 = temp_55;
    temp_95 = ( unsigned char * )(temp_82);
    *temp_95 = temp_57;
    temp_95 = ( unsigned char * )(temp_83);
    *temp_95 = temp_58;
    temp_101 = ( char *** )(temp_84);
    *temp_101 = temp_59;
    temp_94 = ( unsigned int * )(temp_85);
    *temp_94 = temp_60;
    temp_100 = ( int * )(temp_86);
    *temp_100 = temp_61;
    temp_100 = ( int * )(temp_87);
    *temp_100 = temp_62;
    temp_100 = ( int * )(temp_88);
    *temp_100 = temp_63;
    temp_94 = ( unsigned int * )(temp_89);
    *temp_94 = temp_64;
    temp_94 = ( unsigned int * )(temp_90);
    *temp_94 = temp_65;
    temp_94 = ( unsigned int * )(temp_91);
    *temp_94 = temp_66;
    return;
    
    L117:
    #ifdef __cplusplus
    try
    #endif
    {
        
        L116:
        switch( temp_44)
        {
        case 337u: goto L0;
        case 268u: goto L0;
        case 1937u: goto L184;
        case 1270u: goto L182;
        case 1470u: goto L180;
        case 3980u: goto L178;
        case 742u: goto L176;
        case 624u: goto L174;
        case 3296u: goto L172;
        case 2698u: goto L170;
        case 461u: goto L168;
        case 558u: goto L166;
        case 503u: goto L164;
        case 1461u: goto L162;
        case 2744u: goto L160;
        case 3404u: goto L156;
        case 1437u: goto L152;
        case 2273u: goto L148;
        case 3251u: goto L144;
        case 1304u: goto L140;
        case 3449u: goto L134;
        case 1629u: goto L130;
        case 495u: goto L128;
        case 2045u: goto L126;
        case 1305u: goto L96;
        case 62u: goto L96;
        case 2356u: goto L96;
        case 3343u: goto L96;
        case 3509u: goto L94;
        case 2739u: goto L94;
        case 2523u: goto L92;
        case 604u: goto L92;
        case 1936u: goto L90;
        case 752u: goto L90;
        case 3475u: goto L88;
        case 2005u: goto L88;
        case 168u: goto L86;
        case 2079u: goto L86;
        case 2627u: goto L86;
        case 3406u: goto L84;
        case 2543u: goto L84;
        case 2861u: goto L82;
        case 642u: goto L82;
        case 3255u: goto L80;
        case 552u: goto L80;
        case 2412u: goto L78;
        case 3886u: goto L78;
        case 4012u: goto L76;
        case 1441u: goto L76;
        case 3382u: goto L74;
        case 3657u: goto L74;
        case 2735u: goto L72;
        case 586u: goto L72;
        case 89u: goto L70;
        case 2614u: goto L70;
        case 1825u: goto L68;
        case 2714u: goto L68;
        case 1251u: goto L68;
        case 3269u: goto L66;
        case 1848u: goto L66;
        case 2147u: goto L64;
        case 588u: goto L64;
        case 3302u: goto L64;
        case 852u: goto L64;
        case 3752u: goto L62;
        case 483u: goto L62;
        case 2481u: goto L60;
        case 2462u: goto L60;
        case 2192u: goto L56;
        case 1406u: goto L56;
        case 95u: goto L54;
        case 2u: goto L54;
        case 3995u: goto L54;
        case 1758u: goto L52;
        case 438u: goto L52;
        case 3101u: goto L50;
        case 1794u: goto L50;
        case 155u: goto L50;
        case 1061u: goto L48;
        case 3049u: goto L48;
        case 2915u: goto L46;
        case 1418u: goto L46;
        case 6u: goto L44;
        case 542u: goto L42;
        case 54u: goto L42;
        case 4081u: goto L38;
        case 2289u: goto L38;
        case 1427u: goto L36;
        case 3741u: goto L36;
        case 3977u: goto L32;
        case 3525u: goto L32;
        case 2368u: goto L32;
        case 1408u: goto L30;
        case 612u: goto L30;
        case 1243u: goto L26;
        case 2699u: goto L26;
        case 1465u: goto L24;
        case 3499u: goto L22;
        case 734u: goto L22;
        case 2057u: goto L20;
        case 1964u: goto L20;
        case 1023u: goto L18;
        case 2869u: goto L18;
        case 1840u: goto L16;
        case 456u: goto L16;
        case 3416u: goto L14;
        case 3445u: goto L14;
        case 1496u: goto L8;
        case 1910u: goto L8;
        case 3066u: goto L8;
        case 2366u: goto L8;
        case 978u: goto L6;
        case 2402u: goto L6;
        case 708u: goto L4;
        case 2743u: goto L4;
        case 999u: goto L4;
        case 924u: goto L2;
        case 3819u: goto L2;
        case 659u: goto L118;
        default: goto L120;
        }
        
        L0:
        temp_148 = (unsigned int)76;
        temp_147 = (unsigned int)5;
        temp_45 = (bool)0;
        temp_146 = (unsigned int)45;
        temp_105 = (unsigned int)124u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L2:
        temp_57 = ( bool )(temp_63);
        temp_141 = (unsigned int)4294967252u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)8u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)19u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)684u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_45);
        temp_104 = (unsigned int)597u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1065u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L4:
        temp_141 = (unsigned int)4294967281u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)3u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)48u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)540u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L6:
        temp_65 = temp_64 + temp_66;
        temp_141 = (unsigned int)4294967282u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967291u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)2774u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L8:
        temp_53 = ( char * )(temp_57);
        temp_64 = (unsigned int)temp_48;
        temp_65 = ( unsigned int )( temp_46 == 0 );
        temp_141 = (unsigned int)4294967279u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)53u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967249u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1106u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)135u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1802u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L14:
        temp_63 = ( int )(temp_57);
        // The next string is really just an assignment on 32bit platform
        temp_60 = ( unsigned int )( ( size_t )( temp_60 ) + ( ( ( size_t )( temp_60 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_60 ) << 31 ) << 1 ) >> 15 ) );
        temp_66 = (unsigned int)0u;
        temp_141 = (unsigned int)47u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)1u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)34u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)681u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L16:
        temp_64 = temp_66 ^ temp_65;
        temp_57 = (bool)temp_51;
        temp_59 = ( char ** )(temp_57);
        temp_141 = (unsigned int)4294967271u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)31u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)7u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)932u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)1157u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)850u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L18:
        temp_62 = (int)2851521011u;
        // The next string is really just an assignment on 32bit platform
        temp_62 = ( int )( ( size_t )( temp_62 ) + ( ( ( size_t )( temp_62 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_62 ) << 31 ) << 1 ) >> 15 ) );
        temp_141 = (unsigned int)4294967293u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)15u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)21u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)547u;
        temp_44 = temp_44 + temp_105;
        temp_103 = ( unsigned int )(temp_51);
        temp_104 = (unsigned int)1557u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1812u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L20:
        temp_57 = ( bool )(temp_58);
        temp_58 = ( bool )( temp_57 == 0 );
        temp_141 = (unsigned int)37u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)9u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)38u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1562u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L22:
        temp_47 = ( bool )( temp_51 == 0 );
        temp_141 = (unsigned int)4294967277u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967265u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967210u;
        temp_148 = temp_148 + temp_141;
        temp_141 = (unsigned int)2u;
        temp_142 = (unsigned int)0u;
        temp_141 = temp_141 & temp_148;
        temp_144 = temp_141 != temp_142;
        temp_105 = (unsigned int)3292u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_144);
        temp_104 = (unsigned int)1990u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)2491u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L24:
        temp_47 = (bool)temp_52;
        temp_141 = (unsigned int)4294967272u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967263u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967248u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1233u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L26:
        temp_65 = (unsigned int)temp_64;
        temp_66 = (unsigned int)3141584871u;
        temp_105 = (unsigned int)944u;
        temp_44 = temp_44 + temp_105;
        temp_103 = ( unsigned int )(temp_49);
        temp_104 = (unsigned int)1337u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1894u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L30:
        // The next string is really just an assignment on 32bit platform
        temp_60 = ( unsigned int )( ( size_t )( temp_60 ) + ( ( ( size_t )( temp_60 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_60 ) << 31 ) << 1 ) >> 15 ) );
        temp_65 = temp_64 - temp_60;
        temp_105 = (unsigned int)1888u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L32:
        temp_62 = (int)2851521011u;
        temp_57 = ( bool )( size_t )(temp_59);
        temp_141 = (unsigned int)4294967253u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)50u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)26u;
        temp_148 = temp_148 + temp_141;
        temp_141 = (unsigned int)1u;
        temp_142 = (unsigned int)0u;
        temp_141 = temp_141 & temp_146;
        temp_144 = temp_141 != temp_142;
        temp_105 = (unsigned int)3266u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_144);
        temp_104 = (unsigned int)2026u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)559u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L36:
        temp_64 = ( unsigned int )( size_t )(temp_59);
        temp_141 = (unsigned int)9u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)9u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)9u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)924u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L38:
        temp_64 = ( unsigned int )( temp_52 == 0 );
        temp_65 = ( unsigned int )( temp_52 == 0 );
        temp_66 = (unsigned int)0u;
        temp_141 = (unsigned int)29u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967264u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)41u;
        temp_148 = temp_148 + temp_141;
        temp_141 = (unsigned int)1u;
        temp_142 = (unsigned int)0u;
        temp_141 = temp_141 & temp_146;
        temp_144 = temp_141 != temp_142;
        temp_105 = (unsigned int)3006u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_144);
        temp_104 = (unsigned int)394u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)2180u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L42:
        temp_64 = temp_66 ^ temp_65;
        temp_57 = (bool)0u;
        temp_63 = ( int )(temp_57);
        temp_141 = (unsigned int)43u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967246u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967270u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)156u;
        temp_44 = temp_44 + temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)2916u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)363u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L44:
        temp_55 = temp_61 + temp_62;
        temp_63 = ( int )( temp_52 == 0 );
        temp_141 = (unsigned int)23u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)51u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)37u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)424u;
        temp_44 = temp_44 + temp_105;
        temp_103 = ( unsigned int )(temp_52);
        temp_104 = (unsigned int)2516u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)2558u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L46:
        temp_66 = ( unsigned int )(temp_57);
        temp_55 = temp_61 + temp_62;
        temp_63 = (int)0;
        temp_141 = (unsigned int)63u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)5u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967264u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1982u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L48:
        temp_58 = (bool)0u;
        temp_141 = (unsigned int)7u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967295u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967255u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)137u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L50:
        // The next string is really just an assignment on 32bit platform
        temp_62 = ( int )( ( size_t )( temp_62 ) + ( ( ( size_t )( temp_62 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_62 ) << 31 ) << 1 ) >> 15 ) );
        temp_59 = ( char ** )(temp_57);
        temp_141 = (unsigned int)50u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967254u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)15u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)374u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L52:
        temp_59 = ( char ** )(temp_64);
        temp_58 = (bool)0u;
        temp_141 = (unsigned int)4294967287u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)40u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)38u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)765u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L54:
        // The next string is really just an assignment on 32bit platform
        temp_65 = ( unsigned int )( ( size_t )( temp_65 ) + ( ( ( size_t )( temp_65 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_65 ) << 31 ) << 1 ) >> 15 ) );
        temp_59 = ( char ** )(temp_63);
        temp_141 = (unsigned int)4294967264u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967258u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)70u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)73u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L56:
        temp_63 = ( int )( size_t )(temp_59);
        temp_51 = ( bool )( temp_52 == 0 );
        temp_66 = (unsigned int)0u;
        temp_141 = (unsigned int)4u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967230u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)34u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)256u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L60:
        // The next string is really just an assignment on 32bit platform
        temp_65 = ( unsigned int )( ( size_t )( temp_65 ) + ( ( ( size_t )( temp_65 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_65 ) << 31 ) << 1 ) >> 15 ) );
        temp_141 = (unsigned int)4294967293u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967292u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967259u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1496u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L62:
        temp_65 = temp_65 - temp_66;
        temp_66 = (unsigned int)3141584871u;
        temp_141 = (unsigned int)4294967292u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967287u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967280u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)2666u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_51);
        temp_104 = (unsigned int)660u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1658u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L64:
        temp_65 = temp_64 + temp_66;
        temp_141 = (unsigned int)4294967248u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)35u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967249u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1149u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L66:
        temp_48 = (bool)temp_47;
        temp_105 = (unsigned int)2808u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L68:
        temp_141 = (unsigned int)4294967282u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)34u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)5u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1247u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_52);
        temp_104 = (unsigned int)399u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)445u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L70:
        temp_141 = (unsigned int)4294967288u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967288u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967288u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)70u;
        temp_44 = temp_44 + temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)1333u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)3110u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L72:
        temp_66 = temp_66 - temp_60;
        temp_141 = (unsigned int)4294967260u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967285u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967278u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)671u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L74:
        temp_65 = ( unsigned int )(temp_57);
        temp_141 = (unsigned int)4294967295u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967286u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)57u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1886u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L76:
        temp_63 = ( int )(temp_57);
        temp_141 = (unsigned int)4294967293u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)64u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967289u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)3034u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L78:
        temp_141 = (unsigned int)4294967286u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)43u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967212u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)2285u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_48);
        temp_104 = (unsigned int)2291u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1334u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L80:
        temp_141 = (unsigned int)4294967256u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967274u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967264u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)3120u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_52);
        temp_104 = (unsigned int)2173u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)2780u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L82:
        temp_52 = (bool)temp_51;
        temp_141 = (unsigned int)4294967225u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967274u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967256u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)2153u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L84:
        temp_53 = ( char * )(temp_57);
        temp_141 = (unsigned int)12u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967262u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)65u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)2413u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_51);
        temp_104 = (unsigned int)686u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1154u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L86:
        temp_141 = (unsigned int)30u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967284u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967245u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1489u;
        temp_44 = temp_44 + temp_105;
        temp_103 = ( unsigned int )(temp_51);
        temp_104 = (unsigned int)15u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)183u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L88:
        temp_57 = ( bool )(temp_65);
        temp_141 = (unsigned int)4294967275u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)49u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967245u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)3215u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_51);
        temp_104 = (unsigned int)2024u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1797u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L90:
        temp_141 = (unsigned int)4294967281u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)52u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967223u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1786u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)1955u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1311u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L92:
        temp_66 = ( unsigned int )(temp_57);
        temp_141 = (unsigned int)63u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967226u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967235u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)2296u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)99u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)697u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L94:
        temp_141 = (unsigned int)4294967289u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967289u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967289u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)3461u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)1372u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1413u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L96:
        temp_141 = (unsigned int)25u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)61u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)53u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)646u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)2034u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)806u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L126:
        temp_60 = (unsigned int)3141584871u;
        temp_141 = (unsigned int)30u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967259u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)88u;
        temp_148 = temp_148 + temp_141;
        temp_141 = (unsigned int)1u;
        temp_142 = (unsigned int)0u;
        temp_141 = temp_141 & temp_146;
        temp_144 = temp_141 != temp_142;
        temp_105 = (unsigned int)213u;
        temp_44 = temp_44 + temp_105;
        temp_103 = ( unsigned int )(temp_144);
        temp_104 = (unsigned int)1028u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1251u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L128:
        temp_141 = (unsigned int)4294967223u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967283u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967265u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)692u;
        temp_44 = temp_44 + temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)228u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)2565u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L130:
        temp_64 = ( unsigned int )crc32( ( char * )temp_53 );
        temp_141 = (unsigned int)7u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967255u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)28u;
        temp_148 = temp_148 + temp_141;
        temp_141 = (unsigned int)2u;
        temp_142 = (unsigned int)0u;
        temp_141 = temp_141 & temp_148;
        temp_144 = temp_141 != temp_142;
        temp_105 = (unsigned int)1198u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_144);
        temp_104 = (unsigned int)959u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)547u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L134:
        temp_64 = ( unsigned int )crc32( ( char * )temp_53 );
        temp_141 = (unsigned int)19u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967259u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)50u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1037u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L140:
        temp_61 = ( int )printf( ( char const * )temp_56, temp_65 );
        temp_66 = ( unsigned int )(temp_57);
        temp_141 = (unsigned int)4294967263u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967288u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)60u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)762u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L144:
        temp_141 = (unsigned int)4294967284u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)34u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967231u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)2790u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)2345u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)2945u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L148:
        temp_105 = (unsigned int)1815u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_51);
        temp_104 = (unsigned int)2951u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)3051u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L152:
        temp_61 = ( int )printf( ( char const * )temp_56, temp_65 );
        temp_141 = (unsigned int)4294967289u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)34u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)34u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)1086u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L156:
        temp_51 = ( bool )( temp_50 == 0 );
        temp_141 = (unsigned int)40u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)34u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967286u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)543u;
        temp_44 = temp_44 - temp_105;
        goto L116;
        
        L160:
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_150 = ( unsigned int * )(temp_143);
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_152 = ( unsigned int * )(temp_143);
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_154 = ( unsigned int * )(temp_143);
        temp_153 = *temp_154;
        temp_149 = *temp_150;
        // The next string is really just an assignment on 32bit platform
        temp_149 = ( unsigned int )( ( size_t )( temp_149 ) + ( ( ( size_t )( temp_149 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_149 ) << 31 ) << 1 ) >> 15 ) );
        temp_151 = temp_153 + temp_149;
        *temp_150 = temp_149;
        *temp_152 = temp_151;
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_44 = (unsigned int)temp_141;
        goto L116;
        
        L162:
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_150 = ( unsigned int * )(temp_143);
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_156 = ( bool * )(temp_143);
        temp_155 = *temp_156;
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_149 = ( unsigned int )( ( size_t )( ( temp_141 ) & 0xFFFFFFFF ) );
        *temp_150 = temp_149;
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_44 = (unsigned int)temp_141;
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = ( unsigned int )(temp_155);
        temp_141 = temp_141 * temp_142;
        temp_44 = temp_44 + temp_141;
        goto L116;
        
        L164:
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_158 = ( char *** )(temp_143);
        temp_101 = ( char *** )(temp_93);
        temp_68 = *temp_101;
        temp_157 = (char **)temp_68;
        *temp_158 = temp_157;
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_44 = (unsigned int)temp_141;
        goto L116;
        
        L166:
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_160 = ( int * )(temp_143);
        temp_100 = ( int * )(temp_92);
        temp_67 = *temp_100;
        temp_159 = (int)temp_67;
        *temp_160 = temp_159;
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_44 = (unsigned int)temp_141;
        goto L116;
        
        L168:
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_156 = ( bool * )(temp_143);
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_162 = ( bool * )(temp_143);
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_164 = ( bool * )(temp_143);
        temp_161 = *temp_162;
        temp_155 = ( bool )( temp_161 == 0 );
        temp_163 = ( bool )( temp_155 == 0 );
        *temp_156 = temp_155;
        *temp_164 = temp_163;
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_44 = (unsigned int)temp_141;
        goto L116;
        
        L170:
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_143 = temp_136[ temp_141 ];
        temp_157 = ( char ** )(temp_143);
        temp_99 = ( char const ** )(temp_79);
        temp_54 = *temp_99;
        temp_165 = ( char * )(temp_54);
        *temp_157 = temp_165;
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_44 = (unsigned int)temp_141;
        goto L116;
        
        L172:
        temp_99 = ( char const ** )(temp_81);
        temp_56 = *temp_99;
        temp_141 = omni_virtualcode_145[ temp_146 ];
        temp_146 = temp_146 + temp_140;
        temp_142 = omni_virtualcode_145[ temp_147 ];
        temp_147 = temp_147 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_142 = omni_virtualcode_145[ temp_148 ];
        temp_148 = temp_148 + temp_140;
        temp_141 = temp_141 ^ temp_142;
        temp_44 = (unsigned int)temp_141;
        goto L116;
        
        L174:
        temp_141 = (unsigned int)30u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967259u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)48u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)168u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_45);
        temp_104 = (unsigned int)924u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)971u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L176:
        temp_51 = (bool)temp_47;
        temp_141 = (unsigned int)19u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967288u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)29u;
        temp_148 = temp_148 + temp_141;
        temp_141 = (unsigned int)1u;
        temp_142 = (unsigned int)0u;
        temp_141 = temp_141 & temp_147;
        temp_144 = temp_141 != temp_142;
        temp_105 = (unsigned int)681u;
        temp_44 = temp_44 + temp_105;
        temp_103 = ( unsigned int )(temp_144);
        temp_104 = (unsigned int)1869u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1873u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L178:
        temp_141 = (unsigned int)28u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967241u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)4294967274u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)3980u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_58);
        temp_104 = (unsigned int)1834u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)1840u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L180:
        temp_141 = (unsigned int)9u;
        temp_146 = temp_146 + temp_141;
        temp_141 = (unsigned int)4294967238u;
        temp_147 = temp_147 + temp_141;
        temp_141 = (unsigned int)67u;
        temp_148 = temp_148 + temp_141;
        temp_105 = (unsigned int)677u;
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L182:
        temp_105 = (unsigned int)751u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_47);
        temp_104 = (unsigned int)2559u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)23u;
        temp_103 = temp_104 + temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
        L184:
        temp_105 = (unsigned int)851u;
        temp_44 = temp_44 - temp_105;
        temp_103 = ( unsigned int )(temp_50);
        temp_104 = (unsigned int)2187u;
        temp_103 = temp_103 * temp_104;
        temp_104 = (unsigned int)2926u;
        temp_103 = temp_104 - temp_103;
        temp_105 = ( unsigned int )( ( size_t )( ( temp_103 ) & 0xFFFFFFFF ) );
        temp_44 = temp_44 + temp_105;
        goto L116;
        
    }

    #ifdef __cplusplus
    catch( ... )
    {
        
        L123:
        L122:
        temp_94 = ( unsigned int * )(temp_69);
        *temp_94 = temp_44;
        temp_95 = ( unsigned char * )(temp_70);
        *temp_95 = temp_45;
        temp_95 = ( unsigned char * )(temp_71);
        *temp_95 = temp_46;
        temp_95 = ( unsigned char * )(temp_72);
        *temp_95 = temp_47;
        temp_95 = ( unsigned char * )(temp_73);
        *temp_95 = temp_48;
        temp_95 = ( unsigned char * )(temp_74);
        *temp_95 = temp_49;
        temp_95 = ( unsigned char * )(temp_75);
        *temp_95 = temp_50;
        temp_95 = ( unsigned char * )(temp_76);
        *temp_95 = temp_51;
        temp_95 = ( unsigned char * )(temp_77);
        *temp_95 = temp_52;
        temp_98 = ( char ** )(temp_78);
        *temp_98 = temp_53;
        temp_100 = ( int * )(temp_80);
        *temp_100 = temp_55;
        temp_95 = ( unsigned char * )(temp_82);
        *temp_95 = temp_57;
        temp_95 = ( unsigned char * )(temp_83);
        *temp_95 = temp_58;
        temp_101 = ( char *** )(temp_84);
        *temp_101 = temp_59;
        temp_94 = ( unsigned int * )(temp_85);
        *temp_94 = temp_60;
        temp_100 = ( int * )(temp_86);
        *temp_100 = temp_61;
        temp_100 = ( int * )(temp_87);
        *temp_100 = temp_62;
        temp_100 = ( int * )(temp_88);
        *temp_100 = temp_63;
        temp_94 = ( unsigned int * )(temp_89);
        *temp_94 = temp_64;
        temp_94 = ( unsigned int * )(temp_90);
        *temp_94 = temp_65;
        temp_94 = ( unsigned int * )(temp_91);
        *temp_94 = temp_66;
        throw ;
        
    }

    #endif
}

