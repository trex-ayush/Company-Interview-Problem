class Solution {
  public:
    void solve(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int>& temp) {
        res.push_back(temp);
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            solve(nums, i + 1, res, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        solve(nums, 0, res, temp);
        return res;
    }
};
