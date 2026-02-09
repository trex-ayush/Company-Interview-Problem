1// Company tags: Yandex, Meta, Yahoo, Uber
2class Solution {
3public:
4    int height(TreeNode* root){
5        if(!root) return 0;
6        int lH = height(root->left);
7        int rH = height(root->right);
8        return 1 + max(lH, rH);
9    }
10    bool isBalanced(TreeNode* root) {
11        if (!root) return true;
12        if (abs(height(root->left) - height(root->right)) > 1) return false;
13        return isBalanced(root->left) && isBalanced(root->right);
14    }
15};