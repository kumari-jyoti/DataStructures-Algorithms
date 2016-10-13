#include<iostream>
using namespace std;

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

node* newNode(int f,char ch){
	node* p=new node;
	p->freq=f;
	p->data=ch;
	p->left=NULL;
	p->right=NULL;
}

bool isleaf(node* root){if(!root->left && !root->right) return true; return false;}
void decode_huff(node * root,string s)
{
	if(!root) return;
	if(isleaf(root)) cout<<root->data;
	
    node* p =root;
    int i=0;
    for(i;i<s.size();i++){
        if(s[i]=='1')
            {
            	p=p->right;
			}
        else p=p->left;
        if(isleaf(p)){
           cout<<p->data;
           p=root;
        }
    }
    return;
}

int main(){
	node* root=newNode(5,'@');
	root->right=newNode(3,'A');
	root->left=newNode(2,'@');
	root->left->left=newNode(1,'B');
	root->left->right=newNode(1,'C');
	decode_huff(root,"1001011");
	return 0;
	
}
