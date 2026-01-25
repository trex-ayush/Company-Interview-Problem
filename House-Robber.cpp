1// Company tags: Accenture, Agoda, Airbnb, Arcesium, ByteDance, Cisco, Citadel, DE Shaw, Databricks, EPAM Systems, Expedia, Flipkart, Goldman Sachs, Infosys, Intuit, LinkedIn, Morgan Stanley, Nvidia, PayPal, PhonePe, Salesforce, Tesla, Turing, Walmart Labs, Zoho
2
3class Solution {
4public:
5    // T.C: O(n)
6    // S.C: O(n)
7    int rob(vector<int>& nums) {
8        int n = nums.size();
9        if(n == 1) return nums[0];
10        if(n == 2) return max(nums[0], nums[1]);
11
12        vector<int> t(n, -1);
13
14        t[0] = nums[0];
15        t[1] = max(nums[0], nums[1]);
16
17        for(int i = 2; i < n; i++){
18            t[i] = max(t[i-1], nums[i] + t[i-2]);
19        }
20
21        return t[n-1];
22    }
23};