1// Company tags: Arcesium, DE Shaw, Google, Goldman Sachs, J.P. Morgan, LinkedIn, MakeMyTrip, Nvidia, Oracle, PayPal, ServiceNow, TCS, TikTok, Wayfair
2class Solution {
3public:
4    // Time Complexity  : O(n)
5    // Space Complexity : O(1)
6
7    // At each step, the maximum product can be the current element, 
8    // the previous maximum product times the current element, or 
9    // the previous minimum product times the current element (in case of two negatives).
10    int maxProduct(vector<int>& nums) {
11        int n = nums.size();
12        int bestAns = nums[0];
13
14        int minBest = 1;
15        int maxBest = 1;
16
17        for(int i = 0; i < n; i++){
18            int v1 = nums[i];
19            int v2 = nums[i] * minBest;
20            int v3 = nums[i] * maxBest;
21
22            maxBest = max({v1, v2, v3});
23            minBest = min({v1, v2, v3});
24
25            bestAns = max({bestAns, maxBest, minBest});
26        }
27
28        return bestAns;
29    }
30};