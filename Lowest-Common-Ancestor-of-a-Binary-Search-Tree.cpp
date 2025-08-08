/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Company tags: X, LinkedIn, Samsung, Yandex, Google
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        if(root == n1 || root == n2) return root;
        
        if(root->val < n1->val && root->val < n2->val){
            // right
            return lowestCommonAncestor(root->right, n1, n2);
        }else if(root->val > n1->val && root->val > n2->val){
            // left
            return lowestCommonAncestor(root->left, n1, n2);
        }else return root;
    }
};