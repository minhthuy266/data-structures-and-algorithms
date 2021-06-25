#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// De qui duoi la truong hop dac biet cua de qui tuyen tinh

int gcd (int m,int n)
{
	int r;
	if(m<n) return gcd(n,m);
	r=m%n;
	if(r==0)
		return n;
	else 
		return gcd(n,r);
}

int main(int argc, char** argv) {
	int m=25,n=5;
	//int m=5,n=25;
	//int m=7,n=3;
	int kq=gcd(m,n);
	cout<<kq;
	return 0;
}
