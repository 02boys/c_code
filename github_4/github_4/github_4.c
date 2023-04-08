#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define SIZE 6

//快速排序
void quick_sort(int num[], int low, int high)
{
    int i, j, temp;
    int tmp;

    i = low;
    j = high;
    tmp = num[low];   //任命为中间分界线，左边比他小，右边比他大,通常第一个元素是基准数

    if (i > j)  //如果下标i大于下标j，函数结束运行
    {
        return;
    }

    while (i != j)
    {
        while (num[j] >= tmp && j > i)
        {
            j--;
        }

        while (num[i] <= tmp && j > i)
        {
            i++;
        }

        if (j > i)
        {
            temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
    }

    num[low] = num[i];
    num[i] = tmp;

    quick_sort(num, low, i - 1);
    quick_sort(num, i + 1, high);
}

int main(int argc, char** argv)
{
    //创建一个数组
    int num[SIZE] = { 0 };
    int i;

    //输入数字
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &num[i]);
    }

    quick_sort(num, 0, SIZE - 1);

    for (i = 0; i < SIZE; i++)
    {
        printf(" %d ", num[i]);
    }

    return 0;
}

