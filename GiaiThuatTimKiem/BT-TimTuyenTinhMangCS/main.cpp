#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void nhapMang(int F[],int n);
void xuatMang(int F[],int n);
int dem(int F[],int n,int x);
int maxChan(int F[],int n);
int maxLe(int F[],int n);

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	int F[n];
	nhapMang(F,n);
	cout<<"Mang sau khi nhap: \n";
	xuatMang(F,n);
	int x;
	cout<<"\nNhap x: ";
	cin>>x;
	int d=dem(F,n,x);
	cout<<"\n";
	cout<<x<<" xuat hien "<<d<<" lan \n";
	int max=maxChan(F,n);
	if(max=-99999)
		cout<<"Mang khong co so chan";
	else 
		cout<<"max = "<<max;
		
	int maxL=maxLe(F,n);
	if(maxL=-99999)
		cout<<"\nMang khong co so le";
	else 
		cout<<"max = "<<maxL;
	return 0;
}

void nhapMang(int F[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap phan tu thu "<<i<<": ";
		cin>>F[i];
	}
}

void xuatMang(int F[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<F[i]<<"\t";
	}
}

int dem(int F[],int n,int x)
{
	int d=0;
	for(int i=0;i<n;i++)
	{
		if(F[i]==x)
			d++;
	}
	return d;
}

int maxChan(int F[],int n)
{
	int max=-99999;
	for(int i=0;i<n;i++)
	{
		if(F[i]>max && F[i]%2==0)
			max=F[i];
	}
	return max;
}

int maxLe(int F[],int n)
{
	int max=-99999;
	for(int i=0;i<n;i++)
	{
		int f2=F[i];
		if(f2>max && f2%2!=0)
			max=f2;
	}
	return max;
}
