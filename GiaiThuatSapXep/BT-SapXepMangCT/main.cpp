#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nhanVien
{
	int ma;
	char ten[50];
	int tuoi;
};

nhanVien *nhapNhanVien();
void xuatNhanVien(nhanVien *nv);
void nhapDanhSach(nhanVien **&dSNv,int n);
void xuatDanhSach(nhanVien **dSNv,int n);
void interchangeSort(nhanVien **dSNv,int n);
void quickSort(nhanVien **dSNv,int left,int right);

int main(int argc, char** argv) {
	int n=3;
	nhanVien **dSNv;
	nhapDanhSach(dSNv,n);
	cout<<"\n----------------------------------------------------------------------------------------------\n";
	cout<<"Danh sach sau khi nhap: \n";
	xuatDanhSach(dSNv,n);
	interchangeSort(dSNv,n);
	cout<<"\n----------------------------------------------------------------------------------------------\n";
	cout<<"Danh sach sau khi sap xep tuoi (Interchange Sort): \n";
	xuatDanhSach(dSNv,n);
	quickSort(dSNv,0,n-1);
	cout<<"\n----------------------------------------------------------------------------------------------\n";
	cout<<"Danh sach sau khi sap xep ten (Quick Sort): \n";
	xuatDanhSach(dSNv,n);
	return 0;
}

nhanVien *nhapNhanVien()
{
	nhanVien *nv=new nhanVien;
	cout<<"Nhap ma: ";
	cin>>nv->ma;
	cin.ignore();
	cout<<"Nhap ten: ";
	gets(nv->ten);
	cout<<"Nhap tuoi: ";
	cin>>nv->tuoi;
	cin.ignore();
	return nv;
}
void xuatNhanVien(nhanVien *nv)
{
	cout<<nv->ma<<"\t"<<nv->ten<<"\t"<<nv->tuoi<<"\n";
}

void nhapDanhSach(nhanVien **&dSNv,int n)
{
	dSNv=new nhanVien*[n];
	for(int i=0;i<n;i++)
	{
		*(dSNv+i)=nhapNhanVien();
	}
}

void xuatDanhSach(nhanVien **dSNv,int n)
{
	for(int i=0;i<n;i++)
	{
		nhanVien *nv=*(dSNv+i);
		xuatNhanVien(nv);
	}
}

void interchangeSort(nhanVien **dSNv,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			nhanVien *nvi=*(dSNv+i);
			nhanVien *nvj=*(dSNv+j);
			if(nvj->tuoi<nvi->tuoi)
			{
				int ma=nvi->ma;
				char ten[150];
				strcpy(ten,nvi->ten);
				int tuoi=nvi->tuoi;
				
				nvi->ma=nvj->ma;
				strcpy(nvi->ten,nvj->ten);
				nvi->tuoi=nvj->tuoi;
				
				nvj->ma=ma;
				strcpy(nvj->ten,ten);
				nvj->tuoi=tuoi;		
			}
		}
	}
}

void quickSort(nhanVien **dSNv,int left,int right)
{
	if(left>=right) return;
	nhanVien *pivot=*(dSNv+((left+right)/2));
	int i=left, j=right;
	do
	{
		while (stricmp((*(dSNv+i))->ten,pivot->ten)<0) i++;
		while (stricmp((*(dSNv+j))->ten,pivot->ten)>0) j--;
		if(i<=j)
		{
			nhanVien *nvi=*(dSNv+i);
			nhanVien *nvj=*(dSNv+j);
			
			int ma=nvi->ma;
			char ten[150];
			strcpy(ten,nvi->ten);
			int tuoi=nvi->tuoi;
				
			nvi->ma=nvj->ma;
			strcpy(nvi->ten,nvj->ten);
			nvi->tuoi=nvj->tuoi;
				
			nvj->ma=ma;
			strcpy(nvj->ten,ten);
			nvj->tuoi=tuoi;	
			
			i++;
			j--;
		}
	}
		
 	while(i<j);
 		quickSort(dSNv,left,j);
		quickSort(dSNv,i,right);	
}


