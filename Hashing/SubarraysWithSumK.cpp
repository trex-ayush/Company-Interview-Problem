/*
Problem Name: Subarrays with sum K
https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

Asked by : Microsoft

Time Complexity : O(n)
Space Complexity : O(n)
*/
class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        
        for(auto& a : arr){
            sum += a;
            if(mpp.find(sum - k) != mpp.end()){
                count += mpp[sum - k];
            }
            mpp[sum]++;
        }
        
        return count;
    }
};