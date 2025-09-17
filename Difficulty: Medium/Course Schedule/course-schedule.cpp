class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        vector<int> result;
        
        for(auto& prerequisite : prerequisites){
            int u = prerequisite[0];
            int v = prerequisite[1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            
            for(auto& v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return result;
    }
};