/*
    Problem Name: Count Pairs whose sum is less than target
    https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1
    Company : 
*/

/*
    Approach 1 (Brute force)
    Time Complexity : O(n^2)
    Space Complexity : O(1)
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int ans = 0;
        
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int sum = arr[i] + arr[j];
                if(sum < target) ans++;
            }
        }
        
        return ans;
    }
};

/*
     Approach 2 (Optimized using Two Pointer Technique)
    Time Complexity : O(n log n)  [Due to sorting the array]
    Space Complexity : O(1)       [In-place sorting and two pointers]
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());  // O(logn)
        int ans = 0;
        int st = 0;
        int en = n - 1;
        
        while(st <= en){
            int sum = arr[st] + arr[en];
            if(sum < target){
                ans += (en - st);
                st++;
            }else{
                en--;
            }
        }
        return ans;
    }
};