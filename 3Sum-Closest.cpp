1// Company tags: Adobe, Amazon, Apple, Bloomberg, Google, Meta, Microsoft, TCS, Uber, Yahoo, Zoho
2class Solution {
3public:
4    // T.C: O(n^2)
5    // S.C: O(1)
6    int threeSumClosest(vector<int>& nums, int target) {
7        int n = nums.size();
8
9        sort(nums.begin(), nums.end());
10
11        int i = 0;
12        int ans = INT_MAX;
13        int result = 0;
14
15        while(i < n - 2){ 
16            int j = i + 1;
17            int k = n - 1;
18            while(j < k){
19                int sum = nums[i] + nums[j] + nums[k];
20                if(ans >= abs(sum - target)){
21                    ans = abs(sum - target);
22                    result = sum;
23                }
24                if(sum > target) k--;
25                else j++;
26            }
27            i++;
28        }
29
30        return result;
31    }
32};