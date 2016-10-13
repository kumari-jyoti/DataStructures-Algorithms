#include<iostream>
using namespace std;

int subset_sum(int A[],int n, int K){
	int M[n][K+1];
	for(int i=0;i<n;i++)
	for(int j=0;j<=K;j++){
		M[i][j]=0;
		if(A[i]==A[j]) M[i][j]=1;
		else if(i-1>=0 && M[i-1][j]==1) M[i][j]=1;
		else if(j-A[i]>=0 && M[i-1][j-A[i]]==1) M[i][j]=1;
	}
	return M[n-1][K];
}
int main(){
	int A[]={2,3,7,8,9};
	int n=sizeof(A)/sizeof(A[0]);
	int K=6;
	cout<<subset_sum(A,n,K);
}
