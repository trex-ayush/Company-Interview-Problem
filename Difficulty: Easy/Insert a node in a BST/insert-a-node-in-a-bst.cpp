// Function to insert a node in a BST.

/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* insert(Node* root, int k) {
        if(!root) return new Node(k);
        
        Node* curr = root;
        
        while(curr){
            if(curr->data == k) break;
            else if(curr->data > k){
                // left
                if(curr->left == NULL){
                    curr->left = new Node(k);
                    break;
                }
                curr = curr->left;
            }else{
                // right
                if(curr->right == NULL){
                    curr->right = new Node(k);
                    break;
                }
                curr = curr->right;
            }
        }
        
        return root;
    }
};