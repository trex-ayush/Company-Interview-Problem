class Solution {
  public:
    vector<vector<int>> dirs = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, -1}, {-2, 1}};
    bool valid(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    bool solve(vector<vector<int>>& grid, int i, int j, int count) {
        int n = grid.size();
        if (count == n * n - 1) return true;
        
        for (auto& dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            if (valid(x, y, grid) && grid[x][y] == -1) {
                grid[x][y] = count + 1;
                if (solve(grid, x, y, count + 1)) return true;
                grid[x][y] = -1;
            }
        }
        
        return false;
    }
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        
        res[0][0] = 0;
        
        if (solve(res, 0, 0, 0)) return res;
        else return vector<vector<int>>{{-1}};
    }
};