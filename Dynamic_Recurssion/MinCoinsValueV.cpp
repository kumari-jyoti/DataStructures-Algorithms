#include<iostream>
#include<limits.h>
using namespace std;

//using dynamic programmin
int DMinCoins(int coins[], int m, int V){
	//stores the minimum coins required for amount V
	int T[V+1];
	//if amount equals 0, 0 coins required
	T[0]=0;
	// Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        T[i] = INT_MAX;
	for(int i=1;i<=V;i++){
		//check all coins <i
		for(int j=0;j<m;j++){
			if(coins[j]<=i){
				int res=T[i-coins[j]];
				if(res!=INT_MAX && res+1<T[i])
					T[i]=res+1;
			}
		}
	}return T[V];
}
//using recursion
int mincoins(int coins[], int m, int V){
	//if amount equals 0, 0 coins required
	if(V==0) return 0;
	//storing the final result
	int res=INT_MAX;
	for(int i=0;i<m;i++){//try every coin to minimize the number of coins required
		if(coins[i] <= V){//if coin's value is less than or equal to amount then only it can contribute
				int num=mincoins(coins,m, V-coins[i]);
				if(num!=INT_MAX && num+1<res)
				res=num+1;
		}
	}
	return res;
}

//main function
int main(){
	//different coins with denominations
	int coins[]={1,2,3};
	//amount
	int V=4;
	int m=sizeof(coins)/sizeof(coins[0]);
	cout<<mincoins(coins,m, V);
	cout<<endl;
	cout<<DMinCoins(coins,m, V);
}
