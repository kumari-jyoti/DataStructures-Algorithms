#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define B 1000000007

int modpow(int N, int K){
	int temp;
	if(K==0)
		return 1;
	if( K==1 ) return  N;
	temp=pow(N,2);
	temp=temp%B;
	
	if(K%2) return (N*modpow(temp,K/2)%B)%B;
	return modpow(temp,K/2)%B;
}

int NPK(int n, int k){
	int res=1;
	for(int i=n-k+1;i<=n;i++)
		res=(res%B * i)%B;
	return res;
}

int NCK(int n,int k){
	if(k==0) return 1;
	return (NCK(n-1,k-1)%B * n * modpow(k,B-2)%B)%B;
}

long long int fact(int n){
	vector<int> T;
	T.push_back(1);
	T.push_back(1);
	
	int f;
	for(int i=2;i<=n;i++){
		f=T[i-1]*i;
		T.push_back(f);
	}
	
	return T[n];
}

int unsorted_strings(int N, int K){
	//case 1: if N==K
	if(N==K) 
		return(fact(K)-1);
	//case 2: if N>K
	cout<<modpow(K,N)<<endl;
	cout<<NCK(N+K-1,K-1)<<endl;
	if(N>K) return modpow(K,N)-NCK(N+K-1,K-1);
	return NPK(K,N)-NCK(K,min(N,K-N));
}

int main()
{
    int N;
	int K;
	cin>>N>>K;
	
	cout<<unsorted_strings(N,K);
    return 0;
}

