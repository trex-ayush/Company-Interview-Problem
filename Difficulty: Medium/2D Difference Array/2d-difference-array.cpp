class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> check(n, vector<int>(m, 0));
        
        for (auto q : opr) {
            
            int v  = q[0];
            int r1 = q[1];
            int c1 = q[2];
            int r2 = q[3];
            int c2 = q[4];
            
            for (int i = r1; i <= r2; i++) {
                check[i][c1] += v;
                if (c2 + 1 < m){
                    check[i][c2 + 1] = check[i][c2 + 1] - v;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                check[i][j] += check[i][j - 1];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = mat[i][j] + check[i][j];
            }
        }
        
        return mat;
    }
};