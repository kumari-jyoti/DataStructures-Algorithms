#include<iostream>
#include<limits.h>
using namespace std;

int mincoins(int coins[], int m, int V){
	if(V==0) return 0;
	int res=INT_MAX;
	for(int i=0;i<m;i++){
		if(coins[i] <= V){
				int num=mincoins(coins,m, V-coins[i]);
				if(num!=INT_MAX && num+1<res)
				res=num+1;
		}
	
	}
	return res;
}

int numofways(int coins[], int m, int V){
	//if 0 rs 1 solution choose none
	if(V==0) return 1;
	//if amt <0;
	if(V<0) return 0;
	//if no coins no solution
	if(m<=0) return 0;
	
	return numofways(coins,m-1,V)+numofways(coins,m,V-coins[m-1]);
	
}
int main(){
	int coins[]={1,2,3};
	int V=4;
	int m=sizeof(coins)/sizeof(coins[0]);
	cout<<numofways(coins,m,V);
	cout<<endl;
	cout<<mincoins(coins,m, V);
}
