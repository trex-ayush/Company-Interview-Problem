1/*
2    Company tags: Accenture, Agoda, Expedia
3    T.C: O(n * 26) = O(n)
4    S.C: O(26) = O(1)
5*/
6class Solution {
7public:
8    bool checkInclusion(string s1, string s2) {
9        int m = s1.size();
10        int n = s2.size();
11        vector<int> freq1(26, 0);
12        vector<int> freq2(26, 0);
13
14        for(auto& ch : s1) freq1[ch - 'a']++;
15
16        int i = 0;
17        int j = 0;
18
19        while(j < n) {
20            freq2[s2[j] - 'a']++;
21            while(j - i + 1 > m){
22                freq2[s2[i] - 'a']--;
23                i++;
24            }
25            if(freq1 == freq2) return true;
26            j++;
27        }
28
29        return false;
30    }
31};