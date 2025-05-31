// Company Tags: Expedia, Snap, Yandex, DE Shaw, tcs, J.P. Morgan
// longest subarray with atmost k zeros
class Solution {
public:
    /*Approach 2 : Optimal Approach
    T.C : O(n)
    S.C : O(1)
    */
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int zeros = 0;
        int maxLen = 0;

        while(j < n){
            if(nums[j] == 0) zeros++;
            while(zeros > k){
                if(nums[i] == 0) {
                    zeros--;
                }
                i++;
            }
            if(zeros <= k) {
                maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
        return maxLen;
    }

    /*Approach 1 : Brute Force Code
    T.C : O(n*n)
    S.C : O(1)
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            int zeroCount = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == 0) zeroCount++;
                if(zeroCount <= k){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
    */
};