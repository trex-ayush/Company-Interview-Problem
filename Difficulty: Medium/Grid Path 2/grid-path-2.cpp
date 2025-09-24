class Solution {
  public:
    const int mod = 1e9+7;
    int totalWays(int n, int m, vector<vector<int>>& mat) {
        if (mat[0][0] == 1 || mat[n-1][m-1] == 1) return 0;
        
        vector<vector<int>> t(n, vector<int>(m, 0));
        t[0][0] = 1;
        for(int j = 1; j < m; j++) {
            if (mat[0][j] == 0) t[0][j] = t[0][j - 1];
            else t[0][j] = 0;
        }
        
        for(int i = 1; i < n; i++) {
            if (mat[i][0] == 0) t[i][0] = t[i - 1][0];
            else t[i][0] = 0;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][j] != 1) t[i][j] = (t[i][j-1] + t[i-1][j]) % mod;
            }
        }

        return t[n-1][m-1];
    }
};