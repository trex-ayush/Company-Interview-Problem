class Solution {
public:
    int solve(int i, vector<int>& arr, int& n, int& k, vector<int>& dp) {
        if (i >= n) return 0;

        if (dp[i] != INT_MIN) return dp[i];

        int next = 0;
        if (i + k < n) {
            next = solve(i + k, arr, n, k, dp);
        }

        return dp[i] = arr[i] + next;
    }

    int maximumEnergy(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = INT_MIN;
        vector<int> dp(n, INT_MIN);

        for (int i = 0; i < n; i++) {
            int energy = solve(i, arr, n, k, dp);
            if (energy > maxi) {
                maxi = energy;
            }
        }

        return maxi;
    }
};
