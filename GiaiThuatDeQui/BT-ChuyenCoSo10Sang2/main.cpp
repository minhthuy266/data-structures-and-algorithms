#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// Tim qui luat
// Tim diem dung
// Luu stack la luu chi thi lenh, gia tri cua cac bien local

void H10ToH2(int n)
{
	if(n>0)
	{
		int sd=n%2;
		n=n/2;
		H10ToH2(n);
		cout<<sd;
	}
}

int main(int argc, char** argv) {
	int n=12;
	H10ToH2(n);
	return 0;
}
