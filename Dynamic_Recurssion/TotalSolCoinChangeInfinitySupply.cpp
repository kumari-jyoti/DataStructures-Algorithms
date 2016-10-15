#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int T[128];

//Dynamic Solution
int DChange(int Amt, int D[], int N){
	//to store total solution for amout i using j coins
	int T[Amt+1][N];
	//1 solution for amount 0 using any coin, dont include them
	for(int j=0;j<N;j++)
		T[0][j]=1;
	for(int i=1;i<=Amt;i++){
		for(int j=0;j<N;j++){
			// Count solutions including D[j]
            int x = (i-D[j] >= 0)? T[i - D[j]][j]: 0;
 
            // Count solutions excluding D[j]
            int y = (j >= 1)? T[i][j-1]: 0;
 
            // total count
            T[i][j] = x + y;
		}
	}	
	return T[Amt][N-1];	
}
//Recursive solution
int change(int Amt, int D[],int N){
	//if Amount is 0, 1 solution not including any coin
	if(Amt==0) return 1;
	
	//if Amt is <0 no solution
	if(Amt<0) return 0;
	
	//if no coins and Amt >1 no solution
	if(N<=0 && Amt>=1) return 0;
	
	//sum of containing nth coin or not containing it.
	//containint mth coin adds value D[n-1], check for n coins with amt Amt-D[n-1] then only can be added
	//excluding nth coin checks for n-1th coin amounting to Amt
	return change(Amt-D[N-1],D,N)+change(Amt,D,N-1);	
}


//main function
int main(){
	//total amount
	cout<<"enter change amount \n";
	int change_amt;
	cin>>change_amt;
	//number of different denominations
	cout<<"enter number denominations \n";
	int N;
	cin>>N;
	//value of different denominations
	cout<<"enter val of denoms \n";
	int D[N];
	for(int i=0;i<N;i++)
		cin>>D[i];
	cout<<change(change_amt,D,N);
	cout<<endl<<endl;
	cout<<DChange(change_amt,D,N);	
}
