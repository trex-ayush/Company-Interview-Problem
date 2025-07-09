// User function Template for C++

class Solution {
  public:
    int dp[1001][1001];
    int solve(string& s, int i, int j, vector<vector<bool>>& t){
        if(t[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int result = INT_MAX;
        
        for(int k = i; k <= j-1; k++){
            // a|a|b
            // 0|1|2  
            if(t[i][k]){
                int temp = 1 + solve(s, i, k, t) + solve(s, k+1, j, t); 
                result = min(result, temp);    
            } 
        }
        return  dp[i][j] = result;
    }
    int palPartition(string &s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        memset(dp, -1, sizeof(dp));

        for(int L = 1; L <= n; L++){
            for(int i = 0; i + L - 1 < n; i++){
                int j = i + L - 1;
                if(L == 1){
                    // 1 length -> a,c,b,d
                    t[i][j] = true;
                }else if(L == 2){
                    if(s[i] == s[j]){
                        // 2 length -> aa,bb
                        t[i][j] = true;
                    }else{
                        t[i][j] = false;
                    }
                }else {
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }
            }
        }

        return solve(s, 0, n-1, t);
    }
};