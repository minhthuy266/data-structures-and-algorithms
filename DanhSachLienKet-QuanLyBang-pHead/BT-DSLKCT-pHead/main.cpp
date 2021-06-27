#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct sinhVien
{
	int ma;
	char ten[150];
};

struct Node
{
	sinhVien *data;
	Node *pNext;
};

struct singleList
{
	Node *pHead;
};

void initialize(singleList *&list)
{
	list=new singleList;
	list->pHead=NULL;
};

sinhVien *nhapSinhVien()
{
	sinhVien *sv=new sinhVien;
	cout<<"Ma: ";
	cin>>sv->ma;
	cin.ignore();
	cout<<"Ten: ";
	gets(sv->ten);
	return sv;
}

Node *createNode(sinhVien *sv)
{
	Node *pNode=new Node;
	if(pNode!=NULL)
	{
		pNode->data=sv;
		pNode->pNext=NULL;
	}
	else
	{
		cout<<"\nCap phat bo nho that bai!\n";
	}
	return pNode;
}

void insertLast(singleList *&list,sinhVien *sv)
{
	Node *pNode=createNode(sv);
	if(list->pHead==NULL)
	{
		list->pHead=pNode;
	}
	else
	{
		Node *pTmp=list->pHead;
		while(pTmp->pNext!=NULL)
		{
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=pNode;
	}
}

void printList(singleList *list)
{
	Node *pTmp=list->pHead;
	if(pTmp==NULL)
	{
		cout<<"Danh sach rong!";
		return;
	}
	while(pTmp!=NULL)
	{
		sinhVien *sv=pTmp->data;
		cout<<sv->ma<<"\t"<<sv->ten<<"\n";
		pTmp=pTmp->pNext;
	}
}

void sortList(singleList *&list)
{
	for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
		{
			sinhVien *svTmp=pTmp->data;
			sinhVien *svTmp2=pTmp2->data;
			if(svTmp2->ma<svTmp->ma)
			{
				int ma=svTmp->ma;
				char ten[150];
				strcpy(ten,svTmp->ten);
				
				svTmp->ma=svTmp2->ma;
				strcpy(svTmp->ten,svTmp2->ten);
				svTmp2->ma=ma;
				strcpy(svTmp2->ten,ten);
			}
		}
	}
}

void removeNode(singleList *&list,int ma)
{
	Node *pDel=list->pHead;
	if(pDel==NULL)
	{
		cout<<"Danh sach rong!";
	}
	else
	{
		Node *pPre=NULL;
		while(pDel!=NULL)
		{
			sinhVien *sv=pDel->data;
			if(sv->ma==ma)
				break;
			pPre=pDel;
			pDel=pDel->pNext;
		}
		if(pDel==NULL)
		{
			cout<<"Khong thay ma = "<<ma;
		}
		else
		{
			if(pDel==list->pHead)
			{
				list->pHead=list->pHead->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
			else
			{
				pPre->pNext=pDel->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
		}
	}
}

int main(int argc, char** argv) {
	singleList *list;
	initialize(list);
	
	sinhVien *teo=nhapSinhVien();
	insertLast(list,teo);
	
	sinhVien *ty=nhapSinhVien();
	insertLast(list,ty);
	
	sinhVien *bin=nhapSinhVien();
	insertLast(list,bin);
	
	cout<<"\nDanh sach sau khi nhap: \n";
	printList(list);
	
	sortList(list);
	cout<<"\nDanh sach sau sap xep:\n";
	printList(list);
	
	cout<<"\nNhap ma muon xoa: ";
	int ma;
	cin>>ma;
	removeNode(list,ma);
	cout<<"\nDanh sach sau khi xoa:\n";
	printList(list);
	
	
	return 0;
}
