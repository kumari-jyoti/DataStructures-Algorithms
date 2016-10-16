#include<iostream>
#include<algorithm>
using namespace std;

//defining node of the tee
struct node{
	int val;
	node* left;
	node* right;
	int ht;
}*root;
// A utility function to get height of the tree
int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->ht;
}
//creating new node
node* newNode(int k){
	node* p=new node;
	p->val=k;
	p->ht=1;
	p->right=NULL;
	p->left=NULL;
	return p;
}
//left rotation
node* leftrotate(node* root){
	node* newroot=root->right;
	node* shift=newroot->left;
	//do rotation
	root->right=shift;
	newroot->left=root;
	//update height of t and root
	newroot->ht=max(height(newroot->left),height(newroot->right))+1;
	root->ht=max(height(root->left),height(root->right))+1;
	//return new root
	return newroot;
}
//right rotation
node* rightrotate(node* root){
	node* newroot=root->left;
	node* shift=newroot->right;
	//do rotation
	root->left=shift;
	newroot->right=root;
	//update height of t and root
	newroot->ht=max(height(newroot->left),height(newroot->right))+1;
	root->ht=max(height(root->left),height(root->right))+1;
	//return new root
	return newroot;
}
// Get Balance factor of node N
int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
//insert in AVL Tree
node* insert(node* root, int val){
	//if root is null this becomes root
	if(!root) 
		return newNode(val);
	//if less than root, go left, else go right	
	if(root->val>val) root->left=insert(root->left,val);
	else root->right=insert(root->right,val);
	//update the root
	root->ht=max(height(root->left), height(root->right))+1;
	//get balance factor
	int balance=getBalance(root);
	//check if unbalance
	//left side imbalance
	if(balance>1){
		//case 1 left left
		if(root->left->val>val) return rightrotate(root);
		//case 2 left right
		else{
			root->left=leftrotate(root->left);
			return rightrotate(root);
		}
	}	
	//right side imbalance
	if(balance<-1){
		//case 3 right right
		if(root->right->val<val) return leftrotate(root);
		//case 4 right left
		else{
			root->right=rightrotate(root->right);
			return leftrotate(root);
		}
	}
	//if no imbalance
	return root;
}

void inorder(node* root){
	if(!root) return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int main(){
root=insert(root,4);
root=insert(root,3);
root=insert(root,12);
root=insert(root,6);
root=insert(root,9);
root=insert(root,1);
root=insert(root,15);
root=insert(root,8);
root=insert(root,2);
inorder(root);	
}
