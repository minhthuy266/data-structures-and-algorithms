#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// Dac trung: Da duoc sap xep theo 1 thu tu nao do

void nhapMang(int M[],int n);
void xuatMang(int M[],int n);
int bSearch(int M[],int n,int x);
int bSearchRecur(int M[],int x,int left,int right);

int main(int argc, char** argv) {
	int n=5;
	int M[n];
	nhapMang(M,n);
	cout<<"Mang sau khi nhap: \n";
	xuatMang(M,n);
	cout<<"\nNhap so can tim: ";
	int x;
	cin>>x;
	//int kq=bSearch(M,n,x);
	int kq=bSearchRecur(M,x,0,n-1);
	if(kq==-1)
		cout<<"Khong thay "<<x<<endl;
	else
		cout<<"Thay "<<x<<" o vi tri "<<kq<<endl;
	return 0;
}

void nhapMang(int M[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap M["<<i<<"] = ";
		cin>>M[i];
	}
}

void xuatMang(int M[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<M[i]<<"\t";
	}
}
int bSearch(int M[],int n,int x)
{
	int left=0;
	int right=n-1;
	int mid;
	
	do
	{
		mid=(left+right)/2;
		if(M[mid]==x)
			return mid;
		else if(M[mid]>x)
			right=mid-1;
		else 
			left=mid+1;
	}
	while(left<=right);
	return -1;
}

int bSearchRecur(int M[],int x,int left,int right)
{
	if(left>right)
		return -1;
	int mid=(left+right)/2;
	if(M[mid]==x)
		return mid;
	if(M[mid]>x)
		return bSearchRecur(M,x,left,mid-1);
	else
		return bSearchRecur(M,x,mid+1,right);
}
