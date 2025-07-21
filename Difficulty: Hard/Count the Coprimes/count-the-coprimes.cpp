class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        int n = arr.size(), m = 0;
        for(int i = 0; i < n; i++) m = max(m, arr[i]);
        vector<int> freq(m + 1, 0), dp(m + 1, 0);
        for(int i = 0; i < n; i++) freq[arr[i]]++;
        for(int i = m; i >= 1; i--) {
            int c = 0;
            for(int j = i; j <= m; j += i) {
                dp[i] -= dp[j];
                c += freq[j];
            }
            dp[i] += (c * (c - 1)) / 2;
        }
        return dp[1];
    }
};
