#include <iostream>
using namespace std;

/* Minimum distance between two nodes is the minimum no. of edges traversed
   to reach from one node to another.  */

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

node* LCA(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    node *leftLCA = LCA(root->left, n1, n2);
    node *rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA){
        return root;
    }
    if (!leftLCA && !rightLCA){
        return NULL;
    }
    if (leftLCA){
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findDistance(node* root, int key, int dist){
    if(root == NULL){
        return -1;
    }
     
    if(root->data == key){
        return dist;
    }

    int left = findDistance(root->left, key, dist + 1);
    if(left != -1){
        return left;
    }

    return findDistance(root->right, key, dist + 1);
}

int distBtwNodes(node* root, int n1, int n2){
    node *lca = LCA(root, n1, n2);

    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);

    return d1 + d2;
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

    cout << distBtwNodes(root, 4, 7);

    return 0;
}