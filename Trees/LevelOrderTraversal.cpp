#include<iostream>
#include<cstdlib>
#include<queue>
//level order and reverse level order
#include<stack>
using namespace std;

//declare level 
int level;

//defining the tree-node
struct tree_node
{
	int data;
	tree_node* left;
	tree_node* right;
};

//creating new node
tree_node* newNode(int val)
{
	tree_node* pnode=new tree_node;
	pnode->data=val;
	pnode->left=NULL;
	pnode->right=NULL;
	return pnode;
}

//printing in reverse level order
void revlevelorder(tree_node* root){
	if(!root) return;
	queue<tree_node*> q;
	stack<tree_node*> s;//for storing reversing level order 
	q.push(root);
	int nodecount;//keeps count of nodes at each level
		
	while(1)
	{
		nodecount=q.size();
		if(nodecount==0) break;
		while(nodecount>0)
		{
			tree_node* p=q.front();
			s.push(p);//traverse level order and keep pushing to the stack instead of printing
			q.pop();
			if(p->left) q.push(p->left);	
			if(p->right) q.push(p->right);
			nodecount--;
		}
		//pop the stack if asked to reverse just each level
	}
	while(!s.empty()){
			tree_node* p= s.top();
			cout<<p->data<<" ";
			s.pop();
		}
		cout<<endl;
}

//level order traversal
void levelorder(tree_node* root)
{
	if(!root) return;
	queue<tree_node*> q;
	q.push(root);
	int nodecount;//keeps count of node at each level
		
	while(1)
	{
		nodecount=q.size();
		if(nodecount==0) break;
		while(nodecount>0)
		{
			tree_node* p=q.front();
			cout<<p->data<<" ";
			q.pop();
			if(p->left) q.push(p->left);
			if(p->right) q.push(p->right);
			nodecount--;
		}
		cout<<endl;					
	}	
}

//main function
int main()
{
	//declaring root's level
	level=0;
	//input tree
	tree_node* root=newNode(20);
	root->left=newNode(13);
	root->left->left=newNode(5);
	root->right=newNode(22);
	root->left->right=newNode(15);
	root->right->left=newNode(21);
	root->right->right=newNode(25);
	//traversals
	levelorder(root);
	revlevelorder(root);
	return 0;
}
