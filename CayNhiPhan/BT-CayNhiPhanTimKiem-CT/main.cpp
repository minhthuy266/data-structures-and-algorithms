#include <iostream>
#include <string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct sanPham
{
	int ma;
	char ten[250];
	float gia;
};

struct TNode
{
	sanPham *value;
	TNode *pLeft;
	TNode *pRight;
};

typedef TNode *BTree;

TNode *createNode(sanPham *v)
{
	TNode *node=new TNode;
	node->value=v;
	node->pLeft=node->pRight=NULL;
	return node;
}

void insertNode(BTree &root,sanPham *v)
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
			if(tmp->value->ma > node->value->ma)
				tmp=tmp->pLeft;
			else
				tmp=tmp->pRight;
		}
		if(parent->value->ma>node->value->ma)
			parent->pLeft=node;
		else
			parent->pRight=node;
	}
}

void postOrder_LRN(BTree root)
{
	if(root!=NULL)
	{
		postOrder_LRN(root->pLeft);
		postOrder_LRN(root->pRight);
		cout<<root->value->ma<<"\t"<<root->value->ten<<"\t"<<root->value->gia<<"\n";
	}
}

TNode *search(BTree root,int v)
{
	if((root==NULL)||(root->value->ma==v))
		return root;
	else
		if(v<root->value->ma)
			return search(root->pLeft,v);
		else if(v>root->value->ma)
			return search(root->pRight,v);
}

int main(int argc, char** argv) {
	BTree root=NULL;
	sanPham *s1=new sanPham;
	s1->ma=100;
	strcpy(s1->ten,"Coca");
	s1->gia=15.5;
	insertNode(root,s1);
	
	sanPham *s2=new sanPham;
	s2->ma=50;
	strcpy(s2->ten,"Pepsi");
	s2->gia=20;
	insertNode(root,s2);
	
	sanPham *s3=new sanPham;
	s3->ma=200;
	strcpy(s3->ten,"Redbull");
	s3->gia=23.9;
	insertNode(root,s3);
	
	cout<<"\nDanh sach san pham sau khi sap dung postOrder: \n";
	postOrder_LRN(root);
	
	int v;
	cout<<"\nNhap gia tri can tim: ";
	cin>>v;
	TNode *node=search(root,v);
	if(node==NULL)
	{
		cout<<"Khong tim thay ma "<<v<<"!";
	}	
	else
	{
		cout<<"Tim thay "<<v<": ";
		cout<<endl;
		sanPham *s=node->value;
		cout<<s->ma<<"\t"<<s->ten<<"\t"<<s->gia<<"\n";
	}
	
	return 0;
}
