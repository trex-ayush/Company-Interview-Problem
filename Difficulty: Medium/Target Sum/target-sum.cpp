class Solution {
  public:
    int solve(vector<int>& arr, int target, int idx,unordered_map<string,int>& dp){
        if(idx == arr.size()){
            return target == 0 ? 1 : 0;    
        } 
        string key = to_string(idx) + " - " + to_string(target);
        
        if(dp.find(key) != dp.end()) return dp[key];
        
        int MOD = 1e9+7;
        int take = solve(arr, target - arr[idx], idx + 1, dp) % MOD;
        int skip = solve(arr, target + arr[idx], idx + 1, dp) % MOD;
        
        return dp[key] = (take + skip) % MOD;
    }
    int totalWays(vector<int>& arr, int target) {
        unordered_map<string,int> dp;
        return solve(arr, target, 0, dp);
    }
};
