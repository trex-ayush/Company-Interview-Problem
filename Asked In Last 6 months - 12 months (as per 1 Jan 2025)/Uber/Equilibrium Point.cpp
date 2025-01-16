/*
    Problem Name: Geeksforgeeks Equilibrium Point
    https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
    Company : Amazon (1+ year ago), Adobe (1+ year ago), Google (1+ year ago), Facebook (1+ year ago), Microsoft (1+ year ago), Uber (1+ year ago)
*/

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/
class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return -1;
        
        long totalSum = 0, leftSum = 0;
        
        for (auto& a: arr) {
            totalSum += a;
        }
        
        for (int i = 0; i < n; i++) {
            long rightSum = totalSum - leftSum - arr[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += arr[i];
        }
        
        return -1;
    }

};
