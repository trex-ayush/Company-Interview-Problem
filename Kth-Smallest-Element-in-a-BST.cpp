class Solution {
public:
    void solve(TreeNode* root, int k, priority_queue<int>& pq){
        if(!root) return;

        pq.push(root->val);
        if(pq.size() > k) pq.pop();

        if(root -> left)  solve(root -> left, k, pq);
        if(root -> right) solve(root -> right, k, pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;

        solve(root, k, pq);

        return pq.top();
    }
};