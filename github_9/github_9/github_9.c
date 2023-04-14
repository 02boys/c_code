#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

/*
	项目名称：循环队列
	项目时间：4-13
	项目作者：逆风微笑的代码狗
*/
typedef int SLDataType;

//表示队列
typedef struct Queuenode
{
	SLDataType* data;
	int front;//队头指针
	int rear;//队尾指针

}QNode;
//初始化队列
void initQueue(SqQueue& Q) {
	Q.base = (int*)malloc(queueSize * sizeof(int)); //分配队列长度个存储空间
	Q.front = Q.rear = 0; //队头、队尾指向起始空间 
}

//数据元素入队列
void createQueue(SqQueue& Q, int e) {
	if ((Q.rear + 1) % queueSize == Q.front) {
		printf("当前队列元素满了，无法再输入\n");
	}
	Q.base[Q.rear] = e; //插入数据元素 
	Q.rear = (Q.rear + 1) % queueSize; //队尾指针后移一位 
}

//求当前队列长度
int queueLength(SqQueue Q) {
	return (Q.rear - Q.front + queueSize) % queueSize;
}

//数据元素出队列
int deleteQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) {
		printf("队列为空，已无数据元素\n\n");
	}
	e = Q.base[Q.front]; //删除并由e返回数据元素 
	Q.front = (Q.front + 1) % queueSize; //队头指针后移一位 
	return e;
}

//输出队列中的数据元素 
void printQueue(SqQueue Q) {
	while (Q.rear != Q.front) {
		printf("%d ", Q.base[Q.front]); //从队头到队尾输出队列中元素 
		Q.front = (Q.front + 1) % queueSize;
	}

}

int main() {
	SqQueue Q;
	int e, n, choose;
	initQueue(Q);
	printf("选择操作：0-退出，1-入队列，2-出队列，3-输出验证\n");
	scanf("%d", &choose);
	while (choose != 0) {
		switch (choose) {
		case 1: {
			printf("请输入数据元素：\n");
			scanf("%d", &e);
			createQueue(Q, e);
			printf("\n");//换行 
			break;
		}
		case 2: {
			n = 1; //传入数据元素输出载体 
			printf("%d\n", deleteQueue(Q, n));
			break;
		}
		case 3: {
			printQueue(Q);
			printf("\n当前队列长度为：%d", queueLength(Q));
			break;
		}

		}
		scanf("%d", &choose);//读取选择
	}
}
