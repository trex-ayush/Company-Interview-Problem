1// Company tags: BlackRock
2class Solution {
3public:
4    // T.C: O(E log V)
5    // S.C: O(V + E)
6    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int st, int en) {
7        unordered_map<int, vector<pair<int, double>>> adj;  // u -> {v, wt}
8
9        for(int i = 0; i < edges.size(); i++){
10            int u = edges[i][0];
11            int v = edges[i][1];
12            double w = succProb[i];
13
14            adj[u].push_back({v, w});
15            adj[v].push_back({u, w});
16        }
17
18        vector<double> res(n, 0.0);
19        res[st] = 1.0;
20
21        priority_queue<pair<double, int>> pq;
22        pq.push({1.0, st});
23
24        while(!pq.empty()){
25            auto top = pq.top();
26            pq.pop();
27
28            double w = top.first;
29            int u    = top.second;
30
31            if(w < res[u]) continue;
32
33            for(auto& v : adj[u]){
34                int neigh = v.first;
35                double wt = v.second;
36                if(w * wt > res[neigh]){
37                    res[neigh] = w * wt;
38                    pq.push({w * wt, neigh});
39                }
40            }
41        }
42        return res[en];
43    }
44};