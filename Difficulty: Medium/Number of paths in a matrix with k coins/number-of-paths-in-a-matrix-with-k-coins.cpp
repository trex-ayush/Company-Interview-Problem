class Solution {
public:
    int dp[100][100][101];
    int recur(vector<vector<int>>& mat, int r, int c, int req) {
        if (r == 0 && c == 0) return mat[0][0] == req;
        if (dp[r][c][req] != -1) return dp[r][c][req];
        
        int ways = 0;
        
        if (r > 0 && req >= mat[r][c]) ways += recur(mat, r - 1, c, req - mat[r][c]);
        if (c > 0 && req >= mat[r][c]) ways += recur(mat, r, c - 1, req - mat[r][c]);
        
        return dp[r][c][req] = ways;
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        memset(dp, -1, sizeof dp);
        int n = mat.size(), m = mat[0].size();
        return recur(mat, n - 1, m - 1, k);
    }
};