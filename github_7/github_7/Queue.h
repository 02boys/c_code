#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDatatype;
//表示队列
typedef struct QueueNode
{
	struct QueueNode* next;
	QDatatype data;
}QNode;

//队列的结构
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;//元素个数
}Queue;


//初始化
void QueueInit(Queue* pq);
//队列的销毁
void QueueDestroy(Queue* pq);
//队尾入队
void QueuePush(Queue* pq, QDatatype x);
//队头出队
void QueuePop(Queue* pq);
//获取队列头部元素    队列必须支持先进先出
QDatatype QueueFront(Queue* pq);
//获取队尾元素
QDatatype QueueBack(Queue* pq);
//判断队列是否为空,为空返回非0，不为空返回0
int QueueEmpty(Queue* pq);
//获取队列中有效元素个数
int QueueSize(Queue* pq);

