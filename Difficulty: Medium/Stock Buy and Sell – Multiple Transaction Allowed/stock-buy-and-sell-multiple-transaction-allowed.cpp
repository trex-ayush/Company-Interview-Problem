
class Solution {
  public:
    int maximumProfit(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                if (canBuy) {
                    int buy = -arr[idx] + dp[idx + 1][0];
                    int skip = dp[idx + 1][1];
                    dp[idx][canBuy] = max(buy, skip);
                } else {
                    int sell = arr[idx] + dp[idx + 1][1];
                    int skip = dp[idx + 1][0];
                    dp[idx][canBuy] = max(sell, skip);
                }
            }
        }
        
        return dp[0][1];
    }
};
