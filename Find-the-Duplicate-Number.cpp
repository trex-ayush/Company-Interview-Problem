1/*
2    Company tags: Amazon, Anduril, Citadel, Goldman Sachs, Google, IBM, Infosys, J.P. Morgan, Nvidia, Paytm, PhonePe, Zoho
3    T.C: O(n)
4    S.C: O(1)
5*/
6class Solution {
7public:
8    int findDuplicate(vector<int>& nums) {
9        int slow = nums[0];
10        int fast = nums[0];
11        
12        slow = nums[slow];
13        fast = nums[nums[fast]];
14        
15        while(slow != fast) {
16            slow = nums[slow];
17            fast = nums[nums[fast]];
18        }
19        
20        slow = nums[0];
21        while(slow != fast) {
22            slow = nums[slow];
23            fast = nums[fast];
24        }
25        
26        return slow;
27    }
28};