#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct sanPham
{
	int ma;
	char ten[150];
	float gia;
};

void nhapDanhSach(sanPham dSSp[],int n);
void xuatDanhSach(sanPham dSSp[],int n);
sanPham *timSanPham(sanPham dSSp[],int n,float giatim);

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so san pham: ";
	cin>>n;
	sanPham dSSp[n];
	nhapDanhSach(dSSp,n);
	cout<<"San pham sau khi nhap: \n";
	xuatDanhSach(dSSp,n);
	float giatim;
	cout<<"Nhap gia muon tim: ";
	cin>>giatim;
	sanPham *sp=timSanPham(dSSp,n,giatim);
	if(sp==NULL)
	{
		cout<<"Khong thay san pham co gia = "<<giatim;
	}
	else 
	{
		cout<<sp->ma<<"\t"<<sp->ten<<"\t"<<sp->gia;
	}
	return 0;
}

void nhapDanhSach(sanPham dSSp[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap san pham thu: "<<i<<endl;
		cout<<"Ma: ";
		cin>>dSSp[i].ma;
		cin.ignore();
		cout<<"Ten: ";
		gets(dSSp[i].ten);
		cout<<"Gia: ";
		cin>>dSSp[i].gia;	
	}
}

void xuatDanhSach(sanPham dSSp[],int n)
{
	for(int i=0;i<n;i++)
	{
		sanPham sp=dSSp[i];
		cout<<sp.ma<<"\t"<<sp.ten<<"\t"<<sp.gia<<endl;
	}
}

sanPham *timSanPham(sanPham dSSp[],int n,float giatim)
{
	int left=0;
	int right=n-1;
	int mid=0;
	
	do
	{
		int mid=(left+right)/2;
		sanPham sp=dSSp[mid];
		if(sp.gia==giatim)
			return &sp;
		else if(sp.gia>giatim)
			right=mid-1;
		else
			left=mid+1;
	}
	while(left<=right);
	return NULL;
	
}
