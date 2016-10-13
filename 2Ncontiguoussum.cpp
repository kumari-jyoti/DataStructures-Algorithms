#include<iostream>
using namespace std;

int max(int a, int b){
    return (a>b?a:b);
}

int max2(int a, int b, int c){
    if(a>=b){
        if(a>=c) return a;
        return c;
    }
    else{
        if(b>=c) return b;
        return c;
    }
}


int main() {
	int A[2][4]={{1,2,3,4},{2,3,4,5}};
    int maxsum=0;
    int n=4;
    int M[2][n+1];
    for(int i=0;i<2;i++)
    for(int j=0;j<n;j++)
    M[i][j]=0;
    
    M[0][0]=M[1][0]=0;
    int incl;
    int excl;
    incl=A[0][0];
    excl=A[1][0];
    M[0][1]=M[1][1]=max(incl,excl);
    
    for(int j=2;j<n+1;j++){
        for(int i=0;i<2;i++){
            if(i==0){
                incl=A[i][j-1]+max(M[0][j-2],M[1][j-2]);
                excl=max(M[0][j-1],M[1][j-1]);
                M[i][j]=max(incl,excl);
            }
            else
            if(i==1){
                incl=A[i][j-1]+max(M[0][j-2],M[1][j-2]);
                excl=max2(M[0][j-1],M[0][j],M[1][j-1]);
                M[i][j]=max(incl,excl);
            }
            
        }
    }
    
    cout<<M[1][n];
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

