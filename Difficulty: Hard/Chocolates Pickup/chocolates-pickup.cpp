class Solution {
public:
    int recMax(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Boundary conditions
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e9;
        
        // Base case: last row
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = -1e9;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value = recMax(grid, i + 1, j1 + dj1, j2 + dj2, dp);
                maxi = max(maxi, value);
            }
        }
        
        int result;
        if (j1 == j2) {
            result = grid[i][j1] + maxi;
        } else {
            result = grid[i][j1] + grid[i][j2] + maxi;
        }
        
        return dp[i][j1][j2] = result;
    }

    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return recMax(grid, 0, 0, m - 1, dp);
    }
};
