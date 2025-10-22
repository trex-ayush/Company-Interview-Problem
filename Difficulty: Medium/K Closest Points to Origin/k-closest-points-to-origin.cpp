class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;
        
        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dist = (x * x) + (y * y);
            pq.push({dist, point});
            if (pq.size() > k) pq.pop();
        }
        
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
