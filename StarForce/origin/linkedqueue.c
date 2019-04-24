#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

typedef struct HeapElementType
{
	int key;
	char element;
} HeapNode;

typedef struct ArrayHeapType
{
	int maxElementCount;		// 최대 노드 개수
	int currentElementCount;	// 현재 노드 개수
	HeapNode *pElement;		// 노드 저장을 위한 1차원 array
} ArrayMaxHeap, ArrayMinHeap;

// 최대 히프의 생성
ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);

// 최대 히프의 삭제
void deleteArrayMaxHeap(ArrayMaxHeap* pArrayHeap);

// 최소 히프의 생성
ArrayMinHeap* createArrayMinHeap(int maxElementCount);

// 최소 히프의 삭제
void deleteArrayMinHeap(ArrayMinHeap* pArrayHeap);

// 최대 히프의 삽입
void insertMaxHeapAH(ArrayMaxHeap* pArrayHeap, HeapNode element);

// 최대 히프의 삭제
HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pArrayHeap);

// 최소 히프의 삽입
void insertMinHeapAH(ArrayMinHeap* pArrayHeap, HeapNode element);

// 최소 히프의 삭제
HeapNode* deleteMinHeapAH(ArrayMinHeap* pArrayHeap);

// 히프 정보 출력
void displayArrayHeap(ArrayMaxHeap* pList);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif

void printArray(int value[], int count);


// 최대 히프의 생성
ArrayMaxHeap* createArrayMaxHeap(int maxElementCount)
{
	ArrayMaxHeap *pReturn = NULL;
	int i = 0;

	// 최대 원소 개수 검증
	if (maxElementCount > 0) {
		pReturn = (ArrayMaxHeap *)malloc(sizeof(ArrayMaxHeap));

		// 메모리 할당 성공 검증
		if (pReturn != NULL) {
			// 최대 노드 개수, 현재 노드 개수, 배열 포인터 초기화.
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("Error, malloc() in createArrayList()\n");
			return NULL;
		}
	}
	else {
		printf("Max Element Count must be greater than 0\n");
		return NULL;
	}

	// 노드 저장을 위한 1차원 array 할당
	pReturn->pElement = (HeapNode *)malloc(sizeof(HeapNode) * (maxElementCount + 1));
	if (pReturn->pElement == NULL) {
		printf("Error, 2'nd malloc() in createArrayList()\n");
		return NULL;
	}

	// 노드 데이터 초기화.
	memset(pReturn->pElement, 0, sizeof(HeapNode) * (maxElementCount+1));

	return pReturn;
}

// 최대 히프의 삽입
void insertMaxHeapAH(ArrayMaxHeap* pHeap, HeapNode element)
{
	int i = 0;

	if (pHeap != NULL) {
		if (pHeap->currentElementCount ==  pHeap->maxElementCount) {
			printf("Error, heap is full [%d],insertMaxHeapAH()\n", 
				pHeap->maxElementCount);
			return;
		}
		
		pHeap->currentElementCount++;
		i =  pHeap->currentElementCount;
		while((i != 1) && (element.key > pHeap->pElement[i/2].key)) {
			pHeap->pElement[i] = pHeap->pElement[i/2];
			i /= 2;
		}
		pHeap->pElement[i] = element;
	}
}

// 최대 히프의 삭제
HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pHeap)
{
	HeapNode* pReturn = NULL;
	HeapNode* pTemp = NULL;

	int i = 0;
	int parent =0, child = 0;

	if (pHeap != NULL && pHeap->currentElementCount >  0) {
		pReturn = (HeapNode*)malloc(sizeof(HeapNode));
		if (pReturn == NULL) {
			printf("Error, malloc() in deleteMaxHeapAH()\n");
			return NULL;
		}
		*pReturn = pHeap->pElement[ 1 ];

		i =  pHeap->currentElementCount;
		pTemp = &(pHeap->pElement[ i ]);
		pHeap->currentElementCount--;

		parent = 1;
		child = 2;
		while(child <= pHeap->currentElementCount) {
			if ((child < pHeap->currentElementCount)
				&& pHeap->pElement[ child ].key < pHeap->pElement[ child+1 ].key) {
				child++;
			}
			if (pTemp->key >= pHeap->pElement[ child ].key) {
				break;
			}

			pHeap->pElement[ parent ] = pHeap->pElement[ child ];
			parent = child;
			child *= 2;
		}
		pHeap->pElement[ parent ] = *pTemp;
	}

	return pReturn;
}

// 최대 히프의 삭제
void deleteArrayMaxHeap(ArrayMaxHeap* pHeap)
{
	if (pHeap != NULL) {
		if (pHeap->pElement != NULL) {
			free(pHeap->pElement);
		}
		free(pHeap);
	}
}


// 최소 히프의 생성
ArrayMinHeap* createArrayMinHeap(int maxElementCount)
{
	return createArrayMaxHeap(maxElementCount);
}

// 최소 히프의 삭제
void deleteArrayMinHeap(ArrayMaxHeap* pHeap)
{
	deleteArrayMaxHeap(pHeap);
}

// 최소 히프의 삽입
void insertMinHeapAH(ArrayMinHeap* pHeap, HeapNode element)
{
	int i = 0;

	if (pHeap != NULL) {
		if (pHeap->currentElementCount ==  pHeap->maxElementCount) {
			printf("Error, heap is full [%d],insertMinHeapAH()\n", 
				pHeap->maxElementCount);
			return;
		}
		
		pHeap->currentElementCount++;
		i =  pHeap->currentElementCount;
		while((i != 1) && (element.key < pHeap->pElement[i/2].key)) {
			pHeap->pElement[i] = pHeap->pElement[i/2];
			i /= 2;
		}
		pHeap->pElement[i] = element;
	}
}

// 최소 히프의 삭제
HeapNode* deleteMinHeapAH(ArrayMinHeap* pHeap)
{
	HeapNode* pReturn = NULL;
	HeapNode* pTemp = NULL;

	int i = 0;
	int parent =0, child = 0;

	if (pHeap != NULL && pHeap->currentElementCount >  0) {
		pReturn = (HeapNode*)malloc(sizeof(HeapNode));
		if (pReturn == NULL) {
			printf("Error, malloc() in deleteMinHeapAH()\n");
			return NULL;
		}
		*pReturn = pHeap->pElement[ 1 ];

		i =  pHeap->currentElementCount;
		pTemp = &(pHeap->pElement[ i ]);
		pHeap->currentElementCount--;

		parent = 1;
		child = 2;
		while(child <= pHeap->currentElementCount) {
			if ((child < pHeap->currentElementCount)
				&& pHeap->pElement[ child ].key > pHeap->pElement[ child+1 ].key) {
				child++;
			}
			if (pTemp->key <= pHeap->pElement[ child ].key) {
				break;
			}

			pHeap->pElement[ parent ] = pHeap->pElement[ child ];
			parent = child;
			child *= 2;
		}
		pHeap->pElement[ parent ] = *pTemp;
	}

	return pReturn;
}

// 히프 정보 출력
void displayArrayHeap(ArrayMaxHeap* pHeap)
{
	int i = 0;
	if (pHeap != NULL) {
		for(i = 1; i <= pHeap->currentElementCount; i++) {
			printf("[%d],%d\n", i, pHeap->pElement[i]);
		}
	}
}

// 힙 정렬.
void heapSort(int value[], int count)
{
	int i = 0;
	ArrayMinHeap* pHeap = NULL;

	pHeap = createArrayMinHeap(8);
	if (pHeap != NULL) {
		HeapNode node;

		for(i = 0; i < count; i++) {
			node.key = value[i];
			insertMinHeapAH(pHeap, node);
		}

		for(i = 0; i < count; i++) {
			HeapNode *pNode = deleteMinHeapAH(pHeap);
			if (pNode != NULL) {
				value[i] = pNode->key;

				free(pNode);
			}
		}

		deleteArrayMinHeap(pHeap);
	}
	else {
		printf("오류, createArrayMinHeap() in heapSort()\n");
		return;
	}
}

int main(int argc, char *argv[])
{
	int values[] = {10, 50, 70, 80, 60, 20, 40, 30 };

	printf("Before Sort\n");
	printArray(values, 8);

	heapSort(values, 8);

	printf("After Sort\n");
	printArray(values, 8);

	return 0;
}

// 배열 내용 출력
void printArray(int value[], int count)
{
	int i = 0;
	for(i = 0; i < count; i++) {
		printf("%d ", value[i]);
	}
	printf("\n");
}

