class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.emplace(root,0);
        
        while(!q.empty()){
            Node* currNode = q.front().first;
            int currDistan = q.front().second;
            q.pop();
            
            if(mpp.find(currDistan) == mpp.end()) mpp[currDistan] = currNode->data;
            
            if(currNode->left){
                q.emplace(currNode->left, currDistan - 1);
            }
            if(currNode->right){
                q.emplace(currNode->right, currDistan + 1);
            }
        }
        
        for(auto& mp : mpp) ans.push_back(mp.second);
        
        return ans;
    }
};


