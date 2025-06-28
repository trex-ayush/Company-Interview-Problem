class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(N, 0);
        
        for(auto& prerequisite : prerequisites){
            int u = prerequisite.second;
            int v = prerequisite.first;
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        // topological sort
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count += 1;
            
            for(auto& v : adj[node]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        return count == N;
    }
};