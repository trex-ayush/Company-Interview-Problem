class Solution {
  public:
    // prism algo
    typedef pair<int, int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj;
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> isMST(V, false);
        
        pq.push({0, 0});  // {weight, node}
        
        int sum = 0;
        
        while(!pq.empty()){
            int w = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(isMST[u] == true) continue;
            isMST[u] = true;
            sum += w;
            
            for(auto& v : adj[u]){
                int neigh = v.first;
                int wt = v.second;
                
                if(!isMST[neigh]){
                    pq.push({wt, neigh});
                }
            }
        }
        return sum;
    }
};