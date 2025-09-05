// Company tags: Adobe, Amazon, Apple, Bloomberg, Google, Meta, Microsoft, Uber
class Solution {
public:
    void solve(int n, int k, int idx, vector<int>& temp, vector<vector<int>>& res){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        if(idx > n) return;
        
        // skip
        solve(n, k, idx+1, temp, res);
        // take
        temp.push_back(idx);
        solve(n, k, idx+1, temp, res);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(n, k, 1, temp, res);
        return res;
    }
};