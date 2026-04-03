class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n=mat.size();
        vector<int>ans;
        
        unordered_map<int, vector<int>>mpp;

        for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
            mpp[i+j].push_back(mat[i][j]);
          }
        }

        for(int i = 0; i <= 2*n - 2; i++){
            for(int& j : mpp[i]){
                ans.push_back(j);
            }
        }

        return ans;
    }
};