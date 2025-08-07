/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int& k){
        if(!root) return;

        if(root->val > k){
            // left
            if(root->left == NULL){
                root->left = new TreeNode(k);
                return;
            }
            solve(root->left, k);
        }else{
            // right
            if(root->right == NULL){
                root->right = new TreeNode(k);
                return;
            }
            solve(root->right, k);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int k) {
        if(!root) return new TreeNode(k);

        TreeNode* curr = root;

        solve(curr, k);

        return root;
    }
};