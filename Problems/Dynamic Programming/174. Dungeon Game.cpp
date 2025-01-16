/*
    Problem Name: Leetcode 174. Dungeon Game
    https://leetcode.com/problems/dungeon-game/description/
    Solution: https://leetcode.com/problems/dungeon-game/solutions/6288826/detailed-dry-run-with-diagram-beginner-friendly-memoization-step-by-step-solution
    Company : 
*/

/*
    Approach 1 
    Time Complexity : O(n*m)
    Space Complexity : O(n*m)
*/
class Solution {
public:
    int solve(int i, int j, const vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // Base case: Bottom-right cell (princess's room)
        if (i == m - 1 && j == n - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        // If out of bounds
        if (i >= m || j >= n) {
            return INT_MAX;
        }

        // If the value is already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Recursive calculation for the minimum health needed
        int right = solve(i, j + 1, dungeon, dp);
        int down = solve(i + 1, j, dungeon, dp);

        // The knight needs at least 1 health point to survive
        int min_health = min(right, down) - dungeon[i][j];
        dp[i][j] = max(1, min_health);

        return dp[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // Create a memoization table initialized with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start from the top-left cell
        return solve(0, 0, dungeon, dp);
    }
};