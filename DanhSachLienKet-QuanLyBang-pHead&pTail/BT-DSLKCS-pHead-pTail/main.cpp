#include <iostream>
#include <math.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node
{
	int x,n;
	Node *pNext;
};

struct singleList
{
	Node *pHead;
	Node *pTail;
};

void initialize(singleList *&list)
{
	list=new singleList;
	list->pHead=list->pTail=NULL;
}

Node *createNode(int x,int n)
{
	Node *pNode=new Node;
	if(pNode==NULL)
	{
		cout<<"Loi cap phat bo nho";
		exit(0);
	}
	else
	{
		pNode->x=x;
		pNode->n=n;
		pNode->pNext=NULL;
	}
	return pNode;
}

void insertLast(singleList *&list,int x,int n)
{
	Node *pNode=createNode(x,n);
	if(list->pTail==NULL)
		list->pHead=list->pTail=pNode;
	else
	{
		list->pTail->pNext=pNode;
		list->pTail=pNode;
	}	
}

void printList(singleList *list)
{
	Node *pTmp=list->pHead;
	if(pTmp==NULL)
	{
		cout<<"Danh sach rong!";
	}
	else
	{
		while(pTmp!=NULL)
		{
			if(pTmp->pNext!=NULL)
				cout<<pTmp->x<<"^"<<pTmp->n<<" + ";
			else
				cout<<pTmp->x<<"^"<<pTmp->n;
			pTmp=pTmp->pNext;
		}
	}
}

double sumOfList(singleList *list)
{
	double sum=0;
	for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		double value=pow(pTmp->x,pTmp->n);
		sum+=value;
	}
	return sum;
}

int main(int argc, char** argv) {
	singleList *list;
	initialize(list);
	int n,x;
	cout<<"Nhap n: ";
	cin>>n;
	cout<<"Nhap x: ";
	cin>>x;
	
	for(int i=1;i<=n;i++)
	{
		insertLast(list,x,i);
	}
	cout<<"\nDanh sach so: ";
	printList(list);
	double sum=sumOfList(list);
	cout<<" = "<<sum;
	return 0;
}
