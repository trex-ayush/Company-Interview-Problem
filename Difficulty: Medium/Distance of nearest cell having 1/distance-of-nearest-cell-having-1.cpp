class Solution {
  public:
    // T.C: O(n * m);
    // S.C: O(n * m);
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> nearest(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int k = q.size();
            while(k--){
                auto temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                
                for(auto& dir : dirs){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    
                    if(i_ >= 0 && i_ < n && j_ >= 0 && j_< m && res[i_][j_] == -1){
                        res[i_][j_] = 1 + res[i][j];
                        q.push({i_, j_});
                    }
                }
            }
        }
        return res;
    }
};