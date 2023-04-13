#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//�������Ա�
#define DEF_SIZE 5  //��ʼ����
#define CRE_SIZE 2  //���ݵı���

typedef int SLDataType;

typedef struct SeqList 
{
	SLDataType* data;
	size_t size;//��Ч���ݵĸ���
	size_t capicity;//�ռ������Ĵ�С

}SL;//���������

//��������
//��ʼ��˳���
void SeqListInit(SL* psl);
//����˳���
void SeqLsitDestory(SL* psl);
//�������
void CheckCapicity(SL* psl);
//β��
void SeqListpushBack(SL* psl, SLDataType x);
//βɾ
void SeqListpopBack(SL* psl);
//ͷ��
void SeqListpushFront(SL* psl, SLDataType x);
//ͷɾ
void SeqListpopFront(SL* psl);
//����ָ������
int SeqListFind(SL* psl, SLDataType x);
//��ָ��λ�ò�������
void SeqListInset(SL* psl, size_t pos, SLDataType x);
//��ָ��λ��ɾ������
void SeqListErase(SL* psl, size_t pos);
//��ӡ
void SeqListprint(SL* psl);