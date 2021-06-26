#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
* Y tuong: mo phong 1 trong nhung cach sap sep tu nhien nhat trong thuc te
- Chon phan tu nho nhat trong N phan tu dau, dua ve vi tri dau day
- Xem day con N-1 phan tu, bat dau tu vi tri thu 2, lap lai nhu tren

* Cach lam
1. i=0;
2. Tim M[min] trong day tu m[i] den M[N-1]
3. Neu min != i => Hoan vi M[min] va M[i]
4. Neu i < N-1 thi i=i+1, lap lai buoc 2
5. Nguoc lai, dung => xong

* So lan so sanh la:
	(n(n-1))/2
*/

void nhapMang(int M[],int n);
void xuatMang(int M[],int n);
void selectionSort(int M[],int n);

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	int M[n];
	nhapMang(M,n);
	cout<<"Mang sau khi nhap: \n";
	xuatMang(M,n);
	cout<<"\n------------------------------------------------\n";
	cout<<"Mang sau khi sap xep: \n";
	selectionSort(M,n);
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

void selectionSort(int M[],int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(M[j]<M[min])
				min=j;
		}
		if(min!=i)
		{
			int temp=M[i];
			M[i]=M[min];
			M[min]=temp;
		}
	}
}
