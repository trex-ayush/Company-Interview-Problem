1/*
2    Company tags: Atlassian, IBM, Nvidia, PayPal, Salesforce, ServiceNow, SoFi
3    T.C: O(n)
4    S.C: O(1)
5*/
6class Solution {
7public:
8    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
9        if(k <= 1) return 0;
10        int n = nums.size();
11        int res = 0;
12
13        int i = 0;
14        int j = 0;
15        long long prod = 1;
16
17        while(j < n) {
18            prod *= nums[j];
19
20            while(prod >= k) {
21                prod /= nums[i];
22                i++;
23            }
24            res += (j - i + 1);
25            j++;
26        }
27        return res;
28    }
29};