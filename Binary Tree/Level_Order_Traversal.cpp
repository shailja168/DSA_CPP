#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(node *root){
    if(root == NULL){
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node *curr = q.front();
        q.pop();
        if(curr != NULL){
            cout << curr->data << " ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL) 
                q.push(curr->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    } 
}

/*   1
    / \
   2   3
  / \  / \
 4  5  6  7   */

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    //Level Order Traversal
    printLevelOrder(root);

    return 0;
}