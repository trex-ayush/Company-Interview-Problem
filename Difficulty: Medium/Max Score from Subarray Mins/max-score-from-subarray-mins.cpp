class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int result = 0;
        
        for(int i = 1; i < n; i++){
            result = max(result, arr[i]+arr[i-1]);
        }
        
        return result;
    }
};