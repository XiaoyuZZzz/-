#include <stdio.h>
#include <stdlib.h>
/*********************************
@150单链表 
*********************************/
/*
@打印界面 
*/
void print()
{
	printf("*******************************\n");
	printf("********1.CreatList_H**********\n");
	printf("********2.CreatList_R**********\n");
	printf("********3.SearchList***********\n");
	printf("********5.ChangeList***********\n");
	printf("********0.EXIT*****************\n");
}
/*
@线性表----单链表的头插创建、尾插法创建链表之、删、查、改 
*/
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*LinkList,LNode; 
/*
@头插法创建链表 
*/
void CreatList_H(LinkList* L)
{
	LinkList P;
	(*L)=(LinkList)malloc(sizeof(LNode));
	(*L)->next=NULL;
	int n,i;
	char c;
	printf("Please input your nedd input datanum:>\n");
	scanf("%d",&n);
	printf("Please input your need data:>\n");
	for(i=0;i<n;i++)
	{
		P=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&P->data);
		getchar();
		P->next=(*L)->next;
		(*L)->next=P;
	}
}
/*
@尾插法创建链表 
*/
void CreatList_R(LinkList* L)
{
	int n;
	LinkList p;
	(*L)=(LinkList)malloc(sizeof(LNode));
	(*L)->next=NULL;
	LinkList r=(*L);
	printf("Please input your need datanum:>\n");
	scanf("%d",&n);
	printf("Please input your need data:>\n");
	for(int i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		getchar();
		p->next=NULL;
		r->next=p;
		r=p;
	}	
 } 
/*
@查找 
*/
void SearchList(LinkList* L)
{
	ElemType c;
	int count=1;
	printf("Please input your need Search data:>\n");
	scanf("%d",&c);
	LinkList p=(*L)->next;
	while(p)
	{	
	if(p->data== c)
	{
		count=1;
		printf("Have data!\n");
		break;
	}
	else
	{
		count=0;
	}
	p=p->next;
	}
	if(count==0)
	{
		printf("No data!\n");
	}
	
}
/*
@修改 
*/
void ChangeList(LinkList *L)
{
	ElemType n,m;
	printf("Please input your need change two data:>\n");
	scanf("%d %d",&n,&m);
	LinkList p=(*L)->next;
	while(p)
	{
		if(p->data==n)
		{
			p->data=m;
		}
		p=p->next;
	}
}
int main() 
{
	int n;
	LinkList l;
	do
	{
		print();
		printf("Please input num:>\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				CreatList_H(&l);
				break;
			case 2:
				CreatList_R(&l);
				break;
			case 3:
				SearchList(&l);
				break;
			case 4:
				ChangeList(&l);
				break;
			default :
				printf("Please input again>\n");
				break;
			
		}
		
	}while(n);
	return 0;
}
