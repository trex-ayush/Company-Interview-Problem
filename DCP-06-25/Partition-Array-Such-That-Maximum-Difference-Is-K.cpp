class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int st = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] - st > k){
                ans++;
                st = nums[i];
            }
        }        

        return ans + 1;
    }
};