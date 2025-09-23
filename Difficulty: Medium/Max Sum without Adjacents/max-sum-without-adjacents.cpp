class Solution {
  public:
    int solve(vector<int>& arr, int idx, vector<int>& t){
        if(idx < 0) return 0;
        if(t[idx] != -1) return t[idx];
        
        int take, skip;
        take = arr[idx] + solve(arr, idx - 2, t);
        skip = solve(arr, idx - 1, t);
        
        return t[idx] = max(take, skip);
    }
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> t(n, -1);
        return solve(arr, n-1, t);
    }
};