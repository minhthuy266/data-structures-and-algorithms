#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node
{
	double data;
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

Node *createNode(double d)
{
	Node *pNode=new Node;
	if(pNode==NULL)
	{
		cout<<"Loi cap phat o nho!";
		exit(0);
	}
	pNode->data=d;
	pNode->pLink=NULL;
}

void enqueue(QUEUE &queue,double d)
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

double dequeue(QUEUE &queue)
{
	if(queue.pFront==NULL)
	{
		cout<<"Het Queue";
		exit(0);
	}
	double d=queue.pFront->data;
	Node *pDel=queue.pFront;
	queue.pFront=queue.pFront->pLink;
	pDel->pLink=NULL;
	delete pDel;
	return d;
}

bool isEmpty(QUEUE queue)
{
	return queue.pFront==NULL;
}

int main(int argc, char** argv) {
	QUEUE queue;
	initialize(queue);
	enqueue(queue,8.9);
	enqueue(queue,3.1);
	enqueue(queue,4.8);
	while (isEmpty(queue)==false)
	{
		cout<<dequeue(queue)<<"\n";
		cout<<dequeue(queue)<<"\n";
		cout<<dequeue(queue)<<"\n";
	}
	
	return 0;
}
