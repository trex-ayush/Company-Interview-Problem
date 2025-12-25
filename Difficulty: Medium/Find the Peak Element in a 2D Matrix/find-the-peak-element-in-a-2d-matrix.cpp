class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, -1, 0, 1};
        
        vector<int>ans;
        
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                bool peak=1;
                for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        if(mat[r][c]<mat[nr][nc]){
                            peak=0;
                            break;
                        }
                    }
                }
                if(peak){
                    ans.push_back(r);
                    ans.push_back(c);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};
