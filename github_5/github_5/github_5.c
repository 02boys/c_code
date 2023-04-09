#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>


//int Fib(n) 
//{
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//	
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("第%d个数字是:%d", n, ret);
//
//	return 0;
//}

int Han(n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return pow(2, n) - 1;
	}
}

void Hanoi(int n, char A, char B, char C)
{
	if (n == 0)
		return NULL;
	else if (n == 1)
	{
		printf("%c-->%c\n", A, C);
	}
	else
	{
		Hanoi(n - 1, A, C, B);
		printf("%c-->%c\n", A, C);
		Hanoi(n - 1, B, A, C);
	}
}
int main()
{

	int n = 0;
	scanf("%d", &n);
	int ret = Han(n);
	Hanoi(n, 'A', 'B', 'C');
	printf("\n");
	printf("需要移动的次数是：%d", ret);
	return 0;
}