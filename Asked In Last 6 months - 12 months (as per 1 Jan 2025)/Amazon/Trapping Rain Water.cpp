/*
    Problem Name: Leetcode 42. Trapping Rain Water
    https://leetcode.com/problems/trapping-rain-water/description/
    Company: Amazon (1+ year ago), Microsoft (1+ year ago), Google (1+ year ago), Flipkart (1+ year ago), Goldman Sachs (1+ year ago)
    Tags: 
*/

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int> lMaxi(n,-1);
        
        lMaxi[0]=arr[0];
        for(int i=1;i<n;i++){
            lMaxi[i]=max(lMaxi[i-1] , arr[i]);
        }
        
        
        vector<int> rMaxi(n,-1);
        rMaxi[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            rMaxi[i]=max(rMaxi[i+1] , arr[i]);
        }
        
        
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=min(lMaxi[i] , rMaxi[i]);
            if(mini > arr[i]){
                ans+=(mini - arr[i]);
            }
        }
        
        
        return ans;
    }
};