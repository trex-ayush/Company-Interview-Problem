class Solution {
public: 
    /* Approach 2: Bottom Up */
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        int result = 0;
        
        for(int L = 1; L <= n; L++){ // O(n)
            for(int i = 0; i + L - 1 < n; i++){ // O(n)
                int j = i + L - 1;
                if(i == j){ // 1 length  -> a,b,c
                    t[i][j] = true;
                }else if(i+1 == j){  // 2 length -> aa,bb, cc
                    if(s[i] == s[j]){
                        t[i][j] = true;
                    }else t[i][j] = false;
                }else{
                    if(s[i] == s[j] && t[i+1][j-1]){
                        t[i][j] = true;
                    }else t[i][j] = false;
                }

                if(t[i][j] == true) result++;
            }
        }
        return result;
    }

    /* Approach 1: Recursion + Memo */
    // int t[1001][1001];
    // bool isPalindrome(string& s, int i, int j){
    //     if(i >= j) return true;
    //     if(t[i][j] != -1) return t[i][j];
    //     if(s[i] == s[j]){
    //         return t[i][j] = isPalindrome(s, i+1, j-1);
    //     }
    //     return t[i][j] = false;
    // }
    // int countSubstrings(string s) {
    //     int n = s.length();
    //     int result = 0;
    //     memset(t,-1,sizeof(t));

    //     for(int i = 0; i < n; i++){
    //         for(int j = i; j < n; j++){
    //             if(isPalindrome(s, i, j)){
    //                 result += 1;
    //             }
    //         }
    //     }
    //     return result;
    // }
};