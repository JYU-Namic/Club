#include<stdio.h>
#include<malloc.h>
#define N 100
typedef struct
{
	int num[N];
	char name[N];
	int phone_l[N];
	int phone_s[N]; 
}empphone;
typedef struct node1
{
	empphone data;
	struct node1 *next;
}node1;

void biao(node1 * &L)   //读取文件建立链表 
{
	FILE *fp;
	node1 phone;
	node1 *p,*r;
	int n=0;
	 L=(node1 *)malloc(sizeof(node1));
	 r=L;
	 if((fp=fopen("phone.dat","rb"))==NULL)//不存在dat文件 
	 {
	 	if((fp=fopen("phone.dat","wb"))==NULL)
	 	printf("无法创建phone文件");
	 }
	 else
	 {
	 	while(fread(&phone,sizeof(node1),1,fp)==1)
	 	{
		 p=(node1 *)malloc(sizeof(node1));
		 p->data=phone;
		 r->next=p;
		 r=p;
		 n++;
		 }
	 }
	 r->next==NULL;
	 printf("总共有%d个记录",n);
	 fclose(fp);
}
int main()
{
	node1 *L;
	biao(L);
	return 1;
}