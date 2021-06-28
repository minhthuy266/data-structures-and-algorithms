#include <iostream>
#include <string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct product
{
	int id;
	char name[250];
	float price;
};

struct Node
{
	product *data;
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

Node *createNode(product *d)
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
		cout<<"\nCap phat bo nho that bai!\n";
	}
	return pNode;
}

void insertLast(doubleList &list,product *d)
{
	Node *pNode=createNode(d);
	if(list.pTail==NULL)
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
		product *d=pTmp->data;
		cout<<d->id<<"\t"<<d->name<<"\t"<<d->price<<"\n";
		pTmp=pTmp->pNext;
	}
}

doubleList filter(doubleList list,float a,float b)
{
	doubleList listFilter;
	initialize(listFilter);
	Node *pTmp=list.pHead;
	while(pTmp!=NULL)
	{
		product *d=pTmp->data;
		if(d->price>=a && d->price<=b)
		{
			insertLast(listFilter,d);
		}
		pTmp=pTmp->pNext;
	}
	return listFilter;
}

void sortList(doubleList &list)
{
	for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
		{
		
			if(pTmp->data->price < pTmp2->data->price)
			{
				product *d1=pTmp->data;
				int ma1=d1->id;
				char ten1[250];
				strcpy(ten1,d1->name);
				double gia1=d1->price;
				
				product *d2=pTmp2->data;
				pTmp->data->id=d2->id;
				strcpy(pTmp->data->name,d2->name);
				pTmp->data->price=d2->price;
				
				pTmp2->data->id=ma1;
				strcpy(pTmp2->data->name,ten1);
				pTmp2->data->price=gia1;		
			}
		}
	}
}

void removeList(doubleList &list,int id)
{
	Node *pDel=list.pHead;
	if(pDel==NULL)
	{
		cout<<"Danh sach rong!";
		return;
	}
	Node *pPre=NULL;
	while(pDel!=NULL)
	{
		product *d=pDel->data;
		if(d->id==id)
			break;
		pPre=pDel;
		pDel=pDel->pNext;
	}
	if(pDel==NULL)
	{
		cout<<"Khong tim thay de xoa!";
	}
	else
	{
		if(pDel==list.pHead)
		{
			list.pHead=list.pHead->pNext;
			pDel->pNext=NULL;
			if(list.pHead!=NULL)
				list.pHead->pPrevious=NULL;
		}
		else if(pDel->pNext==NULL)
		{
			list.pTail=pPre;
			pDel->pPrevious=NULL;
			pPre->pNext=NULL;
		}
		else
		{
			pPre->pNext=pDel->pNext;
			pDel->pNext->pPrevious=pPre;
			pDel->pPrevious=NULL;
			pDel->pNext=NULL;
		}
		delete pDel;
		pDel=NULL;
	}
}

int main(int argc, char** argv) {
	doubleList list;
	initialize(list);
	
	product *sp1=new product;
	sp1->id=1;
	strcpy(sp1->name,"Coca");
	sp1->price=12.5;
	insertLast(list,sp1);
	
	product *sp2=new product;
	sp2->id=2;
	strcpy(sp2->name,"Pepsi");
	sp2->price=16.3;
	insertLast(list,sp2);
	
	product *sp3=new product;
	sp3->id=3;
	strcpy(sp3->name,"Sting");
	sp3->price=13.8;
	insertLast(list,sp3);
	printList(list);
	
	doubleList list2=filter(list,10,14);
	cout<<"\nDanh sach san pham co gia [10-14]: \n";
	printList(list2);
	
	sortList(list);
	cout<<"\nDanh sach sau sap xep:\n";
	printList(list);
	
	cout<<"\nNhap ma product muon xoa: ";
	int id;
	cin>>id;
	removeList(list,id);
	cout<<"\nDanh sach sau khi xoa: \n";
	printList(list);
	return 0;
}
