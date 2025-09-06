class Solution {
  public:
    void solve(vector<int>& nums, int idx, vector<int>& res, int temp){
        if(idx >= nums.size()){
            res.push_back(temp);
            return;
        }
        // skip 
        solve(nums, idx+1, res, temp);
        // take
        solve(nums, idx+1, res, temp+nums[idx]);
    }
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> res;
        
        solve(nums, 0, res, 0);
        
        return res;
    }
};