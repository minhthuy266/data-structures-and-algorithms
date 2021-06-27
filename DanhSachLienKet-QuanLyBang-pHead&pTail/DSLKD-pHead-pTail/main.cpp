#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node
{
	int data;
	Node *pNext;
};

struct singleList
{
	Node *pHead;
	Node *pTail;
};

void initialize(singleList &list)
{
	list.pHead=list.pTail=NULL;
}

void printList(singleList list)
{
	Node *pTmp=list.pHead;
	if(pTmp==NULL)
	{
		cout<<"Danh sach rong!";
	}
	else
	{
		while(pTmp!=NULL)
		{
			cout<<pTmp->data<<"\t";
			pTmp=pTmp->pNext;
		}
	}
}

int sizeOfList(singleList list)
{
	Node *pTmp=list.pHead;
	int nSize=0;
	while(pTmp!=NULL)
	{
		nSize++;
		pTmp=pTmp->pNext;
	}
	return nSize;
}

Node *createNode(int d)
{
	Node *pNode=new Node;
	if(pNode==NULL)
	{
		cout<<"Loi cap phat bo nho";
	}
	else
	{
		pNode->data=d;
		pNode->pNext=NULL;
	}
	return pNode;
}

void insertFirst(singleList &list,int d)
{
	Node *pNode=createNode(d);
	if(list.pHead==NULL)
	{
		list.pHead=list.pTail=pNode;
	}
	else
	{
		pNode->pNext=list.pHead;
		list.pHead=pNode;
	}
}

void insertLast(singleList &list,int d)
{
	Node *pNode=createNode(d);
	if(list.pTail==NULL)
	{
		list.pHead=list.pTail=pNode;
	}
	else
	{
		list.pTail->pNext=pNode;
		list.pTail=pNode;
	}
}

void insertMid(singleList &list,int pos,int d)
{
	if(pos<0||pos>=sizeOfList(list))
	{
		cout<<"Vi tri chen khong hop le!\n";
		return;
	}
	if(pos==0)
		insertFirst(list,d);
	else if(pos==sizeOfList(list)-1)
		insertLast(list,d);
	else
	{
		Node *pNode=createNode(d);
		Node *pIns=list.pHead;
		Node *pPre=NULL;
		int i=0;
		while(pIns!=NULL)
		{
			if(i==pos) // Vi tri muon chen
				break;
			pPre=pIns;
			pIns=pIns->pNext;
			i++;
		}
		pPre->pNext=pNode;
		pNode->pNext=pIns;
	}
}

void removeNode(singleList &list,int d)
{
	Node *pDel=list.pHead;
	if(pDel==NULL)
	{
		cout<<"Danh sach rong!";
	}
	else
	{
		Node *pPre=NULL;
		while(pDel!=NULL)
		{
			if(pDel->data==d)
				break;
			pPre=pDel;
			pDel=pDel->pNext;
		}
		if(pDel==NULL)
		{
			cout<<"Khong tim thay "<<d<<" can xoa!";
		}
		else
		{
			if(pDel==list.pHead)
			{
				list.pHead=list.pHead->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
			
			else if(pDel->pNext==NULL)
			{
				list.pTail=pPre;
				pPre->pNext=NULL;
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

Node *searchNode(singleList list,int d)
{
	Node *pTmp=list.pHead;
	while(pTmp!=NULL)
	{
		if(pTmp->data==d)
			break;
		pTmp=pTmp->pNext;
	}
	return pTmp;
}

void sortList(singleList &list)
{
	for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		for(Node *pTmp2=list.pHead;pTmp2!=NULL;pTmp2=pTmp2->pNext)
		{
			if(pTmp->data<pTmp2->data)
			{
				int tmp=pTmp->data;
				pTmp->data=pTmp2->data;
				pTmp2->data=tmp;
			}
		}
	}
}

int main(int argc, char** argv) {
	singleList list;
	initialize(list);
	insertFirst(list,10);
	insertFirst(list,7);
	insertFirst(list,5);
	insertLast(list,9);
	insertMid(list,0,1000);
	insertMid(list,1,1001);
	cout<<"\nDanh sach node: \n";
	printList(list);
	int d;
	cout<<"\nNhap node can xoa: ";
	cin>>d;
	cout<<"\nDanh sach node sau khi xoa: \n";
	removeNode(list,d);
	printList(list);
	int size=sizeOfList(list);
	cout<<"\nCo "<<size<<" node trong danh sach\n";
	cout<<"\nNhap gia tri muon tim: ";
	cin>>d;
	Node *pSearch=searchNode(list,d);
	if(pSearch!=NULL)
		cout<<"Tim thay "<<pSearch->data;
	else
		cout<<"Khong tim thay "<<d;
	sortList(list);
	cout<<"\nDanh sach sau khi sap xep: \n";
	printList(list);
	return 0;
}
