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

int Q_empty() { //�ж϶����Ƿ�Ϊ��
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

//���������������
void PreOrderTraverse(BiTree T)
{
    if (T == NULL) return;
    printf("%c ", T->data);
    PreOrderTraverse(T->Lnode);
    PreOrderTraverse(T->Rnode);
}
//���������������
void InOrderTraverse(BiTree T)
{
    if (T == NULL) return;
    InOrderTraverse(T->Lnode);
    printf("%c ", T->data);
    InOrderTraverse(T->Rnode);
}
//�������ĺ������
void PostOrderTraverse(BiTree T)
{
    if (T == NULL) return;
    PostOrderTraverse(T->Lnode);
    PostOrderTraverse(T->Rnode);
    printf("%c ", T->data);
}
//�������Ĳ�α���
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
    printf("ǰ��������Ϊ :\n");
    PreOrderTraverse(T);

    printf("\n\n����������Ϊ :\n");
    InOrderTraverse(T);

    printf("\n\n����������Ϊ :\n");
    PostOrderTraverse(T);

    printf("\n\n��α������Ϊ :\n\n");
    LevelOrderTraverse(T);
    return 0;
}

