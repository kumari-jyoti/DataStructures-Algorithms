/*Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. Level of root is 1.
*/
#include<iostream>
#include<algorithm>
#include<limits.h>
#include <queue>
#include <stack>
using namespace std;

//defining the optimal BST tree node
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

//creating the node
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//printing the optimal BST in levelorder
void levelorder(node* root)
{
	if(!root) return;
	queue<node*> q;
	q.push(root);
	int nodecount;
	//printing in normal order	
	while(1)
	{
		nodecount=q.size();
		if(nodecount==0) break;
		while(nodecount>0)
		{
			node* p=q.front();
			cout<<p->data<<" ";
			q.pop();
			if(p->left) q.push(p->left);
			if(p->right) q.push(p->right);
			nodecount--;
		}
		cout<<endl;					
	}	
}

//creating optimal BST
node* printOBST(int A[],int S[4][4],int start,int end){
	if(start>end) return NULL;//if no more node to be included
	node* temproot=newNode(A[S[start][end]]);//root node at this level
	int br=S[start][end];//optimal r
	node* l=printOBST(A,S,start,br-1);//find optimal new root at left of root
	node* r=printOBST(A,S,br+1,end);//find optimal new root at right of root
	temproot->left=l;
	temproot->right=r;
	return temproot;
}

//finding optimal cost
int cost(int A[], int F[], int n){
	//for storing optimal cost for ith to jth node
	int M[n][n];
	//for storing the structure of optimal tree
	int S[4][4];
	//initialize the structure values as index -1 intially
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		S[i][j]=-1;
	
	//for single node cost is the node's frequency itself and root is that number iteself
	for(int i=0;i<n;i++)
		{
			M[i][i]=F[i];
			S[i][i]=i;
		}
	
	for(int l=2;l<=n;l++){//trees of number of nodes: 2, 3, 4,.. and so on
		for(int i=0;i<=n-l;i++){
			int j=i+l-1;//lies between i and number of nodes considered
			int pos;//stores the root value for subtree ith node to jth node
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
					
					if(sum<cost) pos=k;//if there is updation in optimal cost root points to i	
					cost=min(cost,sum);//update the minimal cost	
				}
				M[i][j]=sumf+cost;//optimal cost of left subtree and right subtree are calculated for 1 level lower,		  
				S[i][j]=pos;//as left subtree and right subtre are 1 level lower to actual root, therefore for whole tree all nodes will 
				//go through root ie 1 level more therefore for each node frequency increases by 1, hence sum of frequencies considered
			}	
		}
	}
	//creating optimal bst
	node* root=printOBST(A,S,0,n-1);
	//printing the tree
	levelorder(root);
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
