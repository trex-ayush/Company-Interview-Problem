class Solution {
  public:
    int countPS(string &s) {
        int n = s.length();
        vector<vector<int>> t(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) t[i][i] = 1;
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j]){
                    t[i][j] = t[i + 1][j] + t[i][j - 1] + 1;
                }else{
                    t[i][j] = t[i + 1][j] + t[i][j - 1] - t[i + 1][j - 1];
                }
            }
        }
        
        return t[0][n - 1];
    }
};