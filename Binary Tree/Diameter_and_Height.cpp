#include <iostream>
using namespace std;

// Height of tree: Depth of the tree's deepest node
// Diameter of tree: No. of nodes in the longest path between any 2 leaf nodes

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

int calcHeight(node* root){  //Time Complexity: O(n)
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

int calcDiameter(node* root){   //Time Complexity: O(n^2)
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;
    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
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

    cout << calcHeight(root) << endl;
    
    cout << calcDiameter(root);

    return 0;
}