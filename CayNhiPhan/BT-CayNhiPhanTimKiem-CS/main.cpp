#include <iostream>
#define MAX 100
#include <stdlib.h>
#include <time.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void nhapMang(int M[],int n)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		int x=rand()%100;
		M[i]=x;
	}
}

void xuatMang(int M[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<M[i]<<"\t";
	}
}

struct TNode
{
	int value;
	TNode *pLeft;
	TNode *pRight;
};

typedef TNode *BTree;

TNode *createNode(int v)
{
	TNode *node=new TNode;
	node->value=v;
	node->pLeft=node->pRight=NULL;
}

void insertNode(BTree &root,int v)
{
	TNode *node=createNode(v);
	if(root==NULL)
	{
		root=node;
	}
	else
	{
		BTree tmp=root;
		BTree parent=NULL; // Nut goc khong co cha => parent = NULL
		while(tmp!=NULL)
		{
			parent=tmp;
			if(tmp->value > node->value)
				tmp=tmp->pLeft;
			else
				tmp=tmp->pRight;
		}
		if(parent->value>node->value)
			parent->pLeft=node;
		else
			parent->pRight=node;
	}
}

void inOrder_LNR(BTree root)
{
	if(root!=NULL)
	{
		inOrder_LNR(root->pLeft);
		cout<<root->value<<"\t";
		inOrder_LNR(root->pRight);
	}
}

void nhapMangLenCay(BTree &root,int M[],int n)
{
	for(int i=0;i<n;i++)
	{
		insertNode(root,M[i]);
	}
}

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	int M[n];
	cout<<"\nMang ngau nhien la: \n";
	nhapMang(M,n);
	xuatMang(M,n);
	
	BTree root=NULL;
	nhapMangLenCay(root,M,n);
	cout<<"\nMang sau khi sap xep: \n";
	inOrder_LNR(root);
	
	return 0;
}
