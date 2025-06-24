// Company tags: Accenture, Atlassian, Booking.com, Citadel, Commvault, Goldman Sachs, IBM, Intuit, PayPal, Samsung, Splunk, Wayfair, Yandex, Zoho
class Solution {
public:
    // Approach: Bottom up
    // T.C: O(n*n)
    // S.C: O(n)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1); 
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    t[i] = max(t[i], 1 + t[j]);
                }
            } 
        }

        return *max_element(t.begin(), t.end());  // O(n)
    }
};