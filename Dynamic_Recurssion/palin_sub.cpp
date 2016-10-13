#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string A="abacd";
    int n=A.length();
    int M[n][n];
    for(int i=0;i<n;i++)
        M[i][i]=1;
    
    int k=0;
    for(int d=2;d<=n;d++){
    for(int i=0;i<=n-d;i++){
        int j=i+d-1;
            if(A[i]==A[j]){
                if(i==j-1)//if 2 elements no substr in middle
                    M[i][j]=2;
                else{
                    if(M[i+1][j-1]==j-i-1)//the elemts in the middle are also palindrome
                        M[i][j]=2+M[i+1][j-1];
                    else
                    M[i][j]=max(M[i][j-1],M[i+1][j]);//though same, middle part not palin
                }
                
            }
                   
            else
                M[i][j]=max(M[i][j-1],M[i+1][j]);;
        }
    }
    
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    	cout<<M[i][j]<<"  ";
    	cout<<endl;
	}
    int len=M[0][n-1];
    cout<<len;
    string res;
    for(int i=0;i<=n-len;i++){
        res=A.substr(i,len);
        string s=res;
        reverse(s.begin(),s.end());
        if(s==res){
        	cout<<res<<endl;
        	break;
		}res;
    }
        
   cout<<res;
   return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

