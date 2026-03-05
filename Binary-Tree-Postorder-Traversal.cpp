1class Solution {
2public:
3    // T.C: O(n)
4    // S.C: O(n)
5    vector<int> postorderTraversal(TreeNode* root) {
6        vector<int> res;
7        if(root == nullptr) return res;
8
9        stack<TreeNode*> st;
10        st.push(root);
11
12        while(!st.empty()){
13            TreeNode* temp = st.top();
14            st.pop();
15            res.push_back(temp->val);
16            if(temp->left) st.push(temp->left);
17            if(temp->right) st.push(temp->right);
18        }
19        reverse(res.begin(), res.end());
20        return res;        
21    }
22};