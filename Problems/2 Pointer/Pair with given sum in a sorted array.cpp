/*
    Problem Name: Pair with given sum in a sorted array
    https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1
    Company : Adobe
*/

/*
    Approach 1 
    Time Complexity : O(n)
    Space Complexity : O(1)
*/
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int res = 0;
        int n = arr.size();
        int left = 0, right = n - 1;
        
        while (left < right) {
            if (arr[left] + arr[right] < target) left++;
            else if (arr[left] + arr[right] > target) right--;
            else {
                int cnt1 = 0, cnt2 = 0;
                int ele1 = arr[left], ele2 = arr[right];
              
                while (left <= right and arr[left] == ele1) {
                    left++;
                    cnt1++;
                }
              
                while(left <= right and arr[right] == ele2) {
                    right--;
                    cnt2++;
                }
               
                if(ele1 == ele2) res += (cnt1 * (cnt1 - 1))/2;
                else res += (cnt1 * cnt2);
            }
        }
        return res;
    }
};