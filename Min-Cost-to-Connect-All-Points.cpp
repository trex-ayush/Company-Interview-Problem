// Company tags: DE Shaw, Nutanix
class Solution {
public:
    // prim's algo
    typedef pair<int, int> P;
    int prismAlgo(int V, unordered_map<int, vector<P>>& adj) {
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        unordered_map<int, vector<P>> adj;

        for(int i = 0; i < V; i++){
            for(int j = i + 1; j < V; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        return prismAlgo(V, adj);
    }
};