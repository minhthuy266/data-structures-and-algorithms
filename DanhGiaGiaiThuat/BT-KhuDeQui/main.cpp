#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Giai bang de qui

int fib(int n)
{
	if(n<=2)
		return 1;
	return fib(n-1)+fib(n-2);
}

// Giai bang vong lap, khu de qui

int fib2(int n)
{
	int f1=1,f2=1;
	if(n<=2)
		return 1;
	int i=3,f3;
	while(i<=n)
	{
		f3=f1+f2;
		f1=f2;
		f2=f3;
		i++;
	}
	return f3;
}

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap n: ";
	cin>>n;
//	int f=fib(n);
//	cout<<"Fib thu f"<<"("<<n<<")"<<" = "<<f;

	int f=fib2(n);
	cout<<"Fib thu f"<<"("<<n<<")"<<" = "<<f;

	return 0;
}
