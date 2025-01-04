/*
    Problem Name: Count all triplets with given sum in sorted array
    https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1
    Company :
*/

/*
    Time Complexity : O(n^2)
    Space Complexity : O(1)
*/

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int count = 0;
        int n = arr.size();
        
        for(int i = 0; i <  n; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum == target){
                    count++;
                    int temp = j + 1;
                    while(temp < k && arr[temp] == arr[temp - 1]){
                        count++;
                        temp++;
                    }
                    k--;
                }else if(sum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        return count;
    }
};