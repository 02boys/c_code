#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//初始化顺序表
void SeqListInit(SL* psl) 
{
	assert(psl);

	//开辟默认大小的空间并初始化
	psl->data = (SLDataType*)calloc(DEF_SIZE,sizeof(SLDataType));

	//防止指针扩容失败
	if (psl == NULL) 
	{
		perror("calloc fail");
		return;
	}
	psl->size = 0;
	psl->capicity = DEF_SIZE;
}

//销毁顺序表
void SeqLsitDestory(SL* psl) 
{
	assert(psl);
	free(psl->data);   //避免内存泄漏
	psl->data = NULL;  //防止野指针
	psl->size = 0;
	psl->capicity = 0;
}

//检查容量
void CheckCapicity(SL* psl) 
{
	assert(psl);
	if (psl->capicity = DEF_SIZE) 
	{
		SLDataType* ret = (SLDataType*)realloc(psl->data, psl->capicity * sizeof(SLDataType) * CRE_SIZE);
		if (ret == NULL) 
		{
			perror("realloc fail");
			return;
		}
		psl->data = ret;
		psl->capicity *= CRE_SIZE;//2倍扩容
	}
}

//尾插
void SeqListpushBack(SL* psl, SLDataType x) 
{

	assert(psl);
	CheckCapicity(psl);
	psl->data[psl->size] = x;
	++psl->size;

}

//尾删
void SeqListpopBack(SL* psl) 
{
	assert(psl);
	assert(psl->size > 0);
	--psl->size;

}

//打印
void SeqListprint(SL* psl) 
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++) 
	{
		printf("%d ", psl->data[i]);
	}
}

//头插
void SeqListpushFront(SL* psl, SLDataType x) 
{
	assert(psl);
	CheckCapicity(psl);
	int i = 0;
	for (i = psl->size - 1; i >= 0; i--) 
	{
		psl->data[i + 1] = psl->data[i];
	}
	psl->data[0] = x;
	++psl->size;
}

//头删
void SeqListpopFront(SL* psl) 
{
	assert(psl);
	assert(psl->size > 0);
	int i = 0;
	for (i = 0; i < psl->size - 1; i++) 
	{
		psl->data[i] = psl->data[i + 1];
	}
	--psl->size;
}

//查找指定数据
int SeqListFind(SL* psl, SLDataType x)
{
	assert(psl);
	assert(psl->size > 0);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->data[i] == x)
		{
			//printf("找到了,位置是:%d\n", i + 1);
			return 1;
		}
	}
	return -1;
}

//在指定位置插入数据
void SeqListInset(SL* psl, size_t pos, SLDataType x) 
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);//检查下标的合法性
	CheckCapicity(psl);

	size_t i = 0;
	for (i = psl->size; i > pos; i--) 
	{
		psl->data[i] = psl->data[i-1];
	}
	psl->data[pos] = x;
	++psl->size;

}

//在指定位置删除数据
void SeqListErase(SL* psl, size_t pos) 
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);
	assert(psl->size > 0);//判空

	size_t i = 0;
	for (i = pos; i < psl->size-1; i++) 
	{
		psl->data[i] = psl->data[i + 1];
	}
	--psl->size;
}