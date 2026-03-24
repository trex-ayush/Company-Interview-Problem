class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        queue<int> q;
        
        for(auto& prerequisite : prerequisites) {
            int x = prerequisite[0];
            int y = prerequisite[1];
            
            adj[y].push_back(x);
            indegree[x]++;
        }
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto& v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        for(auto& val : indegree) {
            if(val != 0) return false;
        }
        
        return true;
    }
};