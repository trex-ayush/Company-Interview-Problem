1// Company tags: Two Sigma, Sprinklr, DoorDash
2class Solution {
3public:
4    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
5        visited[u] = true;
6
7        for(auto& v : adj[u]){
8            if(!visited[v]){
9                dfs(adj, v, visited);
10            }
11        }
12    }
13    int findCircleNum(vector<vector<int>>& isConnected) {
14        int n = isConnected.size();
15        unordered_map<int, vector<int>> adj;
16
17        for(int i = 0; i < n; i++){
18            for(int j = 0; j < n; j++){
19                if(isConnected[i][j] == 1){
20                    adj[i].push_back(j);
21                    adj[j].push_back(i);
22                }
23            }
24        }
25
26        int count = 0;
27        vector<bool> visited(n, false);
28
29        for(int i = 0; i < n; i++){
30            if(!visited[i]){
31                dfs(adj, i, visited);
32                count++;
33            }
34        }
35
36        return count;
37    }
38};