/*
    Problem Name: Geeksforgeeks Indexes of Subarray Sum
    https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
    Company : Amazon (1+ year ago) , Google (1+ year ago) , Facebook (1+ year ago) , Visa (1+ year ago)
*/

/*
    Approach 1 
    Time Complexity : O(n)
    Space Complexity : O(1)
*/
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        
        while(j < n){
            sum += arr[j];
            while(sum > target){
                sum -= arr[i];
                i++;
            }
            if(sum == target) return {i+1,j+1};
            j++;
        }
        return {-1};
    }
};