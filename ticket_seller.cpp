#include<iostream>
using namespace std;

int cost(int a[], int start,int end){
	int C1=0;
	int C2=0;
	if(end%2==0)
		C2=(end/2)*(end+1);
	else
		C2=end*((end+1)/2);
	if(start%2==0)
		C1=(start/2)*(start+1);
	else
		C1=start*((start+1)/2);
	int C=C2-C1;
	cout<<"calculating cost from: "<<start+1<<" to "<<end<<" : "<<C2<<"-"<<C1<<" = "<<C<<endl;
	return C;
}

int max_cost(int a[], int n){
	int M=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>M)
			M=a[i];
	return M;
}

int max_profit(int a[],int n,int k){
	int start=0;
	int end=max_cost(a,n);
	int profit=0;
	int tickets=0;
	
	while(start<=end){		
		int mid=(start+end)/2;
		cout<<"position: "<<start<<" "<<mid<<" "<<end<<endl;
		for(int i=0;i<n;i++)
			if(a[i]>mid){
				tickets+=a[i]-mid;
				profit+=cost(a,mid,a[i]);
				a[i]=mid;
			}
		cout<<"tickets sold: "<<tickets<<endl;
		cout<<"remaining: ";
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		cout<<"earned till now: "<<profit<<endl<<endl;
		if(tickets>=k) break;
		else end--;	
	}
	
	return profit;
}

int main(){
	int a[]={2,8,4,10,6};
	int k=20;
	int n=5;
	cout<<max_profit(a,n,k);
}
