#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

int main() 
{
	SL sl;
	SeqListInit(&sl);
	SeqListpushBack(&sl, 1);
	SeqListpushBack(&sl, 2);
	SeqListpushBack(&sl, 3);
	SeqListpushBack(&sl, 4);
	SeqListpushBack(&sl, 5);
	SeqListprint(&sl);
	printf("\n");
	SeqListpopBack(&sl);
	SeqListpopBack(&sl);
	SeqListpushFront(&sl, 100);
	//SeqListpopFront(&sl);
	//SeqListpopFront(&sl);
	//SeqListpopFront(&sl);
	//SeqListpopFront(&sl);
	SeqListprint(&sl);
	printf("\n");
	//SeqListFind(&sl, 3);
	SeqListInset(&sl, 0, 7);
	SeqListprint(&sl);
	printf("\n");
	SeqListErase(&sl, 2);
	SeqListErase(&sl, 1);
	SeqListprint(&sl);
	printf("\n");
	SeqListErase(&sl, 1);
	SeqListErase(&sl, 2);
	SeqListprint(&sl);
	printf("\n");
	SeqListErase(&sl, 0);
	SeqListprint(&sl);

	return 0;
}