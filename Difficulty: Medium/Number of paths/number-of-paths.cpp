class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& t){
        if(n < 0 || m < 0)  return 0;
        if(n == 0 && m == 0) return 1;
        
        if(t[n][m] != -1) return t[n][m];
        
        int up = solve(n - 1, m, t);
        int left = solve(n, m - 1, t);
        
        return t[n][m] = up + left;
    }
    int numberOfPaths(int n, int m) {
        vector<vector<int>> t(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, t);
    }
};
