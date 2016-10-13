#include <iostream>
#include <algorithm>
using namespace std;

long long int nCr(long long int n, long long int r){
	if(n<=1) return 0;
	long long int ans;
	if(n%2==0)
			ans=(n/2) * (n-1);
	else
			ans=((n-1)/2) * (n);
	
return ans;
}

long long int GCD(long long int num, long long int denom){
	if(num==0)
		return denom;
	return GCD(denom%num, num);
}

long long int main()
{
    long long int N;
    cin>>N;
    long long int A[N];
    long long int count=0;
    long long int num=0;
    long long int denom=nCr(N,2);
    for(long long int i=0;i<N;i++)
    	{
    		cin>>A[i];
    		if(A[i]==0) count++;
    		else
    		if(A[i]==1){
    			if(count!=0){
    				num+=nCr(count,2);
    				count=0;
    			}
    		}
    	}
    if(count!=0)
    	num+=nCr(count,2);
    long long int G=GCD(num,denom);
    cout<<num/G<<" "<<denom/G;
    return 0;
}


