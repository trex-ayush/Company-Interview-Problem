// User function Template for C++

class Solution {
  public:
    int solve(Node* root){
        if(!root) return 0;
        int ans = 0;
        if(root->left){
            ans += 1 + solve(root->left);
        }
        if(root->right){
            ans += 1 + solve(root->right);
        }
        
        return ans;
    }
    int countNodes(Node* root) {
        return solve(root) + 1;
    }
};