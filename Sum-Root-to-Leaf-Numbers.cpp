1class Solution {
2public:
3    bool isLeaf(TreeNode* root) {
4        return !root->left && !root->right; 
5    }
6    void solve(TreeNode* root, int& res, int curr) {
7        if(!root) return;
8
9        if(isLeaf(root)) {
10            curr = curr*10 + root->val;
11            res += curr;
12            cout << "Curr : " << curr << " res : " << res << endl;
13            return;
14        }
15        curr = curr*10 + root->val;
16        // cout << "Curr : " << curr << endl;
17        solve(root->left, res, curr);
18        solve(root->right, res, curr);
19        curr = (curr - root->val) / 10;
20    }
21    int sumNumbers(TreeNode* root) {
22        if(!root) return 0;
23        int res = 0;
24        int curr = 0;
25        solve(root, res, curr);
26        return res;
27    }
28};