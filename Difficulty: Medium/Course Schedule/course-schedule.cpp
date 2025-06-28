class Solution {
  public:
    // T.C: O(n + m)
    // S.C: O(n + m)
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0); 
        vector<int> result;
        
        // Building the graph — O(p)
        for(auto& prerequisite : prerequisites){
            int u = prerequisite[1];
            int v = prerequisite[0];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        // Queue initialization — O(n)
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        // Topological Sort — O(n + p)
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            // For each neighbor of node — total of O(p) over the algorithm
            for(auto& v : adj[node]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        return result;
    }
};
