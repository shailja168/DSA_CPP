#include <iostream>
#include <vector>
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

bool getPath(node* root, int key, vector<int> &path){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == key){
        return true;
    }

    if(getPath(root->left, key, path) || getPath(root->right, key, path)){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(node* root, int node1, int node2){
    vector<int> path1, path2;

    //check if paths exist for node1 and node2
    if(!getPath(root, node1, path1) || !getPath(root, node2, path2)){
        return -1;
    }

    int pc; //pathchange
    for (pc = 0; pc < path1.size() && pc < path1.size() ; pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }
    return path1[pc - 1];
}

node* LCA_Optimized(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    node *leftLCA = LCA_Optimized(root->left, n1, n2);
    node *rightLCA = LCA_Optimized(root->right, n1, n2);

    if(leftLCA && rightLCA){
        return root;
    }
    if(leftLCA){
        return leftLCA;
    }
    else{
        return rightLCA;
    }
}

/*   1
    / \
   2   3
  /   / \
 4   5   6   
    /
   7      */

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);

    int n1 = 7, n2 = 6;

    cout << LCA(root, n1, n2) << endl;

    node *ans = LCA_Optimized(root, n1, n2);
    cout << ans->data;

    return 0;
}