#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void nhapMang(int M[],int n);
void xuatMang(int M[],int n);
void bubbleSort(int M[],int n);
void insertionSort(int M[],int n);
void selectionSort(int M[],int n);
void interchangeSort(int M[],int n);
void quickSort(int M[],int left,int right);
void mergeSort(int M[],int left,int right);
void merge(int M[],int left,int mid,int right);
void menu();

int *M;
int n;

int main(int argc, char** argv) {
	while(true)
		menu();
	return 0;
}

void menu()
{
	cout<<"Moi ban chon chuc nang: \n";
	cout<<"1. Nhap mang\n";
	cout<<"2. Xuat mang\n";
	cout<<"3. Bubble Sort\n";
	cout<<"4. Insertion Sort\n";
	cout<<"5. Selection Sort\n";
	cout<<"6. Interchange Sort\n";
	cout<<"7. Quick Sort\n";
	cout<<"8. Merge Sort\n";
	cout<<"9. Thoat\n";
	cout<<"Ban chon so [1-9]: ";
	int chon;
	cin>>chon;
	cout<<"\n----------------------------------------------------------------------------------------------\n";
	switch(chon)
	{
		case 1:
			cout<<"Nhap n: ";
			cin>>n;
			if(M!=NULL)
			{
				delete M;
				M=NULL;
			}
			M=new int[n];
			nhapMang(M,n);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			break;
			
		case 2:
			cout<<"Cac phan tu trong mang la: \n";
			xuatMang(M,n);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			break;
		case 3:
			cout<<"Bubble Sort: \n";
			bubbleSort(M,n);
			xuatMang(M,n);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			break;
		case 4:
			cout<<"Insertion Sort: \n";
			insertionSort(M,n);
			xuatMang(M,n);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			break;
		case 5:
			cout<<"Selection Sort: \n";
			selectionSort(M,n);
			xuatMang(M,n);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			break;
		case 6:
			cout<<"Interchange Sort: \n";
			interchangeSort(M,n);
			xuatMang(M,n);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			break;
		case 7:
			cout<<"Quick Sort: \n";
			quickSort(M,0,n-1);
			xuatMang(M,n);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			break;
		case 8:
			cout<<"Merge Sort: \n";
			mergeSort(M,0,n-1);
			xuatMang(M,n);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			break;
		case 9:
			exit(0);
			
	}
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
	cout<<endl;
}

// Giai thuat noi bot
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

// Giai thuat chen truc tiep
void insertionSort(int M[],int n)
{
	int pos=0;
	int x;
	for(int i=0;i<n;i++)
	{
		x=M[i];
		for(pos=i;(pos>0)&&(M[pos-1]>x);pos--)
		{
			M[pos]=M[pos-1];
		}
		M[pos]=x;
	}
}

// Giai thuat chon truc tiep
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

// Giai thuat doi cho truc tiep
void interchangeSort(int M[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
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

// Giai thuat sap xep nhanh
void quickSort(int M[],int left,int right)
{
	if(left>=right) return;
	int pivot = M[(left+right)/2];
	int i=left, j=right;
	do
	{
		while (M[i]<pivot) i++;
		while (M[j]>pivot) j--;
		if(i<=j)
		{
			int temp=M[i];
			M[i]=M[j];
			M[j]=temp;
			i++;
			j--;
		}
		
	} 	while(i<j);
		quickSort(M,left,j);
		quickSort(M,i,right);
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
