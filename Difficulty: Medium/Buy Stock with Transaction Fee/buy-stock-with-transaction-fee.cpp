class Solution {
  public:
    int solve(int i, vector<int> &arr, int &k, bool buy, vector<vector<int>> &dp){
        int n = arr.size();
        if(i == n) return 0;
        
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int res = 0;
        
        if(buy){
            res = max(res, -arr[i]-k+solve(i+1, arr, k, false, dp));
            res = max(res, solve(i+1, arr, k, true, dp));
        }
        else{
            res = max(res, arr[i]+solve(i+1, arr, k, true, dp));
            res = max(res, solve(i+1, arr, k, false, dp));
        }
        return dp[i][buy] = res;
    }
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, arr, k, true, dp);
        
    }
};