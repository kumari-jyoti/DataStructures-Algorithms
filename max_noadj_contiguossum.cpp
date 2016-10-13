#include<iostream>
using namespace std;

int max(int a, int b){
	return (a>b?a:b);
}
//from 1 to ith
int brute_maxsum_noadj(int A[], int n){
	//if no element
	if(n<=0) return 0;
	//include the nth number
	int x= A[n-1]+brute_maxsum_noadj(A,n-2);
	//exclude the nth number
	int y= brute_maxsum_noadj(A,n-1);
	//return max of that;
	return max(x,y);
}

int dynamicsol(int A[], int n){
	int M[n];
	if(A[0]>=0) M[0]=A[0];
	else
	M[0]=0;
	M[1]=max(A[1],A[0]);
	for(int i=2;i<n;i++)
		M[i]=max(A[i]+M[i-2],M[i-1]);
	
	int maxsum=0;
	for(int i=0;i<n;i++)
		if(M[i]>maxsum)
			maxsum=M[i];
	return maxsum;
}
//from ith to n
int dynamicsolfromi(int A[], int n){
	int M[n]={0};
	if(A[0]>=0) M[0]=A[0];
	else
	M[n-1]=A[n-1];
	M[n-2]=max(A[n-2],A[n-1]);
	for(int i=n-3;i>=0;i--)
		M[i]=max(A[i]+M[i+2],M[i+1]);
	
	int maxsum=0;
	for(int i=0;i<n;i++)
		if(M[i]>maxsum)
			maxsum=M[i];
	return maxsum;
}
int main(){
	int A[]={-2,11,-4,13,-5,2}; 	
	int n=sizeof(A)/sizeof(A[0]);
	//cout<<brute_maxsum_noadj(A,n);
	cout<<dynamicsol(A,n);
	cout<<dynamicsolfromi(A,n);
}
