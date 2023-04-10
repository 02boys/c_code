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
typedef char SString[MAX_STR_LEN + 1]; // 0号单元存放串的长度 
typedef int Status;

//SString是数组
Status  StrAssign(SString T,char* chars)
{
	//生成一个其值等于chars的串T
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
	//串S复制得到串T
	int i = 0;
	for (i = 0; i < S[0]; i++) 
	{
		T[i] = S[i];
	}
}

Status StrEmpty(SString S) 
{
	//为空直接返回true
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
	//用T返回S1和S2链接成的新串,若为发生截断，返回true，否则返回false
	int i = 0;
	if (S1[0] + S2[0] <= MAX_STR_LEN) 
	{
		//未截断
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
	//用Sub返回串S的第pos个字符串起长度为len的子串
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
	//返回字串T在主串S中第pos个位置之后的位置，若不存在，则函数值为0
	//其中，T非空，1<=pos<=Strlength(s)
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
	//初始条件：串S和T存在，1<=pos<=StrLenght(S)+1
	//操作条件：在串S的第pos个字符之前插入插入串T,完全插入返回TRUE，部分插入返回FALSE
	int i = 0;
	if (pos<1 || pos>S[0] + 1) 
	{
		return ERROR;
	}
	if (S[0] + T[0] <= MAX_STR_LEN) 
	{
		//完全插入
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
		//部分插入
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
	//初始条件;串S存在，1<=pos<=StrLength(S)-len+1
	//操作结果：从串S中删除第pos个字符串起长度为len的子串
	int i = 0;
	if (pos<1 || pos>S[0] - len + 1 || len < 0)
		return ERROR;
	for (i = pos + len; i <= S[0]; i++)
		S[i - len] = S[i];
	S[0] -= len;
	return OK;
}

Status Replace(SString S, SString T, SString V) //此函数于串的存储结构无关
{
	//初始条件：串S，T和V存在，T是非空字符串
	//操作结果：用V替换主串S中出现的所有与T相等的不重叠的字串
	int i = 1;//从串s的第一个字符起查找T
	Status k;
	if (StrEmpty(T))//T是空串
		return ERROR;
	do 
	{
		i = Index(S, T, i);//结果i为从上一个i之后找到的子串T的位置
		if (i) //串S中存在串T
		{
			StrDelets(S, i, StrLength(T));//删除改串T
			k = StrInsert(S, i, V);//在原串T的位置插入V
			if (!k)//不能完全插入
				return ERROR;
			i += StrLength(V);//在插入的串V后面继续查找T
		}
	} while (i);
	return OK;
}

void StrPrint(SString T) 
{
	//输出字符串T
	int i = 0;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}

void get_next(SString T, int next[]) 
{
	//求模式串T的next函数值并存入数组的next
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
	//求模式串T的next函数修正值并存入nextval
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
	//利用模式串的T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，1<=pos<=StrLength(S)
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0]) 
	{
		if (j == 0 || S[i] == T[j])//继续比较后继字符串
		{
			++i;
			++j;
		}
		else//模式串向右移动
			j = next[j];
		if (j > T[0])//匹配成功
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
	printf("主串为: ");
	StrPrint(s1);
	StrAssign(s2, "aaaab");
	printf("子串为: ");
	StrPrint(s2);
	p = (int*)malloc((StrLength(s2) + 1) * sizeof(int)); // 生成s2的next数组空间 
	get_next(s2, p); 
	printf("子串的next数组为: ");
	for (i = 1; i <= StrLength(s2); i++)
		printf("%d ", *(p + i));
	printf("\n");
	i = Index_KMP(s1, s2, 1, p);
	if (i)
		printf("主串和子串在第%d个字符处首次匹配\n", i);
	else
		printf("主串和子串匹配不成功\n");
	get_nextval(s2, p);
	printf("子串的nextval数组为: ");
	for (i = 1; i <= StrLength(s2); i++)
		printf("%d ", *(p + i));
	printf("\n");
	printf("主串和子串在第%d个字符处首次匹配\n", Index_KMP(s1, s2, 1, p));
	getchar();
	return 0;
}