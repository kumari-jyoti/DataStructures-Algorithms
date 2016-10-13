#include<iostream>
#include<limits.h>
using namespace std;

int minCoins(int coins[],int m, int V){
	//if amount is 0 coins required is 0
	if(V==0) return 0;
	//find minimum of all solutions
	int min=INT_MAX;
}
int main(){
	int coins[]={9,6,5,1};
	int m=sizeof(coins)/sizeof(coins[0]);
	int V=11;
	cout<<minCoins(coins,m,V);
}
