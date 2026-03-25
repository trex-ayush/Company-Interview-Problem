class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if (V == 1) return {0};
        
        vector<int> result;
        vector<int> degree(V, 0);
        vector<vector<int>> adj(V);
        
        for (auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> que;
        
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1)
                que.push(i);
        }
        
        int remainingNodes = V;
        
        while (remainingNodes > 2) {
            int size = que.size();
            remainingNodes -= size;
            
            while (size--) {
                int u = que.front();
                que.pop();
                
                for (int v : adj[u]) {
                    degree[v]--;
                    if (degree[v] == 1)
                        que.push(v);
                }
            }
        }
        
        while (!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }
        
        return result;
    }
};