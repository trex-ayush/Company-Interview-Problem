// Company tags: Adobe, Amazon, Apple, Atlassian, Bloomberg, Coupang, IBM, Meta, Microsoft, Salesforce, TCS, TikTok, Uber, Wix, Yahoo, Zoho
class Solution {
public:
    // Time Complexity  : O(n*2^n)
    // Space Complexity : O(n*2^n)
    void solve(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int> temp){
        if(idx >= nums.size()){
            res.push_back(temp);
            return;
        }
        // skip 
        solve(nums, idx+1, res, temp);
        // take
        temp.push_back(nums[idx]);
        solve(nums, idx+1, res, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        solve(nums, 0, res, {});

        return res;
    }
};