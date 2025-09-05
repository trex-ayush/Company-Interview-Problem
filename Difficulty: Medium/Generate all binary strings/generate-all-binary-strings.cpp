// User function Template for C++

class Solution {
  public:
    void solve(int n, int idx, vector<string>& res, string temp){
        if(idx == n){
            res.push_back(temp);
            return;
        } 
        
        solve(n, idx+1, res, temp+'0');
        if(temp.size() == 0 || temp.back() != '1') solve(n, idx+1, res, temp+'1');
    }
    vector<string> generateBinaryStrings(int num) {
        vector<string> res;
        solve(num, 0, res, "");
        return res;
    }
};