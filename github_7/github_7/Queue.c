#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//队列的销毁
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

//队尾入队
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
	//不置空会指向一块随机的地址就报错
	if (pq->head == NULL)
	{
		assert(pq->tail == NULL);
		//如果其中一个不为空，就报错,因为不可能你的头为空，尾非空
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

//队头出队
void QueuePop(Queue* pq)
{
	assert(pq);
	//1,队列为空，改变头和尾
	//2，队列不为空，改变头
	assert(pq->head && pq->tail);//防止队列为空

	//只有一个结点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		//多个结点
		QNode* cur = pq->head->next;
		free(pq->head);
		pq->head = cur;
	}
	pq->size--;
}

//访问队列头部元素
QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

//获取队列尾部元素
QDatatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}

//获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

//判断队列是否为空,为空返回非0，不为空返回0
int  QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}