class Solution {
  public:
    int solveMem(int W, vector<int>& wt, vector<int>& val , int n ,vector<vector<int>>& dp){
        if(n==0||W==0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(wt[n-1] <= W){
            return dp[n][W] = max( val[n-1] + solveMem(W-wt[n-1],wt,val,n-1,dp) , solveMem(W,wt,val,n-1,dp) );
        }else{
            return dp[n][W] = solveMem(W,wt,val,n-1,dp);
        }
    }
    
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (wt[i - 1] <= j) {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j]; 
                }
            }
        }
        return dp[n][W];
    }
};
