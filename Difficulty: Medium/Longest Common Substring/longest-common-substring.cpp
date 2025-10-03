class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        int maxi = 0;
        for(int i = 1;i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++){
                if(s1[i - 1] == s2[j - 1]){
                    t[i][j] = 1 + t[i-1][j-1];
                    maxi = max(maxi, t[i][j]);
                }else t[i][j] = 0;
            }
        }
        
        return maxi;
    }
};