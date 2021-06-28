#include <iostream>
#define MAX_OF_STACK 10
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
- Viec cai dat stack thong qua mang 1 chieu don gian va kha hieu qua
- Tuy nhien han che lon nhat cua phuong an nay la gioi han ve kich thuoc cua stack N
Gia tri cua N co the qua nho so voi nhu cau thuc te hoac qua lon se lam lang phi bo nho
*/

int stack[MAX_OF_STACK];
int top=-1;
// Prototype
void push(int value); // Day vao stack
int pop(); // Lay ra khoi stack va xoa khoi bo nho

int main(int argc, char** argv) {
	push(5);
	push(8);
	push(3);
	int t=pop(); // Lay phan tu tren cung stack
	cout<<t<<endl;
	t=pop();
	cout<<t<<endl;
	t=pop();
	cout<<t<<endl;
	t=pop();
	cout<<t<<endl;
	return 0;
}

void push(int value)
{
	if(top<MAX_OF_STACK)
	{
		top=top+1;
		stack[top]=value;
	}
	else
	{
		cout<<"Stack da day";
		exit(0);
	}
}

int pop()
{
	int value;
	if(top>=0)
	{
		value=stack[top];
		top=top-1;
	}
	else
	{
		cout<<"Stack rong!";
		exit(0);
	}
	return value;
}
