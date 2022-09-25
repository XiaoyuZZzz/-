/*
@线性表SqList ---顺序表的增、删、查、改 
*/
#define ElemType char
#define NUM 100
typedef struct{
	ElemType data[NUM];
	int length;
}SqList;
/**********************
@初始化
**********************/
void InitSqlist(SqList *S)
{
	S->data[NUM]=0;
	S->length=0;
 } 
/*
@插入 
*/
void SqListInsert(SqList *S)
{
	int i;
	char c;
	if(S->length==0||S->length==NUM)
	{
		printf("NO data!\n");
		return ;
	}	
	else
	{
	printf("Please input your need insert num,data:>\n");
	scanf("%d %c",&i,&c);
	getchar();
	for(int j=S->length-1;j>=i-1;j--)
	{
		S->data[j+1]=S->data[j];
		S->data[i-1]=c;
		S->length++;
	}
	}
	
}
/**********************
@增加 
**********************/
void ADDSqList(SqList *S)
{
	if(S->length==NUM)
	return ;
	printf("Please input char:>\n");
	scanf("%c",&S->data[S->length]);
	getchar();
	S->length++;
}
/**********************
@删除 
**********************/
void DeleteSqList(SqList *S)
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
	S->length--;
}
/**********************
@查找
**********************/ 
void SearchSqList(SqList *S)
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
@更换 
**********************/
void ChangeSqList(SqList *S)
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
/*****************************************************************************************************/
/*********************************
@150单链表 
*********************************/
/*
@线性表LinkList----单链表的头插创建、尾插法创建链表之、删、查、改 
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
void SearchLinkList(LinkList* L)
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
void ChangeLinkList(LinkList *L)
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
/*****************************************************************************************************/
/*
@双向链表DuList 
*/
#define ElemType int 
typedef struct DuNode{
	ElemType data;
	struct DuNode *prior;
	struct DuNode *next;
}DuNode,*DuList;
/*
@创建 
@思路：比单链表多了一步操作就是前指针指向前一个元素 
*/
void CreatDuList(DuList *L)
{
	int n;
	DuList p;
	(*L)=(DuList)malloc(sizeof(DuNode));
	(*L)->prior=(*L);
	(*L)->next=(*L);
	DuList r=(*L);
	printf("Please input your need insertnum:>\n");
	scanf("%d",&n);
	printf("Please input data:>\n");
	for(int i=0;i<n;i++)
	{
		p=(DuList)malloc(sizeof(DuNode));
		scanf("%d",&p->data);
		getchar();
		p->next=NULL;
		p->prior=r;
		r->next=p;
		r=p;
	}
}
/*
@双向链表查找 
*/
void SearchDuList(DuList L)
{
	if((*L)->next==(*L))
	break;
	ElemType c;
	int count=0;
	printf("Please input your need data:>\n");
	scanf("%d",&c);
	DuList p=L->next;
	while(p)
	{
		if(p->data==c)
		{
		printf("Have data!\n");
		count++;
		break;
		}
		p=p->next;
	}
	if(count==0)
	printf("No data!\n");
}
/*
@双向链表的改变 
*/
void ChangeDuList(DuList *L)
{
	if((*L)->next==(*L))
	break;
	ElemType front,after;
	printf("Please input your need change two data:>\n");
	scanf("%d %d",&front,&after);
	DuList P=(*L)->next;
	while(P)
	{
		if(P->data==front)
		{
			P->data=after;
			break;
		}
		P=P->next;
	}
}
/*
@删除 
@思路：(1)r->prior->next=r->next; (2)r->next->prior=r->prior;    
*/
void ListDelete_DuL(DuList *L)
{
	if((*L)->next==(*L))
	break;
	ElemType c;
	printf("Please input your need delete data:>\n");
	scanf("%d",&c);
	DuList p=(*L)->next;
	while(p)
	{
		if(p->data==c)
		{
			p->prior->next=p->next;
			p->next->prior=p->prior;
			free(p);
			break;	
		}
		p=p->next; 
	}
}
/*
@双向链表的插入
@思路:(1)s->prior=p->prior (2)p->prior->next=s;(3)s->next=p;(4)p->prior=s 
*/
void ListInsert_DuL(DuList *L)
{
	if((*L)->next==(*L))
	break;
	DuList s=(DuList)malloc(sizeof(DuNode));
	s->next=s;
	s->prior=s;
	ElemType c;
	printf("Please input your need insertdata:>\n");
	scanf("%d",&c);
	printf("Please input data:>\n");
	scanf("%d",&s->data);
	DuList p=(*L)->next;
	while(p)
	{
		if(p->data==c)
		{
			s->prior=p->prior;
			p->prior->next=s;
			s->next=p;
			p->prior=s;
			break;
		}
		p=p->next;
	}
} 
