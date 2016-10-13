/*Basic Tree Operations Contd
1. Maximum Valued node
2. The deepest node's parent
3. The deepest node
4. Deleting a node
5. Number of leaves, half nodes, full nodes
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

//defining the tree node
struct node{
	int data;
	node* left;
	node* right;
};

//creating a new node
node* newNode(int val){
	struct node* pnode=new node;
	pnode->data=val;
	pnode->left=NULL;
	pnode->right=NULL;
	return pnode;
}

//finding if node is a leaf
bool isleaf(node* root){
	if(!root->left && !root->right) return true;
	return false;
}

//finding the node having maximum values
int findmax(node* root){
	if(!root) return -1;
	if(isleaf(root)) return root->data;
	int leftmax=findmax(root->left);
	int rightmax=findmax(root->right);
	int i= max(leftmax,rightmax);
	return(max(i,root->data));
}

//finding deepest node's parent
node* deepestnodeparent(node* root){
	if(!root) return 0;
	queue<node*> q;
	q.push(root);
	node* parent;
	node* p;
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			if(p->left)
				{
					q.push(p->left);
					parent=p;
				}
			if(p->right)
				{
					q.push(p->right);
					parent=p;
				}
			
		}
	return parent;
}

//finding the deepest node
node* deepestnode(node* root){
	node* p=deepestnodeparent(root);
	if(p->right) return p->right;
	return p->left;
}

//deleting a node
void deletebt(node* root, node* temp){
	//find the deepest node's parent
	node* q=deepestnodeparent(root);
	//replace deepest nodes data with node to be deleted
	if(q->right)
	{
		temp->data=q->right->data;
		node* t=q->right;
		q->right=NULL;
		free(t); return;
	}
	if(q->left)
	{
		temp->data=q->left->data;
		node* t=q->left;
		q->left=NULL;
		free(t); return;
	}	
}

//checking if full node
bool isfull(node* root){
	if(root->right && root->left) return true;
	return false;
}

//checking if half leaf node
bool ishalf(node* root){
	if((!root->left && root->right)||(root->left && !root->right)) return true;
	else return false;
}

//finding number of full, half, leaf nodes
int numofleaves(node* root){
	if(!root) return 0;
	//declare count of different types of nodes
	int leaves=0;
	int full=0;
	int half=0;
	//traverse level order and check type of every node
	queue<node*> q;
	q.push(root);
	node* p;
		while(!q.empty())
		{
			p=q.front();
			if(isleaf(p)) leaves++;
			if(isfull(p)) full++;
			if(ishalf(p)) half++;
			q.pop();
			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);
		}
	cout<<full<<" this is number of full leaves "<<endl;
	cout<<half<<" this is number of half leaves "<<endl;
	return leaves;
}

//main function
int main(){
	//input tree
	node* root=newNode(20);
	root->left=newNode(13);
	root->right=newNode(28);
	root->left->left=newNode(5);
	root->left->right=newNode(18);
	root->right->left=newNode(21);
	root->right->right=newNode(25);
	root->left->left->left=newNode(3);
	
	//input node for deletion
	node* q=root->right->left;
	
	//operations
	cout<<findmax(root)<<" this is max node "<<endl;
	node* p;
	p=deepestnode(root);
	cout<<p->data<<" this is the deepest node "<<endl;
	cout<<"node containing "<<q->data<<" has been deleted"<<endl;
	deletebt(root,q );
	cout<<numofleaves(root)<<" this is number of leaves in this tree"<<endl;
	return 0;
}
