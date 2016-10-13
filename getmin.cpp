#include<iostream>
#include<stdlib.h>
using namespace std;

class stack
{
	private:
	static const int max=100;
	int a[max];
	int top;
	public:
		stack(){top=-1;
		}
		
		bool isEmpty()
		{
			if(top == -1)
				return true;
			return false;
		}
		
		bool isfull()
		{
			if(top == max - 1)
				return true;
			return false;
		}
		
		void push(int k)
		{
			if(isfull())
			{
				cout<<"Stack Overflow";
				abort();
			}
			top++;
			a[top] = k;
		}	
		
		int pop()
		{
			if(isEmpty())
			{
				cout<<"Stack Underflow";
				abort();
			}
			int x = a[top];
			top--;
			return x;
		}
		
			
};

class spstack: public stack
{
	stack min;
public:
	int popsp();
	void pushsp(int x);
	int getmin();
};

void spstack::pushsp(int k)
{
	if(isEmpty()==true){
		push(k);
		min.push(k);	
	}	
		
	else
	{
		push(k);
		int y=min.pop();
		min.push(y);
		if(k<=y)
			min.push(k);		
	}
}

int spstack::popsp(){
	int x=pop();
	int y=min.pop();
	if(x!=y)
		min.push(y);
	return x;
}

int spstack::getmin()
{	
	int x = min.pop();
	min.push(x);
	return x;
}
int main()
{
	  spstack s; 
	s.pushsp(10);  
    s.pushsp(20);
    s.pushsp(30);
    cout<<s.getmin()<<endl;
    s.pushsp(5);
    cout<<s.getmin();
    return 0;
	
}
