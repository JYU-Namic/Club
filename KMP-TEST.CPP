//KMP测试 
#include <stdio.h>
#define MaxSize 100
typedef struct
{	
	char data[MaxSize];		//串中字符
	int length;				//串长
} SqString;					//声明顺序串类型


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


int main()
{
	int j;
	int next[MaxSize],nextval[MaxSize];
	SqString s,t;
	StrAssign(s,"abcabcdabcdeabcdefabcdefg");
	StrAssign(t,"abcdeabcdefab");
	printf("串s:");DispStr(s);
	printf("串t:");DispStr(t);
	GetNext(t,next);			//由模式串t求出next值
	GetNextval(t,nextval);		//由模式串t求出nextval值
	printf("改进的KMP算法:\n");
	printf("t在s中的位置=%d\n",KMPIndex1(s,t));
	return 1;
}




