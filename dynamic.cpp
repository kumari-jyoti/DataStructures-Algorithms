#include<iostream>
using namespace std;
#define NIL -1

void initialise(int a[],int n){
	for(int i=0;i<n+1;i++)
			a[i]=NIL;
}

int fib_topdown(int n, int a[]){
	if(a[n]==NIL){
		if(n<=1)
			a[n]=n;
		else
			a[n]=fib_topdown(n-1,a)+fib_topdown(n-2,a);
	}		
	return a[n];
}

int fib_bottomup(int n, int a[]){
	a[0]=0;a[1]=1;
	for(int i=2;i<n+1;i++)
		a[i]=a[i-1]+a[i-2];
	return a[n];
}
//dynamic programming
int main(){
	int n=7;
	int a[n+1];
	initialise(a,n);
	cout<<fib_topdown(n,a);
	cout<<fib_bottomup(n,a);
}
