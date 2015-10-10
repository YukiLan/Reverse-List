#include<iostream>
#include<cstdio>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};
 
Node *head;

void InitList()
{
	//build a list
	head = NULL;
	Node *Cur = head;
	Node *p;
	for(int i=0;i<10;i++)
	{
		p=new Node;
		p->data=i;
		p->next=NULL;
		if(Cur==NULL)
		{
			Cur=p;
			head=p;
		}
		else
		{
			Cur->next=p;
			Cur=Cur->next;
		}
	}

	//print list
	Cur=head;
	printf("before reverse:\n");
	while(Cur!=NULL)
	{
		printf("%d\t", Cur->data);
		Cur=Cur->next;
	}
	puts(" ");
}

void Reserse(int begin, int end)
{
	Node *p = head;
	Node *q = head;
	for(int i=0;i<begin-1;i++)
	{
		p = p->next;
	}
	for(int i=0;i<end;i++)
	{
		q=q->next;
	}
	Node *Cur = p->next;
	Node *bebegin = p;
	Node *afend = q->next;
	Node *tail = afend;

	while(Cur!=afend)
	{
		Node * temp = Cur;
		Cur=Cur->next;
		temp->next=tail;
		tail=temp;
	}
	bebegin->next=tail;
	Cur=head;
	while(Cur!=NULL)
	{
		printf("%d\t", Cur->data);
		Cur=Cur->next;
	}
	puts(" ");
}
int main()
{
	InitList ();
	int begin, end;
	cin>>begin>>end;
	Reserse(begin, end);
	return 0;
}