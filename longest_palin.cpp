#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

string brute(string A){
    int n= A.size();
	//case 1: if length=0;
	//case 2: if length=1;
	if(n==0||n==1) return A;
    //case 3: other lengths
    int maxlen=0;
    int start=1;
    string temp;
    string reqpalin="";
    for(int i=0;i<n;i++){
        //pick substrings of length of i ie j to j+i;
        int j=0;
        while(j<n-i){
        temp=A.substr(j,i+1); 
        reverse(temp.begin(),temp.end());
        if(!temp.compare(A.substr(j,i+1)))
            if(temp.size()>maxlen){
                maxlen=temp.size();
                reqpalin=temp;
            }
        j++;     
        }
    }
    return reqpalin;
   
}

string dynamicsol(string A){
    int n= A.size();
	//case 1: if length=0;
	//case 2: if length=1;
	if(n==0||n==1) return A;
	//initialise array to store previous lengths
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(j==0) a[i][j]=1;
			else
				a[i][j]=0;

	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;j++){
			int len=a[i][j-1];
			int start=i;
			int end=j-a[i][j-1]+1;
			string str1=A.substr(i,end);
			string str2=A.substr(i+len,j);
			if(str1.compare(str2)==0)
				a[i][j]=len+1;
			else
				a[i][j]=len;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
		
	
	return A;
}
int main(){
	string A="agbdba";
    //string palin=brute(A);
    string palin=dynamicsol(A);
    //string C=findlongestsub(A,B,n,n);
    cout<<palin;
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

