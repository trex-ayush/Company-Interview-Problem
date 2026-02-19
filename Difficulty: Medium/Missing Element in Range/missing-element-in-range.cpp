class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int> q;
        set<int> s(arr.begin(), arr.end());
        for (int i = low; i <= high; i++) {
            auto it = s.find(i);
            if (it == s.end()) {
                q.push_back(i);
            }
        }
        return q;
    }
};