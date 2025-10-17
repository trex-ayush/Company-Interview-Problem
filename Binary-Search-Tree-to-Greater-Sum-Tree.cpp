// Company tags: Amazon, eBay
class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(n)
    void inorder(TreeNode* root, vector<int>& d){
        if(!root) return;
        
        inorder(root->left, d);
        d.push_back(root->val);
        inorder(root->right, d);
    }
    TreeNode* bstToGst(TreeNode *root) {
        if(!root) return root;
        
        vector<int> d;
        inorder(root, d);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* u = q.front();
            int temp = u->val;
            q.pop();
            
            int res = 0;
            for(int i = d.size() - 1; i >= 0; i--){
                if(d[i] >= temp) res += d[i];
                else break;
            }
            
            u->val = res;
            if(u->left) q.push(u->left);
            if(u->right) q.push(u->right);
        }
        return root;
    }
};