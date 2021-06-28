#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct device
{
	int id;
	char name[250];
};

struct Node
{
	device *data;
	Node *pLink;
};

typedef Node *STACK;

void initialize(STACK &stack)
{
	stack=NULL;
}

Node *createNode(device *d)
{
	Node *pNode=new Node;
	pNode->data=d;
	pNode->pLink=NULL;
}

void push(STACK &stack, device *d)
{
	Node *pNode=createNode(d);
	if(stack==NULL)
	{
		stack=pNode;
	}
	else
	{
		pNode->pLink=stack;
		stack=pNode;
	}
}

Node *pop(STACK &stack)
{
	Node *pDel=stack;
	stack=stack->pLink;
	pDel->pLink=NULL;
	return pDel;
}

bool isEmpty(STACK stack)
{
	return stack==NULL;
}

int main(int argc, char** argv) {
	STACK stack;
	initialize(stack);
	
	device *d1=new device;
	d1->id=1;
	strcpy(d1->name,"Mouse");
	push(stack,d1);
	
	device *d2=new device;
	d2->id=2;
	strcpy(d2->name,"Keyboard");
	push(stack,d2);
	
	device *d3=new device;
	d3->id=3;
	strcpy(d3->name,"USB");
	push(stack,d3);
	
	while(isEmpty(stack)==false)
	{
		Node *n=pop(stack);
		device *d=n->data;
		cout<<d->id<<"\t"<<d->name<<"\n";
	}
	
	return 0;
}
