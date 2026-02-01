1// Company Tags: American Express
2class Solution {
3public:
4    // T.C: O(n)
5    //S.C: O(1)
6    int minimumCost(vector<int>& nums) {
7        int n = nums.size();
8
9        int firstMin  = nums[0];
10        int secondMin = INT_MAX;
11        int thirdMin  = INT_MAX;
12
13        for(int i = 1; i < n; i++) {
14            if(nums[i] < secondMin) {
15                thirdMin  = secondMin;
16                secondMin = nums[i];
17            } else if(nums[i] < thirdMin) {
18                thirdMin = nums[i];
19            }
20        }
21
22        return firstMin + secondMin + thirdMin;
23    }
24};
25