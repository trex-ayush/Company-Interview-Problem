class Solution {
public:
    int result = -1;
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<int>& count, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                count[v] = count[u] + 1;
                dfs(v, adj, visited, count, inRecursion);
            }else if (inRecursion[v]) { // cycle found
                result = max(result, count[u] - count[v] + 1);
            }
        }
        
        inRecursion[u] = false;
    }

    int longestCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<int> count(V, 1);
        vector<bool> inRecursion(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, count, inRecursion);
            }
        }
        
        return result;
    }
};