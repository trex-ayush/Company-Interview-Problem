class Solution {
  public:
    void solve(int& n, vector<string>& res, string temp, int open, int close){
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }
        if(open < n/2) solve(n, res, temp + '(', open+1, close);
        if(close < open) solve(n, res, temp + ')', open, close+1);
    }
    vector<string> generateParentheses(int n) {
        vector<string> res;
        
        solve(n, res, "", 0, 0);
        
        return res;
    }
};