#include<iostream>
using namespace std;

int maxof_negnum(int A[],int n){
	int max=-INT_MAX;
	for(int i=0;i<n;i++)
		if(A[i]>max)
			max=A[i];
	return max;
}

int sumofall(int A[],int n){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=A[i];
	return sum;
}

int Brute_maxsum(int A[],int n){
	//case1: if all negative
	int i;
	for(i=0;i<n;i++)
		if(A[i]>=0) break;
	if(i==n) return maxof_negnum(A,n);
	//case2: if all positive	
	for(i=0;i<n;i++)
		if(A[i]<0) break;
	if(i==n) return sumofall(A,n);	
	//case3: other	
	int maxsum=0;
	for(i=0;i<n;i++){
		int cursum=0;
		for(int j=i;j<n;j++){
			cursum+=A[j];
			if(cursum>maxsum) maxsum=cursum;
		}
	}
	return maxsum;
}

int max(int a, int b){
	return (a>b)?a:b;
}
int dynamic_maxsum(int A[],int n){
	//store sum ending at i
	int M[n]={0};
	if(A[0]>0)
		M[0]=A[0];
	else
		M[0]=0;
	for(int i=1;i<n;i++)
		M[i]=max(M[i-1]+A[i],0);
	int maxsum=M[0];
	for(int i=1;i<n;i++)
		if(M[i]>maxsum)
			maxsum=M[i];
	return maxsum;
}

int maxsum_no_space(int A[], int n){
	int maxsofar=0;
	int cursumsofar=0;
	for(int i=0;i<n;i++){
		cursumsofar+=A[i];
		if(cursumsofar<0)
			cursumsofar=0;//start new positive sum window
		if(cursumsofar>maxsofar)
			maxsofar=cursumsofar;
	}
	return maxsofar;
}

int main(){
	//int A[]={-2,-11,-4,-13,-5,-2}; //case1:
	int A[]={-2,11,-4,13,-5,2}; //case2:	
	int n=sizeof(A)/sizeof(A[0]);
	//int A[]={-2,11,-4,13,-5,2};	
	//cout<<Brute_maxsum(A,n);
	//cout<<dynamic_maxsum(A,n);
	cout<<maxsum_no_space(A,n);
	
	
}
