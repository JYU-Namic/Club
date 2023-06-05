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
}LinkList;
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
void Get_next(Sting_T,int &next[])
{
    int i=1;
    int j=0;
    next[1]=0;
    while (i<T.Length)
    {
        if(j==0||T.ch[i]==T.ch[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else j=next[j];
    }
}
int KMP(String_S,String_T)
{
    int i=1;
    int j=1;
    while (i<S.Length&&j<T.Length)
    {
        if (j==0||S.ch[i]==T.ch[j])
        {
            i++;
            j++;
        }
        else j=next[j];
    }
    if (j>T.Length)
       return i-T.Length;
    else return 0;
}
// (10)读取记录
int ReadRecord()
{

}