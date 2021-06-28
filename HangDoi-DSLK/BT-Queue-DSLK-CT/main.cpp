#include <iostream>
#include <string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct customer
{
	int id;
	char name[250];
};

struct Node
{
	customer *data;
	Node *pLink;
};

struct QUEUE
{
	Node *pFront;
	Node *pRear;
};

void initialize(QUEUE &queue)
{
	queue.pFront=NULL;
	queue.pRear=NULL;
};

Node *createNode(customer *d)
{
	Node *pNode=new Node;
	if(pNode==NULL)
	{
		cout<<"Loi cap phat o nho";
		exit(0);
	}
	pNode->data=d;
	pNode->pLink=NULL;
}

void enqueue(QUEUE &queue,customer *d)
{
	Node *pNode=createNode(d);
	if(queue.pFront==NULL)
	{
		queue.pFront=queue.pRear=pNode;	
	}
	else
	{
		queue.pRear->pLink=pNode;
		queue.pRear=pNode;
	}
}

Node *dequeue(QUEUE &queue)
{
	if(queue.pFront==NULL)
	{
		cout<<"Het Queue";
		exit(0);
	}

	Node *pDel=queue.pFront;
	queue.pFront=queue.pFront->pLink;
	pDel->pLink=NULL;
	return pDel;
}

bool isEmpty(QUEUE queue)
{
	return queue.pFront==NULL;	
}

int main(int argc, char** argv) {
	QUEUE queue;
	initialize(queue);
	
	customer *c1=new customer;
	c1->id=1;
	strcpy(c1->name,"An");
	
	customer *c2=new customer;
	c2->id=2;
	strcpy(c2->name,"Yen");
	
	customer *c3=new customer;
	c3->id=3;
	strcpy(c3->name,"Hanh");
	
	enqueue(queue,c1);
	enqueue(queue,c2);
	enqueue(queue,c3);
	
	while(isEmpty(queue)==false)
	{
		Node *p=dequeue(queue);
		customer *c=p->data;
		cout<<c->id<<"\t"<<c->name<<"\n";
	}
	return 0;
}
