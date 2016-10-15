#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int int_knapsack(int Si[],int Vi[],int N,int C){
	//maximum value obtained for capacit j using all items
	int M[C+1];
	M[0]=0;
	for(int j=1;j<=C;j++){
		int max_val=-INT_MAX;
		for(int i=1;i<=N;i++)//try all items for capacity C
			if(j-Si[i]>=0) 
				max_val=max(max_val,M[j-Si[i]]+Vi[i]);				
		M[j]=max(M[j-1],max_val);//max of jth capacity or j capacity's value	
	}
		
	return M[C];
}

int _01_knapsack(int Si[],int Vi[],int N,int C){
	//maximum value obtained for capacity j using upto ith items only
	int M[N+1][C+1];
	for(int i=0;i<=N;i++)
		M[i][0]=0;
	for(int i=0;i<=C;i++)
		M[0][i]=0;	
	
	for(int i=1;i<=N;i++)//note all coins are not tried for capacity j, but all capacity is tried for each item
		for(int j=1;j<=C;j++){
			if(j-Si[i]>=0)				
				M[i][j]=max(M[i-1][j],M[i-1][j-Si[i]]+Vi[i]);//excluding ith item, for capacity j, including ith item
			else //if wt > j then cannot be picked and max value remains as previous
				M[i][j]=M[i-1][j];	
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=C;j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	return M[N][C];
}

//main function
int main(){
	int N;
	int C;
	cout<<"enter capacity of knapsack ";
	cin>>C;
	cout<<"\n enter number of types of elements";
	cin>>N;
	
	int Si[N];
	int Vi[N];
	
	//input
	cout<<"\n enter size \n";
	for(int i=1;i<=N;i++)
		cin>>Si[i];	
	cout<<"\n enter value \n";
	for(int i=1;i<=N;i++)
		cin>>Vi[i];
	
	cout<<"integer Knapsacp "<<int_knapsack(Si,Vi,N,C)<<endl;
	cout<<"0-1 Knapsacp "<<_01_knapsack(Si,Vi,N,C)<<endl;
	
}
