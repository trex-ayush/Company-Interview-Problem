class Solution {
  public:
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();
        if (i < 0 || i >= n || j >= m) return 0;
        
        // if already computed, reuse it
        if (dp[i][j] != -1) return dp[i][j];
        
        // move to right-up cell
        int rightUp = solve(i - 1, j + 1, mat, dp);
        // move to right cell
        int right = solve(i, j + 1, mat, dp);
        // move to right-down cell
        int rightDown = solve(i + 1, j + 1, mat, dp);
        
        // cache and return the best of three moves plus current gold
        return dp[i][j] = mat[i][j] + max({ rightUp, right, rightDown });
    }

    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int result = 0;
        // initialize dp table to -1 (uncomputed)
        vector<vector<int>> dp(501, vector<int>(501, -1));
        // try starting from each row in first column
        for (int i = 0; i < n; i++) {
            result = max(result, solve(i, 0, mat, dp));
        }
        return result;
    }
};