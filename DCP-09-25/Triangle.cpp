// Company tags: Agoda, DE Shaw, Salesforce
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int col = 0; col < triangle[n - 1].size(); col++) {
            dp[n - 1][col] = triangle[n - 1][col];
        }
        
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < triangle[row].size(); col++) {
                dp[row][col] = triangle[row][col] + min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }
        
        return dp[0][0];
    }
};