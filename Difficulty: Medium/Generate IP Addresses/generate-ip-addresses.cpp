class Solution {
  public:
    int n;
    vector<string> res;
    
    bool isValid(string str) {
        if(str.size() > 1 && str[0] == '0') return false; // leading zero
        int val = stoi(str);
        return val >= 0 && val <= 255;
    }
    void solve(string& s, int parts, string curr, int idx) {
        if(idx == n && parts == 4) {
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        
        if(idx == n || parts == 4) return;
        
        if(idx < n) solve(s, parts + 1, curr + s.substr(idx, 1) + '.', idx + 1);
        if(idx + 1 < n && isValid(s.substr(idx, 2))) solve(s, parts + 1, curr + s.substr(idx, 2) + '.', idx + 2);
        if(idx + 2 < n && isValid(s.substr(idx, 3))) solve(s, parts + 1, curr + s.substr(idx, 3) + '.', idx + 3);
    }
    vector<string> generateIp(string &s) {
        n = s.size();
        res.clear();
        
        int parts = 0;
        string curr = "";
        
        solve(s, parts, curr, 0);
        
        return res;
    }
};