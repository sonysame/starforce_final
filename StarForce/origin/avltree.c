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


LinkedStack* createLinkedStack()
{
	LinkedStack *pReturn = NULL;
	int i = 0;
	pReturn = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedStack));
	}
	else {
		printf("오류, 메모리할당,createLinkedStack()\n");
		return NULL;
	}

	return pReturn;
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
