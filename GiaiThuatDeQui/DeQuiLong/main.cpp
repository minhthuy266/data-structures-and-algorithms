#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// De qui long la loai de qui goi de qui vao doi so cua ham de qui

int ackerman(int m,int n)
{
	if(m==0) return n+1;
	else if(n==0)
		return ackerman(m-1,1);
	else
		return ackerman(m-1,ackerman(m,n-1));
}

int main(int argc, char** argv) {
	int m=2,n=1;
	cout<<ackerman(m,n);
	return 0;
}
