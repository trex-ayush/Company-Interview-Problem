/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void fun(Node* root, vector<int> &ans){
        if(!root) return;
          
        fun(root->left, ans);  
        fun(root->right, ans);
        
        ans.push_back(root->data);
    }
  
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        fun(root, ans);
        return ans;
    }
};