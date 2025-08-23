class Solution {
public:
    // Time Complexity  : O(n*m)
    // Space Complexity : O(1)
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int stRow = n;
        int enRow = -1;
        int stCol = m;
        int enCol = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    stRow = min(stRow, i);
                    enRow = max(enRow, i);
                    stCol = min(stCol, j);
                    enCol = max(enCol, j);
                }
            }
        }
        return (enCol - stCol + 1) * (enRow - stRow + 1);
    }
};