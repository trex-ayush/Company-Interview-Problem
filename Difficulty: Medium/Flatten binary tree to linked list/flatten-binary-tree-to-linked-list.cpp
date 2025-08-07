// User function Template for C++

class Solution {
  public:
    Node* nextRight = NULL;
    void flatten(Node* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;

        nextRight = root;
    }
};