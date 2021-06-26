#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
* Y tuong sap sep
- Xuat phat tu cuoi (dau) day, doi cho cac cap phan tu ke can de dua pt nho (lon) hon trong cap 
phan tu do ve dung vi tri dung dau (cuoi) day hien hanh, sau do se khong xet den no o buoc tiep theo
- O lan xu ly thu i co vi tri dau day la i
- Lap lai xu ly tren cho den khi khong con phan tu nao de xet

* Cac buoc
1. i=0; //Lan xu ly dau tien
2. j=N-1; // Duyet tu cuoi day nguoc ve vt i
	Trong khi (j>i) thuc hien:
	Neu M[i]<M[j-1] => doi cho
	j=j-1
3. i = i + 1;
4. Neu i>N-1. Het day dung
5. Nguoc lai: Lap lai buoc 2

* Do phuc tap: O(n^2)

* Khuyet diem: 
- Khong nhan dien duoc tinh trang day da co thu tu hay da co thu tu tung phan
- Cac phan tu nho duoc dua ve vi tri dung nhanh, cac pt lon duoc dua ve vt dung rat cham

*/

void nhapMang(int M[],int n);
void xuatMang(int M[],int n);
void bubbleSort(int M[],int n);

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	int M[n];
	nhapMang(M,n);
	cout<<"\nMang sau khi nhap ngau nhien: \n";
	xuatMang(M,n);
	cout<<"\n---------------------------------------------------\n";
	cout<<"\nMang sau khi sap xep tu tang dan: \n";
	bubbleSort(M,n);
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

void bubbleSort(int M[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(M[j]<M[j-1])
			{
				int temp=M[j];
				M[j]=M[j-1];
				M[j-1]=temp;
			}
		}
	}
}
