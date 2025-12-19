1// Company tags: Adobe, Agoda, Airbnb, Amazon, Apple, Bloomberg, ByteDance, Flipkart, LinkedIn, Lyft, MakeMyTrip, Meta, Microsoft, Oracle, PayPal, Salesforce, Snap, Snowflake, SoFi, thoughtspot, TikTok, Uber, Walmart Labs, Yahoo, Yandex, Zopsmart
2class Solution {
3public:
4    // T.C: O(n)
5    // S.C: O(1)
6    bool isValid(vector<int>& have, vector<int>& needed){
7        for(int i = 0; i < 256; i++){
8            if(have[i] < needed[i]) return false;
9        }
10        return true;
11    }
12    string minWindow(string s, string t) {
13        int n = s.size();
14        int m = t.size();
15
16        if(m > n) return "";
17
18        vector<int> have(256), needed(256);
19
20        int i = 0;
21        int j = 0;
22        int len = INT_MAX;
23        int st = 0;
24
25        for(int i = 0; i < m; i++) needed[t[i]]++;
26
27        while(j < n){
28            have[s[j]]++;
29            while(isValid(have, needed)){
30                if(len > j - i + 1){
31                    len = j - i + 1;
32                    st = i;
33                }
34                have[s[i]]--;
35                i++;
36            }
37            j++;
38        }
39        if (len == INT_MAX) return "";
40        return s.substr(st, len);
41    }
42};