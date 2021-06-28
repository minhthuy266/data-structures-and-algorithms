#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct device
{
	int id;
	char name[250];
};

device *stack[MAX];
int top=-1;
void push(device *d);
device *pop();

int main(int argc, char** argv) {
	device *d1=new device;
	d1->id=1;
	strcpy(d1->name,"Mouse");
	push(d1);
	
	device *d2=new device;
	d2->id=2;
	strcpy(d2->name,"Keyboard");
	push(d2);
	
	while(top>=0)
	{
		device *d=pop();
		cout<<d->id<<"\t"<<d->name<<"\n";
	}
	
	return 0;
}

void push(device *d)
{
	if(top<MAX)
	{
		top=top+1;
		stack[top]=d;
	}
	else
	{
		cout<<"Stack da day!";
	}
}

device *pop()
{
	device *d=NULL;
	if(top>=0)
	{
		d=stack[top];
		top=top-1;
	}
	else
	{
		cout<<"Stack rong!";
	}
	return d;
}
