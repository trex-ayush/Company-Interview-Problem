class Solution {
  public:
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