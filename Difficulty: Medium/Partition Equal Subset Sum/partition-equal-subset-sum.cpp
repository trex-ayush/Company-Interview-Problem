
class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        for(auto& a : arr){
            totalSum += a;
        }
        if(totalSum % 2 != 0) return false;
        
        vector<vector<bool>> t(n + 1, vector<bool>(totalSum/2 + 1, false));
        
        for(int i = 0; i <= n; i++) t[i][0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= totalSum/2; j++){
                if(arr[i-1] <= j){
                    bool take = t[i-1][j-arr[i-1]];
                    bool skip = t[i-1][j];
                    
                    t[i][j] = take || skip;
                }else t[i][j] = t[i-1][j];
            }
        }
        return t[n][totalSum/2];
    }
};

