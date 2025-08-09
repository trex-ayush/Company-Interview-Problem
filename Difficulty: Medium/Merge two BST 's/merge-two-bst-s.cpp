/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void inorder(Node* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }

    vector<int> merge(Node *root1, Node *root2) {
        vector<int> v1, v2, merged;
        
        inorder(root1, v1);
        inorder(root2, v2);
        
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                merged.push_back(v1[i++]);
            } else {
                merged.push_back(v2[j++]);
            }
        }
        
        while (i < v1.size()) merged.push_back(v1[i++]);
        while (j < v2.size()) merged.push_back(v2[j++]);
        
        return merged;
    }
};