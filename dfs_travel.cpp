#include<iostream>
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

void inorder(node* root){
	if(!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(node* root){
	if(!root) return;
	cout<<root->data<<" ";
	preorder(root->left);	
	preorder(root->right);
}
void postorder(node* root){
	if(!root) return;
	postorder(root->left);	
	postorder(root->right);
	cout<<root->data<<" ";
}

int max(int a, int b){return (a>b?a:b);
}

int height(node* root){
	if(!root) return 0;
	return max(1+height(root->left),1+height(root->right));
}

int countofnodes(node* root){
	if(!root) return 0;
	return (1+countofnodes(root->left)+countofnodes(root->right));
}

void search(node* root, int key){
	if(!root){
		cout<<"not there"<<endl;
		return;
	}
	if(root->data==key){
		cout<<"found"<<endl;
		return;
	}
	if(key>root->data)
		return search(root->right,key);
	else
		return search(root->left,key);
	
}

void insert(node* root, int key)
{
	node* pnode=newNode(key);
	if(!root){
		root=pnode;
		return;
	}
	
	node* parent=NULL;
	node* current=root;
	while(current!=NULL){
		parent=current;
		if(current->data>key)
			current=current->left;
		else
			current=current->right;
	}
	if(key<parent->data)
		parent->left=pnode;
	else
		parent->right=pnode;
	return;
}

int main(){
	node* root=newNode(20);
	root->left=newNode(13);
	root->right=newNode(22);
	root->left->left=newNode(5);
	root->left->left->left=newNode(3);
	root->left->right=newNode(18);
	root->right->left=newNode(21);
	root->right->right=newNode(25);
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	cout<<height(root);
	cout<<endl;
	cout<<countofnodes(root);
	cout<<endl;
	search(root,22);
	search(root,24);
	search(root,30);
	search(root,25);
	insert(root,23);
	insert(root,19);
	insert(root,26);
	inorder(root);
	return 0;
}
