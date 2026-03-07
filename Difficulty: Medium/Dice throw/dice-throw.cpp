class Solution {
public:
    int solve(int m, int n, int x, int sum, vector<vector<int>>& dp) {
        if (n == 0) {
            if (sum == x) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        int ways = 0;
        for (int i = 1; i <= m; i++) {
            if (sum + i <= x) {
                ways += solve(m, n - 1, x, sum + i, dp);
            }
        }
        return dp[n][sum] = ways;
    }
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
        return solve(m, n, x, 0, dp);
    }
};