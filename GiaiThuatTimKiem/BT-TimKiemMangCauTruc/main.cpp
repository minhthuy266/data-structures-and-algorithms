#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct book
{
	int ma;
	char ten[150];
	int nam;
};

void nhapDanhSach(book dsBook[],int n);
void xuatDanhSach(book dsBook[],int n);
int soSachTimDuoc=0;
book *sachTheoNamXuatBan(book dsBook[],int n,int year);

int main(int argc, char** argv) {
	cout<<"Nhap so cuon sach: ";
	int n;
	cin>>n;
	book dsBook[n];
	cout<<"Danh sach sau khi nhap: \n";
	nhapDanhSach(dsBook,n);
	xuatDanhSach(dsBook,n);
	cout<<"\nNhap nam muon tim: ";
	int year;
	cin>>year;
	book *dsBookTimDuoc = sachTheoNamXuatBan(dsBook,n,year);
	if(soSachTimDuoc==0)
		cout<<"Khong co cuon sach nao co nam xuat ban = "<<year;
	else
		{
			cout<<"\n Cac sach tim thay: \n";
			xuatDanhSach(dsBookTimDuoc,soSachTimDuoc);
		}
	return 0;
}

void nhapDanhSach(book dsBook[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap sach thu "<<i<<endl;
		cout<<"Ma: ";
		cin>>dsBook[i].ma;
		cin.ignore();
		cout<<"Ten: ";
		gets(dsBook[i].ten);
		cout<<"Nam xuat ban: ";
		cin>>dsBook[i].nam;		
	}
}
void xuatDanhSach(book dsBook[],int n)
{
	for(int i=0;i<n;i++)
	{
		book b=dsBook[i];
		cout<<b.ma<<"\t"<<b.ten<<"\t"<<b.nam<<endl;
	}
}

book *sachTheoNamXuatBan(book dsBook[],int n,int year)
{
	book dsTimDuoc[n];
	soSachTimDuoc=0;
	for(int i=0;i<n;i++)
	{
		book b=dsBook[i];
		if(b.nam==year)
		{
			dsTimDuoc[soSachTimDuoc]=b;
			soSachTimDuoc++;
		}
	}
	return dsTimDuoc;
}
