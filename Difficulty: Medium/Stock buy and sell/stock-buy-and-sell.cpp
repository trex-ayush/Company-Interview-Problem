class Solution {
  public:
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

    int stockBuySell(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> t(n, vector<int>(2, -1));
        return solve(arr, 0, true, t);
    }
};
