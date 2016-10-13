#include <iostream>
#include<math.h>
using namespace std;

void winner(int N,int Q,int A[], int start, int end, int Sum[]){
	int turns=Sum[end]-Sum[start-1];
	
	if(turns%2) cout<<"Mishki"<<endl;
		else cout<<"Hacker"<<endl;
	
	return;	
}

int main()
{
    int N;//number of sets
    int Q;//number of days
    cin>>N>>Q;
    int A[N];//sets of stones
    for(int i=0;i<N;i++)
    	cin>>A[i];
    int S[Q][2];
    for(int i=0;i<Q;i++)
    	for(int j=0;j<2;j++)
    		cin>>S[i][j];
    
    int prefix_sum[N+1];
    prefix_sum[0]=0;
    for(int i=1;i<=N;i++){
    	prefix_sum[i]=prefix_sum[i-1]+floor(log(A[i-1]))+1;
    	cout<<prefix_sum[i]<<" ";
    }
    
    for(int i=0;i<Q;i++)
    	winner(N,Q,A,S[i][0],S[i][1],prefix_sum);
    return 0;
}

