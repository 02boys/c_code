#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

#define QueueSize 7  //定义队列长度

typedef int SLDataType;

//表示队列
typedef struct Queuenode 
{
	SLDataType* data;
	int front;//队头指针
	int rear;//队尾指针

}QNode;
