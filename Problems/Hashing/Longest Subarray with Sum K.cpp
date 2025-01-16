/*
    Problem Name: Geeksforgeeks Longest Subarray with Sum K
    https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
    Company : Amazon (1+ year ago)
*/

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0;
        unordered_map<int,int> mpp;  // { sum , index }
        int sum = 0;
        int j = 0;
        
        while(j < n){
            sum += arr[j];
            
            if(sum == k){
                maxLen = max(maxLen , j + 1);
            } 
            
            int target = sum - k;
            if(mpp.find(target) != mpp.end()){
                maxLen = max(maxLen , j - mpp[target]);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = j;
            }
            j++;
        }
        return maxLen;
    }
};