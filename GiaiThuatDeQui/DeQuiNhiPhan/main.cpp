#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// De qui nhi phan la de qui goi 2 lan chinh no

int fib(int n)
{
	if(n<=2)
		return 1;
	return fib(n-1)+fib(n-2);
}

int main(int argc, char** argv) {
	int n=7;
	int f=fib(n);
	cout<<"f = "<<f;
	return 0;
}
