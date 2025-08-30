// Company tags: Accenture, Adobe, Amazon, Apple, Atlassian, Bloomberg, ByteDance, Citadel, eBay, Flipkart, Goldman Sachs, Infosys, Meta, Microsoft, Nutanix, Oracle, PayPal, Paytm, Salesforce, SAP, ServiceNow, Snowflake, Sprinklr, TCS, Tesla, TikTok, Uber, Visa, Walmart Labs, Wix, Yahoo, Yandex, Zoho, Zopsmart
class Solution {
public:
    // Time complexity  : O(n)
    // Space complexity : O(1)
    int maxArea(vector<int>& height) {
        int n = height.size();

        int res = 0;
        int i = 0;
        int j = n - 1;

        while(i < j){
            int w = j - i;
            int h = min(height[i], height[j]);

            res = max(res, w*h);

            if(height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
};