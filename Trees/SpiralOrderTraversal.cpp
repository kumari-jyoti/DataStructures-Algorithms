#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;

int level;

struct tree_node
{
	int data;
	tree_node* left;
	tree_node* right;
};

tree_node* newNode(int val)
{
	tree_node* pnode=new tree_node;
	pnode->data=val;
	pnode->left=NULL;
	pnode->right=NULL;
	return pnode;
}

void spiralorder(tree_node* root){
	if(!root) return;
	queue<tree_node*> q;
	stack<tree_node*> s;
	q.push(root);
	int nodecount;
	int level=0;
	//printing in down up order	
	while(1)
	{
		nodecount=q.size();
		if(nodecount==0) break;
		while(nodecount>0)
		{
			tree_node* p=q.front();
			if(level%2==0)
				cout<<p->data<<" ";
			else
				s.push(p);
				
			q.pop();
			if(p->left) q.push(p->left);	
			if(p->right) q.push(p->right);
			nodecount--;
		}
		
		while(!s.empty()){
			cout<<s.top()->data<<" ";
			s.pop();
		}
		level++;
		cout<<endl;					
	}
}

void levelorder(tree_node* root)
{
	if(!root) return;
	queue<tree_node*> q;
	q.push(root);
	int nodecount;
	//printing in normal order	
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

int main()
{
	level=0;
	tree_node* root=newNode(20);
	root->left=newNode(13);
	root->left->left=newNode(5);
	root->right=newNode(22);
	root->left->right=newNode(15);
	root->right->left=newNode(21);
	root->right->right=newNode(25);
	levelorder(root);
	cout<<endl<<endl;
	spiralorder(root);
	return 0;
}
