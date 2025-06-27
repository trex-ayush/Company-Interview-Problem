// company tags: Adobe, Amazon, Apple, Bloomberg, Meta, Microsoft, Oracle, Uber, Yahoo
class Solution {
public:
    // T.C: O(log n)
    // S.C: O(1)
    int pivot(vector<int>& nums){
        int n = nums.size();
        int st = 0;
        int en = n - 1;

        while(st < en){

            while(st < en && nums[st] == nums[st+1]) st++;
            while(st < en && nums[en] == nums[en-1]) en--;
            int mid = st + (en - st)/2;

            if(nums[mid] > nums[en]){
                st = mid + 1;
            } else if (nums[mid] < nums[en]) {
                en = mid;
            } else {
                en--; // when nums[mid] == nums[en], shrink the window
            }
        }
        return st;
    }
    bool bs(vector<int>& nums, int st, int en, int& k){
        while(st <= en){
            int mid = st + (en - st)/2;
            if(nums[mid] == k) return true;
            else if(nums[mid] < k){
                st = mid + 1;
            }else{
                en = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int pivotIdx = pivot(nums);
        return bs(nums, 0, pivotIdx-1, target) || bs(nums, pivotIdx, nums.size()-1, target);
    }
};