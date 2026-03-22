1/*
2    Company tags: Booking.com, Grammarly, IBM, Tinkoff, Wayfair
3    T.C: O(n)
4    S.C: O(1)
5*/
6class Solution {
7public:
8    bool backspaceCompare(string s, string t) {
9        int n = s.size();
10        int m = t.size();
11
12        if(s == t) return true;
13
14        int i = n - 1;
15        int j = m - 1;
16        int skip_s = 0;
17        int skip_t = 0;
18
19        while(i >= 0 || j >= 0) {
20            while(i >= 0) {
21                if(s[i] == '#') {
22                    skip_s++;
23                    i--;
24                }else if(skip_s > 0) {
25                    skip_s--;
26                    i--;
27                }else break;
28            }
29            while(j >= 0) {
30                // cout << "j : " << j << " -> " << t[j] << " " << skip_t << endl; 
31                if(t[j] == '#') {
32                    skip_t++;
33                    j--;
34                }else if(skip_t > 0) {
35                    skip_t--;
36                    j--;
37                }else break;
38            }
39            char data_s = i >= 0 ? s[i] : '$';
40            char data_t = j >= 0 ? t[j] : '$';
41            // cout << data_s << " -- " << data_t << " i : " << i << " j : " << j << endl;
42            if(data_s != data_t) return false;
43            i--;
44            j--;
45        }
46
47        return true;
48    }
49};