// Company tags: Adobe, Amazon, Apple, BlackRock, Bloomberg, DE Shaw, Disney, Deutsche Bank, Grammarly, Huawei, IBM, Infosys, Intuit, J.P. Morgan, MakeMyTrip, Meta, Microsoft, Nvidia, Oracle, ServiceNow, TCS, Tesla, TikTok, Uber, Visa, Walmart Labs, Yahoo, Yandex, Zenefits, Zoho
class Solution {
  public:
    void solve(int& n, vector<string>& res, string temp, int open, int close){
        if(temp.size() == n*2){
            res.push_back(temp);
            return;
        }
        if(open < n) solve(n, res, temp + '(', open+1, close);
        if(close < open) solve(n, res, temp + ')', open, close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(n, res, "", 0, 0);
        return res;
    }
};