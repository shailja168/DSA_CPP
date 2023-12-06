#include <iostream>
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

void sumReplacement(node* root){    //Time Complexity: O(n)
    if(root == NULL){
        return;
    }

    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left != NULL)
        root->data += root->left->data;
    if(root->right != NULL)
        root->data += root->right->data;
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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

    preorder(root);
    cout << endl;
    sumReplacement(root);
    preorder(root);

    return 0;
}