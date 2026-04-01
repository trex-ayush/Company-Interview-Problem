class Solution {
  public:
    int dp[45];
    int fib(int n) {
        if (n == 1) return 2;
        if (n == 2) return 3;
        
        if (dp[n] != -1) return dp[n];
        
        return dp[n] = fib(n - 1) + fib(n - 2);
    }

    int countStrings(int n) {
        memset(dp, -1, sizeof(dp));
        return fib(n);
    }
};