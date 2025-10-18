/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> getKClosest(Node* root, int target, int k) {
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second; 
            return a.first < b.first;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            int diff = abs(temp->data - target);
            pq.push({diff, temp->data});
            
            if (pq.size() > k) pq.pop();
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
