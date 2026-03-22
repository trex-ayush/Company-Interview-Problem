
class Solution {
  public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int total = 0;
        int timeReq = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != 0) total++;
                if(mat[i][j] == 2) q.push({i, j});
            }
        }
        
        while(!q.empty()){
            int k = q.size();
            count += k;
            
            while(k--){
                auto temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                
                for(auto& dir : dirs){
                    int x_ = dir[0] + x;
                    int y_ = dir[1] + y;
                    
                    if(x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && mat[x_][y_] == 1){
                        q.push({x_,y_});
                        mat[x_][y_] = 2;
                    }
                }
            }
            if(!q.empty()) timeReq++;
        }
        return total == count ?  timeReq : -1;
    }
};

