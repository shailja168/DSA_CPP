#include <iostream>
using namespace std;

/*  Balanced Height Binary Tree: 
For each node, the difference btw the heights of the left subtree 
and right subtree is <= 1  */

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

bool isBalanced(node* root, int* height){     //Time Complexity: O(n)
    int lh = 0, rh = 0;
    if(root == NULL){
        return true;
    }
    if(isBalanced(root->left, &lh) == false){
        return false; 
    }
    if(isBalanced(root->right, &rh) == false){
        return false; 
    }

    *height = max(lh, rh) + 1;

    if(abs(lh-rh) <= 1){
        return true;
    }
    else{
        return false;
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

    int height = 0;
    if(isBalanced(root, &height)){
        cout << "Balanced tree\n";
    }
    else{
        cout << "Unbalanced tree\n";
    }

    return 0;
}