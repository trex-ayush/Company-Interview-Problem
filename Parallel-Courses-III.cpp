class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        vector<int> maxTime(n, 0);

        for(auto& relation : relations){
            int u = relation[0] - 1;  // 0 based indexing
            int v = relation[1] - 1;

            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0) {
                q.push(i);
                maxTime[i] = time[i];
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& v : adj[node]){
                maxTime[v] = max(maxTime[v], maxTime[node] + time[v]);
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return *max_element(maxTime.begin(), maxTime.end());
    }
};