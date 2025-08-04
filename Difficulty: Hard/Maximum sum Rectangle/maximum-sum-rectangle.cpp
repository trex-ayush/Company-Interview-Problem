class Solution {
  public:
    int kadanes(vector<int>& arr) {
        int n = arr.size();
        int maxsum = arr[0];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxsum = max(maxsum, sum);
            if (sum < 0) sum = 0;
        }
        return maxsum;
    }
    
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int maxSum = INT_MIN;
        
        for(int left = 0; left < m; left++){
            vector<int> temp(n, 0);
            for(int right = left; right < m; right++){
                for(int i = 0; i < n; i++){
                    temp[i] += mat[i][right];
                }
                int sum = kadanes(temp);
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
};
