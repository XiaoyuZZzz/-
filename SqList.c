#include <stdio.h>
/*
@���Ա� ---˳��������ɾ���顢�� 
*/
#define ElemType char
#define NUM 100
typedef struct{
	ElemType data[NUM];
	int length;
}SqList;
/**********************
@���� 
**********************/
void print()
{
	printf("*************************\n");
	printf("**********1.ADD**********\n");
	printf("**********2.Delete*******\n");
	printf("**********3.Search*******\n");
	printf("**********4.Replace******\n");
	printf("**********0.EXIT*********\n");
	printf("*************************\n");
}
/**********************
@��ʼ��
**********************/
void InitSqlist(SqList *S)
{
	S->data[NUM]=0;
	S->length=0;
 } 
/**********************
@���� 
**********************/
void ADD(SqList *S)
{
	printf("Please input char:>\n");
	scanf("%c",&S->data[S->length]);
	getchar();
	S->length++;
}
/**********************
@ɾ�� 
**********************/
void Delete(SqList *S)
{
	if(S->length==0)
	{
		printf("ERROR! No data!\n");
		return;
	}
	else
	{
	ElemType c;
	printf("Please input your need delete char:>\n");
	scanf("%c",&c);
	getchar();
	for(int i=0;i<S->length;i++)
	{
		if(S->data[i]==c)
		{
			S->data[i]=S->data[i+1];
		        for(int j=i+1;j<S->length;j++)
		        S->data[j]=S->data[j+1];
		}
		
	}
	}
	
}
/**********************
@����
**********************/ 
void Search(SqList *S)
{
	ElemType c;
	int value=0;
	if(S->length==0)
	{
		printf("NO data!\n");
		return;
	}
	else
	{
	printf("Please input your nedd search char:>\n");
	scanf("%c",&c);
	getchar();
	for(int i=0;i<S->length;i++)
	{
		if(S->data[i]==c)
		{
			printf("num is->%d\n",i);
		value++;
		break;
		}
		
	}	
	}
	if(value==0)
	{
		printf("NO data!\n");
	}
	
}
/**********************
@���� 
**********************/
void Replace(SqList *S)
{
	ElemType front,after;
	if(S->length==0)
	{
		printf("NO data!\n");
		return;
	}
	else
	{
		printf("Please input your need replace two char:>\n");
		scanf("%c %c",&front,&after);
		for(int i=0;i<S->length;i++)
		{
			if(S->data[i]==front)
			S->data[i]=after;
		}
	}
}
int main()
{
	SqList s;
	int n;
	do{
		
		print();
		scanf("%d",&n);
		getchar();
		switch(n)
		{
			case 1:
				ADD(&s);
				break;
			case 2:
				Delete(&s);
				break;
			case 3:
				Search(&s);
				break;
			case 4:
				Replace(&s);
				break;
			default:
				printf("Please input again:>\n");
				break;
		}
	}while(n);
	return 0;
 } 
