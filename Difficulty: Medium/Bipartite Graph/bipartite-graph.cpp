class Solution {
  public:
    bool dfs(unordered_map<int, vector<int>>& adj, int i, vector<int>& color){
        
        for(auto& neigh : adj[i]){
            if(color[neigh] == -1){
                color[neigh] = 1 - color[i];
                if(!dfs(adj, neigh, color)) return false;
            }else if(color[neigh] == color[i]) return false;
        }
        return true;
    }
    bool isBipartite(int v, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(v, -1);
        
        for(int i = 0; i < v; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(adj, i, color)) return false;
            }
        }
        return true;
    }
};