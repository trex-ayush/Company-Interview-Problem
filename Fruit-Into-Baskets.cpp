class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        int i = 0;
        int j = 0;
        int maxLen = INT_MIN;

        while(j < n){
            mpp[nums[j]]++;
            if(i < n && mpp.size() > 2){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};