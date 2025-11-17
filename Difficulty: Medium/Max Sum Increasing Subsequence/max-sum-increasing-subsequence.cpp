class Solution {
  public:
    int solve(vector<int> &arr, int n, int i, int prevInd, vector<vector<int>> &dp){
        if(i == n) return 0;
        
        if(dp[i][prevInd+1] != -1) return dp[i][prevInd+1];
        
        int incl=0, excl=0;
        if( prevInd == -1 || (arr[i] > arr[prevInd])){
            incl = arr[i] + solve(arr, n, i+1, i, dp);
        }
        excl = 0 + solve(arr, n, i+1, prevInd, dp);
        
        return dp[i][prevInd+1] =  max(incl, excl);
    }
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        int prevInd = -1;
        int sum = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(arr, n, 0, prevInd, dp);
    }
};