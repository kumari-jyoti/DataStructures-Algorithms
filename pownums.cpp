#include<iostream>
#include<math.h>
using namespace std;

int powernum(int A[],int n){
	int pownum=0;
	for(int i=0;i<n;i++){
		int k=ceil(sqrt(A[i]));
		int start=1;
		int end=k-1;
		while(start<end){
			int sumsq=pow(start,2) + pow(end,2);
			if(sumsq==A[i]){
				pownum++;
				break;
			}
			if(sumsq<A[i]) start++;
			else end--;
		}
	}
	return pownum;
}

int main(){
	int A[]={1,3,5,13,10,25,100};
	int n=sizeof(A)/sizeof(A[0]);
	cout<<powernum(A,n);
}
