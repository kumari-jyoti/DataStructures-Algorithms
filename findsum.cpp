#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int val){
	node* pnode=new node;
	pnode->data=val;
	pnode->left=NULL;
	pnode->right=NULL;
	return pnode;
}

bool isleaf(node* p){
	if(!p->left && !p->right) return true;
	return false;
}

stack<int> res;
bool issum(node* root, int sum){
	if(!root) return false;
	if(isleaf(root) && root->data==sum){
		res.push(root->data);
		return true;
	}
	if(issum(root->left,sum-root->data)){
		res.push(root->data);
		return true;
	}
		
	if(issum(root->right,sum-root->data)){
		res.push(root->data);
		return true;
	}
	return false;
}

int main()
{
	node* root=newNode(20);
	root->left=newNode(13);
	root->right=newNode(22);
	root->left->left=newNode(5);
	root->left->right=newNode(18);
	root->right->left=newNode(21);
	root->right->right=newNode(25);
	cout<<issum(root,38)<<endl;
	for(int i=0;!res.empty();i++)
		{int k=res.top();
		res.pop();
		cout<<k<<" ";
		}
	cout<<endl;
	cout<<issum(root,25)<<endl;
	
}
