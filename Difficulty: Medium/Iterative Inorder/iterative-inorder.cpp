// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int> result;
        stack<Node*> st;
        Node* current = root;
        
        while (current != nullptr || !st.empty()) {
            // Go to the leftmost node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            
            // Process the node
            current = st.top();
            st.pop();
            result.push_back(current->data);
            
            // Visit the right subtree
            current = current->right;
        }
        
        return result;
    }
};