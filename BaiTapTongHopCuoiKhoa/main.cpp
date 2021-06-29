#include <iostream>
#include <string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct sinhVien
{
	int ma;
	char ten[250];	
};

struct NodeS
{
	sinhVien *value;
	NodeS *pLeft;
	NodeS *pRight;
};

typedef NodeS *BTree;

struct lopHoc
{
	int ma;
	char ten[250];
};

struct NodeL
{
	lopHoc *value;
	NodeL *pNext;
	NodeL *pPrevious;
	BTree root;
};

struct DLink
{
	NodeL *pHead;
	NodeL *pTail;	
};

// Prototype sinhVien

NodeS *createNodeS(sinhVien *sv);
void initializeBTree(BTree &root);
void insertSinhVien(BTree &root,sinhVien *sv);
void inOrder_LNR(BTree root);

// Prototype lopHoc

NodeL *createNodeL(lopHoc *lh);
void initializeDLink(DLink &link);
void insertLopHoc(DLink &link,NodeL *node);
void printLopHoc(DLink link);
NodeL *searchNodeL(DLink link,int ml);


int main(int argc, char** argv) {
	DLink link;
	initializeDLink(link);
	
	lopHoc *lop1=new lopHoc;
	lop1->ma=1;
	strcpy(lop1->ten,"K21-1A");
	NodeL *node1=createNodeL(lop1);
	insertLopHoc(link,node1);
	
	lopHoc *lop2=new lopHoc;
	lop2->ma=2;
	strcpy(lop2->ten,"K20-2A");
	NodeL *node2=createNodeL(lop2);
	insertLopHoc(link,node2);
	
	lopHoc *lop3=new lopHoc;
	lop3->ma=3;
	strcpy(lop3->ten,"K19-3C");
	NodeL *node3=createNodeL(lop3);
	insertLopHoc(link,node3);
	
	cout<<"Danh sach lop hoc: \n";
	printLopHoc(link);
	
	BTree ds1;
	initializeBTree(ds1);
	
	sinhVien *sv1=new sinhVien;
	sv1->ma=20;
	strcpy(sv1->ten,"Nguyen Van A");
	insertSinhVien(ds1,sv1);
	
	sinhVien *sv2=new sinhVien;
	sv2->ma=30;
	strcpy(sv2->ten,"Nguyen Thi B");
	insertSinhVien(ds1,sv2);
	
	sinhVien *sv3=new sinhVien;
	sv3->ma=40;
	strcpy(sv3->ten,"Nguyen Van L");
	insertSinhVien(ds1,sv3);
	
	node1->root=ds1;
	int ml;
	cout<<"\nNhap ma lop muon tim: ";
	cin>>ml;
	NodeL *kq=searchNodeL(link,ml);
	if(kq!=NULL)
	{
		cout<<"\nTim thay lop hoc "<<kq->value->ten<<endl;
		inOrder_LNR(kq->root);
	}
	else
	{
		cout<<"Khong tim thay lop hoc "<<ml<<endl;
	}
	
	
	return 0;
}

NodeS *createNodeS(sinhVien *sv)
{
	NodeS *node=new NodeS;
	node->value=sv;
	node->pLeft=node->pRight=NULL;
	return node;
}

void initializeBTree(BTree &root)
{
	root=NULL;
}

void insertSinhVien(BTree &root,sinhVien *sv)
{
	NodeS *node=createNodeS(sv);
	if(root==NULL)
	{
		root=node;
	}
	else
	{
		NodeS *tmp=root;
		NodeS *parent=NULL;
		while(tmp!=NULL)
		{
			parent=tmp;
			if(tmp->value->ma>node->value->ma)
			{
				tmp=tmp->pLeft;
			}
			else
			{
				tmp=tmp->pRight;
			}
		}
		if(parent->value->ma>node->value->ma)
		{
			parent->pLeft=node;
		}
		else
		{
			parent->pRight=node;
		}
	}
}

void inOrder_LNR(BTree root)
{
	if(root!=NULL)
	{
		inOrder_LNR(root->pLeft);
		cout<<root->value->ma<<"\t"<<root->value->ten<<"\n";
		inOrder_LNR(root->pRight);
	}
}

NodeL *createNodeL(lopHoc *lh)
{
	NodeL *node=new NodeL;
	node->value=lh;
	node->root=NULL;
	node->pNext=node->pPrevious=NULL;
	return node;
}

void initializeDLink(DLink &link)
{
	link.pHead=link.pTail=NULL;
}

void insertLopHoc(DLink &link,NodeL *node)
{
	if(link.pTail==NULL)
	{
		link.pHead=link.pTail=node;
	}
	else
	{
		link.pTail->pNext=node;
		node->pPrevious=link.pTail;
		link.pTail=node;
	}
}

void printLopHoc(DLink link)
{
	NodeL *node=link.pHead;
	while(node!=NULL)
	{
		lopHoc *lop=node->value;
		cout<<lop->ma<<"\t"<<lop->ten<<"\n";
		node=node->pNext;
	}
}

NodeL *searchNodeL(DLink link,int ml)
{
	NodeL *node=link.pHead;
	while(node!=NULL)
	{
		lopHoc *lop=node->value;
		if(lop->ma==ml)
			break;
		node=node->pNext;
	}
	return node;
}
