class Solution {
public:
    void solve(int n, int k, int idx, vector<int>& temp, vector<vector<int>>& res){
        if(n == 0 && temp.size() == k){
            res.push_back(temp);
            return;
        }
        if(n < 0 || temp.size() > k || idx > 9) return;
        solve(n , k, idx+1, temp, res);

        if(n - idx >= 0){
            temp.push_back(idx);
            solve(n-idx , k, idx+1, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;

        solve(n, k, 1, temp, res);

        return res;
    }
};