#include<iostream>
using namespace std;

int catalan(int n, int *T){
	if(n==0 || n==1) {
		return 1;
	}
    //if 0 nodes 1 tree
    if(T[n]!=1){
		return T[n];
	} 
    T[n]=0;
    for(int i=1;i<=n;i++){
    	T[n]+=catalan(i-1,T)*catalan(n-i,T);
	}
       
    
    return T[n];    
}

int main(){
	int A=3;
    int T[A+1];
    for(int i=0;i<=A;i++)
    	T[i]=1;
    cout<< catalan(A,T);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

