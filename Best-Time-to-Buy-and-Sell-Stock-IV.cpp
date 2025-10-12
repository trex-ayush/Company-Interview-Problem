// Company tags: PhonePe, Citadel, Snap, TikTok, Arcesium ,Nvidia, Citadel, Goldman Sachs, Google
class Solution {
public:
    // T.C: O(n*k)
    // S.C: O(n*k)
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2*k+1, vector<int>(2, 0)));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int maxAllowed = 1; maxAllowed < 2*k+1; maxAllowed++) {
                for (int canBuy = 0; canBuy <= 1; canBuy++) {
                    int profit = 0;
                    if (canBuy) {
                        int buy = -prices[idx] + dp[idx + 1][maxAllowed - 1][0];
                        int skip = dp[idx + 1][maxAllowed][1];
                        profit = max(buy, skip);
                    } else {
                        int sell = prices[idx] + dp[idx + 1][maxAllowed - 1][1];
                        int skip = dp[idx + 1][maxAllowed][0];
                        profit = max(sell, skip);
                    }
                    dp[idx][maxAllowed][canBuy] = profit;
                }
            }
        }
        return dp[0][2*k][1];
    }
};