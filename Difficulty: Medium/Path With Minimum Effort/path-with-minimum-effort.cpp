
class Solution {
  public:
    typedef pair<int, pair<int, int>> P; //{u {v, wt}}
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        int n = rows;
        int m = columns;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        
        pq.push({0, {0, 0}});
        ans[0][0] = 0;
        
        while (!pq.empty()) {
            int diff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            for (auto& dir : dirs) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m) {
                    int absDiff = abs(heights[i_][j_] - heights[i][j]);
                    int maxDiff = max(absDiff, diff);
                    
                    if (ans[i_][j_] > maxDiff) {
                        ans[i_][j_] = maxDiff;
                        pq.push({maxDiff, {i_, j_}});
                    }
                }
            }
        }
        
        return ans[n - 1][m - 1];
        
    }
};
