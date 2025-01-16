/*
    Problem Name: Geeksforgeeks Largest subarray of 0's and 1's
    Leettcode 525. Contiguous Array
    https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
    https://leetcode.com/problems/contiguous-array/description/
    Company : Amazon (1+ year ago), Paytm (1+ year ago), Morgan Stanley (1+ year ago), MakeMyTrip (1+ year ago) 
    Tags: Maps
*/

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int maxLen = 0;
        int sum = 0;
        int j = 0;
        
        while(j < n){
            sum += (arr[j] == 0) ? -1 : arr[j];
            if(mpp.find(sum) != mpp.end()){
                maxLen = max(maxLen, j - mpp[sum]);
            }else{
                mpp[sum] = j;
            }
            j++;
        }
        
        return maxLen;
    }
};