#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"

//初始化队列
void QueueInit(Queue* q) 
{
	assert(q);
	q->front = q->rear = NULL;

}

//队尾入队
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

//对头出队
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

//获取队列头部元素
QDataType QueueFront(Queue* q) 
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->front->data;
}

//获取队列尾部元素
QDataType QueueBack(Queue* q) 
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->rear->data;
}

//获取队列中有效元素个数
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

//检查队列是否为空.空=1；非空 = 0
int QueueEmpty(Queue* q) 
{
	assert(q);
	return q->front == NULL ? 1 : 0;
}

//销毁队列
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

//通过前序遍历的数组构建二叉树
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

//二叉树的销毁;
void BinaryTreeDestory(BTNode** root) 
{
	if (*root != NULL) 
	{
		if ((*root)->left)//有左孩子
			BinaryTreeDestory(&(*root)->left);//销毁左孩子子数
		if ((*root)->right)//有右孩子
			BinaryTreeDestory(&(*root)->right);//销毁右孩子子数

		free(*root);//释放根节点
		*root = NULL;
	}
}

//二叉树节点个数
int BinaryTreeSize(BTNode* root) 
{
	if (root == NULL) 
	{
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//二叉树叶子节点个数
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

//二叉树第k层节点个数
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

//二叉树查找值为x的节点
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

//二叉树前序遍历
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

//二叉树中序遍历
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
//二叉树后序遍历
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

//层次遍历
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

//判断二叉树是否是完全二叉树
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
