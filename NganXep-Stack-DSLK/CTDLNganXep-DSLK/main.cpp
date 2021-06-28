#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node
{
	int data;
	Node *pLink;
};

typedef Node *STACK;
void initialize(STACK &stack)
{
	stack=NULL;
};

Node *createNode(int d)
{
	Node *pNode=new Node;
	pNode->data=d;
	pNode->pLink=NULL;
}

void push(STACK &stack,int d);

int pop(STACK &stack);

int main(int argc, char** argv) {
	STACK stack;
	initialize(stack);
	push(stack,113);
	push(stack,114);
	push(stack,100);
	cout<<pop(stack)<<"\n";
	cout<<pop(stack)<<"\n";
	cout<<pop(stack)<<"\n";
	return 0;
}

void push(STACK &stack,int d)
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

int pop(STACK &stack)
{
	int d=stack->data;
	Node *pDel=stack;
	stack=stack->pLink;
	pDel->pLink=NULL;
	delete pDel;
	return d;
}
