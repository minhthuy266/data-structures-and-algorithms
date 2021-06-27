#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node 
{
	int data;
	Node *pNext;
	Node *pPrevious;
};

struct doubleList
{
	Node *pHead;
};

void initialize(doubleList &list)
{
	list.pHead=NULL;
};

Node *createNode(int d)
{
	Node *pNode=new Node;
	if(pNode!=NULL)
	{
		pNode->data=d;
		pNode->pNext=NULL;
		pNode->pPrevious=NULL;
	}
	else
	{
		cout<<"Cap phat bo nho that bai!";
	}
	return pNode;
};

void printList(doubleList list)
{
	Node *pTmp=list.pHead;
	if(pTmp==NULL)
	{
		cout<<"Danh sach rong!";
		return;
	}
	while(pTmp!=NULL)
	{
		cout<<pTmp->data;
		pTmp=pTmp->pNext;
	}
}

void insertLast(doubleList &list,int d)
{
	Node *pNode=createNode(d);
	if(list.pHead==NULL)
	{
		list.pHead=pNode;
	}
	else
	{
		Node *pTmp=list.pHead;
		while(pTmp->pNext!=NULL)
		{
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=pNode;
		pNode->pPrevious=pTmp;
	}
}

doubleList taoBigInt(char *str)
{
	doubleList list;
	initialize(list);
	for(int i=0;i<strlen(str);i++)
	{
		char strTmp[1];
		strTmp[0]=str[i];
		int d=atoi(strTmp);
		insertLast(list,d);
	}
	return list;
}

bool isPrime(int d)
{
	int dem=0;
	for(int i=1;i<=d;i++)
	{
		if(d%i==0)
		{
			dem++;
		}
	}
	return dem==2;
}

doubleList xuatDayNguyenTo(doubleList listGoc)
{
	doubleList list;
	initialize(list);
	Node *pTmp=listGoc.pHead;
	while(pTmp!=NULL)
	{
		int d=pTmp->data;
		bool kt=isPrime(d);
		if(kt==true)
		{
			insertLast(list,d);
		}
		pTmp=pTmp->pNext;
	}
	return list;
}

int main(int argc, char** argv) {
	doubleList list=taoBigInt("45678902198373655367901298");
	cout<<"Big Int: \n";
	printList(list);
	doubleList listPrime=xuatDayNguyenTo(list);
	cout<<"\nBig Int - Prime: \n";
	printList(listPrime);
	return 0;
}
