#include <iostream>
#include <string.h>
#define MAX_OF_QUEUE 10
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct customer
{
	int id;
	char name[250];
};

customer *queue[MAX_OF_QUEUE];
int rear=-1;
int front=-1;
void enqueue(customer *c);
customer *dequeue();
bool isEmpty();

int main(int argc, char** argv) {
	customer *c1=new customer;
	c1->id=1;
	strcpy(c1->name,"An");
	
	customer *c2=new customer;
	c2->id=2;
	strcpy(c2->name,"Yen");
	
	customer *c3=new customer;
	c3->id=3;
	strcpy(c3->name,"Hanh");
	
	enqueue(c1);
	enqueue(c2);
	enqueue(c3);
	
	while(isEmpty()==false)
	{
		customer *c=dequeue();
		cout<<c->id<<"\t"<<c->name<<"\n";
	}
	return 0;
}

void enqueue(customer *c)
{
	if(rear<MAX_OF_QUEUE-1)
	{
		rear=rear+1;
		queue[rear]=c;
	}
	else
	{
		cout<<"Queue is full";
		exit(0);
	}
}

customer *dequeue()
{
	if(front==rear)
	{
		cout<<"Queue is empty";
		exit(0);
	}
	front=front+1;
	customer *c=queue[front];
	return c;
}

bool isEmpty()
{
	return front==rear;
}
