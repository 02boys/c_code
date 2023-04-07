#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HeapDType;

typedef struct Heap
{
	HeapDType* val;
	int count;
	int capacity;
}Heap;

void HeapInti(Heap* pheap)
{
	assert(pheap);

	pheap->val = NULL;
	pheap->capacity = pheap->count = 0;
}

bool HeapEmpty(Heap* pheap)
{
	assert(pheap);
	return pheap->count == 0;
}

void HeapDestory(Heap* pheap)
{
	assert(pheap);
	free(pheap->val);
	pheap->val = NULL;
	pheap->capacity = pheap->count = 0;
}

void Swap(HeapDType* px, HeapDType* py)
{
	HeapDType tmp = *px;
	*px = *py;
	*py = tmp;
}

void AdjustTop(HeapDType* val, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (val[child] < val[parent])
		{
			Swap(&(val[child]), &(val[parent]));
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* pheap, HeapDType x)
{
	assert(pheap);
	if (pheap->count == pheap->capacity)
	{
		int newCapacity = pheap->capacity == 0 ? 4 : pheap->capacity * 2;
		HeapDType* tmp = (HeapDType*)realloc(pheap->val, sizeof(HeapDType) * newCapacity);
		if (NULL == tmp)
		{
			printf("realloc error\n");
			exit(-1);
		}
		pheap->capacity = newCapacity;
		pheap->val = tmp;
	}

	pheap->val[pheap->count++] = x;
	AdjustTop(pheap->val, pheap->count - 1);
}

void HeapPrint(Heap* pheap)
{
	assert(pheap);
	for (int i = 0; i < pheap->count; i++)
	{
		printf("%d ", pheap->val[i]);
	}
}

void AdjustDown(HeapDType* val, int size, int parent)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && val[child] > val[child + 1])
		{
			child++;
		}

		if (val[parent] > val[child] && child < size)
		{
			Swap(&val[parent], &val[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap* pheap)
{
	assert(pheap);

	if (!HeapEmpty(pheap))
	{
		Swap(&(pheap->val[0]), &(pheap->val[pheap->count - 1]));
		pheap->count--;
		AdjustDown(pheap->val, pheap->count, 0);
	}
}

HeapDType HeapTop(Heap* pheap)
{
	assert(pheap);
	assert(pheap->count > 0);
	return pheap->val[0];
}

int HeapSize(Heap* pheap)
{
	assert(pheap);
	return pheap->count;
}
