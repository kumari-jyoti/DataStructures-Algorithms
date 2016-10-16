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
//finding max of values, not keys
pair<int,int> get_max( map<int,int>& x ) {
  using pairtype=std::pair<int,int>; 
  return *max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  }); 
}
//using self balanced bst, map too is a self bst
void WindowMaxBST(vector<int> arr,int n,int k){
	map<int,int> mymap;
	//insert first k elements in the tree
	for(int i=0;i<k;i++){
		mymap.insert(pair<int,int> (i,arr[i]));
	}
		
	auto it=get_max(mymap);
	cout<<endl<<it.second<<" ";//max of first window
	//remove ith element, inser i+kth element, extract max	
	for(int i=0;i<n-k;i++){
		mymap.erase(i);
		mymap.insert(pair<int,int> (i+k,arr[i+k]));
		it=get_max(mymap);
		cout<<it.second<<" ";
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
