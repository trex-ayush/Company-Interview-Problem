// Company tags: Citadel, DE Shaw, Deutsche Bank, eBay, Geico, Goldman Sachs, Infosys, Instacart, Intel, J.P. Morgan, Media.net, Morgan Stanley, Paytm, PhonePe, Qualcomm, Salesforce, TCS, TikTok, Walmart Labs, Wells Fargo, Yahoo, Yandex, Zoho
class Solution {
public:
    // T.C: O(2*n) = O(n)
    // S.C: O(2*n) = O(n)
    int solve(vector<int>& arr, int idx, bool canBuy, vector<vector<int>>& t) {
        if (idx >= arr.size()) return 0;
        if (t[idx][canBuy] != -1) return t[idx][canBuy];
        
        int profit = 0;
        if (canBuy) {
            int buy = -arr[idx] + solve(arr, idx + 1, false, t);
            int skip = solve(arr, idx + 1, true, t);
            profit = max(buy, skip);
        } else {
            int sell = arr[idx] + solve(arr, idx + 1, true, t);
            int skip = solve(arr, idx + 1, false, t);
            profit = max(sell, skip);
        }
        
        return t[idx][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> t(n, vector<int>(2, -1));
        return solve(prices, 0, true, t);
    }
};