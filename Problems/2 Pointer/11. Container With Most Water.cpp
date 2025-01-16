/*
    Problem Name: geeksforgeeks & Leetcode 11. Container With Most Water
    https://leetcode.com/problems/container-with-most-water/description/
    Company: Amazon (1+ year ago), Google (1+ year ago), Flipkart (1+ year ago)
    Tags: 
*/

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int ans = 0;
        
        while(left<right){
            int tempwater=min(arr[left],arr[right])*(right-left);
            ans=max(ans,tempwater);
            if(arr[left]<arr[right])left++;
            else{
                right--;
            }
        }
        return ans;
    }
};