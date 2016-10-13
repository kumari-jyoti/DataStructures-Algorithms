#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int k){
	node* p=new node;
	p->data=k;
	p->left=NULL;
	p->right=NULL;
	return p;
}

bool isleaf(node* p){
	if(!p->left && !p->right) return true;
	return false;
}

bool isBST(node* root,int min, int max){
	//if no root
	if(!root) return true;
	if(root->data<=max && root->data>=min){
		if(isBST(root->left,min,root->data) && isBST(root->right,root->data,max)){
			if(isleaf(root)) return true;
		//case1 has only left nodes
		if(!root->right && root->data>root->left->data) return true;
		if(!root->left && root->data<root->right->data) return true;
		if(root->data>root->left->data && root->data<root->right->data) return true;
	}	
	}
	
	return false;
}

int main()
{
	node* root=newNode(10);
	root->left=newNode(0);
	root->right=newNode(25);
	root->left->left=newNode(1);
	root->left->right=newNode(21);
	root->right->left=newNode(16);
	root->right->right=newNode(32);
	
	int min=-INT_MAX;
	int max=INT_MAX;
	
	cout<<isBST(root,min,max);
}
