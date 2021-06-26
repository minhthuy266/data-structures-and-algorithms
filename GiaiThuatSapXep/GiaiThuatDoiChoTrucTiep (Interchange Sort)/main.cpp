#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
Y tuong
- Xet nghich the co trong day va lam triet tieu dan chung di
- Xuat phat tu dau day, tim tat ca cac nghich the chua phan tu nay, 
triet tieu chung voi phan tu tuong ung trong cap nghich th
- Lap lai xu ly tren voi cac phan tu tiep theo trong day

Cac buoc lam
1. i=0; // Bat dau tu dau day
2. j=i+1; // Tim cac phan tu M[j]<M[i], j>i;
3. Trong khi j<=N thuc hien
- Neu M[j]<M[i] => do cho
- j=j+1;
4. i=i+1;
- Neu i<n. Lap lai buoc 2
- Nguoc lai dunf
*/
void nhapMang(int M[],int n);
void xuatMang(int M[],int n);
int interchangeSort(int M[],int n);


int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	int M[n];
	nhapMang(M,n);
	cout<<"Mang sau khi nhap: \n";
	xuatMang(M,n);
	cout<<"\nMang sau khi sap xep: \n";
	interchangeSort(M,n);
	xuatMang(M,n);
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

int interchangeSort(int M[],int n)
{
	int i,j;
	for(int i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(M[j]<M[i])
			{
				int temp=M[i];
				M[i]=M[j];
				M[j]=temp;
			}
		}
	}
}
