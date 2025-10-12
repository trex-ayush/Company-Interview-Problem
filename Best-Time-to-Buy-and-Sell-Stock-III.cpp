// Company tags: PhonePe, Citadel, Snap, TikTok
class Solution {
public:
    // T.C: O(n*5*2) = O(n)
    // S.C: O(n*5*2) = O(n)
    int solve(vector<int>& prices, int idx, bool canBuy, int maxAllowed, vector<vector<vector<int>>>& t){
        if(maxAllowed == 0 || idx >= prices.size()) return 0;

        if(t[idx][maxAllowed][canBuy] != -1) return t[idx][maxAllowed][canBuy];

        int maxProfit = 0;
        if(canBuy){
            int buyKaro   = -prices[idx] + solve(prices, idx + 1, false, maxAllowed - 1, t);
            int buyMtKaro = solve(prices, idx + 1, true, maxAllowed, t);
            maxProfit = max(buyKaro, buyMtKaro);
        }else{
            int sellKaro   = prices[idx] + solve(prices, idx + 1, true, maxAllowed - 1, t);
            int sellMtKaro = solve(prices, idx + 1, false, maxAllowed, t);
            maxProfit = max(sellKaro, sellMtKaro);
        }
        return t[idx][maxAllowed][canBuy] = maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> t(n + 1, vector<vector<int>>(5, vector<int>(2, -1)));
        return solve(prices, 0, true, 4, t);
    }
};