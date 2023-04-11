#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDatatype;
//��ʾ����
typedef struct QueueNode
{
	struct QueueNode* next;
	QDatatype data;
}QNode;

//���еĽṹ
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;//Ԫ�ظ���
}Queue;


//��ʼ��
void QueueInit(Queue* pq);
//���е�����
void QueueDestroy(Queue* pq);
//��β���
void QueuePush(Queue* pq, QDatatype x);
//��ͷ����
void QueuePop(Queue* pq);
//��ȡ����ͷ��Ԫ��    ���б���֧���Ƚ��ȳ�
QDatatype QueueFront(Queue* pq);
//��ȡ��βԪ��
QDatatype QueueBack(Queue* pq);
//�ж϶����Ƿ�Ϊ��,Ϊ�շ��ط�0����Ϊ�շ���0
int QueueEmpty(Queue* pq);
//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);

