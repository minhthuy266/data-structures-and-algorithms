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
	Node *pTail;
};

void initialize(doubleList &list)
{
	list.pHead=list.pTail=NULL;
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
		list.pHead=list.pTail=pNode;
	}
	else
	{
		list.pTail->pNext=pNode;
		pNode->pPrevious=list.pTail;
		list.pTail=pNode;
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

void insertFirst(doubleList &list,int d)
{
	Node *pNode=createNode(d);
	if(list.pHead==NULL)
	{
		list.pHead=list.pTail=pNode;
	}
	else
	{
		pNode->pNext=list.pHead;
		list.pHead->pPrevious=pNode;
		list.pHead=pNode;
	}
}


doubleList cong2So(doubleList list1,doubleList list2)
{
	doubleList list3;
	initialize(list3);
	Node *tail1=list1.pTail;
	Node *tail2=list2.pTail;
	int v2=0;
	while(tail1!=NULL || tail2!=NULL)
	{
		int v1=0;
		if(tail1!=NULL && tail2!=NULL)	
		{
			v1=tail1->data+tail2->data;
		}
		else if(tail1!=NULL)
		{
			v1=tail1->data;
		}
		else if(tail2!=NULL)
		{
			v1=tail2->data;
		}		
		v1=v1+v2;
		if(v1>=10)
		{
			v2=v1/10;
			v1=v1%10;
		}
		else
		{
			v2=0;
		}
		insertFirst(list3,v1);
		if(tail1!=NULL)
		{
			tail1=tail1->pPrevious;
		}
		if(tail2!=NULL)
		{
			tail2=tail2->pPrevious;
		}
	}
	if(v2!=0)
	{
		insertFirst(list3,v2);
	}
	return list3;
}

int main(int argc, char** argv) {
	doubleList list=taoBigInt("45678902198373655367901298");
	cout<<"Big Int: \n";
	printList(list);
	doubleList listPrime=xuatDayNguyenTo(list);
	cout<<"\nBig Int - Prime: \n";
	printList(listPrime);
	
	doubleList list1=taoBigInt("3254");
	doubleList list2=taoBigInt("132");
	doubleList list3=cong2So(list1,list2);
	cout<<"\nList 1 + List 2 = ";
	printList(list3);
	return 0;
}
