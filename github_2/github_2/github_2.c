#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MaxSize 100

using namespace std;

typedef struct binarytreenode
{
    int data;
    struct binarytreenode* Lnode;
    struct binarytreenode* Rnode;
} BiTNode, * BiTree;

typedef struct queue {
    BiTree numQ[MaxSize];
    int front;
    int rear;
}Queue;

Queue Q;

void Q_initilize()
{
    Q.front = 0;
    Q.rear = 0;
}

void Q_Push(BiTree root)
{
    Q.numQ[++Q.rear] = root;
}

BiTree Q_Pop(BiTree root)
{
    return Q.numQ[++Q.front];
}

int Q_empty() { //判断对列是否为空
    return Q.rear == Q.front;
}

void CreateBiTree(BiTree* T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T) { return; }
        (*T)->data = ch;
        CreateBiTree(&(*T)->Lnode);
        CreateBiTree(&(*T)->Rnode);
    }
}

//二叉树的先序遍历
void PreOrderTraverse(BiTree T)
{
    if (T == NULL) return;
    printf("%c ", T->data);
    PreOrderTraverse(T->Lnode);
    PreOrderTraverse(T->Rnode);
}
//二叉树的中序遍历
void InOrderTraverse(BiTree T)
{
    if (T == NULL) return;
    InOrderTraverse(T->Lnode);
    printf("%c ", T->data);
    InOrderTraverse(T->Rnode);
}
//二叉树的后序遍历
void PostOrderTraverse(BiTree T)
{
    if (T == NULL) return;
    PostOrderTraverse(T->Lnode);
    PostOrderTraverse(T->Rnode);
    printf("%c ", T->data);
}
//二叉树的层次遍历
void LevelOrderTraverse(BiTree T)
{
    if (T == NULL) return;
    Q_Push(T);
    while (!Q_empty()) {
        BiTree tmp = Q_Pop(T);
        printf("%c ", tmp->data);
        if (tmp->Lnode)
            Q_Push(tmp->Lnode);
        if (tmp->Rnode)
            Q_Push(tmp->Rnode);
    }
}

int main()
{
    BiTree T;
    CreateBiTree(&T);
    printf("前序遍历结果为 :\n");
    PreOrderTraverse(T);

    printf("\n\n中序遍历结果为 :\n");
    InOrderTraverse(T);

    printf("\n\n后序遍历结果为 :\n");
    PostOrderTraverse(T);

    printf("\n\n层次遍历结果为 :\n\n");
    LevelOrderTraverse(T);
    return 0;
}

