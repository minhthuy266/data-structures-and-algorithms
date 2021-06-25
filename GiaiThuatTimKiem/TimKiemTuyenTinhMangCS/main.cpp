#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void nhapMang(int M[],int n);
void xuatMang(int M[],int n);
int linearSearch(int M[],int n,int x);

int main(int argc, char** argv) {
	int n=6;
	int M[n];
	nhapMang(M,n);
	cout<<"Mang ngau nhien: \n";
	xuatMang(M,n);
	int x;
	cout<<"\nNhap mot so de tim kiem: ";
	cin>>x;
	int kq=linearSearch(M,n,x);
	if(kq==-1)
		cout<<"Khong thay "<<x<<" trong mang";
	else
		cout<<x<<" o vi tri thu: "<<kq;

	return 0;
}

void nhapMang(int M[],int n)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		M[i]=rand()%100;
	}
}

void xuatMang(int M[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<M[i]<<"\t";
	}
}

int linearSearch(int M[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(M[i]==x)
			return i;
	}
	return -1;
}

