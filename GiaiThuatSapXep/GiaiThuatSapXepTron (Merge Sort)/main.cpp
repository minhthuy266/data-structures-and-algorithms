#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* 
Tu tuong tron:
- Co 2 mang da duoc sap xep chieu dai N,M
- Tao ra 1 mang chung duoc sap xep

Cac buoc lam:
1. Chon min cua 2 phan tu dau day chep qua mang ket qua
2. Huy phan tu min
3. Neu chua den cuoi mang tro ve buoc 1
4. Neu den cuoi mang: chep phan con lai cua mang ki vao ket qua
*/

void nhapMang(int M[],int n);
void xuatMang(int M[],int n);
void mergeSort(int M[],int left,int right);
void merge(int M[],int left,int mid,int right);

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	int M[n];
	nhapMang(M,n);
	cout<<"Mang sau khi nhap: \n";
	xuatMang(M,n);
	mergeSort(M,0,n-1);
	cout<<"\nMang sau khi sap xep: \n";
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

void mergeSort(int M[],int left,int right)
{
	if(left>=right) return;
	int mid = (left+right)/2;
	mergeSort(M,left,mid);
	mergeSort(M,mid+1,right);
	merge(M,left,mid,right);
}


void merge(int M[],int left,int mid,int right)
{
	int nTemp = right-left+1;
	int temp[nTemp];
	int pos=0;
	int i=left;
	int j=mid+1;
	while(!(i>mid && j>right))
	{
		if((i<=mid && j<=right && M[i]<M[j] || j>right))
			temp[pos++]=M[i++];
		else
			temp[pos++]=M[j++];
	}
	for(i=0;i<nTemp;i++)
		M[left+i]=temp[i];
}
