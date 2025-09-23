class Solution {
  public:
    int solve(int day, int lastTask, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != lastTask) {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        
        if (dp[day][lastTask] != -1) return dp[day][lastTask];
        
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != lastTask) {
                int point = arr[day][task] + solve(day - 1, task, arr, dp);
                maxi = max(maxi, point);
            }
        }
        
        return dp[day][lastTask] = maxi;
    }

    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(n - 1, 3, arr, dp);
    }
};
