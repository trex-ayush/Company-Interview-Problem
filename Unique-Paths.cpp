// Comapny tags: Adobe, Amazon, Apple, Bloomberg, ByteDance, Citadel, Coupang, Cruise, DE Shaw, Goldman Sachs, Intuit, J.P. Morgan, Meta, Microsoft, Oracle, Roblox, TCS, TikTok, Uber, Yahoo, Zomato
class Solution {
public:
    // Time Complexity: O(n * m)
    // Space Complexity: O(n * m)
    int uniquePaths(int n, int m) {
        vector<vector<int>> t(n, vector<int>(m, 1));
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                t[i][j] = t[i][j-1] + t[i-1][j];
            }
        }
        
        return t[n-1][m-1];
    }
};