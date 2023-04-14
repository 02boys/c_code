#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

/*
	��Ŀ���ƣ�ѭ������
	��Ŀʱ�䣺4-13
	��Ŀ���ߣ����΢Ц�Ĵ��빷
*/
typedef int SLDataType;

//��ʾ����
typedef struct Queuenode
{
	SLDataType* data;
	int front;//��ͷָ��
	int rear;//��βָ��

}QNode;
//��ʼ������
void initQueue(SqQueue& Q) {
	Q.base = (int*)malloc(queueSize * sizeof(int)); //������г��ȸ��洢�ռ�
	Q.front = Q.rear = 0; //��ͷ����βָ����ʼ�ռ� 
}

//����Ԫ�������
void createQueue(SqQueue& Q, int e) {
	if ((Q.rear + 1) % queueSize == Q.front) {
		printf("��ǰ����Ԫ�����ˣ��޷�������\n");
	}
	Q.base[Q.rear] = e; //��������Ԫ�� 
	Q.rear = (Q.rear + 1) % queueSize; //��βָ�����һλ 
}

//��ǰ���г���
int queueLength(SqQueue Q) {
	return (Q.rear - Q.front + queueSize) % queueSize;
}

//����Ԫ�س�����
int deleteQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) {
		printf("����Ϊ�գ���������Ԫ��\n\n");
	}
	e = Q.base[Q.front]; //ɾ������e��������Ԫ�� 
	Q.front = (Q.front + 1) % queueSize; //��ͷָ�����һλ 
	return e;
}

//��������е�����Ԫ�� 
void printQueue(SqQueue Q) {
	while (Q.rear != Q.front) {
		printf("%d ", Q.base[Q.front]); //�Ӷ�ͷ����β���������Ԫ�� 
		Q.front = (Q.front + 1) % queueSize;
	}

}

int main() {
	SqQueue Q;
	int e, n, choose;
	initQueue(Q);
	printf("ѡ�������0-�˳���1-����У�2-�����У�3-�����֤\n");
	scanf("%d", &choose);
	while (choose != 0) {
		switch (choose) {
		case 1: {
			printf("����������Ԫ�أ�\n");
			scanf("%d", &e);
			createQueue(Q, e);
			printf("\n");//���� 
			break;
		}
		case 2: {
			n = 1; //��������Ԫ��������� 
			printf("%d\n", deleteQueue(Q, n));
			break;
		}
		case 3: {
			printQueue(Q);
			printf("\n��ǰ���г���Ϊ��%d", queueLength(Q));
			break;
		}

		}
		scanf("%d", &choose);//��ȡѡ��
	}
}
