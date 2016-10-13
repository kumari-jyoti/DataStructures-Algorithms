#include<iostream>
#include<stack>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int k){
	node* pnode=new node;
	pnode->data=k;
	pnode->left=NULL;
	pnode->right=NULL;
	return pnode;
}

void iterative_inorder(node* root){
	if(!root) return;
	stack<node* > s;
	while(1){
		if(root){
			s.push(root);
			root=root->left;
		}
		else{
			if(s.empty()) break;
			root=s.top();
			cout<<root->data<<" ";
			s.pop();
			root=root->right;
		}
	}	
	return;
}

void iterative_preorder(node* root){
	if(!root) return;
	stack<node* > s;
	s.push(root);
	while(!s.empty()){
		node* p=s.top();
		cout<<p->data<<" ";
		s.pop();
		if(p->right!=NULL)
			s.push(p->right);
		if(p->left!=NULL)
			s.push(p->left);		
	}
	return;
}

void iterative_postorder(node* root){
	stack<node* > s1;
	stack<node* > s2;
	s1.push(root);
	while(!s1.empty()){
		node* p=s1.top();
		s1.pop();
		s2.push(p);
		if(p->left) s1.push(p->left);
		if(p->right) s1.push(p->right);
	}
	
	while(!s2.empty())
		{
			node* k=s2.top();
			s2.pop();
			cout<<k->data<<" ";
		}
	
}

int main(){
	node* root=newNode(20);
	root->left=newNode(13);
	root->left->left=newNode(5);
	root->left->right=newNode(15);	
	root->right=newNode(22);
	root->right->left=newNode(21);
	root->right->right=newNode(25);
	iterative_inorder(root);
	cout<<endl;
	iterative_preorder(root);
	cout<<endl;
	iterative_postorder(root);
}
