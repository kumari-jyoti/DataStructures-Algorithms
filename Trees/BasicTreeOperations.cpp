/*Basic Tree Operations
1. Inorder Traversal
2. Preorder Traversal
3. Postorder Traversal
4. Height of a Tree
5. Size of a Tree
6. Searching a key
7. Inserting a key
*/

#include<iostream>
using namespace std;

//defining the tree node
struct node{
	int data;
	node* left;
	node* right;
};

//creating new tree node
node* newNode(int val){
	struct node* pnode=new node;
	pnode->data=val;
	pnode->left=NULL;
	pnode->right=NULL;
	return pnode;
}

//recursive inorder traversal
void inorder(node* root){
	if(!root) return;
	inorder(root->left);//traverse left
	cout<<root->data<<" ";//traverse root
	inorder(root->right);//traverse right
}

//recursive pre-order traversal
void preorder(node* root){
	if(!root) return;
	cout<<root->data<<" ";//traverse root
	preorder(root->left);//traverse left	
	preorder(root->right);//traverse right
}

//recursive postorder traversal
void postorder(node* root){
	if(!root) return;
	postorder(root->left);//traverse left	
	postorder(root->right);//traverse right
	cout<<root->data<<" ";//traverse root
}

int max(int a, int b){return (a>b?a:b);
}

//finding height of a tree
int height(node* root){
	if(!root) return 0;
	return max(1+height(root->left),1+height(root->right));
}

//finding size of a tree
int countofnodes(node* root){
	if(!root) return 0;
	return (1+countofnodes(root->left)+countofnodes(root->right));
}

//searching a key
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

//inserting key in the tree
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

//main function
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
