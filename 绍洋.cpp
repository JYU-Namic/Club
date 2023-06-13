#include <stdio.h>
#include <malloc.h>
#include<iostream>
#include<cstdio>
#define MaxSize 20
using namespace std;
typedef struct
{
	int num;						//学号
	char name[10];				    //姓名
	int classes;					//班级
	long int phone;				    //电话
    char address[20];               //地址
    char code[20];                  //邮箱
} EmpType;						    //联系人
typedef struct node
{
	EmpType data;				//存放通讯信息
	struct node *next;			//指向下一个结点的指针
}  EmpList;						//联系人结点类型
typedef struct
{	
	char data[MaxSize];		//串中字符
	int length;				//串长
} SqString;					//声明顺序串类型

void DestroyEmp(EmpList *&L)	//释放联系人单链表L
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
void DelAll(EmpList *&L)		//删除联系人文件中全部记录
{
	FILE *fp;
	if ((fp=fopen("emp.dat","wb"))==NULL)	//重写清空emp.dat文件
	{	
		printf("  提示:不能打开联系人文件\n");
		return;
	}
	fclose(fp);
	DestroyEmp(L);						//释放联系人单链表L
	L=(EmpList *)malloc(sizeof(EmpList));	
	L->next=NULL;						//建立一个空的联系人单链表L
	printf("  提示:联系人记录清除完毕\n");
}
void ReadFile(EmpList *&L)		//读emp.dat文件建立联系人单键表L
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
	printf("  提示:联系人单键表L建立完毕,有%d个记录\n",n);
	fclose(fp);
}
void SaveFile(EmpList *L)	//将联系人单链表数据存入数据文件
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
	DestroyEmp(L);				//释放联系人单链表L
	if (n>0)
		printf("  提示:%d个联系人记录写入emp.dat文件\n",n);
	else
		printf("  提示:没有任何联系人记录写入emp.dat文件!\n");
}
void InputEmp(EmpList *&L)	//添加一个联系人记录
{
	EmpType p;
	EmpList *s;
	printf("  >>输入学号(-1返回):");
	scanf("%d",&p.num);
	if (p.num==-1) return;
	printf("  >>输入姓名 班级 电话 地址 邮箱(中间用空格隔开):");
	scanf("%s%d%ld%s%s",&p.name,&p.classes,&p.phone,&p.address,&p.code);
	s=(EmpList *)malloc(sizeof(EmpList));
	s->data=p;
	s->next=L->next;		//采用头插法插入结点s
	L->next=s;
	printf("  提示:添加成功!\n");
}

void DelEmp(EmpList *&L)	//删除一个职工记录
{
	EmpList *pre=L,*p=L->next;
	int num;
	printf("  >>输入学号(-1返回):");
	scanf("%d",&num);
	if (num==-1) return;
	while (p!=NULL && p->data.num!=num)
	{
		pre=p;
		p=p->next;
	}
	if (p==NULL)
		printf("  提示:指定的联系人记录不存在！\n");
	else
	{
		pre->next=p->next;
		free(p);
		printf("  提示:删除成功！\n");
	}
}
void Sortno(EmpList *&L)	//采用直接插入法单链表L按学号递增有序排序
{
	EmpList *p,*pre,*q;
	p=L->next->next;
	if (p!=NULL)
	{
		L->next->next=NULL;
		while (p!=NULL)
		{
			q=p->next;
			pre=L;
			while (pre->next!=NULL && pre->next->data.num<p->data.num)
				pre=pre->next;
			p->next=pre->next;
			pre->next=p;
			p=q;
		}
	}
	printf("  提示:按学号递增排序完毕！\n");
}
void Sortdepno(EmpList *&L) //采用直接插入法单链表L按班级递增有序排序
{
	EmpList *p,*pre,*q;
	p=L->next->next;
	if (p!=NULL)
	{
		L->next->next=NULL;
		while (p!=NULL)
		{
			q=p->next;
			pre=L;
			while (pre->next!=NULL && pre->next->data.classes<p->data.classes)
				pre=pre->next;
			p->next=pre->next;
			pre->next=p;
			p=q;
		}
	}
	printf("  提示:按班级递增排序完毕\n");
}
void Sortsalary(EmpList *&L) //采用直接插入法单链表L按电话递增有序排序
{
	EmpList *p,*pre,*q;
	p=L->next->next;
	if (p!=NULL)
	{
		L->next->next=NULL;
		while (p!=NULL)
		{
			q=p->next;
			pre=L;
			while (pre->next!=NULL && pre->next->data.phone<p->data.phone)
				pre=pre->next;
			p->next=pre->next;
			pre->next=p;
			p=q;
		}
	}
	printf("  提示:按电话递增排序完毕\n");
}
void DispEmp(EmpList *L)	//输出所有联系人记录
{
	EmpList *p=L->next;
	if (p==NULL)
		printf("  提示:没有任何联系人记录！\n");
	else
	{
		printf("    学号\t姓名\t  班级\t电话\t\t地址\t\t邮箱\n");
		printf("   -------------------------------------------------------------------------------\n");
		while (p!=NULL)
		{
			printf("  %d\t%-10s%d  %ld\t%-s\t%-s\n",p->data.num,p->data.name,p->data.classes,p->data.phone,p->data.address,p->data.code);
			p=p->next; 
		}
		printf("   -------------------------------------------------------------------------------\n");
	}
}

//需添加函数
void Find(EmpList *&L)     //查找记录
{

}

void Change(EmpList *&L)    //修改记录
{

}

//半记忆查找
void StrAssign(SqString &s,char cstr[])	//字符串常量赋给串s
{
	int i;
	for (i=0;cstr[i]!='\0';i++)
		s.data[i]=cstr[i];
	s.length=i;
}


void DispStr(SqString s)	//输出串s
{
	if (s.length>0)
	{	for (int i=0;i<s.length;i++)
			printf("%c",s.data[i]);
		printf("\n");
	}
}


void GetNext(SqString t,int next[])	//由模式串t求出next值
{	int j,k;
	j=0;k=-1;next[0]=-1;
	while (j<t.length-1)
	{	if (k==-1 || t.data[j]==t.data[k]) 	//k为-1或比较的字符相等时
		{	j++;k++;
			next[j]=k;
		}
		else  k=next[k];
	}
}

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

void KMP(EmpList *L,char *T)
{
    // <1>定义声明
	cout<<endl;
	int j;
	char S[MaxSize];
	int next[MaxSize],nextval[MaxSize];
	SqString s,t;
    // <2>T输入
	StrAssign(t,T);
	// <3>S输入
    EmpList *p=L->next;
	while (p!=NULL)
	{
        sprintf(S,"%ld",p->data.phone);
	    StrAssign(s,S);
	    // <5>求nextval
	    GetNext(t,next);			//由模式串t求出next值
	    GetNextval(t,nextval);		//由模式串t求出nextval值
	    // <6>输出结果
		if(KMPIndex1(s,t)!=-1)
		    DispStr(s);
        p=p->next;
	}
}
// 以上属半记忆查找


int main()
{
	EmpList *L;
	int sel;
	printf("由emp.dat文件建立联系人单键表L\n");
	ReadFile(L);
	do
	{	
		printf("[---------------------\n");
		printf("\t1:添加记录\n\t2:显示记录\n\t3:按职学号排序\n\t4:按班级排序\n\t5:按电话排序\n\t6:删除记录\n\t9:清空记录\n\t10:查找记录(还没有函数)\n\t11:修改记录(还没有函数)\n\t12:半记忆查找\n\t0:保存并退出\n");
		printf("----------------------]\n请选择:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 9:
			DelAll(L);
			break;
		case 1:
			InputEmp(L);
			break;
		case 2:
			DispEmp(L);
			break;
		case 3:
			Sortno(L);
			break;
		case 4:
			Sortdepno(L);
			break;
		case 5:
			Sortsalary(L);
			break;
		case 6:
			DelEmp(L);
			break;
		case 10:
			Find(L);
			break;
		case 11:
			Change(L);
			break;
		case 12:
			char T[MaxSize];
            int num;
            cout<<"请输入半记忆电话：";
            cin>>T;
			cout<<"您可能想找以下联系人：";
            KMP(L,T);
			break;
		}
	} while (sel!=0);
	SaveFile(L);
	return 1;
}