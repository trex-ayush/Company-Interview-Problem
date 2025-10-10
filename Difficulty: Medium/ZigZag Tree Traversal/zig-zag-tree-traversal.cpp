
// User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int>& ans){
        queue<Node*> q;
        q.push(root);
        bool left = false;
        
        while(!q.empty()){
            vector<int>temp;
            int n = q.size();
            while(n--){
                Node* curr = q.front();
                q.pop();
                temp.push_back(curr->data);
                if(curr->left) q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            if(left) reverse(temp.begin(),temp.end());
            for(auto& t : temp) ans.push_back(t);
            left = !left;
        }
    }
    
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        
        solve(root, ans);
        return ans;
    }
};

