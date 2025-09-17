class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;  // {u, {v, wt}}
        
        for(auto& flight : flights){
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];
            
            adj[u].push_back({v, wt});
        }
        
        queue<pair<int,int>> q;  // {node , cost};
        q.push({src,0});
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        int step = 0;
        
        while(!q.empty() && step <= k){
            int n = q.size();
            while(n--){
                auto temp = q.front();
                q.pop();
                int u = temp.first;
                int d = temp.second;
                
                for(auto& neigh : adj[u]){
                    int v         = neigh.first;
                    int neighCost = neigh.second;
                    if(distance[v] > neighCost + d){
                        distance[v] = neighCost + d;
                        q.push({v , neighCost + d});
                    }
                }
            }
            step++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};