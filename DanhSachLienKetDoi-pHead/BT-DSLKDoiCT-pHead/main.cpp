#include <iostream>
#include <string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct sanPham
{
	int ma;
	char ten[250];
	double gia;
};

struct Node
{
	sanPham *data;
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

Node *createNode(sanPham *d)
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

void insertFirst(doubleList &list,sanPham *d)
{
	Node *pNode=createNode(d);
	if(list.pHead==NULL)
	{
		list.pHead=pNode;
	}
	else
	{
		pNode->pNext=list.pHead;
		list.pHead->pPrevious=pNode;
		list.pHead=pNode;
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
		sanPham *d=pTmp->data;
		cout<<d->ma<<"\t"<<d->ten<<"\t"<<d->gia<<"\n";
		pTmp=pTmp->pNext;
	}
}

void sortList(doubleList &list)
{
	for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
		{
		
			if(pTmp->data->gia < pTmp2->data->gia)
			{
				sanPham *d1=pTmp->data;
				int ma1=d1->ma;
				char ten1[250];
				strcpy(ten1,d1->ten);
				double gia1=d1->gia;
				
				sanPham *d2=pTmp2->data;
				pTmp->data->ma=d2->ma;
				strcpy(pTmp->data->ten,d2->ten);
				pTmp->data->gia=d2->gia;
				
				pTmp2->data->ma=ma1;
				strcpy(pTmp2->data->ten,ten1);
				pTmp2->data->gia=gia1;		
			}
		}
	}
}

doubleList locSanPhamTheoGia(doubleList listGoc,double gia)
{
	doubleList list;
	initialize(list);
	Node *p=listGoc.pHead;
	while(p!=NULL)
	{
		if(p->data->gia > gia)
		{
			sanPham *d=p->data;
			insertFirst(list,d);
		}
		p=p->pNext;
	}
	return list;
}


int main(int argc, char** argv) {
	doubleList list;
	initialize(list);
	
	sanPham *sp1=new sanPham;
	sp1->ma=1;
	strcpy(sp1->ten,"Coca");
	sp1->gia=12.5;
	insertFirst(list,sp1);
	
	sanPham *sp2=new sanPham;
	sp2->ma=2;
	strcpy(sp2->ten,"Pepsi");
	sp2->gia=16.3;
	insertFirst(list,sp2);
	
	sanPham *sp3=new sanPham;
	sp3->ma=3;
	strcpy(sp3->ten,"Sting");
	sp3->gia=13.8;
	insertFirst(list,sp3);
	
	printList(list);
	
	sortList(list);
	cout<<"\nDanh sach sau sap xep:\n";
	printList(list);
	
	doubleList listGia=locSanPhamTheoGia(list,13);
	cout<<"\nLoc san pham theo gia > 13: \n";
	printList(listGia);
	
	return 0;
}
