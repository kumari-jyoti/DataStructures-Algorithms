#include<iostream>
using namespace std;
//fining max
int max(int a, int b){
    return (a>b?a:b);
}
//finding max for 2nd row calculations
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

//main function
int main() {
	//input 2*n array
	int A[2][4]={{1,2,3,4},{2,3,4,5}};
    int n=4;
    //for storing max non adj contiguius sum till A[i][j]
    int M[2][n+1];
    //initialise 0 in beg
    for(int i=0;i<2;i++)
    for(int j=0;j<n;j++)
    M[i][j]=0;
    //for 0 elements
    M[0][0]=M[1][0]=0;
    //sum including A[i][j]
    int incl;
    //sum excluding A[i][j]
    int excl;
    //for only A[0][0], either one as non adj and that will be even for A[1][0] as they are adj
    incl=A[0][0];
    excl=A[1][0];
    M[0][1]=M[1][1]=max(incl,excl);
    
    //Can be done using 1-D array as well
    for(int j=2;j<n+1;j++){//2*n matrix, hence col loop outside
        for(int i=0;i<2;i++){
            if(i==0){
                incl=A[i][j-1]+max(M[0][j-2],M[1][j-2]);
                excl=max(M[0][j-1],M[1][j-1]);//M[1[j] not yet calculated
                M[i][j]=max(incl,excl);
            }
            else
            if(i==1){
                incl=A[i][j-1]+max(M[0][j-2],M[1][j-2]);
                excl=max2(M[0][j-1],M[0][j],M[1][j-1]);//M[0][j] has been calculated so consider it
                M[i][j]=max(incl,excl);
            }        
        }
    }    
    cout<<M[1][n];
}

