class Solution {
  public:
    bool solve(vector<int>& arr, int k, int idx, vector<vector<int>>& t){
        if(k == 0) return true;
        if(idx >= arr.size()) return false;
        
        if(t[k][idx] != -1) return t[k][idx];
        
        // skip
        bool skip = solve(arr, k, idx+1, t);
        // take
        bool take = false;
        if(arr[idx] <= k){
            take = solve(arr, k-arr[idx], idx+1, t);
        }
        return t[k][idx] = take || skip;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<vector<int>> t(k+1, vector<int>(n+1, -1));
        return solve(arr, k, 0, t);
    }
};