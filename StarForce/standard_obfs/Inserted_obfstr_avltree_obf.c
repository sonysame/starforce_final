#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _AVL_DEF_
#define _AVL_DEF_

#define VALUE_SIZE	100

typedef struct AVLTreeNodeDataType
{
	int key;
	char value[VALUE_SIZE + 1];
} AVLTreeNodeData;

typedef struct AVLTreeNodeType
{
	AVLTreeNodeData data;

	int balance;
	int height;
	struct AVLTreeNodeType* pLeftChild;
	struct AVLTreeNodeType* pRightChild;
} AVLTreeNode;

#endif

#ifndef _LINKED_STACK_
#define _LINKED_STACK_


typedef struct StackNodeType
{
	struct AVLTreeNodeType* data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
#ifndef _AVL_TREE_
#define _AVL_TREE_

typedef struct AVLTreeType
{
	AVLTreeNode *pRootNode;
} AVLTree;

// 트리의 생성
AVLTree* createAVLTree();

// 트리의 삭제
void deleteAVLTree(AVLTree* pAVLTree);

// 트리 노드의 삭제(재귀적)
void deleteAVLTreeNode(AVLTreeNode* pAVLTreeNode);

// 새로운 노드 삽입.
int insertNodeAVL(AVLTree* pAVLTree, AVLTreeNodeData data);

// 기존 노드 삭제.
int deleteNodeAVL(AVLTree* pAVLTree, int key);

// 균형 잡기.
void balanceAVLTree(AVLTree* pAVLTree, LinkedStack* pStack);

int pushAVLTreeNode(LinkedStack* pStack, AVLTreeNode* data);

AVLTreeNode *popAVLTreeNode(LinkedStack* pStack);

AVLTreeNode *peekAVLTreeNode(LinkedStack* pStack);

// 균형 잡기: LL 회전
AVLTreeNode* rotateLLAVLTree(AVLTreeNode *pParentNode);

// 균형 잡기: LR 회전
AVLTreeNode* rotateLRAVLTree(AVLTreeNode *pParentNode);

// 균형 잡기: RR 회전
AVLTreeNode* rotateRRAVLTree(AVLTreeNode *pParentNode);

// 균형 잡기: RL 회전
AVLTreeNode* rotateRLAVLTree(AVLTreeNode *pParentNode);

// 높이, 균형 정보 변경.
void updateHeightAndBalanceAVL(AVLTreeNode* pNode);

// (반복적) 탐색.
AVLTreeNode* searchAVL(AVLTree* pAVLTree, int key);

void displayAVLTree(AVLTree *pTree);

void displayAVLTreeInternal(AVLTreeNode *pTreeNode, int level, char type);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif



/// OBFUSCATED BY OMNI OBFUSCATOR V1.2.1712.19, SEED VALUE: 744211151


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

static void omni_global_function( void *temp_142, void *temp_143, void *temp_144, void *temp_145, void *temp_146, void 
    *temp_147, void *temp_148, void *temp_149, void *temp_150, void *temp_151, void *temp_152, void *temp_153, void 
    *temp_154, void *temp_155, void *temp_156, void *temp_157, void *temp_158, void *temp_159, void *temp_160, void 
    *temp_161, void *temp_162, void *temp_163, void *temp_164, void *temp_165, void *temp_166, void *temp_167, void 
    *temp_168, void *temp_169, void *temp_170, void *temp_171, void *temp_172, void *temp_173, void *temp_174, void 
    *temp_175, void *temp_176, void *temp_177, void *temp_178, void *temp_179, void *temp_180, void *temp_181, void 
    *temp_182 ) OMNI_THROWS;



// Obfuscated function
OMNI_GLOBAL_SCOPE LinkedStack *createLinkedStack( void )
{
    bool temp_8;
    char const *temp_16 = "\xBF""\xC0""\xB7""\xF9"", \xB8""\xDE""\xB8""\xF0""\xB8""\xAE""\xC7""\xD2""\xB4""\xE7"",createLinkedStack()\n";
    bool temp_17;
    unsigned int temp_18;
    unsigned int temp_19;
    unsigned int temp_20;
    unsigned int temp_21;
    unsigned int temp_22;
    unsigned int temp_23;
    bool temp_24;
    bool temp_25;
    size_t temp_41;
    unsigned OMNI__INT64 temp_50;
    unsigned OMNI__INT64 temp_51;
    unsigned OMNI__INT64 temp_52;
    unsigned OMNI__INT64 temp_53;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_74;
    void *temp_75;
    int temp_76;
    unsigned OMNI__INT64 temp_77;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_78;
    void *temp_79;
    size_t temp_80;
    size_t temp_81;
    size_t temp_82;
    size_t temp_83;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_84;
    int temp_85;
    unsigned OMNI__INT64 temp_86;
    size_t temp_87;
    size_t temp_88;
    size_t temp_89;
    void *temp_90;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_91;
    bool state0_92;
    bool state1_93;
    bool state2_94;
    bool state3_95;
    bool state4_96;
    bool state5_97;
    bool state6_98;
    bool state7_99;
    unsigned int temp_100;
    void *temp_202;
    void *temp_203;
    void *temp_204;
    void *temp_205;
    void *temp_206;
    void *temp_207;
    void *temp_208;
    void *temp_209;
    void *temp_210;
    void *temp_211;
    void *temp_212;
    void *temp_213;
    void *temp_214;
    void *temp_215;
    void *temp_216;
    void *temp_217;
    void *temp_218;
    void *temp_219;
    void *temp_220;
    void *temp_221;
    void *temp_222;
    void *temp_223;
    void *temp_224;
    void *temp_225;
    void *temp_226;
    void *temp_227;
    void *temp_228;
    void *temp_229;
    void *temp_230;
    void *temp_231;
    void *temp_232;
    void *temp_233;
    void *temp_234;
    void *temp_235;
    void *temp_236;
    void *temp_237;
    void *temp_238;
    void *temp_239;
    void *temp_240;
    void *temp_241;
    void *temp_242;
    
    L319:
    L318:
    temp_100 = (unsigned int)1202u;
    temp_20 = (unsigned int)1439;
    temp_100 = temp_100 + temp_20;
    goto L322;
    
    L322:
    switch( temp_100)
    {
    case 2641u: goto L321;
    case 1897u: goto L321;
    default: goto L318;
    }
    
    L321:
    {
        
        L320:
        temp_242 = &temp_91;
        temp_241 = &temp_90;
        temp_240 = &temp_89;
        temp_239 = &temp_88;
        temp_238 = &temp_87;
        temp_237 = &temp_86;
        temp_236 = &temp_85;
        temp_235 = &temp_84;
        temp_234 = &temp_83;
        temp_233 = &temp_82;
        temp_232 = &temp_81;
        temp_231 = &temp_80;
        temp_230 = &temp_79;
        temp_229 = &temp_78;
        temp_228 = &temp_77;
        temp_227 = &temp_76;
        temp_226 = &temp_75;
        temp_225 = &temp_74;
        temp_224 = &temp_53;
        temp_223 = &temp_52;
        temp_222 = &temp_51;
        temp_221 = &temp_50;
        temp_220 = &temp_41;
        temp_219 = &temp_25;
        temp_218 = &temp_24;
        temp_217 = &temp_23;
        temp_216 = &temp_22;
        temp_215 = &temp_21;
        temp_214 = &temp_19;
        temp_213 = &temp_18;
        temp_212 = &temp_16;
        temp_211 = &temp_8;
        temp_210 = &state7_99;
        temp_209 = &state6_98;
        temp_208 = &state5_97;
        temp_207 = &state4_96;
        temp_206 = &state3_95;
        temp_205 = &state2_94;
        temp_204 = &state1_93;
        temp_203 = &state0_92;
        temp_202 = &temp_100;
        omni_global_function( ( void * )temp_202, ( void * )temp_203, ( void * )temp_204, ( void * )temp_205, ( void * )temp_206, 
            ( void * )temp_207, ( void * )temp_208, ( void * )temp_209, ( void * )temp_210, ( void * )temp_211, 
            ( void * )temp_212, ( void * )temp_213, ( void * )temp_214, ( void * )temp_215, ( void * )temp_216, 
            ( void * )temp_217, ( void * )temp_218, ( void * )temp_219, ( void * )temp_220, ( void * )temp_221, 
            ( void * )temp_222, ( void * )temp_223, ( void * )temp_224, ( void * )temp_225, ( void * )temp_226, 
            ( void * )temp_227, ( void * )temp_228, ( void * )temp_229, ( void * )temp_230, ( void * )temp_231, 
            ( void * )temp_232, ( void * )temp_233, ( void * )temp_234, ( void * )temp_235, ( void * )temp_236, 
            ( void * )temp_237, ( void * )temp_238, ( void * )temp_239, ( void * )temp_240, ( void * )temp_241, 
            ( void * )temp_242 );
        goto L326;
        
        L326:
        switch( temp_100)
        {
        case 108u: goto L328;
        case 3507u: goto L328;
        case 2188u: goto L328;
        case 2622u: goto L336;
        case 705u: goto L340;
        default: goto L332;
        }
        
        L328:
        return temp_74;
        
        L332:
        return temp_74;
        
        L336:
        return temp_74;
        
        L340:
        return temp_74;
        
    }

}




int pushLS(LinkedStack* pStack, StackNode element)
{
	int ret = FALSE;
	StackNode *pNode = NULL;

	if (pStack != NULL) {
		pNode = (StackNode *)malloc(sizeof(StackNode));
		if (pNode != NULL) {
			memset(pNode, 0, sizeof(StackNode));
			*pNode = element;
			pNode->pLink = pStack->pTopElement;
			pStack->pTopElement = pNode;
			  
			pStack->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 메모리할당,pushLS()\n");
		}
	}

	return ret;
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode* pReturn = NULL;
	if (pStack != NULL)	{
		if (isLinkedStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;
			pStack->pTopElement = pReturn->pLink;
			pReturn->pLink = NULL;

			pStack->currentElementCount--;
		}
	}

	return pReturn;
}

StackNode* peekLS(LinkedStack* pStack)
{
	StackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isLinkedStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;
		}
	}

	return pReturn;
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode *pNode = NULL;
	StackNode *pDelNode = NULL;

	if (pStack != NULL) {
		pNode = pStack->pTopElement;
		while(pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		free(pStack);
	}	
}

int isLinkedStackFull(LinkedStack* pStack)
{
	int ret = FALSE;
	return ret;
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}

// 트리의 생성
AVLTree* createAVLTree()
{
	AVLTree *pReturn = NULL;

	pReturn = (AVLTree *)malloc(sizeof(AVLTree));
	if (pReturn != NULL) {	// 메모리 할당 성공 검증
		// 데이터 초기화.
		memset(pReturn, 0, sizeof(AVLTree));
	}
	else {
		printf("오류, malloc() in createAVLTree()\n");
		return NULL;
	}

	return pReturn;
}

// (반복적) 탐색.
AVLTreeNode* searchAVL(AVLTree* pAVLTree, int key)
{
	AVLTreeNode* pReturn = NULL;
	AVLTreeNode* pNode = NULL;

	if (pAVLTree == NULL) {
		return NULL;
	}

	pNode = pAVLTree->pRootNode;
	if (pNode == NULL) {
		return NULL;
	}

	while(pNode != NULL) {
		if (key == pNode->data.key) {
			pReturn = pNode;
			break;
		}
		else if (key < pNode->data.key) {
			pNode = pNode->pLeftChild;
		}
		else {
			pNode = pNode->pRightChild;
		}
	}

	return pReturn;
}

// 새로운 노드 삽입.
int insertNodeAVL(AVLTree* pAVLTree, AVLTreeNodeData element)
{
	int ret = TRUE;
	AVLTreeNode* pParentNode = NULL;
	AVLTreeNode* pNewNode = NULL;
	LinkedStack* pStack = NULL;

	if (pAVLTree == NULL) {
		ret = FALSE;
		return ret;
	}

	pStack = createLinkedStack();
	if (pStack == NULL) {
		ret = FALSE;
		return ret;
	}

	pParentNode = pAVLTree->pRootNode;
	while(pParentNode != NULL) {
		pushAVLTreeNode(pStack, pParentNode);

		if (element.key == pParentNode->data.key) {
			printf("오류, 중복된 키[%d]가 존재합니다,insertNodeAVL()\n", element.key);
			ret = FALSE;
			return ret;
		}
		else if (element.key < pParentNode->data.key) {
			if (pParentNode->pLeftChild == NULL) {
				break;
			}
			else {
				pParentNode = pParentNode->pLeftChild;
			}
		}
		else {
			if (pParentNode->pRightChild == NULL) {
				break;
			}
			else {
				pParentNode = pParentNode->pRightChild;
			}
		}
	}

	pNewNode = (AVLTreeNode *)malloc(sizeof(AVLTreeNode));
	if (pNewNode != NULL) {	// 메모리 할당 성공 검증
		// 데이터 초기화.
		memset(pNewNode, 0, sizeof(AVLTreeNode));
		pNewNode->data = element;
		pNewNode->height = 1;
	}
	else {
		printf("오류, malloc() in insertNodeAVL()\n");
		deleteLinkedStack(pStack);
		return FALSE;
	}

	if (pParentNode == NULL) {
		pAVLTree->pRootNode = pNewNode;
	}
	else {
		if (pNewNode->data.key < pParentNode->data.key) {
			pParentNode->pLeftChild = pNewNode;
		}
		else {
			pParentNode->pRightChild = pNewNode;
		}
	}
	ret = TRUE;

	balanceAVLTree(pAVLTree, pStack);

	deleteLinkedStack(pStack);

	return ret;
}

// 균형 잡기.
void balanceAVLTree(AVLTree* pAVLTree, LinkedStack* pStack)
{
	AVLTreeNode *pParentNode = NULL;
	AVLTreeNode *pNode = NULL;
	AVLTreeNode *pChildNode = NULL;
	AVLTreeNode *pNewNode = NULL;

	if (pAVLTree == NULL || pStack == NULL) {
		return;
	}

	while(isLinkedStackEmpty(pStack) == FALSE) {
		pNode = popAVLTreeNode(pStack);
		if (pNode != NULL) {
			updateHeightAndBalanceAVL(pNode);

			if (pNode->balance >= -1 && pNode->balance <= 1) {
				continue;			
			}

			if (pNode->balance > 1) {
				pChildNode = pNode->pLeftChild;
				if (pChildNode->balance > 0) {
					pNewNode = rotateLLAVLTree(pNode);
				}
				else {
					pNewNode = rotateLRAVLTree(pNode);
				}
			}
			else if (pNode->balance < -1) {
				pChildNode = pNode->pRightChild;
				if (pChildNode->balance < 0) {
					pNewNode = rotateRRAVLTree(pNode);
				}
				else {
					pNewNode = rotateRLAVLTree(pNode);
				}
			}

			pParentNode = peekAVLTreeNode(pStack);
			if (pParentNode != NULL) {
				if (pParentNode->pLeftChild == pNode) {
					pParentNode->pLeftChild = pNewNode;
				}
				else {
					pParentNode->pRightChild = pNewNode;
				}
			}
			else {
				pAVLTree->pRootNode = pNewNode;
			}
		}
	}
}

int pushAVLTreeNode(LinkedStack* pStack, AVLTreeNode* data)
{
	StackNode node = {0,};
	node.data = data;

	return pushLS(pStack, node);
}

AVLTreeNode *popAVLTreeNode(LinkedStack* pStack)
{
	AVLTreeNode *pReturn = NULL;

	if (isLinkedStackEmpty(pStack) == FALSE) {
		StackNode* pNode = popLS(pStack);
		if (pNode != NULL) {
			pReturn = pNode->data;

			free(pNode);
		}
	}

	return pReturn;
}

AVLTreeNode *peekAVLTreeNode(LinkedStack* pStack)
{
	AVLTreeNode *pReturn = NULL;

	if (isLinkedStackEmpty(pStack) == FALSE) {
		StackNode* pNode = peekLS(pStack);
		if (pNode != NULL) {
			pReturn = pNode->data;
		}
	}

	return pReturn;
}

// 균형 잡기: LL 회전
AVLTreeNode* rotateLLAVLTree(AVLTreeNode *pParentNode)
{
	AVLTreeNode *pLeftNode = NULL;

	if (pParentNode != NULL) {
		pLeftNode = pParentNode->pLeftChild;
		pParentNode->pLeftChild = pLeftNode->pRightChild;
		pLeftNode->pRightChild = pParentNode;

		updateHeightAndBalanceAVL(pParentNode);
		updateHeightAndBalanceAVL(pLeftNode);
	}

	return pLeftNode;
}

// 균형 잡기: RR 회전
AVLTreeNode* rotateRRAVLTree(AVLTreeNode *pParentNode)
{
	AVLTreeNode *pRightNode = NULL;

	if (pParentNode != NULL) {
		pRightNode = pParentNode->pRightChild;
		pParentNode->pRightChild = pRightNode->pLeftChild;
		pRightNode->pLeftChild = pParentNode;

		updateHeightAndBalanceAVL(pParentNode);
		updateHeightAndBalanceAVL(pRightNode);
	}

	return pRightNode;
}

// 균형 잡기: LR 회전
AVLTreeNode* rotateLRAVLTree(AVLTreeNode *pParentNode)
{
	AVLTreeNode *pReturn = NULL;
	AVLTreeNode *pLeftNode = NULL;

	if (pParentNode != NULL) {
		pLeftNode = pParentNode->pLeftChild;
		pParentNode->pLeftChild = rotateRRAVLTree(pLeftNode);

		pReturn = rotateLLAVLTree(pParentNode);
	}

	return pReturn;
}

// 균형 잡기: RL 회전
AVLTreeNode* rotateRLAVLTree(AVLTreeNode *pParentNode)
{
	AVLTreeNode *pReturn = NULL;
	AVLTreeNode *pRightNode = NULL;

	if (pParentNode != NULL) {
		pRightNode = pParentNode->pRightChild;
		pParentNode->pRightChild = rotateLLAVLTree(pRightNode);
		pReturn = rotateRRAVLTree(pParentNode);
	}

	return pReturn;
}

// 높이 및 균형 인수 정보 변경.
void updateHeightAndBalanceAVL(AVLTreeNode *pNode)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (pNode != NULL) {
		if (pNode->pLeftChild != NULL) {
			
			leftHeight = pNode->pLeftChild->height;
		}

		if (pNode->pRightChild != NULL) {
			
			rightHeight = pNode->pRightChild->height;
		}

		if (leftHeight > rightHeight) {
			pNode->height = leftHeight + 1;
		}
		else {
			pNode->height = rightHeight + 1;
		}

		pNode->balance = leftHeight - rightHeight;
	}
}

// 기존 노드 삭제.
int deleteNodeAVL(AVLTree* pAVLTree, int key)
{
	int ret = TRUE;
	AVLTreeNode* pDelNode = NULL;
	AVLTreeNode* pParentNode = NULL;

	AVLTreeNode* pPredecessor = NULL;
	AVLTreeNode* pSuccessor = NULL;

	AVLTreeNode* pChild = NULL;
	LinkedStack* pStackMain = NULL;
	LinkedStack* pStackSub = NULL;

	if (pAVLTree == NULL) {
		ret = FALSE;
		return ret;
	}

	pStackMain = createLinkedStack();
	pStackSub = createLinkedStack();
	if (pStackMain == NULL || pStackSub == NULL) {
		ret = FALSE;
		return ret;
	}

	pParentNode = NULL;
	pDelNode = pAVLTree->pRootNode;
	while(pDelNode != NULL) {
		if (key == pDelNode->data.key) {
			break;
		}
		pParentNode = pDelNode;
		pushAVLTreeNode(pStackMain, pParentNode);

		if (key < pDelNode->data.key) {
			pDelNode = pDelNode->pLeftChild;
		}
		else {
			pDelNode = pDelNode->pRightChild;
		}
	}
	if (pDelNode == NULL) {
		printf("오류,검색 키[%d]인 자료가 없습니다,deleteNodeAVL()\n", key);
		ret = FALSE;
		return ret;
	}

	if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = NULL;
			}
			else {
				pParentNode->pRightChild = NULL;
			}
		}
		else {
			pAVLTree->pRootNode = NULL;
		}
	}
	else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
		pPredecessor = NULL;
		pSuccessor = pDelNode->pLeftChild;
		pushAVLTreeNode(pStackSub, pSuccessor);

		while(pSuccessor->pRightChild != NULL) {
			pPredecessor = pSuccessor;

			pSuccessor = pSuccessor->pRightChild;
			pushAVLTreeNode(pStackSub, pSuccessor);
		}
		pushAVLTreeNode(pStackMain, popAVLTreeNode(pStackSub));

		if (pPredecessor != NULL) {
			pPredecessor->pRightChild = pSuccessor->pLeftChild;
			pSuccessor->pLeftChild = pDelNode->pLeftChild;

			pushAVLTreeNode(pStackSub, pPredecessor->pRightChild);
		}
		pSuccessor->pRightChild = pDelNode->pRightChild;

		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = pSuccessor;
			}
			else {
				pParentNode->pRightChild = pSuccessor;
			}
		}
		else {
			pAVLTree->pRootNode = pSuccessor;
		}
	}
	else {
		if (pDelNode->pLeftChild != NULL) {
			pChild = pDelNode->pLeftChild;
		}
		else {
			pChild = pDelNode->pRightChild;
		}

		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = pChild;
			}
			else {
				pParentNode->pRightChild = pChild;
			}
		}
		else {
			pAVLTree->pRootNode = pChild;
		}
	}
	free( pDelNode );

	balanceAVLTree(pAVLTree, pStackSub);
	balanceAVLTree(pAVLTree, pStackMain);

	deleteLinkedStack(pStackMain);
	deleteLinkedStack(pStackSub);

	return ret;
}

// 트리의 삭제
void deleteAVLTree(AVLTree* pAVLTree)
{
	if (pAVLTree != NULL) {
		deleteAVLTreeNode(pAVLTree->pRootNode);
		free(pAVLTree);
	}
}

// 트리 노드의 삭제(재귀적)
void deleteAVLTreeNode(AVLTreeNode* pAVLTreeNode)
{
	if (pAVLTreeNode != NULL) {
		deleteAVLTreeNode(pAVLTreeNode->pLeftChild);
		deleteAVLTreeNode(pAVLTreeNode->pRightChild);
		free(pAVLTreeNode);
	}
}

void displayAVLTree(AVLTree *pTree)
{
	displayAVLTreeInternal(pTree->pRootNode, 0, ' ');
}

void displayAVLTreeInternal(AVLTreeNode *pTreeNode, int level, char type)
{
    int i = 0;
	for (i = 0; i < level ; i++) {
		printf("    ");
	}

	if (pTreeNode != NULL) {
		printf("-[%i,%i,%c],%i-%s\n", pTreeNode->height, pTreeNode->balance, type, 
			pTreeNode->data.key, pTreeNode->data.value);

		displayAVLTreeInternal(pTreeNode->pLeftChild, level + 1, 'L');
		displayAVLTreeInternal(pTreeNode->pRightChild, level + 1, 'R');
	}
	else {
		printf("NULL\n");
	}
}

int main(int argc, char *argv[])
{
	AVLTree *pTree = NULL;
	AVLTreeNode *pSearch = NULL;
	int key = 0;

	AVLTreeNodeData eB = {9, "키 값이 9"};
	AVLTreeNodeData eG = {3, "키 값이 3"};
	AVLTreeNodeData eE = {1, "키 값이 1"};
	AVLTreeNodeData eC = {10, "키 값이 10"};
	AVLTreeNodeData eL = {12, "키 값이 12"};
	AVLTreeNodeData eH = {6, "키 값이 6"};
	AVLTreeNodeData eI = {4, "키 값이 4"};
	AVLTreeNodeData eF = {5, "키 값이 5"};

	pTree = createAVLTree();
	if (pTree != NULL) 
	{
		printf("1)\n");
		insertNodeAVL(pTree, eB);
		displayAVLTree(pTree);

		printf("\n2)\n");
		insertNodeAVL(pTree, eG);
		displayAVLTree(pTree);
		
		printf("\n3) LL 회전 발생\n");
		insertNodeAVL(pTree, eE);
		displayAVLTree(pTree);
		
		printf("\n4)\n");
		insertNodeAVL(pTree, eC);
		displayAVLTree(pTree);
		
		printf("\n5) RR 회전 발생\n");
		insertNodeAVL(pTree, eL);
		displayAVLTree(pTree);
		
		printf("\n6) RL 회전 발생\n");
		insertNodeAVL(pTree, eH);
		displayAVLTree(pTree);
		
		printf("\n7)\n");
		insertNodeAVL(pTree, eI);
		displayAVLTree(pTree);
		
		printf("\n8) LR 회전 발생\n");
		insertNodeAVL(pTree, eF);
		displayAVLTree(pTree);

		deleteAVLTree(pTree);
	}

	return 0;
}


// Obfuscator generated function
static void omni_global_function( void *temp_142, void *temp_143, void *temp_144, void *temp_145, void *temp_146, void 
    *temp_147, void *temp_148, void *temp_149, void *temp_150, void *temp_151, void *temp_152, void *temp_153, void 
    *temp_154, void *temp_155, void *temp_156, void *temp_157, void *temp_158, void *temp_159, void *temp_160, void 
    *temp_161, void *temp_162, void *temp_163, void *temp_164, void *temp_165, void *temp_166, void *temp_167, void 
    *temp_168, void *temp_169, void *temp_170, void *temp_171, void *temp_172, void *temp_173, void *temp_174, void 
    *temp_175, void *temp_176, void *temp_177, void *temp_178, void *temp_179, void *temp_180, void *temp_181, void 
    *temp_182 ) OMNI_THROWS
{
    unsigned int temp_101;
    bool temp_102;
    bool temp_103;
    bool temp_104;
    bool temp_105;
    bool temp_106;
    bool temp_107;
    bool temp_108;
    bool temp_109;
    bool temp_110;
    char const *temp_111;
    unsigned int temp_112;
    unsigned int temp_113;
    unsigned int temp_114;
    unsigned int temp_115;
    unsigned int temp_116;
    bool temp_117;
    bool temp_118;
    size_t temp_119;
    unsigned OMNI__INT64 temp_120;
    unsigned OMNI__INT64 temp_121;
    unsigned OMNI__INT64 temp_122;
    unsigned OMNI__INT64 temp_123;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_124;
    void *temp_125;
    int temp_126;
    unsigned OMNI__INT64 temp_127;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_128;
    void *temp_129;
    size_t temp_130;
    size_t temp_131;
    size_t temp_132;
    size_t temp_133;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_134;
    int temp_135;
    unsigned OMNI__INT64 temp_136;
    size_t temp_137;
    size_t temp_138;
    size_t temp_139;
    void *temp_140;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_141;
    bool temp_193;
    unsigned int temp_194;
    unsigned int temp_195;
    unsigned int temp_196;
    unsigned int temp_197;
    unsigned int temp_198;
    unsigned int temp_199;
    bool temp_200;
    bool temp_201;
    unsigned int *temp_183;
    unsigned char *temp_184;
    unsigned char temp_185;
    unsigned char temp_186;
    char const **temp_187;
    size_t *temp_188;
    unsigned OMNI__INT64 *temp_189;
    OMNI_GLOBAL_SCOPE LinkedStack **temp_190;
    void **temp_191;
    int *temp_192;
    void *temp_243[120];
    void **temp_244;
    size_t temp_245;
    void *temp_246;
    unsigned int temp_247;
    unsigned int temp_248;
    unsigned int temp_249;
    void *temp_250;
    bool temp_251;
    static unsigned int omni_virtualcode_252[560] = { 2045170935u, 2448352743u, 3088583468u, 3508683748u, 2696196430u, 2086728264u, 3084180447u, 3990893547u, 831403051u, 
        2481936598u, 3161195857u, 603498980u, 597276863u, 1162926449u, 2002417798u, 2931027641u, 2998800991u, 3817701397u, 
        143229040u, 943395513u, 1149863877u, 1832666689u, 2750062619u, 477407754u, 1200444472u, 750888794u, 263121700u, 
        1922164419u, 102962302u, 3965146671u, 63469366u, 1319871070u, 2610326422u, 2437987914u, 1758967768u, 644181163u, 
        2887821289u, 633740139u, 1063083250u, 1511123174u, 1053467284u, 1745053937u, 4144947210u, 1471960655u, 483721491u, 
        1269671579u, 1290297625u, 1386708450u, 723989397u, 3110719873u, 2862375298u, 1411520326u, 2281116871u, 1302288916u, 
        479027397u, 583915936u, 333327891u, 2335885784u, 3780193615u, 929633972u, 4048974203u, 2846591904u, 2578016163u, 
        777441371u, 1847445103u, 3440503056u, 2173009551u, 3322761082u, 224572999u, 331156279u, 4180515599u, 953474297u, 
        2864068652u, 2103262485u, 3784786986u, 3492422984u, 4245358630u, 220499564u, 1833447527u, 3089367254u, 1893658848u, 
        4191908103u, 20065385u, 874860938u, 2890272639u, 485085438u, 1270531465u, 2199961559u, 2118531179u, 1309855526u, 
        3732287398u, 2974308180u, 817834506u, 2938754533u, 1154879038u, 3024735004u, 3076929218u, 1477327460u, 2606516849u, 
        588556468u, 3578268039u, 1350539895u, 4188873475u, 1154567050u, 2004149152u, 1049759658u, 835395585u, 1167048380u, 
        4039031905u, 1409720593u, 2481190799u, 1680912674u, 2090521544u, 559252577u, 1221924146u, 1382740232u, 3416921555u, 
        2456099069u, 987523322u, 2972571169u, 521295290u, 298581592u, 3612956777u, 720230155u, 329294369u, 140810662u, 
        1463523138u, 3366450203u, 2103529454u, 508398174u, 867046796u, 3516362983u, 2040720198u, 1038332212u, 606012554u, 
        3493513796u, 1592740237u, 2395221788u, 607966659u, 2387526725u, 3323361641u, 2060150092u, 1810970875u, 332357441u, 
        2317667262u, 2853631289u, 1919622968u, 2835078349u, 3261452978u, 117620632u, 4061641405u, 3612327101u, 3362283178u, 
        3123504222u, 3835919120u, 1753726758u, 905478218u, 745653952u, 2197492471u, 1705043806u, 3793979768u, 116262195u, 
        1129083254u, 383284729u, 3879078745u, 822116972u, 3791899090u, 95218380u, 2663241041u, 3578027871u, 1473153680u, 
        4208461805u, 2693200134u, 1570307139u, 3701040757u, 4267298224u, 3315517789u, 1897396875u, 3901836678u, 1533901995u, 
        659739770u, 4179573741u, 908357896u, 2593232562u, 523169219u, 541974366u, 3204334465u, 2206325978u, 1157702621u, 
        1300186899u, 3104601013u, 523980665u, 1943456172u, 735057281u, 2692477609u, 3103469603u, 3271257942u, 2711497053u, 
        767095714u, 3594518446u, 2348607039u, 3666257051u, 1483858981u, 1136885550u, 1722236685u, 1030154354u, 1519548919u, 
        126201848u, 755682213u, 1952027989u, 2890506526u, 1824641442u, 4168031019u, 1757252859u, 117542365u, 4210320896u, 
        577110021u, 1127280471u, 1701425083u, 2061315624u, 1119521752u, 1821187743u, 4268603516u, 4134939758u, 830082696u, 
        2381494856u, 1262196773u, 3086983015u, 183572539u, 2411570439u, 87982587u, 1173490153u, 615283798u, 2609512401u, 
        623240323u, 1762601736u, 427444605u, 439691738u, 3856494978u, 760284697u, 3261518486u, 3051144601u, 3180403198u, 
        3656768434u, 935241669u, 1440592833u, 1722814011u, 4151913127u, 3524237681u, 584258633u, 3655778750u, 1335473678u, 
        723892540u, 2275232100u, 1327555404u, 3931340347u, 487479310u, 743896200u, 1116496874u, 316916931u, 3206022922u, 
        4183684714u, 1788245469u, 1355221116u, 1808635798u, 424505087u, 3236661418u, 1824263546u, 3120372054u, 4094017404u, 
        2105036311u, 1874776595u, 2209603120u, 849381717u, 443266856u, 2735381211u, 3795679304u, 3195907649u, 1362097441u, 
        2434720935u, 791197189u, 3208138291u, 443840649u, 12022413u, 37858058u, 2678966882u, 2921656868u, 4241573089u, 
        898934332u, 150717249u, 2255377400u, 3416890681u, 3782228673u, 3783072646u, 1539231304u, 4173200489u, 1583364094u, 
        1423110694u, 667013531u, 1288316038u, 1177661080u, 3419843158u, 576983220u, 3486258406u, 1928523635u, 3987071883u, 
        3319101850u, 3405778461u, 4226715061u, 2761850489u, 3380625553u, 3353711105u, 968055234u, 425565463u, 672322590u, 
        2402640805u, 3322831424u, 3049234328u, 427419142u, 720339041u, 2064382484u, 568338547u, 400648271u, 3780127687u, 
        1895412322u, 1176442459u, 3669461820u, 1054139822u, 4284701840u, 1293454406u, 1537785940u, 154758955u, 3239446338u, 
        2661870185u, 3567433307u, 1283181202u, 2384528991u, 3840725305u, 3167773014u, 1339570040u, 2161109002u, 121643883u, 
        3466784906u, 2613851827u, 4038033576u, 809697524u, 46323068u, 4195715415u, 2005655263u, 3352414728u, 2451554545u, 
        1974415801u, 3983758228u, 1996955934u, 4125467631u, 1423470447u, 4278540207u, 1451917573u, 1974427831u, 592996268u, 
        3544884098u, 242053343u, 4218349475u, 3322252683u, 2750513487u, 2938463406u, 520451697u, 2379743038u, 2684235473u, 
        1766174467u, 3157732542u, 476779248u, 1185504586u, 3175939975u, 1037924824u, 545853009u, 4155702849u, 3426620966u, 
        1308337299u, 3774517240u, 2379742990u, 2684235470u, 1766171624u, 1137237371u, 476779225u, 462424358u, 817633354u, 
        2815035736u, 271190580u, 1058109705u, 1747156258u, 3329257337u, 2975956636u, 2053190170u, 122976754u, 90594199u, 
        713032725u, 141621066u, 467689409u, 1864010942u, 3686655062u, 2851914533u, 964632479u, 1984075177u, 2990727739u, 
        1204849985u, 369016494u, 3865709149u, 297449867u, 2398318131u, 1610335544u, 267792540u, 1447496254u, 206454256u, 
        3390325524u, 2152437517u, 348201546u, 1076811370u, 3557073618u, 231664u, 1930764831u, 3684792987u, 3935508578u, 
        3887049170u, 1336658346u, 2206968427u, 220999717u, 4273946133u, 1314208036u, 2632793347u, 3938706570u, 2997705485u, 
        1824484871u, 3725325326u, 339872089u, 2997019999u, 3322755283u, 2155966821u, 431655664u, 2567625642u, 3078059770u, 
        1029785820u, 2791051453u, 1227035626u, 3167028996u, 3729696610u, 179747174u, 2697677818u, 3508340787u, 1401632578u, 
        3206198421u, 590739796u, 2012941815u, 3020467426u, 234370945u, 4139562805u, 1162852998u, 2847668034u, 3249583913u, 
        1019338780u, 3982999964u, 475265215u, 2969719066u, 1556581297u, 2295268343u, 2812321872u, 2852656299u, 2834185171u, 
        2983161545u, 3846433439u, 3406699101u, 91349958u, 3614709676u, 1737326731u, 4162507445u, 1519611989u, 705896554u, 
        3837219634u, 1816530276u, 2956064962u, 2623842619u, 2677435536u, 2928203616u, 1938472673u, 102394977u, 1622077440u, 
        4013880851u, 1014401663u, 4077351884u, 2962436942u, 2028944250u, 2198122078u, 4002334979u, 3923177043u, 4077869u, 
        4261492404u, 3022928756u, 3376307627u, 80483778u, 3734009883u, 3879171078u, 2431912964u, 3957491314u, 2876633069u, 
        758406208u, 2488267285u, 238607280u, 2254287072u, 2964395884u, 3312211174u, 1858079751u, 1858213624u, 1748141992u, 
        3155400357u, 1551748515u, 3139372992u, 2254903426u, 2401199079u, 2030120788u, 387417776u, 2117282076u, 4280771750u, 
        3511759830u, 3796853009u, 3859209291u, 4227043270u, 725566477u, 1676734438u, 1235720198u, 1293215031u, 246060413u, 
        3810806956u, 909761160u, 3195938479u, 574280796u, 2195069752u, 1065143038u, 1439970675u, 2379668195u, 457298626u, 
        3191813560u, 3452297681u, 3662509803u, 1178626880u, 681619548u, 4187638025u, 4280853322u, 604171504u, 1884287715u, 
        1916289536u, 3019192568u, 1866279637u, 3455047858u, 2114947683u, 3801941615u, 1986292975u, 3508655061u, 3706320292u, 
        2411503690u, 225336564u };
    unsigned int temp_253;
    unsigned int temp_254;
    unsigned int temp_255;
    size_t temp_256;
    size_t *temp_257;
    void *temp_258;
    void **temp_259;
    bool temp_260;
    bool *temp_261;
    bool temp_262;
    bool *temp_263;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_264;
    OMNI_GLOBAL_SCOPE LinkedStack **temp_265;
    bool temp_266;
    bool *temp_267;
    unsigned OMNI__INT64 temp_268;
    unsigned OMNI__INT64 *temp_269;
    size_t temp_270;
    size_t *temp_271;
    size_t temp_272;
    size_t *temp_273;
    size_t temp_274;
    size_t *temp_275;
    int temp_276;
    int *temp_277;
    int temp_278;
    int *temp_279;
    unsigned OMNI__INT64 temp_280;
    unsigned OMNI__INT64 *temp_281;
    unsigned int temp_282;
    unsigned int *temp_283;
    unsigned int temp_284;
    unsigned int *temp_285;
    unsigned OMNI__INT64 temp_286;
    unsigned OMNI__INT64 *temp_287;
    OMNI_GLOBAL_SCOPE LinkedStack *temp_288;
    OMNI_GLOBAL_SCOPE LinkedStack **temp_289;
    
    L347:
    L346:
    temp_101 = (unsigned int)344u;
    temp_183 = ( unsigned int * )(temp_142);
    temp_101 = *temp_183;
    temp_184 = ( unsigned char * )(temp_143);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_102 = temp_185 > temp_186;
    temp_184 = ( unsigned char * )(temp_144);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_103 = temp_185 > temp_186;
    temp_184 = ( unsigned char * )(temp_145);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_104 = temp_185 > temp_186;
    temp_184 = ( unsigned char * )(temp_146);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_105 = temp_185 > temp_186;
    temp_184 = ( unsigned char * )(temp_147);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_106 = temp_185 > temp_186;
    temp_184 = ( unsigned char * )(temp_148);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_107 = temp_185 > temp_186;
    temp_184 = ( unsigned char * )(temp_149);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_108 = temp_185 > temp_186;
    temp_184 = ( unsigned char * )(temp_150);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_109 = temp_185 > temp_186;
    temp_184 = ( unsigned char * )(temp_151);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_110 = temp_185 > temp_186;
    temp_187 = ( char const ** )(temp_152);
    temp_111 = *temp_187;
    temp_183 = ( unsigned int * )(temp_153);
    temp_112 = *temp_183;
    temp_183 = ( unsigned int * )(temp_154);
    temp_113 = *temp_183;
    temp_183 = ( unsigned int * )(temp_155);
    temp_114 = *temp_183;
    temp_183 = ( unsigned int * )(temp_156);
    temp_115 = *temp_183;
    temp_183 = ( unsigned int * )(temp_157);
    temp_116 = *temp_183;
    temp_184 = ( unsigned char * )(temp_158);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_117 = temp_185 > temp_186;
    temp_184 = ( unsigned char * )(temp_159);
    temp_185 = *temp_184;
    temp_186 = (unsigned char)0u;
    temp_118 = temp_185 > temp_186;
    temp_188 = ( size_t * )(temp_160);
    temp_119 = *temp_188;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_161);
    temp_120 = *temp_189;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_162);
    temp_121 = *temp_189;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_163);
    temp_122 = *temp_189;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_164);
    temp_123 = *temp_189;
    temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_165);
    temp_124 = *temp_190;
    temp_191 = ( void ** )(temp_166);
    temp_125 = *temp_191;
    temp_192 = ( int * )(temp_167);
    temp_126 = *temp_192;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_168);
    temp_127 = *temp_189;
    temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_169);
    temp_128 = *temp_190;
    temp_191 = ( void ** )(temp_170);
    temp_129 = *temp_191;
    temp_188 = ( size_t * )(temp_171);
    temp_130 = *temp_188;
    temp_188 = ( size_t * )(temp_172);
    temp_131 = *temp_188;
    temp_188 = ( size_t * )(temp_173);
    temp_132 = *temp_188;
    temp_188 = ( size_t * )(temp_174);
    temp_133 = *temp_188;
    temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_175);
    temp_134 = *temp_190;
    temp_192 = ( int * )(temp_176);
    temp_135 = *temp_192;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_177);
    temp_136 = *temp_189;
    temp_188 = ( size_t * )(temp_178);
    temp_137 = *temp_188;
    temp_188 = ( size_t * )(temp_179);
    temp_138 = *temp_188;
    temp_188 = ( size_t * )(temp_180);
    temp_139 = *temp_188;
    temp_191 = ( void ** )(temp_181);
    temp_140 = *temp_191;
    temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_182);
    temp_141 = *temp_190;
    temp_197 = (unsigned int)0u;
    temp_198 = (unsigned int)0u;
    temp_199 = (unsigned int)0u;
    temp_200 = (bool)0u;
    temp_201 = (bool)0u;
    temp_244 = ( void ** )(temp_243);
    temp_245 = (size_t)1u;
    temp_246 = &temp_101;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_102;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_103;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_104;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_105;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_106;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_107;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_108;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_109;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_110;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_111;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_112;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_113;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_114;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_115;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_116;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_117;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_118;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_119;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_120;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_121;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_122;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_123;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_124;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_125;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_126;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_127;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_128;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_129;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_130;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_131;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_132;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_133;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_134;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_135;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_136;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_137;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_138;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_139;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_140;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_141;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_193;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_194;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_195;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_196;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_197;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_198;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_199;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_200;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_201;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_183;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_184;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_185;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_186;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_187;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_188;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_189;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_190;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_191;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_192;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_142;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_143;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_144;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_145;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_146;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_147;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_148;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_149;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_150;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_151;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_152;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_153;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_154;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_155;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_156;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_157;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_158;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_159;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_160;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_161;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_162;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_163;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_164;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_165;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_166;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_167;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_168;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_169;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_170;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_171;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_172;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_173;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_174;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_175;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_176;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_177;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_178;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_179;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_180;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_181;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_246 = &temp_182;
    *temp_244 = temp_246;
    temp_244 = temp_244 + temp_245;
    temp_247 = (unsigned int)1u;
    goto L345;
    
    L348:
    temp_183 = ( unsigned int * )(temp_142);
    *temp_183 = temp_101;
    temp_184 = ( unsigned char * )(temp_143);
    *temp_184 = temp_102;
    temp_184 = ( unsigned char * )(temp_144);
    *temp_184 = temp_103;
    temp_184 = ( unsigned char * )(temp_145);
    *temp_184 = temp_104;
    temp_184 = ( unsigned char * )(temp_146);
    *temp_184 = temp_105;
    temp_184 = ( unsigned char * )(temp_147);
    *temp_184 = temp_106;
    temp_184 = ( unsigned char * )(temp_148);
    *temp_184 = temp_107;
    temp_184 = ( unsigned char * )(temp_149);
    *temp_184 = temp_108;
    temp_184 = ( unsigned char * )(temp_150);
    *temp_184 = temp_109;
    temp_184 = ( unsigned char * )(temp_151);
    *temp_184 = temp_110;
    temp_183 = ( unsigned int * )(temp_153);
    *temp_183 = temp_112;
    temp_183 = ( unsigned int * )(temp_154);
    *temp_183 = temp_113;
    temp_183 = ( unsigned int * )(temp_155);
    *temp_183 = temp_114;
    temp_183 = ( unsigned int * )(temp_156);
    *temp_183 = temp_115;
    temp_183 = ( unsigned int * )(temp_157);
    *temp_183 = temp_116;
    temp_184 = ( unsigned char * )(temp_158);
    *temp_184 = temp_117;
    temp_184 = ( unsigned char * )(temp_159);
    *temp_184 = temp_118;
    temp_188 = ( size_t * )(temp_160);
    *temp_188 = temp_119;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_161);
    *temp_189 = temp_120;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_162);
    *temp_189 = temp_121;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_163);
    *temp_189 = temp_122;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_164);
    *temp_189 = temp_123;
    temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_165);
    *temp_190 = temp_124;
    temp_191 = ( void ** )(temp_166);
    *temp_191 = temp_125;
    temp_192 = ( int * )(temp_167);
    *temp_192 = temp_126;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_168);
    *temp_189 = temp_127;
    temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_169);
    *temp_190 = temp_128;
    temp_191 = ( void ** )(temp_170);
    *temp_191 = temp_129;
    temp_188 = ( size_t * )(temp_171);
    *temp_188 = temp_130;
    temp_188 = ( size_t * )(temp_172);
    *temp_188 = temp_131;
    temp_188 = ( size_t * )(temp_173);
    *temp_188 = temp_132;
    temp_188 = ( size_t * )(temp_174);
    *temp_188 = temp_133;
    temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_175);
    *temp_190 = temp_134;
    temp_192 = ( int * )(temp_176);
    *temp_192 = temp_135;
    temp_189 = ( unsigned OMNI__INT64 * )(temp_177);
    *temp_189 = temp_136;
    temp_188 = ( size_t * )(temp_178);
    *temp_188 = temp_137;
    temp_188 = ( size_t * )(temp_179);
    *temp_188 = temp_138;
    temp_188 = ( size_t * )(temp_180);
    *temp_188 = temp_139;
    temp_191 = ( void ** )(temp_181);
    *temp_191 = temp_140;
    temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_182);
    *temp_190 = temp_141;
    return;
    
    L345:
    #ifdef __cplusplus
    try
    #endif
    {
        
        L344:
        switch( temp_101)
        {
        case 2641u: goto L0;
        case 1897u: goto L0;
        case 1382u: goto L642;
        case 1411u: goto L642;
        case 2427u: goto L642;
        case 2734u: goto L640;
        case 1019u: goto L640;
        case 692u: goto L638;
        case 2966u: goto L636;
        case 806u: goto L636;
        case 1167u: goto L634;
        case 3626u: goto L634;
        case 3516u: goto L632;
        case 1737u: goto L630;
        case 2027u: goto L630;
        case 1713u: goto L628;
        case 1489u: goto L626;
        case 3194u: goto L626;
        case 2769u: goto L624;
        case 2986u: goto L624;
        case 1048u: goto L622;
        case 3466u: goto L622;
        case 3503u: goto L622;
        case 2237u: goto L620;
        case 2452u: goto L620;
        case 1972u: goto L618;
        case 2429u: goto L618;
        case 1446u: goto L618;
        case 13u: goto L616;
        case 739u: goto L616;
        case 3828u: goto L616;
        case 1014u: goto L614;
        case 3877u: goto L614;
        case 2506u: goto L614;
        case 3435u: goto L612;
        case 958u: goto L610;
        case 496u: goto L610;
        case 671u: goto L608;
        case 3266u: goto L606;
        case 1108u: goto L606;
        case 3777u: goto L606;
        case 1007u: goto L604;
        case 3677u: goto L602;
        case 3944u: goto L602;
        case 1708u: goto L602;
        case 1417u: goto L602;
        case 3494u: goto L600;
        case 2299u: goto L600;
        case 3124u: goto L598;
        case 127u: goto L596;
        case 2609u: goto L596;
        case 3780u: goto L594;
        case 3288u: goto L594;
        case 295u: goto L592;
        case 3772u: goto L590;
        case 3022u: goto L590;
        case 402u: goto L588;
        case 780u: goto L586;
        case 429u: goto L586;
        case 4043u: goto L584;
        case 15u: goto L584;
        case 2262u: goto L582;
        case 1758u: goto L582;
        case 1266u: goto L580;
        case 357u: goto L578;
        case 1177u: goto L578;
        case 3588u: goto L576;
        case 2461u: goto L576;
        case 362u: goto L574;
        case 2377u: goto L574;
        case 2572u: goto L572;
        case 3188u: goto L572;
        case 2858u: goto L570;
        case 3864u: goto L570;
        case 3788u: goto L570;
        case 2528u: goto L570;
        case 3970u: goto L570;
        case 3946u: goto L570;
        case 4967u: goto L570;
        case 3868u: goto L568;
        case 1397u: goto L568;
        case 1068u: goto L568;
        case 4065u: goto L568;
        case 2207u: goto L568;
        case 2430u: goto L568;
        case 781u: goto L566;
        case 1580u: goto L566;
        case 3440u: goto L566;
        case 381u: goto L564;
        case 2668u: goto L562;
        case 437u: goto L562;
        case 2278u: goto L562;
        case 2979u: goto L560;
        case 3581u: goto L560;
        case 2326u: goto L560;
        case 3366u: goto L560;
        case 4461u: goto L560;
        case 3613u: goto L558;
        case 4071u: goto L558;
        case 3338u: goto L558;
        case 3224u: goto L558;
        case 6335u: goto L558;
        case 4218u: goto L558;
        case 1410u: goto L556;
        case 720u: goto L556;
        case 602u: goto L556;
        case 370u: goto L556;
        case 1003u: goto L556;
        case 1693u: goto L556;
        case 1269u: goto L556;
        case 1546u: goto L554;
        case 2190u: goto L554;
        case 2001u: goto L554;
        case 1224u: goto L554;
        case 777u: goto L552;
        case 3420u: goto L552;
        case 2635u: goto L552;
        case 758u: goto L550;
        case 2789u: goto L550;
        case 1185u: goto L550;
        case 4083u: goto L548;
        case 3878u: goto L548;
        case 3546u: goto L548;
        case 2745u: goto L548;
        case 3301u: goto L548;
        case 3123u: goto L548;
        case 3609u: goto L548;
        case 405u: goto L546;
        case 3207u: goto L546;
        case 3132u: goto L544;
        case 4049u: goto L544;
        case 3586u: goto L544;
        case 0u: goto L542;
        case 3928u: goto L542;
        case 3545u: goto L540;
        case 1452u: goto L540;
        case 3377u: goto L540;
        case 322u: goto L540;
        case 2997u: goto L540;
        case 1579u: goto L540;
        case 1297u: goto L540;
        case 2139u: goto L538;
        case 3892u: goto L538;
        case 1888u: goto L538;
        case 877u: goto L538;
        case 345u: goto L538;
        case 2084u: goto L536;
        case 2034u: goto L534;
        case 1854u: goto L534;
        case 3764u: goto L534;
        case 3174u: goto L534;
        case 388u: goto L532;
        case 859u: goto L532;
        case 1251u: goto L532;
        case 3945u: goto L530;
        case 3732u: goto L530;
        case 1562u: goto L530;
        case 1513u: goto L530;
        case 2268u: goto L530;
        case 1159u: goto L528;
        case 468u: goto L528;
        case 803u: goto L528;
        case 2150u: goto L526;
        case 1162u: goto L526;
        case 757u: goto L524;
        case 2884u: goto L524;
        case 2457u: goto L524;
        case 2985u: goto L524;
        case 3079u: goto L524;
        case 873u: goto L524;
        case 3568u: goto L522;
        case 2147u: goto L522;
        case 2699u: goto L520;
        case 3811u: goto L520;
        case 423u: goto L518;
        case 1089u: goto L518;
        case 2425u: goto L516;
        case 1660u: goto L516;
        case 3088u: goto L516;
        case 4367u: goto L516;
        case 2822u: goto L516;
        case 3843u: goto L516;
        case 3786u: goto L514;
        case 2545u: goto L514;
        case 573u: goto L514;
        case 5804u: goto L514;
        case 3197u: goto L514;
        case 2165u: goto L512;
        case 2570u: goto L512;
        case 772u: goto L512;
        case 1543u: goto L510;
        case 1075u: goto L510;
        case 1045u: goto L508;
        case 2830u: goto L508;
        case 578u: goto L508;
        case 1890u: goto L506;
        case 2784u: goto L506;
        case 2706u: goto L506;
        case 2929u: goto L504;
        case 277u: goto L504;
        case 1403u: goto L502;
        case 3900u: goto L502;
        case 2520u: goto L500;
        case 2473u: goto L500;
        case 2491u: goto L498;
        case 1170u: goto L498;
        case 2707u: goto L498;
        case 1646u: goto L498;
        case 3320u: goto L496;
        case 2435u: goto L496;
        case 2042u: goto L494;
        case 865u: goto L494;
        case 3528u: goto L494;
        case 1781u: goto L492;
        case 1932u: goto L492;
        case 586u: goto L490;
        case 1509u: goto L490;
        case 759u: goto L488;
        case 2627u: goto L488;
        case 3929u: goto L486;
        case 4024u: goto L486;
        case 2401u: goto L484;
        case 2216u: goto L484;
        case 581u: goto L482;
        case 2310u: goto L482;
        case 2077u: goto L482;
        case 1964u: goto L480;
        case 3390u: goto L478;
        case 3058u: goto L478;
        case 230u: goto L476;
        case 2261u: goto L474;
        case 3282u: goto L474;
        case 486u: goto L474;
        case 2451u: goto L472;
        case 954u: goto L472;
        case 145u: goto L470;
        case 3180u: goto L470;
        case 1512u: goto L470;
        case 1740u: goto L468;
        case 109u: goto L468;
        case 4031u: goto L466;
        case 367u: goto L466;
        case 3865u: goto L464;
        case 1457u: goto L464;
        case 337u: goto L462;
        case 1945u: goto L462;
        case 242u: goto L460;
        case 2166u: goto L460;
        case 1790u: goto L460;
        case 3212u: goto L458;
        case 378u: goto L458;
        case 3856u: goto L454;
        case 1004u: goto L454;
        case 991u: goto L452;
        case 3418u: goto L450;
        case 1179u: goto L450;
        case 5285u: goto L450;
        case 3808u: goto L450;
        case 3326u: goto L450;
        case 2423u: goto L444;
        case 3914u: goto L444;
        case 1192u: goto L444;
        case 2344u: goto L444;
        case 2247u: goto L436;
        case 3640u: goto L436;
        case 3129u: goto L436;
        case 54u: goto L436;
        case 155u: goto L428;
        case 2102u: goto L428;
        case 1858u: goto L424;
        case 907u: goto L424;
        case 1278u: goto L424;
        case 3402u: goto L412;
        case 900u: goto L412;
        case 2957u: goto L406;
        case 2026u: goto L406;
        case 3610u: goto L402;
        case 2599u: goto L402;
        case 4052u: goto L402;
        case 2028u: goto L398;
        case 216u: goto L398;
        case 23u: goto L384;
        case 3164u: goto L384;
        case 1822u: goto L382;
        case 3831u: goto L382;
        case 2037u: goto L380;
        case 3841u: goto L380;
        case 3850u: goto L380;
        case 3781u: goto L380;
        case 3332u: goto L376;
        case 866u: goto L374;
        case 617u: goto L374;
        case 2455u: goto L374;
        case 2535u: goto L370;
        case 1736u: goto L370;
        case 2984u: goto L370;
        case 1889u: goto L370;
        case 2959u: goto L370;
        case 909u: goto L368;
        case 879u: goto L368;
        case 3965u: goto L366;
        case 1230u: goto L366;
        case 2799u: goto L362;
        case 2624u: goto L362;
        case 3708u: goto L356;
        case 1581u: goto L356;
        case 3182u: goto L354;
        case 868u: goto L354;
        case 3938u: goto L316;
        case 1010u: goto L316;
        case 2082u: goto L316;
        case 1368u: goto L316;
        case 2399u: goto L310;
        case 3372u: goto L310;
        case 3608u: goto L308;
        case 196u: goto L308;
        case 2215u: goto L306;
        case 465u: goto L306;
        case 3678u: goto L306;
        case 2260u: goto L304;
        case 1253u: goto L304;
        case 3311u: goto L300;
        case 306u: goto L300;
        case 1850u: goto L300;
        case 2033u: goto L298;
        case 3994u: goto L298;
        case 1586u: goto L298;
        case 1813u: goto L294;
        case 1381u: goto L294;
        case 1116u: goto L294;
        case 1652u: goto L292;
        case 3566u: goto L292;
        case 1799u: goto L288;
        case 32u: goto L288;
        case 2527u: goto L284;
        case 831u: goto L284;
        case 1681u: goto L284;
        case 3379u: goto L282;
        case 3515u: goto L282;
        case 4040u: goto L280;
        case 1345u: goto L280;
        case 716u: goto L278;
        case 488u: goto L278;
        case 1339u: goto L276;
        case 326u: goto L276;
        case 1606u: goto L274;
        case 3229u: goto L274;
        case 2645u: goto L272;
        case 340u: goto L272;
        case 31u: goto L270;
        case 4060u: goto L270;
        case 258u: goto L266;
        case 3080u: goto L266;
        case 531u: goto L266;
        case 436u: goto L266;
        case 70u: goto L266;
        case 3872u: goto L264;
        case 1461u: goto L264;
        case 1350u: goto L264;
        case 3719u: goto L264;
        case 4194u: goto L264;
        case 3107u: goto L264;
        case 3663u: goto L264;
        case 3497u: goto L258;
        case 835u: goto L258;
        case 1860u: goto L258;
        case 3744u: goto L258;
        case 3913u: goto L258;
        case 1887u: goto L256;
        case 476u: goto L256;
        case 2750u: goto L256;
        case 3061u: goto L256;
        case 3406u: goto L256;
        case 2892u: goto L256;
        case 3369u: goto L254;
        case 2292u: goto L254;
        case 552u: goto L252;
        case 3472u: goto L252;
        case 2404u: goto L252;
        case 918u: goto L250;
        case 2676u: goto L248;
        case 1730u: goto L248;
        case 365u: goto L248;
        case 40u: goto L248;
        case 2317u: goto L248;
        case 2255u: goto L248;
        case 1462u: goto L246;
        case 3910u: goto L246;
        case 231u: goto L246;
        case 1031u: goto L244;
        case 3689u: goto L244;
        case 2185u: goto L242;
        case 2369u: goto L242;
        case 3019u: goto L238;
        case 536u: goto L238;
        case 2074u: goto L238;
        case 2940u: goto L238;
        case 3820u: goto L236;
        case 2738u: goto L236;
        case 3801u: goto L236;
        case 390u: goto L236;
        case 2398u: goto L232;
        case 128u: goto L232;
        case 425u: goto L232;
        case 3247u: goto L230;
        case 3013u: goto L230;
        case 1203u: goto L230;
        case 2758u: goto L228;
        case 309u: goto L228;
        case 4003u: goto L228;
        case 3277u: goto L226;
        case 747u: goto L226;
        case 2078u: goto L226;
        case 5730u: goto L226;
        case 2765u: goto L222;
        case 1969u: goto L222;
        case 1998u: goto L220;
        case 3187u: goto L220;
        case 2384u: goto L220;
        case 2847u: goto L220;
        case 2869u: goto L220;
        case 3133u: goto L220;
        case 3705u: goto L218;
        case 3016u: goto L218;
        case 549u: goto L218;
        case 150u: goto L216;
        case 1370u: goto L216;
        case 2411u: goto L210;
        case 3855u: goto L210;
        case 1597u: goto L210;
        case 704u: goto L208;
        case 101u: goto L208;
        case 1985u: goto L208;
        case 110u: goto L208;
        case 369u: goto L208;
        case 2169u: goto L208;
        case 1134u: goto L206;
        case 207u: goto L206;
        case 1667u: goto L206;
        case 996u: goto L206;
        case 1394u: goto L206;
        case 1305u: goto L206;
        case 1497u: goto L206;
        case 983u: goto L206;
        case 66u: goto L204;
        case 1371u: goto L204;
        case 368u: goto L200;
        case 1002u: goto L200;
        case 1503u: goto L198;
        case 2413u: goto L198;
        case 1733u: goto L198;
        case 2424u: goto L198;
        case 2047u: goto L198;
        case 2390u: goto L198;
        case 3513u: goto L196;
        case 3642u: goto L196;
        case 3899u: goto L196;
        case 3336u: goto L190;
        case 4030u: goto L190;
        case 3445u: goto L186;
        case 5524u: goto L186;
        case 4662u: goto L186;
        case 5666u: goto L186;
        case 3648u: goto L184;
        case 441u: goto L184;
        case 1823u: goto L184;
        case 3411u: goto L184;
        case 3359u: goto L184;
        case 2653u: goto L184;
        case 3233u: goto L182;
        case 3931u: goto L182;
        case 2203u: goto L182;
        case 788u: goto L180;
        case 2787u: goto L180;
        case 4072u: goto L178;
        case 1081u: goto L178;
        case 6757u: goto L178;
        case 4980u: goto L178;
        case 4658u: goto L178;
        case 6615u: goto L178;
        case 428u: goto L174;
        case 3620u: goto L174;
        case 2973u: goto L174;
        case 1118u: goto L172;
        case 371u: goto L172;
        case 955u: goto L170;
        case 1066u: goto L170;
        case 1819u: goto L170;
        case 867u: goto L170;
        case 2332u: goto L166;
        case 1865u: goto L166;
        case 2282u: goto L166;
        case 1575u: goto L166;
        case 2352u: goto L166;
        case 2666u: goto L166;
        case 2397u: goto L166;
        case 3967u: goto L166;
        case 278u: goto L164;
        case 347u: goto L162;
        case 212u: goto L162;
        case 3604u: goto L156;
        case 2167u: goto L156;
        case 2890u: goto L156;
        case 1166u: goto L156;
        case 1792u: goto L154;
        case 875u: goto L154;
        case 2762u: goto L152;
        case 590u: goto L152;
        case 321u: goto L152;
        case 2054u: goto L150;
        case 2875u: goto L148;
        case 1596u: goto L148;
        case 1634u: goto L148;
        case 1663u: goto L148;
        case 910u: goto L148;
        case 1286u: goto L148;
        case 1395u: goto L148;
        case 568u: goto L144;
        case 1373u: goto L144;
        case 2647u: goto L144;
        case 841u: goto L144;
        case 1728u: goto L144;
        case 1359u: goto L142;
        case 1818u: goto L142;
        case 2171u: goto L142;
        case 1706u: goto L142;
        case 2735u: goto L142;
        case 491u: goto L140;
        case 2998u: goto L140;
        case 52u: goto L140;
        case 2325u: goto L138;
        case 1349u: goto L138;
        case 1015u: goto L138;
        case 3935u: goto L136;
        case 2766u: goto L136;
        case 3571u: goto L136;
        case 3735u: goto L134;
        case 562u: goto L134;
        case 5029u: goto L134;
        case 2811u: goto L134;
        case 5440u: goto L134;
        case 3029u: goto L134;
        case 504u: goto L132;
        case 489u: goto L132;
        case 2048u: goto L128;
        case 2059u: goto L128;
        case 982u: goto L128;
        case 1325u: goto L128;
        case 438u: goto L128;
        case 2850u: goto L126;
        case 1807u: goto L126;
        case 2849u: goto L124;
        case 1160u: goto L124;
        case 2946u: goto L122;
        case 1072u: goto L122;
        case 2131u: goto L120;
        case 3686u: goto L118;
        case 3879u: goto L118;
        case 3113u: goto L118;
        case 1408u: goto L116;
        case 2488u: goto L116;
        case 4089u: goto L116;
        case 471u: goto L116;
        case 333u: goto L114;
        case 713u: goto L114;
        case 670u: goto L114;
        case 2927u: goto L112;
        case 850u: goto L112;
        case 1540u: goto L112;
        case 938u: goto L112;
        case 1895u: goto L112;
        case 3662u: goto L110;
        case 2009u: goto L108;
        case 274u: goto L108;
        case 98u: goto L108;
        case 3974u: goto L108;
        case 3121u: goto L102;
        case 1280u: goto L102;
        case 1099u: goto L98;
        case 3733u: goto L98;
        case 2422u: goto L98;
        case 1572u: goto L98;
        case 625u: goto L96;
        case 679u: goto L96;
        case 3176u: goto L94;
        case 4094u: goto L94;
        case 2200u: goto L94;
        case 350u: goto L92;
        case 748u: goto L92;
        case 922u: goto L92;
        case 7u: goto L92;
        case 1308u: goto L92;
        case 1073u: goto L92;
        case 2302u: goto L92;
        case 2197u: goto L84;
        case 1909u: goto L84;
        case 753u: goto L84;
        case 3137u: goto L80;
        case 271u: goto L80;
        case 1783u: goto L78;
        case 695u: goto L78;
        case 1429u: goto L78;
        case 3743u: goto L78;
        case 3417u: goto L76;
        case 1593u: goto L76;
        case 1314u: goto L74;
        case 3049u: goto L74;
        case 1760u: goto L74;
        case 448u: goto L70;
        case 3044u: goto L70;
        case 1093u: goto L70;
        case 1115u: goto L66;
        case 2434u: goto L66;
        case 83u: goto L66;
        case 2089u: goto L66;
        case 2375u: goto L66;
        case 2111u: goto L66;
        case 832u: goto L66;
        case 2218u: goto L62;
        case 2136u: goto L62;
        case 1188u: goto L62;
        case 1338u: goto L62;
        case 2368u: goto L54;
        case 2602u: goto L54;
        case 2307u: goto L52;
        case 3527u: goto L52;
        case 3230u: goto L52;
        case 3135u: goto L52;
        case 2952u: goto L52;
        case 3238u: goto L52;
        case 2924u: goto L48;
        case 391u: goto L48;
        case 1517u: goto L48;
        case 1763u: goto L48;
        case 3399u: goto L48;
        case 2868u: goto L48;
        case 3647u: goto L48;
        case 3292u: goto L48;
        case 3493u: goto L46;
        case 3782u: goto L46;
        case 1608u: goto L46;
        case 5880u: goto L46;
        case 4417u: goto L46;
        case 3225u: goto L46;
        case 4158u: goto L46;
        case 2370u: goto L34;
        case 649u: goto L34;
        case 2049u: goto L30;
        case 430u: goto L30;
        case 923u: goto L26;
        case 2947u: goto L26;
        case 2791u: goto L24;
        case 2003u: goto L24;
        case 1896u: goto L24;
        case 3839u: goto L24;
        case 3256u: goto L24;
        case 1106u: goto L20;
        case 3803u: goto L20;
        case 2838u: goto L16;
        case 2110u: goto L16;
        case 2357u: goto L14;
        case 2337u: goto L14;
        case 2623u: goto L14;
        case 2354u: goto L14;
        case 2239u: goto L10;
        case 3730u: goto L10;
        case 1140u: goto L8;
        case 2359u: goto L8;
        case 1923u: goto L6;
        case 1941u: goto L6;
        case 3722u: goto L6;
        case 764u: goto L4;
        case 1531u: goto L0;
        case 1552u: goto L0;
        case 344u: goto L346;
        case 3200u: goto L346;
        default: goto L348;
        }
        
        L0:
        temp_196 = (unsigned int)860;
        temp_255 = (unsigned int)272;
        temp_254 = (unsigned int)400;
        temp_253 = (unsigned int)97;
        temp_102 = (bool)1;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L4:
        temp_110 = ( bool )( temp_117 == 0 );
        temp_248 = (unsigned int)4294967085u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)82u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)254u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)213u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)561u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)403u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1340u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L6:
        temp_114 = ( unsigned int )( size_t )(temp_125);
        temp_248 = (unsigned int)321u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967072u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)285905049u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)285904727u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_249 = (unsigned int)0u;
        temp_248 = temp_248 & temp_255;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)108u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)331u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1698u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L8:
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)5u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)236u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966956u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)144u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)109u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)1039u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)575u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L10:
        temp_130 = ( size_t )(temp_118);
        temp_117 = ( bool )( temp_110 == 0 );
        temp_248 = (unsigned int)4294967004u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967210u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)335u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1838u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_117);
        temp_195 = (unsigned int)1110u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1251u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L14:
        temp_124 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_138);
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)142u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967059u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)66u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)50u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)567u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L16:
        temp_139 = ( size_t )( size_t )(temp_129);
        temp_140 = ( void * )(temp_110);
        temp_248 = (unsigned int)4294967279u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)9u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)67u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)252u;
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)2u;
        temp_249 = (unsigned int)0u;
        temp_248 = temp_248 & temp_254;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)2500u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)2295u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)333u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L20:
        temp_119 = temp_131 | temp_130;
        temp_132 = temp_131 + temp_133;
        temp_248 = (unsigned int)301u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967228u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)208u;
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)2u;
        temp_249 = (unsigned int)temp_105;
        temp_248 = temp_248 & temp_253;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)65u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)1000u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2076u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L24:
        temp_114 = ( unsigned int )(temp_137);
        temp_248 = (unsigned int)164u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)153u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967122u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)421u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L26:
        temp_125 = ( void * )(temp_130);
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)299080296u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967157u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967024u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967283u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)292u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1119u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L30:
        // The next string is really just an assignment on 32bit platform
        temp_119 = ( size_t )( ( size_t )( temp_119 ) + ( ( ( size_t )( temp_119 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_119 ) << 31 ) << 1 ) >> 15 ) );
        temp_130 = temp_133 ^ temp_119;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)222785056u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967092u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967147u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)172u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)176u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)800u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)295u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L34:
        temp_136 = ( unsigned OMNI__INT64 )(temp_119);
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)131451275u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967204u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)213u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)178u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)524u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1065u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L46:
        temp_129 = ( void * )(temp_114);
        temp_122 = temp_120 | temp_136;
        temp_127 = temp_120 & temp_136;
        temp_110 = temp_122 < temp_127;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)13u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)459u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)25u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)358u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)15u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2445u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L48:
        temp_102 = ( bool )( temp_105 == 0 );
        temp_248 = (unsigned int)4294967256u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967256u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967256u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1910u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L52:
        temp_122 = temp_127 ^ temp_123;
        temp_129 = ( void * )memset( ( void * )temp_124, ( int )temp_126, ( size_t )temp_122 );
        temp_248 = (unsigned int)4294967213u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)109u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)152u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)38u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)542u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L54:
        temp_123 = (unsigned OMNI__INT64)4070557787u;
        temp_115 = ( unsigned int )(temp_114);
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)35u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)72u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967111u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)84u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)628u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)1425u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)497u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L62:
        temp_140 = ( void * )(temp_124);
        temp_125 = ( void * )(temp_138);
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)60612962u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)60612711u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)110u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)149u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1211u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L66:
        temp_126 = ( int )(temp_114);
        temp_107 = ( bool )( temp_102 == 0 );
        temp_125 = ( void * )(temp_138);
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)13328u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)13204u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)388u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)180u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)74u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1331u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L70:
        temp_124 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_138);
        temp_248 = (unsigned int)76u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)348u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)7u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)75u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1169u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L74:
        // The next string is really just an assignment on 32bit platform
        temp_132 = ( size_t )( ( size_t )( temp_132 ) + ( ( ( size_t )( temp_132 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_132 ) << 31 ) << 1 ) >> 15 ) );
        temp_248 = (unsigned int)4294967119u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)7u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)106u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)13720u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294966938u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1206u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L76:
        temp_139 = ( size_t )( size_t )(temp_129);
        temp_137 = (size_t)2348940611u;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)392905321u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967281u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967116u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967035u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2386u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)818u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2463u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L78:
        temp_133 = ( size_t )( size_t )(temp_125);
        temp_136 = ( unsigned OMNI__INT64 )(temp_114);
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)3u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)41u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)2u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)35u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)134u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1742u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)33u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2327u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L80:
        temp_248 = (unsigned int)4294967107u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)45u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)71u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)24u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)216u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1124u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)249u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1111u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L84:
        temp_248 = (unsigned int)4294967135u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)17u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294966935u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)816u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)195u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)661u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L92:
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)4u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967154u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)263u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)107885663u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)107885555u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)66u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)730u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L94:
        temp_125 = ( void * )(temp_118);
        temp_248 = (unsigned int)4294967198u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967198u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)10061u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)9963u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3031u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L96:
        temp_128 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_141);
        temp_248 = (unsigned int)4294967292u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967292u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967292u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)1193u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1636u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L98:
        temp_121 = ( unsigned OMNI__INT64 )(temp_114);
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)153720366u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967189u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967189u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)209010157u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967189u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)84u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1246u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L102:
        temp_248 = (unsigned int)27u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)27u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)2u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)27u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2979u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)534u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1347u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L108:
        temp_125 = ( void * )(temp_138);
        temp_139 = ( size_t )( size_t )(temp_124);
        temp_248 = (unsigned int)6u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)122u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)14u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)382u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)1u;
        temp_249 = (unsigned int)temp_102;
        temp_248 = temp_248 & temp_254;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)1775u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)607u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1479u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L110:
        // The next string is really just an assignment on 32bit platform
        temp_137 = ( size_t )( ( size_t )( temp_137 ) + ( ( ( size_t )( temp_137 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_137 ) << 31 ) << 1 ) >> 15 ) );
        temp_130 = ( size_t )(temp_126);
        temp_248 = (unsigned int)4294967183u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)80u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)1427u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1347u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)2u;
        temp_249 = (unsigned int)0u;
        temp_248 = temp_248 & temp_255;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)3152u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)1473u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1655u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L112:
        temp_115 = ( unsigned int )(temp_137);
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)11u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967029u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)6u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)279u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967260u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)158u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L114:
        temp_119 = ( size_t )(temp_121);
        temp_106 = ( bool )( temp_107 == 0 );
        temp_128 = (OMNI_GLOBAL_SCOPE LinkedStack *)temp_124;
        temp_248 = (unsigned int)4294967120u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)366u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)318u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)1685u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3102u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L116:
        temp_118 = ( bool )(temp_139);
        temp_128 = (OMNI_GLOBAL_SCOPE LinkedStack *)temp_124;
        temp_106 = (bool)temp_103;
        temp_248 = (unsigned int)219u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966906u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)366u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)450u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L118:
        temp_139 = ( size_t )( size_t )(temp_128);
        temp_248 = (unsigned int)4294967049u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)2u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)251u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)5u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)51u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3100u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L120:
        temp_137 = ( size_t )( size_t )(temp_140);
        temp_104 = (bool)temp_102;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)7u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)84u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)245042462u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)245042402u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)14u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)7u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)1u;
        temp_249 = (unsigned int)0u;
        temp_248 = temp_248 & temp_253;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)1991u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)630u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)10u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L122:
        temp_124 = (OMNI_GLOBAL_SCOPE LinkedStack *)0u;
        temp_104 = (bool)temp_107;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)208774716u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)208774691u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967136u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)45u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)123u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)2u;
        temp_249 = (unsigned int)0u;
        temp_248 = temp_248 & temp_255;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)2904u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)336u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)360u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L124:
        temp_117 = ( bool )(temp_132);
        temp_135 = (int)0;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)5426u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)5311u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967028u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967236u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2703u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)3062u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3066u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L126:
        temp_114 = ( unsigned int )( size_t )(temp_124);
        temp_248 = (unsigned int)4294967285u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967289u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967236u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1843u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L128:
        temp_136 = ( unsigned OMNI__INT64 )(temp_114);
        temp_248 = (unsigned int)4294966922u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)231u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)27u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)311u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L132:
        temp_122 = temp_127 ^ temp_123;
        temp_129 = ( void * )memset( ( void * )temp_124, ( int )temp_126, ( size_t )temp_122 );
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)2u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)146u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)118u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)453u;
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)temp_108;
        temp_249 = (unsigned int)temp_107;
        temp_248 = temp_248 & temp_253;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)68u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)381u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2069u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L134:
        temp_128 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_114);
        temp_122 = temp_120 & temp_136;
        temp_123 = temp_120 + temp_121;
        temp_248 = (unsigned int)4294967075u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)43053781u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967211u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)137u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1763u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L136:
        // The next string is really just an assignment on 32bit platform
        temp_137 = ( size_t )( ( size_t )( temp_137 ) + ( ( ( size_t )( temp_137 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_137 ) << 31 ) << 1 ) >> 15 ) );
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)59u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3295u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L138:
        temp_125 = ( void * )(temp_138);
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)272460560u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)272460436u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)388u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)4u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)176u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)195u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L140:
        temp_118 = ( bool )( size_t )(temp_124);
        temp_248 = (unsigned int)4294967057u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)24u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)325u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)78u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1399u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L142:
        temp_130 = ( size_t )(temp_118);
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)423622413u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)423622003u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)10u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)170u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)351920429u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)351920052u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)531u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L144:
        temp_134 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_131);
        temp_248 = (unsigned int)40u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)221u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)55u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)141u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1537u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L148:
        temp_136 = ( unsigned OMNI__INT64 )(temp_135);
        temp_125 = ( void * )(temp_138);
        temp_248 = (unsigned int)173u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)225u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)638u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)633u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)615u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L150:
        temp_125 = ( void * )(temp_138);
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)12u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967104u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967155u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)280088985u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)280088884u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)473u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L152:
        temp_133 = ( size_t )( size_t )(temp_125);
        temp_127 = ( unsigned OMNI__INT64 )( size_t )(temp_128);
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)9u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)61u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)15214u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)15062u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967024u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2326u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)2264u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2414u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L154:
        // The next string is really just an assignment on 32bit platform
        temp_119 = ( size_t )( ( size_t )( temp_119 ) + ( ( ( size_t )( temp_119 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_119 ) << 31 ) << 1 ) >> 15 ) );
        temp_248 = (unsigned int)22u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967007u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967179u;
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)2u;
        temp_249 = ( unsigned int )( temp_109 == 0 );
        temp_248 = temp_248 & temp_255;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)361u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)711u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2600u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L156:
        temp_133 = ( size_t )(temp_132);
        temp_248 = (unsigned int)27u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967012u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)297255512u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)297255400u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)908u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2061u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L162:
        temp_127 = ( unsigned OMNI__INT64 )( size_t )(temp_124);
        temp_128 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_130);
        temp_109 = (bool)temp_102;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)14u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)43u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967018u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)91u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)334u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L164:
        temp_125 = ( void * )(temp_133);
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)4u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)40u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L166:
        temp_114 = ( unsigned int )(temp_127);
        temp_196 = (unsigned int)1995u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L170:
        // The next string is really just an assignment on 32bit platform
        temp_137 = ( size_t )( ( size_t )( temp_137 ) + ( ( ( size_t )( temp_137 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_137 ) << 31 ) << 1 ) >> 15 ) );
        temp_130 = ( size_t )( temp_104 == 0 );
        temp_119 = temp_130 - temp_137;
        temp_248 = (unsigned int)4294967150u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966970u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)30786793u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)30786746u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)196u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L172:
        // The next string is really just an assignment on 32bit platform
        temp_137 = ( size_t )( ( size_t )( temp_137 ) + ( ( ( size_t )( temp_137 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_137 ) << 31 ) << 1 ) >> 15 ) );
        temp_248 = (unsigned int)4294967114u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)85u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)57813520u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)57813358u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2398u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L174:
        temp_124 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_138);
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)2879431u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967175u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)54u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)349u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2194u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L178:
        temp_140 = ( void * )(temp_119);
        temp_196 = (unsigned int)3491u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L180:
        temp_137 = (size_t)4070557787u;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)381904052u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)381903950u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)98u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)271u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1184u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L182:
        temp_130 = temp_131 ^ temp_132;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)4u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)209u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967131u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)4u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)40u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)83u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1119u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L184:
        temp_133 = ( size_t )( size_t )(temp_124);
        temp_248 = (unsigned int)4294967032u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)10u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)276u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)53u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1387u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L186:
        temp_134 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_114);
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)13u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967191u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967295u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)10504u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)10442u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2400u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L190:
        temp_130 = temp_131 ^ temp_132;
        temp_248 = (unsigned int)4u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)124u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)134u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1139u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L196:
        temp_129 = ( void * )(temp_114);
        temp_118 = (bool)0u;
        temp_248 = (unsigned int)295u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)150u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967203u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)25u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)352u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L198:
        temp_132 = (size_t)4070557787u;
        temp_119 = ( size_t )(temp_137);
        temp_196 = (unsigned int)1376u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L200:
        temp_129 = ( void * )(temp_124);
        temp_132 = (size_t)197803677u;
        temp_248 = (unsigned int)177u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967190u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)95u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)358u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)946u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L204:
        temp_137 = (size_t)1232152641u;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)66u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)169u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)22u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)391u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967151u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)53u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L206:
        temp_129 = (void *)temp_125;
        temp_131 = ( size_t )(temp_126);
        temp_248 = (unsigned int)6u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)385u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)166u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2283u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L208:
        // The next string is really just an assignment on 32bit platform
        temp_123 = ( unsigned OMNI__INT64 )( ( size_t )( temp_123 ) + ( ( ( size_t )( temp_123 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_123 ) << 31 ) << 1 ) >> 15 ) );
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)7u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)243u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)193360448u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967143u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)262u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)558u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)41u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1603u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L210:
        temp_130 = temp_131 ^ temp_132;
        temp_248 = (unsigned int)285u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)40u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)84u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)62u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1307u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L216:
        temp_133 = ( size_t )(temp_119);
        temp_136 = (unsigned OMNI__INT64)16u;
        temp_248 = (unsigned int)108u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)41u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)396u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967156u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)125u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)1107u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4006u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L218:
        temp_108 = ( bool )( temp_102 == 0 );
        temp_115 = (unsigned int)temp_102;
        temp_116 = (unsigned int)0u;
        temp_107 = (bool)temp_102;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)90u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)219u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)2195078023u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2195077940u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967088u;
        temp_255 = temp_255 + temp_248;
        temp_139 = ( size_t )(temp_119);
        temp_248 = (unsigned int)29u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967056u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)369u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1968u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L220:
        temp_108 = (bool)temp_104;
        temp_115 = (unsigned int)0u;
        temp_116 = (unsigned int)temp_102;
        temp_248 = (unsigned int)40u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967220u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)19u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)256u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_107 = ( bool )( temp_104 == 0 );
        temp_248 = (unsigned int)354u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)4u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967050u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)60u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)48u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)647u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L222:
        temp_125 = ( void * )(temp_141);
        temp_133 = ( size_t )( size_t )(temp_124);
        temp_248 = (unsigned int)44u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)225u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)59u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1659u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L226:
        temp_135 = ( int )(temp_132);
        temp_130 = temp_133 ^ temp_119;
        temp_248 = (unsigned int)4294967269u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)27u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)284u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)113u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2606u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L228:
        temp_134 = (OMNI_GLOBAL_SCOPE LinkedStack *)0u;
        temp_248 = (unsigned int)94u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)245u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)11485u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967294u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)21u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1248u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L230:
        temp_132 = temp_132 - temp_133;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)15530u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294966974u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)35u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967076u;
        temp_255 = temp_255 + temp_248;
        temp_110 = temp_119 < temp_132;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)217170539u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)217170520u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)57u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)64u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967132u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1965u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_110);
        temp_195 = (unsigned int)1707u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2590u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L232:
        temp_127 = temp_123 - temp_121;
        temp_110 = temp_122 > temp_127;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)23u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)519u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)21u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)297u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)102u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2093u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_110);
        temp_195 = (unsigned int)2755u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3481u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L236:
        temp_138 = temp_139 + temp_119;
        temp_248 = (unsigned int)138u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)132u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)31u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)44u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)4294967045u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)1974078207u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1974078000u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967228u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3773u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)2005u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)98u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L238:
        temp_138 = temp_139 - temp_130;
        temp_248 = (unsigned int)170u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967137u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)47u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2900u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)2782u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2808u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L242:
        temp_124 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_119);
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_249 = (unsigned int)0u;
        temp_248 = temp_248 & temp_254;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)1097u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)579u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)46u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L244:
        temp_248 = (unsigned int)4294967051u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)107u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967235u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)877u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_110);
        temp_195 = (unsigned int)228u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3112u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L246:
        temp_135 = ( int )(temp_118);
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)12872u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967054u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)356335851u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967050u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)19u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)93u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1298u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)273u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)131u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L248:
        temp_141 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_137);
        temp_248 = (unsigned int)4294967293u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967117u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)255u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1960u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L250:
        temp_248 = (unsigned int)207u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)325596253u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)325596171u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)303u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)524u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_110);
        temp_195 = (unsigned int)1678u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1866u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L252:
        temp_248 = (unsigned int)4294967064u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967145u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967235u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1238u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)673u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)661u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L254:
        temp_248 = (unsigned int)15u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)7u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)88u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967184u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2331u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_110);
        temp_195 = (unsigned int)1278u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2639u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L256:
        temp_125 = ( void * )(temp_132);
        temp_248 = (unsigned int)4294967236u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)458u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967178u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)374u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L258:
        temp_133 = (size_t)temp_130;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)2u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)86u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)173u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)378u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)478u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L264:
        temp_139 = (size_t)temp_133;
        temp_137 = (size_t)2715138226u;
        temp_115 = ( unsigned int )( size_t )(temp_140);
        temp_248 = (unsigned int)336u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967004u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)17u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)269u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)2365u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)340u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L266:
        temp_137 = (size_t)1232152641u;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)55u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)155u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)281u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)28u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)115u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3607u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L270:
        temp_248 = (unsigned int)4294967250u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967210u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967136u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)59u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)3653u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3690u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L272:
        temp_125 = ( void * )(temp_114);
        temp_126 = ( int )(temp_131);
        temp_248 = (unsigned int)4294967080u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)355u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967167u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1448u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)1734u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2668u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L274:
        temp_248 = (unsigned int)4294967080u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)355u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967167u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)277u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)256u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1889u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L276:
        temp_117 = ( bool )( size_t )(temp_134);
        temp_114 = ( unsigned int )( size_t )(temp_140);
        temp_140 = ( void * )(temp_124);
        temp_248 = (unsigned int)187u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)152u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)89064754u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)89064650u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)197u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)1630u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)10u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L278:
        temp_141 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_114);
        temp_114 = ( unsigned int )(temp_136);
        temp_140 = ( void * )(temp_124);
        temp_115 = ( unsigned int )( size_t )(temp_128);
        temp_248 = (unsigned int)4294967294u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)6u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)174u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967036u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)504u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)1706u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)46u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L280:
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)1850u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967188u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966900u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)140u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3859u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)1802u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1229u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L282:
        temp_135 = ( int )(temp_114);
        temp_248 = (unsigned int)264u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)389647128u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967020u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967243u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2154u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)511u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2423u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L284:
        temp_128 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_114);
        temp_120 = ( unsigned OMNI__INT64 )(temp_114);
        temp_130 = ( size_t )(temp_127);
        temp_248 = (unsigned int)157u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)28u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)386u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967250u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1018u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)501u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)752u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L288:
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)337660170u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967219u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)127u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967038u;
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)1u;
        temp_249 = (unsigned int)0u;
        temp_248 = temp_248 & temp_255;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)233u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)928u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1168u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L292:
        temp_135 = ( int )( size_t )(temp_128);
        temp_114 = ( unsigned int )(temp_135);
        temp_128 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_126);
        temp_125 = ( void * )(temp_127);
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)17u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)239u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967090u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)67u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)111u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1161u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1410u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)868u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L294:
        temp_130 = ( size_t )( size_t )(temp_129);
        temp_114 = ( unsigned int )( size_t )(temp_129);
        temp_248 = (unsigned int)4294967142u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)295u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)71u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1799u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1671u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1153u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L298:
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)6u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)104u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)10u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)123u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)133u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)448u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)411u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1196u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L300:
        temp_248 = (unsigned int)4294966926u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)197u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967134u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2733u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)2789u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)126u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L304:
        temp_122 = ( unsigned OMNI__INT64 )(temp_139);
        temp_248 = (unsigned int)4294967098u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)30u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)15831u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967164u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)10u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)231u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L306:
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)12101u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967205u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966810u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)99746122u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)99746102u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1157u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)2379u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2455u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L308:
        temp_248 = (unsigned int)214u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966970u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967193u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2598u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)2019u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)108u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L310:
        temp_248 = (unsigned int)124u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966908u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967116u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1624u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1210u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)340u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L316:
        temp_135 = (int)0;
        temp_112 = ( unsigned int )(temp_106);
        temp_113 = (unsigned int)8u;
        temp_112 = temp_112 * temp_113;
        temp_113 = (unsigned int)8u;
        temp_112 = temp_113 + temp_112;
        temp_136 = ( unsigned OMNI__INT64 )( ( size_t )( ( temp_112 ) & 0xFFFFFFFF ) );
        temp_248 = (unsigned int)4294967071u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)2u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)5u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967137u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2956u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)1116u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3058u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L354:
        temp_248 = (unsigned int)4294967267u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)229259585u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)229259456u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)223u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)656u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2846u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)1909u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1996u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L356:
        temp_248 = (unsigned int)4294967271u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)423u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)143u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3693u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)923u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)93u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L362:
        temp_196 = (unsigned int)2150u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)1121u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1612u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L366:
        temp_196 = (unsigned int)3373u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)963u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)185u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L368:
        temp_248 = (unsigned int)4u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)367u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)1187u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)129u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L370:
        temp_129 = ( void * )malloc( ( size_t )temp_127 );
        temp_248 = (unsigned int)259u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)2986018760u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2986018477u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967061u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)9u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)713u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L374:
        temp_117 = temp_132 < temp_131;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)378194286u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967093u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)42u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294966781u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)838u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_117);
        temp_195 = (unsigned int)1835u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)329u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L376:
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)47u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)139u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)21u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)293u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)16u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)13u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2471u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)391u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)62u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L380:
        temp_134 = (OMNI_GLOBAL_SCOPE LinkedStack *)0u;
        temp_248 = (unsigned int)369u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)352554287u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)352554105u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)151u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1165u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)366u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1293u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L382:
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)37u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)405u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967035u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)92u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)716u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)320u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1913u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L384:
        temp_110 = temp_138 >= temp_137;
        temp_248 = (unsigned int)58u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)92u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)27u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)2062u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967192u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)895u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L398:
        temp_110 = temp_131 < temp_132;
        temp_248 = (unsigned int)4294967282u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967003u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967091u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1341u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L402:
        temp_248 = (unsigned int)379u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)253802230u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)253802128u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967187u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3256u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1678u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3214u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L406:
        temp_124 = (OMNI_GLOBAL_SCOPE LinkedStack *)0u;
        temp_248 = (unsigned int)4294967053u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967225u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)10u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)132u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1975u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)596u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1876u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L412:
        temp_248 = (unsigned int)4294967187u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)63u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294966771u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3172u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)1988u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2102u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L424:
        temp_196 = (unsigned int)644u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)632u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2176u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L428:
        temp_248 = (unsigned int)60u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966838u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)118u;
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)8u;
        temp_249 = (unsigned int)0u;
        temp_248 = temp_248 & temp_254;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)66u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)954u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1161u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L436:
        temp_248 = (unsigned int)4294967107u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)146u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)247u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1773u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)2222u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)283u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L444:
        temp_131 = ( size_t )( size_t )(temp_124);
        temp_248 = (unsigned int)4294967095u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)163u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)358u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)631u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L450:
        temp_107 = (bool)temp_106;
        temp_248 = (unsigned int)4294967289u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)109u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967101u;
        temp_255 = temp_255 + temp_248;
        temp_108 = ( bool )( temp_107 == 0 );
        temp_109 = ( bool )( temp_108 == 0 );
        temp_135 = ( int )(temp_138);
        temp_248 = (unsigned int)114u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967294u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)302u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2319;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L452:
        temp_114 = ( unsigned int )(temp_123);
        temp_248 = (unsigned int)159u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966957u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967152u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)706u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)3422u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3487u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L454:
        temp_139 = ( size_t )(temp_133);
        temp_248 = (unsigned int)37u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)368667266u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)368667103u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294966960u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2238u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)1952u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2117u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L458:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_259 = ( void ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_260 = *temp_261;
        temp_258 = *temp_259;
        temp_256 = ( size_t )( size_t )(temp_258);
        *temp_257 = temp_256;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_260);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L460:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_263 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_256 = *temp_257;
        temp_262 = *temp_263;
        temp_260 = (bool)temp_262;
        temp_264 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_256);
        *temp_261 = temp_260;
        *temp_265 = temp_264;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L462:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_260 = *temp_261;
        temp_264 = *temp_265;
        temp_256 = ( size_t )( size_t )(temp_264);
        *temp_257 = temp_256;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_260);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L464:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_263 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_267 = ( bool * )(temp_250);
        temp_266 = *temp_267;
        temp_262 = *temp_263;
        temp_260 = ( bool )( temp_262 == 0 );
        *temp_261 = temp_260;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_266);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L466:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_269 = ( unsigned OMNI__INT64 * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_268 = ( unsigned OMNI__INT64 )( ( size_t )( ( temp_248 ) & 0xFFFFFFFF ) );
        // The next string is really just an assignment on 32bit platform
        temp_268 = ( unsigned OMNI__INT64 )( ( size_t )( temp_268 ) + ( ( ( size_t )( temp_268 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_268 ) << 31 ) << 1 ) >> 15 ) );
        *temp_269 = temp_268;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L468:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_271 = ( size_t * )(temp_250);
        temp_264 = *temp_265;
        temp_256 = ( size_t )( size_t )(temp_264);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_270 = ( size_t )( ( size_t )( ( temp_248 ) & 0xFFFFFFFF ) );
        *temp_257 = temp_256;
        *temp_271 = temp_270;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L470:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_271 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_273 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_275 = ( size_t * )(temp_250);
        temp_272 = *temp_273;
        temp_270 = *temp_271;
        temp_256 = temp_270 | temp_272;
        temp_274 = temp_270 & temp_272;
        *temp_257 = temp_256;
        *temp_275 = temp_274;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L472:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_259 = ( void ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_256 = *temp_257;
        temp_258 = ( void * )(temp_256);
        temp_264 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_258);
        *temp_259 = temp_258;
        *temp_265 = temp_264;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L474:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_260 = *temp_261;
        temp_256 = *temp_257;
        // The next string is really just an assignment on 32bit platform
        temp_256 = ( size_t )( ( size_t )( temp_256 ) + ( ( ( size_t )( temp_256 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_256 ) << 31 ) << 1 ) >> 15 ) );
        *temp_257 = temp_256;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_260);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L476:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_263 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_256 = *temp_257;
        temp_262 = *temp_263;
        temp_260 = ( bool )( temp_262 == 0 );
        temp_264 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_256);
        *temp_261 = temp_260;
        *temp_265 = temp_264;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L478:
        temp_187 = ( char const ** )(temp_152);
        temp_111 = *temp_187;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L480:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_260 = *temp_261;
        temp_256 = *temp_257;
        temp_264 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_256);
        *temp_265 = temp_264;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_260);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L482:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_271 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_273 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_260 = *temp_261;
        temp_272 = *temp_273;
        temp_270 = *temp_271;
        temp_256 = temp_270 ^ temp_272;
        *temp_257 = temp_256;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_260);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L484:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_271 = ( size_t * )(temp_250);
        temp_256 = *temp_257;
        temp_264 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_256);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_270 = ( size_t )( ( size_t )( ( temp_248 ) & 0xFFFFFFFF ) );
        *temp_265 = temp_264;
        *temp_271 = temp_270;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L486:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_277 = ( int * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_279 = ( int * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_269 = ( unsigned OMNI__INT64 * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_281 = ( unsigned OMNI__INT64 * )(temp_250);
        temp_280 = *temp_281;
        temp_278 = *temp_279;
        temp_276 = (int)temp_278;
        temp_268 = (unsigned OMNI__INT64)temp_280;
        *temp_277 = temp_276;
        *temp_269 = temp_268;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L488:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_271 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_273 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_260 = *temp_261;
        temp_272 = *temp_273;
        temp_270 = *temp_271;
        temp_256 = temp_270 + temp_272;
        *temp_257 = temp_256;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_260);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L490:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_283 = ( unsigned int * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_285 = ( unsigned int * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_260 = *temp_261;
        temp_282 = ( unsigned int )(temp_260);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_284 = ( unsigned int )( ( size_t )( ( temp_248 ) & 0xFFFFFFFF ) );
        temp_282 = temp_282 * temp_284;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_284 = ( unsigned int )( ( size_t )( ( temp_248 ) & 0xFFFFFFFF ) );
        temp_282 = temp_284 - temp_282;
        temp_256 = ( size_t )( ( size_t )( ( temp_282 ) & 0xFFFFFFFF ) );
        *temp_283 = temp_282;
        *temp_285 = temp_284;
        *temp_257 = temp_256;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L492:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_263 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_267 = ( bool * )(temp_250);
        temp_262 = *temp_263;
        temp_260 = ( bool )( temp_262 == 0 );
        temp_266 = (bool)temp_260;
        *temp_261 = temp_260;
        *temp_267 = temp_266;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L494:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_283 = ( unsigned int * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_260 = *temp_261;
        temp_256 = *temp_257;
        temp_282 = ( unsigned int )(temp_256);
        *temp_283 = temp_282;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_260);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L496:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_259 = ( void ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_283 = ( unsigned int * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_260 = *temp_261;
        temp_282 = *temp_283;
        temp_258 = ( void * )(temp_282);
        *temp_259 = temp_258;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_260);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L498:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_269 = ( unsigned OMNI__INT64 * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_283 = ( unsigned int * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_281 = ( unsigned OMNI__INT64 * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_260 = *temp_261;
        temp_282 = *temp_283;
        temp_268 = ( unsigned OMNI__INT64 )(temp_282);
        temp_280 = ( unsigned OMNI__INT64 )(temp_260);
        *temp_269 = temp_268;
        *temp_281 = temp_280;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L500:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_263 = ( bool * )(temp_250);
        temp_262 = *temp_263;
        temp_264 = *temp_265;
        temp_260 = ( bool )( size_t )(temp_264);
        *temp_261 = temp_260;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_262);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L502:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_277 = ( int * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_276 = ( int )printf( ( char const * )temp_111 );
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_264 = ( OMNI_GLOBAL_SCOPE LinkedStack * )( ( size_t )( ( temp_248 ) & 0xFFFFFFFF ) );
        *temp_277 = temp_276;
        *temp_265 = temp_264;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L504:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_263 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_269 = ( unsigned OMNI__INT64 * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_281 = ( unsigned OMNI__INT64 * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_287 = ( unsigned OMNI__INT64 * )(temp_250);
        temp_286 = *temp_287;
        temp_280 = *temp_281;
        temp_262 = *temp_263;
        temp_260 = (bool)temp_262;
        temp_268 = temp_280 ^ temp_286;
        *temp_261 = temp_260;
        *temp_269 = temp_268;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L506:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_261 = ( bool * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_265 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_289 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_283 = ( unsigned int * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_263 = ( bool * )(temp_250);
        temp_262 = *temp_263;
        temp_288 = *temp_289;
        temp_264 = *temp_265;
        temp_260 = temp_264 != temp_288;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_282 = ( unsigned int )( ( size_t )( ( temp_248 ) & 0xFFFFFFFF ) );
        *temp_261 = temp_260;
        *temp_283 = temp_282;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = ( unsigned int )(temp_262);
        temp_248 = temp_248 * temp_249;
        temp_101 = temp_101 + temp_248;
        goto L344;
        
        L508:
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_257 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_271 = ( size_t * )(temp_250);
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_250 = temp_243[ temp_248 ];
        temp_273 = ( size_t * )(temp_250);
        temp_272 = *temp_273;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_256 = ( size_t )( ( size_t )( ( temp_248 ) & 0xFFFFFFFF ) );
        temp_270 = temp_256 - temp_272;
        *temp_257 = temp_256;
        *temp_271 = temp_270;
        temp_248 = omni_virtualcode_252[ temp_253 ];
        temp_253 = temp_253 + temp_247;
        temp_249 = omni_virtualcode_252[ temp_254 ];
        temp_254 = temp_254 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_249 = omni_virtualcode_252[ temp_255 ];
        temp_255 = temp_255 + temp_247;
        temp_248 = temp_248 ^ temp_249;
        temp_101 = (unsigned int)temp_248;
        goto L344;
        
        L510:
        temp_248 = (unsigned int)4294967136u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)157u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967264u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1134u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_110);
        temp_195 = (unsigned int)1812u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3195u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L512:
        temp_137 = ( size_t )( size_t )(temp_140);
        temp_248 = (unsigned int)365u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967293u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)61u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1960u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)3681u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)157u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L514:
        temp_139 = ( size_t )( size_t )(temp_129);
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)116547549u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)116547116u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966792u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)12u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)230u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3070u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L516:
        temp_124 = ( OMNI_GLOBAL_SCOPE LinkedStack * )(temp_138);
        temp_248 = (unsigned int)287u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967176u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)221u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2130u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L518:
        temp_248 = (unsigned int)4294967180u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967283u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294966867u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)361u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)1480u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1751u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L520:
        temp_119 = ( size_t )( size_t )(temp_124);
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)7u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)34u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967258u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294966897u;
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)4294966768u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)1u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)168u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2690u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)813u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)136u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L522:
        temp_114 = ( unsigned int )(temp_122);
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)296738845u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294966877u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967177u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)54u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)969u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3000u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L524:
        temp_114 = ( unsigned int )( size_t )(temp_140);
        temp_248 = (unsigned int)470u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967134u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967004u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)509u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L526:
        temp_248 = (unsigned int)113u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)75u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967289u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2000u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)198u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)80u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L528:
        temp_248 = (unsigned int)274u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)393861947u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967238u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967167u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)2u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)111u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L530:
        temp_248 = (unsigned int)300u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)40u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967177u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)555u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L532:
        temp_248 = (unsigned int)325u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)1u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)7u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967219u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1873u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L534:
        temp_248 = (unsigned int)87u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294966915u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)212375018u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967036u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1792u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L536:
        temp_248 = (unsigned int)4294967256u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967256u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967256u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1504u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L538:
        temp_248 = (unsigned int)103u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)391u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967151u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1892u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L540:
        temp_248 = (unsigned int)116u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_103);
        temp_195 = (unsigned int)16u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)296u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)17u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)75u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1284u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L542:
        temp_248 = (unsigned int)80u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)261u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)95u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2261u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L544:
        temp_248 = (unsigned int)4294967098u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)342u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)119u;
        temp_255 = temp_255 + temp_248;
        temp_248 = (unsigned int)2u;
        temp_249 = (unsigned int)0u;
        temp_248 = temp_248 & temp_253;
        temp_251 = temp_248 != temp_249;
        temp_196 = (unsigned int)2802u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_251);
        temp_195 = (unsigned int)3125u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)588u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L546:
        temp_248 = (unsigned int)40u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)6u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)29u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)273u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)1335u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L548:
        temp_248 = (unsigned int)333u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967038u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967270u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)894u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2343u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L550:
        temp_248 = (unsigned int)159u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967083u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)26u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)228u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)3273u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L552:
        temp_248 = (unsigned int)301u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)94u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)189u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294966970u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)489u;
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L554:
        temp_248 = (unsigned int)57u;
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)1717900301u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1717900152u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967073u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_104);
        temp_195 = (unsigned int)34u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2076u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L556:
        temp_248 = (unsigned int)166u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)454u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967214u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)311u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L558:
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)275437230u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)275437098u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967013u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967260u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)2651u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)5862u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L560:
        temp_248 = (unsigned int)4294967127u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967220u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967183u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)1664u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2199u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L562:
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)100017542u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967092u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)34u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)336u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)47u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)113u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)18u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)453u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L564:
        temp_248 = (unsigned int)62u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)62u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)62u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)24u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L566:
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)15u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)4294967243u;
        temp_194 = temp_195 - temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967048u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)31u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)250u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)378u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L568:
        temp_248 = (unsigned int)219u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967070u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)158u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)941u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L570:
        temp_248 = (unsigned int)279u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967130u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)218u;
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)2233u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L572:
        temp_248 = (unsigned int)4294967286u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)4294967286u;
        temp_254 = temp_254 + temp_248;
        temp_248 = (unsigned int)4294967286u;
        temp_255 = temp_255 + temp_248;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)31u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)310u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L574:
        temp_248 = (unsigned int)4294967082u;
        temp_253 = temp_253 + temp_248;
        temp_248 = (unsigned int)326u;
        temp_254 = temp_254 + temp_248;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)19u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)84u;
        temp_194 = temp_195 + temp_194;
        temp_248 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_255 = temp_255 + temp_248;
        temp_196 = (unsigned int)5u;
        temp_101 = temp_101 - temp_196;
        goto L344;
        
        L576:
        temp_196 = (unsigned int)3476u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)2138u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2256u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L578:
        temp_196 = (unsigned int)250u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)512u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1545u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L580:
        temp_196 = (unsigned int)1079u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)3224u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3742u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L582:
        temp_196 = (unsigned int)2139u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)2040u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3256u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L584:
        temp_196 = (unsigned int)3863u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)2000u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2311u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L586:
        temp_196 = (unsigned int)856u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)705u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2026u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L588:
        temp_196 = (unsigned int)1268u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_102);
        temp_195 = (unsigned int)58u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1121u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L590:
        temp_196 = (unsigned int)3440u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)2609u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)5u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L592:
        temp_196 = (unsigned int)274u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)1933u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1943u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L594:
        temp_196 = (unsigned int)3519u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)817u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1479u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L596:
        temp_196 = (unsigned int)180u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1770u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)184u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L598:
        temp_196 = (unsigned int)2938u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)715u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1153u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L600:
        temp_196 = (unsigned int)1098u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)274u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)95u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L602:
        temp_196 = (unsigned int)2468u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)963u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1216u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L604:
        temp_196 = (unsigned int)265u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)138u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1657u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L606:
        temp_196 = (unsigned int)3106u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)3736u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3923u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L608:
        temp_196 = (unsigned int)527u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)2979u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3460u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L610:
        temp_196 = (unsigned int)630u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)366u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)211u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L612:
        temp_196 = (unsigned int)2792u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)751u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1848u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L614:
        temp_196 = (unsigned int)978u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1091u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)846u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L616:
        temp_196 = (unsigned int)2273u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_108);
        temp_195 = (unsigned int)378u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1376u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L618:
        temp_196 = (unsigned int)1701u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)137u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2127u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L620:
        temp_196 = (unsigned int)645u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1278u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)1719u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L622:
        temp_196 = (unsigned int)805u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)450u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)788u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L624:
        temp_196 = (unsigned int)2682u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_109);
        temp_195 = (unsigned int)480u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)58u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L626:
        temp_196 = (unsigned int)1247u;
        temp_101 = temp_101 + temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)423u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)872u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L628:
        temp_196 = (unsigned int)1454u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1865u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)327u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L630:
        temp_196 = (unsigned int)993u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1323u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2185u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L632:
        temp_196 = (unsigned int)3370u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)2820u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)899u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L634:
        temp_196 = (unsigned int)1145u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_107);
        temp_195 = (unsigned int)1377u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)9u;
        temp_194 = temp_195 + temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L636:
        temp_196 = (unsigned int)2746u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)775u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2956u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L638:
        temp_196 = (unsigned int)560u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)1075u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3313u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L640:
        temp_196 = (unsigned int)2515u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_105);
        temp_195 = (unsigned int)3349u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)3467u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
        L642:
        temp_196 = (unsigned int)1167u;
        temp_101 = temp_101 - temp_196;
        temp_194 = ( unsigned int )(temp_106);
        temp_195 = (unsigned int)350u;
        temp_194 = temp_194 * temp_195;
        temp_195 = (unsigned int)2022u;
        temp_194 = temp_195 - temp_194;
        temp_196 = ( unsigned int )( ( size_t )( ( temp_194 ) & 0xFFFFFFFF ) );
        temp_101 = temp_101 + temp_196;
        goto L344;
        
    }

    #ifdef __cplusplus
    catch( ... )
    {
        
        L351:
        L350:
        temp_183 = ( unsigned int * )(temp_142);
        *temp_183 = temp_101;
        temp_184 = ( unsigned char * )(temp_143);
        *temp_184 = temp_102;
        temp_184 = ( unsigned char * )(temp_144);
        *temp_184 = temp_103;
        temp_184 = ( unsigned char * )(temp_145);
        *temp_184 = temp_104;
        temp_184 = ( unsigned char * )(temp_146);
        *temp_184 = temp_105;
        temp_184 = ( unsigned char * )(temp_147);
        *temp_184 = temp_106;
        temp_184 = ( unsigned char * )(temp_148);
        *temp_184 = temp_107;
        temp_184 = ( unsigned char * )(temp_149);
        *temp_184 = temp_108;
        temp_184 = ( unsigned char * )(temp_150);
        *temp_184 = temp_109;
        temp_184 = ( unsigned char * )(temp_151);
        *temp_184 = temp_110;
        temp_183 = ( unsigned int * )(temp_153);
        *temp_183 = temp_112;
        temp_183 = ( unsigned int * )(temp_154);
        *temp_183 = temp_113;
        temp_183 = ( unsigned int * )(temp_155);
        *temp_183 = temp_114;
        temp_183 = ( unsigned int * )(temp_156);
        *temp_183 = temp_115;
        temp_183 = ( unsigned int * )(temp_157);
        *temp_183 = temp_116;
        temp_184 = ( unsigned char * )(temp_158);
        *temp_184 = temp_117;
        temp_184 = ( unsigned char * )(temp_159);
        *temp_184 = temp_118;
        temp_188 = ( size_t * )(temp_160);
        *temp_188 = temp_119;
        temp_189 = ( unsigned OMNI__INT64 * )(temp_161);
        *temp_189 = temp_120;
        temp_189 = ( unsigned OMNI__INT64 * )(temp_162);
        *temp_189 = temp_121;
        temp_189 = ( unsigned OMNI__INT64 * )(temp_163);
        *temp_189 = temp_122;
        temp_189 = ( unsigned OMNI__INT64 * )(temp_164);
        *temp_189 = temp_123;
        temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_165);
        *temp_190 = temp_124;
        temp_191 = ( void ** )(temp_166);
        *temp_191 = temp_125;
        temp_192 = ( int * )(temp_167);
        *temp_192 = temp_126;
        temp_189 = ( unsigned OMNI__INT64 * )(temp_168);
        *temp_189 = temp_127;
        temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_169);
        *temp_190 = temp_128;
        temp_191 = ( void ** )(temp_170);
        *temp_191 = temp_129;
        temp_188 = ( size_t * )(temp_171);
        *temp_188 = temp_130;
        temp_188 = ( size_t * )(temp_172);
        *temp_188 = temp_131;
        temp_188 = ( size_t * )(temp_173);
        *temp_188 = temp_132;
        temp_188 = ( size_t * )(temp_174);
        *temp_188 = temp_133;
        temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_175);
        *temp_190 = temp_134;
        temp_192 = ( int * )(temp_176);
        *temp_192 = temp_135;
        temp_189 = ( unsigned OMNI__INT64 * )(temp_177);
        *temp_189 = temp_136;
        temp_188 = ( size_t * )(temp_178);
        *temp_188 = temp_137;
        temp_188 = ( size_t * )(temp_179);
        *temp_188 = temp_138;
        temp_188 = ( size_t * )(temp_180);
        *temp_188 = temp_139;
        temp_191 = ( void ** )(temp_181);
        *temp_191 = temp_140;
        temp_190 = ( OMNI_GLOBAL_SCOPE LinkedStack ** )(temp_182);
        *temp_190 = temp_141;
        throw ;
        
    }

    #endif
}

