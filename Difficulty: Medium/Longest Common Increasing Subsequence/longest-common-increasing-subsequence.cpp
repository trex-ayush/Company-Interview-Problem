class Solution {
public:
    int LCIS(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        int res = 0;
        vector<int> dp(m, 0);
        
        for (int i = 0; i < n; i++) {
            int ans = 0;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], 1 + ans);
                    res = max(res, dp[j]);
                }
                if (a[i] > b[j]) {
                    ans = max(ans, dp[j]);
                }
            }
        }
        return res;
    }
};