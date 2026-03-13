1// Company tags: Adobe, Amazon, Apple, Arista Networks, Cisco, Meta, Microsoft, Oracle, TikTok, Yandex, Zoho
2// T.C: O(3^4)
3// S.C: O(1)
4class Solution {
5public:
6    int n;
7    vector<string> res;
8    
9    bool isValid(string str) {
10        if(str.size() > 1 && str[0] == '0') return false; // leading zero
11        int val = stoi(str);
12        return val >= 0 && val <= 255;
13    }
14    void solve(string& s, int parts, string curr, int idx) {
15        if(idx == n && parts == 4) {
16            curr.pop_back();
17            res.push_back(curr);
18            return;
19        }
20        
21        if(idx == n || parts == 4) return;
22        
23        if(idx < n) solve(s, parts + 1, curr + s.substr(idx, 1) + '.', idx + 1);
24        if(idx + 1 < n && isValid(s.substr(idx, 2))) solve(s, parts + 1, curr + s.substr(idx, 2) + '.', idx + 2);
25        if(idx + 2 < n && isValid(s.substr(idx, 3))) solve(s, parts + 1, curr + s.substr(idx, 3) + '.', idx + 3);
26    }
27
28    vector<string> restoreIpAddresses(string s) {
29        n = s.size();
30        res.clear();
31        
32        int parts = 0;
33        string curr = "";
34        
35        solve(s, parts, curr, 0);
36        
37        return res;
38    }
39};