class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshCount = 0;

        queue<pair<int,int>> q;  //{i,j}

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) freshCount++;
                else if(grid[i][j] == 2) q.push({i,j});
            }
        }

        int time = 0;

        while(!q.empty() && freshCount > 0){
            int k = q.size();

            while(k--){
                pair<int,int> temp = q.front();
                q.pop();

                int i = temp.first;
                int j = temp.second;

                grid[i][j] = 2;

                for(auto& dir : dirs){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1){
                        q.push({new_i, new_j});
                        grid[new_i][new_j] = 2;
                        freshCount--;
                    }
                }
            }
            time++;
        }
        return freshCount == 0 ? time : -1;
    }
};