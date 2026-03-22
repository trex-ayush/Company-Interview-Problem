1/*
2    Company tags: Tiktok, Walmart Labs, Oracle
3    T.C: O(n)
4    S.C: O(h)
5*/
6class Solution {
7public:
8    bool isLeaf(TreeNode* root) {
9        return !root->left && !root->right;
10    }
11    void solve(TreeNode* root, int& k, vector<vector<int>>& res, vector<int> temp, int curr){
12        if(!root) return;
13        curr += root->val;
14        temp.push_back(root->val);
15        if(isLeaf(root) && curr == k) {
16            res.push_back(temp);
17        }
18
19        solve(root->left, k, res, temp, curr);
20        solve(root->right, k, res, temp, curr);
21
22        curr -= root->val;
23        temp.pop_back();
24    }
25    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
26        vector<vector<int>> res;
27        if(!root) return res;
28
29        solve(root, targetSum, res, {}, 0);
30
31        return res;
32    }
33};