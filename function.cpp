// 【1】预编译
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<new>
// 【2】宏定义
using namespace std;
#define MAXSIZE 8
// 【3】结构定义
typedef char ElemType;
typedef struct
{  
	char Num[MAXSIZE];//学号（最多9位数）
    ElemType Name;//姓名
    int ClassNum;//班级
    ElemType Address;//住址
    long int Phone_Long;//手机长号
    long int Phone_Short;//手机短号
    ElemType Code;//邮箱
}EmpType;
typedef struct node
{
	EmpType data;
	struct node *next;
}EmpList;

// 【4】功能
// (1)读取记录：读emp.dat文件建立职工单键表L
void ReadFile(EmpList *&L)		
{
	FILE *fp;
	EmpType emp;
	EmpList *p,*r;
	int n=0;
	L=(EmpList *)malloc(sizeof(EmpList));	//建立头结点
	r=L;
	if ((fp=fopen("emp.dat","rb"))==NULL) //不存在emp.dat文件
	{	
		 if ((fp=fopen("emp.dat","wb"))==NULL) 
			 printf("  提示:不能创建emp.dat文件\n");
	}
	else		//若存在emp.dat文件
	{
		while (fread(&emp,sizeof(EmpType),1,fp)==1)
		{	//采用尾插法建立单链表L
			p=(EmpList *)malloc(sizeof(EmpList));
			p->data=emp;
			r->next=p;
			r=p;
			n++;
		}
	}
	r->next=NULL;
	printf("  提示:职工单键表L建立完毕,有%d个记录\n",n);
	fclose(fp);
}

// (2)添加记录
int AddRecord(EmpList *&L)
{
    EmpType p;
    EmpList *s;
    cout<<"请输入学生的学号(最多9位):";
    cin.getline(p.Num,MAXSIZE+1);
	cout<<"请输入学生的姓名：";
	cin>>p.Name;
	cout<<"班级：";
	cin>>p.ClassNum;
	cout<<"住址：";
	cin>>p.Address;
	cout<<"手机长号：";
	cin>>p.Phone_Long;
	cout<<"手机短号：";
	cin>>p.Phone_Short;
	cout<<"邮箱：";
	cin>>p.Code;
    s=new EmpList;
    s->data=p;
    s->next=L->next;
    L->next=s;
    cout<<"添加完成！！！";
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
void GetNextval()  
{

}
// (10)写入记录：//将单链表数据存入数据文件
void SaveFile(EmpList *L)	
{
	EmpList *p=L->next;
	int n=0;
	FILE *fp;
	if ((fp=fopen("emp.dat","wb"))==NULL) 
	{	
		printf("  提示:不能创建文件emp.dat\n");
		return;
	}
	while (p!=NULL)
	{
		fwrite(&p->data,sizeof(EmpType),1,fp);
		p=p->next;
		n++;
	}
	fclose(fp);
	DestroyEmp(L);				//释放职工单链表L
	if (n>0)
		printf("  提示:%d个职工记录写入emp.dat文件\n",n);
	else
		printf("  提示:没有任何职工记录写入emp.dat文件\n");

}
// (11)摧毁链表
void DestroyEmp(EmpList *&L)	//释放职工单链表L
{
	EmpList *pre=L,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
}

