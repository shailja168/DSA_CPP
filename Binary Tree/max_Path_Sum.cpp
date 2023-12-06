#include <iostream>
#include <climits>
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

int maxPathSumUtility(node* root, int ans){
    if(root == NULL){
        return 0;
    }

    int left = maxPathSumUtility(root->left, ans);
    int right = maxPathSumUtility(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), 
                        max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    return singlePathSum;
}

int maxPathSum(node* root){

    int ans = INT_MIN;
    return maxPathSumUtility(root, ans);
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

    cout << maxPathSum(root);

    return 0;
}