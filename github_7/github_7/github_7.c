#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"


int main()
{
	Queue plist;
	QueueInit(&plist);
	//���
	printf("��ʼ���:\n");
	QueuePush(&plist, 1);
	QueuePush(&plist, 2);
	QueuePush(&plist, 3);
	QueuePush(&plist, 4);

	printf("��������ЧԪ�ظ���Ϊ��%d", QueueSize(&plist));
	printf("\n");
	printf("\n");

	//����
	printf("��ʼ����:\n");
	while (!QueueEmpty(&plist))
	{
		printf("%d ", QueueFront(&plist));
		QueuePop(&plist);
	}
	printf("\n");
	printf("�������\n");
	printf("\n");
	printf("��������ЧԪ�ظ���Ϊ��%d", QueueSize(&plist));
	printf("\n");
	return 0;
}