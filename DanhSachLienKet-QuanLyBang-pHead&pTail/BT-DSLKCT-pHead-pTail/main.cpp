#include <iostream>
#include <math.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct phanSo
{
	int tu,mau;
};

struct Node 
{
	phanSo *data;
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

Node *createNode(int tu,int mau)
{
	Node *pNode=new Node;
	if(pNode==NULL)
	{
		cout<<"Loi cap phat bo nho";
		exit(0);
	}
	phanSo *ps=new phanSo;
	ps->mau=mau;
	ps->tu=tu;
	pNode->data=ps;
	pNode->pNext=NULL;
	return pNode;
}

void insertLast(singleList *&list,int tu,int mau)
{
	Node *pNode=createNode(tu,mau);
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
			phanSo *ps=pTmp->data;
			if(pTmp->pNext!=NULL)
				cout<<ps->tu<<"/"<<ps->mau<<" + ";
			else
				cout<<ps->tu<<"/"<<ps->mau;
			pTmp=pTmp->pNext;
		}
	}
}

int giaiThua(int n)
{
	if(n<=1)
		return 1;
	return n*giaiThua(n-1);
}

double sumOfList(singleList *list)
{
	double sum=0;
	for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		phanSo *ps=pTmp->data;
		sum=sum+(ps->tu*1.0/ps->mau);
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
		int tu=(int)pow(x,i);
		int mau=giaiThua(i);
		insertLast(list,tu,mau);
	}
	cout<<"\nDanh sach so: ";
	printList(list);
	double sum=sumOfList(list);
	cout<<" = "<<sum;
	return 0;
}
