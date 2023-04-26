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
//链式结构：表示队列

typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;

}QNode;


//队列结构
typedef struct Queue
{
	QNode* front;
	QNode* rear;

}Queue;



BTNode* CreateBTNode(BTDataType x);
//通过前序遍历的数组构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
//二叉树的销毁
void BinaryTreeDestory(BTNode** root);
//二叉树的结点个数
int BinaryTreeSize(BTNode* root);
//二叉树叶子结点个数
int BinaryTreeLeafSize(BTNode* root);
//二叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//二叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root);
//二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
//二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);


//初始化队列
void QueueInit(Queue* q);
//队尾入队
void QueuePush(Queue* q, QDataType data);
//对头出队
void QueuePop(Queue* q);
//获取队头元素
QDataType QueueFront(Queue* q);
//获取队尾元素
QDataType QueueBack(Queue* q);
//获取队列中有效元素个数
int QueueSize(Queue* q);
//检测队列是否为空
int QueueEmpty(Queue* q);
//销毁队列
void QueueDestory(Queue* q);


//层序遍历
void BinaryTreeLevelOrder(BTNode* root);
//判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
