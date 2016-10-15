//finding number of BST possible with n nodes
#include<iostream>
using namespace std;

//Using catalan to find number of possible structures
int catalan(int n, int *T){
	//base condition
	if(n==0 || n==1) {//if no node null is the tree, if 1 node ie the root and the tree
		return 1;
	}
	//using memoization
    if(T[n]!=1){
		return T[n];
	} 
    T[n]=0;
    for(int i=1;i<=n;i++){
    	T[n]+=catalan(i-1,T)*catalan(n-i,T);//summation of,] product of different pairs of structures of left subtree and right subtree
	}    
    return T[n];    
}

int main(){
	//Number of nodes
	int A=5;
	//storing number of structures for i nodes
    int T[A+1];
    
    for(int i=0;i<=A;i++)
    	T[i]=1;
    cout<< catalan(A,T);
}

