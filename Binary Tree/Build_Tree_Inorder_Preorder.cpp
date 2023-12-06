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

int search(int inorder[], int start, int end, int curr){
    for (int i = start; i <= end; i++){
        if (inorder[i] == curr)
            return i;
    }
    return -1;
}

node* buildTree(int preorder[], int inorder[], int start, int end){
    static int preindx = 0;
    if(start>end){  //base case
        return NULL;
    }

    int curr = preorder[preindx];
    preindx++;
    node *root = new node(curr);

    if(start==end){    //if tree has only 1 node
        return root;
    }

    //this will give the position of the current element in inorder[]
    int pos = search(inorder, start, end, curr);

    root->left = buildTree(preorder, inorder, start, pos - 1); // build left subtree
    root->right = buildTree(preorder, inorder, pos + 1, end); // build right subtree

    return root;
}

void inorderPrint(node *root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    node* root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}