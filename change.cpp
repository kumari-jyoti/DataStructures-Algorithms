#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int T[128];

int change(int Amt, int D[],int N){
	//if Amount is 0 1 solution not including any coin
	if(Amt==0) return 1;
	
	//if coins count is 0 or Amt is <0 no solution
	if(Amt<0) return 0;
	
	//if no coins and Amt >1 no solution
	if(N<=0 && Amt>=1) return 0;
	
	//sum of containing nth coin or not containing it.
	//containint mth coin adds value D[n], excluding nth coin, check for n-1th coin
	return change(Amt-D[N-1],D,N)+change(Amt,D,N-1);	
}

int main(){
	int change_amt;
	cout<<"enter change amount \n";
	cin>>change_amt;
	//initialization
	for(int i=0;i<=change_amt;i++)
		T[i]=0;
	cout<<"enter number denominations \n";
	int N;
	cin>>N;
	cout<<"enter val of denoms \n";
	int D[N];
	for(int i=0;i<N;i++)
		cin>>D[i];
	cout<<change(change_amt,D,N);	
}
