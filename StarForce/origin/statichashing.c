#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _STATIC_HASHING_
#define _STATIC_HASHING_

#define HASH_KEY_SIZE	30

typedef enum HashElementStatusType { EMPTY = 0, USED, DELETED  } HashElementStatus;

typedef struct HashElementType {
	char key[HASH_KEY_SIZE + 1];
	int value;
	HashElementStatus status;
} HashElement;

typedef struct HashTableType {
	int bucketSize;
	int currentElementCount;
	HashElement *pElement;
} HashTable;

// �ؽ� ���̺��� ����.
HashTable* createHashTable(int bucketSize);

// �ڷ��� �߰�.
int addElementSHT(HashTable* pHashTable, HashElement element);

// �ڷ��� ����.
int deleteElementHT(HashTable* pHashTable, char* key);

int hashFunction(char *pKey, int bucketSize);

unsigned int stringToInt(char *pKey);

int isEmptyBucket(HashElement* pElement);

int isEmptyOrDeletedBucket(HashElement* pElement);

// �ڷ��� �˻�.
HashElement* searchHT(HashTable* pHashTable, char* key);

// �ؽ� ���̺� ���� ǥ��.
void displayHashTable(HashTable *pHashTable);

// �ؽ� ���̺��� ���� �ڷ��� ����.
int getElementCountHT(HashTable *pHashTable);

// �ؽ� ���̺��� ����.
void deleteHashTable(HashTable *pHashTable);

#endif

#ifndef _COMMON_HASHING_DEF_
#define _COMMON_HASHING_DEF_

#define TRUE		1
#define FALSE		0

#endif

int main(int argc, char *argv[])
{
	HashTable *pHashTable = NULL;
	HashElement element1 = {"january", 1};
	HashElement element2 = {"february", 2};
	HashElement element3 = {"march", 3};
	HashElement element4 = {"april", 4};
	HashElement element5 = {"may", 5};
	HashElement element6 = {"june", 6};
	HashElement element7 = {"july", 7};
	HashElement element8 = {"august", 8};
	HashElement element9 = {"september", 9};
	HashElement element10 = {"october", 10};
	HashElement element11 = {"november", 11};
	HashElement element12 = {"december", 12};
	HashElement *pElement = NULL;
	HashElement *pElement2 = NULL;

	// �ؽ� ���̺� ����
	pHashTable = createHashTable(13);
	if (pHashTable != NULL)
	{
		addElementSHT(pHashTable, element1);
		addElementSHT(pHashTable, element2);
		addElementSHT(pHashTable, element3);
		addElementSHT(pHashTable, element4);
		addElementSHT(pHashTable, element5);
		addElementSHT(pHashTable, element6);
		addElementSHT(pHashTable, element7);
		addElementSHT(pHashTable, element8);
		addElementSHT(pHashTable, element9);
		addElementSHT(pHashTable, element10);
		addElementSHT(pHashTable, element11);
		addElementSHT(pHashTable, element12);

		printf("�ؽ� ���̺� ����:\n");
		displayHashTable(pHashTable);

		pElement = searchHT(pHashTable, "april");
		if (pElement != NULL) {
			printf("�˻�Ű-%s, �˻� ���-%d\n", pElement->key, pElement->value);

			deleteElementHT(pHashTable, "april");
			printf("�˻�Ű[%s]�� �ڷ� ����\n", "april");

			//printf("�ؽ� ���̺� ����:\n");
			//displayHashTable(pHashTable);

			pElement2 = searchHT(pHashTable, "april");
			if (pElement2 != NULL) {
				printf("�˻�Ű-%s, �˻� ���-%d\n", pElement2->key, pElement2->value);
			}

			pElement2 = searchHT(pHashTable, "june");
			if (pElement2 != NULL) {
				printf("�˻�Ű-%s, �˻� ���-%d\n", pElement2->key, pElement2->value);
			}
		}
		else {
			printf("Not found\n");
		}

		deleteHashTable(pHashTable);
	}

	return 0;
}

// �ؽ� ���̺��� ����.
HashTable* createHashTable(int bucketSize) {
	HashTable *pReturn = NULL;
	int i = 0;

	if (bucketSize <= 0) {
		printf("��Ŷ ũ��� 0���� Ŀ���մϴ�\n");
		return NULL;
	}

	pReturn = (HashTable *)malloc(sizeof(HashTable));
	if (pReturn != NULL) {
		pReturn->currentElementCount = 0;
		pReturn->bucketSize = bucketSize;
		pReturn->pElement = NULL;
	}
	else {
		printf("����, ù��° �޸��Ҵ�, createHashTable()\n");
		return NULL;
	}

	pReturn->pElement = (HashElement *)malloc(sizeof(HashElement) * bucketSize);
	if (pReturn->pElement != NULL) {
		memset(pReturn->pElement, 0, sizeof(HashElement) * bucketSize);
	}
	else {
		if (pReturn != NULL) free(pReturn);
		printf("����, �ι�° �޸��Ҵ�, createHashTable()\n");
		return NULL;
	}
	return pReturn;	
}

// �ڷ��� �߰�.
int addElementSHT(HashTable* pHashTable, HashElement element) {
	int ret = FALSE;
	HashElement *pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;

	if (pHashTable == NULL) {
		printf("����,NULL-�ؽ� ���̺��Դϴ�\n");
		ret = FALSE;
		return ret;
	}

	bucketIndex = hashFunction(element.key, pHashTable->bucketSize);
	if (bucketIndex < 0 || bucketIndex >= pHashTable->bucketSize) {
		printf("����, �߸��� �ؽ� ���̺� �ּҰ� ���Ǿ����ϴ�, addSHT()\n");
		ret = FALSE;
		return ret;
	}

	tempIndex = bucketIndex;

	do {
		pElement = &(pHashTable->pElement[tempIndex]);

		// 1) �� �ּ� Ȥ�� ������ �ּ����� ����.
		if (isEmptyOrDeletedBucket(pElement) == TRUE) {
			pHashTable->pElement[tempIndex] = element;
			pHashTable->pElement[tempIndex].status = USED;
			pHashTable->currentElementCount++;
			ret = TRUE;
			break;
		}
		else {	// 2) �� ������ ã�� ���� ���.
			// 2-1) ������ key�� �̹� �����ϴ� ���.
			if (strcmp(pElement->key, element.key) == 0) {
				printf("����, �ߺ��� Ű-[%s], addSHT()\n",
						element.key);
				ret = FALSE;
				break;
			}
			else { // 2-2) �������� �ʴ� key�� ���, ���� �������� �̵�.
				tempIndex = (tempIndex + inc) % pHashTable->bucketSize;

				// �ؽ� ���̺��� ��� ������ ��� �� ���.
				if (tempIndex == bucketIndex) {
					printf("����, �ؽ� ���̺��� ����á���ϴ�, addSHT()\n");
					ret = FALSE;
					break;
				}
			}					
		}
	}
	while(tempIndex != bucketIndex);

	return ret;
}

int hashFunction(char *pKey, int bucketSize) {
	int ret = -1;
	unsigned int temp_key = 0;

	if (pKey == NULL) {
		return ret;
	}

	temp_key = stringToInt(pKey);
	if (bucketSize > 0) {
		ret = temp_key % bucketSize;
	}

	return ret;
}

// ���ڿ��� ���ڷ� ��ȯ.
unsigned int stringToInt(char *pKey) {
	unsigned int ret = 0;
	while(*pKey != '\0') {
		ret = (ret * 31) + (*pKey);
		*pKey++;
	}
	if (ret < 0) {
		ret = ret * (-1);
	}

	return ret;
}

// �� �ּ� Ȥ�� ������ �ּ����� ����.
int isEmptyOrDeletedBucket(HashElement* pElement) {
	int ret = FALSE;

	if (pElement != NULL) {
		if (pElement->status == EMPTY
			|| pElement->status == DELETED) {
			ret = TRUE;
		}
	}

	return ret;
}

// �ڷ��� �˻�.
HashElement* searchHT(HashTable* pHashTable, char* key) {
	HashElement* pReturn = NULL;
	HashElement *pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;

	if (pHashTable == NULL) {
		printf("����,NULL-�ؽ� ���̺��Դϴ�\n");
		pReturn = NULL;
		return pReturn;
	}

	bucketIndex = hashFunction(key, pHashTable->bucketSize);
	if (bucketIndex < 0) {
		printf("����, �߸��� �ؽ� ���̺� �ּҰ� ���Ǿ����ϴ�, addSHT()\n");
		pReturn = NULL;
		return pReturn;
	}

	tempIndex = bucketIndex;

	do {
		pElement = &(pHashTable->pElement[tempIndex]);

		// 1) �� ������ ã�� ���. �˻� ����.
		if (isEmptyBucket(pElement) == TRUE) {
			printf("�˻� ����, �˻�Ű-[%s]�� �������� �ʽ��ϴ�, searchHT()\n", key);
			pReturn = NULL;
			break;
		}
		else {
			// 2-1) ������ key�� ã�� ���. �˻� ����.
			if (pElement->status == USED 
					&& strcmp(pElement->key, key) == 0) {
				pReturn = pElement;
				break;
			}
			else { // 2-2) �������� �ʴ� key�� ���, ���� �ּҷ� �̵�.
				tempIndex = (tempIndex + 1) % pHashTable->bucketSize;
				
				// �ؽ� ���̺��� ��� ������ �˻��� ���.
				if (tempIndex == bucketIndex) {
					printf("�˻� ����, �˻�Ű-[%s]�� �������� �ʽ��ϴ�, searchHT()\n", key);
					pReturn = NULL;
					break;
				}
			}					
		}
	}
	while(tempIndex != bucketIndex);

	return pReturn;
}

// �� �ּ����� ����.
int isEmptyBucket(HashElement* pElement) {
	int ret = FALSE;

	if (pElement != NULL) {
		if (pElement->status == EMPTY) {
			ret = TRUE;
		}
	}

	return ret;
}

// �ڷ��� ����.
int deleteElementHT(HashTable* pHashTable, char* key) {
	int ret = FALSE;
	HashElement *pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;

	if (pHashTable != NULL) {
		pElement = searchHT(pHashTable, key);
		if (pElement != NULL) {
			pElement->status = DELETED;
			pElement->key[0] = '\0';
			pElement->value = 0;
			pHashTable->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("���� ����, �˻�Ű-[%s]�� �������� �ʽ��ϴ�, deleteElementHT()\n", key);
		}
	}

	return ret;
}

// �ؽ� ���̺��� ����.
void deleteHashTable(HashTable *pHashTable) {
	int i = 0;
	if (pHashTable != NULL) {
		free(pHashTable->pElement);
	}
	free(pHashTable);
}

// �ؽ� ���̺��� ���� �ڷ��� ����.
int getElementCountHT(HashTable *pHashTable) {
	int ret = 0;

	if (pHashTable != NULL) {
		ret = pHashTable->currentElementCount;
	}

	return ret;
}

// �ؽ� ���̺� ���� ���.
void displayHashTable(HashTable *pHashTable) {
	int i = 0, j = 0;
	int bucketIndex = 0;

	HashElement *pElement = NULL;
	if (pHashTable != NULL) {
		printf("-----------------------------------------\n");

		for(i = 0; i < pHashTable->bucketSize; i++) {
			printf("[%d],", i);

			pElement = &(pHashTable->pElement[i]);
			if (pElement->key[0] != '\0') {
				bucketIndex = hashFunction(pElement->key, pHashTable->bucketSize);

				printf("%s, (%d->%d), [%d]\n", pElement->key, 
					bucketIndex, i,
					pElement->value);
			}
			else {
				printf("������ϴ�\n");
			}
		}

		printf("-----------------------------------------\n");
	}
	else {
		printf("NULL-�ؽ� ���̺��Դϴ�\n");
	}
}