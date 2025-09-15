// Company tags: Visa
class Solution {
public:
    // T.C : O(n*n)
    // S.C : O(n*n)
    int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp){
        int n = mat.size();
        if(j < 0 || j >= n) return INT_MAX;
        if(i == n - 1) return mat[i][j];

        if(dp[i][j] != INT_MIN) return dp[i][j];

        int down = solve(mat, i + 1, j, dp);
        int leftDiag = solve(mat, i + 1, j - 1, dp);
        int rightDiag = solve(mat, i + 1, j + 1, dp);

        return dp[i][j] = mat[i][j] + min({down, leftDiag, rightDiag});
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        int mini = INT_MAX;

        for(int j = 0; j < n; j++){
            mini = min(mini, solve(mat, 0, j, dp));
        }

        return mini;
    }
};
