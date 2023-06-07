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
	if ((fp=fopen("emp.txt","rb"))==NULL) //不存在emp.txt文件
	{	
		 if ((fp=fopen("emp.txt","wb"))==NULL) 
			 printf("  提示:不能创建emp.txt文件\n");
	}
	else		//若存在emp.txt文件
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

int main()
{
    EmpList *L=NULL;   //定义职工单链表头指针
    printf("********************读入文件中职工信息************************\n"); 
    ReadFile(L);     //读入文件emp.txt中的职工信息,建立职工单链表L

    printf("\n********************输出职工信息************************\n");
    EmpList *p=L->next;     //p指向第一个职工信息结点
    while(p!=NULL)
    {
        printf("   学号:%s \n",p->data.Num);     //输出学号
        printf("   姓名:%c \n",p->data.Name);     //输出姓名 
        printf("   班级:%d \n",p->data.ClassNum);     //输出班级
        printf("   住址:%c \n",p->data.Address);     //输出住址    
        printf("   手机长号:%ld \n",p->data.Phone_Long);     //输出手机长号
        printf("   手机短号:%ld \n",p->data.Phone_Short);     //输出手机短号
        printf("   邮箱:%c \n",p->data.Code);  //输出邮箱  
        p=p->next;     //指向下一职工
    }
    printf("\n********************结束************************\n");
}