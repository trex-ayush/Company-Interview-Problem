// Company tags: Anduril, Agoda, ByteDance, Citade, Coupang, Docusign, eBay, Flipkart, Karat, Nvidia, Nutanix, Oracle, Snap, Snowflake, Visa, VMware, Walmart Labs, Yelp, Zenefits.
class Solution {
public:
    // Time Complexity  : O(N + P) N = Number of courses, P = Number of prerequisites
    // Space Complexity : O(N + P)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto& prerequisite : prerequisites){
            int u = prerequisite[0];
            int v = prerequisite[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;

            for(auto& v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        return count == numCourses;
    }
};