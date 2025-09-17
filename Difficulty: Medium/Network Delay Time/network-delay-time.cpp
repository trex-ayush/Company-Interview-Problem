class Solution {
  public:
    typedef pair<int, int> P;
    int findDelayTime(int n, vector<vector<int>> &times, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto& time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> time(n, INT_MAX);
        pq.push({0, k});
        time[k] = 0;
        
        while(!pq.empty()){
            int t = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for(auto& v : adj[u]){
                int nextNode = v.first;
                int ti = v.second;
                
                if(time[nextNode] > t + ti){
                    time[nextNode] = t + ti;
                    pq.push({t + ti, nextNode});
                }
            }
        }
        
        int maxTime = 0;
        for(int i = 0; i < n; i++){
            if(time[i] == INT_MAX) return -1;
            maxTime = max(maxTime, time[i]);
        }
        return maxTime;
    }
};