1// Company tags: DE Shaw, Expedia, Goldman Sachs, Nvidia, Oracle, Yandex
2class Solution {
3public:
4    // T.C: O(n)
5    // S.C: O(1)
6    int minSubArrayLen(int target, vector<int>& nums) {
7        int n = nums.size();
8        int i = 0;
9        int j = 0;
10        int res = INT_MAX;
11        int sum = 0;
12
13        while(j < n){
14            sum += nums[j];
15            while(sum >= target){
16                res = min(res, j - i + 1);
17                sum -= nums[i];
18                i++;
19            }
20            j++;
21        }
22
23        return res == INT_MAX ? 0 : res;
24    }
25};