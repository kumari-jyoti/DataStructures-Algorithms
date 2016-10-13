#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fill_fi(vector<int> a, int n){
	vector<int> fi;
	int count;
	for(int i=0;i<n;i++){
		count=0;
		for(int j=i+1;j<n;j++)
			if(a[i]<a[j]) count++;
		fi.push_back(count);
	}
	
	fi.push_back(0);
	return fi;
}

void unordered_pairs(vector<int> fi,int sum){
	sort(fi.begin(),fi.end());
	int i=0;
	int j=fi.size();
	j=j-1;
	
	int count=0;
	while(i<j){
		if(fi[i]+fi[j]==sum) count++;
		else
		if(fi[i]+fi[j]<sum) i++;
		else{
			count++;
			j--;
		}
	}
	if(count<0)
		count=0;
	cout<<count;
	return;
}

int main()
{
	int N;
	int K;
	cin>>N>>K;
	vector<int> a;
	int ip;
	for(int i=0;i<N;i++){
		cin>>ip;
		a.push_back(ip);
	}
	
	
	vector<int> fi;
	fi=fill_fi(a,N);
	
	unordered_pairs(fi,K);
    return 0;
}

