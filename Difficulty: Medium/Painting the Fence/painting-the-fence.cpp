class Solution {
  public:
    int mod = 1e9 + 7; 
    int dp[301][3];
    int solve(int n, int k, int i, int prevSame) {
        if (i >= n) return 1;
        
        if (dp[i][prevSame] != -1) return dp[i][prevSame];
        
        long long ways = 0;
        if (prevSame < 2) {
            ways += solve(n, k, i + 1, prevSame + 1);
        }
        ways += (long long)(k - 1) * solve(n, k, i + 1, 1);
        
        return dp[i][prevSame] = ways;
    }
    int countWays(int n, int k) {
        memset(dp , - 1, sizeof(dp));    
        return solve(n, k, 0, 0);
    }
};