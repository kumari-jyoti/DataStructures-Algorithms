#include<iostream>
#include<queue>
#include<limits.h>
#include<stack>
#include<algorithm>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int val){
	struct node* pnode=new node;
	pnode->data=val;
	pnode->left=NULL;
	pnode->right=NULL;
	return pnode;
}

int maxsum(node* root){
	queue<node*> q;
	q.push(root);
	int level;
	int sum=-INT_MAX;
	while(1){
		int nodecount=q.size();
		if(nodecount==0) break;
		int tempsum=0;
		while(nodecount>0){		
			node* p= q.front();
			q.pop();
			tempsum+=p->data;
			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);
			nodecount--;
		}
		sum=max(sum,tempsum);
	}
	return sum;
}
int diameter(node* root, int* ptr){
	if(!root) {
		*ptr=max(*ptr,0);
		return 0;
	}
	int left=diameter(root->left,ptr);
	int right=diameter(root->right,ptr);
	
	if(left+right+1>*ptr) 
		*ptr=left+right+1;
	
	return max(left,right)+1;
}

bool isleaf(node* root){
	if(!root->left && !root->right) return true;
	return false;
}

void printpath(int path[],int pathlen){
	for(int i=0;i<pathlen;i++)
		cout<<path[i]<<" ";
	cout<<endl;	
}

void roottoleafpath(node* root, int path[], int pathlen){
	if(!root) return;
	path[pathlen]=root->data;
	pathlen++;
	if(isleaf(root))
		printpath(path,pathlen);
	else{		
	roottoleafpath(root->left,path,pathlen);
	roottoleafpath(root->right,path,pathlen);		
	}
}

int height(node* root){
	if(!root) return 0;
	int l=height(root->left);
	int r=height(root->right);
	return max(l,r)+1;
}

bool pathgivensum(node* root, int sum){
	if(!root) return(0);
	if(root->data==sum) return true;
	//for sum of any n nodes
	//if(pathgivensum(root->left,sum-root->data)||pathgivensum(root->right,sum-root->data)||pathgivensum(root->left,sum)||pathgivensum(root->right,sum))
	//	return true;
	if(pathgivensum(root->left,sum-root->data)||pathgivensum(root->right,sum-root->data)) return true;
	return false;	
}

int main(){
	node* root=newNode(20);
	root->left=newNode(-13);
	
	root->left->left=newNode(5);
	root->right=newNode(28);
	root->left->right=newNode(18);
	root->right->left=newNode(21);
	root->right->right=newNode(25);
	root->left->left->left=newNode(3);
	root->left->left->left->left=newNode(31);
	
	root->left->right->right=newNode(19);
	root->left->right->right->left=newNode(23);
	root->left->right->right->left->right=newNode(24);

	root->right->left->right=newNode(19);
	root->right->left->right->left=newNode(23);
	root->right->left->right->left->right=newNode(24);
	
	
	//1. diameter
	int d=-INT_MAX;
	cout<<diameter(root,&d)<<" ";
	cout<<d<<endl;
	//2. max level having maxsum
	cout<<"sum"<<maxsum(root)<<endl;
	//3. all root to leaf paths
	int h=height(root);
	int path[h];
	int pathlen=0;
	roottoleafpath(root,path,pathlen);
	cout<<endl;
	//4. existence of path with given sum
	cout<<pathgivensum(root,12);
	return 0;
	
}
