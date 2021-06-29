#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

void preOrder_NLR(BTree root)
{
	if(root!=NULL)
	{
		cout<<root->value<<"\t";
		preOrder_NLR(root->pLeft);
		preOrder_NLR(root->pRight);
	}
}

void postOrder_LRN(BTree root)
{
	if(root!=NULL)
	{
		postOrder_LRN(root->pLeft);
		postOrder_LRN(root->pRight);
		cout<<root->value<<"\t";
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

int countNode(BTree root)
{
	if(root==NULL)
		return 0;
	else
		return(1+(countNode(root->pLeft)+countNode(root->pRight)));
}

int countLeaf(BTree root)
{
	if(root!=NULL)
		if(root->pLeft==NULL && root->pRight==NULL)
			return 1;
		else
			return countLeaf(root->pLeft)+countLeaf(root->pRight);
	else
		return 0;
}

int max(int a,int b)
{
	return a>b?a:b;
}

int height(BTree root)
{
	if(root==NULL)
		return 0;
	else
		return 1+max(height(root->pLeft),height(root->pRight));
}

TNode *search(BTree root,int v)
{
	if((root==NULL)||(root->value=v))
		return root;
	else
		if(v<root->value)
			return search(root->pLeft,v);
		else if(v>root->value)
			return search(root->pRight,v);
}

/*
XOA MOT NODE KHOI CAY - 3 TRUONG HOP
1. X la nut la => Chi don gian la huy X vi k moc noi den phan tu nao

2. X chi co 1 con (trai hoac phai)
- Truoc khi huy X ta moc noi cha cua X voi con duy nhat cua no

3. X co du ca 2 con
- Khong the huy truc tiep => gian tiep
- Tim 1 phan tu the mang Y (co toi da 1 con)
- Thong tim tai Y => chuyen len luu tai X
- Nut huy that su la Y giong 2 TH ban dau

* Phan tu the mang:
- Phan tu nho nhat (trai nhat) tren cay con phai
- Phan tu lon nhat (phai nhat) tren cay con trai
*/

void removeNode(BTree &root,int v)
{
	if(root==NULL)
	{
		cout<<"Tree is empty";
		return;
	}
	TNode *pParent=NULL;
	TNode *pDel=NULL;
	TNode *pTmp=root;
	while(pTmp!=NULL)
	{
		pParent=pTmp;
		if(pTmp->value>v)
			pTmp=pTmp->pLeft;
		else if(pTmp->value<v)
			pTmp=pTmp->pRight;
		if(pTmp->value==v)
		{
			pDel=pTmp;
			break;
		}
	}
	
	if(pDel==NULL)
	{
		cout<<"Not found!";
		return;
	}
	if(pDel->pLeft==NULL && pDel->pRight==NULL)
	{
		if(pParent->value>pDel->value)
			pParent->pLeft=NULL;
		else
			pParent->pRight=NULL;
		delete pDel;
		pDel=NULL;
	}
	else if(pDel->pLeft!=NULL && pDel->pRight==NULL)
	{
		if(pParent->value>pDel->value)
		{
			pParent->pLeft=pDel->pLeft;
		}
		else
		{
			pParent->pRight=pDel->pLeft;
		}
		pDel->pLeft=NULL;
		delete pDel;
		pDel=NULL;
	}
	else if(pDel->pLeft==NULL && pDel->pRight!=NULL)
	{
		if(pParent->value>pDel->value)
		{
			pParent->pLeft=pDel->pRight;
			pDel->pRight=NULL;
		}
		else
		{
			pParent->pRight=pDel->pRight;
			pDel->pRight=NULL;
		}
		delete pDel;
		pDel=NULL;
	}
	else
	{
		// Tim node trai nhat cua cay con phai
		TNode *pMinOfRight=pDel->pRight;
		TNode *pParentMinOfRight=NULL;
		while(pMinOfRight->pLeft!=NULL)
		{
			pParentMinOfRight=pMinOfRight;
			pMinOfRight=pMinOfRight->pLeft;
		}
		pDel->value=pMinOfRight->value;
		
		if(pParentMinOfRight==NULL)
		{
			pDel->pRight=NULL;
		}
		else if(pParentMinOfRight->value>pMinOfRight->value)
		{
			pParentMinOfRight->pLeft=pMinOfRight->pRight;
		}
		delete pMinOfRight;
		pMinOfRight=NULL;
	}
}

int main(int argc, char** argv) {
	BTree root=NULL;
	insertNode(root,10);
	insertNode(root,20);
	insertNode(root,5);
	insertNode(root,8);
	insertNode(root,15);
	
	cout<<"\nDuyet cay theo preOrder:\n";
	preOrder_NLR(root);
	cout<<"\n----------------------------\n";
	
	cout<<"\nDuyet cay theo postOrder:\n";
	postOrder_LRN(root);
	cout<<"\n----------------------------\n";
	
	cout<<"\nDuyet cay theo inOrder:\n"; // => Day sap xep theo thu tu tang dan
	inOrder_LNR(root);
	cout<<"\n----------------------------\n";
	
	int n1=countNode(root);
	cout<<"\nSo node tren cay: "<<n1<<endl;
	
	int n2=countLeaf(root);
	cout<<"\nSo leaf tren cay: "<<n2<<endl;
	
	int h=height(root);
	cout<<"\nChieu cao cua cay: "<<h<<endl;
	
	int v;
	cout<<"\nNhap gia tri can tim: ";
	cin>>v;
	TNode *s=search(root,v);
	if(s==NULL)
		cout<<"Khong tim thay "<<v<<" tren cay nhi phan!";
	else
		cout<<"Tim thay "<<v<" !";
	
	removeNode(root,20);
	cout<<"\nDuyet cay theo preOrder:\n";
	preOrder_NLR(root);
	cout<<"\n----------------------------\n";
	
	 
	return 0;
}
