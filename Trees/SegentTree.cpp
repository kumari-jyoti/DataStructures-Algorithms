#include<iostream>
#include<algorithm>
#include<limits.h>
#include<math.h>
using namespace std;

void CreateSegmentTree(int arr[],int* ST,int pos,int l, int r){
	if(l==r) {
		ST[pos]=arr[l];
		return ;	
	}
	int mid=l+(r-l)/2;
	CreateSegmentTree(arr,ST,2*pos+1,l,mid);	//cout<<pos<<" ";return;
	CreateSegmentTree(arr,ST,2*pos+2,mid+1,r);

	ST[pos]=max(ST[2*pos+1],ST[2*pos+2]);
	return;
}

int main(){
	int n=6;
	int arr[n]={-1,3,4,0,2,1};
	//Height of segment tree
    int x = (int)(ceil(log2(n))); 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;
	//cout<<max_size<<endl; 
    // Allocate memory
    int *st = new int[max_size];
	CreateSegmentTree(arr,st,0,0,n-1);
	for(int i=0;i<max_size;i++)
		cout<<*(st+i)<<" ";
	
}
