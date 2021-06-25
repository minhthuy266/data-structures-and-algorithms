#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void nhapMang(float F[],int n);
void xuatMang(float F[],int n);
int bSearch(float F[],int n,float x);

int main(int argc, char** argv) {
	int n;
	float F[n];
	cout<<"Nhap so phan tu: ";
	cin>>n;
	nhapMang(F,n);
	cout<<"Mang sau khi nhap: \n";
	xuatMang(F,n);
	float x;
	cout<<"\nNhap so can tim: ";
	cin>>x;
	int kq=bSearch(F,n,x);
	if(kq==-1)
		cout<<x<<" khong co trong mang";
	else
		cout<<x<<" o vi tri thu: "<<kq;
	return 0;
}

void nhapMang(float F[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"F["<<i<<"] = ";
		cin>>F[i];
	}
}
void xuatMang(float F[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<F[i]<<"\t";
	}
}

int bSearch(float F[],int n,float x)
{
	int left=0;
	int right=n-1;
	int mid;
	do
	{
		mid=(left+right)/2;
		if(F[mid]==x)
			return mid;
		else if(F[mid]>x)
			left=mid+1;
		else
			right=mid-1;
	}
	while(left<=right);
	return -1;
}
