#include<iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

struct node* newNode(int val)
{
	struct node* node=new struct node;
	node->data=val;
	node->left=NULL;
	node->right=NULL;
	return (node);
}

bool isleaf(node * node)
{
	if(!node->left && !node->right) return true;
	return false;
}

int issumtree(node *head)
{
	int ls;
	int rs;
	
	if(head==NULL || isleaf(head))	return 1;
	
	if(issumtree(head->left) && issumtree(head->right))
	{
		if(!head->left)
			ls=0;
		else if(isleaf(head->left))
				 ls=head->left->data;
		else ls=2*head->left->data;
		
		if(!head->right)
			rs=0;
		else if(isleaf(head->right))
			 	rs=head->right->data;
		else rs=2*head->right->data;
		if(head->data==ls+rs) {
		return 1;	
		}
		
	}
	return 0;
}

int main()
{
	struct node* node=newNode(26);
	node->left=newNode(10);
	node->right=newNode(3);
	node->left->left=newNode(4);
	node->left->right=newNode(6);
	node->right->right=newNode(3);
	int k= issumtree(node);
	cout<<k<<endl;
	return k;
}
