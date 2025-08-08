/*
// Tree Node
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
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root == n1 || root == n2) return root;
        
        if(root->data < n1->data && root->data < n2->data){
            // right
            return LCA(root->right, n1, n2);
        }else if(root->data > n1->data && root->data > n2->data){
            // left
            return LCA(root->left, n1, n2);
        }else return root;
    }
};