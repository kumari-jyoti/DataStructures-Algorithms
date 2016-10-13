//Checking if a given binary tree is BST or not
#include<iostream>
using namespace std;

//defining the tree node
struct node{
	int data;
	node* left;
	node* right;
};

//creating new node
node* newNode(int k){
	node* p=new node;
	p->data=k;
	p->left=NULL;
	p->right=NULL;
	return p;
}

//checking if node is a leaf or not
bool isleaf(node* p){
	if(!p->left && !p->right) return true;
	return false;
}

//find if the given BT is a BST or not
bool isBST(node* root,int min, int max){//min max defines the range for root
	if(!root) return true;//if no root return true
	if(isleaf(root)) return true;//if tree is a leaf return true
	if(root->data<=max && root->data>=min){
		if(isBST(root->left,min,root->data) && isBST(root->right,root->data,max)){//left subtree values should be less than root's value and right subtree values should be greater than root's value 	
			if(!root->right && root->data>root->left->data) return true;//if only left subtree exists, compare just its value
			if(!root->left && root->data<root->right->data) return true;//if only right subtree exists, compare just its value
			if(root->data>root->left->data && root->data<root->right->data) return true;//else compare with both
		}	
	}
	return false;
}

//main function
int main()
{
	//input tree
	node* root=newNode(10);
	root->left=newNode(0);
	root->right=newNode(25);
	root->left->left=newNode(1);
	root->left->right=newNode(21);
	root->right->left=newNode(16);
	root->right->right=newNode(32);
	
	//define range for the root
	int min=-INT_MAX;
	int max=INT_MAX;
	
	cout<<isBST(root,min,max);
}
