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
};

void initialize(singleList &list)
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
	}
	else
	{
		cout<<"Cap phat bo nho that bai!";
	}
	return pNode;
};

void printList(singleList list)
{
	Node *pTmp=list.pHead;
	if(pTmp==NULL)
	{
		cout<<"Danh sach rong!";
		return;
	}
	while(pTmp!=NULL)
	{
		cout<<pTmp->data<<"\t";
		pTmp=pTmp->pNext;
	}
}

int sizeOfList(singleList list)
{
	Node *pTmp=list.pHead;
	int nSize=0;
	while(pTmp!=NULL)
	{
		pTmp=pTmp->pNext;
		nSize++;
	}
	return nSize;
}

void insertFirst(singleList &list,int d)
{
	Node *pNode=createNode(d);
	if(list.pHead==NULL)
	{
		list.pHead=pNode;
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
	}
}

void insertMid(singleList &list,int pos,int d)
{
	if(pos<0||pos>=sizeOfList(list))
	{
		cout<<"Vi tri chen khong hop le";
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

void freeMemory(singleList &list)
{
	cout<<"\n---------------------------------------------\nDang xoa...\n";
	while(list.pHead!=NULL)
	{
		Node *pTmp=list.pHead;
		list.pHead=pTmp->pNext;
		pTmp->pNext=NULL;
		cout<<pTmp->data<<" da bi xoa \n";
		delete pTmp;
		pTmp=NULL;
	}
	cout<<"\n---------------------------------------------\n";
	cout<<"Xoa xong!";
}

int main(int argc, char** argv) {
	singleList list;
	initialize(list);
	insertFirst(list,10);
	insertLast(list,113);
	insertFirst(list,5);
	insertFirst(list,7);
	insertFirst(list,3);
	insertMid(list,1,10000);
	insertMid(list,2,-10000);
	insertLast(list,18);
	printList(list);
	cout<<"\n---------------------------------------------\n";
	cout<<"\nXoa so 20: \n";
	removeNode(list,3);
	printList(list);
	int n=sizeOfList(list);
	cout<<"\n---------------------------------------------\n";
	cout<<"\nCo "<<n<<" Node";
	int d;
	cout<<"\n---------------------------------------------\n";
	cout<<"\nNhap gia tri muon tim: ";
	cin>>d;
	Node *pSearch=searchNode(list,d);
	if(pSearch!=NULL)
		cout<<"Tim thay "<<pSearch->data;
	else
		cout<<"Khong tim thay "<<d;
	sortList(list);
	cout<<"\n---------------------------------------------\n";
	cout<<"\nDanh sach sau khi sap xep: \n";
	printList(list);
	freeMemory(list);
	
	return 0;
}
