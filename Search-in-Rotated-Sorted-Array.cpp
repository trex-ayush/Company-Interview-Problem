// Company tags: Accolite, Adobe, Amazon, Anduril, Apple, Arcesium, Bloomberg, ByteDance, Disney, eBay, EPAM Systems, Expedia, Flipkart, Goldman Sachs, Grammarly, Google, IXL, IXZcaler, LinkedIn, Media.net, Meta, Microsoft, MongoDB, Netflix, Nvidia, Oracle, PayPal, PhonePe, Salesforce, Samsung, ServiceNow, Snowflake, TikTok, Tinkoff, Uber, Visa, VMware, Walmart Labs, Yahoo, Yandex, Zepto, Zoho
class Solution {
public:
    // T.C: O(log n)
    // S.C: O(1)
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int en = n - 1;

        while(st <= en){
            int mid = st + (en-st)/2;
            if(nums[mid] == target) return mid;

            if(nums[st] <= nums[mid]){
                // left sorted
                if(nums[st] <= target && target < nums[mid]){
                    en = mid - 1;
                }else st = mid + 1;
            }else{
                // right sorted
                if(nums[mid] < target && target <= nums[en]){
                    st = mid + 1;
                }else en = mid - 1;
            }
        }
        return -1;
    }
};