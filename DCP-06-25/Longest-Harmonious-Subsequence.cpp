class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mpp;
        
        for(auto& num : nums) mpp[num]++;

        int maxLen = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int mini = nums[i];
            int maxi = nums[i] + 1;
            if(mpp.find(maxi) != mpp.end()){
                maxLen = max(maxLen, mpp[maxi] + mpp[mini]);
            }
        }
        return maxLen;
    }
};