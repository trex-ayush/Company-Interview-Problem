1class Solution {
2public:
3    // T.C: O(n)
4    // S.C: O(1)
5    vector<int> inorderTraversal(TreeNode* root) {
6        TreeNode* curr = root;
7        vector<int> res;
8
9        while(curr) {
10            if(curr->left == NULL) {
11                res.push_back(curr->val);
12                curr = curr->right;
13            } else {
14                TreeNode* leftChild = curr->left;
15                while(leftChild->right) {
16                    leftChild = leftChild->right;
17                }
18                leftChild->right = curr;
19                // Very Important Step
20                TreeNode* temp = curr;
21                curr = curr->left;
22                temp->left = NULL;
23            } 
24        }
25        return res;
26    }
27};