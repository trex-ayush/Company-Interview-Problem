class Solution {
public:
    int t[21][2001];
    int solve(vector<int>& nums, int& target, int idx, int sum){
        if(idx >= nums.size()) {
            if(sum == target) return 1;
            return 0;
        }
        if(t[idx][sum + 1000] != -1) return t[idx][sum + 1000];
        int takePos = solve(nums, target, idx+1, sum + nums[idx]);
        int takeNeg = solve(nums, target, idx+1, sum - nums[idx]);

        return t[idx][sum + 1000] = takePos + takeNeg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t, -1, sizeof(t));
        return solve(nums, target, 0, 0);
    }
};