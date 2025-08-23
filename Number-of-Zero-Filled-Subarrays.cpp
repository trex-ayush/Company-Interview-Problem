// Company tags: Meta
class Solution {
public:
    // Time Complexity  : O(n)
    // Space Complexity : O(1)
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int i = 0;
        int n = nums.size();

        while(i < n){
            long long len = 0;
            if(nums[i] == 0){
                while(i < n && nums[i] == 0){
                    len++;
                    i++;
                }
            }else{
                i++;
            }
            res += (len * (len + 1))/2;
        }
        return res;
    }
};