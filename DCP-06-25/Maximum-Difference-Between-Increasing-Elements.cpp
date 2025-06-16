// Company Tags: Cisco, Salesforce
class Solution {
public:
    /* 
        Approach 2: Optimal Force
        T.C: O(n)
        S.C: O(1)
    */
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int maxi = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mini) {
                maxi = max(maxi, (nums[i] - mini));
            } else {
                mini = nums[i];
            }
        }

        return maxi;
    }
    /* 
        Approach 1: Brute Force
        T.C: O(n^2)
        S.C: O(1)
        -------------------------------------------------
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] < nums[j]) maxi = max(maxi, nums[j]-nums[i]);
            }
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
    */
};