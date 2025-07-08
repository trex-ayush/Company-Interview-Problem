// Company tags: Arcesium, DE Shaw, Google, Goldman Sachs, J.P. Morgan, LinkedIn, MakeMyTrip, Nvidia, Oracle, PayPal, ServiceNow, TCS, TikTok, Wayfair
class Solution {
public:
    // Time Complexity  : O(n)
    // Space Complexity : O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 1;
        int suff = 1;
        int result = INT_MIN;

        for(int i = 0; i < n; i++){
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
            pref *= nums[i];
            suff *= nums[n-i-1];
            
            result = max({result, pref, suff});
        }
        return result;
    }
};