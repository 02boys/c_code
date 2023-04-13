#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//��ʼ��˳���
void SeqListInit(SL* psl) 
{
	assert(psl);

	//����Ĭ�ϴ�С�Ŀռ䲢��ʼ��
	psl->data = (SLDataType*)calloc(DEF_SIZE,sizeof(SLDataType));

	//��ָֹ������ʧ��
	if (psl == NULL) 
	{
		perror("calloc fail");
		return;
	}
	psl->size = 0;
	psl->capicity = DEF_SIZE;
}

//����˳���
void SeqLsitDestory(SL* psl) 
{
	assert(psl);
	free(psl->data);   //�����ڴ�й©
	psl->data = NULL;  //��ֹҰָ��
	psl->size = 0;
	psl->capicity = 0;
}

//�������
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
		psl->capicity *= CRE_SIZE;//2������
	}
}

//β��
void SeqListpushBack(SL* psl, SLDataType x) 
{

	assert(psl);
	CheckCapicity(psl);
	psl->data[psl->size] = x;
	++psl->size;

}

//βɾ
void SeqListpopBack(SL* psl) 
{
	assert(psl);
	assert(psl->size > 0);
	--psl->size;

}

//��ӡ
void SeqListprint(SL* psl) 
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++) 
	{
		printf("%d ", psl->data[i]);
	}
}

//ͷ��
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

//ͷɾ
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

//����ָ������
int SeqListFind(SL* psl, SLDataType x)
{
	assert(psl);
	assert(psl->size > 0);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->data[i] == x)
		{
			//printf("�ҵ���,λ����:%d\n", i + 1);
			return 1;
		}
	}
	return -1;
}

//��ָ��λ�ò�������
void SeqListInset(SL* psl, size_t pos, SLDataType x) 
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);//����±�ĺϷ���
	CheckCapicity(psl);

	size_t i = 0;
	for (i = psl->size; i > pos; i--) 
	{
		psl->data[i] = psl->data[i-1];
	}
	psl->data[pos] = x;
	++psl->size;

}

//��ָ��λ��ɾ������
void SeqListErase(SL* psl, size_t pos) 
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);
	assert(psl->size > 0);//�п�

	size_t i = 0;
	for (i = pos; i < psl->size-1; i++) 
	{
		psl->data[i] = psl->data[i + 1];
	}
	--psl->size;
}