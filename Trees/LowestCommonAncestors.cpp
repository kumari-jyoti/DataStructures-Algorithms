//Lowest Coomon Ancestor for Binary Tree
//Lowest Coomon Ancestor for Binary Search Tree
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
//Lowest Coomon Ancestor for Binary Tree
node* LCABT(node* root,node* n1,node* n2){
	if(!root) return NULL;
	if(root==n1||root==n2) return root;
	node* lef=LCABT(root->left,n1,n2);
	node* rig=LCABT(root->right,n1,n2);
	if(lef!=NULL && rig!=NULL) return root;
	if(lef==NULL && rig==NULL) return NULL;
	
	return (lef!=NULL?lef:rig);
	
}
//Lowest Coomon Ancestor for Binary Tree
node* LCABST(node* root,node* n1,node* n2){
	if(!root) return NULL;
	if(root==n1||root==n2) return root;
	if(root->data>max(n1->data,n2->data)) return LCABST(root->left,n1,n2);
	if(root->data<min(n1->data,n2->data)) return LCABST(root->right,n1,n2);
	return (root);
}
//main function
int main(){
	//create the tree
	node * root=newNode(7);
	root->left=newNode(3);
	node* n1=root->left->left=newNode(2);
	root->left->right=newNode(5);
	root->left->right->left=newNode(4);
	node* n2=root->left->right->right=newNode(6);
	root->right=newNode(9);
	root->right->right=newNode(13);
	root->right->right->left=newNode(8);
	
	//node* n1=newNode(2);
	//node* n2=newNode(5);
	
	node* p= LCABT(root,n1,n2);
	node* q= LCABST(root,n1,n2);
	cout<<p->data<<endl<<q->data;
	return 0;
	
}
