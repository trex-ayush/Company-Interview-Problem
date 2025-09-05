// Company tags: Adobe, Airbnb, Amazon, Apple, Autodesk, Bloomberg, ByteDance, Citadel, DE Shaw, Huawei, Infosys, J.P. Morgan, LinkedIn, Meta, Microsoft, Oracle, PayPal, Salesforce, Snap, TCS, TikTok, Uber, Walmart Labs, Yahoo, Zoho
class Solution {
  public:
    // Time complexity  : O(n * 2^n)
    // Space Complexity : O(2^n * n)
    void solve(vector<int>& arr, int k, int idx, vector<int>& temp, vector<vector<int>>& res){
        if(k == 0){
            res.push_back(temp);
            return;
        }
        if(idx >= arr.size() || k < 0) return;
        
        // skip
        solve(arr, k, idx+1, temp, res);
        // take
        temp.push_back(arr[idx]);
        solve(arr, k - arr[idx], idx, temp, res);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(arr, target, 0, temp, res);
        
        return res;
    }
};