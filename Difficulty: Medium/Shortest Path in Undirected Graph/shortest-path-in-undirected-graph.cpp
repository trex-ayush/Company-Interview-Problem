class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> res(n, -1);
        vector<bool> visited(n , false);
        
        queue<int> q;
        q.push(src);
        visited[src] = true;
        res[src] = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto& v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    res[v] = res[u] + 1; 
                    q.push(v);
                }   
            }
        }
        
        return res;
    }
};