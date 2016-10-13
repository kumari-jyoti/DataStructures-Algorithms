#include<iostream>
using namespace std;

int lis_len(int A[], int n){
	int lis[n];
	int pos[n];
	for(int i=0;i<n;i++)
		{
			lis[i]=1;
			pos[i]=-1;
		}
		
	
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++){
			if(A[i]>A[j] && lis[j]+1>lis[i]){
				lis[i]=lis[j]+1;
				pos[i]=j;
			}
				
		}
	
	int end;
	int max=lis[0];
	for(int i=0;i<n;i++)
		if(max<lis[i]){
			max=lis[i];
			end=i;
		}
	int i=end;
	while(i!=-1)
	{
		cout<<A[i]<<" ";
		i=pos[i];
	}
	return max;

}

int main(){
	int A[]={5,6,2,3,4,1,9,9,8,9,5};
	int n=sizeof(A)/sizeof(A[0]);
	
	cout<<lis_len(A,n);
}
