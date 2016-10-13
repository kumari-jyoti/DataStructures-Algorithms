#include<iostream>
#include<queue>
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

bool isleaf(node* root){
	if(!root->left && !root->right) return true;
	return false;
}

int max(int a,int b){
return(a>b?a:b);	
}

int findmax(node* root){
	if(!root) return -1;
	if(isleaf(root)) return root->data;
	int leftmax=findmax(root->left);
	int rightmax=findmax(root->right);
	int i= max(leftmax,rightmax);
	return(max(i,root->data));
}

node* deepestnode(node* root){
	if(!root) return 0;
	queue<node*> q;
	q.push(root);
	node* p;
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);
		}
	return p;
}

int height(node* root){
	if(!root) return 0;
	int h=0;
	queue<node*> q;
	q.push(root);
	int nodecount;
	node* p;
	
	while(1){
		nodecount=q.size();
		if(nodecount==0) break;
		while(nodecount>0)
		{
			p=q.front();
			q.pop();
			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);
			nodecount--;
		}
		h++;
	}
	
	return h;
}

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

bool isfull(node* root){
	if(root->right && root->left) return true;
	return false;
}

bool ishalf(node* root){
	if((!root->left && root->right)||(root->left && !root->right)) return true;
	else return false;
}
int numofleaves(node* root){
	if(!root) return 0;
	int leaves=0;
	int full=0;
	int half=0;
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

int main(){
	node* root=newNode(20);
	root->left=newNode(13);
	root->right=newNode(28);
	root->left->left=newNode(5);
	root->left->right=newNode(18);
	node* q=root->right->left=newNode(21);
	root->right->right=newNode(25);
	root->left->left->left=newNode(3);
	cout<<findmax(root)<<" this is max node "<<endl;
	cout<<height(root)<<" this is height of tree "<<endl;
	node* p;
	p=deepestnode(root);
	cout<<p->data<<" this is the deepest node "<<endl;
	deletebt(root,q );
	cout<<"a node has been deleted"<<endl;
	cout<<numofleaves(root)<<" this is number of leaves in this tree"<<endl;
	return 0;
}
