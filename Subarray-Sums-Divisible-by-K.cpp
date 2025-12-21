1// Company tags: Citadel, Expedia, PayPal, Tinkoff, thoughtspot
2class Solution {
3public:
4    // T.C: O(n)
5    // S.C: O(k)
6    int subarraysDivByK(vector<int>& nums, int k) {
7        int n = nums.size();
8        unordered_map<int, int> mpp;
9        mpp[0] = 1;
10
11        int j = 0;
12        int res = 0;
13        int sum = 0;
14
15        while(j < n){
16            sum += nums[j];
17            int rem = ((sum % k) + k) % k;
18            if(mpp.find(rem) != mpp.end()) res += mpp[rem];
19            mpp[rem]++;
20            j++;
21        }
22
23        return res;
24    }
25};