#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef char BTDataType;

typedef struct BinaryTreeNode 
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeBide* right;

}BTNode;


typedef BTNode* QDataType;
//��ʽ�ṹ����ʾ����

typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;

}QNode;


//���нṹ
typedef struct Queue
{
	QNode* front;
	QNode* rear;

}Queue;



BTNode* CreateBTNode(BTDataType x);
//ͨ��ǰ����������鹹��������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
//������������
void BinaryTreeDestory(BTNode** root);
//�������Ľ�����
int BinaryTreeSize(BTNode* root);
//������Ҷ�ӽ�����
int BinaryTreeLeafSize(BTNode* root);
//��������k�������
int BinaryTreeLevelKSize(BTNode* root, int k);
//����������ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//������ǰ�����
void BinaryTreePrevOrder(BTNode* root);
//�������������
void BinaryTreeInOrder(BTNode* root);
//�������������
void BinaryTreePostOrder(BTNode* root);


//��ʼ������
void QueueInit(Queue* q);
//��β���
void QueuePush(Queue* q, QDataType data);
//��ͷ����
void QueuePop(Queue* q);
//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q);
//��ȡ��βԪ��
QDataType QueueBack(Queue* q);
//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);
//�������Ƿ�Ϊ��
int QueueEmpty(Queue* q);
//���ٶ���
void QueueDestory(Queue* q);


//�������
void BinaryTreeLevelOrder(BTNode* root);
//�ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
