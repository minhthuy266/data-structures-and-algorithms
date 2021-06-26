#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
Cac buoc lam:
1. Chon tuy y mot phan tu M[k] trong day la gia tri moc
	l<=k<=r
	pivot=M[k]; i=l; j=r;
2. Phat hien va hieu chinh cap phan tu M[i], M[j] nam sai cho:
	2a. Trong khi (M[i]<x) i++
	2b. Trong khi (M[j]>x) j--
	2c. Neu i<=j // M[i]>=pivot>=M[j] ma M[j] dung sau M[i]
	=> Hoan vi M[i] va M[j]
3. 
	Neu i<j. Dung lai buoc 2 // Chua xet het mang
	Neu i>=j Dung
*/
void nhapMang(int M[],int n);
void xuatMang(int M[],int n);
void quickSort(int M[],int left,int right);

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	int M[n];
	nhapMang(M,n);
	cout<<"Mang sau khi nhap: \n";
	xuatMang(M,n);
	cout<<"\n------------------------------------------------\n";
	quickSort(M,0,n-1);
	cout<<"Mang sau khi sap xep: \n";
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

void quickSort(int M[],int left,int right)
{
	if(left>=right) return;
	int pivot = M[(left+right)/2];
	int i=left, j=right;
	do
	{
		while (M[i] < pivot) i++;
		while (M[j] > pivot) j--;
		if(i<=j)
		{
			int temp=M[i];
			M[i]=M[j];
			M[j]=temp;
			i++;
			j--;
		}
	} while(i<j);
		quickSort(M,left,j);
		quickSort(M,i,right);
}
