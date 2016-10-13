/*Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. Level of root is 1.
*/
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

//finding optimal cost
int cost(int A[], int F[], int n){
	//for storing optimal cost for ith to jth node
	int M[n][n];
	//for storing the structure of optimal tree
	int S[n][n];
	//initialize the structure values as index -1 intially
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		S[i][j]=-1;
	
	//for single node cost is the node's frequency itself and root is that number iteself
	for(int i=0;i<n;i++)
		{
			M[i][i]=F[i];
			S[i][i]=i+1;
		}
	
	for(int l=2;l<=n;l++){
		for(int i=0;i<=n-l;i++){
			int j=i+l-1;
			int pos;
			if(j>0){
				int sumf=0;
				int cost=INT_MAX;
				int sum;
				for(int k=i;k<=j;k++){
					sumf+=F[k];
					if(k==i)
						sum=M[k+1][j];//if root has elements only at its right, then only rightmost optimal cost considered
					else
					if(k==j)
						sum=M[i][k-1];//if root has elements only at its left, then only leftmost optimal cost is considered
					else
						sum=M[i][k-1]+M[k+1][j];//root lies in between i and j, then take optimal cost of left and right
					
					if(sum<cost) pos=i;//if there is updation in optimal cost root points to i	
					cost=min(cost,sum);//update the minimal cost	
				}
				M[i][j]=sumf+cost;//optimal cost of left subtree and right subtree are calculated for 1 level lower,		  
				S[i][j]=pos+1;//as left subtree and right subtre are 1 level lower to actual root, therefore for whole tree all nodes will 
				//go through root ie 1 level more therefore for each node frequency increases by 1, hence sum of frequencies considered
			}
		
		
	}
	}
	
		for(int i=0;i<n;i++){
	
	for(int j=0;j<n;j++)
	cout<<S[i][j]<<" ";
	cout<<endl;}
	
	cout<<endl<<endl;
	return M[0][n-1];

	
}

//main function
int main(){
	//Search keys
	int A[]={10,12,16,21};
	//Serach keys' frequencies
	int F[]={4,2,6,3};
	int n=sizeof(A)/sizeof(A[0]);
	
	cout<<cost(A,F,n);
}
