#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node
{
	float data;
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

Node *createNode(float d)
{
	Node *pNode=new Node;
	if(pNode!=NULL)
	{
		pNode->data=d;
		pNode->pNext=NULL;
	}
	else
	{
		cout<<"Cap phat bo nho that bai";
	}
	return pNode;
};

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
		cout<<pTmp->data<<"\t";
		pTmp=pTmp->pNext;
	}
}

int sizeOfList(singleList *list)
{
	Node *pTmp=list->pHead;
	int nSize=0;
	while(pTmp!=NULL)
	{
		pTmp=pTmp->pNext;
		nSize++;
	}
	return nSize;
}

void insertFirst(singleList *&list,float d)
{
	Node *pNode=createNode(d);
	if(list->pHead==NULL)
	{
		list->pHead=pNode;
	}
	else
	{
		pNode->pNext=list->pHead;
		list->pHead=pNode;
	}
}

void insertLast(singleList *&list,float d)
{
	Node *pNode=createNode(d);
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

void insertMid(singleList *&list,int pos,float d)
{
	if(pos<0 || pos>=sizeOfList(list))
	{
		cout<<"Vi tri chen khong hop le!";
		return;
	}
	if(pos==0)
		insertFirst(list,d);
	else if(pos==sizeOfList(list)-1)
		insertLast(list,d);
	else
	{
		Node *pNode=createNode(d);
		Node *pIns=list->pHead;
		Node *pPre=NULL;
		int i=0;
		while(pIns!=NULL)
		{
			if(i==pos)
				break;
				pPre=pIns;
				pIns=pIns->pNext;
				i++;
		}
		pNode->pNext=pIns;
		pPre->pNext=pNode;
	}
};

float sumOfList(singleList *list)
{
	Node *pTmp=list->pHead;
	float sum=0;
	while(pTmp!=NULL)
	{
		sum=sum+pTmp->data;
		pTmp=pTmp->pNext;
	}
	return sum;
};

Node *searchNode(singleList *list,float d)
{
	Node *pTmp=list->pHead;
	while(pTmp!=NULL)
	{
		if(pTmp->data=d)
			break;
		pTmp=pTmp->pNext;
	}
	return pTmp;
};

void sortList(singleList *&list)
{
	for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
		{
			if(pTmp2->data<pTmp->data)
			{
				float tmp=pTmp->data;
				pTmp->data=pTmp2->data;
				pTmp2->data=tmp;
			}
		}
	}
};
	
void removeNode(singleList *&list,float d)
{
	Node *pDel=list->pHead;
	if(pDel==NULL)
		cout<<"Danh sach rong!";
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
			cout<<"Khong thay "<<d<<" de xoa";
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
		
};


int main(int argc, char** argv) {
	singleList *list;
	initialize(list);
	insertFirst(list,5.5);
	insertLast(list,7.2);
	insertFirst(list,10.7);
	insertMid(list,1,15.5);
	printList(list);
	
	sortList(list);
	cout<<"\n------------------------------------\n";
	cout<<"\nSort: \n";
	printList(list);
	
	float sum=sumOfList(list);
	cout<<"\n------------------------------------\n";
	cout<<"\nSum = "<<sum<<endl;
	
	cout<<"\n------------------------------------\n";
	cout<<"Nhap gia tri can tim: ";
	float f;
	cin>>f;
	Node *pFind=searchNode(list,f);
	if(pFind==NULL)
	{
		cout<<"Khong thay "<<f;
	}
	else
	{
		cout<<"Thay "<<f;
	}
	
	cout<<"\n------------------------------------\n";
	cout<<"Nhap gia tri muon xoa: ";
	cin>>f;
	removeNode(list,f);
	cout<<"\nDanh sach sau khi xoa: \n";
	printList(list);
	
	return 0;
}
