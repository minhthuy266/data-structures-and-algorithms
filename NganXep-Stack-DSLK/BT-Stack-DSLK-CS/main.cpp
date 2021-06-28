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

Node *pop(STACK &stack)
{
	if(stack==NULL)
		return NULL;
	Node *pDel=stack;
	stack=stack->pLink;
	pDel->pLink=NULL;
	return pDel;
}

Node *top(STACK &stack)
{
	return stack;
}

int main(int argc, char** argv) {
	STACK stack;
	initialize(stack);
	push(stack,113);
	push(stack,114);
	push(stack,100);
	Node *t=top(stack);
	cout<<"Node tren cung cua stack: \n";
	cout<<t<<"\n";
	cout<<t->data<<"\n";
	cout<<"\n----------------------------------\n";
	
	Node *n=pop(stack);
	cout<<n->data<<"\n";
	n=pop(stack);
	cout<<n->data<<"\n";
	n=pop(stack);
	cout<<n->data<<"\n";
	n=pop(stack);
	if(n==NULL)
	{
		cout<<"Stack rong!";
	}
	
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



