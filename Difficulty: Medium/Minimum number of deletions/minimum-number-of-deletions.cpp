class Solution {
  public:
    int t[1001][1001];
    int solve(string& s, int i, int j){
        if(i == j) return 1;
        if(i > j) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        int mini = 0;
        
        if(s[i] == s[j]) {
            mini = 2 + solve(s, i + 1, j - 1);
        }else{
            mini = max(solve(s, i + 1, j), solve(s, i, j - 1));
        }
        return t[i][j] = mini;
    }
    int minDeletions(string &s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        int cnt = solve(s, 0, n-1);
        return n - cnt;
    }
};