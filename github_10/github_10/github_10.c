#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXSIZE 10 //������󳤶�
typedef int QueueElemenType;


typedef struct 
{
	QueueElemenType data[MAXSIZE];//���пռ�
	int front;//��ͷָ��
	int rear;//��βָ��

}SeqQueue;

//��ʼ��
SeqQueue* InitQueue() 
{
	//��ʼһ���յ�ѭ������
	SeqQueue* Q;
	SeqQueue* ptr;

	//Q = (SeqQueue*)malloc(sizeof(SeqQueue));
	//��д������ɶԿ�ָ������þ���

	ptr = (SeqQueue*)malloc(sizeof(SeqQueue));
	if (ptr == NULL) 
	{
		perror("malloc fail");
		return;
	}
	Q = ptr;
	Q->front = Q->rear = 0;//��ָ��0Ϊ��
	return Q;
}

//ѭ�����
void EnterQueue(SeqQueue* Q,QueueElemenType x) 
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) //����һ���ռ�
	{
		printf("ѭ����������\n");
	}
	else 
	{
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MAXSIZE;
	}
}

//ѭ������
void DeleteQueue(SeqQueue* Q) 
{
	if (Q->front == Q->rear) 
	{
		printf("����Ϊ��\n");
	}
	else 
	{
		Q->front = (Q->front + 1) % MAXSIZE;
	}
}

//ѭ��������ʾ
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
		printf("��ǰ��ѭ���������£�����->��β����\n");
		DisplayQueue(Q);
		printf("\n------------------------------------\n");
		printf("         Main Menu         \n");
		printf("    1   ����    \n");
		printf("    2   ����   \n");
		printf("    3   ����   \n");
		printf("    0   ��������   \n");
		printf("------------------------------------\n");
		printf("��������ѡ��Ĳ˵���<1, 2, 3, 0>:\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("���������Ԫ�أ�");
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
			printf("��������\n");
			break;
		}
	}
	return 0;
}