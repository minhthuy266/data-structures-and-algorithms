#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
Cac buoc lam
1. i=1; //Gia su co doan M[0] da duoc sap
2. x=M[i]. Tim vi tri pos thich hop trong doan M[0] den M[i-1]
3. Doi cho cac phan tu tu M[pos] den M[i-1] sang vi tri 1 de danh cho cho M[i]
4. M[pos]=x //Co doan M[0]...M[i-1] da duoc sap xep
5. i = i + 1;
	Neu i<n lap lai buoc 2
	Nguoc lai dung
*/

void nhapMang(int M[],int n);
void xuatMang(int M[],int n);
void insertionSort(int M[],int n);

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	int M[n];
	nhapMang(M,n);
	cout<<"Mang sau khi nhap: \n";
	xuatMang(M,n);
	cout<<"\nMang sau khi sap xep: \n";
	insertionSort(M,n);
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

void insertionSort(int M[],int n)
{
	// Luu vi tri can chen
	int pos=0;
	// Luu tru gia tri M[i] tranh bi ghi de khi doi cho cac phan tu
	int x;
	// Xem doan M[0] da sap
	for(int i=1;i<n;i++)
	{
		x=M[i];
		for(pos=i;(pos>0)&&(M[pos-1]>x);pos--)
		{
			M[pos]=M[pos-1];
		}
		M[pos]=x; //Chen x vao day
	}
}

