#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<algorithm>
using namespace std;

void WindowMax(vector<int> arr,int n,int k){
	//bruteforce
	for(int i=0;i<=n-k;i++){
		int max=arr[i];
		for(int j=1;j<k;j++)
			if(arr[i+j]>max) max=arr[i+j];
		cout<<max<<" ";
	}
	cout<<endl;
	//using deque
	deque<int> d;
	d.push_front(0);
	for(int i=1;i<n;i++){
		while(!d.empty() && d.front()<=i-k) d.pop_front();
		while(!d.empty() && arr[d.back()]<arr[i]) d.pop_back();
		d.push_back(i);
		if(i>=k-1)
		cout<<arr[d.front()]<<" ";
	}	
}

//using self balanced bst, map too is a self bst
void WindowMaxBST(vector<int> arr,int n,int k){
	map<int,int> mymap;
	//insert first k elements in the tree
	for(int i=0;i<k;i++){
		if(mymap.find(arr[i])==mymap.end())
			mymap.insert(pair<int,int> (arr[i],1));
		else
			mymap.at(arr[i])++;
	}		
	auto it=max_element(mymap.begin(),mymap.end());
	cout<<endl<<it->first<<" ";//max of first window
	//remove ith element, inser i+kth element, extract max	
	for(int i=0;i<n-k;i++){
		if(mymap.at(arr[i])==1)
			mymap.erase(arr[i]);
		else
			mymap.at(arr[i])--;
		if(mymap.find(arr[i+k])!=mymap.end())
			mymap.at(arr[i+k])++;
		else
			mymap.insert(pair<int,int> (arr[i+k],1));
		it=max_element(mymap.begin(),mymap.end());
		cout<<it->first<<" ";
	}
		
}

	
int main(){
	//window size
	int K;
	cin>>K;
	//arr size
	int N;
	cin>>N;
	//input vector
	vector<int> arr;
	int input;
	for(int i=0;i<N;i++){
		cin>>input;
		arr.push_back(input);
	}
	WindowMax(arr, N, K);
	WindowMaxBST(arr,N,K);
}
