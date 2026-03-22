1/*
2    Company tags: Accenture, Airbnb, BlackRock, Cisco, Cognizant, IBM, J.P. Morgan, Snowflake, TCS, Verily, X, Zoho
3    T.C: O(logn)
4    S.C: O(1)
5*/
6class Solution {
7public:
8    int find(int n) {
9        int sum = 0;
10        while (n > 0) {
11            int d = n % 10;
12            sum += d * d;
13            n /= 10;
14        }
15        return sum;
16    }
17
18    bool isHappy(int n) {
19        int slow = n;
20        int fast = n;
21
22        while (true) {
23            slow = find(slow);
24            fast = find(find(fast));
25
26            if (fast == 1) return true;
27            if (slow == fast) return false; // cycle
28        }
29    }
30};