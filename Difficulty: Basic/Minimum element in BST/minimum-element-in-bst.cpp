// Function to find the minimum element in the given BST.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    void solve(Node* root, int& mini){
        mini = min(root->data, mini);
        if(root->left) solve(root->left, mini);
    }
    int minValue(Node* root) {
        if(!root) return -1;
        int mini = INT_MAX;
        
        solve(root, mini);
        
        return mini;
    }
};