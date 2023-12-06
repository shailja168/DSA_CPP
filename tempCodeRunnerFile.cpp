#include <iostream>
#include <climits>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;   
    }
};

node* insertBST(node* root, int val){
    if(root == NULL){
        return new node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


/*   5
    / \
   1   7
    \    
     3   
    / \            
   2   4    */

int main()
{
    node *root = NULL;
    int val;
    cin >> val;
    root = insertBST(root, val);
    for (int i = 0; i < 5; i++){  
        cin >> val;
        insertBST(root, val);
    }

    inorder(root);

    return 0;
}