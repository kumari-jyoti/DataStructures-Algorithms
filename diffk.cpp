#include<algorithm>
#include<iostream>
#include<unordered_set>
using namespace std;

int pairswithdiff(int A[],int K,int n){
	int pairs=0;
	unordered_set<int> s;
	for(int i=0;i<n;i++){
		unordered_set<int>::const_iterator got=s.find(K+A[i]);
		unordered_set<int>::const_iterator got2=s.find(A[i]-K);
		if(got!=s.end())pairs++;
		if(got2!=s.end())pairs++;	
		s.insert(A[i]); 
	}
	return pairs;
}
int main(){
	int A[]={2,5,6,4,9,3};
	int n=sizeof(A)/sizeof(A[0]);
	int diff=2;
	cout<<pairswithdiff(A,diff,n);
}

