#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"
//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//���е�����
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//��β���
void QueuePush(Queue* pq, QDatatype x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	//���ÿջ�ָ��һ������ĵ�ַ�ͱ���
	if (pq->head == NULL)
	{
		assert(pq->tail == NULL);
		//�������һ����Ϊ�գ��ͱ���,��Ϊ���������ͷΪ�գ�β�ǿ�
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

//��ͷ����
void QueuePop(Queue* pq)
{
	assert(pq);
	//1,����Ϊ�գ��ı�ͷ��β
	//2�����в�Ϊ�գ��ı�ͷ
	assert(pq->head && pq->tail);//��ֹ����Ϊ��

	//ֻ��һ�����
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		//������
		QNode* cur = pq->head->next;
		free(pq->head);
		pq->head = cur;
	}
	pq->size--;
}

//���ʶ���ͷ��Ԫ��
QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

//��ȡ����β��Ԫ��
QDatatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

//�ж϶����Ƿ�Ϊ��,Ϊ�շ��ط�0����Ϊ�շ���0
int  QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}