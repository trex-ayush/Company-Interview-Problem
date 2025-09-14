class Solution {
  public:
    int t[101][101];
    const int mod = 1e9+7;
    int solve(vector<vector<int>>& mat, int i, int j){
        if(i >= mat.size() || j >= mat[0].size() || mat[i][j] == 1) return 0;
        if(i == mat.size() - 1 && j == mat[0].size() - 1) return 1;
        
        if(t[i][j] != -1) return t[i][j];
        
        int ans = 0;
        
        ans = (ans + solve(mat, i + 1, j)) % mod;
        ans = (ans + solve(mat, i, j + 1)) % mod;
        
        return t[i][j] = ans % mod;
    }
    int totalWays(int n, int m, vector<vector<int>>& mat) {
        memset(t,-1,sizeof(t));
        return solve(mat, 0, 0);
    }
};