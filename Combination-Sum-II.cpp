class Solution {
public:
    void solve(vector<int>& arr, int k, int idx, vector<int>& temp, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(temp);
            return;
        }
        if (idx >= arr.size() || k < 0) return;

        int nextIdx = idx + 1;
        while (nextIdx < arr.size() && arr[nextIdx] == arr[idx])
            nextIdx++;

        solve(arr, k, nextIdx, temp, res);

        temp.push_back(arr[idx]);
        solve(arr, k - arr[idx], idx + 1, temp, res);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(arr, target, 0, temp, res);
        return res;
    }
};
