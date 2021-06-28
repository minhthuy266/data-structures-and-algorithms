#include <iostream>
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
}
void printList(doubleList list)
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

int sizeOfList(doubleList list)
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

void insertFirst(doubleList &list,int d)
{
	Node *pNode=createNode(d);
	if(list.pHead==NULL)
	{
		list.pHead=pNode=list.pTail=pNode;
	}
	else
	{
		pNode->pNext=list.pHead;
		list.pHead->pPrevious=pNode;
		list.pHead=pNode;
	}
}

void insertLast(doubleList &list,int d)
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

void insertMid(doubleList &list,int pos,int d)
{
	if(pos<0||pos>=sizeOfList(list))
	{
		cout<<"Vi tri chen khong hop le\n";
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
		pNode->pNext=pIns;
		pNode->pPrevious=pPre;
		pPre->pNext=pNode;
		pIns->pPrevious=pNode;
	}
}

void removeNode(doubleList &list,int d)
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
}

Node *searchNode(doubleList list,int d)
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

void sortList(doubleList &list)
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
	doubleList list;
	initialize(list);
	insertFirst(list,10);
	insertFirst(list,5);
	insertLast(list,9999);
	insertFirst(list,7);
	insertFirst(list,3);
	insertLast(list,1000);
	insertMid(list,0,99);
	insertMid(list,4,1008);
	cout<<"Danh sach lien ket doi la: \n";
	printList(list);
	
	int d;
	cout<<"\nNhap node can xoa: ";
	cin>>d;
	cout<<"\nDanh sach node sau khi xoa: \n";
	removeNode(list,d);
	printList(list);
	
	int f;
	cout<<"\nNhap gia tri muon tim: ";
	cin>>f;
	Node *pSearch=searchNode(list,f);
	if(pSearch!=NULL)
		cout<<"Tim thay "<<pSearch->data;
	else
		cout<<"Khong tim thay "<<f;
		
	sortList(list);
	cout<<"\nDanh sach sau khi sap xep: \n";
	printList(list);
	
	return 0;
}
