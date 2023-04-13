#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//定义线性表
#define DEF_SIZE 5  //初始容量
#define CRE_SIZE 2  //扩容的倍数

typedef int SLDataType;

typedef struct SeqList 
{
	SLDataType* data;
	size_t size;//有效数据的个数
	size_t capicity;//空间容量的大小

}SL;//定义变量名

//函数定义
//初始化顺序表
void SeqListInit(SL* psl);
//销毁顺序表
void SeqLsitDestory(SL* psl);
//检查容量
void CheckCapicity(SL* psl);
//尾插
void SeqListpushBack(SL* psl, SLDataType x);
//尾删
void SeqListpopBack(SL* psl);
//头插
void SeqListpushFront(SL* psl, SLDataType x);
//头删
void SeqListpopFront(SL* psl);
//查找指定数据
int SeqListFind(SL* psl, SLDataType x);
//在指定位置插入数据
void SeqListInset(SL* psl, size_t pos, SLDataType x);
//在指定位置删除数据
void SeqListErase(SL* psl, size_t pos);
//打印
void SeqListprint(SL* psl);