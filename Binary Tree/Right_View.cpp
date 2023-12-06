#include <iostream>
#include <queue>
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

void rightView(node* root){ //Time Complexity: O(n)
    if(root == NULL){
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty()){

        int n = q.size(); // calculate nodes in any level
        for (int i = 0; i < n; i++){    //n is the no. of nodes in any level
            node *curr = q.front();
            q.pop();

            if(i == n-1){ //check if the node is rightmost
                cout << curr->data << " "; 
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }  
    }
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

    rightView(root);

    return 0;
}