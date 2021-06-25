#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct sinhVien
{
	char ma[10];
	char ten[150];
	bool gioitinh;
};

void nhapDanhSach(sinhVien dSSv[],int siso);
void xuatDanhSach(sinhVien dSSv[],int siso);
sinhVien *timSinhVienTheoMa(sinhVien dSSv[],int siso,char matim[]);

int main(int argc, char** argv) {
	int siso=3;
	sinhVien dSSv[siso];
	nhapDanhSach(dSSv,siso);
	cout<<"Danh sach sinh vien sau khi nhap: \n";
	xuatDanhSach(dSSv,siso);
	char matim[10];
	cout<<"Nhap ma muon tim: ";
	gets(matim);
	sinhVien *pSV=timSinhVienTheoMa(dSSv,siso,matim);
	if(pSV==NULL)
	{
		cout<<"Khong tim thay ma "<<matim;
	}
	else
	{
		cout<<"Tim thay sinh vien co ma = "<<matim<<endl;
		cout<<pSV->ma<<"-"<<pSV->ten<<"-"<<(pSV->gioitinh==true?"Nu":"Nam")<<endl;
	}
	
	cout<<"Moi ban nhap gioi tinh (m/f): ";
	char gender[2];
	gets(gender);
	for(int i=0;i<siso;i++)
	{
		bool genderbool=false; //nam
		if(strcmp(gender,"f"))
			genderbool=true; //nu
		if(dSSv[i].gioitinh==genderbool)
		{
			cout<<dSSv[i].ma<<"\t"<<dSSv[i].ten<<"\t"<<(dSSv[i].gioitinh==true?"Nu":"Nam")<<endl;
		}
	}
	return 0;
}

void nhapDanhSach(sinhVien dSSv[],int siso)
{
	for(int i=0;i<siso;i++)
	{
		cout<<"Nhap ma: ";
		gets(dSSv[i].ma);
		cout<<"Nhap ten: ";
		gets(dSSv[i].ten);
		cout<<"Gioi tinh (m/f): ";
		char gt[2];
		gets(gt);
		if(strcmp(gt,"m")==0)
			dSSv[i].gioitinh=false;
		else
			dSSv[i].gioitinh=true;
	}
}
void xuatDanhSach(sinhVien dSSv[],int siso)
{
	for(int i=0;i<siso;i++)
	{
		cout<<dSSv[i].ma<<"\t"<<dSSv[i].ten<<"\t"<<(dSSv[i].gioitinh==true?"Nu":"Nam")<<endl;
	}
}

sinhVien *timSinhVienTheoMa(sinhVien dSSv[],int siso,char matim[])
{
	for(int i=0;i<siso;i++)
	{
		if(strcmp(dSSv[i].ma,matim)==0)
		{
			return &dSSv[i];
		}
	}
	return NULL;
}



