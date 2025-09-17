// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int v, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        
        vector<int> res(v, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});  // {distance, node}
        res[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            
            pq.pop();
            
            for(auto& neigh : adj[node]){
                int nextDist = neigh.second;
                int nextNode = neigh.first;
                
                if(res[nextNode] > dist + nextDist){
                    res[nextNode] = dist + nextDist;
                    pq.push({dist + nextDist, nextNode});
                }
            }
        }
        return res;
    }
};