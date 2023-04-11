#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define OK 1  
#define TRUE 1  
#define FALSE 0  
#define ERROR 0  
#define INFEASIBLE -1

#define DestroyString ClearString
#define MAX_STR_LEN 40
typedef char SString[MAX_STR_LEN + 1]; // 0�ŵ�Ԫ��Ŵ��ĳ��� 
typedef int Status;

//SString������
Status  StrAssign(SString T,char* chars)
{
	//����һ����ֵ����chars�Ĵ�T
	int i = 0;
	if (strlen(chars) > MAX_STR_LEN)
		return ERROR;
	else 
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++) 
		{
			T[i] = *(chars - 1);
			return OK;
		}
	}
}

void StrCopy(SString T,SString S) 
{
	//��S���Ƶõ���T
	int i = 0;
	for (i = 0; i < S[0]; i++) 
	{
		T[i] = S[i];
	}
}

Status StrEmpty(SString S) 
{
	//Ϊ��ֱ�ӷ���true
	if (S[0] == 0)
		return TRUE;
	else
		return FALSE;
}

int	StrCompare(SString S, SString T) 
{
	int i = 0;
	for (i = 1; i <= S[0] && i <= T[0]; i++) 
	{
		if (S[i] != T[i]) 
		{
			return S[i] - T[i];
		}
		return S[0] - T[0];
	}
}

int StrLength(SString S) 
{
	return S[0];
}

void ClearString(SString S) 
{
	S[0] = 0;
}

Status ConCat(SString T,SString S1,SString S2) 
{
	//��T����S1��S2���ӳɵ��´�,��Ϊ�����ضϣ�����true�����򷵻�false
	int i = 0;
	if (S1[0] + S2[0] <= MAX_STR_LEN) 
	{
		//δ�ض�
		for (i = 1; i <= S1[0]; i++) 
		{
			T[i] = S1[i];
		}
		for (i = 1; i <= S2[0]; i++) 
			T[S1[0] + i] = S2[i];
		T[0] = S1[0] + S2[0];
		return TRUE;
	}
	else 
	{
		for (i = 1; i <= S1[0]; i++) 
		{
			T[i] = S1[i];
		}
		for (i = 1; i <= MAX_STR_LEN - S1[0]; i++) 
			T[S1[0] + i] = S2[i];
		T[0] = MAX_STR_LEN;
		return FALSE;
	}
}

Status SubString(SString Sub,SString S,int pos,int len) 
{
	//��Sub���ش�S�ĵ�pos���ַ����𳤶�Ϊlen���Ӵ�
	int i = 0;
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1) 
	{
		return ERROR;
	}
	for (i = 1; i <= len; i++) 
	{
		Sub[i] = S[pos + i - 1];
	}
	Sub[0] = len;
	return OK;
}

int Index(SString S,SString T,int pos)
{
	//�����ִ�T������S�е�pos��λ��֮���λ�ã��������ڣ�����ֵΪ0
	//���У�T�ǿգ�1<=pos<=Strlength(s)
	int i, j;
	if (1 <= pos && pos <= S[0]) 
	{
		i = pos;
		j = 1;
		while (i <= S[0] && j <= T[0]) 
		{
			if (S[i] == T[j]) 
			{
				++i;
				++j;
			}
			else 
			{
				i = i - j + 2;
				j = 1;
			}
			if (j > T[0])
				return i - T[0];
			else
				return 0;
		}
	}
	else 
	{
		return 0;
	
	}
}

Status StrInsert(SString S, int pos, SString T) 
{
	//��ʼ��������S��T���ڣ�1<=pos<=StrLenght(S)+1
	//�����������ڴ�S�ĵ�pos���ַ�֮ǰ������봮T,��ȫ���뷵��TRUE�����ֲ��뷵��FALSE
	int i = 0;
	if (pos<1 || pos>S[0] + 1) 
	{
		return ERROR;
	}
	if (S[0] + T[0] <= MAX_STR_LEN) 
	{
		//��ȫ����
		for (i = S[0]; i >= pos; i--) 
		{
			S[i + T[0]] = S[i];
		}
		for (i = pos; i < pos + T[0]; i++) 
		{
			S[i] = T[i - pos + 1];
		}
		S[0] += T[0];
		return TRUE;
	}
	else 
	{
		//���ֲ���
		for (i = MAX_STR_LEN; i >= pos + T[0]; i--)
			S[i] = S[i - T[0]];
		for (i = pos; i < pos + T[0] && i <= MAX_STR_LEN; i++)
			S[i] = T[i - pos + 1];
		S[0] = MAX_STR_LEN;
		return FALSE;
	}
}

Status StrDelets(SString S, int pos, int len) 
{
	//��ʼ����;��S���ڣ�1<=pos<=StrLength(S)-len+1
	//����������Ӵ�S��ɾ����pos���ַ����𳤶�Ϊlen���Ӵ�
	int i = 0;
	if (pos<1 || pos>S[0] - len + 1 || len < 0)
		return ERROR;
	for (i = pos + len; i <= S[0]; i++)
		S[i - len] = S[i];
	S[0] -= len;
	return OK;
}

Status Replace(SString S, SString T, SString V) //�˺����ڴ��Ĵ洢�ṹ�޹�
{
	//��ʼ��������S��T��V���ڣ�T�Ƿǿ��ַ���
	//�����������V�滻����S�г��ֵ�������T��ȵĲ��ص����ִ�
	int i = 1;//�Ӵ�s�ĵ�һ���ַ������T
	Status k;
	if (StrEmpty(T))//T�ǿմ�
		return ERROR;
	do 
	{
		i = Index(S, T, i);//���iΪ����һ��i֮���ҵ����Ӵ�T��λ��
		if (i) //��S�д��ڴ�T
		{
			StrDelets(S, i, StrLength(T));//ɾ���Ĵ�T
			k = StrInsert(S, i, V);//��ԭ��T��λ�ò���V
			if (!k)//������ȫ����
				return ERROR;
			i += StrLength(V);//�ڲ���Ĵ�V�����������T
		}
	} while (i);
	return OK;
}

void StrPrint(SString T) 
{
	//����ַ���T
	int i = 0;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}

void get_next(SString T, int next[]) 
{
	//��ģʽ��T��next����ֵ�����������next
	int i = 1, j = 0;
	next[1] = 0;
	while (i<T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else 
		{
			j = next[j];
		}
	}
}

void get_nextval(SString T, int nextval[]) 
{
	//��ģʽ��T��next��������ֵ������nextval
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i<T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			if (T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}

int Index_KMP(SString S, SString T, int pos, int next[]) 
{
	//����ģʽ����T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	//���У�T�ǿգ�1<=pos<=StrLength(S)
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0]) 
	{
		if (j == 0 || S[i] == T[j])//�����ȽϺ���ַ���
		{
			++i;
			++j;
		}
		else//ģʽ�������ƶ�
			j = next[j];
		if (j > T[0])//ƥ��ɹ�
			return i - T[0];
		else
			return 0;
	}
}

int main()
{
	int i, * p;
	SString s1, s2; 
	StrAssign(s1, "aaabaaaab");
	printf("����Ϊ: ");
	StrPrint(s1);
	StrAssign(s2, "aaaab");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s2);
	p = (int*)malloc((StrLength(s2) + 1) * sizeof(int)); // ����s2��next����ռ� 
	get_next(s2, p); 
	printf("�Ӵ���next����Ϊ: ");
	for (i = 1; i <= StrLength(s2); i++)
		printf("%d ", *(p + i));
	printf("\n");
	i = Index_KMP(s1, s2, 1, p);
	if (i)
		printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n", i);
	else
		printf("�������Ӵ�ƥ�䲻�ɹ�\n");
	get_nextval(s2, p);
	printf("�Ӵ���nextval����Ϊ: ");
	for (i = 1; i <= StrLength(s2); i++)
		printf("%d ", *(p + i));
	printf("\n");
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n", Index_KMP(s1, s2, 1, p));
	getchar();
	return 0;
}