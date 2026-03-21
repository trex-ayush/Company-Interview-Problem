1class Solution {
2public:
3    bool isLeaf(TreeNode* root) {
4        return !root->left && !root->right;
5    }
6    bool solve(TreeNode* root, int& k, int curr){
7        if(!root) return 0;
8
9        curr += root->val;
10        if(isLeaf(root)) {
11            return curr == k;
12        }
13        return solve(root->left, k, curr) 
14            || solve(root->right, k, curr);
15    }
16    bool hasPathSum(TreeNode* root, int targetSum) {
17        if(!root) return false;
18        return solve(root, targetSum, 0);
19    }
20};