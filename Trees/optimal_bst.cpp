#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int cost(int A[], int F[], int n){
	int M[n][n];
	int S[n][n];
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		S[i][j]=-1;
	for(int i=0;i<n;i++)
		{
			M[i][i]=F[i];
			S[i][i]=i+1;
		}
	
	for(int l=2;l<=n;l++){
		for(int i=0;i<=n-l;i++){
			int j=i+l-1;
			int pos;
			if(j>0){
				int sumf=0;
				int root=INT_MAX;
				int sum;
				for(int k=i;k<=j;k++){
					sumf+=F[k];
					if(k==i)
						sum=M[k+1][j];
					else
					if(k==j)
						sum=M[i][k-1];
					else
						sum=M[i][k-1]+M[k+1][j];
					
					if(sum<root) pos=i;	
					root=min(root,sum);	
				}
				M[i][j]=sumf+root;
				S[i][j]=pos+1;			
			}
		
		
	}
	}
	
		for(int i=0;i<n;i++){
	
	for(int j=0;j<n;j++)
	cout<<S[i][j]<<" ";
	cout<<endl;}
	
	cout<<endl<<endl;
	return M[0][n-1];

	
}

int main(){
	int A[]={10,12,16,21};
	int F[]={4,2,6,3};
	int n=sizeof(A)/sizeof(A[0]);
	cout<<cost(A,F,n);
}
