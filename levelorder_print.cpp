#include <iostream>
#include <queue>
#include <stack>
using namespace std;
 
struct node
{
    struct node *left;
    int data;
    struct node *right;
};


void printLevelOrder(node *root)
{
    if (root == NULL)  return;
 
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    int level=1;
 
    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
 
        while (nodeCount > 0)
        {
            node *node = q.front();
            if(level%2)
            	cout << node->data << " ";
            else
            	s.push(node);
            
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        if(level%2==0)
        while(!s.empty()){
        	node* t=s.top();
        	s.pop();
        	cout<<t->data<<" ";
		}
        cout << endl;
        level++;
    }
}
 
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    printLevelOrder(root);
    return 0;
}
