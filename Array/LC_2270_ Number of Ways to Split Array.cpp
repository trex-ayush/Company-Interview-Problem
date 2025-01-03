/*
    Problem Name: 2270. Number of Ways to Split Array
    https://leetcode.com/problems/number-of-ways-to-split-array/description
    Company : Google , Bloomberg , Amazon , Adobe , Yahoo
*/

/*
    Approach 1 (Brute force)
    Time Complexity : O(n^2)
    Space Complexity : O(1)
*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int validSplit = 0;

        for(int i = 0; i < n - 1; i++){
            int leftSum = 0;
            for (int j = 0; j <= i; j++) {
                leftSum += nums[j];
            }

            int rightSum = 0;
            for (int j = i + 1; j < n; j++) {
                rightSum += nums[j];
            }

            if(leftSum >= rightSum){
                validSplit++;
            }
        }
        return validSplit;
    }
};

/*
    Approach 2 (optimal )
    Time Complexity : O(n + n) = O(2n) = O(n)
    Space Complexity : O(1)
*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int validSplit = 0;
        long long totalSum = 0;

        for(auto& n : nums) totalSum += n;

        long long leftSum = 0;

        for(int i = 0; i < n - 1; i++){
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;

            if(leftSum >= rightSum){
                validSplit++;
            }
        }
        return validSplit;
    }
};
