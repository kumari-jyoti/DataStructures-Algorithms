//To check if 2 binary trees are same
#include<iostream>
using namespace std;

//defining the tree node
struct node{
	int data;
	node* left;
	node* right;
};

//creating new node
node* newNode(int val){
	node* pnode=new node;
	pnode->data=val;
	pnode->left=NULL;
	pnode->right=NULL;
}

//checking if node is a leaf
bool isleaf(node* root){
	if(!root->left && !root->right) return true;
	return false;
}

//checking if 2 given trees are same or not
bool issame(node* root1, node* root2){
	if(!root1 && !root2) return true;//if both trees are null return true
	if(isleaf(root1) && isleaf(root2) && root1->data==root2->data) return true;//if both tree has just one node and the node data is same return true
	if(issame(root1->left,root2->left) && issame(root1->right,root2->right))//else recursively check if both left subtree and right subtree are same or not
		if(root1->data==root2->data) return true;
	return false;
}

//main function
int main(){
	node* root1=newNode(20);
	root1->left=newNode(13);
	root1->right=newNode(22);
	root1->left->left=newNode(5);
	root1->left->left->left=newNode(3);
	root1->left->right=newNode(18);
	root1->right->left=newNode(21);
	root1->right->right=newNode(25);
	
	node* root2=newNode(20);
	root2->left=newNode(13);
	root2->right=newNode(22);
	root2->left->left=newNode(5);
	root2->left->left->left=newNode(3);
	root2->left->right=newNode(18);
	root2->right->left=newNode(21);
	root2->right->right=newNode(2);
	
	return issame(root1,root2);
	
}
