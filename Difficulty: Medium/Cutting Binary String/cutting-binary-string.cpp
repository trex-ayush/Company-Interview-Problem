class Solution {
public:
    int solve(int i, string s, unordered_set<int>& powers, vector<int>& dp) {
        // base case
        if (i == s.size()) return 0;
        // recursive case
        if (dp[i] != -1) return dp[i];
        int res = s.size() + 1, num = 0;
        for (int j = i; j < s.size(); j++) {
            num = num * 2 + (s[j] - '0');
            if (s[i] != '0' && powers.count(num)){
                res = min(res, 1 + solve(j + 1, s, powers, dp));
            }
        }
        return dp[i] = res;
    }
    int cuts(string s) {
        if (s[0] == '0') return -1;
        vector<int> dp(s.size(), -1);
        unordered_set<int> powers;
        
        for (int i = 1; i <= 1e9; i *= 5) powers.insert(i);
        
        int ans = solve(0, s, powers, dp);
        return ans > s.size() ? -1 : ans;
    }
};