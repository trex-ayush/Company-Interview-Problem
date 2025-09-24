// Company tags: Adobe, Agoda, Amazon, Apple, Atlassian, Bloomberg, Cisco, Coupang, Cruise, Meta, Microsoft, Pinterest, Samsung, Tencent, Uber, Yahoo, Zepto, Zomato
class Solution {
public:
    // Time Complexity	: O(n * m)
    // Space Complexity	: O(n * m)
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

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
                if(mat[i][j] != 1) t[i][j] = t[i][j-1] + t[i-1][j];
            }
        }

        return t[n-1][m-1];
    }
};