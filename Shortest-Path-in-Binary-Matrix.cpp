class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;

        int minPath = 0;
        queue<pair<int, int>> q;

        q.push({0, 0});
        grid[0][0] = 1;

        while(!q.empty()){
            int k = q.size();
            while(k--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i == n - 1 && j == m - 1) return minPath + 1;

                for(auto& dir : dirs){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && grid[i_][j_] == 0){
                        q.push({i_, j_});
                        grid[i_][j_] = 1;
                    }
                }
            }
            minPath++;
        }

        return -1;
    }
};
