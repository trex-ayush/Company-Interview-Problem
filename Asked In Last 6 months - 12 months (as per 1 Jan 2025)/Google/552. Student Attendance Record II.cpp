/*
    Problem Name: Leetcode 552. Student Attendance Record II
    https://leetcode.com/problems/student-attendance-record-ii/description/
    solution : https://leetcode.com/problems/student-attendance-record-ii/solutions/6251418/detailed-dry-run-with-example-beginner-friendly-step-by-step-solution
    Company : Google (6 months ago)
*/

/*
    Approach 1 
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
class Solution {
public: 
    long long int mod = 1e9 + 7;

    int solve(int n, int absentCount, int lateCount, vector<vector<vector<int>>>& dp) {
        if(lateCount >= 3 || absentCount >= 2) return 0;
        if(n == 0) return 1;

        if(dp[n][absentCount][lateCount] != -1) return dp[n][absentCount][lateCount];

        int present = solve(n - 1, absentCount, 0, dp);

        int absent = solve(n - 1, absentCount + 1, 0, dp);

        int late = solve(n - 1, absentCount, lateCount + 1, dp);
        int result = (present%mod + absent%mod + late%mod) % mod;
        return dp[n][absentCount][lateCount] = result;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0, dp);
    }
};
