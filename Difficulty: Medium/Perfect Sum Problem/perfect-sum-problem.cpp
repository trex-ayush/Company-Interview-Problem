class Solution {
  public:
    int perfectSum(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<vector<int>> t(n + 1, vector<int>(k + 1, 0));
        
        for(int i = 0; i < n + 1; i++){
            t[i][0] = 1;
        }
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < k + 1; j++){
                if(arr[i - 1] <= j){
                    int take = t[i-1][j - arr[i - 1]];
                    int skip = t[i-1][j];
                    
                    t[i][j] = take + skip;
                }else t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][k];
    }
};