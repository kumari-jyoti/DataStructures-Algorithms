#include<iostream>
#include<vector>
using namespace std;
int cut=0;

void print_cut(vector<vector<int> >S, int start,int end){
	if(start==end) return; 
	int k=S[start][end];
	cut++;
	cout<<cut<<" cut after A"<<k<<endl;
	print_cut(S,0,k);
	print_cut(S,k+1,end);
	
}

void matorder(int P[],int len){
	int n=len-1;
	int M[n][n];
	
	//initialise all val as INT_MAX in M;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			M[i][j]=INT_MAX;
	
	//initialise all val as 0 in S;	
	
	vector<vector<int> > S(n, vector<int> (n,-1));
			
			
	for(int i=0;i<n;i++)
		M[i][i]=0;
	
	cout<<endl<<endl;
	
	for(int d=1;d<n;d++){
		for(int i=0;i<n-d;i++){
			int j=i+d;
			M[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int cost=M[i][k]+M[k+1][j]+P[i]*P[k+1]*P[j+1];
				if(cost<M[i][j]){
					M[i][j]=cost;
					S[i][j]=k;
				}
					
			}
		}
		
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
				cout<<S[i][j]<<" ";
		cout<<endl;
	}
		cout<<endl<<endl;
		
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
				cout<<M[i][j]<<" ";
		cout<<endl;
	}
	
	cout<<endl<<endl;
	
	cout<<M[0][n-1]<<endl;
	print_cut(S,0,n-1);
}
int main(){
	int P[]={40, 20, 30, 10, 30};
	matorder(P,5);
}
