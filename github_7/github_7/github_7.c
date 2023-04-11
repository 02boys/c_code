#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"


int main()
{
	Queue plist;
	QueueInit(&plist);
	//入队
	printf("开始入队:\n");
	QueuePush(&plist, 1);
	QueuePush(&plist, 2);
	QueuePush(&plist, 3);
	QueuePush(&plist, 4);

	printf("队列中有效元素个数为：%d", QueueSize(&plist));
	printf("\n");
	printf("\n");

	//出队
	printf("开始出队:\n");
	while (!QueueEmpty(&plist))
	{
		printf("%d ", QueueFront(&plist));
		QueuePop(&plist);
	}
	printf("\n");
	printf("出队完成\n");
	printf("\n");
	printf("队列中有效元素个数为：%d", QueueSize(&plist));
	printf("\n");
	return 0;
}