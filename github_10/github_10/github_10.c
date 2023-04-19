#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXSIZE 10 //队列最大长度
typedef int QueueElemenType;


typedef struct 
{
	QueueElemenType data[MAXSIZE];//队列空间
	int front;//对头指针
	int rear;//队尾指针

}SeqQueue;

//初始化
SeqQueue* InitQueue() 
{
	//初始一个空的循环队列
	SeqQueue* Q;
	SeqQueue* ptr;

	//Q = (SeqQueue*)malloc(sizeof(SeqQueue));
	//此写法会造成对空指针的引用警告

	ptr = (SeqQueue*)malloc(sizeof(SeqQueue));
	if (ptr == NULL) 
	{
		perror("malloc fail");
		return;
	}
	Q = ptr;
	Q->front = Q->rear = 0;//都指向0为空
	return Q;
}

//循环入队
void EnterQueue(SeqQueue* Q,QueueElemenType x) 
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) //牺牲一个空间
	{
		printf("循环队列已满\n");
	}
	else 
	{
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MAXSIZE;
	}
}

//循环出队
void DeleteQueue(SeqQueue* Q) 
{
	if (Q->front == Q->rear) 
	{
		printf("队列为空\n");
	}
	else 
	{
		Q->front = (Q->front + 1) % MAXSIZE;
	}
}

//循环队列显示
void DisplayQueue(SeqQueue* Q) 
{
	int i;
	for (i = Q->front; i != Q->rear; i = (i + 1) % MAXSIZE) 
	{
		printf("%d ", Q->data[i]);
	}
}
int main()
{
	SeqQueue* Q;
	Q = InitQueue();
	int a, i = 1, x;
	for (a = 1; a < 5; a++)
	{
		EnterQueue(Q, a);
	}
	system("cls");
	while (i) 
	{
		printf("当前的循环队列如下（队首->队尾）：\n");
		DisplayQueue(Q);
		printf("\n------------------------------------\n");
		printf("         Main Menu         \n");
		printf("    1   进队    \n");
		printf("    2   出队   \n");
		printf("    3   清屏   \n");
		printf("    0   结束程序   \n");
		printf("------------------------------------\n");
		printf("请输入你选择的菜单号<1, 2, 3, 0>:\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("请输入进队元素：");
			scanf("%d", &x);
			EnterQueue(Q, x);
			printf("\n\n");
			break;
		case 2:
			DeleteQueue(Q);
			printf("\n\n");
			break;
		case 3:
			system("cls");
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("输入有误\n");
			break;
		}
	}
	return 0;
}