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

node* buildTree(int postorder[], int inorder[], int start, int end){
    static int postidx = end;
    if(start > end){  //base case
        return NULL;
    }

    int curr = postorder[postidx];
    postidx--;
    node *root = new node(curr);

    if(start==end){    //if tree has only 1 node
        return root;
    }

    //this will give the position of the current element in inorder[]
    int pos = search(inorder, start, end, curr);

    root->right = buildTree(postorder, inorder, pos + 1, end); // build right subtree
    root->left = buildTree(postorder, inorder, start, pos - 1); // build left subtree

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
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    node* root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}