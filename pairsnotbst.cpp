#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
struct result
{
	int val1;
	int val2;
}; 

vector<int> s;

void inorder_pair_not_bst(node* root){
	if(!root) return;
	inorder_pair_not_bst(root->left);
	s.push_back(root->data);
	inorder_pair_not_bst(root->right);
	return;			
}

void findpair(node* root){
	inorder_pair_not_bst(root);
	if(s.empty()) return;
	int k=s[0];
	for(int i=1;i<s.size();i++)
	{
		if(s[i]<s[i-1]){
			for(int j=0;j<i;j++){
				if(s[i]<s[j])
					cout<<s[j]<<" "<<s[i]<<endl;
			}
		}
	}
return;
}


int main()
{
	node *root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(60);
    root->left->left = newNode(20);
    root->left->right = newNode(25);
    root->right->left = newNode(10);
    root->right->right = newNode(40);
    findpair(root);
}
