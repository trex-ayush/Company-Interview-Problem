class Solution {
public:
    int pivot(vector<int>& nums){
        int n = nums.size();
        int st = 0;
        int en = n - 1;

        while(st < en){
            int mid = st + (en - st)/2;

            if(nums[mid] > nums[en]){
                st = mid + 1;
            } else {
                en = mid;
            } 
        }
        return st;
    }
    int findMin(vector<int>& nums) {
        return nums[pivot(nums)];
    }
};