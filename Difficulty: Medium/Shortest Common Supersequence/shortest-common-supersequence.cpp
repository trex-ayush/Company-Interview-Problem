class Solution {
  public:
    int getLCS(string& text1, string& text2){
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(text1[i-1] == text2[j-1]) t[i][j] = 1 + t[i-1][j-1];
                else t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return t[n][m];
    }
    int shortestCommonSupersequence(string &s, string &s2) {
        int lcs = getLCS(s, s2);
        
        return s.size() + s2.size() - lcs;
    }
    
    /* Bottom Up */
    int solve(string &s, string &t){
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < m+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = i + j;
                }else if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int shortestCommonSupersequence(string &s, string &s2) {
        return solve(s,s2);
    }
    
    
    /* Recursion + Memo */
    int t[501][501];
    int solve(string& s, string&s2, int n, int m){
        if(n == 0 || m == 0) return n + m;
        
        if(t[n][m] != -1) return t[n][m];
        
        if(s[n-1] == s2[m-1]) return t[n][m] = 1 + solve(s,s2,n-1,m-1);
        else return t[n][m] = 1 + min(solve(s,s2,n,m-1), solve(s,s2,n-1,m));
    }
    int shortestCommonSupersequence(string &s, string &s2) {
        memset(t,-1,sizeof(t));
        return solve(s,s2,s.length(), s2.length());
    }
};
