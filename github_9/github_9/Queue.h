#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

#define QueueSize 7  //������г���

typedef int SLDataType;

//��ʾ����
typedef struct Queuenode 
{
	SLDataType* data;
	int front;//��ͷָ��
	int rear;//��βָ��

}QNode;
