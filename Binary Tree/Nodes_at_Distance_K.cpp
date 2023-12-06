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

//case 1: subtree
void printSubtreeNodes(node *root, int k){
    if(root == NULL || k<0){
        return;
    }
    if(k==0){
        cout << root->data << " ";
        return;
    }
    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}
 
//case 2: ancestor

int printNodesAtk(node *root, node *target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printSubtreeNodes(root, k);
        return 0;
    }

    int dl = printNodesAtk(root->left,target, k);
    if(dl != -1){  //target found in left subtree
        if(dl + 1 == k){
            cout << root->data << " ";
        }
        else{
            printSubtreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printNodesAtk(root->right,target, k);
    if(dr != -1){  //target found in left subtree
        if(dr + 1 == k){
            cout << root->data << " ";
        }
        else{
            printSubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
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

    int k;
    cout << "enter value of k: ";
    cin >> k;

    printNodesAtk(root, root->right, k);

    return 0;
}