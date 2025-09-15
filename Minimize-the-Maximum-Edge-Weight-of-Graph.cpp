class Solution {
public:
    typedef pair<int,int> P;
    void dfs(unordered_map<int, vector<P>>& adj, int mid, vector<bool>& visited, int u){
        visited[u] = true;

        for(auto& neigh : adj[u]){
            int v = neigh.first;
            int w = neigh.second;

            if(w <= mid && !visited[v]){
                visited[v] = true;
                dfs(adj, mid, visited, v);
            }
        } 
    }
    bool canReachToEveryNodeZero(unordered_map<int, vector<P>>& adj, int mid, int n){
        // DFS
        vector<bool> visited(n, false);
        dfs(adj, mid, visited, 0);

        for(int i = 0; i < n; i++){
            if(visited[i] == false) return false;
        }
        return true;

        // // BFS
        // queue<int> q;
        // vector<bool> visited(n, false);
        // visited[0] = true;
        // q.push(0);

        // while(!q.empty()){
        //     int u = q.front();
        //     q.pop();

        //     for(auto& neigh : adj[u]){
        //         int v = neigh.first;
        //         int w = neigh.second;

        //         if(w <= mid && !visited[v]){
        //             visited[v] = true;
        //             q.push(v);
        //         }
        //     }
        // }

        // for(int i = 0; i < n; i++){
        //     if(visited[i] == false) return false;
        // }
        // return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;

        int maxWeight = 0;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            maxWeight = max(maxWeight, w);
            adj[v].push_back({u, w});    // reverse direction
        }

        int result = INT_MAX;
        int st = 0;
        int en = maxWeight;

        while(st <= en){
            int mid = st + (en - st)/2;

            if(canReachToEveryNodeZero(adj, mid, n)){
                result = mid;
                en = mid - 1;
            }else st = mid + 1;
        }

        return result == INT_MAX ? -1 : result;
    }
};