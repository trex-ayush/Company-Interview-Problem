class Solution {
  public:
    // even number to 0 
    // odd number to 1
    // count subaaray with sum k
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int i = 0;

        while(i < n){
            sum += (nums[i]%2 == 0) ? 0 : 1;
            if(mpp.find(sum - k) != mpp.end()){
                count += mpp[sum - k];
            } 
            mpp[sum]++;
            i++;
        }

        return count;
    }
};