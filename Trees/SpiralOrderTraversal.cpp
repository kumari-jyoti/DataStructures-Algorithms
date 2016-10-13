/*Spiral order Traversal
1. using a queue and a stack
2. using 2 stacks
3. using double ended queue
*/
#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;

//declare tree level
int level;

//defining the tree node
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

//using a queue and a stack
void spiralorder(tree_node* root){
	if(!root) return;
	queue<tree_node*> q;
	stack<tree_node*> s;//for storing odd levels values
	q.push(root);
	int nodecount;
	int level=0;
		
	while(1)
	{
		nodecount=q.size();
		if(nodecount==0) break;
		while(nodecount>0)
		{
			tree_node* p=q.front();
			if(level%2==0) cout<<p->data<<" ";
			else s.push(p);	
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

//main function
int main()
{
	//declare the level of root
	level=0;
	//input tree
	tree_node* root=newNode(20);
	root->left=newNode(13);
	root->left->left=newNode(5);
	root->right=newNode(22);
	root->left->right=newNode(15);
	root->right->left=newNode(21);
	root->right->right=newNode(25);
	
	spiralorder(root);
	return 0;
}
