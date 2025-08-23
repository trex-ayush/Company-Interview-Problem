// Company tags: Tinkoff
class Solution {
public:
    // Time Complexity  : O(n*m)
    // Space Complexity : O(n*m)
    int t[301][301];
    int solve(int i, int j, vector<vector<int>>& matrix){
        if(i >= matrix.size() || j >= matrix[0].size()) return 0;
        if(matrix[i][j] == 0) return 0;

        if(t[i][j] != -1) return t[i][j];

        int right = solve(i, j + 1, matrix);
        int down  = solve(i + 1, j, matrix);
        int diag  = solve(i + 1, j + 1, matrix);

        return t[i][j] = 1 + min({right, down, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        memset(t, -1, sizeof(t));

        int result = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    result += solve(i, j, matrix);
                }
            }
        }

        return result;
    }
};