class Solution {
public:
    int mod = 1000000007;
    int distinctSubseq(string &str) {
        int n = str.size();
        // dp[i] = number of distinct subsequences of str[0..i-1]
        vector<long long> dp(n + 1, 0);
        
        // last[ch] = last index where character ch occurred
        vector<int> last(26, -1);
        
        dp[0] = 1;  // empty subsequence
        
        for (int i = 1; i <= n; i++) {
            // We always have the option to include or exclude str[i-1]
            dp[i] = (2 * dp[i - 1]) % mod;
            int ch = str[i - 1] - 'a';
            
            /*
                If this character appeared earlier at idx = last[ch],
                then dp[i] included all subsequences before idx TWICE:
                
                1) Once by dp[i-1] (when skipping this char)
                2) Once by appending current char to each of dp[idx] subsequences
                   → duplicates!
                   
                So we subtract dp[last[ch]] to remove overcounted subsequences.
            */
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch]] + mod) % mod;
            }
            
            // Mark last occurrence of this character
            last[ch] = i - 1;
        }
        
        return dp[n];
    }
};