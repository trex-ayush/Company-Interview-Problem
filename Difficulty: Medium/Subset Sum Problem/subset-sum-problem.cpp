class Solution {
  public:
    bool solve(vector<int>& arr, int sum, int idx, vector<vector<int>>& t){
        if(sum == 0) return true;
        if(idx < 0)  return false;
        
        if(t[sum][idx] != -1) return t[sum][idx];
        
        bool take = false;
        
        bool skip = solve(arr, sum, idx - 1, t);
        if(arr[idx] <= sum){
            take = solve(arr, sum - arr[idx], idx - 1, t);
        }
        
        return t[sum][idx] = take || skip;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> t(sum + 1, vector<int>(n, -1));
        return solve(arr, sum, n - 1, t);
    }
};