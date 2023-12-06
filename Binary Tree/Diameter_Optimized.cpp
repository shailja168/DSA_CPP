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

int calcDiameter(node* root, int* height){   //Time Complexity: O(n)
    if (root == NULL){
        *height = 0;
        return 0;
    }
    
    int lheight = 0, rheight = 0;
    int lDiameter = calcDiameter(root->left, &lheight);
    int rDiameter = calcDiameter(root->right, &rheight);

    int currDiameter = lheight + rheight + 1;
    *height = max(lheight, rheight) + 1;

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

    int height = 0;
    cout << calcDiameter(root, &height);

    return 0;
}