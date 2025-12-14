class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();
        int q = queries.size();
        
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int j = 0;j<m;j++){
            for(int i = 1;i<n;i++){
                mat[i][j]+=mat[i-1][j];
            }
        }
        
        vector<int> sums(q);
        for(int i = 0;i<q;i++){
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            
            sums[i] = mat[r2][c2];
            
            if(r1-1>=0){
                sums[i]-=mat[r1-1][c2];
            }
            if(c1-1>=0){
                sums[i]-=mat[r2][c1-1];
            }
            
            // intersection matrix
            if(r1-1>=0 and c1-1>=0){
                sums[i]+=mat[r1-1][c1-1];
            }
        }
        
        return sums;
    }
};
