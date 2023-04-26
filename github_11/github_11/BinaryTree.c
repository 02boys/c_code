#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"

//��ʼ������
void QueueInit(Queue* q) 
{
	assert(q);
	q->front = q->rear = NULL;

}

//��β���
void QueuePush(Queue* q, QDataType data) 
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = data;
	newnode->next = NULL;
	if (q->rear == NULL) 
	{
		q->front = q->rear = newnode;
	}
	else 
	{
		q->front = q->rear = newnode;
		q->rear = newnode;
	}
}

//��ͷ����
void QueuePop(Queue* q) 
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->front == q->rear) 
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else 
	{
		QNode* cur = q->front->next;
		free(q->front);
		q->front = cur;
	}
}

//��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q) 
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->front->data;
}

//��ȡ����β��Ԫ��
QDataType QueueBack(Queue* q) 
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->rear->data;
}

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q) 
{
	assert(q);
	int size = 0;
	QNode* cur = q->front;
	while (cur) 
	{
		++size;
		cur = cur->next;
	}
	return size;
}

//�������Ƿ�Ϊ��.��=1���ǿ� = 0
int QueueEmpty(Queue* q) 
{
	assert(q);
	return q->front == NULL ? 1 : 0;
}

//���ٶ���
void QueueDestory(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur) 
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
}


BTNode* CreateBTNode(BTDataType x) 
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

//ͨ��ǰ����������鹹��������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) 
{
	if (a[*pi] == '#') 
	{
		return NULL;
	}
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = a[*pi];
	++*pi;
	node->left = BinaryTreeCreate(a, n, pi);
	++* pi;
	node->right = BinaryTreeCreate(a, n, pi);
	return node;

}

//������������;
void BinaryTreeDestory(BTNode** root) 
{
	if (*root != NULL) 
	{
		if ((*root)->left)//������
			BinaryTreeDestory(&(*root)->left);//������������
		if ((*root)->right)//���Һ���
			BinaryTreeDestory(&(*root)->right);//�����Һ�������

		free(*root);//�ͷŸ��ڵ�
		*root = NULL;
	}
}

//�������ڵ����
int BinaryTreeSize(BTNode* root) 
{
	if (root == NULL) 
	{
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) 
{
	if (root = NULL) 
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL) 
	{
		return 1;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

//��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL) 
	{
		return 0;
	}
	if (k == 1) 
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) 
{
	if (root = NULL) 
	{
		return NULL;
	}
	if (root->data == x) 
	{
		return root;
	}
	BTNode* ret = BinaryTreeFind(root->left, x);
	if (ret != NULL) 
	{
		return ret;
	}
	ret = BinaryTreeFind(root->right, x);
	if (ret != NULL) 
	{
		return ret;
	}
	return NULL;
}

//������ǰ�����
void BinaryTreePrevOrder(BTNode* root) 
{
	if (root == NULL) 
	{
		return;
	}
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

//�������������
void BinaryTreeInOrder(BTNode* root) 
{
	if (root = NULL) 
	{
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
//�������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root = NULL) 
	{
		return 0;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}

//��α���
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root) 
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q)) 
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		if (front->left) 
		{
			QueuePush(&q, front->left);
		}
		if (front->right) 
		{
			QueuePush(&q, front->right);
		}
	}
}

//�ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root) 
{
	Queue q;
	QueueInit(&q);
	if (root) 
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q)) 
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL) 
		{
			break;
		}
		printf("%s ", front->data);
		if (front->left) 
		{
			QueuePush(&q, front->left);
		}
		if (front->right) 
		{
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q)) 
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL) 
		{
			return 0;
		}
	}  
	return 1;
}
