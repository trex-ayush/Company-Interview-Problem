class Solution {
public:
    /*----Approach 2: Bottom Up----*/
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> t(n, vector<int>(n, 0));

        for(int L = 2; L <= n; L++){
            for(int i = 0; i + L - 1 < n; i++){
                int j = i + L - 1;
                if(s[i] == s[j]){
                    // 0 insertion
                    t[i][j] = t[i+1][j-1];
                }else {
                    t[i][j] =  min(1+ t[i+1][j], 1+t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }

    /*----Approach 1: Recursion + Memoization----*/
    // int t[501][501];
    // int solve(string& s, int i, int j){
    //     if(i >= j) return 0;

    //     if(t[i][j] != -1) return t[i][j];
    //     if(s[i] == s[j]){
    //         return t[i][j] = solve(s, i+1, j-1);
    //     }
    //     return t[i][j] = min(1+ solve(s, i+1, j), 1+solve(s, i, j-1));
    // }
    // int minInsertions(string s) {
    //     memset(t,-1,sizeof(t));
    //     return solve(s, 0, s.length()-1);
    // }
};