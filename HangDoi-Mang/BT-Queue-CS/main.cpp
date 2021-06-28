#include <iostream>
#define MAX_OF_QUEUE 10
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double queue[MAX_OF_QUEUE];
int rear=-1;
int front=-1;
void enqueue(double value);
double dequeue();
bool isEmpty();

int main(int argc, char** argv) {
	while(true)
	{
		cout<<"Nhap 1 gia tri: (-113 de thoat): ";
		double value;
		cin>>value;
		if(value==-113)
			break;
		enqueue(value);
	}

	while(isEmpty()==false)
	{
		double value=dequeue();
		cout<<value<<"\n";
	}
	return 0;
}

void enqueue(double value)
{
	if(rear<MAX_OF_QUEUE-1)
	{
		rear=rear+1;
		queue[rear]=value;
	}
	else
	{
		cout<<"Queue is full";
		exit(0);
	}
}

double dequeue()
{
	if(front==rear)
	{
		cout<<"Queue is empty";
		exit(0);
	}
	front=front+1;
	double value=queue[front];
	return value;
}

bool isEmpty()
{
	return front==rear;
}
