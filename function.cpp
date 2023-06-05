// 【1】预编译
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
// 【2】宏定义
using namespace std;
#define MAXSIZE 8
// 【3】结构定义
typedef char ElemType;
typedef struct Lnode
{
    ElemType Name;//姓名
    ElemType ClassNum;//班级
    int Num[MAXSIZE];//学号（最多9位数）
    ElemType Address;//住址
    ElemType Phone_Long;//手机长号
    ElemType Phone_Short;//手机短号
    ElemType Code;//邮箱
    struct Lnode *next;//next域指针 
}*LinkList;
// 【4】功能
// (1)创建通讯录文件
int CreatFile()
{

}
// (2)添加记录
int AddRecord()
{

}
// (3)删除记录
int DeleteRecord()
{

}
// (4)查找记录
int FindRecord()
{

}
// (5)修改记录
int ChangeRecord()
{

}
// (6)插入记录
int InsertRecord()
{

}
// (7)排序记录
int RankRecord()
{

}
// (8)统计记录
int StatisticsRecord()
{

}
// (9)半记忆查找——针对Num
void GetNextval(SqString t,int nextval[])  //由模式串t求出nextval值
{
	int j=0,k=-1;
	nextval[0]=-1;
	while (j<t.length)
	{	if (k==-1 || t.data[j]==t.data[k])
		{	j++;k++;
			if (t.data[j]!=t.data[k])
				nextval[j]=k;
			else
				nextval[j]=nextval[k];
		}
		else
			k=nextval[k];
	}
}
int KMPIndex1(SqString s,SqString t)	//修正的KMP算法
{
	int nextval[MaxSize],i=0,j=0;
	GetNextval(t,nextval);
	while (i<s.length && j<t.length) 
	{	if (j==-1 || s.data[i]==t.data[j]) 
		{	i++;
			j++;
		}
		else
			j=nextval[j];
	}
	if (j>=t.length)
		return(i-t.length);
	else
		return(-1);
}

// (10)读取记录
int ReadRecord()
{

}