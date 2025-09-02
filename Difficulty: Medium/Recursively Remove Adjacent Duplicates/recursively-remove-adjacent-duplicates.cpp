// User function template for C++

class Solution {
  public:
    string solve(string& s){
        string res = "";
        int i = 0;
        
        while (i < s.size()) {
            bool isDuplicate = false;
            while (i + 1 < s.size() && s[i] == s[i + 1]) {
                isDuplicate = true;
                i++;
            }
            
            if (!isDuplicate) res += s[i];
            i++;
        }
        
        if(s.size() == res.size() || res.empty()) return res;
        return solve(res);
    }
    
    string removeUtil(string &s) {
        return solve(s);
    }
};