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

bool isleaf(node* root){if(!root->left && !root->right) return true; return false;
}

node* LCABT(node* root,node* n1,node* n2){
	if(!root) return NULL;
	if(root==n1||root==n2) return root;
	node* lef=LCABT(root->left,n1,n2);
	node* rig=LCABT(root->right,n1,n2);
	if(lef!=NULL && rig!=NULL) return root;
	if(lef==NULL && rig==NULL) return NULL;
	
	return (lef!=NULL?lef:rig);
	
}

int main(){
	node * root=newNode(3);
	root->left=newNode(6);
	node* n1=root->left->left=newNode(2);
	root->left->right=newNode(11);
	root->left->right->left=newNode(9);
	node* n2=root->left->right->right=newNode(5);
	root->right=newNode(8);
	root->right->right=newNode(13);
	root->right->right->left=newNode(7);
	
	//node* n1=newNode(2);
	//node* n2=newNode(5);
	
	node* p= LCABT(root,n1,n2);
	cout<<p->data<<endl;
	return 0;
	
}
