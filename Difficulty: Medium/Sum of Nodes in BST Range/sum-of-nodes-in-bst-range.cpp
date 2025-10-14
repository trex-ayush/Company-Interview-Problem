/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorderSum(Node* root, int l, int r, int &sum) {
        if (!root) return;
        
        if (root->data > l) {
            inorderSum(root->left, l, r, sum);
        }
        
        if (root->data >= l && root->data <= r) {
            sum += root->data;
        }
        
        if (root->data < r) {
            inorderSum(root->right, l, r, sum);
        }
    }
    
    int nodeSum(Node* root, int l, int r) {
        int sum = 0;
        inorderSum(root, l, r, sum);
        return sum;
    }
};
