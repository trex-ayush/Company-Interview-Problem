/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int, vector<int>> mpp;
        queue<pair<int,Node*>> q;
        q.push({0, root});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int i = temp.first;
            Node* node = temp.second;
            
            mpp[i].push_back(node->data);
            
            if(node->left) q.push({i-1, node->left});
            if(node->right) q.push({i+1, node->right});
        }
        
        vector<vector<int>> res;
        for(auto& mp : mpp) res.push_back(mp.second);
        return res;
    }
};