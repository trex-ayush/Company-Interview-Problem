class Solution {
  public:
    // Time Complexity  : O(n × m)
    // Space Complexity : O(n × m)
    int getLCS(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        if(i == word1.size() || j == word2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(word1[i] == word2[j]) return dp[i][j] = 1 + getLCS(word1, word2, i + 1, j + 1, dp);
        else return dp[i][j] = max(getLCS(word1, word2, i + 1, j, dp), getLCS(word1, word2, i, j + 1, dp));
    }
    int minOperations(string &word1, string &word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int lcs = getLCS(word1, word2, 0, 0, dp);
        int deletion = n - lcs;
        int insertion = m - lcs;
        return insertion + deletion;
    }
};